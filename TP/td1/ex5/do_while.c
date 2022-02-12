#include<stdio.h>
#include<stdlib.h>
void main(){
    int i,n,som;
    som=0;
    i=1;
    do{
        printf("donner l'entier numero %d : ",i);
        scanf("%d",&n);
        som+=n;
        i++;
    }while (i<=4);
    printf("le somme de 4 entier est : %d \n",som);
    system("pause");
}