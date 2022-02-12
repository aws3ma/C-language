#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(){
    char ch[201];

    do
    {
        printf("donner une chaine de characteres : ");
        gets(ch);
    } while (ch==NULL);
    int l=strlen(ch);
    printf(" Longeur : %d \n",l);
    int s=0;
    for (int i = 0; i < l; i++)
    {
        if(ch[i]=='e')
            s++;
    }
    printf(" Occurance : %d \n",s);
    for (int i = l-1; i >= 0; i--)
    {
        printf("%c",ch[i]);
    }
    printf("\n");
    printf(" TXT non inversé : %s\n",ch);
    for (int i = l-1; i > l/2-1; i--)
    {
        char a=ch[i];
        ch[i]=ch[l-i-1];
        ch[l-i-1]=a;
    }
    
    printf(" TXT inversé : %s\n",ch);
    system("pause");

}