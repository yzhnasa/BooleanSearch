#ifndef __BinaryExpressionTree_H
#define __BinaryExpressionTree_H
#include <vector>
#include <string>
#include "queryToken.h"
using namespace std;

class BinaryExpressionTree{
    private:
        QueryToken *root;
    public:
        explicit BinaryExpressionTree();
        explicit BinaryExpressionTree(vector<string> *queryToken); // Build tree here.
        void buildBinaryExpressionTree(vector<string> *queryToken); // Build tree here.
        // Some tree operations.
        // return subtree
        // delete subtree
};
#endif
