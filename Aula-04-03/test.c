#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"
#include "celula.h"
#include "produto.h"

//fazendo uma lista de 3 produtos
int main()
{
    int i;
    tLista *l = allocaLista();
    for(i=0 ; i<3 ; i++)
    {
        tProduto *p = allocaProduto();
        leProduto(p);
        tCelula *c = allocaCelula();
        atribuiProduto(c, p);
        insereCelulaLista(c, l);
    }
    imprimeLista(l);
    liberaLista(l);
}
