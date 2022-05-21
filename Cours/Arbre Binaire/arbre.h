typedef struct noeud
{
    int cle;
    struct noeud* gauche;
    struct noeud* droite;
}noeud ;

void addNode(noeud** tree, int key); //Version itérative
 
void addNodeRec(noeud** tree, int key); //version réucrsive

void afficheTree(noeud* tree);

int rechercheElem(noeud* tree, int key);

void SuppTree(noeud** tree);

unsigned taille(noeud* noeud);

unsigned Nb_Feuilles(noeud* tree);

unsigned hauteur(noeud* tree);

noeud* suppNoeud(noeud* tree, int x);
