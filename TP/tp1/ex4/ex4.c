#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void main(){
    int a;
    float epsilon,racine,reel,Un=1,Unplus,absofUnplus;
    printf("donner l'entier' x \n");
    scanf("%d",&a);
    printf("donner l'epsilon \n");
    scanf("%f",&epsilon);
    racine=sqrtf(a);
    printf("%f\n",racine);
    do
    {
        Unplus=0.5*(Un+a/Un);
        printf("Unplus %d\n",Unplus);
        absofUnplus=Unplus-Un;
        Un=Unplus;
        
        printf("absofunplus before if  %d\n",absofUnplus);
        if(absofUnplus<0)
            absofUnplus=-absofUnplus;
        printf("absofunplus %d\n",absofUnplus);
        reel=(float)absofUnplus/Un;
        printf("%f\n",reel);
    } while (absofUnplus/Un>epsilon);
    
    printf("racine carré de %d est %d\n",a,Unplus);
    system("pause");
}