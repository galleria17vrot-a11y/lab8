#include <iostream>
#include <windows.h>

using namespace std;

#include "product_catalog.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"

void output(product_catalog* catalog) {
    /********** вывод стоимости **********/
    SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8); cout << "Стоимость........: ";
    SetConsoleCP(1251); SetConsoleOutputCP(1251); cout << catalog->stoimost << '\n';
    /********** вывод количества **********/
    SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8); cout << "Количество.......: ";
    SetConsoleCP(1251); SetConsoleOutputCP(1251); cout << catalog->colvo << '\n';
    /********** вывод категории **********/
    SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8); cout << "Категория........: ";
    SetConsoleCP(1251); SetConsoleOutputCP(1251); cout << catalog->category << '\n';
    /********** вывод названия **********/
    SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8); cout << "Название.........: ";
    SetConsoleCP(1251); SetConsoleOutputCP(1251); cout << catalog->name << '\n';
    cout << '\n';
}

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8);
    cout << "Лабораторная работа #8\n";
    cout << "Вариант #10. Каталог товаров\n";
    cout << "Автор: Подрез Виктория\n";
    cout << "Группа: 25Пинж-1д.\n\n";
    product_catalog* catalogs[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", catalogs, size);
        cout << "***** Каталог товаров *****\n\n";
        for (int i = 0; i < size; i++)
        {
            output(catalogs[i]);
        }
        bool (*check_function)(product_catalog*);
        SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8);
        cout << "\nКритерии отбора:\n";
        cout << "1)Вывести все товары в категории «Промтовары».\n";
        cout << "2)Вывести все товары стоимостью выше 100 рублей.\n";
        cout << "\nВыберите критерий отбора: ";
        int item;
        cin >> item;
        cout << "\n";
        switch (item)
        {
        case 1:
            check_function = check_by_category;
            cout << "***** Каталог товаров в категории «Промтовары» *****\n\n";
            break;
        case 2:
            check_function = check_by_price;
            cout << "***** Каталог товаров стоимостью выше 100 рублей *****\n\n";
            break;
        default:
            throw 2;
        }
        int new_size;
        product_catalog** filtered = filter(catalogs, size, check_function, new_size);
        for (int i = 0; i < new_size; i++)
        {
            output(filtered[i]);
        }
        delete[] filtered;
        
    }
    catch (const int error)
    {
        SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8);
        switch (error) {
        case 1:
            cout << "Ошибка открытия файла\n";
            break;
        case 2:
            cout << "Нет такого критерия\n";
            break;
        case 3:
            cout << "Нет такого метода\n";
            break;
        case 4:
            cout << "Нет такого критерия\n";
            break;
        case 5:
            cout << "Нет такой категории\n";
        }
    }
    return 0;
}