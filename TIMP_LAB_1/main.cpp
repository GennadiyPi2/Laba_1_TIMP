#include <locale>
#include <codecvt>
#include <iostream>
#include "modAlphaCipher.h"
using namespace std;
locale loc("ru_RU.UTF-8");
// проверка, чтобы строка состояла только из прописных букв
bool isValid(const wstring& s)
{ 
	for(auto c:s)
		if (!isalpha(c,loc) || !isupper(c,loc))
			return false;
	return true;
}

int main()
{ 
	//locale loc("ru_RU.UTF-8");
	locale::global(loc); // установка глобальной локали
	wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
	wstring key;
	wstring text;
	unsigned op;
	wcout<<L"Cipher готов. Введите ключ: ";
	wcin>>key;
	if (!isValid(key)) {
		wcerr<<"ERROR\n";
		return 1;
	}	

wcout<<"Key loaded\n";
modAlphaCipher cipher(key);
do {
	wcout<<"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
	wcin>>op;
	if (op > 2) {
		wcout<<"Illegal operation\n";
	} 
	else if (op >0) {
		wcout<<"Cipher ready. Input text: ";
		wcin>>text;
		if (isValid(text)) 
			{
			if (op==1) 
				{
					wcout<<"Encrypted text: "<<cipher.encrypt(text)<<endl;
				} else 
					{
						wcout<<"Decrypted text: "<<cipher.decrypt(text)<<endl;
					}
				} else 
			{
			wcout<<"Operation aborted: invalid text\n";
			}
		}
	} while (op!=0);
	return 0;
}