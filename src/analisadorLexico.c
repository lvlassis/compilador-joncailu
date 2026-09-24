#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "include/token.h"

TokenType automato(char caracter){
    switch (caracter) {
    case "$":
        return TokenEOF;
        break;
    case "~":
        return TokenUnop;
        break;
    case "{":
        return TokenLBrack;
        break;
    case "}":
        return TokenRBrack;
        break;
    case ";":
        return TokenSemicolon;
        break;
    case "(":
        return TokenLParen;
        break;
    case ")":
        return TokenRParen;
        break;
    case "+":
        return TokenBinop;
        break;
    case "-":
        return TokenBinop;
        break;
    case "/":
        return TokenBinop;
        break;
    case "\%":
        return TokenBinop;
        break;
    case ">":
        return TokenBinop;
        break;
    case "<":
        return TokenBinop;
        break;
    case "<=":
        return TokenBinop;
        break;
    case ">=":
        return TokenBinop;
        break;
    case "==":
        return TokenBinop;
        break;
    case "!=":
        return TokenBinop;
        break;
    case "=":
        return TokenBinop;
        break;
    case ",":
        return TokenComma;
        break;
    case "\\n":
        return TokenIgn;
        break;
    case "\\s":
        return TokenIgn;
        break;
    case "\\t":
        return TokenIgn;
        break;
    
    default:
        if (isalpha(caracter)) {
            return TOKEN_ID; // Ou o retorno que sua função gerar
        } else if (isdigit(caracter)) {
            return TokenInt;
        } else {
            return TokenErr; 
        }
    }
}
