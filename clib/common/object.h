#ifndef UNILIB_CLIB_COMMON_COBJECT_H
#define UNILIB_CLIB_COMMON_COBJECT_H

#include <memory>

class CObject
{
 public:
  template<typename T>
  CObject(T value) : ptr_(std::make_unique<Derived<T>>(value)) {}

  class Base {
   public:
    virtual ~Base() = default;  
  };

  template<typename T>
  class Derived : public Base {
   public:
    explicit Derived(const T& value) {
      value_ = value;
    }
    T value_;
  };

 private:
  std::unique_ptr<Base> ptr_;
};

#endif