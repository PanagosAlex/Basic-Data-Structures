#ifndef DATA_H
#define DATA_H
#include <string>
#include <iostream>
using namespace std;

class Data {
private:
    string word;
    int numOfTimes;
public:
    Data();
    Data(string w);

    void setWord(string w);
    void setNumOfTimes(int n);
    void increaseNum();
    string getWord();
    int getNumOfTimes();


    Data operator =(Data d);
    Data operator ++();
    friend Data & operator <<(ostream &o,Data &d){
        o<<"Word:"<<d.getWord()<<" Times:"<<d.getNumOfTimes()<<endl;
        return d;
    }
};



#endif //DATA_H
