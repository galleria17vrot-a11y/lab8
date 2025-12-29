#include "filter.h"
#include <iostream>

product_catalog** filter(product_catalog* array[], int size, bool (*check)(product_catalog* element), int& result_size)
{
	product_catalog** result = new product_catalog * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_by_category(product_catalog* element) {
	return strcmp(element->category, "Промтовары") == 0;
}
bool check_by_price(product_catalog* element) {
	return element->stoimost > 100;
}