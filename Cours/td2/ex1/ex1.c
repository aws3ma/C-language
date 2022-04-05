#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Cellule Cellule;
struct Cellule
{
    float x;
    float y;
    char ch[10];
    Cellule *svt;
};

Cellule* nouvelleList(float x,float y,char ch[]){
    Cellule *c= (Cellule*)malloc(sizeof(Cellule));
    c->x=x;
    c->y=y;
    strcpy(c->ch,ch);
    c->svt=NULL;
    return c;
} 
void afficher(Cellule *list){
    Cellule *l=list;
    while (l!=NULL)
    {
        printf("%f %f %s\n",l->x,l->y,l->ch);
        l = l->svt;
    }
    
}
int tailleList(Cellule *c){
    int i=0;
    if(c!= NULL){
        i=1;
        while (c->svt!=NULL)
        {
            i++;
            c=c->svt;
        }
    }

    return i;
}
void insererElement(Cellule **list,Cellule *c,int i){
    if(list !=NULL){
        int len = tailleList(*list);
        if(i==1){
            c->svt=*list;
            *list=c;
        }else{
            Cellule *l=*list;
            if(i==len+1){
                while(l->svt!=NULL){
                    l=l->svt;}
                l->svt=c;
            }
            if(i>len+1){
                printf("index out of range\n");}
            if(i<len){
            for (int j = 2; j < i; j++)
            {
                l=l->svt;
            }
            c->svt=l->svt;
            l->svt=c;
            }
        }
        
    }
}
void supprimerElement(Cellule **list,int i){
    if(*list !=NULL){
        Cellule *l=*list;
        int len = tailleList(l);
        if(i==1){
            Cellule *c=l;
            l=l->svt;
            free(c);
            
        }
        if(i==len){
            while(l->svt->svt!=NULL){
                l=l->svt;
            }
            Cellule *c=l->svt;
            l->svt=NULL;
            free(c);
        }
        if(i<len && i>1)
        {
            for (int j = 2; j < i; j++)
            {
                l=l->svt;
            }
            Cellule *c=l->svt;
            l->svt=l->svt->svt;
            c->svt=NULL;
            free(c);
        }

        
    }
}
int main(int argc, char const *argv[])
{
    Cellule *list=nouvelleList(1,2,"point 1");
    Cellule *c;
    c=nouvelleList(4,3,"point 2");
    insererElement(&list,c,1);
    c=nouvelleList(4,3,"point 3");
    insererElement(&list,c,3);
    c=nouvelleList(4,3,"point 4");
    insererElement(&list,c,5);
    afficher(list);
    printf("\nDelete\n");
    supprimerElement(&list,3);
    afficher(list);
    // c=nouvelleList(4,3,"point 3");
    // insererElement(&list,&c,1);
    // c=nouvelleList(4,3,"point 4");
    // insererElement(&list,&c,3);
    system("pause"); 
    return 0;
}
