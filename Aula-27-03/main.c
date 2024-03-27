#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main()
{
    //inicializa matrizes
    printf("Inicializando as tres matrizes\n");
    Matriz *m1 = inicializaMatriz(2, 2);
    Matriz *m2 = inicializaMatriz(2, 2);
    Matriz *m3 = inicializaMatriz(3, 3);
    int i, j, n;
    printf("Trez matrizes inicializadas\n");

    printf("Atribua elementos a m1\n");

    // ATRIBUI ELEMENTOS A M1
    for(i=0 ; i<recuperaNLinhas(m1) ; i++)
    {
        for(j=0 ; j<recuperaNColunas(m1) ; j++)
        {
            scanf("%d", &n);
            modificaElemento(m1, i, j, n);
        }
    }
    imprimeMatriz(m1);
    printf("Atribua elementos a m2\n");

    // ATRIBUI ELEMENTOS A M2
    for(i=0 ; i<recuperaNLinhas(m2) ; i++)
    {
        for(j=0 ; j<recuperaNColunas(m2) ; j++)
        {
            scanf("%d", &n);
            modificaElemento(m2, i, j, n);
        }
    }
    imprimeMatriz(m2);
    printf("Atribua elementos a m3\n");

    //Atribui elementos a M3
    for(i=0 ; i<recuperaNLinhas(m3) ; i++)
    {
        for(j=0 ; j<recuperaNColunas(m3) ; j++)
        {
            scanf("%d", &n);
            modificaElemento(m3, i, j, n);
        }
    }
    imprimeMatriz(m3);

    //Faz a transposta de m3:
    Matriz *tm3 = transposta(m3);
    printf("matriz 3:\n");
    imprimeMatriz(m3);
    printf("\n");
    printf("transposta de m3\n");
    imprimeMatriz(tm3);
    printf("\n");

    //mostra que nao da pra multiplicar m3 e m1
    Matriz *mult = multiplicacao(m1, m3);

    //faz a multiplicacao de m1 por m2;
    mult = multiplicacao(m1, m2);
    printf("multiplicacao de m1 por m2:\n");
    imprimeMatriz(mult);

    //Libera tudo:
    destroiMatriz(m1);
    destroiMatriz(m2);
    destroiMatriz(m3);
    destroiMatriz(mult);
    destroiMatriz(tm3);
}