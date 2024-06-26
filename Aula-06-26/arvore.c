#include "arvore.h"

struct arvore{
    struct arvore *esq;
    struct arvore *dir;
    tAluno *aluno;
};

tArvore *inicializaArvore(tAluno *aluno){
    tArvore *a = malloc(sizeof(tArvore));
    a->esq = NULL;
    a->dir = NULL;
    a->aluno = aluno;
    return a;
}

void insereArvore(tArvore *raiz, tArvore *no)
{
    if(raiz==NULL) raiz = no;
    else
    {
        if(retornaMatricula(no->aluno) < retornaMatricula(raiz->aluno)) insereArvore(raiz->esq, no);
        else insereArvore(raiz->dir, no); 
    }
}

tAluno *buscaAluno(tArvore *raiz, int matricula)
{
    if(raiz==NULL) return NULL;
    else
    {
        if(retornaMatricula(raiz->aluno) == matricula) return raiz->aluno;
        if(retornaMatricula(raiz->aluno) < matricula) return buscaAluno(raiz->esq, matricula);
        else return buscaAluno(raiz->dir, matricula); 
    }
}

void liberaArvore(tArvore *raiz)
{
    if(raiz!=NULL)
    {
        liberaArvore(raiz->esq);
        liberaArvore(raiz->dir);
        liberaAluno(raiz->aluno);
        free(raiz);
    }
}

tAluno *retornaAluno(tArvore *raiz)
{
    return raiz->aluno;
}