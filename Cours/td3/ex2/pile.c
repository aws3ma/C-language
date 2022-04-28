#include <stdbool.h>
#include "pile.h"
Etudiant *createPile(){
    return NULL;
}
bool empty(Etudiant *head){
    return head==NULL;
}
Etudiant *last(Etudiant *head){
    return head;
}
void push(int cin,float moy, Etudiant **head){
    Etudiant *temp = (Etudiant*)malloc(sizeof(Etudiant));
    temp->moyenne=moy;
    temp->cin=cin;
    temp->succ=(*head);
    *head=temp;
}
void pop(Etudiant **head){
    if(*head!=NULL){
    Etudiant *temp = (Etudiant*)malloc(sizeof(Etudiant));
    temp=*head;
    *head=(*head)->succ;
    free(temp);}
}