#ifndef PRODUTO_H_
#define PRODUTO_H_

typedef struct produto tProduto;

tProduto *allocaProduto();

char *retornaNome(tProduto *p);

int retornaCodigo(tProduto *p);

float retornaPreco(tProduto *p);

void leProduto(tProduto *p);

void liberaProduto(tProduto *p);

void imprimeProduto(tProduto *p);

#endif