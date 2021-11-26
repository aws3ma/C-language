#include <stdio.h>
#include <stdlib.h>
void main()
{
    int nbr1, nbr2, pgcd, i;
  
    printf("Entrez premier entier: ");
    scanf("%d", &nbr1);
    printf("Entrez deuxieme entier: ");
    scanf("%d", &nbr2);
    for(i=1; i <= nbr1 && i <= nbr2; ++i)
    {
        if(nbr1%i==0 && nbr2%i==0)
            pgcd = i;
    }
  
    printf("PGCD de %d et %d est %d\n", nbr1, nbr2, pgcd);
    system("pause");
}