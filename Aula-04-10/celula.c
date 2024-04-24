#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "celula.h"

struct celula{
    tCelula *prox, *ant;
    tProduto *produto;
};

tCelula *allocaCelula()
{
    tCelula *c = malloc(sizeof(tCelula));
    c->prox=NULL;
    c->produto=NULL;
    c->ant = NULL;
    return c;
}

tCelula *insereLista(tCelula *velha, tProduto *prod)
{
    tCelula *nova = malloc(sizeof(tCelula));
    nova->prox = velha;
    velha->produto = prod;
    nova->ant = NULL;
    velha->ant = nova;
    return nova;
}

void atribuiProduto(tCelula *c, tProduto *p)
{
    c->produto = p;
}

void atribuiProxCelula(tCelula *prim, tCelula *prox)
{
    prim->prox = prox;
}

tCelula *retornaAntCelula(tCelula *c)
{
    return c->ant;
}

/*tCelula *liberaCelula(tCelula *c)
{
    tCelula *j = retornaProxCelula(c);
    liberaProduto(c->produto);
    if(c!=NULL)
    {
        free(c);
    }
    return j;
}*/

tProduto *retornaProduto(tCelula *c)
{
    return c->produto;
}

void imprimeLista(tCelula *l)
{
    while(l->ant!=NULL)
    {
        imprimeProduto(retornaProduto(l));
        l=retornaAntCelula(l);
    }
}