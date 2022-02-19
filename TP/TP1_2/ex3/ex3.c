#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int j, m, a;
} Date;
typedef struct
{
    int anne, nseq;
} Identifiant;
typedef struct
{
    Identifiant id;
    char nom[20], prenom[20];
    Date date_naiss;
} Etudiant;

int main(int argc, char const *argv[])
{
    Etudiant *etd;
    int n;
    printf("nombre des etudiants : ");
    scanf("%d", &n);
    etd = malloc(n * sizeof(Etudiant));
    for (int i = 0; i < n; i++)
    {
        printf("Etudiant num %d \n", i + 1);
        printf("Nom : ");
        scanf("%s", etd->nom);
        printf("prenom : ");
        scanf("%s", etd->prenom);
        printf("identifiant\n");
        printf("Annee inscription : ");
        scanf("%d", &etd->id.anne);
        printf("numero sequentiel : ");
        scanf("%d", &etd->id.nseq);
        printf("Date de naissance\n");
        printf("Annee : ");
        scanf("%d", &etd->date_naiss.a);
        printf("Mois : ");
        scanf("%d", &etd->date_naiss.m);
        printf("Jour : ");
        scanf("%d", &etd->date_naiss.j);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Identifiant \n");
        printf("Annee : %d\n", (etd + i)->id.anne);
        printf("Numero sequentiel : %d\n", (etd + i)->id.nseq);
        printf("Nom : %s\n", (etd + i)->nom);
        printf("Prenom : %s\n", (etd + i)->prenom);
        printf("Date de naissance : %d/%d/%d\n", (etd + i)->date_naiss.j, (etd + i)->date_naiss.m, (etd + i)->date_naiss.a);
    }
    system("pause");
    return 0;
}
