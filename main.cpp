#include <iostream>
#include <cstring>
#include <string>
#include <time.h>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <chrono>

#include "forcabruta.h"
#include "arvorebinaria.h"

using namespace std;
using namespace std::chrono;

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
        cout<<" \n Quantidade de argumentos errada, tente novamente \n";
        exit(1);
    }

    execucao.metodo = atoi(argv[1]); cout<<"\n Metodo: "<<execucao.metodo<<endl;

    if(argc == 3) {
       strcpy(execucao.padrao, argv[2]);
       cout << "\n -> Padrao: " << execucao.padrao << endl;
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
    Celula* arvore = nullptr;
    char* flag;
    double tempoTotal;
    Ocorrencia* ocorrencias = new Ocorrencia[100000]; // Guarda todas as ocorrências da palavra pesquisada.
    int posnovetor = 0; // Quantas ocorrências foram encontradas.


     clock_t tempoInicial;
     clock_t tempoFinal;
     int comparacoes=0;


    char *aux = new char[100000];
    switch (execucao.metodo) {
    case 1:
        cout << "\n __________________________________________________________";
        cout << "\n Arquivo Invertido \n" << endl;
        Inicializa(arvore);
        arvore = insere(arvore, "nada");
        insere(arvore, "ronaldo");
        insere(arvore, "coisa");
        insere(arvore, "pipa");
        insere(arvore, "xinelo");
        pesquisa(arvore, execucao.padrao);

        imprime(arvore);
        cout<<endl<<endl;


         //for (int i = 0; i < qtdarquivos; i++){
           // colecao = fopen(nomes[i], "r");
            //while(fscanf(colecao,"%[A-Za-z]"))
        //}
        deletaTudo(arvore);
        break;
    case 2:
        cout << "\n __________________________________________________________";
        cout << "\n Forca Bruta \n" << endl;
        tempoInicial = clock();

        for (int i = 0; i < qtdarquivos; ++i) {
            colecao = fopen(nomes[i], "r");
            int lido, qtd = 0; // qtd: define a quantidade de caracteres do texto. lido: caractere que foi lido.
            while ((lido = getc(colecao)) != EOF) {
                texto[qtd] = static_cast<char>(lido);
                //cout<<texto[qtd]<<" | ";
                qtd++;
            }
            /*
             * . Posnovetor  ->  quantidade de ocorrências encontradas.
             * . i+1         ->  define a numeração do arquivo.
            */
            forcaBruta(texto, qtd, execucao.padrao, static_cast<long>(strlen(execucao.padrao)), ocorrencias, &posnovetor, i+1, &comparacoes);

        }
        tempoFinal = clock();

        tempoTotal = tempoFinal - tempoInicial;
        cout<<"Tempo total: "<<((static_cast<double>(tempoTotal))/CLOCKS_PER_SEC)<<" segundos"<<endl;
        cout<<"Quantidade de comparacoes: "<<comparacoes<<endl;

        cout << "\n Ocorrencias: " << endl << endl;
        for (int i = 0; i < posnovetor; ++i) {
            cout << " Arquivo: " << ocorrencias[i].numArquivo << " | Posicao da ocorrencia: " << ocorrencias[i].posicao << endl;
        }
        cout << "\n Total de ocorrencias: " << posnovetor << endl;
        break;
    default:

        exit(1);
    }


    // deletando os nomes...

    for (int i = 0; i < qtdarquivos; ++i) {
        delete [] nomes[i];
    }
    delete [] nomes;


    delete [] ocorrencias;


    delete [] texto;


    return 0;
}
