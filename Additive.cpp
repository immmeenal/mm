#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to convert a character to its corresponding index in the range 0-25
int charToIndex(char ch) {
    return toupper(ch) - 'A';
}

// Function to convert an index in the range 0-25 to its corresponding character
char indexToChar(int index) {
    return static_cast<char>(index + 'A');
}

// Function to encrypt a character
char encryptChar(char plainChar, int key) {
    if (!isalpha(plainChar)) return plainChar; // Ignore non-alphabetic characters
    int index = charToIndex(plainChar);
    return indexToChar((index + key +26) % 26);
}

// Function to decrypt a character
char decryptChar(char cipherChar, int key) {
    if (!isalpha(cipherChar)) return cipherChar; // Ignore non-alphabetic characters
    int index = charToIndex(cipherChar);
    return indexToChar((index - key + 26) % 26);
}


int main() {
    string plaintext;
    int key;

    // Input plaintext
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    // Input key and validate it
    do {
        cout << "Enter the key (non-zero integer): ";
        cin >> key;
    } while (key==0);

    // Encryption
    string ciphertext = "";
    for (char ch : plaintext) {
        ciphertext += encryptChar(ch, key);
    }
    cout << "Encrypted text: " << ciphertext << endl;

    // Decryption
    string decryptedText = "";
    for (char ch : ciphertext) {
        decryptedText += decryptChar(ch, key);
    }
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
