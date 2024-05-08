#include "posto.h"
#include "lista.h"
#include "amostra.h"
#include <stdlib.h>


struct posto{   
    char *nome;
    tLista *nprocessados, *positivo, *negativo;
};

Posto* inicPosto(char* nome)
{
    Posto *p = malloc(sizeof(Posto));
    p->nome = nome;
    p->negativo = allocaLista();
    p->positivo = allocaLista();
    p->nprocessados = allocaLista();
}

void imprimePosto(Posto* posto)
{
    printf("Exames não processados:\n");
    imprimeLista(posto->nprocessados);
    printf("Exames positivos\n");
    imprimeLista(posto->positivo);
    printf("Exames negativos\n");
    imprimeLista(posto->negativo);
}

void realizaColeta(Posto* posto, char* pessoa, int idade)
{
    Amostra *a = inicAmostra(pessoa, idade);
    tCelula *c = allocaCelula();
    atribuiCelula(c, a);
    if(idade>=60)
    {
        InsereCelulaListaPrim(c, posto->nprocessados);
    }
    else
    {
        insereCelulaLista(c, posto->nprocessados);
    }
}

void processaLoteAmostras(Posto* posto)
{
    tLista *l = posto->nprocessados;
    tCelula *c = retornaprim(l);
    while(c != NULL)
    {
        if(retornaCargaViral(retornaConteudo(c))>= 500)
        {
            insereCelulaLista(c, posto->positivo);
        }
        else
        {
            insereCelulaLista(c, posto->negativo);
        }
        c = retornaProxCelula(c);
    }
}

void liberaPosto(Posto* posto)
{
    if(posto->nprocessados != NULL)
    {
        liberaLista(posto->nprocessados);
    }
    if(posto->positivo != NULL)
    {
        liberaLista(posto->positivo);
    }
    if(posto->negativo != NULL)
    {
        liberaLista(posto->negativo);
    }
    if(posto->nome != NULL)
    {
        free(posto->nome);
    }
    if(posto != NULL)
    {
        free(posto);
    }
}