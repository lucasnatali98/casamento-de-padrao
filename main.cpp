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
#include "arquivoinvertido.h"
#include "listaencadeada.h"
using namespace std;


typedef struct execucao
{
    int metodo;
    char padrao[200];

}TipoExecucao;

const long qtdarquivos = 1000;

int main(int argc, char *argv[])
{
    using namespace std::chrono;

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


    int linha = 100000;
    int coluna = 20;
    char** nomes = new char*[qtdarquivos]; // Os nomes dos arquivos.
    char vocabulario[100000][20];

    criaNomesVocabulario(vocabulario, 10);
    cout<<"Passou do cria Nomes"<<endl;

    for (int i = 0; i < 10; ++i) {
        cout<<endl;
        for (int j = 0; j < coluna; ++j) {
            cout<<vocabulario[i][j]<<" | ";
        }
    }

    for (int i = 0; i < qtdarquivos; ++i) {
        nomes[i] = new char[9];
        fscanf(filenames, "%s", nomes[i]);
    }

    fclose(filenames);
    Celula* arvore = nullptr;
  //  Celula* aux = nullptr;



    Ocorrencia* ocorrencias = new Ocorrencia[1000000]; // Guarda todas as ocorrências da palavra pesquisada.
    Ocorrencia* ocorrencias2 = new Ocorrencia[1000000];
    int posnovetor = 0; // Quantas ocorrências foram encontradas.

    int comparacoes=0;

    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;
    //FILE* ocorrenciasVocubulario;
    duration<double> total_time;


    //char *aux = new char[100000];
    switch (execucao.metodo) {
    case 1:
        cout << "\n __________________________________________________________";
        cout << "\n Arquivo Invertido \n" << endl;


        Inicializa(arvore);
        cout<<endl<<endl<<endl;

        char palavra[26];
        //char referencia[30];
        char espacoVazio;
        int auxVocabulario;

        for (int i = 0; i < qtdarquivos/250; ++i) {
            colecao = fopen(nomes[i], "r"); //Um arquivo por iteração
            auxVocabulario = 0;
            int lido = 0;  int quantidade = 0, flag=0;
            while ((lido = getc(colecao)) != EOF)
            {
                //Passando os conteúdos dos arquivos para a memória principal
                texto[quantidade] = static_cast<char>(lido);
                quantidade++;
            }


            cout<<"Quantidade apos insercao no texto: "<<quantidade<<endl;
            //quantidade = 0;

            cout<<endl;
            cout<<"Quantidade antes do while: "<<quantidade<<endl;

            while(texto[flag] > 96 && texto[flag] < 123) // caracteres não especiais
            {
                palavra[flag] = texto[flag];
                flag++;
            }

            cout<<"O valor de quantidade: "<<flag<<endl;
            //strcpy(palavra,texto); // Passando conteúdo do texto para
            cout<<"Palavra: "<<palavra<<endl;

            if(pesquisa(arvore, palavra) == nullptr) //Palavra ainda não está na arvore
            {
                arvore = insere(arvore, palavra);
                imprime(arvore);
                cout<<endl;
                //if((ocorrenciasVocubulario = fopen(vocabulario[auxVocabulario], "w+")) == nullptr)
              //  {
                //    exit(1);
              //  }

                //Chamaremos a força bruta para buscar todas as ocorrencias da palavra
                forcaBruta(texto,quantidade,palavra,static_cast<long>(strlen(palavra)), ocorrencias, &posnovetor,
                           i+1, &comparacoes);


                  //  fprintf(ocorrenciasVocubulario, "%d %d\n",ocorrencias[i].numArquivo, ocorrencias[i].posicao);
              }

                //fclose(ocorrenciasVocubulario);
            else
            { // Já existe o registro na árvore
                cout<<"Ja existe a palavra na árvore"<<endl;
                //ocorrenciasVocubulario = fopen(vocabulario[auxVocabulario], "a+");
                forcaBruta(texto,quantidade,palavra,static_cast<long>(strlen(palavra)), ocorrencias, &posnovetor,
                           i+1, &comparacoes);



                //fclose(ocorrenciasVocubulario);
            }


            flag++;
            cout<<"Quantidade (Comparacao caracteres): "<<quantidade<<endl;
            if((texto[flag] > 32 && texto[flag] < 48) && (texto[flag] > 57 && texto[flag] < 65))
            {
                espacoVazio = ' ';
                if(pesquisa(arvore,&espacoVazio)==nullptr)
                {
                    //strcpy(referencia, vocabulario[quantidade]);
                    insere(arvore, &espacoVazio);
                  //  ocorrenciasVocubulario = fopen(vocabulario[auxVocabulario], "w+");
                    //Chamaremos a força bruta para buscar todas as ocorrencias da palavra
                    forcaBruta(texto,quantidade,palavra,static_cast<long>(strlen(palavra)), ocorrencias, &posnovetor,
                               i+1, &comparacoes);


                        //fprintf(ocorrenciasVocubulario, "%d %d\n",ocorrencias[i].numArquivo, ocorrencias[i].posicao);

                    //fclose(ocorrenciasVocubulario);


                }
            }
            flag++;


        }
        cout << "\n Ocorrencias: " << endl << endl;
        for (int i = 0; i < posnovetor; ++i) {
            cout << " Arquivo: " << ocorrencias[i].numArquivo
                 << " | Posicao da ocorrencia: " << ocorrencias[i].posicao << endl;
        }



        deletaTudo(arvore);
        break;
    case 2:
        cout << "\n __________________________________________________________";
        cout << "\n Forca Bruta \n" << endl;

        t1 = high_resolution_clock::now();
        for (int i = 0; i < 4; ++i) {
            colecao = fopen(nomes[i], "r");
            int lido=0;
            int qtd =0;// qtd: define a quantidade de caracteres do texto. lido: caractere que foi lido.
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



        t2 = high_resolution_clock::now();
        total_time = duration_cast<duration<double>>(t2-t1);

        cout<<"Tempo total : "<<total_time.count()<<endl;
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
