#include <iostream>
#include <string>
#include "UnorderedArray.h"
#include "OrderedArray.h"
#include "BinarySearchTree.h"
#include "Node.h"
#include "AVLSearchTree.h"
#include "FileHandling.h"
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;
using namespace std::chrono;



int main(){
    /*FileHandling f("small-file.txt");
    string* data;
    string* set;
    set=f.Qset(1000);
    data=f.getWords();
    int k;
    OrderedArray oa(1000);

    for(int i=0;i<1000;i++){
        oa.addWord(set[i]);
    }
    oa.printData();*/

    //Data a("test");
    OrderedArray test(5);
    int p=-1;

    test.addWord("test1");
    test.addWord("test2");
    test.addWord("test3");
    test.addWord("test4");
    test.addWord("test5");

    test.printData();

    test.findWord("test5", p);
    cout<<"test"<<endl<<p<<endl;
}