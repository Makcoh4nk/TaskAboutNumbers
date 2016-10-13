#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <iostream>
#include <locale.h>
using namespace std;

void SearchANumber(int);

void main()
{
	srand((unsigned)time(NULL));

	int N1 = (rand() % 10)*(rand() % 10);
	int N2 = (rand() % 100)*(rand() % 100);
	int N3 = (rand() % 1000)*(rand() % 1000);

	setlocale(LC_ALL, "Russian");

	cout << endl << "Первое число последовательности равно -1:" << endl;
	SearchANumber(-1);

	cout << endl << "Первое число последовательности равно 0:" << endl;
	SearchANumber(0);

	cout << "Первое число последовательности равно 1:" << endl;
	SearchANumber(1);

	cout << "Первое число последовательности задаётся рандомом:" << endl;
	SearchANumber(N1);
	SearchANumber(N2);
	SearchANumber(N3);

	_getch();
}

void SearchANumber(int N)
{
	int Clone1 = N, Clone2 = 0;
	int ArN[10];
	int temp = 0;
	int i = 0, j = 0;

	if (N == 0)
		cout << "FAIL" << endl << endl;
	else
		if ((N < 0) || (N > 1000000))
			cout << "Некорректый ввод данных" << endl;
	else
	{
		while (temp != 1)
		{
			Clone1 = N*(j + 1);
			Clone2 = Clone1;
			cout << Clone1 << "  ";
			while (Clone1 != 0)
			{
				temp = Clone1 % 10;
				for (i = 0; i < 10; i++)
					if ((temp == i) && (ArN[i] != i))
					{
						ArN[i] = temp;
						break;
					}
				Clone1 = Clone1 / 10;
			}
			j++;

			for (i = 0; i < 10; i++)
				if (ArN[i] != i)
				{
					temp = 0;
					break;
				}
				else temp = 1;
		}
		cout << endl << "Искомое число: " << Clone2 << endl << endl;
	}
}