#include "HashTable.h"
#include <iostream>
using namespace std;

HashTable::HashTable(int size) {
    length=size*2;
    data= new Data[size];
}

HashTable::HashTable(string word,int size) {
    length=size*2;
    data= new Data[size];
    Data w(word);
    insertWord(w.getWord());
}

void HashTable::insertWord(string word) {

    int position=-3;
    if(searchWord(word,position)==true){
        ++data[position];
    }
    else{
        data[position].setWord(word);
        data[position].setNumOfTimes(1);
    }
}
bool HashTable::searchWord(string word, int & pos){
    int position= Hashing(word);
    while( data[position].getWord()!=" "){
        if(data[position].getWord()==word){
            pos= position;
            return true;
        }
        else{
            position++;
        }
    }
    pos=position;
    return false;
}

bool HashTable::searchWord(string word){
    int dummy;
    return searchWord(word,dummy);
}

void HashTable::printData(){
    for(int i=0;i<length;i++){
        if(data[i].getWord()!=" "){
            cout<<data[i];
            cout<<endl;
        }
    }
}

unsigned long HashTable::Hashing(string word){
    unsigned long hash = 5381;
    for(char ch:word){
        hash = ((hash << 5) + hash) + abs((int)ch);
    }
    return hash %length;
}
