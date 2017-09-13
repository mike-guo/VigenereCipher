//////////////////////////////////////////////////////////////////////////
// Vigenere Cipher & Vigenere Square
// --- by Mike 16.09.15 
// 
// For GaaYII
//
// Happy Mid-Autumn Day! 
//
#include <stdio.h>
#include <string>
#include "VigenereCipher.h"

#define		USER_LENGTH		200

enum MODE { ENCODE = 1, DECODE };


bool TextSizeJudge(char text[], int size);
void ModeProcess(MODE mode);



void main()
{
	VigenereCipher vc;
	vc.VigenereSquare();

	printf("\n                    Vigenere Cipher \n");

	printf("\nTIPS of working mode: \n");
	printf(" - Input \"1\" for Encode Mode, \"2\" for Decode Mode; \n");
	printf(" - Input \"help\" to show Vigenere Square. \n");

	printf("\nTIPS of inputting text: \n");
	printf(" - Only letters will be read, which means space, \n");
	printf("   punctuation and other symbols will be ignored; \n");
	printf(" - Less than %d characters are required for each text. \n", USER_LENGTH);

	printf("\nNow let's go! \n\n\n");


	while(true)
	{
		char mode[5] = "\0";
		printf("\nSelect working mode: ");
		scanf("%s", mode);
		getchar();

		// Encode Mode
		if (strcmp(mode, "1") == 0)
		{
			ModeProcess(ENCODE);
		}
		
		// Decode Mode
		else if (strcmp(mode, "2") == 0)
		{
			ModeProcess(DECODE);
		}

		// Help Mode
		else if (strcmp(mode, "help") == 0)
		{
			vc.VigenereSquare();
		}

		// Invalid instruction
		else
		{
			printf("\nInvalid instruction! Please retry.\n\n\n");
		}
	}
}

void ModeProcess(MODE mode)
{
	char sz_mode[10];
	char sz_in[10];
	char sz_out[10];

	switch (mode)
	{
	case ENCODE:
		strcpy_s(sz_mode, "Encode");
		strcpy_s(sz_in, " Plain");
		strcpy_s(sz_out, "Cipher");
		break;

	case DECODE:
		strcpy_s(sz_mode, "Decode");
		strcpy_s(sz_in, "Cipher");
		strcpy_s(sz_out, " Plain");
		break;
	}

	//char scanFormat[100] = "\0";
	//sprintf(scanFormat, "%%%d[^\\n]", USER_LENGTH);
	
	VigenereCipher vc;
	while (true)
	{
		printf("\n%s Mode\n", sz_mode);

		char key[USER_LENGTH] = "\0";
		printf("\nInput Key Text     : ");
		scanf("%[^\n]", key);
		//scanf(scanFormat, key);
		getchar();

		int size_key = strlen(key);
		if (!TextSizeJudge("Key", size_key))
		{
			continue;
		}

		FormatText(key, size_key);
		if (!TextSizeJudge("Key", size_key))
		{
			continue;
		}

		vc.SetKey(key);
		break;
	}

	while (true)
	{
		char in[USER_LENGTH] = "\0";
		printf("\nInput %s Text  : ", sz_in);
		scanf("%[^\n]", in);
		//scanf(scanFormat, plain);
		getchar();

		int size_in = strlen(in);
		if (!TextSizeJudge(sz_in, size_in))
		{
			printf("\n%s Mode\n", sz_mode);
			printf("\nInput Key Text     : %s\n", vc.getKey());
			continue;
		}

		FormatText(in, size_in);
		if (!TextSizeJudge(sz_in, size_in))
		{
			printf("\n%s Mode\n", sz_mode);
			printf("\nInput Key Text     : %s\n", vc.getKey());
			continue;
		}

		(mode == ENCODE) ? vc.SetPlain(in) : vc.SetCipher(in);
		break;
	}

	//char out[USER_LENGTH] = "\0";
	if ((mode == ENCODE) ? vc.Encode(/*out*/) : vc.Decode(/*out*/))
	{
		printf("\nThe %s Text is : %s\n\n\n", /*sz_out, out);*/
			sz_out, (mode == ENCODE) ? vc.getCipher() : vc.getPlain());
	} 
	else
	{
		printf("\nError occurs! Please retry.\n\n\n");
	}
}

bool TextSizeJudge(char text[], int size)
{
	if (size < 1)
	{
		printf("\nError! %s Text can't be empty. Please retry.\n\n\n", text);
		return false;
	}

	if (size > USER_LENGTH)
	{
		printf("\nError! %s Text is too long. Please retry.\n\n\n", text);
		return false;
	}

	return true;
}