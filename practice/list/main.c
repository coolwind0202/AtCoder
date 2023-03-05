#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(void) {
    List* first = createList(5);
    printf("%d\n", first->value);

    add(first, 6);
    add(first, 8);
    add(first, 4);

    List* current = first;
    
    while (current->Next != NULL) {
        current = current->Next;
        printf("%d\n", current->value);
    }

    return 0;
}