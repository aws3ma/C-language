#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
    float x,y,z;
}vect;
vect saisir(){
    vect v;
    printf("X : ");
    scanf("%f",&v.x);
    printf("y : ");
    scanf("%f",&v.y);
    printf("z : ");
    scanf("%f",&v.z);
    return v;
}

void normaliser(vect *v){
    double norme = sqrt(v->x*v->x + v->y*v->y+ v->z*v->z);
    v->x=v->x/norme;
    v->y=v->y/norme;
    v->z=v->z/norme;
}
void afficher(vect v){
    printf("x : %f y : %f : z : %f",v.x,v.y,v.z);
}
int main(int argc, char const *argv[])
{
    vect v=saisir();
    normaliser(&v);
    afficher(v);
    system("pause");
    return 0;
}
