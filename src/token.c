#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/token.h"


static int compare_keywords(const void *word, const void *element)
{
    const char *searched_word = (const char *) word;
    const Keyword *kw = (const Keyword*) element;
    return strcmp(searched_word, kw->lexeme);
}

TokenType lookup_token(const char *lexeme)
{
    Keyword *match = bsearch(
        lexeme,
        KEYWORDS,
        NUM_KEYWORDS,
        sizeof(Keyword),
        compare_keywords
    );

    if (match != NULL)
    {
        return match->type;
    }

    return TokenID;
}

void token_print(const Token *t) {
    printf("Print Token!");
}
