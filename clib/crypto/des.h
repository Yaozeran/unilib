#ifndef UNILIB_CLIB_CRYPTO_DES_H
#define UNILIB_CLIB_CRYPTO_DES_H

#include <string>

/**
 * Data encrytion standard (DES) implementation
 * 
 * One round of a Feistel cipher
 *  L_i = R_{i-1}
 *  R_i = L_{i-1} XOR f(R_{i-1}, K_i)
 * 
 * One round of des
 *  key_{i-1} -> shift (produce key_{i}) -> compression permutation
 *  f(R_{i-1}, K_i): R_{i-1} -> expansion permutation -> XOR comp perm of keys
 *                   -> s-box substitution -> p-box permutation -> XOR L_{i-1}
 */
class DataEncryptionStandard 
{
 public:
  static inline void Encrypt();
  static inline void Decrypt();

};

#endif 