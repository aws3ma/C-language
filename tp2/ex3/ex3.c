#include <stdio.h>
#include <stdlib.h>
void main(){
    int n,coef = 1,i, j;
    int* *l;
    do{printf("donner un entier : ");
    scanf("%d",&n);}while(n<0 || n>13);
    l=malloc(n*sizeof(int*));
    
    for(i=0;i<n;i++){
        *(l+i)=malloc(n*sizeof(int));
    }
   
   for (i = 0; i < n; i++) {
      for (j = 0; j <= i; j++) {
         if (j == 0 || i == 0)
            coef = 1;
         else
            coef = coef * (i - j + 1) / j;
         *(*(l+i)+j)=coef;
      }
   }
   for (i = 0; i < n; i++) {
      for (j = 0; j <= i; j++) {
         printf("%d \t",*(*(l+i)+j));
      }
      printf("\n");
   }

    system("pause");
}