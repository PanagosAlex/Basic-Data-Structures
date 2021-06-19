#ifndef BinarySearchTree_h
#define BinarySearchTree_h
#include <string>
#include <iostream>
#include "Node.h"

using namespace std;
/*
 * This class represents a Binary Search Tree.
 */
class BinarySearchTree{
  protected:
    Node* root;
    Node* found;
    void insert(Node* , string);
    bool search(Node *,string);
    bool increaseDecrease(Node *,string,bool);
  public:
    BinarySearchTree(string);
    void setRoot(Node*);
    Node* getRoot();
    void insertWord(string);
    bool deleteWord(string);
    bool searchWord(string);
    void inOrder(Node*);
    void preOrder(Node*);
    void postOrder(Node*);
    Node* getMinNode(Node*);
};

#endif