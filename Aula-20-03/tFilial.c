#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tFilial.h"

struct _tFilial{
    int nprodutos;
    char *nome;
    void **lista;
};

tFilial *alocaFilial()
{
    tFilial *f = malloc(sizeof(tFilial));
    char nome[100];
    printf("Digite o nome da nova filial: ");
    scanf("%[^\n]%*c", nome);
    f->nome = malloc((strlen(nome)+1)*sizeof(char));
    strcpy(f->nome, nome);
    f->lista=NULL;
    f->nprodutos=0;
    return f;
}

char *obtemNomeFilial(tFilial *f)
{
    return f->nome;
}

int obtemProdutosFilial(tFilial *f)
{
    return f->nprodutos;
}

int obtemEstoqueFilial(tFilial *f)
{
    int estoque=0, i;
    for(i=0 ; i<obtemProdutosFilial(f) ; i++)
    {
        estoque += retornaQuantidadeProduto(f->lista[i]);
    }
    return estoque;
}

void addProdutosEmFilial(tFilial *f, void *p)
{
    f->nprodutos++;
    f->lista = realloc(f->lista, obtemProdutosFilial(f)*sizeof(void*));
    f->lista[obtemProdutosFilial(f)-1] = p;
}

void liberaFilial(tFilial *f)
{
    int i=0;
    for(i=0 ; i<obtemProdutosFilial(f) ; i++)
    {
        liberaProduto(f->lista[i]);
    }
    if(f->lista!=NULL)
    {
        free(f->lista);
    }
    if(f->nome!=NULL)
    {
        free(f->nome);
    }
    if(f!=NULL)
    {
        free(f);
    }
}

void imprimeProdutosFilial(tFilial *f)
{
    int i;
    if(obtemProdutosFilial(f)==0)
    {
        printf("\t\tfilial se encontra sem produtos\n");
        return;
    }
    for(i=0 ; i<obtemProdutosFilial(f) ; i++)
    {
        imprimeProduto(f->lista[i]);
    }
}

void fazResumoFilial(tFilial *f)
{
    printf("\tFilial: %s\n\tEstoque: %d\n", obtemNomeFilial(f), obtemEstoqueFilial(f));
    imprimeProdutosFilial(f);
}

void menuFilial(tFilial *f)
{
    printf("Você está acessando a filial %s\n\n", obtemNomeFilial(f));
    int opcao, i;
    while(1)
    {
        printaMenuFilial();
        scanf("%d%*c", &opcao);
        if(opcao==1)
        {
            tProduto *p = alocaProduto();
            LeProduto(p);
            addProdutosEmFilial(f, p);
            printf("Produto adicionado com sucesso a filial\n\n");
        }
        else if(opcao==2)
        {
            fazResumoFilial(f);
            printf("\n");
        }
        else if(opcao==3)
        {
            printf("Voltando ao menu do mercado\n\n");
            break;
        }
    }
}

void printaMenuFilial()
{
    printf("Digite:\n\t1- para adicionar um produto a filial\n\t2- para ver os dados da filial\n\t3- para voltar\nDigite uma opcao: ");
}