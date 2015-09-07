#include "queryToken.h"

QueryToken::QueryToken(){
    this->token = "";
    this->tokenType = TOK_NULL_TYPE;
    this->operatorType = OP_NULL_TYPE;
    this->nextQueryToken = NULL;
}

QueryToken::QueryToken(string token, int tokenType, int operatorType){
    this->token = token;
    this->tokenType = tokenType;
    this->operatorType = operatorType;
    this->nextQueryToken = NULL;
}

void QueryToken::setToken(string token){
     this->token = token;
}

string QueryToken::getToken(){
     return this->token;
}

void QueryToken::setTokenType(int tokenType){
     this->tokenType = tokenType;
}

int QueryToken::getTokenType(){
     return this->tokenType;
}

bool QueryToken::isTokenQueryType(){
    if(this->tokenType == QUERY_TYPE)
        return true;
    return false;
}

bool QueryToken::isTokenOperatorType(){
     if(this->tokenType == OPERATOR_TYPE)
         return true;
     return false;
}

void QueryToken::setOperatorType(int operatorType){
     this->operatorType = operatorType;
}

int QueryToken::getOperatorType(){
     return this->operatorType;
}

bool QueryToken::isAndType(){
     if(this->operatorType == AND_TYPE)
         return true;
     return false;
}

bool QueryToken::isOrType(){
     if(this->operatorType == OR_TYPE)
         return true;
     return false;
}

bool QueryToken::isNotType(){
     if(this->operatorType == NOT_TYPE)
         return true;
     return false;
}

void QueryToken::setLeftNextQueryToken(QueryToken *leftNextQueryToken){
    this->leftNextQueryToken = leftNextQueryToken;
}

QueryToken *QueryToken::getLeftNextQueryToken(){
     return this->leftNextQueryToken;
}

bool QueryToken::isLeftNextQueryTokenNull(){
     if(this->leftNextQueryToken == NULL)
         return true;
     return false;
}

void QueryToken::setRightNextQueryToken(QueryToken *rightNextQueryToken){
     this->rightNextQueryToken = rightNextQueryToken;
}

QueryToken *QueryToken::getRightNextQueryToken(){
     return this->rightNextQueryToken;
}

bool QueryToken::isRightNextQueryTokenNull(){
     if(this->rightNextQueryToken == NULL)
         return true;
     return false;
}

/*void QueryToken::setNextQueryToken(QueryToken *nextQueryToken){
     this->nextQueryToken = nextQueryToken;
}

QueryToken *QueryToken::getNextQueryToken(){
     return this->nextQueryToken;
}

bool QueryToken::isNextQueryTokenNull(){
     if(this->nextQueryToken == NULL)
         return true;
     return false;
}*/

QueryToken::~QueryToken(){

}
