#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int num;
    char villeD[20],villeA[20];
    float dist;
}Vol;

Vol saisir_vol(){
    Vol v;
    printf("Num vol : ");
    scanf("%d",&v.num);
    printf("Ville depart : ");
    scanf("%s",v.villeD);
    printf("Ville arrive : ");
    scanf("%s",v.villeA);
    printf("Distance : ");
    scanf("%f",&v.dist);

    return v;
}

void saisir_vols(int n, Vol vols[]){
    for (int i = 0; i < n; i++)
    {
        printf("vol numero %d",i+1);
        vols[i]=saisir_vol();
    }
    
}

int vol_plus_long(int n,Vol vols[]){
    int num=vols[0].num;
    int max=vols[0].dist;
    for (int i = 1; i < n; i++)
    {
        if(vols[i].dist>max){
            num=vols[i].num;
            max=vols[i].dist;
        }
    }
    return num;
}

void affiche_vol(Vol v){
    printf("Num : %d\nVille depart : %s\nVille arrive : %s\nDistance : %.2f\n",v.num,v.villeD,v.villeA,v.dist);
}


int main(int argc, char const *argv[])
{
    Vol vols[20];
    int n,i=0,num;
    printf("donner nombre des immats : ");
    scanf("%d", &n);
    saisir_vols(n,vols);
    num=vol_plus_long(n,vols);
    while(i<n && vols[i].num!=num){
        i++;
    }
    affiche_vol(vols[i]);
    system("pause");
    return 0;
}
