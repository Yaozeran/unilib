/** Copyright (c) 2016 Pieter Wuille */

#ifndef CRYPTO_AES_H
#define CRYPTO_AES_H

#include <cstdint>
#include <cstdlib>

typedef struct {
  uint16_t slice[8]; 
} aes_state;

typedef struct {
  aes_state rk[11];
} aes128_ctx;

typedef struct {
  aes_state rk[13];
} aes192_ctx;

typedef struct {
  aes_state rk[15];
} aes256_ctx;

void AES128Encrypt(const aes128_ctx ctx, size_t blocks, unsigned char* plain16, unsigned char* cipher16);

void AES192Encrypt(const aes192_ctx ctx, size_t blocks, unsigned char* plain16, unsigned char* cipher16);

void AES256Encrypt(const aes256_ctx ctx, size_t blocks, unsigned char* plain16, unsigned char* cipher16);

#endif 