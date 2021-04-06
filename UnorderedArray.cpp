#include <iostream>
#include <string>
#include "UnorderedArray.h"

using namespace std;

/*UnorderedArray::UnorderedArray()
{
  string a[1];
  length =1;
  data = a;
}*/

UnorderedArray::UnorderedArray(string *a,int len)
{
  length = len;
  data = a;
}

bool UnorderedArray::setSentence(string sent,int pos)
{
    if(pos>=0 && pos<length)
    {
      data[pos] = sent;
      return true;
    }
    return false;
}

string UnorderedArray::getSentence(int pos)
{
  return data[pos];
}

bool UnorderedArray::findSentence(string s,int& t)
{
  for(int i=0;i<length;i++)
  {
    if(s == data[i])
    {
      t=i;
      return true;
    }
  }
  return false;
}

bool UnorderedArray::deleteSentence(string s)
{
  int t;
  string temp;

  if(findSentence(s,t))
  {
    temp=data[t];
    data[t]=data[length];
    data[length]="~";
    length--;
    return true;
  }
  
  return false;
}