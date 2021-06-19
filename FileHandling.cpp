#include "FileHandling.h"
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <string>

/*
 * κατασκευαστής με όρισμα συμβολοσειρά name που αναπαριστά το όνομα του αρχείου
 */
FileHandling::FileHandling(string name) {
    words= new string[6000000];
    length=6000000;
    aow=0;
    filename=name;
    //Διάβασμα του αρχείου λέξη λέξη
   if(readFile()){
       for(int j=0;j<aow;j++){
           //αφαίρεση ανεπιθύμητων χαρακτήρων
           removeChars(j);
           //μετατροπή λέξεων σε πεζά
           toLowercase(j);
       }
       //αφαίρεση κενών θέσεων του πίνακα
       removeBlankSpaces();
   }
}

/*
 * getter του πίνακα λέξεων
 */
string * FileHandling::getWords(){
    return words;
}
/*
 * getter του μεγέθους του πίνακα
 */
int FileHandling::getLength() {
    return length;
}
/*
 * bool συνάρτηση που διαβάζει το αρχείο και το εισάγει στον πίνακα λέξεων
 */
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

/*
 * void συνάρτηση που δέχεται με int μία θέση του πίνακα και αφαιρεί όλους τους χαρακτήρες
 * που περιέχει η συμβολοσειρά εκτός απο αυτούς που ανήκουν στο λατινικό αλφάβητο
 */
void FileHandling::removeChars(int j) {
    for(int k=0; k<words[j].length();k++){
        if (words[j][k]<65 || words[j][k]>122 || (words[j][k]>90 && words[j][k]<97)) {
            words[j].erase(k);
        }
    }}

/*
* void συνάρτηση που δέχεται με int μία θέση του πίνακα και μετατρέπει όλους τους χαρακτήρες σε πεζούς
 */
void FileHandling::toLowercase(int j){
for(int k=0; k<words[j].length();k++){
    words[j][k]=tolower(words[j][k]);
}
}

/*
 * void συνάρτηση που αφαιρεί τις κενές θέσεις του πίνακα
 */
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

/*
 * string * συνάρτηση που δέχεται με int το μέγεθος του συνόλου Q και επιστρέφει τον πίνακα που αποτελεί το σύνολο Q
 */
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
