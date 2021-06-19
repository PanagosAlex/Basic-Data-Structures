#include "AVLSearchTree.h"
/*
* κατασκευαστής που δέχεται ως όρισμα μια λέξη a
*/
AVLSearchTree:: AVLSearchTree(string a):BinarySearchTree(a){

    height=1;
    difference=0;
}
/*
* getter για το height
*/
int AVLSearchTree:: getHeight(){
    return height;
}
/*
* getter για το difference
*/
int AVLSearchTree:: getDifference(){
    difference=abs(calculateHeight(root->getLeftChild())-calculateHeight(root->getRightChild()));
    return difference;
}
/*
* υπολογίζει την διαφορά στο ύψος του δέντρου
*/
int AVLSearchTree:: calculateHeight(Node* p){
    if(p==NULL){
        return 0;
    }
    else{
        height=maxOfTrees(calculateHeight(p->getLeftChild()),calculateHeight(p->getRightChild()))+1;
        return height;
    }
}
/*
* εισάγει μια λέξη a στο δέντρο
*/
void AVLSearchTree:: insertWord(string a){
    BinarySearchTree::insertWord(a);
    calculateHeight(root);
}
/*
* αφαιρεί μια λέξη a άπο το δέντρο
*/
void AVLSearchTree:: deleteWord(string a){
  BinarySearchTree::deleteWord(a);
  calculateHeight(root);
}
/*
* επιτελεί μια απλή δεξιά περιστροφή
*/
void AVLSearchTree:: simpleRightRotation(Node* x){
  Node* tempparent,* tempy,* tempB;

 tempparent = x->getParent(); 
  tempy = x->getRightChild();
  tempB = tempy->getRightChild();

  x->setLeftChild(tempB);
  tempB->setParent(x);
  tempy->setRightChild(x);
  x->setParent(tempy);
  if(tempparent!= NULL)
    tempy->setParent(tempparent);
  else
    tempy->setParent(NULL);
}
/*
* επιτελεί μια απλή αριστερή περιστροφή
*/
void AVLSearchTree:: simpleLeftRotation(Node* x){
  Node* tempparent,* tempy,* tempB;

  tempparent = x->getParent(); 
  tempy = x->getRightChild();
  tempB = tempy->getRightChild();

  x->setRightChild(tempB);
  tempB->setParent(x);
  tempy->setLeftChild(x);
  x->setParent(tempy);
  if(tempparent!= NULL)
    tempy->setParent(tempparent);
  else
    tempy->setParent(NULL);
}
/*
* επιτελεί μια πολύπλοκη δεξιά περιστροφή
*/
void AVLSearchTree:: complexRightRotation(Node* x){
  Node* tempparent,* tempy,* tempx,* tempB1,* tempB2,* tempz;

  tempparent = x->getParent(); 
  tempy = x->getRightChild();
  tempx = tempy->getParent();
  tempz = tempy->getLeftChild();
  tempB1 = tempz->getLeftChild();
  tempB2 = tempz->getRightChild();

  tempy->setLeftChild(tempB2);
  tempB2->setParent(tempy);
  tempx->setRightChild(tempB1);
  tempB1->setParent(tempx);
  tempz->setLeftChild(tempx);
  tempz->setRightChild(tempy);
  tempx->setParent(tempz);
  tempy->setParent(tempz);
  if(tempparent!= NULL)
    tempz->setParent(tempparent);
  else
    tempz->setParent(NULL);
}
/*
* επιτελεί μια πολύπλοκη αριστερή περιστροφή
*/
void AVLSearchTree:: complexLeftRotation(Node* x){
  Node* tempparent,* tempy,* tempx,* tempB1,* tempB2,* tempz;

  tempparent = x->getParent(); 
  tempy = x->getLeftChild();
  tempx = tempy->getParent();
  tempz = tempy->getLeftChild();
  tempB1 = tempz->getLeftChild();
  tempB2 = tempz->getRightChild();

  tempx->setLeftChild(tempB2);
  tempB2->setParent(tempx);
  tempy->setRightChild(tempB1);
  tempB1->setParent(tempy);
  tempz->setRightChild(tempx);
  tempy->setLeftChild(tempy);
  tempx->setParent(tempz);
  tempy->setParent(tempz);
  if(tempparent!= NULL)
    tempz->setParent(tempparent);
  else
    tempz->setParent(NULL);
}