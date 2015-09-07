#ifndef __Dictionary_H
#define __Dictionary_H
#include <string>
#include <vector>
#include <ext/hash_map>
#include "dictionary.h"
#include "dictionaryTerm.h"
#include "binaryExpressionTree.h"
using namespace std;
using namespace __gnu_cxx;

class Dictionary{
    private:
        hash_map<string, DictionaryTerm *> dictionary;
    public:
        explicit Dictionary();
        bool isDictionaryTermExit(string term);
        void setDictionaryTerm(string term, DictionaryTerm *dictionaryTerm);
        DictionaryTerm *getDictionaryTerm(string term);
        vector<PostingItem *> *processingSearchQuery(BinaryExpressionTree *binaryExpressionTree);
        void printResult(vector<PostingItem *> *result);
        // Union operation.
        // Intersection operation.
        // Complement operation.
        ~Dictionary();
};
#endif
