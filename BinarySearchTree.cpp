#include "BinarySearchTree.h"
#include <iostream>
#include <string>


using namespace std;

BinarySearchTree::BinarySearchTree(string a)
{
  Node test(a,NULL,NULL);
  root = &test;
}

void BinarySearchTree::insert(Node* root, string a )
{
  //Δοκιμασε να αλλαξεις την root->getData() με το true και δουλευει. D:<
  if( root->getData() > a)
  //if(true)
    {
      if(root->getRightChild())
      {
        Node *tempNode = new Node(a);
        root->setRightChild(tempNode);
      }
      else
        insert(root->getLeftChild(), a);
    }
  else
    {
      if(root->getLeftChild())
      {
        Node *tempNode = new Node(a);
        root->setLeftChild(tempNode);
      }
      else
        insert(root->getRightChild(), a);
    }
}

void BinarySearchTree::insertWord(string data) 
{
   insert(root, data);
}

bool BinarySearchTree:: findWord(string word, Node * &parent){
    Node * r1= root;
    Node * prev=root;
    bool flag= false;
    while(!flag && !(r1->getRightChild()==NULL || r1->getLeftChild()==NULL)){
        if(word==r1->getData()){
            flag=true;
            parent=prev;
            return true;
        }
        prev=r1;
        if (word>r1->getData()){
            r1=r1->getRightChild();
        }
        else {
            r1=r1->getLeftChild();
        }
    }
    return false;
}

bool BinarySearchTree::deleteWord(string word) {
    Node *r;
    Node *toBeDeleted;
    if(findWord(word,r)){
        if(r->getLeftChild()->getData()==word)
            toBeDeleted=r->getLeftChild();
        else
            toBeDeleted=r->getRightChild();
        if(toBeDeleted->getRightChild()==NULL && toBeDeleted->getLeftChild()==NULL){
            if(r->getLeftChild()->getData()==word){
                r->setLeftChild(NULL);
            }
            else
            {
                r->setRightChild(NULL);
            }
        }
        else if (toBeDeleted->getRightChild()!=NULL || toBeDeleted->getLeftChild()!=NULL){
            Node* child;
            if(toBeDeleted->getRightChild()!=NULL){
                child= toBeDeleted->getRightChild();
            }
            else{
                child= toBeDeleted->getLeftChild();
            }
            if(r->getLeftChild()->getData()==word)
                r->setLeftChild(child);
            else
                r->setRightChild(child);
        }
        else{
            Node* replace=getMinNode(toBeDeleted);
            toBeDeleted->setData(replace->getData());
            deleteWord(replace->getData());
        }
        return true;
    }
    return false;
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