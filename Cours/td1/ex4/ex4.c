#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int j,m,a;
}date;

typedef struct {
    char titre[30];
    char auteur[15];
    date d;
}livre;

int saisie(livre books[]){
    int n;
    printf("Nombre des livres : ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Livre numero %d :",i+1);
        printf("Titre :");
        scanf("%s",&books[i].titre);
        printf("Auteur :");
        scanf("%s",&books[i].auteur);
        printf("Date d'edition :");
        printf("Jour :");
        scanf("%s",&books[i].d.j);
        printf("Mois :");
        scanf("%s",&books[i].d.m);
        printf("Année :");
        scanf("%s",&books[i].d.a);
    }
}

int nombre(char auteur[], livre books[], int n){
    int s=0;
    int len =strlen(auteur);
    for (int i = 0; i < n; i++)
    {
        if(strlen(books[i].auteur)==len){
            int j;
            for(j=0;j < len && auteur[j]==books[i].auteur[j];j++)
            {
                continue;
            }
            if(j==len)
                s++;
        }
    }
    return s;
}

int main(int argc, char const *argv[])
{
    int n;
    char auteur[15];
    livre books[100];
    // strcpy(books[0].auteur,"ous");
    // strcpy(books[0].titre,"hello");
    // books[0].d.a=2020;
    // books[0].d.m=1;
    // books[0].d.j=2;
    // strcpy(books[1].auteur,"ous");
    // strcpy(books[1].titre,"hello");
    // books[1].d.a=2020;
    // books[1].d.m=1;
    // books[1].d.j=2;
    n=saisie(books);
    n=2;
    fflush(stdin);
    // strcpy(auteur,"ous");
    gets(auteur);
    printf("le nombre des livres de l'auteur %s est : %d",auteur,nombre(auteur,books,n));
    system("pause");
    return 0;
}
