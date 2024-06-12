#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main()
{
    tArvore *a = criaArvore();
    tArvore *b = criaArvore();
    tArvore *c = criaArvore();
    tArvore *d = criaArvore();
    tArvore *e = criaArvore();
    tArvore *f = criaArvore();
    colocaNaDireita(a, b);
    colocaNaEsquerda(a, c); 
    colocaNaDireita(c,d);
    colocaNaEsquerda(d, e);
    colocaNaDireita(e, f);
    printf("%d\n", altura(a));
    return 0;
}