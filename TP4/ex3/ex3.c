#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(){
    char ch[10];

    do
    {
        printf("Donner un chaine : ");
        gets(ch);
    } while (ch==NULL);
    
    for (int i = 0; i < strlen(ch); i++)
    {
        if(ch[i]>='a' && ch[i]<='z')
            ch[i]=ch[i]-32;
        else if(ch[i]>='A' && ch[i]<='Z')
            ch[i]=ch[i]+32;
    }
    printf("%s",ch);
    
    system("pause");

}