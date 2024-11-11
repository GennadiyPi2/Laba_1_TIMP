#ifndef TABLE_TRANSPOSITION_H
#define TABLE_TRANSPOSITION_H

#include <string>

class TableTranspositionCipher {
public:
    TableTranspositionCipher(int numColumns);

    std::string encrypt(const std::string& plaintext);
    std::string decrypt(const std::string& ciphertext);

private:
    int numColumns;
};

#endif