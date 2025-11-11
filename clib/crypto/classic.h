#ifndef UNILIB_CLIB_CRYPTO_CLASSIC_H
#define UNILIB_CLIB_CRYPTO_CLASSIC_H

#include <string>
#include <array>
#include <vector>
#include <algorithm>

#include "csprng.h"

/**
 * A mono-alphabetic substitution cipher
 */
class SimpleSubstitution
{
 public:
  SimpleSubstitution() = default;
  ~SimpleSubstitution() = default;

  std::string Encrypt(std::string p, const std::array<char, 26>& k) {
    std::string c;
    for (char ch : p) {
      c.push_back(k[ch]);
    }
    return c;
  }
  std::string Decrypt(std::string c, const std::array<char, 26>& k) {
    std::string p;
    for (char ch : c) {
      auto iter = std::find(k.begin(), k.end(), ch);
      int index = iter - k.begin();
      p.push_back('A' + index);
    }
    return p;
  }
  /** a demo using letter frequency to attack */
  std::string Attack(std::string c) {
    std::string p;
    std::array<int, 26> cnt{};
    for (char ch : c) {
      cnt[ch]++;
    }
    std::array<char, 26> cnt_arr = GetSortedChars(cnt);
    std::array<char, 26> ftable_arr = GetSortedChars(ftable_);
    for (char ch : c) {
      auto iter = std::find(cnt_arr.begin(), cnt_arr.end(), ch);
      int index = iter - cnt_arr.begin();
      p.push_back(ftable_arr[index]);
    }
    return p;
  }
  inline static const std::array<double, 26>* GetTable() { return &ftable_; }
  template<typename T>
  inline static const std::array<char, 26> GetSortedChars(const std::array<T, 26>& arr) {
    std::array<char, 26> letters;
    for (int i = 0; i < 26; ++i) letters[i] = 'A' + i;
    std::sort(letters.begin(), letters.end(), [](char a, char b) -> bool {
      return arr[a - 'A'] > arr[b - 'A'];
    });
    return letters;
  }

 private:
  inline static const std::array<double, 26> ftable_ = {
    8.17, 1.49, 2.78, 4.25, 12.7, 2.23, 2.02, 6.09,
    6.97, 0.15, 0.77, 4.03, 2.41, 6.75, 7.51, 1.93,
    0.10, 5.99, 6.33, 9.06, 2.76, 0.98, 2.36, 0.15,
    1.97, 0.07
  };
};

/**
 * A poly-alphabetic substitution cipher
 */
class Vigenere
{
 public:
  std::string Encrypt(std::string p, const std::vector<int>& k) {
    std::string c;
    auto iter = k.begin();
    for (int i = 0; i < p.size(); ++i) {
      int shift = k[(i % k.size())];
      c.push_back('A' + ModPositive(p[i] - 'A' + shift, 26));
    }
    return c;
  }
  std::string Decrypt(std::string c, const std::vector<int>& k) {
    std::string p;
    auto iter = k.begin();
    for (int i = 0; i < p.size(); ++i) {

    }
  }
  std::string Attack(std::string c) {
    
  }
 private:
  inline static int ModPositive(int n, int m) {
    return (n % m + m) % m;
  }
};

/**
 * 
 */
class OneTimePad
{
 public:
  std::string Encrypt(std::string p) {
    
  }
};

#endif