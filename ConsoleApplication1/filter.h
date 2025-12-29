#ifndef FILTER_H
#define FILTER_H

#include "product_catalog.h"

product_catalog** filter(product_catalog* array[], int size, bool (*check)(product_catalog* element), int& result_size);

bool check_by_category(product_catalog* element);
bool check_by_price(product_catalog* element);

#endif