#include <stdio.h>
#include <stdlib.h>
void main(){
    int a;
    printf("entrer le nombre des lignes");
    scanf("%d",&a);
    for (int i = 1; i <= a; i++)
    {
        if(i==1)
            printf("*");
        else
            {
                for (int j = 0; j <i; j++)
                {
                    printf("*");
                }
                
            }
        printf("\n");
    }
    
    system("pause");
}