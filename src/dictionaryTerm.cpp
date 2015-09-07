#include "dictionaryTerm.h"


DictionaryTerm::DictionaryTerm(){
    this->term = "";
    this->frequency = 0;
}

DictionaryTerm::DictionaryTerm(string term){
    this->term = term;
    this->frequency = 0;
}

void DictionaryTerm::setTerm(string term){
     this->term = term;
}

string DictionaryTerm::getTerm(){
     return this->term;
}

void DictionaryTerm::setFrequency(int frequency){
    this->frequency = frequency;
}

void DictionaryTerm::frequencyIncreasingOne(){
     this->frequency++;
}

int DictionaryTerm::getFrequency(){
     return this->frequency;
}

void DictionaryTerm::setPostingItem(PostingItem *postingItem){
    postingItems.push_back(postingItem);
}

PostingItem *DictionaryTerm::getPostingItem(int index){
     return this->postingItems.at(index);
}

int DictionaryTerm::getPostingItemsSize(){
     return this->postingItems.size();
}

DictionaryTerm::~DictionaryTerm(){

}
