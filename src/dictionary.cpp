#include "dictionary.h"

Dictionary::Dictionary(){

}

bool Dictionary::isDictionaryTermExit(string term){
    DictionaryTerm *tempDictionaryTerm = dictionary[term];
    if(tempDictionaryTerm != NULL)
        return true;
    return false;
}

void Dictionary::setDictionaryTerm(string term, DictionaryTerm *dictionaryTerm){
    dictionary[term] = dictionaryTerm;
}

DictionaryTerm *Dictionary::getDictionaryTerm(string term){
     return dictionary[term];
}
