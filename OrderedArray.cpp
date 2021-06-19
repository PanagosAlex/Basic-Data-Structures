#include "OrderedArray.h"
#include <string>

/*
 * κατασκευαστής με κληρονομικότητα
 */
OrderedArray::OrderedArray(Data *a, int len): UnorderedArray(a,len){
}
/*
 * κατασκευαστής με κληρονομικότητα
 */
OrderedArray::OrderedArray(int len): UnorderedArray(len){

}
/*
 * bool συνάρτηση αναζήτησης λέξεων επιστρέφει true αν η λέξη βρεθεί και false σε κάθε άλλη περίπτωση
 */
bool OrderedArray:: searchWord(string word, int &pos){
        int l=0;
        int r=numOfData-1;
        while (l <= r) {
           int mid = (l + r)/ 2;

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

/*
 * bool συνάρτηση εισαγωγής λέξεων επιστρέφει true αν η λέξη καταφέρει να εισαχθεί και false σε κάθε άλλη περίσταση
 */
bool OrderedArray:: insertWord(string word) {
if(numOfData<length){
    int pos=-2;
    if(searchWord(word,pos)){
        ++data[pos];
        return true;
    }
    else{

        data[numOfData].setWord(word);
        data[numOfData].setNumOfTimes(1);
        numOfData++;
    }
    int j;
    Data k;
    for (int i = 1; i < numOfData; i++)
    {
        k = data[i];
        j = i - 1;
        while (j >= 0 && data[j].getWord() > k.getWord())
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = k;
    }
    return true;
}
    return false;
}

/*
 * bool συνάρτηση διαγραφής λέξεων επιστρέφει true αν η λέξη καταφέρει να διαγραφείκαι false σε κάθε άλλη περίσταση
 */
bool OrderedArray:: deleteWord(string word)
{
  int pos=0;
  if(searchWord(word,pos))
  {
    for(int i=pos; i<length-1; i++)
    {
      data[i].setWord(data[i+1].getWord());
      data[i].setNumOfTimes(data[i+1].getNumOfTimes());
    }
    numOfData--;
    return true;
  }
  return false;

}



