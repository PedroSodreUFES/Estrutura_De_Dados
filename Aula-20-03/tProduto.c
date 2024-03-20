#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tProduto.h"

struct _tProduto{
    char *nome;
    int qntd;
    float preco;
};

tProduto *allocaProduto()
{
    tProduto *p = malloc(sizeof(tProduto));
    return p;
}

void liberaProduto(tProduto *p)
{
    if(p->nome!=NULL)
    {
        free(p->nome);
    }
    if(p!=NULL)
    {
        free(p);
    }
}

void LeProduto(tProduto *p)
{
    char nome[100];
    int qntd;
    float preco;
    printf("Digite o nome do produto: ");
    scanf("%[^\n]%*c", nome);
    p->nome = malloc((strlen(nome)+1)*sizeof(char));
    strcpy(p->nome, nome);
    printf("digite o preco do produto: ");
    scanf("%f", &preco);
    p->preco = preco;
    printf("digite a quantidade desse produto no estoque: ");
    scanf("%d%*c", &qntd);
    p->qntd = qntd;
}

char *retornaNomeProduto(tProduto *p)
{
    return p->nome;
}

float retornaPrecoProduto(tProduto *p)
{
    return p->preco;
}

int retornaQuantidadeProduto(tProduto *p)
{
    return p->qntd;
}

void imprimeProduto(tProduto *p)
{
    printf("Item: %s, valor unitário: %.2f, quantidade: %d\n", retornaNomeProduto(p), retornaPrecoProduto(p), retornaQuantidadeProduto(p));
}

tProduto **alocaListaDeProdutos()
{
    tProduto **lista = malloc(sizeof(tProduto*));
    return lista;
}

//isso aqui tem de ir pra filial
void AdicionaProduto(tProduto **lista, tProduto *p, int i)
{
    i++;
    lista = (tProduto**)realloc(lista, i*sizeof(tProduto*));
    lista[i-1]=p;
}
