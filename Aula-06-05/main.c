#include <stdio.h>
#include <stdlib.h>
#include "tCelula.h"

int main()
{
    tCelula *fila = allocaCelula();
    insereNaFila(fila, NULL);
    insereNaFila(fila, NULL);
    insereNaFila(fila, NULL);
    insereNaFila(fila, NULL);
    insereNaFila(fila, NULL);
    imprimeFila(fila);
    desalocaFila(fila);
    return 0;
}