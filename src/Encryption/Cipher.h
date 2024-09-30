#ifndef Cipher_H
#define Cipher_H

#include "AESLib.h"
#include "esp_system.h"

#define KEY_SIZE 16
#define VECTOR_SIZE 16

class Cipher {
  public:
    Cipher();
    ~Cipher();
    uint16_t Encrypt(byte* i_Msg, uint16_t i_MsgLen, byte* i_Ciphertext);
    uint16_t Decrypt(byte* i_Ciphertext, uint16_t i_CipherLen, byte* i_Cleartext);
    void RandVector();
    void ResetVector();
    byte* GetCurrVector();
  private:
    AESLib m_AesLib;
    byte* m_AesKey;    
    byte* m_EncIV;    
    byte* m_EncIVDup;  // Original IV for resetting after each encryption/decryption mutation
};

#endif 
