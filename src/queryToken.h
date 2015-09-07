#ifndef __QueryToken_H
#define __QueryToken_H

#define TOK_NULL_TYPE       0
#define QUERY_TYPE          1
#define OPERATOR_TYPE       2

#define OP_NULL_TYPE        0
#define AND_TYPE            1
#define OR_TYPE             2
#define NOT_TYPE            3

#include <string>
using namespace std;

class QueryToken{
    private:
        string token;
        int tokenType; // Two type: query string, operator.
        int operatorType; // Three type: AND, OR, NOT.
        //QueryToken *nextQueryToken;
        QueryToken *leftNextQueryToken;
        QueryToken *rightNextQueryToken;
    public:
        explicit QueryToken();
        explicit QueryToken(string token, int tokenType, int operatorType);
        void setToken(string token);
        string getToken();
        void setTokenType(int tokenType);
        int getTokenType();
        bool isTokenQueryType();
        bool isTokenOperatorType();
        void setOperatorType(int operatorType);
        int getOperatorType();
        bool isAndType();
        bool isOrType();
        bool isNotType();
        void setLeftNextQueryToken(QueryToken *leftNextQueryToken);
        QueryToken *getLeftNextQueryToken();
        bool isLeftNextQueryTokenNull();
        void setRightNextQueryToken(QueryToken *rightNextQueryToken);
        QueryToken *getRightNextQueryToken();
        bool isRightNextQueryTokenNull();
        //void setNextQueryToken(QueryToken *nextQueryToken);
        //QueryToken *getNextQueryToken();
        //bool isNextQueryTokenNull();
        ~QueryToken();
};
#endif
