#include "FileHandling.h"
FileHandling::FileHandling(string name) {
    words= new string[600000];
    length=0;
    filename=name;
    //read file in string array word by word
   if(readFile()){
       for(int j=0;j<length;j++){
           //remove all characters beside letters
           removeChars(j);
           //turn characters to lowercase
           toLowercase(j);
       }
       removeBlankSpaces();
   }
}
string * FileHandling::getWords(){
    return words;
}
int FileHandling::getLength() {
    return length;
}
bool FileHandling::readFile(){
    ifstream file;
    file.open(filename);
    if (file.is_open()){
        while (file >> words[length]){
            length++;
        }
        return true;
    }
    else{
        cout<<"File Error"<<endl;
        return  false;
    }
}
void FileHandling::removeChars(int j) {
    for(int k=0; k<words[j].length();k++){
        if (words[j][k]<65 || words[j][k]>122){
            words[j].erase(k);
        }
    }}
void FileHandling::toLowercase(int j){
    for(int k=0; k<words[j].length();k++){
        words[j][k]=tolower(words[j][k]);
    }
}
void FileHandling::removeBlankSpaces(){
    string * fin=new string[length];
    int count=0;
    for(int j=0;j<length;j++){
        if(words[j]!=""){
            fin[count++]=words[j];
        }
    }
    delete[] words;
    words=fin;
    length= count;
}