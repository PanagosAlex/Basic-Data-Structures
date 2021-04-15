#ifndef ORDEREDARRAY_H
#define ORDEREDARRAY_H
#include <string>
#include <iostream>
#include "UnorderedArray.h"


class OrderedArray: public UnorderedArray{
public:
    OrderedArray(string *,int);
    ~OrderedArray();

    bool findWord(string, int&);
    bool addWord(string);
    bool deleteWord(string);
};


#endif //ORDEREDARRAY_H
