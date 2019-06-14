#include <iostream>
#include <cstring>
#include <string>
#include "forcabruta.h"

using namespace std;

typedef struct execucao
{
    int metodo;
    char padrao[200];

}TipoExecucao;

const long qtdarquivos = 1000;

int main(int argc, char *argv[])
{

    TipoExecucao execucao;
    if(argc < 3 || argc > 4)
    {
        cout<<"Quantidade de argumentos errada, tente novamente \n";
        exit(1);
    }

    execucao.metodo = atoi(argv[1]); cout<<"Metodo: "<<execucao.metodo<<endl;

    if(argc == 3) {
       strcpy(execucao.padrao, argv[2]);
       cout << " Padrao c 2 param: " << execucao.padrao << endl;
    }

    FILE* colecao; // Arquivo atualmente aberto.
    FILE* filenames = fopen("nomes.txt", "r"); // Abre arquivo que tem a lista de nomes.
    char* texto = new char[1000000]; // Guarda o conteúdo de cada arquivo.

    char** nomes = new char*[qtdarquivos]; // Os nomes dos arquivos.
    for (int i = 0; i < qtdarquivos; ++i) {
        nomes[i] = new char[9];
        fscanf(filenames, "%s", nomes[i]);
    }
    fclose(filenames);

    Ocorrencia* ocorrencias = new Ocorrencia[100000]; // Guarda todas as ocorrências da palavra pesquisada.
    int posnovetor = 0; // Quantas ocorrências foram encontradas.

    switch (execucao.metodo) {
    case 1:
        cout << "\n __________________________________________________________";
        cout << "\n Arquivo Invertido \n" << endl;
        break;
    case 2:
        cout << "\n __________________________________________________________";
        cout << "\n Forca Bruta \n" << endl;

        for (int i = 0; i < qtdarquivos; ++i) {
            colecao = fopen(nomes[i], "r");
            int lido, qtd = 0; // qtd: define a quantidade de caracteres do texto. lido: caractere que foi lido.
            while ((lido = getc(colecao)) != EOF) {
                texto[qtd] = static_cast<char>(lido);
                qtd++;
            }
            /*
             * . Posnovetor  ->  quantidade de ocorrências encontradas.
             * . i+1         ->  define a numeração do arquivo.
            */
            forcaBruta(texto, qtd, execucao.padrao, static_cast<long>(strlen(execucao.padrao)), ocorrencias, &posnovetor, i+1);
            fclose(colecao);
        }

        cout << "\n Ocorrencias: " << endl << endl;
        for (int i = 0; i < posnovetor; ++i) {
            cout << " Arquivo: " << ocorrencias[i].numArquivo << " | Posicao da ocorrencia: " << ocorrencias[i].posicao << endl;
        }
        break;
    default:
        exit(1);
    }

    cout << "\n chegou aqui" << endl;
    // deletando os nomes...

    for (int i = 0; i < qtdarquivos; ++i) {
        delete [] nomes[i];
    }
    delete [] nomes;
    cout << "\n chegou aqui n" << endl;

    delete [] ocorrencias;
    cout << "\n chegou aqui o" << endl;

    delete [] texto;
    cout << "\n chegou aqui t" << endl;

    return 0;
}
