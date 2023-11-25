/*
В текстовом файле input.txt записан русский текст. 
Найти в тексте слова, содержащие букву, не входящую ни в одно из слов текста с максимальной длиной, 
записать их заглавными буквами и указать после каждого такого слова в скобках найденные буквы. 
Полученный текст записать в файл output.txt. Весь текст, кроме найденных слов, должен остаться неизменным, включая и знаки препинания.

Мои мысли:
Буква, которой нет в словах с макс. длиной - записать заглавными буквами и указать в скобках после слова. 
Буквы, которые встречаются в словах с макс. длиной - записать без изменений.
Слова, в которых встречаются все буквы из слов с макс. длиной или сами слова с макс. длиной - записать без изменений.
*/

#include <iostream>
#include <fstream>
#include "StringFunctions.hpp"

void ResetBoolMassive(bool *mas, int len)
{
	for (int i = 0; i < len; i++)
	{
		mas[i] = false;
	}
}

bool IsHaveCharInBoolMassive(char chr, bool* mas)
{
	return mas[chr + 32];
}

void CheckAndWriteChars(char* str, bool* out)
{
	int i = 0;
	while (str[i] != '\0')
	{
		char chr = str::ToLower(str[i]);
		if (str::IsRusChar(chr))
			out[chr + 32] = true;
		
		i++;
	}
}
//Проверяет, есть ли в str буквы, которых нет в словах с максимальной длиной.
//Если встречается буква, которой нет в словах с макс. длиной, возращаяет true
//Если таких букв нет - возращяет false
bool CheckCharsInStr(char* str, bool* alphabet)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (!IsHaveCharInBoolMassive(str::ToLower(str[i]), alphabet)) return true;
		i++;
	}
	return false;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	
	char** words = new char* [2000];

	std::ifstream in("input.txt");
	if (!in.is_open())
	{
		std::cout << "Файл не существует";
		return 0;
	}

	int countWords = 0;
	int maxLenWord = 0;
	bool alphabet[32];

	ResetBoolMassive(alphabet, 32);					//Инициализируем массив

	while (!in.eof())								//Считываем слова
	{
		char word[101];
		in >> word;

		char* w = new char[strlen(word) + 1];
		str::CopyStr(w, word);
		words[countWords] = w;

		int countChar = str::CountCharsInStr(w);	//Кол-во русских букв в слове
		if (maxLenWord < countChar)					
		{
			maxLenWord = countChar;
			ResetBoolMassive(alphabet, 32);
			CheckAndWriteChars(words[countWords], alphabet);	//Заполняем массив alphabet, в котором элемент i будет равен true, 
		}														//если встретится прописная русская буква с номером i
		else if(maxLenWord == countChar)
			CheckAndWriteChars(words[countWords], alphabet);

		countWords++;
	}


	char* out = new char[maxLenWord*countWords*countWords];			//Строка с полученным результатом
	int p = 0;														//Указатель на текущую позицию в строке
	for (int i = 0; i < countWords; i++)
	{
		int len = strlen(words[i]);
		int lenChr = len;
		char sign;
		bool isDontHaveChar = CheckCharsInStr(words[i], alphabet);	//См. описания функции

		if (!str::IsRusChar(words[i][len - 1]))						//Если это не русская буква, т.е. знак препинания
		{
			lenChr--;												//Уменьшаем длину слова
			sign = words[i][lenChr];								//Сохраняем знак препинания
		}

		if (lenChr == maxLenWord || !isDontHaveChar)				//Если это слово с макс. длиной или в этом слове нет букв, которые
		{															//встречаются в словах с макс. длиной
			for (int o = 0; o < len; o++)							//То просто переписываем его до конца вместе со знаком препинания(если он есть)
			{
				out[p] = words[i][o];
				p++;
			}
			out[p] = (char)32;
			p++;
			continue;
		}

		int end = p + lenChr + 1;									//Указатель на конец слова
		out[end - 1] = '(';
		for (int o = 0; o < lenChr; o++)
		{
			if (!IsHaveCharInBoolMassive(words[i][o], alphabet))	//Если данная буква не встречается в слове с макс. длиной
			{
				out[end] = str::ToLower(words[i][o]);				//Записываем букву в конец
				out[p] = str::ToUpper(words[i][o]);					//Записываем букву в текущую позицию в строке с заглавной буквы
				end++;
			}
			else													//Если данная буква встречается - просто переписываем ее.
			{
				out[p] = words[i][o];
			}
			
			p++;
		}

		out[end] = ')';												
		p = end + 1;

		if (len != lenChr)											//В случае, если у нас есть знак препинания
		{
			out[p] = sign;											//Ставим его в конце после скобки
			p++;
		}
		out[p] = (char)32;
		p++;
	}
	out[p] = '\0';

	std::ofstream output("output.txt");

	output << out;
	
	return 0;
}