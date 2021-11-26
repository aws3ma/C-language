#include <stdio.h>
#include <stdlib.h>
void main(){
    //les variables des numero de chaque joueur
    int nj1,nj2;
    //les variables de chaque partie du numero de chaque jouer
    int premierValnj1,deuxiemeValnj1,troisiemeValnj1,quatriemeValnj1;
    int premierValnj2,deuxiemeValnj2,troisiemeValnj2,quatriemeValnj2;
    //compteur
    int i=0;
    //lecture du numero du joueur 1
    do{
        printf("entre un entier de 4 chiffre \n");
        scanf("%d",&nj1);
    }while(nj1<1000 || nj1>9999);
    //vider la console
    system("cls");
    //premier chiffre du nombre de joueur 1
    premierValnj1=nj1%10;
    //deuxieme chiffre du nombre de joueur 1
    deuxiemeValnj1=nj1%100/10;
    //troisieme chiffre du nombre de joueur 1
    troisiemeValnj1=nj1%1000/100;
    //quatrieme chiffre du nombre de joueur 1
    quatriemeValnj1=nj1%10000/1000;
    //traitement pour verifier l'egalite entre le numero du joueur 1 et numero du joueur 2 chiffre par chiffre
    do{
        i++;
        //lecture la numero du joueur 2
        printf("essai numero %d \n donner un entier de 4 chiffre\n",i);
        scanf("%d",&nj2);
        //chaque chiffre du numero de joueur 2
        premierValnj2=nj2%10;
        deuxiemeValnj2=nj2%100/10;
        troisiemeValnj2=nj2%1000/100;
        quatriemeValnj2=nj2%10000/1000;
        //affichage des chiffres correct et des etoiles si incorrect
        quatriemeValnj2==quatriemeValnj1? printf("%d",quatriemeValnj2):printf("*");
        troisiemeValnj2==troisiemeValnj1? printf("%d",troisiemeValnj2):printf("*");
        deuxiemeValnj2==deuxiemeValnj1? printf("%d",deuxiemeValnj2):printf("*");
        premierValnj2==premierValnj1? printf("%d",premierValnj2):printf("*");
        printf("\n");
    }while(i<5 && nj1!=nj2);
    //afficher le resultat
    nj1==nj2? printf("gangne \n"): printf("perdu \n");
    system("pause");
}