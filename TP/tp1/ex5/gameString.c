#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main(){
    char NJoueur1[4], NJoueur2[4];
    int nj1,nj2,k=1,len;
    do{
        printf("Donner un entier de 4 chiffre : ");
        scanf("%d",&nj1);
        sprintf(NJoueur1,"%d",nj1);
        len=strlen(NJoueur1);
        printf("J1 %s \n",NJoueur1);
    }while(len!=4);
    system("clear");
    do{
        printf("Essai numero %d \n Donner un entier de 4 chiffre : ",k);
        scanf("%d",&nj2);
        sprintf(NJoueur2,"%d",nj2);
        len=strlen(NJoueur2);
        if(len==4){
            for(int i=0;i<4;i++){
                NJoueur2[i]==NJoueur1[i]?printf("%c",NJoueur1[i]):printf("*");
            }
            printf("\n");
        }
    }while(k<6 && nj1!=nj2);
    nj1==nj2?printf("Gagne"):printf("Perdu!\n Le numero correcte est %d",nj1);
}