#ifndef FORCABRUTA_H
#define FORCABRUTA_H
#include <iostream>
#include <cstring>

typedef struct ocorrencias{
    int numArquivo;
    int posicao;
}Ocorrencia ;

using namespace std;

void forcaBruta(char*, long n, char[], long m, Ocorrencia*, int* posnovetor, int file);
#endif // FORCABRUTA_H
