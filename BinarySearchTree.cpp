#include "BinarySearchTree.h"
#include <iostream>
#include <string>



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
  /*else{
    wordCount++;
    }
    */
}

void BinarySearchTree::insertWord(string data) 
{
   insert(root, data);
}

bool BinarySearchTree:: searchWord(Node * r,string a){
   if(r==NULL){
        return false;
   }
   if(r->getData()==a){
       found=r;
       return true;
   }
   else if( a.compare(r->getData())>0 )
   {
       return searchWord(r->getRightChild(),a);
   }
    else
   {
       return searchWord(r->getLeftChild(),a);
   }
}

bool BinarySearchTree:: searchWord(string a){
    return searchWord(root,a);
}

bool BinarySearchTree::deleteWord(string a) {
   if(!searchWord(root,a)){
       return false;
   }
   else{
       if(found->hasNoChildren()){
           if(found->getParent()==NULL){
               root->setData(" ");
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
           string replace=getMinNode(found->getRightChild())->getData();
           if(getMinNode(found->getRightChild())->isLeftChild()){
               getMinNode(found->getRightChild())->getParent()->setLeftChild(NULL);
           }
           if(getMinNode(found->getRightChild())->isRightChild()){
               getMinNode(found->getRightChild())->getParent()->setRightChild(NULL);
           }
           if(found->getParent()==NULL){
               root->setData(replace);
           }
           else if(found->isLeftChild()){
               found->getParent()->getLeftChild()->setData(replace);
           }
          else if(found->isRightChild()){
               found->getParent()->getRightChild()->setData(replace);
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