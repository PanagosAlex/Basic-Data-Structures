#include "BinarySearchTree.h"
#include <iostream>
#include <string>

using namespace std;
/*
* κατασκευαστής που δέχεται ως όρισμα μια λέξη a
*/
BinarySearchTree::BinarySearchTree(string a)
{
  Node* node= new Node(a);
  root = node;
}
/*
* setter για την ρίζα του δέντρου
*/
void BinarySearchTree:: setRoot(Node* node){
    root=node;
}
/*
* getter για την ρίζα του δέντρου
*/
Node* BinarySearchTree:: getRoot(){
    return root;
}
/*
* δέχεται ως ορίσματα εναν δείκτη r και μια λέξη a και εισάγει στο δέντρο από το r και κάτω την λέξη a
*/
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
    increase(r, a);
  }
}
/*
* δέχεται ως ορίσματα μια λέξη και καλεί την προστατευμένη συνάρτηση insert
*/
void BinarySearchTree::insertWord(string data) 
{
   insert(root, data);
}
/*
* δέχεται ως ορίσματα εναν δείκτη r και μια λέξη a και ψάχνει στο δέντρο να βρει a από το r και κάτω
*/
bool BinarySearchTree:: search(Node * r,string a){
   if(r==NULL){
        return false;
   }
   if(r->getData().compare(a)==0){
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
/*
* δέχεται ως ορίσματα εναν δείκτη r και μια λέξη a και ένα bool b. Αν το b είναι true αυξάνει τον αριθμό εμφάνισης
*/
bool BinarySearchTree:: increase(Node * r,string a){
   if(r->getData()==a){
       r->increase();
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
/*
* δέχεται ως ορίσματα μια λέξη και καλεί την προστατευμένη συνάρτηση search
*/
bool BinarySearchTree:: searchWord(string a){
    return search(root,a);
}
/*
* δέχεται ως ορίσματα μια λέξη και την διαγράφει από την δομή
 */
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
/*
* δέχεται ως ορίσματα έναν δείκτη Node και μεφανίαζει όλα τα στοιχεία σε inorder μορφή
*/
void BinarySearchTree::inOrder(Node * root)
{
  if (!root)
  {
    return;
  }
  inOrder(root->getLeftChild());
  cout<<"Word: "<<root->getData()<<" "<<"Times: "<<root->getTimes()<<endl;
  inOrder(root->getRightChild());
}
/*
* δέχεται ως ορίσματα έναν δείκτη Node και μεφανίαζει όλα τα στοιχεία σε preorder μορφή
*/
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
/*
* δέχεται ως ορίσματα έναν δείκτη Node και μεφανίαζει όλα τα στοιχεία σε postorder μορφή
*/
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
/*
* δέχεται ως ορίσματα έναν δείκτη Node και επιστρέφει το ελάχιστο στοιχείο του δέντρου
*/
Node* BinarySearchTree:: getMinNode(Node* n){
    while (n->getLeftChild() != NULL) {
        n = n->getLeftChild();
    }
    return n;
}