// Kontr_6_1-Cpp-ITMO.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <fstream>
#include <iostream>
# include <windows.h>
#include <string>

using namespace std;

int main() {

    setlocale(LC_CTYPE, "rus");


    wcout << L"Введите название файла (лучше цифры): ";
    string filename;
    cin >> filename;
    string filename0 = filename + ".txt";

      ofstream file(filename0);// окрываем файл для записи
    if (!file) {
        cout << L"Не удалось открыть файл \"" << filename0 << "\"" << endl;
        return 1;
    }

    wcout << L"Введите текст стихотворения (цифры или англ.):" << endl;

    for (string line; getline(cin, line);) {
        if (!line.empty()) {
            file << line << '\n';
        }
        if (line == "&") {
            break;
        }
    }

    wcout << L"Ввод завершен" << endl;
    file.close();     // закрываем файл


    wcout << L"Введите название файла для чтения: ";
    string nameFale;
    string line;
    cin >> nameFale;
    cout << "* " << nameFale << endl;
    string nameFale0 = nameFale + ".txt";
    ifstream fileOut(nameFale0); // окрываем файл для чтения
    if (fileOut.is_open())
    {
        wcout << L"\n=проверка=" << endl;
        while (getline(fileOut, line))
        {

            cout << line << endl;
        }
    }
    else {
            cout << L"Не удалось открыть файл \"" << nameFale0 << "\"" << endl;

    }
    fileOut.close();     // закрываем файл


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
