#include "arvore.h"

int main()
{
    int matricula;
    tArvore *raiz=NULL;
    
    while(scanf("%d", &matricula)==1)
    {
        printf("antes");
        tAluno *a = inicAluno(NULL, matricula);
        tArvore *no = inicializaArvore(a);
        insereArvore(raiz, no);
        printf("fui");
    }

    tAluno *a = buscaAluno(raiz, 120);
    if(a == NULL)
    {
        printf("Student not found\n");
    }
    else
    {
        printf("Student has been found with this reguster number: %d\n", retornaMatricula(a));
    }
    liberaArvore(raiz);
    return 0;
}