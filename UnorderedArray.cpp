#include <string>
#include "UnorderedArray.h"

using namespace std;
/*
* κατασκευαστής που δέχεται ως όρισμα έναν πίνακα απο Data και το μέγεθος του πίνακα
*/
UnorderedArray::UnorderedArray(Data * a,int len)
{
  length = len;
  data = new Data[length];
    for (int i = 0; i < length; i++) {
        data[i]=a[i];
    }
    numOfData=length;
}
/*
* κατασκευαστής που δέχεται ως όρισμα μέγεθος του πίνακα
*/
UnorderedArray:: UnorderedArray(int len){
    length=len;
    data = new Data[len];
    numOfData=0;
}
/*
* καταστροφέας
*/
UnorderedArray:: ~UnorderedArray(){
    delete[] data;
}
/*
* setter που βάζει στην θεση pos την λέξη w
*/
bool UnorderedArray::setWord(string w,int pos)
{
    if(pos>=0 && pos<length)
    {
      Data temp(w);
      data[pos] = temp;
      return true;
    }
    return false;
}
/*
* getter που επιστρέφει την λέξη στην θέση pos
*/
Data UnorderedArray::getWord(int pos)
{
  return data[pos];
}
/*
* getter που βάζει το μέγεθος του πίνακα
*/
int UnorderedArray::getLength() {
    return length;
}
/*
* δέχεται ως όρισμα ένα string και με αναφορά ένα int. επιστρέφει true αν βρει το string μέσα στον πίνακα και στο int γράφει την θέση του και false σε κάθε άλλη περίπτωση
*/
bool UnorderedArray::searchWord(string s,int& pos)
{
  for(int i=0;i<length;i++)
  {
    if(s == data[i].getWord())
    {
      pos=i;
      return true;
    }
  }
  return false;
}
/*
* δέχεται ως όρισμα ένα string. επιστρέφει true αν μπορέσει να προσθέσει την λέξη στον πίνακα και false σε κάθε άλλη περίπτωση
*/
bool UnorderedArray::insertWord(string s) {

        int pos=-2;
        if(searchWord(s,pos)){
            ++data[pos];
            return true;
        }
        else{
            if(numOfData==length){
                Data *temp= new Data[length+200];
                if(temp==nullptr)
                    return false;
                numOfData++;
                for(int i=0;i<length;i++){
                    temp[i]=data[i];
                }
                delete[] data;
                temp[length].setWord(s);
                temp[length].setNumOfTimes(1);
                data = temp;
                length+=1000;
                return true;
            } else{
                data[numOfData].setWord(s);
                data[numOfData].setNumOfTimes(1);
                numOfData++;
                return true;
            }
        }
}
/*
* δέχεται ως όρισμα ένα string. επιστρέφει true αν αφεραίσει το string μέσα από τον πίνακα και false σε κάθε άλλη περίπτωση
*/
bool UnorderedArray::deleteWord(string s) {
    int t;
   if (searchWord(s, t)) {
        data[t]=data[numOfData-1];
        data[numOfData].setWord(" ");
        data[numOfData].setNumOfTimes(0);
        numOfData--;
        return true;
    }
    return false;
}