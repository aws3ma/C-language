#include <stdio.h>
#include <stdlib.h>
void main(){
    int t[10],n,occ=0,occ2=0,x,inter;
    do
    {
        printf("donner n \n");
        scanf("%d",&n);
    } while (n<0 && n>9);

    for (int i = 0; i < n; i++)
    {
        printf("donner l'entier numero %d : ",i);
        scanf("%d",&t[i]);
    }
    for(int i=0;i<n;i++){
        occ=0;
        for(int j=0;j<n;j++){
            
            if(t[i]==t[j]){
                occ++;
            }
        }
        if(occ>occ2){
            occ2=occ;
            x=t[i];
        }
    }
    printf("l'entier est %d \n nb occurance = %d\n",x,occ2);
    occ=0;
    while(t[occ]!=x)
        occ;
    for (occ+=1; occ < n; occ++)
    {
        if(t[occ]==x){
            int a;
            for(int i=occ;i<n-1;i++){
                t[i]=t[i+1];
            }
            t[n--]=x;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d \t",t[i]);
    }
    for (int i = 0,j=n-1; i < n/2; i++,j--)
    {
        inter=t[i];
        t[i]=t[j];
        t[j]=inter;
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d \t",t[i]);
    }
    
    
    system("pause");
}