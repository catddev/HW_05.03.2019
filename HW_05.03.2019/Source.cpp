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

void isPalindrom(char *str) {
	char*p;
	strlwr(str);
	while (*str != '\0')
	{
		if (*str != ' ') *p= *str;
		p++;
		str++;
	}
	*(p + 1) = '\0';
	cout << p << endl;



}







// 2.	**Убрать из строки все символы «о» и уменьшить ее до необходимого размера.


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
		
		}
		break;
		case 2:
		{
		
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}