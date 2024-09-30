#include "Cipher.h"

#define BAUD 115200
#define INPUT_BUFFER_LIMIT (31 + 1)  // 21 bytes for payload + 1 for null-terminator
#define CIPHER_BUFFER_LIMIT 32

Cipher Cipher;
byte cleartext[INPUT_BUFFER_LIMIT] = {0};
byte ciphertext[CIPHER_BUFFER_LIMIT] = {0};  // Twice the size for ciphertext

void test(){
  byte message1[31] = "21_byte_payload_tesqaaaaaaaaaa";
  byte message2[31] = "21_byte_payload_saadaaaaaaaaaa";
  byte message3[31] = "21_byte_payload_poiyaaaaaaaaaa";

  performEncryptionDecryption(message1);
  performEncryptionDecryption(message2);
  performEncryptionDecryption(message3);
}

void performEncryptionDecryption(byte* message) {
  Cipher.RandVector();
  uint16_t encLen = Cipher.Encrypt(message, sizeof(message), ciphertext);
  Cipher.ResetVector();
  uint16_t decLen = Cipher.Decrypt(ciphertext, encLen, cleartext);

  if(memcmp(message, cleartext, sizeof(message)) == 0) {
    Serial.println("Decrypted correctly.");
  } 
  else {
    Serial.println("Decryption test failed.");
  }
}

void setup() {
  Serial.begin(BAUD);
  test();
}

void loop() {}