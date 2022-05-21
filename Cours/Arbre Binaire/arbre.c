#include"arbre.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void addNode(noeud** tree, int key) //Version itérative
{
    noeud* tmpTree = *tree;
    noeud* tmpNode;
    noeud* elem = malloc(sizeof(struct noeud));
    elem->cle = key;
    elem->gauche = NULL;
    elem->droite = NULL;
    if (tmpTree != NULL) //Arbre non vide
    {
        do
        {
            tmpNode = tmpTree;
            if (key > tmpTree->cle)
            {
                tmpTree = tmpTree->droite; //accès à la branche droite
                if (tmpTree == NULL)
                    tmpNode->droite = elem; //inserer l'élément à droite
            }
            else
            {
                tmpTree = tmpTree->gauche; //accès à la branche gauche
                if (tmpTree == NULL)
                    tmpNode->gauche = elem; //inserer l'élément à gauche
            }
        } while (tmpTree != NULL);
    }
    else //Arbre vide
        *tree = elem;
}

void addNodeRec(noeud** tree, int key) //Version récursive
{
    noeud* elem = malloc(sizeof(struct noeud));
    elem->cle = key;
    elem->gauche = NULL;
    elem->droite = NULL;
    if ((*tree) != NULL) //Arbre non vide
    {
        if (key > (*tree)->cle)
        {
            addNodeRec(&(*tree)->droite, key);
        }
        else
        {
            addNodeRec(&(*tree)->gauche, key);
        }
    }
    else //Arbre vide
        *tree = elem;

}

void afficheTree(struct noeud* tree)
{
    if (tree == NULL) return;
    if (tree->droite) afficheTree(tree->droite);
    printf("\n Cle = %d\n", tree->cle);
    if (tree->gauche) afficheTree(tree->gauche);

}

int rechercheElem(struct noeud* tree, int key)
{
    while (tree)
    {
        if (key == tree->cle)
            return 1;
        if (key > tree->cle)
            tree = tree->droite;
        else
            tree = tree->gauche;
    }
    return 0;
}

void SuppTree(struct noeud** tree)
{
    struct noeud* tmpTree = *tree;
    if (!tree) return;
    if (tmpTree->gauche) SuppTree(&tmpTree->gauche);
    if (tmpTree->droite) SuppTree(&tmpTree->droite);
    free(tmpTree);
    *tree = NULL;
}

unsigned taille(noeud* tree) // compter le nombre de nœuds de l’arbre.
{
    if (tree == NULL)
        return(0);
    else
        return(1 + taille(tree->droite) + taille(tree->gauche));
}

unsigned Nb_Feuilles(noeud* tree) // compter le nombre de feuilles
{
    if (tree == NULL)
        return(0);
    if ((tree->gauche == NULL) && (tree->droite == NULL)) //si pas de fils incrémenter le nbre de feuilles
        return(1);
    else
        return (Nb_Feuilles(tree->gauche) + Nb_Feuilles(tree->droite));
}

unsigned hauteur(noeud* tree)
{
    int Nb1, Nb2;
    if (tree == NULL)
        return(0);
    else
    {
        Nb1 = Nb_Feuilles(tree->gauche);
        Nb2 = Nb_Feuilles(tree->droite);
    }
    //max(Nb1, Nb2)
    if (Nb1 > Nb2)
        return(Nb1 + 1);
    else
        return(Nb2 + 1);
}
noeud* minValueNode(noeud* node) // noeud* maxValueNode(noeud* node)
{
    noeud* curseur = node;

    /*boucle pour trouver la feuille la plus à gauche = chercher la valeur la plus petite*/
    while ((curseur != NULL) && (curseur->gauche != NULL)) //(curseur->droite != NULL))
        curseur = curseur->gauche;  //curseur = curseur->droite;

    return curseur;
}
/*
- si le noeud à enlever ne possède aucun fils, on l'enlève,
- si le noeud à enlever n'a qu'un fils, on le remplace par ce fils,
- si le noeud à enlever a deux fils, on le remplace par la feuille de plus petite valeur dans le
sous-arbre droit, puis on supprime cette feuille.*/
noeud* suppNoeud(noeud* tree, int x)
{
    // arbre vide
    if (tree == NULL) return tree;

    /*Si la valeur à supprimer (clé) est inférieur à la valeur (clé) de la racine,
     alors elle se trouve dans le sous-arbre gauche*/
    if (x < tree->cle)
        tree->gauche = suppNoeud(tree->gauche, x);

    /*Si la valeur à supprimer (clé) est supérieur à la valeur (clé) de la racine,
     alors elle se trouve dans le sous-arbre droite*/

    else if (x > tree->cle)
        tree->droite = suppNoeud(tree->droite, x);

    /* si la valeur à supprimer est la même que la clé de la racine, alors c'est le nœud à supprimer*/
    else // x == tree->cle
    {
        // noeud avec un seul fils
        if (tree->gauche == NULL)
        {
            noeud* temp = tree->droite;
            free(tree);
            return temp;
        }
        else if (tree->droite == NULL)
        {
            noeud* temp = tree->gauche;
            free(tree);
            return temp;
        }

        // cas 3 : noeud avec deux fils
          //Etape 1 : cherche le noeud ayant une valeur (clé) plus petite, ce noeud est appelé ici tmp
           noeud* temp = minValueNode(tree->droite); //noeud* temp = maxValueNode(tree->gauche);

        // copier la valeur (clé) du noeud tmp dans la valeur du noeud à supprimer
          tree->cle = temp->cle;

        // supprimer le noeud tmp (récursion)
        tree->droite = suppNoeud(tree->droite, temp->cle); //tree->gauche = suppNoeud(tree->gauche, temp->cle);
    }
    return tree;

}

