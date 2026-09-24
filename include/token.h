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
    TokenNULL
} TokenType;

typedef struct
{
    TokenType type;
    char *lexeme;
} Token;

typedef Token Keyword;

static const Keyword KEYWORDS[] = {
    {TokenReturn, "devolva"},
    {TokenEnd, "fim"},
    {TokenFunc, "func"},
    {TokenStart, "inicio"},
    {TokenSens, "obstaculo"},
    {TokenProg, "programa"},
    {TokenRep, "repetir"},
    {TokenIf, "se"},
    {TokenElse, "senao"},
    {TokenSens, "sujo"}
};

static const size_t NUM_KEYWORDS = sizeof(KEYWORDS) / sizeof(KEYWORDS[0]);

TokenType lookup_token(const char *lexeme);

void token_print(const Token *t);

void free_token(Token *token);

#endif
