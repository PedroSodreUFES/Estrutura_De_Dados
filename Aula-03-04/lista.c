#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

struct lista{
    tCelula *prim;
    tCelula *ult;
};

tLista *allocaLista()
{
    tLista *l = malloc(sizeof(tLista));
    l->ult = NULL;
    l->prim = NULL;
    return l;
}

void insereCelulaLista(tCelula *c, tLista *l)
{
    if(l->ult==NULL)
    {
        l->ult=c;
    }
    if(l->prim==NULL)
    {
        l->prim =c;
    }
    else
    {
        tCelula *a = l->prim;
        l->prim =c;
        atribuiProxCelula(c, a);
    }
}

void liberaLista(tLista *l)
{
    tCelula *p= l->prim;
    while(p != NULL)
    {
        p = liberaCelula(p);
    }
    if(l!=NULL)
    {
        free(l);
    }
}

void imprimeLista(tLista *l)
{
    tCelula *c = l->prim;
    while(c!=NULL)
    {
        imprimeProduto(retornaProduto(c));
        c=retornaProxCelula(c);
    }
}