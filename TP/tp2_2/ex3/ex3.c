#include <stdio.h>
#include <stdlib.h>

typedef struct List_circulaire
{
    struct List_circulaire *precedent;
    struct List_circulaire *suivant;
    int contenu;
} list;

list *insereList(int x, list *p)
{
    list *e = (list *)malloc(sizeof(list));
    e->contenu = x;

    if (p == NULL)
    {
        e->precedent = NULL;
        e->suivant = NULL;
        p = e;
    }
    else
    {
        e->precedent = p;
        if (p->precedent == NULL)
        {
            p->precedent = e;
        }
        if (p->suivant == NULL)
        {
            e->suivant = p;
            p->suivant = e;
        }
        else
        {
            e->suivant = p->suivant;
            p->suivant = e;
        }
        p = e;
    }
    return p;
}

list *effaceElemntList(list *p)
{
    list *prec = p->precedent;
    if (p->precedent == NULL && p->suivant == NULL)
    {
        free(p);
        return NULL;
    }

    else
    {
        prec->suivant = p->suivant;
        p->suivant->precedent = prec;
        free(p);
    }
    return prec;
}

// list *effaceElemntList(list *p,int x){
//     list* cur=p;

//     do{
//         if(cur->contenu==x){
//             list* prec=cur->precedent;
//             if(cur->precedent==NULL && cur->suivant==NULL)
//             {
//                 free(cur);
//                 return NULL;
//             }

//             else{
//                 prec->suivant=cur->suivant;
//                 cur->suivant->precedent=prec;
//                 cur->precedent=NULL;
//                 cur->suivant=NULL;
//                 free(cur);
//             }
//             return p;
//         }
//         cur=cur->suivant;
//     }while(cur!=p);

// }

int compte(list *p)
{
    int x = 0;
    list *cur = p;
    do
    {
        x++;
        cur = cur->suivant;
    } while (cur != p);
    return x;
}

void inverse(list **p)
{
    if (p != NULL)
    {
        list *perv = *p;
        list *cur = (*p)->suivant;
        list *temp = *p;
        perv->precedent = perv;
        perv->suivant = perv;
        while (cur != *p)
        {
            temp = cur->suivant;
            cur->suivant = perv;
            perv->precedent = cur;
            (*p)->suivant = cur;
            cur->precedent = *p;
            perv = cur;
            cur = temp;
        }
        *p = perv;
    }
}

void afficher(list *p)
{
    list *cur = p;
    do
    {
        printf("%d\t", cur->contenu);
        cur = cur->suivant;
    } while (cur != p);
}

void diviseListe(list *p, list **l1, list **l2)
{
    list *slow_ptr = p;
    list *fast_ptr = p;

    if (p == NULL)
        return;

    /* If there are odd nodes in the circular list then
       fast_ptr->suivant becomes p and for even nodes
       fast_ptr->suivant->suivant becomes p */
    while (fast_ptr->suivant != p && fast_ptr->suivant->suivant != p)
    {
        fast_ptr = fast_ptr->suivant->suivant;
        slow_ptr = slow_ptr->suivant;
    }

    /* If there are even elements in list then move fast_ptr */
    if (fast_ptr->suivant->suivant == p)
        fast_ptr = fast_ptr->suivant;

    /* Set the p pointer of first half */
    *l1 = p;

    /* Set the p pointer of second half */
    if (p->suivant != p)
        *l2 = slow_ptr->suivant;

    /* Make second half circular */
    fast_ptr->suivant = slow_ptr->suivant;

    /* Make first half circular */
    slow_ptr->suivant = p;
}

int main(int argc, char const *argv[])
{
    list *p = NULL;
    list *l2 = NULL;
    list *l1 = NULL;
    p = insereList(1, p);
    p = insereList(2, p);
    p = insereList(3, p);
    p = insereList(4, p);
    p = insereList(5, p);
    afficher(p);
    printf("\nnombre : %d", compte(p));
    printf("\n");
    p = effaceElemntList(p);
    afficher(p);
    printf("\ninverse: ");
    inverse(&p);
    afficher(p);
    diviseListe(p, &l1, &l2);
    printf("\ns: ");
    afficher(l1);
    printf("\ns: ");
    afficher(l2);
}