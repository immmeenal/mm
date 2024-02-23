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

// Function to calculate the greatest common divisor
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate the modular multiplicative inverse
int modInverse(int a, int mod) {

    for (int x = 1; x < mod; x++) {
        if (((a % mod) * (x % mod)) % mod == 1) {
            return x;
        }
    }
    return -1; // If no modular inverse exists
}


// Function to encrypt a character
char encryptChar(char plainChar, int key) {
    if (!isalpha(plainChar)) return plainChar; // Ignore non-alphabetic characters
    int index = charToIndex(plainChar);
    return indexToChar((index * key) % 26);
}

// Function to decrypt a character
char decryptChar(char cipherChar, int key) {
    if (!isalpha(cipherChar)) return cipherChar; // Ignore non-alphabetic characters
    int index = charToIndex(cipherChar);
    int inverse = modInverse(key, 26);
    if (inverse == -1) {
         exit(1);
    }
    
    return indexToChar((index * inverse) % 26);
}

int main() {
    string plaintext;
    int key;

    // Input plaintext
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    // Input key and validate it
    do {
        cout << "Enter the key (an integer in Z26* and non-zero integer): ";
        cin >> key;
    } while (key==0);  

  
    
    if((gcd(key, 26) == 1)){
        cout << "GCD(" << key << ", " << "26" << ") == 1, hence multiplicative inverse exist." << endl;
        int inverse = modInverse(key, 26);
        if (inverse != -1) {
            cout << "The multiplicative inverse of " << key << " under mod " << 26 << " is " << inverse << endl;
            
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
        }
    }
    else{
        cout << "GCD(" << key << ", " << 26 << ") != 1, hence multiplicative inverse does not exist. \nCannot perform multiplicative cipher. " << endl;
    }


    return 0;
}
