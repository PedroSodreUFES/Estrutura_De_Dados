#ifndef _TMERCADO_H_
#define _TMERCADO_H_

#include "tProduto.h"
#include "tFilial.h"

typedef struct _tMercado tMercado;

typedef struct _RedesDeMercados RedesDeMercados;

tMercado *allocaMercado();

void liberaMercado(tMercado *m);

int MercadoExiste(RedesDeMercados *r, char *nome);

void addFilial(tMercado *m, void *f);

int obtemFiliaisDoMercado(tMercado *m);

RedesDeMercados *allocaRedesDeMercados();

void liberaRedeDeMercados(RedesDeMercados *r);

void addMercado(RedesDeMercados *r, void *m);

int obtemNumeroDeMercados(RedesDeMercados *r);

int obtemEstoqueDoMercado(tMercado *m);

void fazResumoGeral(RedesDeMercados *r);

void menuMercados(RedesDeMercados *r);

void printaMenuMercados();

void menuMercado(tMercado *m);

void printaMenuMercado();

int FilialExiste(tMercado *m, char* nome);


#endif