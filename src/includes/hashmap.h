#ifndef _HELLO_HASHMAP_H
#define _HELLO_HASHMAP_H

typedef struct DataItem DataItem;

struct DataItem {
    void *data;   
    void *key;
};

typedef struct Hashmap Hashmap;

struct Hashmap {
    int Size;
    DataItem **Items;

    void (*Set)(Hashmap *h, void *key, void *value);
    void (*Delete)(Hashmap *h, void *key);

    void *(*Get)(Hashmap *h, void *key);
};

void *Hashmap_Get(Hashmap *h, void *key);

void Hashmap_Set(Hashmap *h, void *key, void *value);

void Hashmap_Delete(Hashmap *h, void *key);

Hashmap *NewHashmap();

#endif
