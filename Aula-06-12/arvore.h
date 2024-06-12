#ifndef ARVORE_H
#define ARVORE_H

typedef struct arvore tArvore;

tArvore *criaArvore();

void *retornaConteudo(tArvore *a);

int celulaNula(tArvore *a);

void atribuiConteudo(tArvore *a, void *conteudo);

int folhas (tArvore* a);

int ocorrencias (tArvore* a , char* nome);

int altura (tArvore* a);

void colocaNaDireita(tArvore *a, tArvore *cel);

void colocaNaEsquerda(tArvore *a, tArvore *cel);

#endif