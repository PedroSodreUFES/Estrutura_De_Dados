#include "Cachorro.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct cachorro{
    char *nome;
    int manso_ou_bravo;
};

Cachorro* inicCachorro(char *nome, int mob)
{
    Cachorro *c = malloc(sizeof(Cachorro));
    char n = malloc(sizeof(char) * (strlen(nome)+1));
    n = strcpy(n, nome);
    c->nome = n;
    c->manso_ou_bravo = mob;
    return c;
}

void liberaCachorro(Cachorro *c)
{
    if(c->nome != NULL)
    {
        free(c->nome);
    }
    if(c!=NULL)
    {
        free(c);
    }
}

void imprimeCachorro(Cachorro *c)
{
    printf("Pet é um cachorro ");
    if(c->manso_ou_bravo)
    {
        printf("manso");
    }
    else
    {
        printf("bravo");
    }
    printf(" de nome %s\n", c->nome);
}

int EhCachorroManso(Cachorro *c)
{
    if(c->manso_ou_bravo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}