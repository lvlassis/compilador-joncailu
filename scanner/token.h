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