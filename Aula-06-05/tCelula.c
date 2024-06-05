#include <stdio.h>
#include <stdlib.h>
#include "tCelula.h"

struct celula{
    void *conteudo;
    void (*imprimeConteudo)(void*);
    struct celula *prox;
    struct celula *ant;
};

tCelula* allocaCelula()
{
    tCelula *c = malloc(sizeof(tCelula));
    c->conteudo=NULL;
    c->prox=NULL;
    c->ant = NULL;
    c->imprimeConteudo=NULL;
}

void atribuiConteudo(tCelula *c, void *conteudo)
{
    c->conteudo = conteudo;
}

tCelula *retornaProx(tCelula *c)
{
    return c->prox;
}

tCelula *retornaUlt(tCelula *c)
{
    if(c->prox == NULL)
    {
        return c;
    }
    else
    {
        return retornaUlt(retornaProx(c));
    }
}

void insereNaFila(tCelula *prim, void *conteudo)
{
    tCelula *nova = allocaCelula();
    atribuiConteudo(nova, conteudo);
    tCelula *ult = retornaUlt(prim);
    ult->prox = nova;
    nova->ant = ult;
}

void desalocaFila(tCelula *prim)
{
    tCelula *aux = prim->prox;
    if(prim->conteudo != NULL)
    {
        printf("IMPLEMENTA A FUNÇÃO DE DESALOCAR CONTEUDO EM CELULA.C\n");
    }
    if(prim!=NULL)
    {
        free(prim);
    }
    if(aux==NULL)
    {
        return;
    }
    else
    {
        return desalocaFila(aux);
    }
}

void imprimeFila(tCelula *prim)
{
    if(prim == NULL)
    {
        return;
    }
    printf("Imprimindo conteudo da célula:\n");
    //funcao imprime conteudo;
    imprimeFila(retornaProx(prim));
}
