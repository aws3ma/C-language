#include <stdio.h>
#include <stdlib.h>
void main(){
    int moy=0,i=0,n;
    do{
        printf("donner l'entier numero %d : ",i);
        scanf("%d",&n);
        if(n!=-1){
            moy+=n;
            i++;
        }
    }
    while(n!=-1);
    printf("la moyenne de %d entiers est %d\n",i,moy/i);
    system("pause");
}