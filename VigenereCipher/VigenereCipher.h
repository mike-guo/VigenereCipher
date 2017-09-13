//////////////////////////////////////////////////////////////////////////
// Vigenere Cipher & Vigenere Square
// --- by Mike 16.09.15 
// 
// For GaaYII
//
// Happy Mid-Autumn Day! 
//
#pragma once

#define		MAX_LENGTH		256
#define		LETTER_NUM		26


class VigenereCipher
{
public:
	VigenereCipher(void);
	~VigenereCipher(void);

private:
	char key[MAX_LENGTH];
	char plain[MAX_LENGTH];
	char cipher[MAX_LENGTH];

public:
	void SetKey(char keyText[]);
	void SetPlain(char plainText[]);
	void SetCipher(char cipherText[]);
	char* getKey()		{ return key; }
	char* getPlain()	{ return plain; }
	char* getCipher()	{ return cipher; }

public:
	void VigenereSquare();
	bool Encode(/*char cipherText[]*/);
	bool Decode(/*char plainText[]*/);
};



//int Sizeof(char sz[]); // Stop counting till '\0' occurs at the first time
void FormatText(char sz[], int& size); // Ignore space, punctuation and other symbols