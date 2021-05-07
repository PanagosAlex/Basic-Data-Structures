#ifndef UnorderedArray_h
#define UnorderedArray_h

using namespace std;
/*
 * This class represents an Unordered Array.
 */
class UnorderedArray{
  protected:
    string* data;
    int length;
  public:

    UnorderedArray(string a[],int len);
    ~UnorderedArray();

    bool setWord(string, int);
    string getWord(int);
    int getLength();

    bool findWord(string, int&);
    bool addWord(string);
    bool deleteWord(string);
    int numOfTimes(int n);

};

#endif