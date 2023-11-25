/*
Дан файл, содержащий русский текст.
Найти в тексте N<=2000 слов, содержащих наибольшее кол-во сочетаний из двух гласных.
Записать найденные слова в текстовый файл в порядке убывания кол-ва сочетаний.
Для каждого слова вывести также это кол-во. Все найденные слова должны быть разными!
*/


#include <iostream>
#include <fstream>

char GetLowerCase(char chr)						//Функция для перевода символа в нижний регистр
{
	if (chr >= -64 && chr < -32)
	{
		return chr + 32;
	}
	return chr;
}

void StrToLower(char* str)						//Функция для перевода всей строки в нижний регистр
{
	int i = 0;
	while (str[i] != '\0')
	{
		str[i] = GetLowerCase(str[i]);
	}
}

bool IsVowel(char chr)							//Функция проверяющая гласная ли буква(символ)
{
	chr = GetLowerCase(chr);
	char vowels[21] = "аоэеиыуёюя";
	for (int i = 0; i < 10; i++)
	{
		if (chr == vowels[i]) return true;
	}
	return false;
}

void AddStr(char* dest, char* source)			//Функция для добавления строки в другую строку посимвольно
{
	int i = 0;
	while (source[i] != '\0')
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
}

bool IsStrEqual(char* first, char* second)				//Функция проверяющая одинаковы ли две строки
{
	if (strlen(first) != strlen(second)) return false;
	int i = 0;
	while (first[i] != '\0')
	{
		if (GetLowerCase(first[i]) != GetLowerCase(second[i])) return false;
		i++;
	}
	return true;
}

void SwapStr(char* first, char* second)					//Функция меняющая местами 2 строки
{
	char temp[101];
	AddStr(temp, first);
	AddStr(first, second);
	AddStr(second, temp);

}

int main()
{
	const int N = 2000;					//Кол-во слов
	const int L = 41;					//Кол-во букв в строке(20)
	std::setlocale(LC_ALL, "Rus");

	int* counts = new int[N];			//Указатель на массив с кол-во пар гласных в куч
	char* words = new char[N*L];		//Указатель на длинную строку в куче, где будут храниться слова
										//Тут можно было бы место длинной строки создать массив указателей
	std::ifstream in("input.txt");		//Которые указывали бы на строки и работать с ними

	int current = 0;					//Кол-во найденных слов, удовл-ющих условию
	while (!in.eof())
	{
		char word[L];
		int count = 0;					//Кол-во пар гласных в слове
		
		in >> word;						//Считываем слово
		
		int i = 0;
		while (word[i] != '\0')			//Переводим в нижний регистр и проверяем пары букв
		{
			if (i > 0 && IsVowel(word[i - 1]) && IsVowel(word[i]))
			{
				count++;
			}
			i++;
		}
		if (count != 0)
		{
			counts[current] = count;			//Записываем кол-во пар гласных слова
			AddStr(words + L*current, word);	//Записываем слово в строку
			current++;							
		}
		
		std::cout << word << " " << count << std::endl;
	}

	for (int i = 0; i < current-1; i++)				//Сортируем по убыванию кол-во пар гласных
	{
		for (int o = i + 1; o < current; o++)
		{
			if (counts[o] == 0) continue;
			if (IsStrEqual(words + L * i, words + L * o))	//Если найдено повторяющееся слово - 
			{												//ставим ему кол-во пар гласных в 0
				counts[o] = 0;								//В дальнейшем слова с нулевым кол-вом пар будут игнорироваться
				continue;
			}
			if (counts[i] < counts[o])						//Сортировка пузырьком
			{
				std::swap(counts[i], counts[o]);
				SwapStr(words + L * i, words + L * o);
			}
		}
	}

	std::fstream out("output.txt");
	for (int i = 0; i < current; i++)						//Записываем в выходной файл полученные слова
	{
		if (counts[i] == 0) continue;						//Игнорируем слова с 0 кол-вом пар гласных
		std::cout << counts[i] << " " << words + L * i << std::endl;
		out << words + L * i << std::endl;
	}

	return 0;
}