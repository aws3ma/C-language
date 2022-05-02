#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "file.h"
File *creer()
{
    F = (File *)malloc(sizeof(File));
    F->queue = NULL;
    F->tete = NULL;
    return F;
}
bool vide()
{
    return F->tete == NULL;
}
int premier()
{
    if (!vide())
        return F->tete->elem;
    return -9999;
}
void enfiler(int x)
{
    struct Cellule *c = (struct Cellule *)malloc(sizeof(struct Cellule));
    c->elem = x;
    c->succ = F->queue;
    F->queue = c;
    if (F->tete == NULL)
        F->tete = c;
}
void defiler()
{

    if (!vide())
    {

        if(F->queue==F->tete){
            free(F->queue);
            F->tete = NULL;
            F->queue=NULL;
        }else{
            struct Cellule *h=F->tete;
            struct Cellule *q=F->queue;
            while(q->succ!=h)
            {
                q=q->succ;
            }
            q->succ=NULL;
            free(h);
            F->tete=q;
        }
    }
}
int main(int argc, char const *argv[])
{

    F = creer();
    enfiler(1);
    enfiler(12);
    enfiler(13);
    enfiler(14);
    while(!vide())
    {
        printf("%d\t", premier());
        defiler();
    }
    system("pause");
    return 0;
}
