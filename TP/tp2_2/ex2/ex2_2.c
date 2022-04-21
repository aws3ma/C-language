#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int x;
    struct element *sui;
    struct element *prec;
} el;

typedef struct liste
{
    el *p;
    el *d;
} list;

list *initlist()
{
    list *l = (list *)malloc(sizeof(list));
    l->p = NULL;
    l->d = NULL;
    return l;
}

list *insereDeb(list *l, int y)
{
    el *e = (el *)malloc(sizeof(el));
    e->x = y;
    e->prec = NULL;
    if (l->p == NULL)
    {
        e->sui = NULL;
        l->p = e;
        l->d = e;
    }
    else
    {
        e->sui = l->p;
        l->p = e;
    }
    return l;
}

list *insereFin(list *l, int y)
{
    el *e = (el *)malloc(sizeof(el));
    e->x = y;
    el *cur = l->p;
    if (l->p == NULL)
    {
        e->sui = NULL;
        e->prec = NULL;
        l->p = e;
        l->d = e;
    }
    else
    {
        e->prec = l->d;
        l->d = e;
        e->sui = NULL;
    }
    return l;
}

void affiche(list *l)
{
    el *cur = l->p;
    if (l->p == NULL)
    {
        printf("la liste est vide");
    }
    else
    {
        while (cur != NULL)
        {
            printf("%d\t", cur->x);
            cur = cur->sui;
        }
    }
}

void supprimerPre(list *l)
{
    el *tmp = l->p;
    if (l->p == NULL)
    {
        printf("la liste est vide");
    }
    else
    {
        l->p = l->p->sui;
        l->p->prec = NULL;
        tmp->sui == NULL;
        free(tmp);
    }
}

void supprimerFin(list *l)
{
    el *tmp = l->p;
    if (l->p == NULL)
    {
        printf("la liste est vide");
    }
    else if (l->p->sui == NULL)
    {
        free(tmp);
    }
    else
    {
        while (tmp->sui != NULL)
        {
            tmp = tmp->sui;
        }
        tmp->prec->sui = NULL;
        tmp->prec = NULL;
        free(tmp);
    }
}

void test_suffixe(list *l1, list *l2)
{
    el *cur1 = l1->d;
    el *cur2 = l2->d;
    int test = 1;

    while (cur1->sui != NULL)
    {
        if (cur1->x != cur2->x)
        {
            printf("l1 nest pas un suffixe");
            test = 0;
            break;
        }
        cur1 = cur1->prec;
        cur2 = cur2->prec;
    }
    if (test == 1)
    {
        printf("l1 est  un suffixe");
    }
}

void main()
{
    list *l1 = initlist();
    list *l2 = initlist();

    l2 = insereDeb(l2, 4);
    l2 = insereDeb(l2, 2);
    l2 = insereDeb(l2, 9);
    l2 = insereDeb(l2, 8);
    l2 = insereDeb(l2, 6);

    l1 = insereDeb(l1, 4);
    l1 = insereDeb(l1, 2);

    affiche(l1);
    printf("\n  \n");
    affiche(l2);
    printf("\n  \n");
    test_suffixe(l1, l2);
}
