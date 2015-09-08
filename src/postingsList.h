#ifndef __PostingsList_H
#define __PostingsList_H
#include <string>
#include <vector>
#include <algorithm>
#include "postingItem.h"
using namespace std;

class PostingsList{
    private:
        vector<PostingItem *> postingItems;
    public:
        explicit PostingsList();
        void setPostingItem(PostingItem *postingItem);
        PostingItem *getPostingItem(unsigned int index);
        unsigned int getPostingItemsSize();
        static bool comparePostingItem(PostingItem *itemA, PostingItem *itemB);
        void sortPostingsList();
        ~PostingsList();
};
#endif
