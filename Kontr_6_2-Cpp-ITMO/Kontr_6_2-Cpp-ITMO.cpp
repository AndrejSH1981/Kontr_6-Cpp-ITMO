﻿// Kontr_6_2-Cpp-ITMO.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
# include <windows.h>
#include <fstream>

using namespace std;


int main()
{
    double sum = 0;
    const int N = 10;

    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    int a1[N];
    for (int i = 0; i < N; i++) {
        a1[i] = a[i];
    }

    int min = 0; // для записи минимального значения
    int buf = 0; // для обмена значениями

    for (int i = 0; i < N; i++)
    {
        min = i; // номер текущей ячейки, как ячейки с минимальным значением
        // в цикле найдем реальный номер ячейки с минимальным значением
        for (int j = i + 1; j < N; j++)
            min = (a[j] < a[min]) ? j : min;
        // перестановка этого элемента, поменяв его местами с текущим
        if (i != min)
        {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }


    ofstream out("0000.txt", ios::out | ios::binary);

    if (!out) {
        wcout << L"Файл открыть невозможно\n";
        return 1;
    }
    out.write((char*)a1, sizeof(a1)), ((char*)a, sizeof(a));

    out.close();

    ifstream in("0000.txt", ios::in | ios::binary);
    if (!in) {
        wcout << L"Файл открыть невозможно";
        return 1;
    }
    cout << "\nof the source array: ";
    in.read((char*)&a1, sizeof(a1));
   
    
    int k1 = sizeof(a1) / sizeof(int);
    for (int i = 0; i < k1; i++)
    {
        
        cout << a1[i] << ' ';
    }
    cout << "\nof the sorted array: ";

    in.read((char*)&a, sizeof(a));

    int k = sizeof(a) / sizeof(int);
    for (int i = 0; i < k; i++)
    {

        cout << a[i] << ' ';
    }
    cout << "\n" << endl;
    in.close();






}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
