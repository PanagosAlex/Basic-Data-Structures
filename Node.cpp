#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

Node::Node(string a)
{
  data=a;
  leftchild=NULL;
  rightchild=NULL;
}

Node::Node(string a,Node *l, Node *r)
{
  data=a;
  leftchild=l;
  rightchild=r;
}

void Node::setData(string d)
{
  data=d;
}

string Node::getData()
{
  return data;
}

void Node::setLeftChild(Node *l)
{
  leftchild=l;
}

Node* Node::getLeftChild()
{
  return leftchild;
}

void Node::setRightChild(Node *r)
{
  rightchild=r;
}

Node* Node::getRightChild()
{
  return rightchild;
}