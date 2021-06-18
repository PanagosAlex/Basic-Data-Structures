#include <iostream>
#include <string>
#include <cstring>
#include "UnorderedArray.h"


using namespace std;

UnorderedArray::UnorderedArray(Data * a,int len)
{
  length = len;
  data = new Data[length];
    for (int i = 0; i < length; i++) {
        data[i]=a[i];
    }
    numOfData=length;
}
UnorderedArray:: UnorderedArray(int len){
    length=len;
    data = new Data[len];
    numOfData=0;
}

UnorderedArray:: ~UnorderedArray(){
    delete[] data;
}

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

Data UnorderedArray::getWord(int pos)
{
  return data[pos];
}

int UnorderedArray::getLength() {
    return length;
}

bool UnorderedArray::findWord(string s,int& pos)
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

bool UnorderedArray::addWord(string s) {

        int pos=-2;
        if(findWord(s,pos)){
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

// Αυτό δουλεύει? και γιατί δεν το έχουμε φτιάξει δυναμικά?
//οχι δυναμικο σε περιπτωση προσθηκης λεξεων
/* Data temp;
temp.setWord(data[t].getWord());
        temp.setNumOfTimes(data[t].getNumOfTimes());
        data[t].setWord(data[length - 1].getWord());
        data[length - 1].setWord("~");
        data[length - 1].setNumOfTimes(0);
        length--;
*/
bool UnorderedArray::deleteWord(string s) {
    int t;
   if (findWord(s, t)) {
        data[t]=data[numOfData-1];
        data[numOfData].setWord(" ");
        data[numOfData].setNumOfTimes(0);
        numOfData--;
        return true;
    }
    return false;
}


