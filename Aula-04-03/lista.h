#ifndef LISTA_H
#define LISTA_H

#include "celula.h"

typedef struct lista tLista;

tLista *allocaLista();

void insereCelulaLista(tCelula *c, tLista *l);

void liberaLista(tLista *l);

void imprimeLista(tLista *l);

#endif