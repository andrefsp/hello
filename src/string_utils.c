#include "gc.h"
#include <stdlib.h>
#include <string.h>

#ifndef _HELLO_STRING_UTILS_C
#define _HELLO_STRING_UTILS_C

#include "string_utils.h"


char *str_clean(const char *text) {
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


char *str_strip(const char *text, char ch) {
    char *strip = str_rstrip(text, ch);
    return str_lstrip(strip, ch);
}


char *str_rstrip(const char *text, char ch) {
    const int len = strlen(text);
    char *string = GC_MALLOC(len*sizeof(char));
    strcpy(string, text);

    int x = len-1;
    while (string[x] == ch) { x--; }
    string[x+1] = '\0';
    return string;
}


char *str_lstrip(const char *text, char ch) {
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


char **str_tokenize(const char *text, const char *sep) {
    const int len = strlen(text);

    char *string = GC_MALLOC(len*sizeof(char));
    strcpy(string, text);

    int numparts = 0;
    for (int x = 0; x < len; x++) {
        if (string[x] == *sep)
            numparts++;
    }

    char **output = GC_MALLOC((numparts+1)*sizeof(char*));

    char *token;
    token = strtok(string, sep);

    numparts = 0;

    output[numparts] = GC_MALLOC(strlen(token)*sizeof(char));
    strcpy(output[numparts], token);
    numparts++;

    while(token != NULL) {
        token = strtok(NULL, sep);
        if (!token)
            break;
        output[numparts] = GC_MALLOC(strlen(token)*sizeof(char));
        strcpy(output[numparts], token);
        numparts++;
    }
    return output;
}


char **str_n_tokenize(const char *text, const char *sep, int n) {
    if (n < 1) {
        return str_tokenize(text, sep);
    }

    const int len = strlen(text);

    char string[len];
    strcpy(string, text);

    int numbreak = 0;
    for (int x = 0; x < len; x++) {
         if (string[x] == *sep)
            numbreak++;
         if (numbreak == n)
            break;
    }

    char *token;
    char **output = GC_MALLOC((numbreak+1)*sizeof(char*));

    numbreak = 0;
    int breakIndex = 0;

    token = strtok(string, sep);
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

    return output;
}


char *str_concat(char *current, char *next) {
    char *ret = GC_MALLOC((strlen(current)+strlen(next))*sizeof(char));
    strcat(ret, current);
    strcat(ret, next);
    return ret; 
}


#endif
