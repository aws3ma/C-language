#include <stdbool.h>
typedef struct Etu
{
    int cin;
    float moyenne;
    struct Etu *succ;
} Etudiant;
Etudiant *createPile();
bool empty(Etudiant *head);
Etudiant* last(Etudiant *head);
void push(int cin,float moy, Etudiant **head);
void pop(Etudiant **head);