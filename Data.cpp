#include "Data.h"
#include <string>
using namespace std;
Data ::Data() {
    word=" ";
    numOfTimes=0;
}

Data ::Data(string w) {
    word=w;
    numOfTimes=1;
}

void Data::setWord(string w) {
    word=w;
}

void Data::setNumOfTimes(int n) {
    numOfTimes=n;
}

void Data:: increaseNum(){
  numOfTimes++;
}

void Data:: decreaseNum(){
  numOfTimes--;
}

string Data::getWord() {
    return word;
}

int Data::getNumOfTimes() {
    return numOfTimes;
}

/*Data Data::operator++() {
    numOfTimes++;
    return *this;
}*/

