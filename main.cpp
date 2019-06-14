#include <iostream>
#include <cstring>
#include "forcabruta.h"

using namespace std;

typedef struct execucao
{
    int metodo;
    char padrao[200];

}TipoExecucao;


int main(int argc, char *argv[])
{

    TipoExecucao execucao;
    if(argc < 2 || argc > 3)
    {
        cout<<"Quantidade de argumentos errada, tente novamente \n";
        exit(1);
    }

    execucao.metodo = atoi(argv[1]); cout<<"Metodo: "<<execucao.metodo<<endl;

    strcpy(execucao.padrao, argv[2]); cout<<"Padrao: "<<execucao.padrao<<endl;



    char *texto;



    FILE *colecao1;
    if((colecao1 = fopen("0001.txt","r")) == nullptr)
    {
        cout<<"Nao foi possivel abrir o arquivo \n";
        exit(1);
    }


    int j=0;

    while(fscanf(colecao1,"%[A-Z a-z %-%.%,%;]\n", texto) != EOF)
    {
        j++;

        //forcaBruta(texto, 20, execucao.padrao, 8);
        cout<<texto<<"|";
    }
    cout<<endl;

   cout<<texto[0]<<endl;



    switch(execucao.metodo)
    {
        case 1:
            cout<<"Arquivo invertido"<<endl;
        break;
    case 2:
            cout<<"Forca Bruta"<<endl;
        break;
    default:
        exit(1);

    }



    return 0;
}
