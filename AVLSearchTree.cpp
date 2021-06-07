#include "AVLSearchTree.h"

AVLSearchTree:: AVLSearchTree(string a):BinarySearchTree(a){

    height=1;
    difference=0;
}
int AVLSearchTree:: getHeight(){
    return height;
}
int AVLSearchTree:: getDifference(){
    difference=abs(calculateHeight(root->getLeftChild())-calculateHeight(root->getRightChild()));
    return difference;
}
int AVLSearchTree:: calculateHeight(Node* p){
    if(p==NULL){
        return 0;
    }
    else{
        height=maxOfTrees(calculateHeight(p->getLeftChild()),calculateHeight(p->getRightChild()))+1;
        return height;
    }
}

void AVLSearchTree:: insertWord(string a){
    BinarySearchTree::insertWord(a);
    calculateHeight(root);
}
void AVLSearchTree:: simpleRightRotation(Node* x){
  Node* tempparent,* tempy,* tempB;

  tempparent = x->getParent(); 
  //tempC = x->getLeftChild();
  tempy = x->getRightChild();
  //tempx = tempy->getParent();
  //tempA = tempy->getLeftChild();
  tempB = tempy->getRightChild();

  x->setLeftChild(tempB);
  tempB->setParent(x);
  tempy->setRightChild(x);
  x->setParent(tempy);
  tempy->setParent(tempparent);
}

void AVLSearchTree:: simpleLeftRotation(Node* x){
  Node* tempparent,* tempy,* tempB;

  tempparent = x->getParent(); 
  //tempC = x->getLeftChild();
  tempy = x->getRightChild();
  //tempx = tempy->getParent();
  //tempA = tempy->getLeftChild();
  tempB = tempy->getRightChild();

  x->setRightChild(tempB);
  tempB->setParent(x);
  tempy->setLeftChild(x);
  x->setParent(tempy);
  tempy->setParent(tempparent);
}

//Σημειώσεις μην τις σβήσεις :)
/*void AVLSearchTree:: simpleLeftRotation(Node* x){
  Node* tempparent,*tempC,* tempy,* tempx,* tempA,* tempB;

  tempparent = x->getParent(); 
  tempC = x->getLeftChild();
  tempy = x->getRightChild();
  tempx = tempy->getParent();
  tempA = tempy->getLeftChild();
  tempB = tempy->getRightChild();

}*/