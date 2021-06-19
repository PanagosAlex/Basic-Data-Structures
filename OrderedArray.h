#ifndef ORDEREDARRAY_H
#define ORDEREDARRAY_H
#include <string>
#include <iostream>
#include "UnorderedArray.h"

/*
 * Αυτή η κλάση αναπαριστά έναν Ταξινομημένο Πίνακα
 */
class OrderedArray: public UnorderedArray{
public:
    OrderedArray(Data *,int);
    OrderedArray(int );

    bool searchWord(string, int&);
    bool insertWord(string);
    bool deleteWord(string);

};


#endif //ORDEREDARRAY_H
