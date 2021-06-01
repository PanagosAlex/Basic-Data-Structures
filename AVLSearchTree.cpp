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
void AVLSearchTree:: rightRotation(){

}
void AVLSearchTree:: leftRotation(){

}