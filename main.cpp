#include <iostream>
#include <string>
#include "UnorderedArray.h"
#include "OrderedArray.h"
#include "BinarySearchTree.h"
#include "Node.h"
#include "AVLSearchTree.h"

using namespace std;

int main() {
    AVLSearchTree tree("leg");
    tree.insertWord("sky");
    tree.insertWord("fox");
    tree.insertWord("cat");
    tree.insertWord("nit");
    tree.insertWord("ice");
    tree.insertWord("vat");
    tree.insertWord("mud");
     tree.inOrder(tree.getRoot());
     cout<<endl;
     cout<<tree.getHeight()<<endl;
     cout<<tree.getDifference();

    return 0;
}