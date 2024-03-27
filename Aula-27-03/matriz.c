#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


struct matriz{
    int **m, linhas, colunas;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas)
{
    Matriz *m = (Matriz*)malloc(1*sizeof(Matriz));
    int **mat = (int**)malloc(nlinhas * sizeof(int*));
    int i, j, n;
    for(i=0 ; i<nlinhas ; i++)
    {
        mat[i] = (int*)malloc(ncolunas * sizeof(int));
    }
    m->m = mat;
    m->linhas = nlinhas;
    m->colunas = ncolunas;
    return m;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem)
{
    mat->m[linha][coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna)
{
    return mat->m[linha][coluna];
}

int recuperaNColunas (Matriz* mat)
{
    return mat->colunas;
}

int recuperaNLinhas (Matriz* mat)
{
    return mat->linhas;
}

void imprimeMatriz(Matriz* mat)
{
    int i, j;
    for(i=0 ; i<recuperaNLinhas(mat) ; i++)
    {
        for(j=0 ; j<recuperaNColunas(mat) ; j++)
        {
            printf("%d", recuperaElemento(mat, i, j));
            if(j!= recuperaNColunas(mat)-1)
            {
                printf(" |");
            }
        }
        printf("\n");
    }
}

void destroiMatriz (Matriz* mat)
{
    int i;
    for(i=0 ; i<recuperaNLinhas(mat) ; i++)
    {
        if(mat->m[i] != NULL)
        {
            free(mat->m[i]);
        }
    }
    if(mat->m!= NULL)
    {
        free(mat->m);
    }
    if(mat!=NULL)
    {
        free(mat);
    }
}

Matriz* transposta (Matriz* mat)
{
    Matriz *t = inicializaMatriz(recuperaNColunas(mat), recuperaNLinhas(mat));
    int i, j;
    for(i=0 ; i<recuperaNLinhas(mat) ; i++)
    {
        for(j=0 ; j<recuperaNColunas(mat) ; j++)
        {
            modificaElemento(t, j, i, recuperaElemento(mat, i, j));
        }
    }
    return t;
}

Matriz* multiplicacao(Matriz* mat1, Matriz* mat2)
{
    if(recuperaNColunas(mat1) != recuperaNLinhas(mat2))
    {
        printf("Não é possivel multiplicar ambas as matrizes!\n\n");
        return NULL;
    }
    Matriz *mult = inicializaMatriz(recuperaNLinhas(mat1), recuperaNColunas(mat2));
    int i, j, z, soma;
    for(i=0 ; i<recuperaNLinhas(mat1) ; i++)
    {
        for(j=0 ; j<recuperaNColunas(mat2) ; j++)
        {
            soma=0;
            for(z=0 ; z<recuperaNLinhas(mat2) ; z++)
            {
                soma += recuperaElemento(mat1, i, z) * recuperaElemento(mat2, z, j);
            }
            modificaElemento(mult, i, j, soma);
        }
    }
    return mult;
}