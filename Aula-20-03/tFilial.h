#ifndef _TFILIAL_H_
#define _TFILIAL_H_

#include "tProduto.h"

typedef struct _tFilial tFilial;

tFilial *alocaFilial();
void addProdutosEmFilial(tFilial *f, void *p);
void liberaFilial(tFilial *f);
int obtemEstoqueFilial(tFilial *f);
int obtemProdutosFilial(tFilial *f);
void imprimeProdutosFilial(tFilial *f);
char *obtemNomeFilial(tFilial *f);
void fazResumoFilial(tFilial *f);
void menuFilial(tFilial *f);
void printaMenuFilial();

#endif