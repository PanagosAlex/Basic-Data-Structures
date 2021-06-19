#ifndef ORDEREDARRAY_H
#define ORDEREDARRAY_H
#include <string>
#include <iostream>
#include "UnorderedArray.h"


class OrderedArray: public UnorderedArray{
public:
    OrderedArray(Data *,int);
    OrderedArray(int );

    bool findWord(string, int&);
    bool addWord(string);
    bool deleteWord(string);
    bool insertword(string w){
        UnorderedArray::addWord(w);
        int j;
        Data k;
        for (int i = 1; i < numOfData; i++)
        {
            k = data[i];
            j = i - 1;
            while (j >= 0 && data[j].getWord() > k.getWord())
            {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = k;
        }
    }
};


#endif //ORDEREDARRAY_H
