/*
*AEM: 3591
*Ονοματεπώνυμο: Ευαγγελία Στάμογλου
*
*AEM: 3782
*Ονοματεπώνυμο: Αλέξανδρος Πανάγος
*/
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

/*
 * Αυτή είναι η κύρια κλάση του προγράμματος. Κατά την εκτέλεση εισάγει 500 τυχαίες
 * λέξεις στις δομές και εμφανίζει ανα δομή τις λέξεις που περιέχει και τις εμφανίσεις τους.
 */

int main() {
    FileHandling f("small-file.txt");
    string *data;
    string *set;
    set = f.Qset(50);
    data = f.getWords();

    UnorderedArray ua(50);
    OrderedArray oa(50);
    BinarySearchTree bst(set[0]);
    HashTable ht(50);

    for(int i=0;i<50;i++){
        ua.insertWord(set[i]);
        oa.insertWord(set[i]);
        ht.insertWord(set[i]);
        if(i>=1)
            bst.insertWord(set[i]);
    }

    cout<<"-----------------------UNORDERED ARRAY-----------------------"<<endl;
    ua.printData();
    cout<<"-----------------------ORDERED ARRAY-----------------------"<<endl;
    oa.printData();
    cout<<"-----------------------HASH TABLE-----------------------"<<endl;
    ht.printData();
    cout<<"-----------------------BINARY SEARCH TREE-----------------------"<<endl;
    bst.inOrder(bst.getRoot());

}