#include <assert.h>
#include <string.h>

#include "../src/hello.c"

void test_hashmap_construct() {
    Hashmap *map = NewHashmap();
    assert(((void)"size", map->Size == 0));
}

void test_hashmap_get_and_set() {
    Hashmap *map = NewHashmap();

    map->Set(map, "key1", "value1");
    char *value1 = map->Get(map, "key1");
    assert(((void)"get and set", strcmp(value1, "value1") == 0));

    map->Set(map, "key2", "value2");
    char *value2 = map->Get(map, "key2");
    assert(((void)"get and set", strcmp(value2, "value2") == 0));

    char *value3 = map->Get(map, "doesnotexist");
    assert(((void)"null value", !value3));
}

void test_hashmap_multiple_set_same_key() {
    Hashmap *map = NewHashmap();

    map->Set(map, "key", "value1");
    char *value = map->Get(map, "key");
    assert(((void)"get and set", strcmp(value, "value1") == 0));
    assert(((void)"size", map->Size == 1));

    map->Set(map, "key", "new_value");
    value = map->Get(map, "key");
    assert(((void)"get and set", strcmp(value, "new_value") == 0));
    assert(((void)"size after", map->Size == 1));
}


void test_hashmap_get_and_set_delete() {
    Hashmap *map = NewHashmap();

    map->Set(map, "key1", "value1");
    map->Set(map, "key2", "value2");

    map->Delete(map, "key1");
    char *value1 = map->Get(map, "key1");
    assert(((void)"null value", !value1));

    char *value2 = map->Get(map, "key2");
    assert(((void)"get and set", strcmp(value2, "value2") == 0));
}

void test_hashmap_get_and_set_ints() {
    Hashmap *map = NewHashmap();

    int x = 10;
    int y = 20;

    map->Set(map, "key1", &x);
    map->Set(map, "key2", &y);

    int *value1 = map->Get(map, "key1");
    assert(((void)"key 1 equal", *value1 == 10));

    int *value2 = map->Get(map, "key2");
    assert(((void)"key 2 equal", *value2 == 20));
}


void test_hashmap_strange_combinations() {
    Hashmap *map = NewHashmap();
    
    char *ctype = "text/html";
    char *custom = "myheader";
    char *etag = "anothra";

    map->Set(map, "Content-Type", ctype);
    map->Set(map, "X-Custom", custom);
    map->Set(map, "ETag", etag);

    char *value1 = map->Get(map, "Content-Type");
    char *value2 = map->Get(map, "X-Custom");
    char *value3 = map->Get(map, "ETag");

    assert(((void)"ctype check", strcmp(value1, "text/html") == 0));
    assert(((void)"custom check", strcmp(value2, "myheader") == 0));
    assert(((void)"another check", strcmp(value3, "anothra") == 0));
}

void test_hashmap(void) {
    for (int x = 0; x < 10000; x++) {
        test_hashmap_construct();
        test_hashmap_get_and_set();
        test_hashmap_get_and_set_delete();
        test_hashmap_multiple_set_same_key();
        test_hashmap_get_and_set_ints();
        test_hashmap_strange_combinations();
    }
}
