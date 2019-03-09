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
	cout << str << endl;
	char*p;
	char*context;
	_strlwr(str);

	p = strtok_s(str, " ", &context);
	strcpy(str, p);

	while (p != NULL)
	{
		p = strtok_s(context, " ", &context);
		if (p == NULL) break;
		strcat(str, p);
	}
	cout << str << endl;

	int n = strlen(str);
	//cout << n << endl;
	
	char s[100];
	int j = 0;
	for (int i = n; i > n / 2; i--)
		s[j++] = *(str + i - 1);
		
	int f = strncmp(str, s, n/2);

	if (f == 0) cout << "is a palindrome" << endl << endl;
	else cout << "not a palindrome" << endl << endl;
}


// 2.	**Убрать из строки все символы «о» и уменьшить ее до необходимого размера.

char* deleteSym(char*str) {
	char*p, *context;
	
	p = strtok_s(str, "o", &context);
	strcpy(str, p); //strcpy_s не принимает почему?

	while (p != NULL)
	{
		p = strtok_s(NULL, "o", &context);
		if (p == NULL) break;
		strcat(str, p); //strcat_s не принимает почему?
	}
	//cout << str << endl;

	// указатели надо удалять?
	//delete p;
	//delete context;
	
	return str;
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
			char str[100]="abcoodefoooo";
			//cin.getline(str, 100);
			cout << str << endl << "given size: " << strlen(str) << endl << endl;
			
			char*newStr = deleteSym(str);
			
			cout << newStr << endl << "new size: " << strlen(newStr) << endl;
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}