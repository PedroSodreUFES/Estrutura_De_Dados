#ifndef CELULA_H
#define CELULA_H



typedef struct celula tCelula;

tCelula *allocaCelula();

void atribuiCelula(tCelula *c, void *p);

void atribuiProxCelula(tCelula *prim, tCelula *prox);

tCelula *retornaProxCelula(tCelula *c);

tCelula *liberaCelula(tCelula *c);

void *retornaConteudo(tCelula *c);

#endif