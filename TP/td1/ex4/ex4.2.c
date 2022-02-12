#include<stdio.h>
#include<stdlib.h>
void main(){
    int a,b,c,max;
    printf("first int : ");
    scanf("%d",&a);
    printf("second int : ");
    scanf("%d",&b);
    printf("third int : ");
    scanf("%d",&c);
    max=a;
    if(b>max)
        max=b;
    if(c>max)
        max=c;
    printf("%d is the maximum",max);
    system("pause");
}