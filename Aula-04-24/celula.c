#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "celula.h"

#define CACHORRO 1
#define GATO 0

struct celula{
    tCelula *prox;
    void *animal;
    int catordog;
};

tCelula *allocaCelula()
{
    tCelula *c = malloc(sizeof(tCelula));
    c->prox=NULL;
    c->animal=NULL;
    c->catordog=-1;
    return c;
}

void atribuiAnimal(tCelula *c, void *p)
{
    c->animal = p;
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
        free(c);
    }
    return j;
}

void *retornaAnimal(tCelula *c)
{
    return c->animal;
}

void EhCachorro(tCelula *c)
{
    c->catordog=CACHORRO;
}

void EhGato(tCelula *c)
{
    c->catordog=GATO;
}

int catOrDOG(tCelula *c)
{
    if(c->catordog)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void *retornaAnimal(tCelula *c)
{   
    return c->animal;
}