#include <iostream>
#include <string>
#include "UnorderedArray.h"
#include "OrderedArray.h"
#include "BinarySearchTree.h"
#include "Node.h"
#include "AVLSearchTree.h"
#include "FileHandling.h"
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;
using namespace std::chrono;



int main() {
    FileHandling f("small-file.txt");
    string *data;
    string *set;
    set = f.Qset(1000);
    data = f.getWords();







}