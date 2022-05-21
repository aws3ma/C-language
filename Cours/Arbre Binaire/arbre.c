#include"arbre.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void addNode(noeud** tree, int key) //Version it�rative
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
                tmpTree = tmpTree->droite; //acc�s � la branche droite
                if (tmpTree == NULL)
                    tmpNode->droite = elem; //inserer l'�l�ment � droite
            }
            else
            {
                tmpTree = tmpTree->gauche; //acc�s � la branche gauche
                if (tmpTree == NULL)
                    tmpNode->gauche = elem; //inserer l'�l�ment � gauche
            }
        } while (tmpTree != NULL);
    }
    else //Arbre vide
        *tree = elem;
}

void addNodeRec(noeud** tree, int key) //Version r�cursive
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

unsigned taille(noeud* tree) // compter le nombre de n�uds de l�arbre.
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
    if ((tree->gauche == NULL) && (tree->droite == NULL)) //si pas de fils incr�menter le nbre de feuilles
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

    /*boucle pour trouver la feuille la plus � gauche = chercher la valeur la plus petite*/
    while ((curseur != NULL) && (curseur->gauche != NULL)) //(curseur->droite != NULL))
        curseur = curseur->gauche;  //curseur = curseur->droite;

    return curseur;
}
/*
- si le noeud � enlever ne poss�de aucun fils, on l'enl�ve,
- si le noeud � enlever n'a qu'un fils, on le remplace par ce fils,
- si le noeud � enlever a deux fils, on le remplace par la feuille de plus petite valeur dans le
sous-arbre droit, puis on supprime cette feuille.*/
noeud* suppNoeud(noeud* tree, int x)
{
    // arbre vide
    if (tree == NULL) return tree;

    /*Si la valeur � supprimer (cl�) est inf�rieur � la valeur (cl�) de la racine,
���� alors elle se trouve dans le sous-arbre gauche*/
    if (x < tree->cle)
        tree->gauche = suppNoeud(tree->gauche, x);

    /*Si la valeur � supprimer (cl�) est sup�rieur � la valeur (cl�) de la racine,
���� alors elle se trouve dans le sous-arbre droite*/

    else if (x > tree->cle)
        tree->droite = suppNoeud(tree->droite, x);

    /* si la valeur � supprimer est la m�me que la cl� de la racine, alors c'est le n�ud � supprimer*/
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
          //Etape 1 : cherche le noeud ayant une valeur (cl�) plus petite, ce noeud est appel� ici tmp
           noeud* temp = minValueNode(tree->droite); //noeud* temp = maxValueNode(tree->gauche);

        // copier la valeur (cl�) du noeud tmp dans la valeur du noeud � supprimer
          tree->cle = temp->cle;

        // supprimer le noeud tmp (r�cursion)
        tree->droite = suppNoeud(tree->droite, temp->cle); //tree->gauche = suppNoeud(tree->gauche, temp->cle);
    }
    return tree;

}

