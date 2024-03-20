#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tProduto.h"

int main()
{
    tProduto **lista= alocaListaDeProdutos();
    int i;
    for(i=0 ; i<3 ; i++)
    {
        tProduto *p= allocaProduto();
        LeProduto(p);
        AdicionaProduto(lista, p, i);
        imprimeProduto(lista[i]);
    }
    
    for(i=0 ; i<3 ; i++)
    {
        imprimeProduto(lista[i]);
    }

    for(i=0 ; i<3 ; i++)
    {
        liberaProduto(lista[i]);
    }
    free(lista);
    return 0;
}
