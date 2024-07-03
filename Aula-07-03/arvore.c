#include "arvore.h"

struct arvore{
    struct arvore *esq;
    struct arvore *dir;
    void *conteudo;
};

tArvore *inicializaArvore(void *conteudo)
{
    tArvore *a = malloc(sizeof(tArvore));
    a->esq = NULL;
    a->dir = NULL;
    a->conteudo = conteudo;
    return a;
}

void *criaArvoreVazia()
{
    return NULL;
}

tArvore *insereArvore(tArvore *raiz, void *conteudo, Maior compara)
{
    if(raiz == NULL)
    {
        tArvore *raiz = inicializaArvore(conteudo);
    }
    else if(compara(conteudo, raiz->conteudo)) // maior
    {
        raiz->dir = insereArvore(raiz->dir, conteudo, compara);
    }
    else //menor
    {
        raiz->esq = insereArvore(raiz->esq, conteudo, compara);
    }
    return raiz;
}

//RETORNA O NO COM O CONTEUDO NO PARAMETRO
tArvore *buscaConteudo(tArvore *raiz, void *parametro, Maior compara)
{
    if(raiz == NULL) return NULL;
    else if(compara(raiz->conteudo, parametro) == 1) return buscaConteudo(raiz->esq, parametro, compara);
    else if(compara(raiz->conteudo, parametro) == -1) return buscaConteudo(raiz->dir, parametro, compara);
    else return raiz;
}

//LIBERA TODA A ARVORE
void liberaArvore(tArvore *raiz, desalocaConteudo desaloca)
{
    if(raiz != NULL)
    {
        liberaArvore(raiz->esq, desaloca);
        liberaArvore(raiz->dir, desaloca);
        desaloca(raiz->conteudo);
    }
}

//RETORNA O CONTEUDO DA ARVORE CASO NECESSARIO
void *retornaConteudo(tArvore *raiz)
{
    return raiz->conteudo;
}

//IMPRIME ESQUERDA PRIMEIRO
void imprimeArvore(tArvore *raiz, imprimeConteudo imprime)
{
    if(raiz != NULL)
    {
        imprimeArvore(raiz->esq, imprime);
        imprime(raiz->conteudo);
        imprimeArvore(raiz->dir, imprime);
    }
}

