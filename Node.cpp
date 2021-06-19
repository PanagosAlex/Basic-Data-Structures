#include "Node.h"
#include <iostream>
#include <string>

using namespace std;
/*
* κατασκευαστής που δεν δέχεται κανένα όρισμα
*/
Node::Node(){
    data.setWord(" ");
    data.setNumOfTimes(0);
    leftchild=NULL;
    rightchild=NULL;
    parent= NULL;
}
/*
* κατασκευαστής που δέχεται ως όρισμα μια λέξη a
*/
Node::Node(string a)
{
  data.setWord(a);
  data.setNumOfTimes(1);
  leftchild=NULL;
  rightchild=NULL;
  parent= NULL;
}
/*
* κατασκευαστής που δέχεται ως όρισμα μια λέξη a και 3 δείκτες από Node
*/
Node::Node(string a,Node *l, Node *r,Node *p)
{
  data.setWord(a);
  data.setNumOfTimes(1);
  leftchild=l;
  rightchild=r;
  parent= p;
}
/*
* setter για την λέξη d
*/
void Node::setData(string d)
{
  data.setWord(d);
}
/*
* getter για την λέξη d
*/
string Node::getData()
{
  return data.getWord();
}
/*
* setter για τον αριθμό εμφάνισης της λέξης
*/
void Node::setTimes(int d)
{
  data.setNumOfTimes(d);
}
/*
* getter για τον αριθμό εμφάνισης της λέξης
*/
int Node::getTimes()
{
  return data.getNumOfTimes();
}
/*
* αυξάνει τον αριθμό εμφάνισης της λέξης κατά ένα
*/
void Node::increase()
{
  ++data;
  return;
}
/*
* setter για το αριστερό παιδί του κόμβου
*/
void Node::setLeftChild(Node *l)
{
  leftchild=l;
}
/*
* getter για το αριστερό παιδί του κόμβου
*/
Node* Node::getLeftChild()
{
  return leftchild;
}
/*
* setter για το δεξιό παιδί του κόμβου
*/
void Node::setRightChild(Node *r)
{
  rightchild=r;
}
/*
* getter για το δεξιό παιδί του κόμβου
*/
Node* Node::getRightChild()
{
  return rightchild;
}
/*
* setter για τον γονέα του κόμβου
*/
void Node::setParent(Node* p){
    parent= p;
}
/*
* getter για τον γονέα του κόμβου
*/
Node* Node::getParent(){
    return parent;
}
/*
* επιστέφει true αν ο κόμβος έχει τουλάχιστον ένα παιδί και false στις άλλες περιπτώσεις
*/
bool Node:: hasOneChild(){
    if((rightchild!=NULL && leftchild==NULL) ||
    (leftchild!=NULL && rightchild==NULL)){
        return true;
    }
    return false;
}
/*
* επιστέφει true αν ο κόμβος δεν έχει κανένα παιδί και false στις άλλες περιπτώσεις
*/
bool Node:: hasNoChildren(){
    if(rightchild==NULL && leftchild==NULL){
        return true;
    }
    return false;
}
/*
* επιστέφει true αν ο κόμβος είναι δεξιό  παιδί του γονέα του και false στις άλλες περιπτώσεις
*/
bool Node:: isRightChild(){
    if(parent->getRightChild()==this){
        return true;
    }
    return false;
}
/*
* επιστέφει true αν ο κόμβος είναι αριστερό  παιδί του γονέα του και false στις άλλες περιπτώσεις
*/
bool Node::  isLeftChild(){
    if(parent->getLeftChild()==this){
        return true;
    }
    return false;
}