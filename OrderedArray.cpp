#include "OrderedArray.h"
#include <string>


OrderedArray::OrderedArray(Data *a, int len): UnorderedArray(a,len){
}

OrderedArray::OrderedArray(int len): UnorderedArray(len){

}

bool OrderedArray:: searchWord(string word, int &pos){
        int l=0;
        int r=numOfData-1;
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

bool OrderedArray:: insertWord(string word) {
    if(numOfData<length){
        int pos = -2;
        if (searchWord(word, pos)) {
            ++data[pos];
            return true;
        } else {

            data[numOfData].setWord(word);
            data[numOfData].setNumOfTimes(1);
            numOfData++;
            int j;
            Data k;
            for (int i = 1; i < numOfData; i++) {
                k = data[i];
                j = i - 1;
                while (j >= 0 && data[j].getWord() > k.getWord()) {
                    data[j + 1] = data[j];
                    j--;
                }
                data[j + 1] = k;
                return true;
            }
        }
    }
    return false;
}

bool OrderedArray:: deleteWord(string word)
{
  int pos=0;
  if(searchWord(word,pos))
  {
    for(int i=pos; i<numOfData; i++)
    {
      data[pos].setWord(data[pos+1].getWord());
      data[pos].setNumOfTimes(data[pos+1].getNumOfTimes());
    }
    return true;
  }
  return false;

}



