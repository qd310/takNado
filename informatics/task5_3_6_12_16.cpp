#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <stdio.h>
#include <time.h>
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
	cout << "-------task5_3-------\n";

	int n, x, sum = 0;

	cout << "n = "; // размер массива
	cin >> n;
	cout << "x = "; 
	cin >> x;

	int *a = new int[n]; // объявление массива

	cout << "Массив: { ";
	srand((unsigned)time(NULL)); // начальная точка генерации
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 15; //псевдослучайное число
		cout << a[i] << ", ";
	}
	cout << " }\n";

	for (int i = 0; i < n; i++) // нахождение суммы нечетных элементов, меньше заданного числа х
		if (a[i] < x && a[i] % 2 != 0)
			sum += a[i];
	
	if (sum == 0) // вывод, если таких чисел нет
		cout << "Таких элементов нет\n\n";
	else // вывод суммы
		cout << "Сумма = " << sum << "\n\n";

	main();
}

void two()
{
	cout << "-------task5_6-------\n";

	int n, x;
	bool fl = false;

	cout << "n = "; // размер массива
	cin >> n;
	cout << "x = ";
	cin >> x;

	int* a = new int[n]; // объявление массива

	cout << "Массив: { ";
	srand((unsigned)time(NULL)); // начальная точка генерации
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 15; //псевдослучайное число
		cout << a[i] << ", ";
	}
	cout << " }\n";
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] % x != 0)
		{
			cout << i << "\n";
			fl = true;
		}

		if (!fl && i == n - 1)
			cout << "таких элементов нет\n\n";
	}

	main();
}

void three()
{
	cout << "-------task5_12-------\n";

	int n;

	cout << "n = "; // размер массива
	cin >> n;

	int* a = new int[n]; // объявление массива

	cout << "Массив ДО: { ";
	srand((unsigned)time(NULL)); // начальная точка генерации
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 15; //псевдослучайное число
		cout << a[i] << ", ";
	}
	cout << " }\n";

	int max = a[0]; //максимум = нулевой элемент
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i]; //поиск максимума

	for (int i = 0; i < n; i++) // смена числа на противопложное
		if (a[i] == max)
			a[i] = a[i] - a[i] - a[i];

	cout << "Массив ПОСЛЕ: { ";
	for (int i = 0; i < n; i++) // вывод
		cout << a[i] << ", ";
	cout << " }\n\n";

	main();
}

void four()
{
	cout << "-------task5_16-------\n";

	int n;
	bool fl = false;

	cout << "n = "; // размер массива
	cin >> n;

	int* a = new int[n]; // объявление массива

	cout << "Массив ДО: { ";
	srand((unsigned)time(NULL)); // начальная точка генерации
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 15; // псевдослучайное число
		cout << a[i] << ", ";
	}
	cout << " }\n";

	int min = a[0]; // минимум = нулевой элемент
	for (int i = 1; i < n; i++)
		if (a[i] < min)
			min = a[i]; // поиск минимума

	int max = a[0]; // максимум = нулевой элемент
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i]; // поиск максимума

	for (int i = 0; i < n; i++)
	{
		if (a[i] == min)
			for (int j = 0; j < n; j++)
				if (a[j] == max)
				{
					swap(a[i], a[j]); // смена первого минимального значения на первое максимальное
					j = n;
					i = n;
				}
	}

	cout << "Массив ПОСЛЕ: { ";
	for (int i = 0; i < n; i++) // вывод
		cout << a[i] << ", ";
	cout << " }\n\n";

	main();
}