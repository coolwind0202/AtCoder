#ifndef _LIST_H_
#define _LIST_H_

typedef struct List {
    int value;
    struct List *Prev;
    struct List *Next;
} List;

List* createList(int value);

List* getFirst(List*);

List* getLast(List*);

List* getElement(List*, unsigned int);

void add(List*, int);

unsigned int getLength(List*);

#endif /* _LIST_H_*/