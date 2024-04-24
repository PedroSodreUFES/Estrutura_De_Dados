#ifndef _TPRODUTO_H_
#define _TPRODUTO_H_

typedef struct _tProduto tProduto;

tProduto *alocaProduto();
void liberaProduto(tProduto *p);
void LeProduto(tProduto *p);
char *retornaNomeProduto(tProduto *p);
float retornaPrecoProduto(tProduto *p);
int retornaQuantidadeProduto(tProduto *p);
void imprimeProduto(tProduto *p);

#endif