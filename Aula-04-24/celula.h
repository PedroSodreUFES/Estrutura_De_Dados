#ifndef CELULA_H
#define CELULA_H

#define GATO 0
#define CACHORRO 1

#include "Cachorro.h"
#include "Gato.h"

typedef struct celula tCelula;

tCelula *allocaCelula();

void atribuiAnimal(tCelula *c, void *p);

void atribuiProxCelula(tCelula *prim, tCelula *prox);

tCelula *retornaProxCelula(tCelula *c);

tCelula *liberaCelula(tCelula *c);

void *retornaAnimal(tCelula *c);

void EhCachorro(tCelula *c);

void EhGato(tCelula *c);

int catOrDOG(tCelula *c);

void *retornaAnimal(tCelula *c);

#endif