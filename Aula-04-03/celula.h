#ifndef CELULA_H
#define CELULA_H

#include "produto.h" 

typedef struct celula tCelula;

tCelula *allocaCelula();

void atribuiProduto(tCelula *c, tProduto *p);

void atribuiProxCelula(tCelula *prim, tCelula *prox);

tCelula *retornaProxCelula(tCelula *c);

tCelula *liberaCelula(tCelula *c);

tProduto *retornaProduto(tCelula *c);

#endif