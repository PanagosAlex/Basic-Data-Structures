#include "BinarySearchTree.h"
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

BinarySearchTree::BinarySearchTree(string a)
{
  Node test(a,NULL,NULL);
  root = &test;
}

void BinarySearchTree::insert(Node* root,string a)
{
  if( a.compare(root->getData()) > 0)
    {
      if(root->getRightChild()==NULL)
      {
        Node *tempNode = new Node(a);
        root->setRightChild(tempNode);
      }
      else
        insert(root->getLeftChild(), a);
    }
  else
    {
      if(root->getLeftChild()==NULL)
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