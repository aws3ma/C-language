#include <stdio.h>
#include <stdlib.h>
int saisie(){
    int n;
    printf("donner n");
    scanf("%d",&n);
    fflush(stdin);
    return n;
}
void remplir(char tab[],int n){
    for(int i=0;i<n;i++){
        do{
        printf("donner color %d",i);
        fflush(stdin);
        scanf("%c",&tab[i]);
        }while(tab[i]!='B' && tab[i]!='W' && tab[i]!='R');
    }
}
void tri(char t[],int n){
    int b=0,temp;
    for(int i=0;i<n;i++){
        if(b!=i){
            while(t[i]=='B' || t[i]=='R'){
                if(t[i]=='B'){
                    b++;
                    temp=t[i];
                    t[i]=t[b];
                    t[b]=temp;
                }else{
                    temp=t[i];
                    t[i]=t[n-1];
                    t[n-1]=temp;
                    n--;
                }
            }
        }
    }
}
void affiche(char t[],int n){
    for(int i=0;i<n;i++){
        printf("%c\t",t[i]);
    }
}
int main()
{
    int n;
    char t[10];
    n=saisie();
    remplir(t,n);
    tri(t,n);
    affiche(t,n);
    system("pause");
    return 0;
}
