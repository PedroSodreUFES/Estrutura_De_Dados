#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

struct indicepilha{
int Topo, Base;
};

struct tipopilhadupla{
    TipoItem* Item[MaxTam];
    IndicePilha Pilha1, Pilha2;
};

TipoPilhaDupla *allocaPilhaDupla()
{
    TipoPilhaDupla* p = (TipoPilhaDupla*) malloc (sizeof (TipoPilhaDupla));
    p->Pilha1.Base = 0;
    p->Pilha1.Topo = -1; /* cresce para a direita */
    p->Pilha2.Base = MaxTam -1;
    p->Pilha2.Topo = MaxTam; /* cresce para a esquerda */
    return p;
}

void EmpilhaPilha1(TipoPilhaDupla *p, TipoItem *i)
{
    p->Pilha1.Topo++;
    if(p->Pilha1.Topo<p->Pilha2.Topo)
    {
        p->Item[p->Pilha1.Topo]=i;
    }
    else
    {
        printf("Pilha 1 Atigiu o máximo\n");
        p->Pilha1.Topo--;
    }
}

void EmpilhaPilha2(TipoPilhaDupla *p, TipoItem *i)
{
    p->Pilha2.Topo--;
    if(p->Pilha2.Topo>p->Pilha1.Topo)
    {
        p->Item[p->Pilha2.Topo]=i;
    }
    else
    {
        printf("Pilha 2 Atigiu o máximo\n");
        p->Pilha2.Topo++;
    }
}

TipoItem *DesempilhaPilha1(TipoPilhaDupla *p)
{
    if(p->Pilha1.Topo >= p->Pilha1.Base)
    {
        TipoItem *i = p->Item[p->Pilha1.Topo];
        p->Pilha1.Topo--;
        return i;
    }
    else
    {
        printf("Pilha1 está vazia\n");
        return NULL;
    }
}

TipoItem *DesempilhaPilha2(TipoPilhaDupla *p)
{
    if(p->Pilha2.Topo <= p->Pilha2.Base)
    {
        TipoItem *i = p->Item[p->Pilha2.Topo];
        p->Pilha2.Topo++;
        return i;
    }
    else
    {
        printf("Pilha2 está vazia\n");
        return NULL;
    }
}

TipoItem *allocaItem()
{
    int p;
    scanf("%d", &p);
    TipoItem *item = malloc(sizeof(TipoItem));
    *(item)=p;
    return item;
}

void ImprimePilha(TipoPilhaDupla *p)
{
    int i;
    TipoItem *j;
    printf("Imprimindo Pilha 1\n");
    {
        for(i=0 ; i<=p->Pilha1.Topo ; i++)
        {
            j=p->Item[i];
            printf("%d ", j[0]);
        }
        printf("\n");
    }
    printf("Imprimindo Pilha 2\n");
    {
        for(i=MaxTam ; i>=p->Pilha2.Topo ; i--)
        {
            j=p->Item[i];
            printf("%d ", j[0]);
        }
        printf("\n");
    }
}


