#ifndef UnorderedArray_h
#define UnorderedArray_h

using namespace std;

class UnorderedArray
{
  private:
    string* data;
    int length;
  public:
    //UnorderedArray();
    UnorderedArray(string a[],int len);
    bool setSentence(string, int);
    string getSentence(int);
    bool findSentence(string, int&);
    bool deleteSentence(string);
};

#endif