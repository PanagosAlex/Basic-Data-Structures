#ifndef UnorderedArray_h
#define UnorderedArray_h

using namespace std;
/*
 * This class represents an Unordered Array.
 */
class UnorderedArray
{
  private:
    string* data;
    int length;
  public:
    //UnorderedArray();

    UnorderedArray(string a[],int len);
    ~UnorderedArray();

    bool setWord(string, int);
    string getWord(int);
    int getLength();

    bool findWord(string, int&);
    bool addWord(string);
    bool deleteWord(string);
    int numOfTimes(int );
};

#endif