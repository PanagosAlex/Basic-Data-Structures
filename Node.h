#ifndef Node_h
#define Node_h
#include <string>
#include <iostream>

using namespace std;
/*
 * This class represents a Node in a Binary Search Tree.
 */
class Node{
  private:
    string data;
    Node *leftchild;
    Node *rightchild;
  public:
    Node(string);
    Node(string, Node *, Node *);
    
    void setData(string);
    string getData();
    void setLeftChild(Node *);
    Node *getLeftChild();
    void setRightChild(Node *);
    Node *getRightChild();
};

#endif