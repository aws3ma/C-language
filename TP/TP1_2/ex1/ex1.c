#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct
{
    int nserie, nseq;
} Immat;

Immat saisie_immat()
{
    Immat m;
    printf("numero serie : ");
    scanf("%d", &m.nserie);
    printf("numero nseq : ");
    scanf("%d", &m.nseq);
    return m;
}
int saisie(Immat immats[])
{
    int n;
    printf("donner nombre des immats : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("immat num %d : ", i + 1);
        immats[i]=saisie_immat();
    }

    return n;
}

int nombre_voitures(int n, Immat immats[], int s)
{
    int nbr = 0;

    for (int i = 0; i < n; i++)
    {
        if (immats[i].nserie == s)
            nbr++;
    }
    return nbr;
}
bool immat_exist(int n, Immat immats[], Immat m)
{
    for (int i = 0; i < n; i++)
    {
        if (immats[i].nseq == m.nseq && immats[i].nserie == m.nserie)
            return true;
    }
    return false;
}
int main(int argc, char const *argv[])
{
    Immat immats[20],m;
    int n = saisie(immats), s;
    printf("numero de serie a chercher");
    scanf("%d", &s);
    printf("Nombre des voitures ayant la serie %d = %d", s, nombre_voitures(n, immats, s));
    printf("saisie immat a rechercher");
    m=saisie_immat();
    immat_exist(n,immats,m)?printf("Immatricule existe"):printf("Immatricule n'existe pas");
        system("pause");
    return 0;
}
