#include <stdio.h>
#include <stdlib.h>
void main(){
    int puis,i;
    double x,res;
    
    printf("donner un double");
    scanf("%lf",&x);
    printf("donner la puissance");
    scanf("%d",&puis);
    res=x;
    i=puis;
    while(i>1)
    {
        res=res*x;
        i--;
    }
    printf("%.3f puissance %d = %.3f",x,puis,res);
    system("pause");
}