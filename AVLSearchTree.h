#ifndef AVLSEARCHTREE_H
#define AVLSEARCHTREE_H
#include <string>
#include "BinarySearchTree.h"

/*
 * Αυτή η κλάση αναπαριστά ένα Δυαδικό Δέντρο τυπου AVL
 */

class AVLSearchTree: public BinarySearchTree{
private:
    int height;
    int difference;

public:
    AVLSearchTree(string);
    void insertWord(string a);
    void deleteWord(string a);
    int getHeight();
    int getDifference();
    int calculateHeight(Node* root);
    void simpleRightRotation(Node* x);
    void simpleLeftRotation(Node* x);
    void complexRightRotation(Node* x);
    void complexLeftRotation(Node* x);
    int maxOfTrees(int a,int b){
        if (a>b){
            return a;
        }
        return b;
    }
    void simpleLeftRotationtest(){
      simpleLeftRotation(root);
    }
    void simpleRightRotationtest(){
      simpleRightRotation(root);
    }
    void complexRightRotationtest(){
      complexRightRotation(root);
    }
};
#endif //AVLSEARCHTREE_H