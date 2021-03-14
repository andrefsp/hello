#ifndef _HELLO_STRING_UTILS_H
#define _HELLO_STRING_UTILS_H

// Tokenization
char **str_tokenize(const char *text, const char *sep);

// Tokenization N times
char **str_n_tokenize(const char *text, const char *sep, int n);

// left strip
char *str_lstrip(const char *text, char ch);

// right strip
char *str_rstrip(const char *text, char ch);

// full string strip
char *str_strip(const char *text, char ch);

// clean cariage returns
char *str_clean(const char *text);

#endif
