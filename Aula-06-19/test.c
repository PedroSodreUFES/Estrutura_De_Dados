#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void rapida (int n, int* v);

int main()
{
    int *v = malloc(100000 * sizeof(int));
    srand(time(NULL));
    for(int i=0 ; i<100000 ; i++)
    {
        v[i] = rand();
    }
    time_t t1, t2;
    t1 = time(0);
    rapida(100000, v);
    int cont =0;  
    for(int i=0 ; i<100000 ; i++)
    {
        printf("%d\n", v[i]);
        if(v[i]==0)
        {
            cont ++;
        }
    }
    printf("numero de zeros: %d\n", cont);     
    free(v);
    return 0;
}

void rapida (int n, int* v)
{   
    if (n <= 1) return;
        else {
            int x = v[0];
            int a = 1;
            int b = n-1;
    do {
        while (a < n && v[a] <= x) a++;
        while (v[b] > x) b--;
        if (a < b) { /* faz troca */
        int temp = v[a];
        v[a] = v[b];
        v[b] = temp;
        a++; b--;
        }
    } while (a <= b);
        /* troca pivô */
        v[0] = v[b];
        v[b] = x;
        /* ordena sub-vetores restantes */
        rapida(b,v);
        rapida(n-a,&v[a]);
    }
}