#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node{
    int x;
    Node *next;
};

void saisie(Node **list,int n){
    Node *temp;
    for (int i = 0; i < n; i++)
    {
        Node *no=(Node*)malloc(sizeof(Node));
        printf("entier %d :",i);
        scanf("%d",&no->x);
        if(*list==NULL){
            *list=no;
            temp=*list;
        }else{
            no->next=*list;
            temp->next=no;
            temp=no;
            
        }
    }
    
}
int compterNodes(Node *list){
    int i=0;
    Node *temp=list;
    if(list!=NULL)
    {
        i++;
        printf("%d\t",temp->x);
        temp=list->next;
    }
    while(temp!=list){
        i++;
        printf("%d\t",temp->x);
        temp=temp->next;
    }
    return i;
}
int main(int argc, char const *argv[])
{
    int n;
    Node *list=NULL;
    printf("saisie un entier");
    scanf("%d",&n);
    saisie(&list,n);
    int i=compterNodes(list);
    printf("\nTotal : %d",i);
    system("pause");
    return 0;
}
