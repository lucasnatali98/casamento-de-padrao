#ifndef ARQUIVOINVERTIDO_H
#define ARQUIVOINVERTIDO_H

#include "arvorebinaria.h"
#include "forcabruta.h"

void criaNomesVocabulario(char vocabulario[100000][20], int posicao);
short geraArquivoInvertido(FILE*);
short criaArquivoInvertidoPalavra(FILE*);
short adicionaOcorrencias(FILE*);

#endif // ARQUIVOINVERTIDO_H
