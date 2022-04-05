#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct{
    char type[20];
    int prix;
}Repas;

typedef struct{
    int nbrStars;
    int prix;
}Hotel;

typedef struct 
{
    char nom[20],prenom[30];
    int dej;
    int diner;
    int nbetoilesh;
    int nbRepas;
    bool conjoint;
    bool hotel;
    Repas r[2];
    Hotel h;
}Participant;

typedef Participant TabPart[100];
}TabPart; 
void Nb2Etoiles(TabPart t, int n){
    for (int i = 0; i < n; i++)
    {
        if(t[i].nbetoilesh==2)
            printf("Nom : %s \nPrenom : %s",t.tabPart[i].nom,t.tabPart[i].prenom);
    }
    
}
int NbDej(TabPart t, int n){
    int s=0;
    for (int i = 0; i < n; i++)
    {
        if(t[i].dej>0)
            s++;
        if(t[i].diner>0)
            s++;
        
        if(t[i].conjoint==true)
            s*=2;
        
    }
    
    return s;
}

int montant(Participant p){
    int som=0;
    if(p.hotel)
        som+=p.h.prix;
    if(p.nbRepas>0)
        {
            int a=0;
            for (int i = 0; i < p.nbRepas; i++)
            {
                a+=p.r[i].prix;
            }
            if(p.conjoint)
                a*=2;
            som+=a;
        }
    return som;
}


Participant saisie_particip(){
    Participant p;
    char c;
    printf("Nom :");
    scanf("%s",p.nom);
    printf("Prnom :");
    scanf("%s",p.prenom);
    fflush(stdin);
    do
    {
        printf("Conjoint? O/N");
        scanf("%c",&c);
    } while (c!='O' &&c!='N');
    c=='O'?p.conjoint=true:p.conjoint=false;
    do
    {
        printf("Repas? O/N");
        scanf("%c",&c);
    } while (c!='O' &&c!='N');
    if(c=='O'){
        int nb_repas;
        do
        {
            printf("Déjeuner : 1 | Diner : 2 | les deux : 3");
            scanf("%d",nb_repas);
        } while (nb_repas>0 && nb_repas<4);
        switch(nb_repas){
            case 1 : {
                strcpy(p.r[0].type,"Dejeuner");
                p.r->prix=20;
                p.nbRepas=1;
            }
            case 2 : {
                strcpy(p.r[1].type,"Diner");
                p.r->prix=35;
                p.nbRepas=1;
            }
            case 3 : {
                strcpy(p.r[0].type,"Dejeuner");
                p.r->prix=20;
                strcpy(p.r[1].type,"Diner");
                p.r->prix=35;
                p.nbRepas=2;
            }

        }
        
    }
    do
    {
        printf("Hotel? O/N");
        scanf("%c",&c);
    } while (c!='O' &&c!='N');
    if(c=='O'){
        p.hotel=true;
        int nbstars;
        do
        {
            printf("Hotel 3 etoiles : 3 | hotel 4 etoiles : 4");
            scanf("%d",p.h.nbrStars);
        } while (nbstars>2 && nbstars<5);
        printf("Prix hotel");
        scanf("%d",p.h.prix);
    }
}

TabPart saisie_tab(){
    TabPart tp;
    int i=0;
    do{

    }
    
}

int main(int argc, char const *argv[])
{
    TabPart t;
    int n;
    Nb2Etoiles(t,n);
    system("pause");
    return 0;
}

