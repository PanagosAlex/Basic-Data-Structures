#include "Data.h"
#include <string>

using namespace std;
/*
* κατασκευαστής που δεν δέχεται κανένα όρισμα
*/
Data ::Data() {
    word=" ";
    numOfTimes=0;
}
/*
* κατασκευαστής που δέχεται ως όρισμα μια λέξη w
*/
Data ::Data(string w) {
    word=w;
    numOfTimes=1;
}
/*
* setter για την λέξη w
*/
void Data::setWord(string w) {
    word=w;
}
/*
* setter για τον αριθμό εμφάνισης της λέξης
*/
void Data::setNumOfTimes(int n) {
    numOfTimes=n;
}
/*
* αυξάνει τον αριθμό εμφάνισης της λέξης κατά ένα
*/
void Data:: increaseNum(){
  numOfTimes++;
}
/*
* getter για την λέξη w
*/
string Data::getWord() {
    return word;
}
/*
* getter για τον αριθμό εμφάνισης της λέξης
*/
int Data::getNumOfTimes() {
    return numOfTimes;
}
/*
* υπερφόρτωση του τελεστή =
*/
Data & Data:: operator =(Data d){
    word=d.getWord();
    numOfTimes=d.getNumOfTimes();
    return *this;
}
/*
* υπερφόρτωση του τελεστή ++
*/
Data Data::operator++() {
    numOfTimes++;
    return *this;
}