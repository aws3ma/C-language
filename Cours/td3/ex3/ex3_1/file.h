#include <stdbool.h>
typedef struct Cellule
{
    int elem;
    struct Cellule *succ;
} File;
File *F;
File* creer();
bool vide();
int premier();
void enfiler(int x);
void defiler();