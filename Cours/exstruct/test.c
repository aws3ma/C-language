#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct note 
{
    float ds,examen;
}n;
typedef struct etudiant
{
    char nom[10],prenom[10];
    n x;
}e;
void saisie_note(n *x){
    printf("donner la note du ds  : ");
    scanf("%f",&x->ds);
    printf("donner la note d'examen : ");
    scanf("%f",&x->examen);
}
void saisie_etudiant(e *y){
    printf("donner le nom : ");
    scanf("%s",&y->nom);
    printf("donner le prenom : ");
    scanf("%s",&y->prenom);
    fflush(stdin);
    saisie_note(&y->x);
}
void remplir(e t[],int n){
    for (int i=0;i<n;i++)
        saisie_etudiant(&t[i]);
    
}
void affiche_note(n x){
    printf("la note ds est : %f \n",x.ds);
    printf("la note d'examen est : %f \n",x.examen);
}
void affiche_etudiant(e t[],int n ){
    for (int i=0;i<n;i++){
        printf("nom : %s \n",t[i].nom);
        printf("prenom : %s \n",t[i].prenom);
        affiche_note(t[i].x);
    }
}
void main(){
    int n ;
    e t[50];
    printf("donner la dimension du structure : ");
    scanf("%d",&n);
    remplir(t,n);
    affiche_etudiant(t,n);
    system("pause");
}