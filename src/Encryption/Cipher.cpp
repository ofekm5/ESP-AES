#include "Cipher.h"

Cipher::Cipher() {
  this->m_AesKey = new byte[KEY_SIZE];
  this->m_EncIV = new byte[VECTOR_SIZE];
  this->m_EncIVDup = new byte[VECTOR_SIZE];
      
  byte keyInit[16] = { 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA };
  memcpy(m_AesKey, keyInit, 16);
  this->m_AesLib.set_paddingmode((paddingMode)0); // No padding, AES block size will handle it
}

Cipher::~Cipher() {
  delete[] this->m_AesKey;
  delete[] this->m_EncIV;
  delete[] this->m_EncIVDup;
}

uint16_t Cipher::Encrypt(byte* i_Msg, uint16_t i_MsgLen, byte* i_Ciphertext) {
  Serial.println("Calling encrypt (string)...");
  int cipherlength = this->m_AesLib.encrypt(i_Msg, i_MsgLen, i_Ciphertext, this->m_AesKey, 16, this->m_EncIV);
  return cipherlength;
}

uint16_t Cipher::Decrypt(byte* i_Ciphertext, uint16_t i_CipherLen, byte* i_Cleartext) {
  Serial.print("Calling decrypt...; ");
  uint16_t dec_bytes = this->m_AesLib.decrypt(i_Ciphertext, i_CipherLen, i_Cleartext, this->m_AesKey, 16, this->m_EncIV);
  return dec_bytes;
}

void Cipher::RandVector(){
  for (size_t i = 0; i < VECTOR_SIZE; i++) {
    this->m_EncIVDup[i] = esp_random() & 0xFF;  // Generate a random byte using hardware RNG
  }
  memcpy(this->m_EncIV, this->m_EncIVDup, VECTOR_SIZE);
}

void Cipher::ResetVector(){
  memcpy(this->m_EncIV, this->m_EncIVDup, VECTOR_SIZE);
}

byte* Cipher::GetCurrVector(){
  return this->m_EncIVDup;
}
