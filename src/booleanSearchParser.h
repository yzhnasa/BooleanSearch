#ifndef __BooleanSearchParser_H
#define __BooleanSearchParser_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "postingItem.h"
#include "postingsList.h"
#include "dictionaryTerm.h"
#include "dictionary.h"
#include "queryToken.h"
#include "binaryExpressionTree.h"
using namespace std;

class BooleanSearchParser{
    public:
        static vector<string> *tokenizer(string textString);
        static BinaryExpressionTree *parseringQueryStringBuildBinaryExpressionTree(vector<string> *queryToken);
        static PostingsList *parseringFileBuildPostingsList(string filename);
        static Dictionary *buildDictionary(PostingsList *postingsList);
};
#endif
