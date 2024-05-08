#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"
#include "amostra.h"

struct lista{
    tCelula *prim;
    tCelula *ult;//prox
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
    //inicializar
    if(l->ult==NULL)
    {
        l->ult=c;
    }
    //se a primeira celula não existe
    if(l->prim==NULL)
    {
        l->prim =c;
    }
    //se a primeira celula existe
    else
    {
        tCelula *a = l->prim;
        l->prim =c;
        atribuiProxCelula(c, a);
    }
}

void InsereCelulaListaPrim(tCelula *c, tLista*l)
{
    atribuiProxCelula(c, l->prim);
    l->prim=c;
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
    tCelula *c = retornaprim(l);
    while(c!=NULL)
    {
        imprimeAmostra(retornaConteudo(c));
        c = retornaProxCelula(c);
    }
}

tCelula *retornaprim(tLista *l)
{
    return l->prim;
}