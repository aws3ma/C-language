#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(){
    char voy[7]="aeiouy",ch[20];
    do
    {
        printf("Donner un chaine : ");
        gets(ch);
    } while (ch==NULL);

    for (int i = 0; i < strlen(ch); i++)
    {
        char *c=strchr(voy,ch[i]);
        
        if(c!=NULL)
            {   
                int position=c-voy;
                if(position==5)
                    position=-1;
                ch[i]=voy[position+1];
            }
            
    }
    printf("%s",ch);
    system("pause");
    
    
}