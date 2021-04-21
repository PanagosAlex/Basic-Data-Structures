#include "OrderedArray.h"
#include <string>


OrderedArray::OrderedArray(string *a, int len): UnorderedArray(a,len){
}

bool OrderedArray:: findWord(string word, int &pos){
        int l=0;
        int r=length-1;
        while (l <= r) {
           int mid = (l + r)/ 2;
            if (data[mid] == word){
                pos=mid;
                return true;
            }
            if (data[mid] < word)
                l = mid + 1;
            else
                r = mid - 1;
            pos=mid;
        }
        return false;
}

bool OrderedArray:: addWord(string word)
{
  int pos=0;
  bool test=findWord(word,pos);

    if(UnorderedArray::addWord("zzzzz"))
    {
      for(int i=length-1;i>pos+1;i--)
      {
        data[i] = data[i-1];
      }
      data[pos] = word;
      return true;
    }
  return false;
}

bool OrderedArray:: deleteWord(string word)
{
  int pos=0;
  if(findWord(word,pos))
  {
    for(int i=pos; i<length; i++)
    {
      data[pos]=data[pos+1];
    }

    string *temp = new string[length-1];
    if(temp==nullptr)
        return false;
    for(int i=0;i<length-1;i++){
        temp[i]= data[i];
    }
    delete[] temp;
    length--;
    return true;
  }
  return false;

}
/*
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
}*/