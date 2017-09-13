//////////////////////////////////////////////////////////////////////////
// Vigenere Cipher & Vigenere Square
// --- by Mike 16.09.15 
// 
// For GaaYII
//
// Happy Mid-Autumn Day! 
//
#include "VigenereCipher.h"
#include <stdio.h>
#include <string>


VigenereCipher::VigenereCipher(void)
{
	strcpy_s(key, "\0");
	strcpy_s(plain, "\0");
	strcpy_s(cipher, "\0");
}

VigenereCipher::~VigenereCipher(void)
{
	if (strcmp(key, "\0"))
	{
		strcpy_s(key, "\0");
	}
	if (strcmp(plain, "\0"))
	{
		strcpy_s(plain, "\0");
	}
	if (strcmp(cipher, "\0"))
	{
		strcpy_s(cipher, "\0");
	}
}

void VigenereCipher::SetKey(char keyText[])			
{
	strcpy_s(key, keyText);
}

void VigenereCipher::SetPlain(char plainText[])		
{ 
	strcpy_s(plain, plainText); 
}

void VigenereCipher::SetCipher(char cipherText[])
{ 
	strcpy_s(cipher, cipherText); 
}

void VigenereCipher::VigenereSquare()
{
	printf("\n                    Vigenere Square \n");
	printf("\n    ");
	for (int i = 0; i < LETTER_NUM; i++)
	{
		printf("%c ", i + 'A');
	}
	printf("\n    ");
	for (int i = 0; i < LETTER_NUM; i++)
	{
		printf("- ");
	}
	printf("\n");
	for (int i = 0; i < LETTER_NUM; i++)
	{
		printf("%c | ", i + 'A');
		for (int j = 0; j < LETTER_NUM; j++)
		{
			char letter = i + 'A' + j;
			printf("%c ", (letter > 'Z') ? (letter - LETTER_NUM) : letter);
		}
		printf("\n");
	}	
	printf("\n\n");
}

bool VigenereCipher::Encode(/*char cipherText[]*/)
{
	int size_key = strlen(key);
	int size_plain = strlen(plain);

	if (size_key < 1 || size_plain < 1)
	{
		return false;
	}
	
	for (int i = 0; i < size_plain; i++)
	{		
		cipher[i] = plain[i] + (key[i % size_key] - 'A');
		//cipher[i] = plain[i] + key[i % size_key] - 'A';
		if (cipher[i] > 'Z')
		{
			cipher[i] -= LETTER_NUM;
		}
	}
	cipher[size_plain] = '\0';
	//strcpy_s(cipherText, cipher);
	return true;
}

bool VigenereCipher::Decode(/*char plainText[]*/)
{
	int size_key = strlen(key);
	int size_cipher = strlen(cipher);

	if (size_key < 1 || size_cipher < 1)
	{
		return false;
	}

	for (int i = 0; i < size_cipher; i++)
	{
		plain[i] = cipher[i] - (key[i % size_key] - 'A');
		//plain[i] = cipher[i] - key[i % size_key] + 'A';
		if (plain[i] < 'A')
		{
			plain[i] += LETTER_NUM;
		}
	}
	plain[size_cipher] = '\0';
	//strcpy_s(plainText, plain);
	return true;
}



/*int Sizeof(char sz[])
{
	int res = 0;
	while (sz[res] != '\0')
	{
		res++;
	}
	return res;
}*/

void FormatText(char sz[], int& size)
{
	char diff = 'a' - 'A';
	int i = 0;
	while (i < size)
	{
		if (sz[i] >= 'A' && sz[i] <= 'Z')
		{
			i++;
		} 
		else if (sz[i] >= 'a' && sz[i] <= 'z')
		{			
			sz[i] -= diff;
			i++;
		}
		else
		{
			for (int j = i; j < size; j++)
			{
				sz[j] = sz[j + 1];
			}
			size--;
		}
	}
}