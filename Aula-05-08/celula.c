#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "celula.h"
#include "amostra.h"

struct celula{
    tCelula *prox;
    void *conteudo;
};

tCelula *allocaCelula()
{
    tCelula *c = malloc(sizeof(tCelula));
    c->prox=NULL;
    c->conteudo=NULL;
    return c;
}

void atribuiCelula(tCelula *c, void *p)
{
    c->conteudo = p;
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
    if(c!=NULL)
    {
        if(c->conteudo != NULL)
        {
            liberaAmostra(c->conteudo);
        }
        free(c);
    }
    return j;
}

void *retornaConteudo(tCelula *c)
{
    return c->conteudo;
}