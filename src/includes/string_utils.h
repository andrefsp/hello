#ifndef _HELLO_STRING_UTILS_H
#define _HELLO_STRING_UTILS_H

// Tokenization
char **str_tokenize(char *text, const char *sep);

// Tokenization N times
char **str_n_tokenize(char *text, const char *sep, int n);

// left strip
char *str_lstrip(char *text, char ch);

// right strip
char *str_rstrip(char *text, char ch);

// full string strip
char *str_strip(char *text, char ch);

// clean cariage returns
char *str_clean(char *text);

#endif
