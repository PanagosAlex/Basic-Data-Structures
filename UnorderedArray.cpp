#include <iostream>
#include <string>
#include "UnorderedArray.h"

using namespace std;

UnorderedArray::UnorderedArray(string *a,int len)
{
  length = len;
  data = new string[length];
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
      data[pos] = w;
      return true;
    }
    return false;
}

string UnorderedArray::getWord(int pos)
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
    if(s == data[i])
    {
      pos=i;
      return true;
    }
  }
  return false;
}

bool UnorderedArray::addWord(string s) {
    string *temp= new string[length+1];
    if(temp==nullptr)
        return false;
    for(int i=0;i<length;i++){
        temp[i]= data[i];
    }
    delete[] data;
    temp[length]=s;
    data = temp;
    length++;
    return true;
}

bool UnorderedArray::deleteWord(string s)
{
  int t;
  string temp;

  if(findWord(s,t))
  {
    temp=data[t]; //what's the use of that?
    data[t]=data[length-1];
    data[length-1]="~";
    length--;
    return true;
  }
  
  return false;
}
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
