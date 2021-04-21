#include <iostream>
#include <string>
#include "UnorderedArray.h"
#include "OrderedArray.h"

using namespace std;

int main() {
    int dataLen=20;

    //UnorderedArray Test
     string data[20] = {"dolphin","colony","governor","clay","precedent","rage","governor","purple","tokyo","dolphin","rails","infrastructure","bible","tokyo","slime","capitalism","commence","bible","wilderness","rainbow"};
    UnorderedArray a(data,dataLen);
     a.addWord("blueple");
     /*for(int i=0;i<a.getLength();i++){
         cout<<a.getWord(i)<<endl;
     }*/

    //OrderedArray Test

    int t=0;
    string sorted_data[20] = {"Bible", "Bible","Capitalism","Clay", "Colony", "Commence","Dolphin","Dolphin","Governor","Governor","Infrastructure","Precedent","Purple","Rage","Rails","Rainbow","Slime","Tokyo","Tokyo","Wilderness"};
    OrderedArray b(sorted_data, dataLen);
    /*cout<<b.findWord("Random",t)<<endl;
    cout<<t<<endl;
    cout<<b.findWord("Dolphin",t)<<endl;
    cout<<t<<endl;
    cout<<"test"<<endl;*/

  cout<<b.addWord("Eva")<<endl<<b.findWord("Eva",t)<<endl<<t<<endl<<b.getWord(t)<<endl;

  cout<<b.findWord("Eva",t)<<endl;
  cout<<b.deleteWord("Eva")<<endl;
  cout<<b.findWord("Eva",t);

}
//fstream what if the file has 2 blanks between the words? or both a . and a blank