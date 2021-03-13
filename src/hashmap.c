#ifndef _HELLO_HASHMAP_C
#define _HELLO_HASHMAP_C


#include "gc.h"
#include "string.h"
#include "stdio.h"
#include "hashmap.h"

void *Hashmap_Get(Hashmap *map, void *lkey) {
    for (int i = 0; i < map->Size; i++) {
        if (strcmp((const char *)map->Items[i]->key, (const char *)lkey) == 0) {
            return map->Items[i]->data;
        }
    }
    return NULL;
}

void Hashmap_Set(Hashmap *map, void *lkey, void *value) {
    for (int i = 0; i < map->Size; i++) {
        if (strcmp((const char *)map->Items[i]->key, (const char *)lkey) == 0) {
            map->Items[i]->data = value;
            return;
        }
    }
    
    DataItem *item = GC_MALLOC(sizeof(DataItem));
    item->key = lkey; 
    item->data = value;
    
    map->Items[map->Size] = item;
    map->Size += 1;
}

void Hashmap_Delete(Hashmap *map, void *lkey) {
    int index = -1;
    for (int i = 0; i < map->Size; i++) {
        if (strcmp((const char *)map->Items[i]->key, (const char *)lkey) == 0) {
            index = i;
            break;
        }
    }
    if (index < 0)
        return;

    for (int i = index; i < map->Size-1; i++) {
        map->Items[i] = map->Items[i+1];
    }
    
    map->Size -= 1;
}


Hashmap *NewHashmap() { 
    Hashmap *map = GC_MALLOC(sizeof(Hashmap));
    map->Size = 0;
    map->Items = GC_MALLOC(0);

    map->Set = Hashmap_Set;
    map->Get = Hashmap_Get;
    map->Delete = Hashmap_Delete;

    return map;
}

#endif
