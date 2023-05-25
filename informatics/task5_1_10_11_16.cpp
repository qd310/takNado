#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include<limits.h>
using namespace std;
void one();
void two();
void three();
void four();

int main()
{
	setlocale(LC_ALL, "RUS");
	int exercise;
	cout << "Введите цифру для выбора задания (1 - 4)";
	cin >> exercise;
	if (exercise == 1) one();
	else if (exercise == 2) two();
	else if (exercise == 3) three();
	else if (exercise == 4) four();
	else cout << "НЕККОРЕКТНЫЙ ОТВЕТ!!\nУкажите цифру от 1 до 4 \n";
	main();

	return 0;
}

void one()
{
	cout << "-------task5_1-------\n";

	int n;

	cout << "n = "; // размер массива
	cin >> n;

	int **mas = new int*[n]; // объявление массива

	for (int i = 0; i < n; i++) // создание двумерности в массиве
		mas[i] = new int[n];
	
	for (int i = 0; i < n; i++) // заполнение массива
	{
		for (int j = 0; j < n; j++)
			mas[i][j] = 1 + i;
	}

	for (int i = 0; i < n; i++) // вывод массива ДО
	{
		for (int j = 0; j < n; j++)
			cout << mas[i][j] << "\t";

		cout << endl;
	} 

	cout << endl << endl << endl;

	for (int k = 0; k < n / 2; k++) // меняем первую строку с последней и т.д.
	{ 
		for (int j = 0; j < n; j++)
			swap(mas[k][j], mas[n - 1 - k][j]);
	}

	for (int k = 0; k < n; k++) // вывод массива ПОСЛЕ
	{
		for (int j = 0; j < n; j++)
			cout << mas[k][j] << "\t";
		cout << endl;
	}

	main();
}

void two()
{
	cout << "-------task5_10-------\n";

	int n, s = 0;

	cout << "n = "; // размер массива
	cin >> n;

	int** mas = new int* [n]; // объявление массива

	for (int i = 0; i < n; i++) // создание двумерности в массиве
		mas[i] = new int[n];

	for (int i = 0; i < n; i++) // заполнение массива
	{
		for (int j = 0; j < n; j++)
			mas[i][j] = 1 + i;
	}

	mas[1][1] = 5;
	mas[2][1] = 4;
	mas[3][2] = 1;

	for (int i = 0; i < n; i++) // вывод массива ДО
	{
		for (int j = 0; j < n; j++)
			cout << mas[i][j] << "\t";

		cout << endl;
	}
	cout << endl << endl << endl;

	for (int k = 0; k < n; k++) 
	{
		for (int j = 0; j < n; j++) // поиск строк, содержащие только нечетные элементы
		{
			if (mas[k][j] % 2 != 0) s++;
		}

		if (s == n)
		{
			for (int j = 0; j < n; j++) // замена строк
				mas[k][j] = 0;
		}

		s = 0;
	}

	for (int i = 0; i < n; i++) // вывод массива ПОСЛЕ
	{
		for (int j = 0; j < n; j++)
			cout << mas[i][j] << "\t";

		cout << endl;
	}

	cout << endl << endl << endl;

	main();
}

void three()
{
	cout << "-------task5_11-------\n";

	int n, c = 0, r = 0;

	cout << "n = "; // размер массива
	cin >> n;

	int** mas = new int* [n]; // объявление массива

	for (int i = 0; i < n; i++) // создание двумерности в массиве
		mas[i] = new int[n];
	/*
	for (int i = 0; i < n; i++) // заполнение массива
	{
		for (int j = 0; j < n; j++)
			mas[i][j] = 1 + i;
	}*/

	int mass[5][5] = { // массив для примера  
		{4, 5, 8, 2, 1},
		{2, 4, 1, 3, 2},
		{4, 3, 7, 2, 0},
		{9, 5, 2, 7, 4},
		{4, 6, 8, 1, 3}
	};
	for (int i = 0; i < n; i++) // вывод массива ДО
	{
		for (int j = 0; j < n; j++)
			cout << mass[i][j] << "\t";

		cout << endl;
	}
	cout << endl << endl << endl;

	for (int j = 0; j < n; j++) // поиск среднего арифмитического
	{
		for (int i = 0; i < n; i++)
		{
			if (mass[i][j] % 2 != 0)
			{
				c++;
				r += mass[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++) // вывод массива ПОСЛЕ
	{
		for (int j = 0; j < n; j++)
			cout << mas[i][j] << "\t";

		cout << endl;
	}

	cout << endl << endl << endl;

	main();
}

void four()
{
	cout << "-------task5_16-------\n";

	int n, c = -1, k = 0;

	cout << "n = "; // размер массива
	cin >> n;

	int** mas = new int* [n]; // объявление массива

	for (int i = 0; i < n; i++) // создание двумерности в массиве
		mas[i] = new int[n];

	for (int i = n - 1; i >= 0; i--) // заполнение массива
	{
		if (k % 2 == 0)
		{
			for (int j = n - 1; j >= 0; j--)
				mas[i][j] = c += 1;
			k++;
		}
		else
		{
			for (int j = 0; j < n; j++)
				mas[i][j] = c += 1;
			k++;
		}
	}

	for (int i = 0; i < n; i++) // вывод массива
	{
		for (int j = 0; j < n; j++)
			cout << mas[i][j] << "\t";

		cout << endl;
	}

	main();
}