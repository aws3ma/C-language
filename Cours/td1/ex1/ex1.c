#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cin;
    float taille, poids;
    char genre;
}Personne;
Personne saisie(){
    Personne p;
    fflush(stdin);
    printf("cin : ");
    scanf("%d",&p.cin);
    printf("taille : ");
    scanf("%f",&p.taille);
    printf("poids : ");
    scanf("%f",&p.poids);
    fflush(stdin);
    printf("genre : ");
    scanf("%c",&p.genre);
    return p;
}
void afficher(Personne p){
    printf("Cin : %d \nTaille : %f \nPoids : %f \nGenre : %c\n",p.cin,p.taille,p.poids,p.genre);
}
void permuterInfos(Personne *p1, Personne *p2){
    Personne temp=*p1;
    *p1=*p2;
    *p2=temp;  
}
int main(int argc, char const *argv[])
{
    Personne p1=saisie();
    Personne p2=saisie();
    afficher(p1);
    afficher(p2);
    permuterInfos(&p1,&p2);
    afficher(p1);
    afficher(p2);
    system("pause");
    return 0;
}
