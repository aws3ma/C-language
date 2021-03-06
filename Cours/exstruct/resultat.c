#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct Notes{
    float ds,exam;
}note;

typedef struct Etudiants{
    char nom[10],prenom[10];
    note n;
    float moy;
}etudiant;

int saisie(){
    int n;
    do
    {
        printf("Donner nombre des etudiants : ");
        scanf("%d",&n);
    } while (n<0);
    fflush(stdin);
    return n;
}

note saisie_notes(){
    struct Notes no;
    printf("Donner note DS : ");
    scanf("%f",&no.ds);
    printf("Donner note Exam : ");
    scanf("%f",&no.exam);
    fflush(stdin);
    return no;
}

float calculer_moy(note no){
    return (no.ds+no.exam*2)/3;
}

etudiant nouveau_etudiant(){
    etudiant e;
    printf("\nDonner nom : ");
    gets(e.nom);
    printf("Donner prenom : ");
    gets(e.prenom);
    e.n=saisie_notes();
    e.moy=calculer_moy(e.n);
    return e;
}

void remplir(etudiant e[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("Etudiant numero %d",i+1);
        e[i]=nouveau_etudiant();
    }
}

void affichage(etudiant e[],int n){
    int nb=0;
    for (int i = 0; i < n; i++)
    {
        if(e[i].moy>=9.5){
            printf("Nom : %s \t Prenom : %s \t ds %f \t Exam : %f \t Moy : %f \n",e[i].nom,e[i].prenom,e[i].n.ds,e[i].n.exam,e[i].moy);
            nb++;
        }
        
    }
    printf("Le nombre des etudiants reussite est %d",nb);
}

void main(){
    etudiant e[30];
    int n=saisie();
    remplir(e,n);
    e[1].n.ds=1;
    affichage(e,n);
    system("pause");
}