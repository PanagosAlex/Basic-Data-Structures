#include <iostream>
#include <string>
#include "UnorderedArray.h"

using namespace std;

int main() {
  string data[20] = {"dolphin","colony","governor","clay","precedent","rage","governor","purple","tokyo","dolphin","rails","infrastructure","bible","tokyo","slime","capitalism","commence","bible","wilderness","rainbow"};
  int dataLen=20;

  UnorderedArray a(data,20);
  a.addWord("blueple");
    for(int i=0;i<a.getLength();i++){
        cout<<a.getWord(i)<<endl;
    }
}
//fstream what if the file has 2 blanks between the words? or both a . and a blank