#include <stdbool.h>
#include "pile.h"
Pile *createPile(){
    return NULL;
}
bool empty(Pile *head){
    return head==NULL;
}
int last(Pile *head){
    return head->data;
}
void push(int X, Pile **head){
    Pile *temp = (Pile*)malloc(sizeof(Pile));
    temp->data=X;
    temp->next=(*head);
    *head=temp;
}
void pop(Pile **head){
    if(*head!=NULL){
    Pile *temp = (Pile*)malloc(sizeof(Pile));
    temp=*head;
    *head=(*head)->next;
    free(temp);}
}