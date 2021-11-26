#include <stdio.h>
#include <stdlib.h>
void main(){
    int m,n,sommedesdiviseurM=1,sommedesdiviseurN=1;
    printf("donner la valeur m");
    scanf("%d",&m);
    printf("donner la valeur n");
    scanf("%d",&n);
    for (int i = 2; i < m; i++)
    {
        if(m%i==0)
            sommedesdiviseurM+=i;
    }
    
    if (sommedesdiviseurM==n) 
       printf ("%d et %d son amis \n",m,n);
    else
        printf ("%d et %d ne son pas amis \n",m,n);
    system("pause");
}