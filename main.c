#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

int main() {
    Dictionary *dict = dictionary_init();

    Element e;
    
    e.key = (void*) (3211420);
    e.value = (void*)("a");

    dictionary_add(dict, e);

    e.key = (void*) (99999999);
    e.value = (void*) ("b");

    dictionary_add(dict, e);

    e.key = (void*) (85121215);
    e.value = (void*) ("c");

    dictionary_add(dict, e);


    printf("dict = {");
    for(int i = 0; i < dict->size; i++) {
        printf("%d : %s", (int)dict->keys__[i], (char*)dict->values__[i]);

        if (i != dict->size-1) {
            printf(",  ");
        }
    }
    printf("}\n");

    dictionary_sort(dict, 1, 0);

    printf("dict = {");
    for(int i = 0; i < dict->size; i++) {
        printf("%d : %s", (int)dict->keys__[i], (char*)dict->values__[i]);

        if (i != dict->size-1) {
            printf(",  ");
        }
    }
    printf("}\n");


    dictionary_remove(dict, 3211420);
    Element get = dictionary_get(dict, 3211420);
    printf("%d, %s\n", (int)get.key, (char*)get.value);

    printf("dict = {");
    for(int i = 0; i < dict->size; i++) {
        printf("%d : %s", (int)dict->keys__[i], (char*)dict->values__[i]);

        if (i != dict->size-1) {
            printf(",  ");
        }
    }
    printf("}\n");


    void **keys;
    keys = malloc(sizeof(void*)*(dict->size));
    int size = dictionary_keys(dict, keys);

    for(int i = 0; i < size; i++) {
        printf("%d\t", (int)keys[i]);
    }
    printf("\n");
    free(keys);


    dictionary_free(dict);

    return 0;
}
