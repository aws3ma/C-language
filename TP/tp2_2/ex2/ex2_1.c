#include <stdio.h>
#include<stdlib.h>

typedef struct element{
    int x;
    struct element* sui;
}el;

typedef struct liste{
    el *p;
}list;

list* initlist(){
    list* l =(list*) malloc (sizeof(list));
    l->p=NULL;
    return l;
}

list* insere (list* l , int value){
    el *e=(el*) malloc (sizeof(el));
    e->x=value;
    e->sui=l->p;
    l->p=e;
    return l;
}

void test_suffixe(list *l1,list *l2){
    el* cur1=l1->p;
    el* cur2=l2->p;
    int x1=0;
    int x2=0;
    int test=1;
    while(cur1!=NULL){
        x1++;
        cur1=cur1->sui;
    }
    while(cur2!=NULL){
        x2++;
        cur2=cur2->sui;
    }
    if(x1>x2){
        test =0;
        printf("La liste L1 est plus grande");
    }
    if(x1==x2){
        cur1=l1->p;
        cur2=l2->p;
        while(cur1!=NULL){
            if(cur1->x!=cur2->x){
                printf("L1 n'est pas un suffixe");
                test=0;
                break;
            }
            cur2=cur2->sui;
            cur1=cur1->sui;
        }
    }
    if(x1<x2){
        cur1=l1->p;
        cur2=l2->p;
        for(int i=0;i<=(x2-x1-1);i++){
            cur2=cur2->sui;
        }
        while (cur1!=NULL){
            if(cur1->x!=cur2->x){
                printf("L1 n'est pas un suffixe");
                test=0;
                break;
            }
            cur2=cur2->sui;
            cur1=cur1->sui;
        }
    }
    if(test==1){
        printf("Suffixe");
    }  
}
void affiche(list* l){
    el *e=l->p;
    while(e!=NULL){
        printf("%d",e->x);
        e=e->sui;
    }
}

void main(){
    list* l1=initlist();
    list* l2=initlist();

    l2=insere(l2,4);
    l2=insere(l2,2);
    l2=insere(l2,9);
    l2=insere(l2,8);
    l2=insere(l2,6);

    l1=insere(l1,4);
    l1=insere(l1,2);

    affiche(l1);
    printf("\n  \n");
    affiche(l2);
    printf("\n  \n");
    test_suffixe(l1,l2);

}
