#include "OrderedArray.h"
#include <string>


OrderedArray::OrderedArray(string *a, int len): UnorderedArray(a,len){
}

OrderedArray:: ~OrderedArray(){
    delete[] data;
}

bool OrderedArray:: findWord(string word, int& pos){
        int l=0;
        int r=length-1;
        while (l <= r) {
            int mid = l + (r-l)/ 2;
            if (data[mid] == word){
                pos=mid;
                return true;
            }
            if (data[mid] < word)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
}
bool OrderedArray:: addWord(string word){
}
bool OrderedArray:: deleteWord(string word){
}


