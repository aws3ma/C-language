#include <stdio.h>
void main(){
    int n=10, p=5, q=10,r ;
    r=n==(p=q);
    printf("A: n%d p=%d r=%d\n",n,p,q,r);
    n=p=q=5;
    n+=p+=q;
    printf("B: n%d p=%d r=%d\n",n,p,q,r);
    q=n<p? n++:p++;
    printf("C: n%d p=%d r=%d\n",n,p,q,r);
    q= n>p? n++:p++;
    printf("D: n%d p=%d r=%d\n",n,p,q,r);
}