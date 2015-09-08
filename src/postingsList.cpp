#include "postingsList.h"

PostingsList::PostingsList(){

}

void PostingsList::setPostingItem(PostingItem *postingItem){
    this->postingItems.push_back(postingItem);
}

PostingItem *PostingsList::getPostingItem(unsigned int index){
    return this->postingItems.at(index);
}

unsigned int PostingsList::getPostingItemsSize(){
     return this->postingItems.size();
}

bool PostingsList::comparePostingItem(PostingItem *itemA, PostingItem *itemB){
    if(itemA->getDocID() > itemB->getDocID())
        return true;
    return false;
}

void PostingsList::sortPostingsList(){
    sort(postingItems.begin(), postingItems.end(), comparePostingItem);
}

PostingItem::~PostingItem(){

}
