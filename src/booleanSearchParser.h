#ifndef __BooleanSearchParser_H
#define __BooleanSearchParser_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
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
        static int checkTokenType(string queryString);
        static int checkOperatorType(string queryString);
        static BinaryExpressionTree *parseringQueryStringBuildBinaryExpressionTree(vector<string> &queryString);
        static PostingsList *parseringFileBuildPostingsList(string filename);
        static void buildDictionary(Dictionary &dictionary, PostingsList &postingsList);
};
#endif
