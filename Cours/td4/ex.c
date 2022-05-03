#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *right;
    struct node *left;
} Node;

void insert(int x, Node **head)
{
    if (*head == NULL)
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->key = x;
        temp->left = NULL;
        temp->right = NULL;
        *head = temp;
    }
    else
    {
        if (x < (*head)->key)
        {
            insert(x, &(*head)->left);
        }
        else
        {
            insert(x, &(*head)->right);
        }
    }
}

int taille(Node *head)
{
    if (head == NULL)
        return 0;
    else
    {
        return 1 + taille(head->left) + taille(head->right);
    }
}
int nb_feuille(Node *head)
{
    if (head == NULL)
        return 0;
    else
    {
        if (head->left == NULL && head->right == NULL)
            return 1;
        else
            return nb_feuille(head->right)+nb_feuille(head->left);
    }
}
int hauteur(Node *head){
    if (head == NULL)
        return 0;
    else{
        int ls;
        int rs;
        ls = hauteur(head->left);
        rs = hauteur(head->right);
        if(rs<ls)
            return 1+ls;
        else
            return 1+rs;
    }
}
void supprimer(int x,Node **head,Node *prec){
    if(head != NULL){
        if((*head)->key==x && prec==NULL){
            *head=(*head)->right;
        }
        if((*head)->key<x){
            supprimer(x,&(*head)->right);
        }else if((*head)->key>x){
            supprimer(x,&(*head)->left);
        }
    }
}
void afficher(Node *head)
{
    if (head != NULL)
    {
        afficher(head->left);
        printf("%d\t", head->key);
        afficher(head->right);
    }
}

int main(int argc, char const *argv[])
{
    Node *tree = NULL;
    insert(3, &tree);
    insert(2, &tree);
    insert(4, &tree);
    insert(1, &tree);
    insert(5, &tree);
    afficher(tree);
    printf("%d\t", taille(tree));
    printf("%d\t", nb_feuille(tree));
    printf("%d\t", hauteur(tree));
    supprimer(3,&tree);
    printf("\n");
    afficher(tree);
    system("pause");
    return 0;
}
