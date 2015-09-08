#include "booleanSearchParser.h"

vector<string> *BooleanSearchParser::tokenizer(string textString){
    vector<string> *tokens = new vector<string>;
    vector<char> token;
    unsigned int i = 0;
    while(i != textString.size()){
        if(textString[i] == ' '
                || textString[i] == '\t'
                || textString[i] == ','
                || textString[i] == '.'){
            if(!token.empty())
                tokens->push_back(string(token.begin(), token.end()));
            token.clear();
        }else
            token.push_back(textString[i]);
        i++;
    }
    tokens->push_back(string(token.begin(), token.end()));
    return tokens;
}

int BooleanSearchParser::checkTokenType(string queryString){
     if(queryString == "AND" || queryString == "OR" || queryString == "NOT")
         return OPERATOR_TYPE;
     if(queryString == "(")
         return LEFT_BRACKET_TYPE;
     if(queryString == ")")
         return RIGHT_BRACKET_TYPE;
     return QUERY_TYPE;
}

int BooleanSearchParser::checkOperatorType(string queryString){
     if(queryString == "AND")
         return AND_TYPE;
     if(queryString == "OR")
         return OR_TYPE;
     if(queryString == "NOT")
         return NOT_TYPE;
     return OP_NULL_TYPE;
}

BinaryExpressionTree *BooleanSearchParser::parseringQueryStringBuildBinaryExpressionTree(vector<string> &queryString){
    //queryToken
    vector<QueryToken *> tokenList;
    QueryToken *tempToken = NULL;
    int tokenType;
    int operatorType;
    for(unsigned int i = 0; i < queryString.size(); i++){
        tokenType = checkTokenType(queryString.at(i));
        operatorType = checkOperatorType(queryString.at(i));
        tempToken = new QueryToken(queryString.at(i), tokenType, operatorType);
        tokenList.push_back(tempToken);
    }
    BinaryExpressionTree *binaryExpressionTree = new BinaryExpressionTree(tokenList);
    return binaryExpressionTree;
}

PostingsList *BooleanSearchParser::parseringFileBuildPostingsList(string filename){
    fstream inputStream(filename, ios::in);
    if(!inputStream){
        cout << "Open file " << filename << " fail." << endl;
        exit(1);
    }

    string line;
    vector<string> *tokens = NULL;
    PostingsList *postingsList = new PostingsList();
    PostingItem *tempPostingItem = NULL;
    while(!inputStream.eof()){
        getline(inputStream, line);
        if(!line.empty()){
            tokens = tokenizer(line);
            for(unsigned int i = 0; i < tokens->size(); i++){
                tempPostingItem = new PostingItem(tokens->at(i), filename);
                postingsList->setPostingItem(tempPostingItem);
            }
        }
    }
    return postingsList;
}

void BooleanSearchParser::buildDictionary(Dictionary &dictionary, PostingsList &postingsList){
    //Dictionary *dictionary = new Dictionary();
    postingsList.sortPostingsList();
    PostingItem *tempPostingItem = NULL;
    DictionaryTerm *tempDictionaryTerm = NULL;
    string tempTerm;
    for(unsigned int i = 0; i < postingsList.getPostingItemsSize(); i++){
        tempPostingItem = postingsList.getPostingItem(i);
        tempTerm = tempPostingItem->getTerm();
        std::transform(tempTerm.begin(), tempTerm.end(), tempTerm.begin(), ::tolower);
        if(dictionary.isDictionaryTermExit(tempTerm)){
            tempDictionaryTerm = dictionary.getDictionaryTerm(tempTerm);
            tempDictionaryTerm->setPostingItem(tempPostingItem);
        }else{
            tempDictionaryTerm = new DictionaryTerm(tempTerm);
            dictionary.setDictionaryTerm(tempTerm, tempDictionaryTerm);
        }
        tempDictionaryTerm->frequencyIncreasingOne();
    }
    //return dictionary;
}
