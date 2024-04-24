#include "Gato.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct gato{
    char *nome;
    int manso_ou_bravo;
};

Gato* inicGato(char *nome, int mob)
{
    Gato *c = malloc(sizeof(Gato));
    char n = malloc(sizeof(char) * (strlen(nome)+1));
    n = strcpy(n, nome);
    c->nome = n;
    c->manso_ou_bravo = mob;
    return c;
}

void liberaGato(Gato *g)
{
    if(g->nome != NULL)
    {
        free(g->nome);
    }
    if(g!=NULL)
    {
        free(g);
    }
}

void imprimeGato(Gato *g)
{
    printf("Pet é um gato ");
    if(g->manso_ou_bravo)
    {
        printf("manso");
    }
    else
    {
        printf("bravo");
    }
    printf(" de nome %s\n", g->nome);
}

int EhGatoManso(Gato *g)
{
    if(g->manso_ou_bravo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}