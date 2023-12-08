#include <iostream>
#include <fstream>

bool IsUpperChar(char chr) { return (chr >= 'A' && chr <= 'Z'); }
bool IsLowerChar(char chr) { return (chr >= 'a' && chr <= 'z'); }
bool IsPunMark(char chr) { return chr == '!' || chr == ',' || chr == '.' || chr == ' ' || chr == ':'; }

void Encrypt()
{
	std::ifstream in("input.txt");
	std::ofstream out("outputEncrypt.txt");
	if (!in.is_open())
	{
		std::cout << "File not exist" << '\n';
		return;
	}

	int key = 0;
	int keyPunMarks = 0;

	std::cout << "Key to encrypt: ";
	std::cin >> key;

	key = key % 26;
	keyPunMarks = key % 4;

	char inChr;
	while (in.get(inChr))
	{
		unsigned char currentChr = inChr;
		char PunChars[6] = " !,.:";
		if (IsUpperChar(currentChr))
		{
			currentChr += key;
			if (currentChr > 'Z') currentChr -= 26;
		}
		else if (IsLowerChar(currentChr))
		{
			currentChr += key;
			if (currentChr > 'z') currentChr -= 26;
		}
		else if (IsPunMark(currentChr))
		{
			int pos;
			for (pos = 0; pos < 5; pos++)
			{
				if (currentChr == PunChars[pos]) break;
			}
			pos += keyPunMarks;
			if (pos > 4) pos -= 5;
			currentChr = PunChars[pos];
		}
		out << currentChr;
		out << char((currentChr + key + keyPunMarks) % 26 + 'a');
		out << char(((currentChr + key + keyPunMarks) * 3) % 26 + 'a');
	}
}

void Decrypt()
{
	std::ifstream in("outputEncrypt.txt");
	std::ofstream out("outputDecrypt.txt");
	if (!in.is_open())
	{
		std::cout << "File not exist" << '\n';
		return;
	}

	int key = 0;
	int keyPunMarks = 0;

	std::cout << "Key to decrypt: ";
	std::cin >> key;

	key = key % 26;
	keyPunMarks = key % 4;

	char inChr;
	int count = 0;
	while (in.get(inChr))
	{
		if (count != 0)
		{
			count = (count + 1)%3;
			continue;
		}
		unsigned char currentChr = inChr;
		char PunChars[6] = " !,.:";
		if (IsUpperChar(currentChr))
		{
			currentChr -= key;
			if (currentChr < 'A') currentChr += 26;
		}
		else if (IsLowerChar(currentChr))
		{
			currentChr -= key;
			if (currentChr < 'a') currentChr += 26;
		}
		else if (IsPunMark(currentChr))
		{
			int pos;
			for (pos = 0; pos < 5; pos++)
			{
				if (currentChr == PunChars[pos]) break;
			}
			pos -= keyPunMarks;
			if (pos < 0) pos += 5;
			currentChr = PunChars[pos];
		}
		out << currentChr;
		count++;
	}
}
int main()
{
	Encrypt();
	Decrypt();
	return 0;
}