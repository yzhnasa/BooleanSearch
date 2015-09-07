#include "postingItem.h"

PostingItem::PostingItem(){
    this->term = "";
    this->docID = "";
}

PostingItem::PostingItem(string term, string docID){
    this->term = term;
    this->docID = docID;
}
void PostingItem::setTerm(string term){
     this->term = term;
}

string PostingItem::getTerm(){
     return this->term;
}

void PostingItem::setDocID(string docID){
     this->docID = docID;
}

string PostingItem::getDocID(){
     return this->docID;
}

PostingItem::~PostingItem(){

}
