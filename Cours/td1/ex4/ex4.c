#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int m,a;
}date;

typedef struct {
    char titre[30];
    char auteur[15];
    date d;
}livre;

void saisie(livre books[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("Livre numero %d :",i+1);
        printf("Titre :");
        gets(books[i].titre);
        printf("Auteur :");
        gets(books[i].auteur);
        printf("Date d'edition :");
        printf("Mois :");
        scanf("%d",&books[i].d.m);
        printf("Annee :");
        scanf("%d",&books[i].d.a);
        fflush(stdin);
    }
}

int nombre(char auteur[], livre books[], int n){
    int s=0;
    for (int i = 0; i < n; i++)
    {
        if(strcmp(books[i].auteur,auteur)==0){
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
    printf("Nombre des livres : ");
    scanf("%d",&n);
    fflush(stdin);
    saisie(books,n);
    fflush(stdin);
    printf("nom de l'auteur : ");
    gets(auteur);
    printf("le nombre des livres de l'auteur %s est : %d \n",auteur,nombre(auteur,books,n));
    system("pause");
    return 0;
}
