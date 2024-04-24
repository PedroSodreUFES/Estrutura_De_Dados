#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tMercado.h"

int main()
{
    RedesDeMercados *r = allocaRedesDeMercados();
    menuMercados(r);
    liberaRedeDeMercados(r);
    return 0;
}
