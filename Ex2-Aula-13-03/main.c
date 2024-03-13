#include <stdio.h>
#include <stdlib.h>
#include "aula12.h"

int main(int argc, char **argv)
{

    //Calculo das medidas da esfera
    float raio=10;
    float *ar=malloc(sizeof(float));
    float *v=malloc(sizeof(float));
    calc_esfera(raio, ar, v);
    free(ar);
    free(v);

    //Calculo das raizes
    float a=1, b=5, c=6;
    float *x1=malloc(sizeof(float));
    float *x2=malloc(sizeof(float));
    if(raizes(a, b, c, x1, x2))
    {
        printf("peguei as raízes\n");
    }
    else
    {
        printf("nao peguei raiz\n");
    }
    free(x1);
    free(x2);

    //numero de pares
    int *vet=malloc(10*sizeof(int));
    int i;
    for(i=0 ; i<10 ; i++)
    {
        vet[i] = i+1;
    }
    int p = pares(10, vet);
    printf("O numero de pares no vetor eh:%d\n", p);
    free(vet);

    //vetor ao contrario
    int *vet2=malloc(10*sizeof(int));
    for(i=0 ; i<10 ; i++)
    {
        vet2[i] = i+1;
    }
    inverte(10, vet2);
    free(vet2);

    //avalia de polinomios
    
    return 0;
}