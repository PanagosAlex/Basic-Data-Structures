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
    string* data;
    void insert(Node* ,string);
    // int numofdata; //or maybe height of tree?
  public:
    BinarySearchTree(string);
    //setters getters
    void insertWord(string data);
    bool deleteWord(string);
    bool findWord(string,Node *&);
    void inOrder(Node*);
    void preOrder(Node*);
    void postOrder(Node*);
    Node* getMinNode(Node*);
};

#endif