#ifndef BOOK_SUBSCRIPTION_H
#define BOOK_SUBSCRIPTION_H

#include "constants.h"

struct catalog
{
    double costs;
    int number;
    char categor[MAX_STRING_SIZE];
    char name[MAX_STRING_SIZE];
};

#endif