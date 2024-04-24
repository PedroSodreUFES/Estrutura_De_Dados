#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "celula.h"
#include "produto.h"

//fazendo uma lista de 3 produtos
int main()
{
    int i;
    tCelula *primeira = allocaCelula();
    tCelula *l = primeira;
    for(i=0 ; i<3 ; i++)
    {
        tProduto *p = allocaProduto();
        leProduto(p);
        l = insereLista(l, p);
    }
    imprimeLista(primeira);
}
