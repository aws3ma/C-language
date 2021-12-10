#include <stdio.h>
#include <stdlib.h>
void main(){
    int t[100],n=0,a=0,hexa=0,puiss;
    while (a!=-1)
    {
        do{printf("element %d",n);
        scanf("%d",&a);}while(a!=1 && a!=0 && a!=-1);
        if(a!=-1){
            t[n]=a;
            n++;
        }
    }
    for (int i = n-1; i >=0; i--)
    {
        puiss=1;
        for (int j = 0; j <= n-i-2; j++)
        {
            puiss=puiss*2;
        }
        hexa=hexa+(t[i]*puiss);
    }
    printf("hexa %d",hexa);
    system("pause");
}