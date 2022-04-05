#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node{
    Node *previous;
    int x;
    Node *next;
};
Node* createNode(int x){
    Node *n=(Node*)malloc(sizeof(Node));
    n->next=NULL;
    n->previous=NULL;
    n->x=x;
    return n;
}
void afficher(Node *list){
        while(list!=NULL){
            printf("%d\n",list->x);
            list=list->next;
        }
}
void insererDebut(Node **list,Node *c){
    
    
    if(*list ==NULL){
        *list=c;
    }else{
        c->next=(*list);
        (*list)->previous=c;
    }
}
void insererFin(Node **list,Node *c){
    if(*list!=NULL){
        Node *l = *list;
        l->next=c;
        c->previous=l; 
        c->next=NULL;
    }
    if(*list==NULL){
        *list = c;
    }
}
void inserer(Node **list,Node *c){
    if(*list!=NULL){
        Node *l = *list;
        while(l->next !=NULL && l->x < c->x){
            l=l->next;
        }
        if(l->previous==NULL && l->x > c->x){
            insererDebut(&l,c);
        }else
        if(l->next==NULL && l->x < c->x){
            insererFin(&l,c);
        }else
        {
            c->next=l;
            c->previous=l->previous;
            l->previous->next=c;
            l->previous=c;
        }
        
    }
    if(*list==NULL){
        *list = c;
    }
}
void supprimerDeb(Node **list){
    if((*list)!=NULL){
        Node *c=*list;
        *list=(*list)->next;
        (*list)->previous=NULL;
        free(c);
    }
}
void supprimer(Node **list,int i){
    if((*list)!=NULL){
        if(i==1){
            supprimerDeb(list);
        }else{
            Node *l=*list;
            for (int j = 2; j < i; j++)
            {
                l=l->next;
            }
            Node *c=l->next;
            l->next=c->next;
            l->next->previous=l;
        }
    }
}
int main()
{
    Node *list = NULL;
    Node *n;
    n=createNode(1);
    inserer(&list,n);
    n=createNode(4);
    inserer(&list,n);
    n=createNode(5);
    inserer(&list,n);
    n=createNode(3);
    inserer(&list,n);
    supprimer(&list,2);
    afficher(list);
    system("pause");
    return 0;
}
