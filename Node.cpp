#include "Node.h"
#include <iostream>
#include <string>

using namespace std;
Node::Node(){
    data.setWord(nullptr);
    data.setNumOfTimes(0);
    leftchild=NULL;
    rightchild=NULL;
    parent= NULL;
}

Node::Node(string a)
{
  data.setWord(a);
  data.setNumOfTimes(1);
  leftchild=NULL;
  rightchild=NULL;
  parent= NULL;
}

Node::Node(string a,Node *l, Node *r,Node *p)
{
  data.setWord(a);
  data.setNumOfTimes(1);
  leftchild=l;
  rightchild=r;
  parent= p;
}

void Node::setData(string d)
{
  data.setWord(d);
}

string Node::getData()
{
  return data.getWord();
}

void Node::setTimes(int d)
{
  data.setNumOfTimes(d);
}

int Node::getTimes()
{
  return data.getNumOfTimes();
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

void Node::setParent(Node* p){
    parent= p;
}

Node* Node::getParent(){
    return parent;
}

bool Node:: hasOneChild(){
    if((rightchild!=NULL && leftchild==NULL) ||
    (leftchild!=NULL && rightchild==NULL)){
        return true;
    }
    return false;
}

bool Node:: hasNoChildren(){
    if(rightchild==NULL && leftchild==NULL){
        return true;
    }
    return false;
}
bool Node:: isRightChild(){
    if(parent->getRightChild()==this){
        return true;
    }
    return false;
}
bool Node::  isLeftChild(){
    if(parent->getLeftChild()==this){
        return true;
    }
    return false;
}*/