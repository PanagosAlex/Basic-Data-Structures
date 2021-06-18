#include "FileHandling.h"
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <string>

FileHandling::FileHandling(string name) {
    words= new string[6000000];
    length=6000000;
    aow=0;
    filename=name;
    //read file in string array word by word
   if(readFile()){
       for(int j=0;j<aow;j++){
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
    string word;
    file.open(filename);
    if (file.is_open()){
        while (file >> word){
            if (aow==length && aow!=0){
                string * temp=new string[length+200];
                if(temp== nullptr){
                    cout<<"Not enough memory";
                    return false;
                }
                else{
                    for(int i=0;i<aow+200;i++){
                        temp[i]=words[i];
                    }
                    delete[] words;
                    words=temp;
                    length+=200;
                }
            }
                words[aow]=word;
                aow++;
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
        if (words[j][k]<65 || words[j][k]>122 || (words[j][k]>90 && words[j][k]<97)) {
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

string* FileHandling::Qset(int size) {
    if (size<=length){
        int parallel[length];
        for(int i=0;i<length;i++){
            parallel[i]=0;
        }
        string * set=new string[size];
        srand(time(NULL));
        int random= rand()%length;
        for(int i=0;i<size;i++){
            while (parallel[random]!=0){
                random= rand()%length;
            }
            parallel[random]++;
            set[i]=words[random];
            random= rand()%length;
        }
        return set;
    }
    else{
        return NULL;
    }
}
