#ifndef ARVORE_H
#define ARVORE_H

#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"

typedef struct arvore tArvore;

tArvore *inicializaArvore(tAluno *aluno);

void insereArvore(tArvore *raiz, tArvore *no);

tAluno *buscaAluno(tArvore *raiz, int matricula);

void liberaArvore(tArvore *raiz);

tAluno *retornaAluno(tArvore *raiz);

#endif