#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "celula.h"

struct celula{
    tCelula *prox;
    tProduto *produto;
};

tCelula *allocaCelula()
{
    tCelula *c = malloc(sizeof(tCelula));
    c->prox=NULL;
    c->produto=NULL;
    return c;
}

void atribuiProduto(tCelula *c, tProduto *p)
{
    c->produto = p;
}

void atribuiProxCelula(tCelula *prim, tCelula *prox)
{
    prim->prox = prox;
}

tCelula *retornaProxCelula(tCelula *c)
{
    return c->prox;
}

tCelula *liberaCelula(tCelula *c)
{
    tCelula *j = retornaProxCelula(c);
    liberaProduto(c->produto);
    if(c!=NULL)
    {
        free(c);
    }
    return j;
}

tProduto *retornaProduto(tCelula *c)
{
    return c->produto;
}