#ifndef BOOK_SUBSCRIPTION_H
#define BOOK_SUBSCRIPTION_H

#include "constants.h"

struct product_catalog {
	double stoimost;
	int colvo;
	char category[MAX_STRING_SIZE];
	char name[MAX_STRING_SIZE];
};

#endif