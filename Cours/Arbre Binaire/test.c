#include"arbre.h"
#include<stdio.h>
#include<stdlib.h>

void main()
{
	noeud* T = NULL;
	addNodeRec(&T, 10); addNodeRec(&T, 20); addNodeRec(&T, 4); 
	addNodeRec(&T, 8); 	addNodeRec(&T, 2); addNodeRec(&T, 35); 	addNodeRec(&T, 13);
	afficheTree(T);	
	
	if (rechercheElem(T, 9))
		printf("\n Element existant \n");
	else
		printf("\n Element non existant \n");

	printf("\n La taille de l'arbre est %u \n", taille(T));

	printf("\n Le nombre de feuilles est: %u\n", Nb_Feuilles(T));
	
	printf("\n La hauteur de l'arbre est %u \n", hauteur(T));
	
	printf("\n supprimer une valeur de l'arbre \n");
	T = suppNoeud(T, 13);

	//SuppTree(&T);
	afficheTree(T);
}