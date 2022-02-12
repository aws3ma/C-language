#include <stdio.h>
#include <stdlib.h>
void main(){
    float x,e=1,epsilon,powerofx=1,absoluofpower;
    int j=0,factoriel=1;
    printf("donner le réel x \n");
    scanf("%f",&x);
    printf("donner l'epsilon \n");
    scanf("%f",&epsilon);
    do
    {
        j++;
        for(int i=0;i<j;i++){
            powerofx*=x;  
        }
        for (int k = 1; k < j; k++)
            {
                factoriel*=k;
            }
        if(powerofx<0)
            absoluofpower=-powerofx;
        else
            absoluofpower=powerofx;
        e+=(powerofx/factoriel);
    }while(absoluofpower/factoriel>epsilon);
    printf("%f\n",e);
    system("pause");
}