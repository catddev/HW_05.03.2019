#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>
#include<cstring>
#include<string.h>

using namespace std;

// 1.	***Написать функцию, которая определяет является ли строка палиндромом
// (т.е.строкой, которую можно читать и слева направо, и справа налево :
// «А роза упала на лапу Азора», «Аргентина манит негра», «Я ем змея»).
// Рекомендации:
// Из строки предварительно нужно удалить пробелы и привести ее к одному регистру.

void isPalindrome(char *str) {
	char*p;
	char*context;
	char line[100];
	_strlwr(str);

	p = strtok_s(str, " ", &context);
	strcpy_s(line, p);

	while (p != NULL)
	{
		p = strtok_s(context, " ", &context);
		if (p == NULL) break;
		strcat_s(line, p);
	}
	cout << line << endl;

	int n = strlen(line);
	//cout << n << endl;
	char *s1 = line;
	char s2[100];
	int j = 0;
	for (int i = n; i > n / 2; i--)
		s2[j++] = *(line + i - 1);
		
	int f = strncmp(s1, s2, n/2);

	if (f == 0) cout << "is a palindrome" << endl << endl;
	else cout << "not a palindrome" << endl << endl;
}


// 2.	**Убрать из строки все символы «о» и уменьшить ее до необходимого размера.

char* deleteSym(char*str) {
	char*p, *context;
	char line[100];
	
	p = strtok_s(str, "o", &context);
	strcpy_s(line, p);
	//line[strlen(line)] = '\0';

	while (p != NULL)
	{
		p = strtok_s(NULL, "o", &context);
		if (p == NULL) break;
		strcat_s(line, p);
	}
	//line[strlen(line)] = '\0';
	cout << line << endl;

	
	/*char s2[100];
	for (int i = 0; i<strlen(line); i++)
	{
		s2[i] = *(line+i);

	}*/
	
	return line; // именно при возврате указателя чтото ломается
}


int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn; cin.get();

		switch (tn)
		{
		case 1:
		{
			char str1[50] = "А роза упала на лапу Азора";
			char str2[50] = "Аргентина манит негра";
			char str3[50] = "Я ем змея";
			char str4[50] = "Аргентина НЕ манит негра";

			isPalindrome(str1);
			isPalindrome(str2);
			isPalindrome(str3);
			isPalindrome(str4);
		}
		break;
		case 2:
		{
			char str[100];
			cin.getline(str, 100);

			char*newStr = deleteSym(str);
			cout << newStr << endl << "new size: " << strlen(newStr) << endl;
			// when printing newStr
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}