#ifndef TOKEN_DEFINITION
#define TOKEN_DEFINITION

#include <stddef.h>

typedef enum 
{
    TokenProg,
    TokenStart,
    TokenRep,
    TokenID,
    TokenLParen,
    TokenRParen,
    TokenLBrack,
    TokenRBrack,
    TokenComma,
    TokenIf,
    TokenElse,
    TokenSens,
    TokenEnd,
    TokenInt,
    TokenBinop,
    TokenUnop,
    TokenEOF,
    TokenFunc,
    TokenReturn,
    TokenSemicolon,
    TokenIgn,
    TokenComment,
    TokenErr
} TokenType;

typedef struct
{
    TokenType type;
    char lexeme[1024];
} Token;

typedef Token Keyword;

static const Keyword KEYWORDS[] = {
    {TokenProg, "programa"},
    {TokenStart, "inicio"},
    {TokenIf, "se"},
    {TokenElse, "senao"},
    {TokenSens, "sujo"},
    {TokenSens, "obstaculo"},
    {TokenEnd, "fim"},
    {TokenFunc, "func"},
    {TokenReturn, "devolva"}
};

static const size_t NUM_KEYWORDS = sizeof(KEYWORDS) / sizeof(KEYWORDS[0]);

TokenType lookup_token(const char *lexeme);

#endif