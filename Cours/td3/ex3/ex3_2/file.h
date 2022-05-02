#include <stdbool.h>
struct Cellule
{
    int elem;
    struct Cellule *succ;
};
typedef struct
{
    struct Cellule *tete;
    struct Cellule *queue;
} File;
File *F;
File *creer();
bool vide();
int premier();
void enfiler(int x);
void defiler();