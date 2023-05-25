#include <iostream>
#include <algorithm> 
#include <fstream> 
#include <string> 
#include <set> 
#include <map> 
#include <vector> 
#include <iterator> 

void One();
void Two();
void Three();

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int main()
{
    setlocale(LC_ALL, "ru");

    int ex;
    cout << "Введите номер задания (1 - 3): "; cin >> ex;

    if (ex == 1) One();
    else if (ex == 2) Two();
    else if (ex == 3) Three();
    else
    {
        cout << "Неккоректный ввод!";
        main();
    }

    return 0;
}

set <int> set_n(int n)
{
    set <int> S;

    while (n != 0)
    {
        S.insert(n % 10);
        n /= 10;
    }

    return S;
}

void One()
{
    cout << "_____1_2______" << endl;

    set <int> s1, s0, s, res;
    int n, a;

    cout << "n = "; cin >> n;

    for (int i = 0; i < n; i++)
    {
        s = set_n(i);
        s1.insert(s.begin(), s.end());
    }

    cout << "Введите числа: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]=";
        cin >> a;
        s = set_n(a);
        if (a > 99 && a <= 999)
            s0.insert(s.begin(), s.end());
    }

    set_difference(s1.begin(), s1.end(), s0.begin(), s0.end(), inserter(res, res.begin()));

    cout << "Цифры, которые встречаются в двузначных числах, но не встречаются в трехзначных: " << endl;

    for (set<int>::iterator it = res.begin(); it != res.end(); it++)
        cout << *it << " " << endl << endl << endl;

    main();

}



void Two()
{   
    cout << "_____2_7______" << endl;

    string str = "Вопросительное предложени? Восклицательное предложение! Повествовательное предложение.";

    set<string> vopr, vosk, pov;
    string razd = "!?.";

    auto k = str.find_first_of(razd);

    for (int i = 0; i < str.length(); i++)
    {
        auto tmp = str[k];
    }

    /*
    int k = 0;
    set <string> set_inter; // set для хранения слов из вопросительных предложений
    set <string> set_exc; // set для хранения слов из восклицательных предложений
    set <string> set_dot; //set для хранения слов из повествовательных предложений
    set <string> set_cross; // set для хранения пересечения
    set <string> set_dif; // set для хранения разницы 
    string data;
    string sub = "";
    getline(in, data);
    for (int i = 0; i < data.length(); i++)
    {
        k++;
        sub += data[i];
        if (data[i] == '?') // заполняем set с вопросительными предложениями
        {


            set_inter.insert(sub);

            sub = "";
            k = 0;
        }
        if (data[i] == '!') // заполняем set с восклицательными предложениями
        {
            set_exc.insert(sub);
            sub = "";
            k = 0;
        }
        if (data[i] == '.') // заполняем set с повествовательными предложениями
        {
            set_dot.insert(sub);
            sub = "";
            k = 0;
        }
    }
    set_intersection(set_dot.begin(), set_dot.end(), set_exc.begin(), set_exc.end(), inserter(set_cross, set_cross.begin())); // пересечение восклицательных и повествовательных предложений
    set_intersection(set_exc.begin(), set_exc.end(), set_dot.begin(), set_dot.end(), inserter(set_cross, set_cross.begin()));
    set_difference(set_dot.begin(), set_dot.end(), set_cross.begin(), set_cross.end(), inserter(set_dif, set_dif.begin())); // разница вопросительных предложений и (восклицательные * повествовательных) 
                                                                                                                            //(то, что требуется)
    out << "set_inter(?): ";
    for (set<string>::iterator it = set_inter.begin(); it != set_inter.end(); it++)
    {
        out << *it << " "; // вывод вопросительных предложений
    }
    out << endl;
    out << "set_exc(!): ";
    for (set<string>::iterator it = set_exc.begin(); it != set_exc.end(); it++)
    {
        out << *it << " "; //вывод восклицательных предложений
    }
    out << endl;
    out << "set_dot(.): ";
    for (set<string>::iterator it = set_dot.begin(); it != set_dot.end(); it++)
    {
        out << *it << " "; //вывод повествовательных предложений
    }
    out << endl;
    out << "set_cross(!*.): "; //вывод пересечение восклицательных и повествовательных предложений
    for (set<string>::iterator it = set_cross.begin(); it != set_cross.end(); it++)
    {
        out << *it << " "; //вывод пересечение восклицательных и повествовательных предложений
    }
    out << endl;
    out << "Результат: ";
    for (set<string>::iterator it = set_dif.begin(); it != set_dif.end(); it++)
    {
        out << *it << " "; // вывод конечного результата
    }
    out << endl;
    out << endl;
    out << "Кол-во = " << set_dif.size();
    */
    main();
}

void Three()
{
    cout << "_____3_11______" << endl;


    string alf = " ";
    string str;
    multiset <string> slova; // count(const std::string &key)
    // multiset <string> count(const string & key);

    int x, n, c, tic = 0;
    ifstream fin("file.txt");

    if (!fin) {
        cout << "Файл не найден" << endl;
        system("pause");
        exit(0);
    }
    else {
        getline(fin, str);
        int k = str.find_first_of(alf);
        string word = str.substr(0, k);
        cout << word << endl;
        str.push_back(' ');
        cout << str << endl;

        for (; str.length() > 0;) {
            if (str.find_first_of(alf)) {
                k = str.find_first_of(alf);
                string temp = str.substr(0, k);
                slova.insert(temp);
                str.erase(0, k + 1);
            }

        }
        for (multiset<string>::iterator it1 = slova.begin(); it1 != slova.end(); it1++)
        {
            if (word == *it1)
            {
                tic++;
            }
        }

    }
    cout << tic;

    main();
}