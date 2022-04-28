#include <stdio.h>
#include <stdlib.h>
#include "pile.c"

void diviser(Etudiant *E1, Etudiant **E2, Etudiant **E3)
{
    while (!empty(E1))
    {
        if (last(E1)->moyenne >= 10)
        {
            push(last(E1)->cin, last(E1)->moyenne, E2);
        }
        else
        {
            push(last(E1)->cin, last(E1)->moyenne, E3);
        }
        pop(&E1);
    }
}

Etudiant *trier(Etudiant *E1)
{

    Etudiant *min = createPile();
    push(0, 20, &min);
    Etudiant *temp = createPile();
    Etudiant *E2 = createPile();
    int length;
    int i;
    int minpos;

    while (!empty(E1))
    {
        i = 0;
        while (!empty(E1))
        {
            i++;
            if (last(E1)->moyenne <= min->moyenne)
            {
                min->moyenne = last(E1)->moyenne;
                min->cin = last(E1)->cin;
                minpos = i;
            }
            push(last(E1)->cin, last(E1)->moyenne, &temp);
            pop(&E1);
        }
        length = i;
        push(min->cin, min->moyenne, &E2);
        min->moyenne = 20;
        while (length > 0)
        {

            if (length != minpos)
            {
                push(last(temp)->cin, last(temp)->moyenne, &E1);
            }
            pop(&temp);
            length--;
        }
    }

    return E2;
}
int main(int argc, char const *argv[])
{
    Etudiant *E1 = createPile();
    Etudiant *E2 = createPile();
    Etudiant *E3 = createPile();
    push(0, 15, &E1);
    push(1, 13, &E1);
    push(2, 7, &E1);
    push(3, 13, &E1);
    push(4, 9, &E1);
    diviser(E1, &E2, &E3);
    printf("admis");
    while (!empty(E2))
    {
        printf("Cin : %d \t Moy : %f\n", last(E2)->cin, last(E2)->moyenne);
        pop(&E2);
    }
    printf("redoublent");
    while (!empty(E3))
    {
        printf("Cin : %d \t Moy : %f\n", last(E3)->cin, last(E3)->moyenne);
        pop(&E3);
    }
    // Etudiant *temp = createPile();
    // push(0, 5, &E1);
    // push(1, 3, &E1);
    // push(2, 7, &E1);
    // push(3, 3, &E1);
    // push(4, 9, &E1);
    // temp = trier(E1);
    // while (!empty(temp))
    // {
    //     printf("%f\t", last(temp)->moyenne);
    //     pop(&temp);
    // }
    system("pause");
    return 0;
}
