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
        int frequency;
        vector<PostingItem *> postingItems;
    public:
        explicit DictionaryTerm();
        explicit DictionaryTerm(string term);
        void setTerm(string term);
        string getTerm();
        void setFrequency(int frequency);
        void frequencyIncreasingOne();
        int getFrequency();
        void setPostingItem(PostingItem *postingItem);
        PostingItem *getPostingItem(int index);
        int getPostingItemsSize();
        ~DictionaryTerm();
};
#endif
