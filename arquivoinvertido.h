#ifndef ARQUIVOINVERTIDO_H
#define ARQUIVOINVERTIDO_H

#include "arvorebinaria.h"
#include "forcabruta.h"

void criaNomesVocabulario(char vocabulario[100000][20], int posicao);
short geraArquivoInvertido(FILE*);

#endif // ARQUIVOINVERTIDO_H
