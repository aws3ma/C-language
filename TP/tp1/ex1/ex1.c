#include <stdio.h>
#include <stdlib.h>
void main(){
    int n,nbEntierPositive=0,sommeValNegative=0,SommeValeurPositive=0,x;
    printf("donner un nombre : \n");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        printf("donner le valeur N° %d : \n",i);
        scanf("%d",&x);
        if(x>=0)
        {
            nbEntierPositive++;
            SommeValeurPositive+=x;
        }else{
            sommeValNegative+=x;
        }
    }
    printf("Le nombre des valuers : %d \n Le nombre des entier positive : %d \n Le nombre des valuers negative : %d \n La somme des entier positive : %d \n La somme des entier negative : %d \n",n,nbEntierPositive,n-nbEntierPositive,SommeValeurPositive,sommeValNegative);
    system("pause");
}