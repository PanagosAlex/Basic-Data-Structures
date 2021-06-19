#include "OrderedArray.h"
#include <string>


OrderedArray::OrderedArray(Data *a, int len): UnorderedArray(a,len){
}

OrderedArray::OrderedArray(int len): UnorderedArray(len){

}

bool OrderedArray:: findWord(string word, int &pos){
        int l=0;
        int r=length-1;
        while (l <= r) {
           int mid = (l + r)/ 2;
            pos=mid;
            if (data[mid].getWord() == word){
                pos=mid;
                return true;
            }
            if (data[mid].getWord() < word )
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
}

bool OrderedArray:: addWord(string word)
{
  int pos=0;
  bool test=findWord(word,pos);

  if (test){
    data[pos].increaseNum();
    return true;
  }
  else {
    if(UnorderedArray::addWord("zzzzz"))
    {
      for(int i=length-1;i>pos+1;i--)
      {
        data[i] = data[i-1];
      }
      data[pos].setWord(word);
      data[pos].setNumOfTimes(1);
      return true;
    }
  return false;
  }
}

bool OrderedArray:: deleteWord(string word)
{
  int pos=0;
  if(findWord(word,pos))
  {
    for(int i=pos; i<length; i++)
    {
      data[pos].setWord(data[pos+1].getWord());
      data[pos].setNumOfTimes(data[pos+1].getNumOfTimes());
    }

    Data *temp = new Data[length-1];
    if(temp==nullptr)
        return false;
    for(int i=0;i<length-1;i++){
        temp[i].setWord(data[i].getWord());
        temp[i].setNumOfTimes(data[i].getNumOfTimes());
    }
    delete[] temp;
    length--;
    return true;
  }
  return false;

}



