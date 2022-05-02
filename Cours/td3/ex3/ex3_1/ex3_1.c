#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "file.h"
File *creer()
{
    return NULL;
}
bool vide()
{
    return F == NULL;
}
int premier()
{
    if (!vide())
    {
        File *temp=F;
        while (temp->succ != NULL)
            temp = temp->succ;
        return temp->elem;
    }
    return -9999;
}
void enfiler(int x)
{
    File *f = (File *)malloc(sizeof(File));
    f->elem = x;
    f->succ = F;
    F = f;
}
void defiler()
{

    File *temp = F;

    if (!vide())
    {
        if (temp->succ == NULL)
        {
            free(temp);
            F=NULL;
        }

        else
        {
            while (temp->succ->succ != NULL)
            {
                temp = temp->succ;
            }
            if (temp->succ == NULL)
                free(temp);
            else
            {
                File *deleted = temp->succ;
                temp->succ = NULL;
                free(deleted);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    File *f = creer();
    enfiler(1);
    enfiler(2);
    enfiler(3);
    while(!vide()){
        printf("%d\t", premier());
        defiler();
    }
    system("pause");
    return 0;
}
