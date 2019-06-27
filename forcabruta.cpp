#include "forcabruta.h"


void forcaBruta(char *texto, long n, char padrao[], long m, Ocorrencia* o, int* posnovetor, int file, int *comparacoes)
{
    //m = tamanho do padrão
    //n = tamanho do texto


    long i,j,k;


    for (i=1;i<=(n-m+1); i++)
    {

        k=i;
        j=1;
        while(texto[k-1] == padrao[j-1] && j<=m)
        {
            (*comparacoes)++;

            j++;
            k++;


        }
        if(j > m){
            o[*posnovetor].posicao = i;
            o[*posnovetor].numArquivo = file;
            *posnovetor += 1;
        }
    }


}
