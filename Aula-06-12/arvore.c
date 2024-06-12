#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

struct arvore{
    void *conteudo;
    struct arvore *esq;
    struct arvore *dir;
};

tArvore *criaArvore()
{
    tArvore *a = malloc(sizeof(tArvore));
    a->conteudo = NULL;
    a->dir = NULL;
    a->esq = NULL;
    return a;
}

void *retornaConteudo(tArvore *a)
{
    return a;
}

int celulaNula(tArvore *a)
{
    if(a == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void atribuiConteudo(tArvore *a, void *conteudo)
{
    a->conteudo = conteudo;
}


void liberaArvore(tArvore *raiz)
{
    if(raiz!=NULL)
    {
        liberaArvore(raiz->esq);
        liberaArvore(raiz->dir);
        free(raiz->conteudo);
    }
    free(raiz);
}

int folhas (tArvore* a)
{
    if(!celulaNula(a))
    {
        if(a->dir == NULL && a->esq == NULL)
        {
            return 1;
        }
        else
        {
            return 0 + folhas(a->esq) + folhas(a->dir);
        }
    }
    return 0;
}

int ocorrencias (tArvore* a , char* nome)
{
    if(!celulaNula(a))
    {
        if(strcmp((char*)a->conteudo, nome)==0)
        {
            return 1 + ocorrencias(a->esq, nome) + ocorrencias(a->dir, nome);
        }
        else
        {
            return 0 + ocorrencias(a->esq, nome) + ocorrencias(a->dir, nome);
        }
    }
    return 0;
}

int altura (tArvore* a)
{
    if(!celulaNula(a))
    {
        if(a->dir == NULL && a->esq == NULL) return 0;
        int altEsq = altura(a->esq) + 1;
        int altDir = altura(a->dir) + 1;
        if(altEsq > altDir) return altEsq;
        return altDir;
    }
    return -1;
}

void colocaNaDireita(tArvore *a, tArvore *cel)
{
    a->dir = cel;
}

void colocaNaEsquerda(tArvore *a, tArvore *cel)
{
    a->esq = cel;
}
