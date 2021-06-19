#ifndef UnorderedArray_h
#define UnorderedArray_h
#include <iostream>

using namespace std;

#include "Data.h"
using namespace std;
/*
 * Αυτή η κλάση αναπαριστά έναν Αταξινόμητο Πίνακα
 */
class UnorderedArray{
protected:
    Data* data;
    int length;
    int numOfData;

  public:

    UnorderedArray(Data * a,int len);
    UnorderedArray(int len);
    ~UnorderedArray();

    bool setWord(string, int);
    Data getWord(int);
    int getLength();

    bool searchWord(string, int&);
    bool insertWord(string);
    bool deleteWord(string);
    void printData(){
        for(int i=0;i<numOfData;i++) {
            cout << data[i];
        }
    }

};

#endif