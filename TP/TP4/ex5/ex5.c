#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(){
    char TXT[201];
    do
    {
        printf("Donner un chaine : ");
        gets(TXT);
    } while (TXT==NULL);

    
    system("pause");
}