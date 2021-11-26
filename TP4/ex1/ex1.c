#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(){
    int n; 
    char jour[10];
    do
    {
        printf("Donner un numero du jour : ");
        scanf("%d",&n);
    } while (n<1 || n>7);
    
    switch (n)
    {
    case 1: strcpy(jour,"Lundi"); break;
    case 2 :strcpy(jour,"Mardi"); break;
    case 3 :strcpy(jour,"Mercredi"); break;
    case 4 :strcpy(jour,"Jeudi"); break;
    case 5 :strcpy(jour,"Vendredi"); break;
    case 6 :strcpy(jour,"Samedi"); break;
    case 7 :strcpy(jour,"Dimanche"); break;
    }
    printf("%s \n",jour);
    system("pause");
}