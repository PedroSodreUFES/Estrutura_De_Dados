#ifndef GATO_H_
#define GATO_H_

#define MANSO 1
#define BRAVO 0

typedef struct gato Gato;

//Função que alloca o gato
//mob = manso ou bravo
Gato* inicGato(char *nome, int mob);

//
void liberaGato(Gato *g);

void imprimeGato(Gato *g);

int EhGatoManso(Gato *g);


#endif