#include <stdio.h>
#include <stdlib.h>
#include "pile.c"


void copier(Pile **p1, Pile **p2){
    Pile *temp=createPile();
    while(!empty(*p1)){
        if(last(*p1)%2==0){
            push(last(*p1),p2);
        }
        push(last(*p1),&temp);
        pop(p1);
        
    }
    while (!empty(temp))
    {
        push(last(temp),p1);
        pop(&temp);
    }
    
}

void diviser(Pile **p1, Pile **p2, Pile **p3){
    copier(p1,p2);
    while(!empty(*p1)){
        if(last(*p1)%2!=0){
            push(last(*p1),p3);
        }
        pop(p1);
    }
}
void déplacer(Pile **p1,Pile **p2,Pile **p3){
    
    diviser(p1,p2,p3);
    while(!empty(*p3)){
        push(last(*p3),p2);
        pop(p3);
    }
    
}
int main(int argc, char const *argv[])
{
    Pile *stack=createPile();
    Pile *p2 = createPile();
    Pile *p3 = createPile();
    push(4,&stack);
    push(3,&stack);
    déplacer(&stack,&p2,&p3);
    // printf("%d",p3->data);
    printf("%d",p2->data);
    printf("%d",p2->next->data);
    if(empty(stack))
        printf("p1 is empty");
    system("pause");
    return 0;
}
