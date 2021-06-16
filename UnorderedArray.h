#ifndef UnorderedArray_h
#define UnorderedArray_h

#include "Data.h"
using namespace std;
/*
 * This class represents an Unordered Array.
 */
class UnorderedArray{
  protected:
    Data* data;
    int length;
  public:

    UnorderedArray(Data* a,int len);
    ~UnorderedArray();

    bool setWord(string, int);
    Data getWord(int);
    int getLength();

    bool findWord(string, int&);
    bool addWord(string);
    bool deleteWord(string);
    //int numOfTimes(int n);

};

#endif