#ifndef SORT_H
#define SORT_H

#include "product_catalog.h"

void selection_sort(product_catalog* array[], int size, int (*criteria)(product_catalog* exemplar1, product_catalog* exemplar2));
void merge_sort(product_catalog* array[], int size, int (*criteria)(product_catalog* exemplar1, product_catalog* exemplar2));

int criteria1(product_catalog* exemplar1, product_catalog* exemplar2);
int criteria2(product_catalog* exemplar1, product_catalog* exemplar2);

#endif