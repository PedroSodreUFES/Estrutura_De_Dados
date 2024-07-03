#ifndef ARVORE_H
#define ARVORE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct arvore tArvore;

typedef void (*imprimeConteudo)(void*);
typedef void (*desalocaConteudo)(void*);
/*
Primeiro > Segundo --> retorna 1
Primeiro < Segundo --> retorna -1
Primeiro == Segundo --> retorna 0
*/
typedef int (*Maior)(void*,void*);

void *criaArvoreVazia();

tArvore *inicializaArvore(void *conteudo);

tArvore *insereArvore(tArvore *raiz, void *conteudo, Maior compara);

tArvore *buscaConteudo(tArvore *raiz, void *parametro, Maior compara);

void liberaArvore(tArvore *raiz, desalocaConteudo desaloca);

void *retornaConteudo(tArvore *raiz);

void imprimeArvore(tArvore *raiz, imprimeConteudo imprime);

#endif