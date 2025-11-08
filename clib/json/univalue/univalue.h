#ifndef UNILIB_CLIB_JSON_UNIVALUE_H
#define UNILIB_CLIB_JSON_UNIVALUE_H

#include <system_error>
#include <vector>
#include <string>
#include <cstdint>
#include <type_traits>
#include <utility>
#include <charconv>

class UniValue
{
 public:
  enum ValueType { kNull, kBool, kNum, kStr, kObj, kArr };

  class type_error : public std::runtime_error {
    using std::runtime_error::runtime_error;
  };

  UniValue() { type_ = kNull; }
  UniValue(UniValue::ValueType type, std::string str = {})
      : type_{type}, value_{std::move(str)} {}
  template<typename Ref, 
           typename T = std::remove_cv_t<std::remove_reference_t<Ref>>,
           std::enable_if_t<std::is_floating_point_v<T> ||
                            std::is_same_v<bool, T> || 
                            std::is_signed_v<T> || std::is_unsigned_v<T> ||
                            std::is_constructible_v<std::string, T>, bool> = true>
  UniValue(Ref&& val) {
    if constexpr (std::is_floating_point_v<T>) {
      SetFloat(val);
    } else if constexpr (std::is_same_v<bool, T>) {
      SetBool(val);
    } else if constexpr (std::is_signed_v<T>) {
      SetInt(int64_t{val});
    } else if constexpr (std::is_unsigned_v<T>) {
      SetInt(uint64_t{val});
    } else {
      setStr(std::string{std::forward<Ref>(val)});
    }
  }

  void Clear();

  void SetNull();
  void SetBool(bool val);
  void SetNumStr(std::string str);
  void SetInt(uint64_t val);
  void SetInt(int64_t val);
  void SetFloat(double val);
  void SetStr(std::string str);
  void SetArray();
  void SetObject();
  
  enum ValueType GetType() const { return type_; }
  const std::string& GetStrVal() const { return value_; }
  bool empty() const { return (values_.size() == 0); }

  bool IsNull() const { return type_ == kNull; } 
  bool IsTrue() const { return (type_ == kBool) && (value_ == "1"); }
  bool IsFalse() const { return (type_ == kBool) && (value_ != "1"); }
  bool IsBool() const { return type_ == kBool; }
  bool IsStr() const { return type_ == kStr; }
  bool IsNum() const { return type_ == kNum; }
  bool IsArray() const { return type_ == kArr; }
  bool IsObject() const { return type_ == kObj; }

  void PushBack(UniValue val);
  void PushBackV(std::vector<UniValue>& vec);
  template<typename Iter>
  void PushBackV(Iter first, Iter last);

  void PushKVEnd(std::string key, UniValue val);
  void PushKVs(UniValue val);
  void PushKV(std::string key, UniValue val);

  template<typename Int>
  Int GetInt() const;

 private:
  UniValue::ValueType type_;
  std::string value_;
  std::vector<std::string> keys_;
  std::vector<UniValue> values_;
 
  void CheckType(const ValueType& expected) const;
  bool FindKey(const std::string& key, size_t& ret_idx) const;
  void WriteArray() const;
  void WriteObject() const;
};

template<typename Iter>
void UniValue::PushBackV(Iter first, Iter last) {
  CheckType(kArr);
  values_.insert(values_.end(), first, last);
}

template<typename Int>
Int UniValue::GetInt() const {
  CheckType(kNum);
  Int result;
  const auto [first_nonmatching, error_cond] = std::from_chars(val.data(), val.data() + val.size(), result);
  if (first_nonmatching != val.data() + val.size() || error_cond != std::errc{}) {
    throw std::runtime_error("JSON integer out of range");
  }
  return result;
}

enum JTokenType {
  kTokenError = -1,
  kTokenNone = 0,
  kTokenObjOpen,
  kTokenObjClose,
  kTokenArrOpen,
  kTokenArrClose,
  kTokenColon,
  kTokenComma,
  kTokenNull,
  kTokenFalse,
  kTokenTrue,
  kTokenNumber,
  kTokenString
};

extern enum JTokenType GetJToken(std::string& str, unsigned int& consumed, const char* raw, const char* end);

extern const char* UniValueTypeName(UniValue::ValueType t);

static inline bool JTokenIsValue(enum JTokenType jtt) {
  switch (jtt) {
    case kTokenNull:
    case kTokenFalse:
    case kTokenTrue:
    case kTokenNumber:
    case kTokenString:
      return true;
    default:
      return false;
  }
}

static inline bool IsSpace(int ch) {
  switch (ch) {
    case 0x20: 
    case 0x09:
    case 0x0a:
    case 0x0d:
      return true;
    default:
      return false;
  };
}

#endif