#include <stdio.h>
#include <stdlib.h>
void remplir(int *t, int n){
    for(int i=0;i<n;i++){
        printf("Entier numero %d : ",i);
        scanf("%d",t+i);
        printf("\n");
    }
}
void affiche(int *t,int n){
    
    for (int i = 0; i < n; i++)
    {
        printf("%d \t",t[i]);
    }
    printf("\n");
    
}
int somme(int *t, int n){
    int s=0;
    for (int i = 0; i < n; i++)
    {
        s+=*(t+i);
    }
    return s;
}
void minmax(int *t, int *max, int *min, int n){
    *max=*(t);
    *min=*(t);
    for (int i = 1; i < n; i++)
    {
        if(*(t+i)>*max)
            *max=*(t+i);
        if(*(t+i)<*min)
            *min=*(t+i);
    }
    
}
int premier(int x){
    for (int i = 2; i < x; i++)
    {
        if(x%i==0)
            return 0;
    }
    
    return 1;
    
}
int NbrP(int *t, int n){
    int s=0;
    for (int i = 0; i < n; i++)
    {
        if(premier(*(t+i))==1)
            s++;
    }
    
}
void supprimer (int *t, int *n,int x){
    for (int i = 0; i < *n; i++)
    {
        if(*(t+i)==x){
            int j;
            for (j = i; j < *n-1; j++)
            {
                t[j]=t[j+1];
            }
            //free(t+*n);
            *n=*(n)-1;
        }

    }
}
void main(){
    int n; int *F;
    printf("donner la taille du tableau : ");
    scanf("%d",&n);
    F=malloc(n*4);
    remplir(F,n);
    printf("La somme des elements du tableau : %d \n",somme(F,n));
    for (int i = 0; i < n; i++)
    {
        if(premier(*(F+i))==1){
            
            supprimer(F,&n,*(F+i));
        }
    }
    affiche(F,n);
    int min,max;
    minmax(F,&max,&min,n);
    printf("Max = %d \n Min = %d \n",max,min);

    system("pause");
}