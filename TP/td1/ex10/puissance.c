#include <stdio.h>
#include <stdlib.h>
void main(){
    int puis;
    double x,res;
    
    printf("donner un double");
    scanf("%lf",&x);
    printf("donner la puissance");
    scanf("%d",&puis);
    res=x;
    for (int i = 1; i < puis; i++)
    {
        res=res*x;
    }
    printf("%f",res);
    system("pause");
}