/* Name : Faraz Hayder
   Roll No. : I22-2687 */
#include <iostream>
#include <iomanip>
#include <string.h>
#include <bitset>
using namespace std;

void Encrypt(char[]);
void Decrypt(char[]);
string ToBinary(int);

int main()
{

	char charCoding[52];
	charCoding[0] = 'a';
	charCoding[1] = 'b';
	charCoding[2] = 'c';
	charCoding[3] = 'd';
	charCoding[4] = 'e';
	charCoding[5] = 'f';
	charCoding[6] = 'g';
	charCoding[7] = 'h';
	charCoding[8] = 'i';
	charCoding[9] = 'j';
	charCoding[10] = 'k';
	charCoding[11] = 'l';
	charCoding[12] = 'm';
	charCoding[13] = 'n';
	charCoding[14] = 'o';
	charCoding[15] = 'p';
	charCoding[16] = 'q';
	charCoding[17] = 'r';
	charCoding[18] = 's';
	charCoding[19] = 't';
	charCoding[20] = 'u';
	charCoding[21] = 'v';
	charCoding[22] = 'w';
	charCoding[23] = 'x';
	charCoding[24] = 'y';
	charCoding[25] = 'z';
	charCoding[26] = 'A';
	charCoding[27] = 'B';
	charCoding[28] = 'C';
	charCoding[29] = 'D';
	charCoding[30] = 'E';
	charCoding[31] = 'F';
	charCoding[32] = 'G';
	charCoding[33] = 'H';
	charCoding[34] = 'I';
	charCoding[35] = 'J';
	charCoding[36] = 'K';
	charCoding[37] = 'L';
	charCoding[38] = 'M';
	charCoding[39] = 'N';
	charCoding[40] = 'O';
	charCoding[41] = 'P';
	charCoding[42] = 'Q';
	charCoding[43] = 'R';
	charCoding[44] = 'S';
	charCoding[45] = 'T';
	charCoding[46] = 'U';
	charCoding[47] = 'V';
	charCoding[48] = 'W';
	charCoding[49] = 'X';
	charCoding[50] = 'Y';
	charCoding[51] = 'Z';

	Encrypt(charCoding);
	Decrypt(charCoding);

	return 0;
}

void Encrypt(char charCoding[52])
{

	string text = "";
	const char spaceString[] = " ";
	cout << "Enter text to be encrypted : ";
	getline(cin, text);
	int length = text.length();
	string tempCipher = "";
	string cipherText = "";
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < 52; j++)
		{
			if (text[i] == charCoding[j])
			{
				if (j >= 0 && j < 26)
				{
					int a = j + 96;
					tempCipher = ToBinary(a);
					cipherText = cipherText + tempCipher;
				}
				else if (j >= 26 && j < 52)
				{
					int a = j + 38;
					tempCipher = ToBinary(a);
					cipherText = cipherText + tempCipher;
				}
			}
		}
		if (text[i] == spaceString[0])
		{
			cipherText = cipherText + " ";
		}
	}
	cout << "Encrypted text : " << cipherText << endl;
}

void Decrypt(char charCoding[52])
{

	string text = "";
	const char spaceString[] = " ";
	cout << "\nEnter text to be decrypted : ";
	getline(cin, text);
	int length = text.length();
	string tempDecipher = "";
	string newText = "";
	string decipherText = "";
	int a = 0, t = 0;
	for (int i = 0; i <= length; i++)
	{
		newText = "";
		for (int j = 0; j < 5; j++)
		{
			if (text[t] == spaceString[0])
			{
				newText[0] = spaceString[0];
				j += 4;
				t++;
			}
			else
			{
				newText = newText + text[t];
				t++;
			}
		}
		if (newText[0] == spaceString[0])
		{
			decipherText = decipherText + " ";
			i += 1;
		}
		else
		{
			for (int k = 64; k < 90; k++)
			{
				tempDecipher = ToBinary(k);
				if (newText == tempDecipher)
				{
					a = k - 64;
					decipherText = decipherText + charCoding[a];
				}
			}
			i += 4;
		}
	}
	cout << "Decrypted text : " << decipherText << endl;
}

string ToBinary(int a)
{

	string binary = bitset<5>(a).to_string();
	return binary;
}

// Table of some decimals with their binary equivalents
/*int coding[52];
coding[0]=00000;
coding[1]=00001;
coding[2]=00010;
coding[3]=00011;
coding[4]=00100;
coding[5]=00101;
coding[6]=00110;
coding[7]=00111;
coding[8]=01000;
coding[9]=01001;
coding[10]=01010;
coding[11]=01011;
coding[12]=01100;
coding[13]=01101;
coding[14]=01110;
coding[15]=01111;
coding[16]=10000;
coding[17]=10001;
coding[18]=10010;
coding[19]=10011;
coding[20]=10100;
coding[21]=10101;
coding[22]=10110;
coding[23]=10111;
coding[24]=11000;
coding[25]=11001;
coding[26]=00000;
coding[27]=00001;
coding[28]=00010;
coding[29]=00011;
coding[30]=00100;
coding[31]=00101;
coding[32]=00110;
coding[33]=00111;
coding[34]=01000;
coding[35]=01001;
coding[36]=01010;
coding[37]=01011;
coding[38]=01100;
coding[39]=01101;
coding[40]=01110;
coding[41]=01111;
coding[42]=10000;
coding[43]=10001;
coding[44]=10010;
coding[45]=10011;
coding[46]=10100;
coding[47]=10101;
coding[48]=10110;
coding[49]=10111;
coding[50]=11000;
coding[51]=11001;*/

// Example text cypher and it's decypher:
// this is a sample text
// 10011001110100010010 0100010010 00000 100100000001100011110101100100 10011001001011110011
