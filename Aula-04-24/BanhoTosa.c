#include "BanhoTosa.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct banhotosa{
    char *nome;
    tLista *animais;
};

BanhoTosa* inicBanhoTosa(char* nome)
{
    char *n;
    BanhoTosa *b = malloc(sizeof(BanhoTosa));
    b->animais = allocaLista();
    n = malloc(sizeof(char)*(strlen(nome)+1));
    n = strcpy(n, nome);
    b->nome = n;
    return b;
}

void cadastraCachorro(BanhoTosa* loja, Cachorro* dog)
{
    tCelula *c = allocaCelula();
    atribuiAnimal(c, dog);
    EhCachorro(c);
    insereCelulaLista(c, loja->animais);
}

void cadastraGato(BanhoTosa* loja, Gato* cat)
{
    tCelula *c = allocaCelula();
    atribuiAnimal(c, cat);
    EhCachorro(c);
    insereCelulaLista(c, loja->animais);
}

void imprimeBanhoTosa(BanhoTosa* loja)
{
    imprimeLista(loja->animais);
}

float calculaReceita(BanhoTosa* loja)
{
    float receita=0;
    tCelula *p= retornaprim(loja->animais);
    while(p != NULL)
    {
        if(catOrDOG(p))
        {
            if(EhCachorroManso(retornaAnimal(p)))
            {
                receita +=40;
            }
            else
            {
                receita += 45;
            }
        }
        else
        {
            if(EhGatoManso(retornaAnimal(p)))
            {
                receita += 30;
            }
            else
            {
                receita += 35;
            }
        }
        p = retornaProxCelula(p);
    }
    return receita;
}

void liberaBanhoTosa(BanhoTosa* loja)
{
    liberaLista(loja->animais);
    if(loja->nome!=NULL)
    {
        free(loja->nome);
    }
    if(loja!=NULL)
    {
        free(loja);
    }
}

void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat)
{
    return;
}

void atualizaSituacaoCachorro(BanhoTosa* loja, Cachorro* dog)
{
    return;
}
