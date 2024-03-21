#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tMercado.h"

struct _tMercado{
    char *nome;
    void  **filiais;
    int nfiliais;
};

struct _RedesDeMercados
{
    void **mercados;
    int nmercados;
};

tMercado *allocaMercado()
{
    tMercado *m = malloc(sizeof(tMercado));
    char nome[100];
    printf("Digite o nome do novo mercado: ");
    scanf("%[^\n]%*c", nome);
    m->nome = malloc((strlen(nome)+1)*sizeof(char));
    strcpy(m->nome, nome);
    m->filiais=NULL;
    m->nfiliais=0;
}

int obtemFiliaisDoMercado(tMercado *m)
{
    return m->nfiliais;
}

void liberaMercado(tMercado *m)
{
    int i;
    for(i=0 ; i<obtemFiliaisDoMercado(m) ; i++)
    {
        liberaFilial(m->filiais[i]);
    }
    if(m->filiais!=NULL)
    {
        free(m->filiais);
    }
    if(m->nome!=NULL)
    {
        free(m->nome);
    }
    if(m!=NULL)
    {
        free(m);
    }
}

char *retornaNomeDoMercado(tMercado *m)
{
    return m->nome;
}

void addFilial(tMercado *m, void *f)
{
    m->nfiliais++;
    m->filiais = realloc(m->filiais, obtemFiliaisDoMercado(m)*sizeof(void*));
    m->filiais[obtemFiliaisDoMercado(m)-1]=f;
}

int MercadoExiste(RedesDeMercados *r, char *nome)
{
    int i;
    for(i=0 ; i<obtemNumeroDeMercados(r) ; i++)
    {
        if(strcmp(retornaNomeDoMercado(r->mercados[i]), nome)==0)
        {
            return i;
        }
    }
    printf("O mercado com o nome ""%s"" não foi encontrado em nossa base de dados\n", nome);
    return -1;
}

RedesDeMercados *allocaRedesDeMercados()
{
    RedesDeMercados *r = malloc(sizeof(RedesDeMercados));
    r->mercados=NULL;
    r->nmercados=0;
}

void liberaRedeDeMercados(RedesDeMercados *r)
{
    int i;
    for(i=0 ; i<obtemNumeroDeMercados(r) ; i++)
    {
        liberaMercado(r->mercados[i]);
    }
    if(r->mercados!=NULL)
    {
        free(r->mercados);
    }
    if(r!=NULL)
    {
        free(r);
    }
}

void addMercado(RedesDeMercados *r, void *m)
{
    r->nmercados++;
    r->mercados = realloc(r->mercados,obtemNumeroDeMercados(r)*sizeof(void*));
    r->mercados[obtemNumeroDeMercados(r)-1]=m;
}

int obtemNumeroDeMercados(RedesDeMercados *r)
{
    return r->nmercados;
}

int obtemEstoqueDoMercado(tMercado *m)
{
    int estoque=0, i;
    for(i=0 ; i<obtemFiliaisDoMercado(m) ; i++)
    {
        estoque += obtemEstoqueFilial(m->filiais[i]);
    }
    return estoque;
}

void fazResumoGeral(RedesDeMercados *r)
{
    int i, j;
    tMercado *m;
    for(i=0 ; i<obtemNumeroDeMercados(r); i++)
    {
        m = (tMercado*)r->mercados[i];
        printf("Nome: %s, Estoque Total: %d\n", retornaNomeDoMercado(m), obtemEstoqueDoMercado(m));
        if(obtemFiliaisDoMercado(m)==0)
        {
            printf("\tMercado sem filiais\n");
            continue;
        }
        for(j=0 ; j<obtemFiliaisDoMercado(m) ; j++)
        {
            fazResumoFilial(m->filiais[j]);
        }
    }
}

void menuMercados(RedesDeMercados *r)
{
    int opcao, indice;
    char nome[100];
    while(1)
    {
        printaMenuMercados();
        scanf("%d%*c", &opcao);
        if(opcao==1)
        {
            tMercado *m = allocaMercado();
            addMercado(r, m);
            printf("Mercado registrado com sucesso\n\n");
        }
        else if(opcao==2)
        {
            printf("Digite o nome do mercado que deseja encontrar: ");
            scanf("%[^\n]%*c", nome);
            indice = MercadoExiste(r, nome);
            if(indice>=0)
            {
                printf("\n");
                menuMercado(r->mercados[indice]);
            }
        }
        else if(opcao==3)
        {
            printf("Encerrando o programa!\n\n");
            fazResumoGeral(r);
            break;
        }
    }
}

void printaMenuMercados()
{
    printf("Digite:\n\t1- para registrar um novo mercado no sistema\n\t2- para averiguar um mercado que já exista\n\t3- para imprimir o relatório geral e sair do programa\nDigite uma opcao: ");
}

void menuMercado(tMercado *m)
{
    int opcao, indice, i;
    char nome[100];
    printf("Voce está vendo informações do mercado %s\n\n", retornaNomeDoMercado(m));
    while(1)
    {
        printaMenuMercado();
        scanf("%d%*c", &opcao);
        if(opcao==1)
        {
            tFilial *f = alocaFilial();
            addFilial(m, f);
            printf("Filial registrada com sucesso\n\n");
        }
        else if(opcao==2)
        {
            printf("Digite o nome da filial que deseja encontrar: ");
            scanf("%[^\n]%*c", nome);
            indice = FilialExiste(m, nome);
            if(indice>=0)
            {
                printf("\n");
                menuFilial(m->filiais[indice]);
            }
        }
        else if(opcao==3)
        {
            printf("Digite o nome da filial que deseja encontrar: ");
            scanf("%[^\n]%*c", nome);
            indice = FilialExiste(m, nome);
            if(indice>=0)
            {
                fazResumoFilial(m->filiais[indice]);
                printf("\n");
            }
        }
        else if(opcao==4)
        {
            printf("Voltando ao menu de todos os mercados\n\n");
            break;
        }
        else if(opcao==5)
        {
            printf("\n");
            printf("Nome: %s, Estoque Total: %d\n", retornaNomeDoMercado(m), obtemEstoqueDoMercado(m));
            if(obtemFiliaisDoMercado(m)==0)
            {
                printf("\tMercado sem filiais\n");
                continue;
            }
            for(i=0 ; i<obtemFiliaisDoMercado(m) ; i++)
            {
                fazResumoFilial(m->filiais[i]);
            }
        }
    }
}

void printaMenuMercado()
{
    printf("Digite:\n\t1- para registrar uma nova filial no mercado\n\t2- para averiguar uma filial que já exista\n\t3- para imprimir informaçoes sobre o estoque de uma filial\n\t4- para voltar\n\t5- para ver informacoes do mercado atual\n\tDigite uma opcao: ");
}

int FilialExiste(tMercado *m, char* nome)
{
    int i;
    for(i=0 ; i<obtemFiliaisDoMercado(m) ; i++)
    {
        if(strcmp(obtemNomeFilial(m->filiais[i]), nome)==0)
        {
            return i;
        }
    }
    printf("A filial com o nome ""%s"" não foi encontrado em nossa base de dados\n\n", nome);
    return -1;
}


