#include "arquivoinvertido.h"



void criaNomesVocabulario(char vocabulario[100000][20], int posicao)
{
    cout << "entrou cria nome fitas" << endl;
    char aux[1];
    char nome[20];
    for (int i = 0; i < posicao; ++i) {
        int j = i;
        strcpy(nome, "vocabulario");
        itoa(j, aux, 10);
        strcat(nome,aux);
        strcat(nome, ".txt");
        strcpy(vocabulario[i],nome);
    }
    cout<<endl;
}

short geraArquivoInvertido(FILE* colecao)
{

   colecao = fopen("0001.txt", "r");

}
