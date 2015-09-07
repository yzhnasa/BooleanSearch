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

BinaryExpressionTree *BooleanSearchParser::parseringQueryStringBuildBinaryExpressionTree(vector<string> *queryToken){

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

Dictionary *BooleanSearchParser::buildDictionary(PostingsList *postingsList){
    Dictionary *dictionary = new Dictionary();
    postingsList->sortPostingsList();
    return dictionary;
}
