#include <iostream>
#include <string>
#include <algorithm>
#include <random>
using namespace std;

const string FIXED_KEY = "CRYPTOMASTER2024";
const int MIN_CHAR = 32;
const int MAX_CHAR = 126;
const int RANGE = MAX_CHAR - MIN_CHAR + 1;

string getShuffledAlphabet() {
    string alphabet;
    for (int i = MIN_CHAR; i <= MAX_CHAR; i++) {
        alphabet += char(i);
    }
    
    mt19937 rng(hash<string>{}(FIXED_KEY));
    shuffle(alphabet.begin(), alphabet.end(), rng);
    return alphabet;
}

string encryptText(const string& text) {
    string alphabet;
    for (int i = MIN_CHAR; i <= MAX_CHAR; i++) {
        alphabet += char(i);
    }
    string shuffled = getShuffledAlphabet();
    
    string result;
    for (char c : text) {
        size_t pos = alphabet.find(c);
        if (pos != string::npos) {
            result += shuffled[pos];
        } else {
            result += c;
        }
    }
    return result;
}

string decryptText(const string& text) {
    string alphabet;
    for (int i = MIN_CHAR; i <= MAX_CHAR; i++) {
        alphabet += char(i);
    }
    string shuffled = getShuffledAlphabet();
    
    string result;
    for (char c : text) {
        size_t pos = shuffled.find(c);
        if (pos != string::npos) {
            result += alphabet[pos];
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    int choice;
    string input;
    
    cout << "========================================\n";
    cout << "      CRYPTO FIXED v1.0\n";
    cout << "========================================\n";
    cout << "No key needed. Same input always gives same output.\n\n";
    
    do {
        cout << "1. Encrypt\n";
        cout << "2. Decrypt\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                cout << "Enter text to encrypt: ";
                getline(cin, input);
                cout << "Encrypted: " << encryptText(input) << "\n\n";
                break;
            case 2:
                cout << "Enter text to decrypt: ";
                getline(cin, input);
                cout << "Decrypted: " << decryptText(input) << "\n\n";
                break;
            case 0:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice!\n\n";
        }
    } while (choice != 0);
    
    return 0;
}