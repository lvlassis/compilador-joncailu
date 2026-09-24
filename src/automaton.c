#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "include/token.h"
#include "include/automaton.h"

TokenType handle_state_transition(StateType *state, char caracter)
{
    StateType newState = Unknown;
    TokenType probTokenType;
    TokenType ignToken = TokenNULL;
    switch (caracter) {
            case '$':
                newState = StateEOF;
                break;
            case '{':
                newState = Markup;
                probTokenType = TokenLBrack;
                break;
            case '}':
                newState = Markup;
                probTokenType = TokenRBrack;
                break;
            case ';':
                newState = Markup;
                probTokenType = TokenSemicolon;
                break;
            case '(':
                newState = Markup;
                probTokenType = TokenLParen;
                break;
            case ')':
                newState = Markup;
                probTokenType = TokenRParen;
                break;
            case '+':
                newState = GenericBinop;
                break;
            case '-':
                newState = GenericBinop;
                break;
            case '/':
                newState = GenericBinop;
                break;
            case '\%':
                newState = GenericBinop;
                break;
            case '>':
                newState = GreatherThan;
                break;
            case '<':
                newState = LessThan;
                break;
            case '=':
                newState = Equal;
                break;
            case '!':
                newState = Different;
                break;
            case '|':
                newState = GenericBinop;
                break;
            case '&':
                newState = GenericBinop;
                break;
            case ',':
                newState = Markup;
                probTokenType = TokenComma;
                break;
            case '\n':
                newState = Start;
                ignToken = TokenIgn;
                break;
            case ' ':
                newState = Start;
                ignToken = TokenIgn;
                break;
            case '\t':
                ignToken = TokenIgn;
                newState = Start;
                break;
            case '#':
                newState = Comment;
                break;
            default:
                newState = Unknown;
    }
    printf("cahar: %c\n", caracter);
    printf("state %d\n", *state);

    if (*state == Start)
    {
        if (newState == Unknown)
        {
            if (isalpha(caracter) || caracter == '_')
                *state = Id;
            else if (isdigit(caracter)) 
                *state = Numeric;
            else 
                *state = Error;
        }
        else
            *state = newState;
        if (ignToken == TokenIgn)
            return TokenIgn; 
        return TokenNULL;
    }
    else if (*state == Id) {
        if (newState == Unknown)
        {
            if (isalpha(caracter) || caracter == '_' || isdigit(caracter))
            {
                *state = Id;
                return TokenNULL;
            }
            else
            {
                *state = Error;
            }
        }
        *state = Start;
        return TokenID;
    }
    else if (*state == Comment) 
    {
        if (caracter == '\n')
        {
            *state = Start;
            return TokenComment;
        }
        return TokenNULL;
    }
    else if (*state == Numeric)
    {
        if (newState == Unknown)
        {
            if (!isdigit(caracter))
            {
                *state = Start;
            }
            else
            {
                *state = Error;
            }
        }
        return TokenInt;
    }
    else if (*state == GreatherThan || *state == LessThan || *state == Equal || *state == Different)
    {
        
        if (caracter == '=')
        {
            *state = GenericBinop;
            return TokenNULL;
        }

        
        if (!newState == Unknown && (isalpha(caracter) || caracter == '_' || isdigit(caracter)))
        {
            *state = Error;
        }

        *state = Start;
        if (newState == Different)
            return TokenUnop;
        return TokenBinop;
    }
    else if (*state == StateEOF)
    {
        if (caracter == '\0')
        {
            *state = Start;
        }
        *state = Error;
        return TokenEOF;
    }
    else if (*state == GenericBinop)
    {
        if (newState == Unknown)
        {
            if (!newState == Unknown && (isalpha(caracter) || caracter == '_' || isdigit(caracter)))
                *state = Error;
            else
                *state = Start;
        }
        return TokenBinop;
    }
    else if (*state == Markup)
    {
        if (newState == Unknown)
        {
            if (!newState == Unknown && (isalpha(caracter) || caracter == '_' || isdigit(caracter)))
                *state = Error;
            else
                *state = Start;
        }
        return probTokenType;
    }
    else {
        *state = Error;
        return TokenNULL;
    }
}
