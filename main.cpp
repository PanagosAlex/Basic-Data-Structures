#include <iostream>
#include <string>
#include "UnorderedArray.h"
#include "OrderedArray.h"
#include "BinarySearchTree.h"
#include "Node.h"

using namespace std;

int main() {/*
  Node a("test");
  //Node b("test");
  Node* pointer;

  //ptrBox = &Box1;
  pointer = &a;

  a.setLeftChild(pointer);

  cout<<a.getData()<<endl<<a.getLeftChild();*/

  BinarySearchTree test("test");
  test.insertWord("Eva");
  cout<<"test";
  return 0;
}