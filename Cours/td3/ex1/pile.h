#include <stdbool.h>
typedef struct Pile
{
    int data;
    struct Pile *next;
} Pile;
Pile *createPile();
bool empty(Pile *head);
int last(Pile *head);
void push(int X, Pile **head);
void pop(Pile **head);