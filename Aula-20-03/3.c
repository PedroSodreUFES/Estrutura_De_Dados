#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    tFilial *filiais;
    int nfiliais;
}tMercado;

typedef struct{
    int estoque, nprodutos;
    tProduto *produtos;
}tFilial;

typedef struct{
    char nome[30];
    int quantidade;
    float preco;
}tProduto;


int main()
{
    
}