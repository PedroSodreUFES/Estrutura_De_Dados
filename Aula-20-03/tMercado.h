#ifndef _TMERCADO_H_
#define _TMERCADO_H_

#include "tProduto.h"
#include "tFilial.h"

typedef struct{
    char nome[30];
    tFilial *filiais;
    int nfiliais;
}tMercado;

#endif