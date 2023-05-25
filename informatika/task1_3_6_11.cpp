#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void One();
void Two();
void Three();


using namespace std;


int main() {

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

void One()
{
    cout << "_____1_3______" << endl;

    int n = 10, y = 0;

    vector<int> vec;

    for (int i = 0; i < n; i++)
        vec.push_back(i);

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) // вывод ДО
        cout << *iter << " ";
    cout << endl;

    for (int i = 0; i < vec.size(); i++) // замена нечетных элементов нулем
    {
        if (vec[i] % 2 != 0)
            replace(vec.begin(), vec.end(), vec[i], y);
    }

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) // вывод ПОСЛЕ
        cout << *iter << " ";
    cout << endl;

    main();

}

void Two()
{
    
    cout << "_____2_6______" << endl;

    int n = 10, x, min, max;

    cout << "x = "; cin >> x; cout << endl;

    vector<int> vec;

    for (int i = 0; i < n; i++)
        vec.push_back(i);

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) // вывод ДО
        cout << *iter << " ";
    cout << endl << endl;

    vector<int> temp(vec); // копия вектора

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] % x != 0)
            replace(temp.begin(), temp.end(), vec[i], 0); // замена элементов не кратных Х на ноль
    }
    cout << "Сумма = " << accumulate(temp.begin(), temp.end(), 0) << endl; // нахождение суммы элементов кртных Х

    min = *min_element(vec.begin(), vec.end()); // поиск минимального элемента
    cout << "Минимальный = " << min << endl << endl; // вывод

    max = *max_element(vec.begin(), vec.end()); // поиск максимального элемента
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] % 2 == 0)
            replace(vec.begin(), vec.end(), vec[i], max); // замена четных элементов на максимальный
    
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) // вывод после
        cout << *iter << " ";
    cout << endl << endl;

    main();
}

void Three()
{
    cout << "_____3_11______" << endl;

    int n = 10;

    vector<int> vec1;
    vector<int> vec2;

    for (int i = 0; i < n; i++)
    {
        vec1.push_back(i);                         // rand() % 10
        vec2.push_back(i);
    }

    cout << "vec-1     ";
    for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); iter++) // вывод 1 до
        cout << *iter << " ";
    cout << endl << endl;

    cout << "vec-2     ";
    for (vector<int>::iterator iter = vec2.begin(); iter != vec2.end(); iter++) // вывод 2 до
        cout << *iter << " ";
    cout << endl << endl << endl;

    cout << "удаление четных и НЕчетных элементов" << endl << endl << endl;

    for (int i = 0; i < vec1.size(); i++)
        if (vec1[i] % 2 == 0)
        {
            vector<int>::iterator it = remove(vec1.begin(), vec1.end(), vec1[i]); // удаление четных чисел в vec - 1
            vec1.erase(it, vec1.end());
        }

    for (int i = 0; i < vec2.size(); i++)
        if (vec2[i] % 2 != 0)
        {
            vector<int>::iterator it = remove(vec2.begin(), vec2.end(), vec2[i]); // удаление НЕчетных чисел в vec - 2
            vec2.erase(it, vec2.end());
        }

    cout << "vec-1     ";
    for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); iter++) // вывод 1 после
        cout << *iter << " ";
    cout << endl << endl;

    cout << "vec-2     ";
    for (vector<int>::iterator iter = vec2.begin(); iter != vec2.end(); iter++) // вывод 2 после
        cout << *iter << " ";
    cout << endl << endl << endl;

    cout << "сортируем" << endl << endl << endl;

    sort(vec1.begin(), vec1.end()); // сортировка vec - 1
    sort(vec2.begin(), vec2.end()); // сортировка vec - 2

    cout << "vec-1     ";
    for (vector<int>::iterator iter = vec1.begin(); iter != vec1.end(); iter++) // вывод 1 после
        cout << *iter << " ";
    cout << endl << endl;

    cout << "vec-2     ";
    for (vector<int>::iterator iter = vec2.begin(); iter != vec2.end(); iter++) // вывод 2 после
        cout << *iter << " ";
    cout << endl << endl << endl;

    vector<int> temp(vec1);
    temp.insert(temp.end(), vec2.begin(), vec2.end());

    cout << "vec-temp     ";
    for (vector<int>::iterator iter = temp.begin(); iter != temp.end(); iter++) // вывод объединенных векторов
        cout << *iter << " ";
    cout << endl << endl;

    main();
}