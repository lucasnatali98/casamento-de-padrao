#include "arquivoinvertido.h"


short criaArquivoInvertidoPalavra(FILE* arq, char vocabulario[100000][20], int i, int quantidade,
       char* texto, long n, char padrao[], long m, Ocorrencia*o, int* posnovetor,
        int file, int *comparacoes)
{
    //i = Posição do nome
    if((arq = fopen(vocabulario[i], "w")) == nullptr)
    {
        exit(1);
    }

    forcaBruta(texto,n, padrao,m, o, posnovetor,file, comparacoes);
    fprintf(arq, "%d", o->posicao);
    return 1;
}

short adicionaOcorrencias()
{
    return 1;
}
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
