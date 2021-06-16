#include <iostream>
#include <string>
#include <cstring>
#include "UnorderedArray.h"


using namespace std;

UnorderedArray::UnorderedArray(Data * a,int len)
{
  length = len;
  data = new Data[length];
  //memcpy(data,a,len*sizeof (Data));
    for (int i = 0; i < length; i++) {
        data[i] = a[i];
    }

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
    Data *temp= new Data[length+1];
    if(temp==nullptr)
        return false;
    for(int i=0;i<length;i++){
        temp[i].setWord(data[i].getWord());
        temp[i].setNumOfTimes(data[i].getNumOfTimes());
    }
    delete[] data;
    temp[length].setWord(s);
    temp[length].setNumOfTimes(1);
    data = temp;
    length++;
    return true;
}

// Αυτό δουλεύει? και γιατί δεν το έχουμε φτιάξει δυναμικά?
bool UnorderedArray::deleteWord(string s)
{
  int t;
  Data temp;

  if(findWord(s,t))
  {
    temp.setWord(data[t].getWord());
    temp.setNumOfTimes(data[t].getNumOfTimes());
    data[t].setWord(data[length-1].getWord());
    data[length-1].setWord("~");
    data[length-1].setNumOfTimes(0);
    length--;
    return true;
  }
  
  return false;
}/*

int UnorderedArray::numOfTimes(int n) {
    int times[length];
    for (int i = 0; i < length; i++) {
        times[i] = 0;
    }
    for (int i = 0; i < length; i++) {
        string t = data[i];
        for (int j = 0; j < length; j++) {
            if (t == data[j]) {
                times[i]++;
            }
        }
    }
    return times[n];
}
*/