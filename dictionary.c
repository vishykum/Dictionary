#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

//Initializes all memory related to the dictionary
Dictionary* dictionary_init() {
    Dictionary *dict = (Dictionary*) malloc(sizeof(Dictionary));
    dict->size = 0;
    dict->capacity = 10;
    dict->keys__ = malloc(dict->capacity * sizeof(void*));
    dict->values__ = malloc(dict->capacity * sizeof(void*));

    return dict;
}

//Add Element to Dictionary
void dictionary_add(Dictionary *dict, Element element) {

    if (dict->capacity <= dict->size) {
        dict->capacity *= 2;
        dict->keys__ = realloc(dict, (dict->capacity)*sizeof(void*));
        dict->values__ = realloc(dict, (dict->capacity)*sizeof(void*));
    }

    dict->keys__[dict->size] = element.key;
    dict->values__[dict->size] = element.value;
    dict->size++;
}

/* Function used to get an element given the value of the key.
*  If the element is not in the dictionary, an element with NULL pointers is returned
*/

//Change the type from int in the condition into whatever type your key is
Element dictionary_get(Dictionary *dict, void* key) {

    for(int i = 0; i < dict->size; i++) {
        int condition = ((int)key == (int)(dict->keys__[i])); //Change type in this line

        if (condition) {
            Element e;
            e.key = dict->keys__[i];
            e.value = dict->values__[i];

            return e;
        }
    }

    Element e;
    e.key = NULL;
    e.value = NULL;

    return e; 
}


/* Function used to remove and return an element given the value of the key.
*  If the element is not in the dictionary, an element with NULL pointers is returned
*/

//Change the type from int in the condition into whatever type your key is
Element dictionary_remove(Dictionary *dict, void *key) {

    if (dict->size <= (int)(dict->capacity/2)) {
        dict->capacity /= 3;
        dict->keys__ = realloc(dict->keys__, (dict->capacity*sizeof(void*)));
        dict->values__ = realloc(dict->values__, (dict->capacity*sizeof(void*)));
    }

    Element e;
    e.key = NULL;
    e.value = NULL;

    if (dict->size == 0) return e;

    void **temp_keys = malloc((dict->capacity) * sizeof(void*));
    void **temp_values = malloc((dict->capacity) * sizeof(void*));

    int index = 0;
    for(int i = 0; i < dict->size; i++) {
        int condition = ((int)(key) == (int)(dict->keys__[i])); //Change type in this line
        if (condition) {
            e.key = dict->keys__[i];
            e.value = dict->values__[i];
            continue;
        }

        temp_keys[index] = dict->keys__[i];
        temp_values[index] = dict->values__[i];
        index++;
    }

    free(dict->keys__);
    free(dict->values__);

    dict->keys__ = temp_keys;
    dict->values__ = temp_values;

    dict->size--;

    return e;
}

//Copies the keys list into void **keys and returns the size of the keys list
//keys is a dynamic array of void* of size dict->size
int dictionary_keys(Dictionary *dict, void **keys) {
    for(int i = 0; i < dict->size; i++) {
        keys[i] = dict->keys__[i];
    }

    return dict->size;
}

/* Function used to sort a dictionary by key if onKey != 0 and value if onKey == 0.
*  Ascending if reverse == 0 and Descending if reverse == 1
*/

//Change the type from int in the condition into whatever type your key is
void dictionary_sort(Dictionary *dict, int onKey, int reverse) {
    if (dict->size <= 1) return;

    void **array;

    if (onKey) array = dict->keys__;
    else array = dict->values__;

    void **temp_keys = malloc(sizeof(void*)*dict->capacity);
    void **temp_values = malloc(sizeof(void*)*dict->capacity);

    for(int i = 0; i < dict->size; i++) {
        int index = i;
        for(int j = i; j < dict->size; j++) {
            int condition = (reverse) ? (int)(array[index]) < (int)(array[j]) : (int)(array[index]) > (int)(array[j]); //Change type in this line

            if (condition) {
                index = j;
            }
        }

        void *temp = dict->keys__[index];
        dict->keys__[index] = dict->keys__[i];
        dict->keys__[i] = temp;

        temp = dict->values__[index];
        dict->values__[index] = dict->values__[i];
        dict->values__[i] = temp;
    }
}

//Deallocates dictionary memeory allocated from the heap
void dictionary_free(Dictionary *dict) {
    free(dict->keys__);
    free(dict->values__);
    free(dict);
}



