#ifndef DATA_H
#define DATA_H
#include <string>
#include <iostream>
using namespace std;

/*
 * Αυτή η κλάση αναπαριστά τα δεδομένα. Τα δεδομένα αποτελόυν ζεύγη μίας συμβολοσειράς και ενός ακεραίου.
 */

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


    Data &operator =(Data d);
    Data operator ++();
    friend ostream & operator <<(ostream &o,Data &d){
        o<<"Word:"<<d.getWord()<<" Times:"<<d.getNumOfTimes()<<endl;
        return o;
    }
};



#endif //DATA_H
