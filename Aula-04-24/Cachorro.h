#ifndef CACHORRO_H_
#define CACHORRO_H_

#define MANSO 1
#define BRAVO 0

typedef struct cachorro Cachorro;

//Função que alloca o cachorro
//mob = manso ou bravo
Cachorro* inicCachorro(char *nome, int mob);

//
void liberaCachorro(Cachorro *c);

void imprimeCachorro(Cachorro *c);

int EhCachorroManso(Cachorro *c);



#endif