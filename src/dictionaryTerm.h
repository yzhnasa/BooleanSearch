#ifndef __DictionaryTerm_H
#define __DictionaryTerm_H
#include <iostream>
#include <string>
#include <vector>
#include "postingItem.h"
using namespace std;

class DictionaryTerm{
    private:
        string term;
        unsigned int frequency;
        vector<PostingItem *> postingItems;
    public:
        explicit DictionaryTerm();
        explicit DictionaryTerm(string term);
        void setTerm(string term);
        string getTerm();
        void setFrequency(unsigned int frequency);
        void frequencyIncreasingOne();
        int getFrequency();
        void setPostingItem(PostingItem *postingItem);
        PostingItem *getPostingItem(unsigned int index);
        unsigned int getPostingItemsSize();
        ~DictionaryTerm();
};
#endif
