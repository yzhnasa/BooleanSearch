#ifndef __PostingItem_H
#define __PostingItem_H
#include <iostream>
#include <string>
using namespace std;

class PostingItem{
    private:
        string term;
        string docID;
    public:
        explicit PostingItem();
        explicit PostingItem(string term, string docID);
        void setTerm(string term);
        string getTerm();
        void setDocID(int docID);
        int getDocID();
        ~PostingItem();
};
#endif
