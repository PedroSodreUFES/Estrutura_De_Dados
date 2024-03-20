#ifndef _TFILIAL_H_
#define _TFILIAL_H_

#include "tProduto.h"

typedef struct{
    int estoque, nprodutos;
    tProduto **produtos;
}tFilial;

#endif