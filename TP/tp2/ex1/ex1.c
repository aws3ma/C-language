#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void main(){
    int m,n,a=0;
    int t1[6],t2[10];
    bool test;
    int i=0,j=0;
    do{
        printf("donner m");
        scanf("%d",&m);
    }while(m<3 || m>7);
    do{
        printf("donner n");
        scanf("%d",&n);
    }while(n<m || n%2!=0);
    printf("tab1\n");
    
    for(i=0;i<m;i++){
        do{printf ("donner entier numero %d : ",i);
            j=0;
            scanf("%d",&a);
            while(a!=t1[j] && j<i)
                j++;
            if(a!=t1[j] || j==i)
                t1[i]=a;
        }while(!a==t1[j]);
    }
        printf("tab2 \n");

    for(i=0;i<n;i++){
        do{printf ("donner entier numero %d : ",i);
            j=0;
            scanf("%d",&a);
            while(a!=t2[j] && j<i)
                j++;
            if(a!=t2[j] || j==i)
                t2[i]=a;
        }while(!a==t2[j]);
    }
    /*for (int i = 0,j=0,k,diff=0,diff1; i < n; i++)
    {
        diff1=diff;
        if(t2[i]==t1[j] && diff==diff1){
            j++;
            k++;
            diff=i-j;
        }
            
    }*/
    i=0;
    j=0;
        while(t2[i]!=t1[j] && i<n){
            i++;
            printf("while 1 %d\n",i);
        }
        while(t2[i]==t1[j] && i<=n && j<=m){
            i++;j++;
            printf("while 2 %d %d\n",i,j);
        }
    if(j==m){
        printf("existe \n");
    }else{
        printf("n'existe pas \n");
    }
    system("pause");

}