#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(){
    int n,*NOTES,som=0,max=0,min=60,NOMBRE[7]={0};
    char m[7][7][8];
    do{printf("donner un entier : ");
    scanf("%d",&n);}while(n<20 || n>50);
    NOTES=malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        do{printf("Donner le note %d : ",i+1);
        scanf("%d",(NOTES+i));}while(*(NOTES+i)<0 || *(NOTES+i)>60);
        
    }
    for (int i = 0; i < n; i++)
    {
        som+=*(NOTES+i);
        if(*(NOTES+i)>max)
            max=*(NOTES+i);
        if(*(NOTES+i)<min)
            min=*(NOTES+i);
    }

    printf("La moyenne des eleves : %.2f \nLa note minimal : %d \nLa note maximal : %d",(float)som/n,min,max);
    for (int j = 0; j < n; j++)
    {
        *(NOTES+j)>=0 && *(NOTES+j)<=9?NOMBRE[0]++:*(NOTES+j)<=19?NOMBRE[1]++:*(NOTES+j)<=29?NOMBRE[2]++:*(NOTES+j)<=39?NOMBRE[3]++:*(NOTES+j)<=49?NOMBRE[4]++:*(NOTES+j)<=59?NOMBRE[5]++:NOMBRE[6]++;
    }

    for (int i = 0; i < 7; i++)
    {
        printf("%d \t",NOMBRE[i]);
    }
    max=0;
    for (int j=0; j < 7; j++)
    {
        if(NOMBRE[j]>max)
            max=NOMBRE[j];
    }

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j <=max; j++)
        {
            if(NOMBRE[i]==0)
                strcpy(m[i][j],"       ");
            else{
                if(j<=NOMBRE[i])
                    strcpy(m[i][j],"#######");
                else
                    strcpy(m[i][j],"       ");
            }
            
        }
    }
    printf("Total eleve : %d\n",n);
    int i=max;
        for (int j = max; j >0; j--)
        {
            printf("%d > ",i);
            for (int k = 0; k <7; k++){
                
                printf("%s ",m[k][j]);
            }
            i--;
            printf("\n");
        }
    printf("   +-------+-------+-------+-------+-------+-------+-------+\n");
    printf("      0-9    10-19   20-29   30-39   40-49    50-59    60 \n");
    system("pause");
}