#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(){
    char m[4][4][4];
    for(int i=0;i<4;i++){
        for (int j = 0; j < 4 ;j++)
        {
            strcpy(m[i][j],"##");
        }
        
        
        
    }
    for(int i=0;i<4;i++){
        for (int j = 0; j < 4; j++)
        {
            printf("%s",m[i][j]);
        }
        printf("\n");
    }
    system("pause");
}