#include <stdio.h>
#include <stdlib.h>
int indexOf(int *t,int n,int x){
    if(n<0)
        return n;
    if(*(t+n)==x)
        return n;
    return indexOf(t,n-1,x);
}
void supprimer(int *t,int *n, int x){
    int a = indexOf(t,*n-1,x);
    if(a>=0){
        for (int i = a; i < *n-1; i++)
        {
            *(t+i)=*(t+i+1);
        }
    *n=*n-1;
    supprimer(t,n,x);
    }
}
void main(){
    int *t,n,x;
    do
    {
        printf(" Donner la taille du tableau : ");
        scanf("%d",&n);
    } while ( n<=0);
    t=malloc(n*4);
    for (int i = 0; i < n; i++){
        printf("Entier N %d : ",i+1);
        scanf("%d",t+i);
    }
    printf("Donner x a suuprimer : ");
    scanf("%d",&x);
    supprimer(t,&n,x);
    t=realloc(t,n*4);
    for (int i = 0; i < n; i++)
    {
        printf("%d \t",*(t+i));
    }
    
    system("pause");
}