#include <iostream>
#include <string.h>

using namespace std;

typedef struct execucao
{
    int metodo;
    string padrao;

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
    execucao.padrao = argv[2]; cout<<"Padrao: "<<execucao.padrao<<endl;



    if(execucao.metodo == 1)
    {
        cout<<"Arquivo Invertido"<<endl;
    }
    else
    {
        cout<<"Metodo Invalido \n";
        exit(1);
    }




    return 0;
}
