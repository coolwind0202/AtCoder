/***
 * 
 * 
 * Summary: List API written by C language.
 * 
 * 2023/02/27 coolwind0202
 * 
 * 
*/

#include <stdlib.h>

#include "list.h"

List* createList(int value) {
    List* first;
    first = (struct List *)malloc(sizeof (struct List));
    
    if (first == NULL) {
        return NULL;
    }

    first->value = value;
    first->Prev = NULL;
    first->Next = NULL;

    return first;
}

List* getFirst(List* list) {
    List* current = list;

    while (current->Prev != NULL) {
        current = current->Prev;
    }

    return current;
}

List* getLast(List* list) {
    List* current = list;

    while (current->Next != NULL) {
        current = current->Next;
    }

    return current;
}

List *getElement(List *list, unsigned int index) {
    List* first = getFirst(list);
    List* current = first;
    unsigned int i = 0;

    while (i <= index) {
        if (first->Next == NULL) {
            return NULL;
        }

        current = first->Next;
    }

    return current;
}

void add(List* list, int value) {
    List* last = getLast(list);
    List* newElement = createList(value);
    last->Next = newElement;
    newElement->Prev = last;
}

unsigned int getLength(List *list) {
    List* first = getFirst(list);
    List* current = first;

    int counter = 0;
    
    while (current->Next != NULL) {
        current = current->Next;
        counter++;
    }

    return counter;
}
