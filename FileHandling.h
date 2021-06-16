#ifndef FILEHANDLING_H
#define FILEHANDLING_H
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

class FileHandling {
private:
    string filename;
    string *words;
    int length;
public:
FileHandling(string name);
string * getWords();
int getLength();
void removeChars(int);
bool readFile();
void toLowercase(int);
void removeBlankSpaces();
};


#endif //FILEHANDLING_H