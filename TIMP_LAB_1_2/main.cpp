#include <iostream>
#include "Table_Transposition.h"

int main()
{
    std::string plaintext;
    int key;
    unsigned op;

    std::cout << "Enter number of columns: ";
    std::cin >> key;
    std::cin.ignore();
    TableTranspositionCipher cipher(key);

    do {
        std::cout<<"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        std::cin>>op;
        if (op > 2) {
            std::cout<<"Illegal operation\n";
        } else if (op >0) {

            std::cout << "Enter plaintext: ";
            std::cin.ignore();
            std::getline(std::cin, plaintext);

            if (op==1) {

                std::string ciphertext = cipher.encrypt(plaintext);
                std::cout << "Encrypted text: " << ciphertext << std::endl;

            } else {

                std::string decryptedText = cipher.decrypt(plaintext);
                std::cout << "Decrypted text: " << decryptedText << std::endl;

            }

        }
    } while (op!=0);
    return 0;
}