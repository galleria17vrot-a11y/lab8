#include <iostream>
#include <windows.h>

using namespace std;

#include "product_catalog.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
#include "Sort.h"

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
        int (*criteria)(product_catalog * exemplar1, product_catalog * exemplar2);
        void (*sort)(product_catalog * array[], int size, int (*criteria)(product_catalog * exemplar1, product_catalog * exemplar2));
        SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8);
        cout << "\nМетоды сортировки:\n";
        cout << "1)Сортировка выбором (Selection sort)\n";
        cout << "2)Сортировка слиянием (Merge sort)\n";
        cout << "\nВыберите метод сортировки: ";
        cin >> item;
        cout << "\n";
        switch (item)
        {
        case 1:
            sort = selection_sort;
            cout << "***** Сортировка выбором (Selection sort) *****\n\n";
            break;
        case 2:
            sort = merge_sort;
            cout << "***** Сортировка слиянием (Merge sort) *****\n\n";
            break;
        default:
            throw 3;
        }
        cout << "\nКритерии сортировки:\n";
        cout << "1)По убыванию количества товара на складе\n";
        cout << "2)По возрастанию категории товара, а в рамках одной категории по убыванию стоимости\n";
        cout << "\nВыберите критерий сортировки: ";
        cin >> item;
        cout << "\n";
        switch (item)
        {
        case 1:
            criteria = criteria1;
            cout << "***** Сортировка выбором (Selection sort) *****\n\n";
            break;
        case 2:
            criteria = criteria2;
            cout << "***** Сортировка слиянием (Merge sort) *****\n\n";
            break;
        default:
            throw 4;
        }
        sort(catalogs, size, criteria);
        for (int i = 0; i < size; i++)
        {
            output(catalogs[i]);
        }
        SetConsoleCP(CP_UTF8); SetConsoleOutputCP(CP_UTF8);
        cout << "\nКатегории товаров:\n";
        cout << "1)Промтовары\n";
        cout << "2)Инструменты\n";
        cout << "3)Электроника\n";
        cout << "4)Автотовары\n";
        cout << "5)Канцтовары\n";
        cout << "6)Продукты\n";
        cout << "7)Одежда\n";
        cout << "\nВыберите категорию товаров: ";
        cin >> item;
        cout << "\n";
        char category1[MAX_STRING_SIZE];
        switch (item)
        {
        case 1:
            strcpy_s(category1, MAX_STRING_SIZE, "Промтовары");
            cout << "***** Стоимость всех промтоваров *****\n\n";
            break;
        case 2:
            strcpy_s(category1, MAX_STRING_SIZE, "Инструменты");
            cout << "***** Стоимость всех инструментов *****\n\n";
            break;
        case 3:
            strcpy_s(category1, MAX_STRING_SIZE, "Электроника");
            cout << "***** Стоимость всей электроники *****\n\n";
            break;
        case 4:
            strcpy_s(category1, MAX_STRING_SIZE, "Автотовары");
            cout << "***** Стоимость всех автотоваров *****\n\n";
            break;
        case 5:
            strcpy_s(category1, MAX_STRING_SIZE, "Канцтовары");
            cout << "***** Стоимость всех канцтоваров *****\n\n";
            break;
        case 6:
            strcpy_s(category1, MAX_STRING_SIZE, "Продукты");
            cout << "***** Стоимость всех продуктов *****\n\n";
            break;
        case 7:
            strcpy_s(category1, MAX_STRING_SIZE, "Одежда");
            cout << "***** Стоимость всей одежды *****\n\n";
            break;
        default:
            throw 5;
        }
        for (int i = 0; i < size; i++)
        {
            delete catalogs[i];
        }
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