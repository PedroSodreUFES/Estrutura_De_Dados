#include "aula12.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14

void calc_esfera (float r, float* area, float* volume)
{
    float a, v, *c;
    a = 4 * PI * r * r;
    v = 4 * PI * r * r *r / 3;
    *area = a;
    *volume = v;
    printf("Area:%.2f,  Volume:%.2f\n", *area, *volume);
}

int raizes(float a, float b, float c, float* x1, float* x2)
{
    float delta;
    delta = (b*b) - (4*a*c);
    if(delta<0)
    {
        printf("Equacao nao apresenta raizes\n");
        return 0;
    }
    *x1 = (-b + sqrt(delta))/2*a;
    *x2 = (-b - sqrt(delta))/2*a;
    printf("A fórmula apresenta raizes, tais que raiz 1:%.2f e raiz 2:%.2f\n", *x1, *x2);
    return 1;
}

int pares (int n, int* vet)
{
    int pares=0, i;
    printf("vetor: {");
    for(i=0 ; i<n ; i++)
    {
        printf("%d, ", vet[i]);
    }
    printf("}\n");
    for(i=0; i<n ; i++)
    {
        if(vet[i]%2==0)
        {
            pares++;
        }
    }
    return pares;
}

void inverte (int n, int*vet)
{
    int i;
    int salvavalor;
    printf("vetor antigo: {");
    for(i=0 ; i<n ; i++)
    {
        printf("%d, ", vet[i]);
    }
    printf("}\n");
    for(i=0 ; i<n/2 ; i++)
    {
        salvavalor = vet[i];
        vet[i] = vet[n-1-i];
        vet[n-1-i] = salvavalor;
    }
    printf("vetor novo: {");
    for(i=0 ; i<n ; i++)
    {
        printf("%d, ", vet[i]);
    }
    printf("}\n");
}

double avalia (double* poli, int grau, double x)
{
    
}