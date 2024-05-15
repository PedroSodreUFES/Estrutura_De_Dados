#ifndef PILHA_H
#define PILHA_H

#define MaxTam 1000

typedef struct indicepilha IndicePilha;

typedef int TipoItem;

typedef struct tipopilhadupla TipoPilhaDupla;

TipoPilhaDupla *allocaPilhaDupla();

void EmpilhaPilha1(TipoPilhaDupla *p, TipoItem *i);

void EmpilhaPilha2(TipoPilhaDupla *p, TipoItem *i);

TipoItem *DesempilhaPilha1(TipoPilhaDupla *p);

TipoItem *DesempilhaPilha2(TipoPilhaDupla *p);

TipoItem *allocaItem();

void ImprimePilha(TipoPilhaDupla *p);

#endif