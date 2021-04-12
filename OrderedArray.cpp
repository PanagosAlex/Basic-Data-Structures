/*#include "OrderedArray.h"
#include <string>

OrderedArray:: OrderedArray(string *a,int len){
    length=len;
    data= new string[length];
    data=a;
    sortArray(data);
}
OrderedArray:: ~OrderedArray(){
    delete[] data;
}

bool setWord(string s, int pos){
    data[pos]=s;
}
string getWord(int pos){
    return data[pos];
 }
int getLength(){
    return length;
 }

bool findWord(string, int&);
bool addWord(string);
bool deleteWord(string);
int numOfTimes(int );
void sortArray(string *a);
    */