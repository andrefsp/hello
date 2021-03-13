#ifndef _HELLO_STRING_UTILS_C
#define _HELLO_STRING_UTILS_C

#include <stdlib.h>
#include <string.h>
#include "gc.h"
#include "string_utils.h"


char *str_clean(char *text) {
    const int len = strlen(text);
    char *string = GC_MALLOC(len*sizeof(char));
    
    int si = 0;
    int ti = 0;
    while (ti < len) {
        if (text[ti] == '\r' || text[ti] == '\n') {
            ti +=1;
            continue;
        }
        string[si] = text[ti];
        ti++;
        si++;
    }
    string[si] = '\0';
    return string;
}


char *str_strip(char *text, char ch) {
    char *lstrp = str_lstrip(text, ch);
    char *strip = str_rstrip(lstrp, ch);

    GC_FREE(lstrp);
    return strip;
}

char *str_rstrip(char *text, char ch) {
    const int len = strlen(text);
    int x = len-1;
    while (text[x] == ch) { x--; }

    char *string = GC_MALLOC(x*sizeof(char));
    for (int i = 0; i <= x; i++) {
        string[i] = text[i];
    }
    string[x+1] = '\0';
    return string;
}

char *str_lstrip(char *text, char ch) { 
    int x = 0;
    while (text[x] == ch) { x++; }
    
    const int len = strlen(text);
    const int tlen = (len-x);
    char *string = GC_MALLOC(tlen*sizeof(char));

    for (int i = x; i < len; i++) {
        string[i-x] = text[i];
    }

    string[tlen] = '\0';
    return string;
}

char **str_tokenize(char *text, const char *sep) {
    const int len = strlen(text);

    char string[len];
    strcpy(string, text);
    
    char **output = GC_MALLOC(sizeof(char*));

    char *token = strtok(string, sep);
    int numparts = 0;

    output[numparts] = GC_MALLOC(strlen(token)*sizeof(char));
    strcpy(output[numparts], token);
    numparts++;
 
    while(token != NULL) {
        char *token = strtok(NULL, sep);
        if (!token)
            break;
        output[numparts] = GC_MALLOC(strlen(token)*sizeof(char));
        strcpy(output[numparts], token);
        numparts++;
    }
    
    return output;
}


char **str_n_tokenize(char *text, const char *sep, int n) {
    if (n < 1) { 
        return str_tokenize(text, sep);
    }

    const int len = strlen(text);

    char string[len];
    strcpy(string, text);

    char **output = GC_MALLOC(sizeof(char*));
    
    int numbreak = 0;
    int breakIndex = 0;

    char *token = strtok(string, sep);
    for (int i = 0; i < n; i++) {
        if (!token)
            break;
                 
        breakIndex += (strlen(token)+strlen(sep));
        numbreak++;
        output[i] = GC_MALLOC(strlen(token)*sizeof(char));
        strcpy(output[i], token);

        token = strtok(NULL, sep);
    }
 
    char *rest = GC_MALLOC(len*sizeof(char));
    for (int i = breakIndex; i < len; i++)
        rest[i-breakIndex] = text[i];
    
    output[numbreak] = GC_MALLOC(strlen(rest)*sizeof(char));
    strcpy(output[numbreak], rest);
   
    GC_FREE(rest);
    return output;
}


#endif
