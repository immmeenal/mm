#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to encrypt the plaintext using the Vigenère cipher
string encrypt(string plaintext, string key) {
    string ciphertext = "";
    int keyLen = key.length();
    int j = 0; // Index for the key
    for (char c : plaintext) {
        if (!isalpha(c)) {
            // Skip non-alphabetic characters
            ciphertext += c;
            continue;
        }
       
        char encryptedChar = ((toupper(c)- 'A') + (toupper(key[j]) - 'A')) % 26 + 'A'; // Encryption formula
        ciphertext += encryptedChar;
        j = (j + 1) % keyLen; // Move to the next key character
    }
    return ciphertext;
}

// Function to decrypt the ciphertext using the Vigenère cipher
string decrypt(string ciphertext, string key) {
    string plaintext = "";
    int keyLen = key.length();
    int j = 0; // Index for the key
    for (char c : ciphertext) {
        if (!isalpha(c)) {
            // Skip non-alphabetic characters
            plaintext += c;
            continue;
        }
       
        char decryptedChar = ((toupper(c) - 'A') - (toupper(key[j]) - 'A') + 26) % 26 + 'A'; // Decryption formula
        plaintext += decryptedChar;
        j = (j + 1) % keyLen; // Move to the next key character
    }
    return plaintext;
}

int main() {
    string plaintext, key;

    // Input plaintext
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    // Input key
    cout << "Enter the key: ";
    cin >> key;

    // Encrypt the plaintext
    string ciphertext = encrypt(plaintext, key);
    cout << "Encrypted text: " << ciphertext << endl;

    // Decrypt the ciphertext
    string decryptedText = decrypt(ciphertext, key);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
