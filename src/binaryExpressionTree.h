#ifndef __BinaryExpressionTree_H
#define __BinaryExpressionTree_H
#include <vector>
#include <stack>
#include <string>
#include "queryToken.h"
using namespace std;

class BinaryExpressionTree{
    private:
        QueryToken *root;
    public:
        explicit BinaryExpressionTree();
        explicit BinaryExpressionTree(vector<QueryToken *> &queryToken); // Build tree here.
        void buildBinaryExpressionTree(vector<QueryToken *> &queryToken); // Build tree here.
        void setRoot(QueryToken *root);
        QueryToken *getRoot();
        // Some tree operations.
        // return subtree
        // delete subtree
};
#endif
