#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void *key;
    void *value;
} Element;

typedef struct {
    void ** keys__;
    void ** values__;
    unsigned int size;
    unsigned int capacity;
} Dictionary;

//Initializes all memory related to the dictionary
Dictionary* dictionary_init();

//Add Element to Dictionary
void dictionary_add(Dictionary*, Element);

/* Function used to get an element given the value of the key.
*  If the element is not in the dictionary, an element with NULL pointers is returned
*/

//Change the type from int in the condition into whatever type your key is
Element dictionary_get(Dictionary*, void*);

/* Function used to remove and return an element given the value of the key.
*  If the element is not in the dictionary, an element with NULL pointers is returned
*/

//Change the type from int in the condition into whatever type your key is
Element dictionary_remove(Dictionary*, void*);

//Copies the keys list into void **keys and returns the size of the keys list
//keys is a dynamic array of void* of size dict->size
int dictionary_keys(Dictionary *, void**);

/* Function used to sort a dictionary by key if onKey != 0 and value if onKey == 0.
*  Ascending if reverse == 0 and Descending if reverse == 1
*/

//Change the type from int in the condition into whatever type your key is
void dictionary_sort(Dictionary *, int, int);

//Deallocates dictionary memeory allocated from the heap
void dictionary_free(Dictionary *);

#endif