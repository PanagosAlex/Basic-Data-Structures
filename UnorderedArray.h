#ifndef UnorderedArray_h
#define UnorderedArray_h
#include <iostream>

using namespace std;

#include "Data.h"
using namespace std;
/*
 * This class represents an Unordered Array.
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

    bool findWord(string, int&);
    bool addWord(string);
    bool deleteWord(string);
    void printData(){
        for(int i=0;i<numOfData;i++) {
            cout << data[i];
        }
    }

};

#endif