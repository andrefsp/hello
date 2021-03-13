#include <assert.h>
#include <string.h>
#include "../src/hello.c"

void test_str_clean() { 
    char *res = str_clean("type\r\n");
    assert(strcmp(res, "type") == 0);

    res = str_clean("type\r");
    assert(strcmp(res, "type") == 0);

    res = str_clean("type\n");
    assert(strcmp(res, "type") == 0);
}


void test_str_lstrip() {
    char *text = "  this is a test";
    char *res = str_lstrip(text, ' ');
    
    assert(strcmp(res, "this is a test") == 0);
}

void test_str_rstrip() {
    char *text = "this is a test   ";
    char *res = str_rstrip(text, ' ');

    assert(strcmp(res, "this is a test") == 0);
}

void test_str_rstrip_new_lines() {
    char *text = "Content-Type: text/html\n";
    char *res = str_rstrip(text, '\n');
    
    assert(strcmp(res, "Content-Type: text/html") == 0);
}

void test_str_rstrip_carrige_return() {
    char *text = "Content-Type: text/html\r";
    char *res = str_rstrip(text, '\r');
    
    assert(strcmp(res, "Content-Type: text/html") == 0);
}


void test_str_rstrip_carrige_return_new_lines() {
    char *text = str_clean("Content-Type: text/html\r\n");
    char *res = str_rstrip(text, '\n');
    
    res = str_rstrip(text, '\r');
    
    
    assert(strcmp(res, "Content-Type: text/html") == 0);
}


void test_str_strip() {
    char *text = "  this is a test   ";
    char *res = str_strip(text, ' ');

    assert(strcmp(res, "this is a test") == 0);
}

void test_str_tokenize() { 
    char *text = "this is a test";
    char **parts = str_tokenize(text, " ");
    
    assert(strcmp("this", parts[0]) == 0);
    assert(strcmp("is", parts[1]) == 0);   
    assert(strcmp("a", parts[2]) == 0);   
    assert(strcmp("test", parts[3]) == 0);   
}

void test_str_tokenize_escape() { 
    char *text = "this \"W\"";
    char **parts = str_tokenize(text, " ");
   
    assert(strcmp("this", parts[0]) == 0);
    assert(strcmp("\"W\"", parts[1]) == 0);   
}

void test_str_tokenize_no_char_to_break() { 
    char *text = "this is a test";
    char **parts = str_tokenize(text, "|");
   
    assert(strcmp("this is a test", parts[0]) == 0);
}

void test_str_n_tokenize() { 
    char *text = "this is a test";
    char **parts = str_n_tokenize(text, " ", 1);

    assert(strcmp("this", parts[0]) == 0);
    assert(strcmp("is a test", parts[1]) == 0);   
}


void test_str_n_tokenize_multiple() { 
    char *text = "this is a test";
    char **parts = str_n_tokenize(text, " ", 2);

    assert(strcmp("this", parts[0]) == 0);
    assert(strcmp("is", parts[1]) == 0);
    assert(strcmp("a test", parts[2]) == 0);   
}

void test_str_n_tokenize_no_char_to_break() { 
    char *text = "this is a test";
    char **parts = str_n_tokenize(text, "|", 2);
   
    assert(strcmp("this is a test", parts[0]) == 0);
}

void test_str_n_tokenize_more_breaks_than_items() { 
    char *text = "this is a test";
    char **parts = str_n_tokenize(text, " ", 100);

    assert(strcmp("this", parts[0]) == 0);
    assert(strcmp("is", parts[1]) == 0);   
    assert(strcmp("a", parts[2]) == 0);
    assert(strcmp("test", parts[3]) == 0);   
}


void test_string_utils() {
    test_str_tokenize();
    test_str_tokenize_escape();
    test_str_tokenize_no_char_to_break(); 
    test_str_n_tokenize();
    test_str_n_tokenize_multiple();
    test_str_n_tokenize_no_char_to_break(); 
    test_str_n_tokenize_more_breaks_than_items(); 

    test_str_clean();

    test_str_lstrip();
    test_str_rstrip_new_lines();
    test_str_rstrip_carrige_return(); 
    test_str_rstrip_carrige_return_new_lines(); 
    test_str_rstrip();
    test_str_strip(); 
}
