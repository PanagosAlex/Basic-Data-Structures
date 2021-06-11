#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Data.h"

class HashTable {
private:
    Data* data;
    int length;
public:
    HashTable(int size);
    HashTable(string word,int size);

    void insertWord(string word);
    bool searchWord(string word, int & pos);
    bool searchWord(string word);
    void printData();
    unsigned long Hashing(string word);
};


#endif //HASHTABLE_H
