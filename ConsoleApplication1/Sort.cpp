#include "sort.h"
#include <iostream>

int criteria1(product_catalog* exemplar1, product_catalog* exemplar2) {
    if (exemplar1->colvo > exemplar2->colvo)
        return 1;
    else if (exemplar1->colvo < exemplar2->colvo)
        return -1;
    else
        return 0;
}

int criteria2(product_catalog* exemplar1, product_catalog* exemplar2) {
    int ctgr = strcmp(exemplar1->category, exemplar2->category);
    if (ctgr > 0)
        return -1;
    else if (ctgr < 0)
        return 1;
    else {
        if (exemplar1->stoimost > exemplar2->stoimost)
            return 1;
        else if (exemplar1->stoimost < exemplar2->stoimost)
            return -1;
        else
            return 0;
    }
}

void selection_sort(product_catalog* array[], int size, int (*criteria)(product_catalog* exemplar1, product_catalog* exemplar2)) {
    for (int i = 0; i < size - 1; i++) {
        int maxj = i;
        for (int j = i + 1; j < size; j++) {
            if (criteria(array[maxj], array[j]) < 0) {
                maxj = j;
            }
        }
        product_catalog* temp = array[maxj];
        array[maxj] = array[i];
        array[i] = temp;
    }
}

void merge_sort(product_catalog* array[], int size, int (*criteria)(product_catalog* exemplar1, product_catalog* examplar2)) {
    if (size <= 1) return;
    int mid = size / 2, levi = mid, pravi = size - mid;
    product_catalog** levi_arr = new product_catalog * [levi];
    product_catalog** pravi_arr = new product_catalog * [pravi];

    for (int i = 0; i < levi; i++)
        levi_arr[i] = array[i];
    for (int i = 0; i < pravi; i++)
        pravi_arr[i] = array[mid + i];

    merge_sort(levi_arr, levi, criteria);
    merge_sort(pravi_arr, pravi, criteria);

    int i = 0, j = 0, k = 0;

    while (i < levi && j < pravi) {
        if (criteria(levi_arr[i], pravi_arr[j]) > 0) {
            array[k] = levi_arr[i];
            i++;
        }
        else {
            array[k] = pravi_arr[j];
            j++;
        }
        k++;
    }

    while (i < levi) {
        array[k] = levi_arr[i];
        i++;
        k++;
    }

    while (j < pravi) {
        array[k] = pravi_arr[j];
        j++;
        k++;
    }
    delete[] levi_arr;
    delete[] pravi_arr;
}