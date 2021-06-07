#ifndef AVLSEARCHTREE_H
#define AVLSEARCHTREE_H
#include <string>
#include "BinarySearchTree.h"

class AVLSearchTree: public BinarySearchTree{
private:
    int height;
    int difference;

public:
    AVLSearchTree(string);
    void insertWord(string a);
    int getHeight();
    int getDifference();
    int calculateHeight(Node* root);
    void simpleRightRotation(Node* x);
    void simpleLeftRotation(Node* x);
    int maxOfTrees(int a,int b){
        if (a>b){
            return a;
        }
        return b;
    }
};
#endif //AVLSEARCHTREE_H