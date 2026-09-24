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
    TokenAct,
    TokenEnd,
    TokenInt,
    TokenBinop,
    TokenUnop,
    TokenEOF,
    TokenFunc,
    TokenReturn,
    TokenSemicolon,
    TokenIgn,
    TokenComment
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
    {TokenAct, "direita"},
    {TokenAct, "esquerda"},
    {TokenAct, "limpar"},
    {TokenAct, "mover"},
    {TokenEnd, "fim"},
    {TokenFunc, "func"},
    {TokenReturn, "devolva"}
};

