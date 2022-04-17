#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Element{
    int x;
    struct Element *suivant;
}element;

element* initListe(){
    element *e=NULL;
    return  e;
}

void insererUnElem(element **list,element *e){
    if(*list==NULL)
        *list=e;
    else{
        element *l=*list;
        while(l->suivant !=NULL){
            l=l->suivant;
        }
        l->suivant=e;
    }
}
void afficherListe(element *list){
    while(list!=NULL){
        printf("%d\t",list->x);
        list=list->suivant;
    }
    printf("\n");
}
float moyList(element *list){
    float s=0;
    int i=0;
    while(list!=NULL){
        printf("%d",s);
        s=s+list->x;
        list=list->suivant;
        i++;
    }
    if(i==0){
        return 0;
    }
    return s/i;
}
void supPremier(element **list){
    if(*list!=NULL){
    element *del=*list;
    *list=(*list)->suivant;
    free(del);}
}
void supDernier(element **list){
    if(*list!=NULL){
        element *l=*list;
        while(l->suivant->suivant!=NULL){
            l=l->suivant;
        }
        element *del=l->suivant;
        l->suivant=NULL;
        free(del);
    }
    
}

element* concatList(element *a,element *b){
    element *newList=a;
    while(a->suivant!=NULL)
        a=a->suivant;
    a->suivant=b;
    return newList;
}
element* carreList(element *list){
    if(list !=NULL){
        element *l=initListe();
        element *e;
        while(list!=NULL){
            e=(element*)malloc(sizeof(element));
            e->x=list->x*list->x;
            e->suivant=NULL;
            insererUnElem(&l,e);
            list=list->suivant;
        }
         return l;
    }
    return NULL;
}
void triListe(element **list){
    if(*list!=NULL){
        bool test=true;
        int tmp;
        element *q=(*list);
        element *l=*list;
        afficherListe(l);
        while(l->suivant!=NULL){
            if(l->x > l->suivant->x){
                tmp=l->suivant->x;
                l->suivant->x=l->x;
                l->x=tmp;
                l=q;
            }
            if(l->x <= l->suivant->x){              
                l=l->suivant;
            }
        }
        
    }
}
int main(int argc, char const *argv[])
{
    element *list;
    // list = initListe();
    element *e;
    e=(element*)malloc(sizeof(element));
    e->x=1;
    e->suivant=NULL;
    insererUnElem(&list,e);
    e=(element*)malloc(sizeof(element));
    e->x=0;
    e->suivant=NULL;
    insererUnElem(&list,e);
    e=(element*)malloc(sizeof(element));
    e->x=5;
    e->suivant=NULL;
    insererUnElem(&list,e);
    printf("Moyenne : %f\n",moyList(list));
    printf("liste a\t");

    afficherListe(list);
    supPremier(&list);
    afficherListe(list);
    supDernier(&list);
    afficherListe(list);
    //______________________
    element *listb=initListe();
    e=(element*)malloc(sizeof(element));
    e->x=1;
    e->suivant=NULL;
    insererUnElem(&listb,e);
    e=(element*)malloc(sizeof(element));
    e->x=3;
    e->suivant=NULL;
    insererUnElem(&listb,e);
    e=(element*)malloc(sizeof(element));
    e->x=2;
    e->suivant=NULL;
    insererUnElem(&listb,e);
    e=(element*)malloc(sizeof(element));
    e->x=0;
    e->suivant=NULL;
    insererUnElem(&listb,e);
    printf("liste b\t");
    afficherListe(listb);
    // printf("concat deux liste\t");
    // element *newList=concatList(list,listb);
    // afficherListe(newList);
    //__________________________

    // printf("deux lise concat carree ");
    // afficherListe(carreList(newList));

    printf("tri ");
    triListe(&listb);
    afficherListe(listb);
    system("pause");
    return 0;
}

