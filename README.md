# ESP-AES

## Overview

This project demonstrates how to implement AES encryption and decryption using an ESP32 microcontroller. The core functionality is encapsulated in a custom `Cipher` class, which performs encryption and decryption using the AES algorithm. This project also leverages the ESP32 hardware random number generator to create secure initialization vectors (IVs).

## Features

- AES-128 encryption and decryption
- Random Initialization Vector (IV) generation using hardware-based RNG
- Key and IV management
- Encryption and decryption tests using predefined payloads
- Serial output for debugging and result verification

## Components

- **Cipher Class**: The class manages AES encryption/decryption, IV generation, and key storage. It also provides methods for resetting IVs to their original state and for retrieving the current IV.
- **Test Sketch**: A simple test function is provided to encrypt and decrypt three predefined 21-byte payloads. The results are verified through serial output.

## Prerequisites

1. **ESP32 Board**: You will need an ESP32 microcontroller to run this sketch.
2. **Arduino IDE**: Ensure you have the Arduino IDE installed and configured for ESP32 development.
3. **AESLib Library**: This project requires the [AESLib](https://github.com/DavyLandman/AESLib) library for AES encryption and decryption. Install it via the Arduino Library Manager.

## Circuit

No additional circuit components are needed for this sketch, aside from the ESP32 connected to a computer for serial communication.

## Installation

1. **Clone or Download** this project.
2. Open the project in **Arduino IDE**.
3. Ensure that you have the **AESLib** library installed.
4. Connect your **ESP32** board to the computer.
5. Select the appropriate board and port in Arduino IDE.
6. Upload the sketch to your ESP32.

## Usage

1. Once the sketch is uploaded, open the **Serial Monitor** in Arduino IDE.
2. Set the baud rate to `115200`.
3. The test function will automatically run, encrypting and decrypting predefined payloads.
4. The results of the encryption and decryption process will be printed on the Serial Monitor.

## Code Structure

### Cipher Class

- `Encrypt(byte* i_Msg, uint16_t i_MsgLen, byte* i_Ciphertext)`: Encrypts the provided message using AES-128 and stores the result in the `i_Ciphertext` buffer.
- `Decrypt(byte* i_Ciphertext, uint16_t i_CipherLen, byte* i_Cleartext)`: Decrypts the ciphertext back into plaintext.
- `RandVector()`: Generates a new random IV using the ESP32 hardware RNG.
- `ResetVector()`: Resets the IV to its original state after encryption or decryption.
- `GetCurrVector()`: Returns the current IV.

### Sketch Functions

- `test()`: Encrypts and decrypts three sample messages to verify the functionality of the Cipher class.
- `performEncryptionDecryption(byte* message)`: Handles the encryption and decryption of a single message and compares the result to the original message to ensure correctness.

## Serial Output Example

```
Calling encrypt (string)...
Calling decrypt...; 
Decrypted correctly.
Calling encrypt (string)...
Calling decrypt...; 
Decrypted correctly.
Calling encrypt (string)...
Calling decrypt...; 
Decrypted correctly.
```

## Customization

- **Change the AES Key**: You can modify the key used for AES encryption by adjusting the `keyInit` array in the `Cipher` constructor.
- **Modify Payloads**: Update the `message1`, `message2`, and `message3` variables in the `test()` function to test different payloads.

## Limitations

- This sketch uses **AES-128**, meaning the key size is fixed at 16 bytes (128 bits). For other AES key sizes (192-bit or 256-bit), modifications are required.
- The maximum message size is 21 bytes, as demonstrated in the sketch. For larger payloads, the buffer sizes must be adjusted accordingly.
