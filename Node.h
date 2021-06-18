#ifndef Node_h
#define Node_h
#include <string>
#include <iostream>

#include "Data.h"
using namespace std;
/*
 * This class represents a Node in a Binary Search Tree.
 */
class Node{
  private:
    Data data;
    Node *leftchild;
    Node *rightchild;
    Node *parent;
  public:
    Node();
    Node(string);
    Node(string, Node *l, Node *r,Node *p);
    
    void setData(string);
    string getData();
    void setTimes(int);
    int getTimes();
    void setLeftChild(Node *);
    Node *getLeftChild();
    void setRightChild(Node *);
    Node *getRightChild();
    void setParent(Node*);
    Node *getParent();
    bool hasOneChild();
    bool hasNoChildren();
    bool isRightChild();
    bool isLeftChild();
};

#endif