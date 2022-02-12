#include<stdio.h>
#include<stdlib.h>
void main(){
    int a,b;
    printf("first int : ");
    scanf("%d",&a);
    printf("second int : ");
    scanf("%d",&b);
    a>b? printf("%d > %d",a,b):printf("%d > %d",b,a);
    system("pause");
}