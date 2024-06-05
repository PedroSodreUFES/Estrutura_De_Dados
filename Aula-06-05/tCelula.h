#ifndef TCELULA_H
#define TCELULA_H


typedef struct celula tCelula;

tCelula* allocaCelula();

void atribuiConteudo(tCelula *c, void *conteudo);

tCelula *retornaProx(tCelula *c);

tCelula *retornaUlt(tCelula *c);

void insereNaFila(tCelula *prim, void *conteudo);

void desalocaFila(tCelula *prim);

void imprimeFila(tCelula *prim);

#endif