#include "file_reader.h"
#include "constants.h"

#include <fstream>

void read(const char* file_name, product_catalog* array[], int& size)
{
    std::fstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        while (!file.eof())
        {
            product_catalog* item = new product_catalog;
            file >> item->stoimost;
            file >> item->colvo;
            file >> item->category;
            file.ignore(1);
            file.getline(item->name, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw 1;
    }
}