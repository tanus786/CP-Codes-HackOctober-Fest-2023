#include <bits/stdc++.h>
using namespace std;

//function to encrypt
string caesarEncrypt(const string &plaintext, int shift)
{
    string encryptedText = "";
    for (char c : plaintext)
    {
        if (isalpha(c))
        {
            char base = (islower(c)) ? 'a' : 'A';
            encryptedText += static_cast<char>((c - base + shift) % 26 + base);
        }
        else
        {
            encryptedText += c;
        }
    }
    return encryptedText;
}
//function to decrypt
string caesarDecrypt(const string &ciphertext, int shift)
{
    return caesarEncrypt(ciphertext, 26 - shift);
}

//driver function
int main()
{
    cout << "Caesar Cipher Encryption and Decryption" << endl;

    int choice;

    cout << "Select an option:" << endl;
    cout << "1. Encrypt" << endl;
    cout << "2. Decrypt" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    cin.ignore();

    string text;
    int shift;

    
    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the shift value (0-25): ";
    cin >> shift;

    if (shift < 0 || shift > 25)
    {
        cout << "Invalid shift value. Exiting..." << endl;
        return 1;
    }

    if (choice == 1)
    {

        string encryptedText = caesarEncrypt(text, shift);
        cout << "Encrypted text: " << encryptedText << endl;
    }
    else if (choice == 2)
    {

        string decryptedText = caesarDecrypt(text, shift);
        cout << "Decrypted text: " << decryptedText << endl;
    }
    else
    {
        cout << "Invalid choice. Exiting..." << endl;
        return 1;
    }

    return 0;
}
