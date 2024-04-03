#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "produto.h"

struct produto{
    int codigo;
    char *nome;
    float preco;
};

tProduto* allocaProduto()
{
    tProduto *p = malloc(sizeof(tProduto));
    p->codigo=-1;
    p->nome=NULL;
    p->preco=-1;
    return p;
}

char *retornaNome(tProduto *p)
{
    return p->nome;
}

int retornaCodigo(tProduto *p)
{
    return p->codigo;
}

float retornaPreco(tProduto *p)
{
    return p->preco;
}

void leProduto(tProduto *p)
{
    char nome[200];
    printf("digite o nome do produto: ");
    scanf("%[^\n]%*c", nome);
    p->nome = malloc(sizeof(char) * (strlen(nome)+1));
    strcpy(p->nome, nome);
    printf("Digite o codigo do produto em um número inteiro: ");
    int c;
    scanf("%d%*c", &c);
    p->codigo = c;
    printf("Digite o preço do produto: ");
    float preco;
    scanf("%f%*c", &preco);
    p->preco = preco;
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

void imprimeProduto(tProduto *p)
{
    printf("Nome: %s, Preço: %.2f, Código: %d\n", retornaNome(p), retornaPreco(p), retornaCodigo(p));
}