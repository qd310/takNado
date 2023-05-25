//во входном файле задан набор слов и целых чисел, разделенных пробелами.
//найти все слова, встречающиеся столько же раз, сколько первое число.

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "RUS");

	ifstream in("in.txt");
	map<string, int> w, n;
	string n_f, num = "0123456789", buf;


	while (in>>buf) {
		if (buf.find_first_not_of(num) == string::npos) {
			if (n.empty())
				n_f = buf;
			n[buf]++;
		}
		else w[buf]++;
	}

	int k = stoi(n_f);

	cout << "Первое число: " << n_f << endl;
	cout << "Слова, встречающиеся столько же раз, сколько первое число: " << endl;

	for (auto it = w.begin(); it != w.end(); it++) //вывод слов
		if (it->second == k)
			cout << it->first;

	return 0;
}
