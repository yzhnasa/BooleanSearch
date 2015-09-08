#include "binaryExpressionTree.h"

BinaryExpressionTree::BinaryExpressionTree(){
    this->root = NULL;
}

BinaryExpressionTree::BinaryExpressionTree(vector<QueryToken *> &queryToken){
    stack<QueryToken *> tokenStack;
    QueryToken *tempLeftToken = NULL;
    QueryToken *tempRightToken = NULL;
    QueryToken *tempRootToken = NULL;
    for(unsigned int i = 0; i < queryToken.size(); i++){
        if(queryToken.at(i)->isTokenRightBracketType()){
            tempRightToken = tokenStack.top();
            tokenStack.pop();
            tempRootToken = tokenStack.top();
            tokenStack.pop();
            tempLeftToken = tokenStack.top();
            tokenStack.pop();
            tokenStack.pop();
            tempRootToken->setRightNextQueryToken(tempRightToken);
            tempRootToken->setLeftNextQueryToken(tempLeftToken);
            tokenStack.push(tempRootToken);
        }else{
            tokenStack.push(queryToken.at(i));
        }
    }
}

void BinaryExpressionTree::buildBinaryExpressionTree(vector<QueryToken *> &queryToken){
    stack<QueryToken *> tokenStack;
    //QueryToken * = NULL;
    QueryToken *tempLeftToken = NULL;
    QueryToken *tempRightToken = NULL;
    QueryToken *tempRootToken = NULL;
    for(unsigned int i = 0; i < queryToken.size(); i++){
        if(queryToken.at(i)->isTokenRightBracketType()){
            tempRightToken = tokenStack.top();
            tokenStack.pop();
            tempRootToken = tokenStack.top();
            tokenStack.pop();
            tempLeftToken = tokenStack.top();
            tokenStack.pop();
            tokenStack.pop();
            tempRootToken->setRightNextQueryToken(tempRightToken);
            tempRootToken->setLeftNextQueryToken(tempLeftToken);
            tokenStack.push(tempRootToken);
            this->root = tempRootToken;
        }else{
            tokenStack.push(queryToken.at(i));
        }
    }
}

void BinaryExpressionTree::setRoot(QueryToken *root){
     this->root = root;
}

QueryToken *BinaryExpressionTree::getRoot(){
     return this->root;
}
