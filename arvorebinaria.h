#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include <cstring>

typedef struct celula Celula;

void Inicializa(Celula*);
Celula* criaCelula(char*, char*);
Celula* insere(Celula*, char*);
Celula* pesquisa(Celula*, char*);
void imprime(Celula*);
void deletaTudo(Celula*);

#endif // ARVOREBINARIA_H
