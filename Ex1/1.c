#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int a=1, b=2 , c=3, d=4;
    int *A, *B, *C, *D;
    A = &a;
    B = &b;
    C = &c;
    D = &d;

    printf("Estado das váriaveis anteriormente: a=%d, b=%d, c=%d, d=%d\n\n", a, b, c, d);

    *A = 2;
    *B = 3;
    *C = 4;
    *D = 5;

    printf("Estado das váriaveis posteriormente: a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);

}