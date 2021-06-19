#include "BinarySearchTree.h"
#include <iostream>
#include <string>

//found, prepei na yparxei? Δεν θα ήταν πιο αποτελεσματικό να γίνει όρισμα στις συναρτήσεις που το χρειάζεσαι ως &found ?

using namespace std;

BinarySearchTree::BinarySearchTree(string a)
{
  Node* node= new Node(a);
  root = node;
}

void BinarySearchTree:: setRoot(Node* node){
    root=node;
}

Node* BinarySearchTree:: getRoot(){
    return root;
}

void BinarySearchTree::insert(Node* r, string a)
{ 
  if(!searchWord(a)){
    if( a.compare(r->getData())>0 )
    {
      if(r->getRightChild()==NULL)
      {
          Node *tempNode = new Node(a,NULL,NULL,r);
          r->setRightChild(tempNode);
      }
      else
        insert(r->getRightChild(), a);
    }
  else //if(a.compare(r->getData())<0)
    {
      if(r->getLeftChild()==NULL)
      {
          Node *tempNode = new Node(a,NULL,NULL,r);
          r->setLeftChild(tempNode);
      }
      else
        insert(r->getLeftChild(), a);
    }
  }
  else{
    increaseDecrease(r, a, true);
  }
}

void BinarySearchTree::insertWord(string data) 
{
   insert(root, data);
}

bool BinarySearchTree:: search(Node * r,string a){
   if(r==NULL){
        return false;
   }
   if(r->getData()==a){
       found=r;
       return true;
   }
   else if( a.compare(r->getData())>0 )
   {
       return search(r->getRightChild(),a);
   }
    else
   {
       return search(r->getLeftChild(),a);
   }
   return false;
}

bool BinarySearchTree:: increaseDecrease(Node * r,string a, bool b){
   if(r->getData()==a){
    if(b)
       r->increase();
    else
      r->decrease();
      return true;
   }
   else if( a.compare(r->getData())>0 )
   {
       return search(r->getRightChild(),a);
   }
    else
   {
       return search(r->getLeftChild(),a);
   }
   return false;
}

bool BinarySearchTree:: searchWord(string a){
    return search(root,a);
}

bool BinarySearchTree::deleteWord(string a) {
   if(!search(root,a)){
       return false;
   }
   else{
       if(found->hasNoChildren()){
           if(found->getParent()==NULL){
               root->setData(" ");
               root->setTimes(0);
           }
           else if(found->isLeftChild()){
               found->getParent()->setLeftChild(NULL);
           }
           else if(found->isRightChild()){
               found->getParent()->setRightChild(NULL);
           }
       }
       else if(found->hasOneChild()){
           if(found->getParent()==NULL){
               if(found->getRightChild()!=NULL){
                   setRoot(root->getRightChild());
               }
               else{
                  setRoot(root->getLeftChild());
               }
           }
           else if(found->getRightChild()!=NULL){

               if(found->isLeftChild()){
                   found->getParent()->setLeftChild(found->getRightChild());
               }
               if(found->isRightChild()){
                   found->getParent()->setRightChild(found->getRightChild());
               }
           }
           else{
               if(found->isLeftChild()){
                   found->getParent()->setLeftChild(found->getLeftChild());
               }
               if(found->isRightChild()){
                   found->getParent()->setRightChild(found->getLeftChild());
               }
           }
       }
       else {
           string replaceW=getMinNode(found->getRightChild())->getData();
           int replaceN=getMinNode(found->getRightChild())->getTimes();
           if(getMinNode(found->getRightChild())->isLeftChild()){
               getMinNode(found->getRightChild())->getParent()->setLeftChild(NULL);
           }
           if(getMinNode(found->getRightChild())->isRightChild()){
               getMinNode(found->getRightChild())->getParent()->setRightChild(NULL);
           }
           if(found->getParent()==NULL){
               root->setData(replaceW);
               root->setTimes(replaceN);
           }
           else if(found->isLeftChild()){
               found->getParent()->getLeftChild()->setData(replaceW);
               found->getParent()->getLeftChild()->setTimes(replaceN);
           }

          else if(found->isRightChild()){
               found->getParent()->getRightChild()->setData(replaceW);
               found->getParent()->getRightChild()->setTimes(replaceN);
           }
       }
       return true;

   }
}

void BinarySearchTree::inOrder(Node * root)
{
  if (!root)
  {
    return;
  }
  inOrder(root->getLeftChild());
  cout<<root->getData()<<" ";
  inOrder(root->getRightChild());
}

void BinarySearchTree::preOrder(Node * root)
{
  if (!root)
  {
    return;
  }
  cout<<root->getData()<<" ";
  preOrder(root->getLeftChild());
  preOrder(root->getRightChild());
}

void BinarySearchTree::postOrder(Node * root)
{
  if (!root)
  {
    return;
  }
  postOrder(root->getLeftChild());
  postOrder(root->getRightChild());
  cout<<root->getData()<<" ";
}

Node* BinarySearchTree:: getMinNode(Node* n){
    while (n->getLeftChild() != NULL) {
        n = n->getLeftChild();
    }
    return n;
}