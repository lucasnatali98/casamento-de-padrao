#include "arvorebinaria.h"
#include "iostream"
using namespace std;

struct celula{
    char nome[30];
    char referencia[30];
    Celula* esquerda = nullptr;
    Celula* direita = nullptr;
};

void Inicializa(Celula *raiz)
{
    raiz = nullptr;
}

Celula *criaCelula(char* nome)
{
    Celula* nova = new Celula;

    strcpy(nova->nome, nome);

    nova->esquerda = nullptr;
    nova->direita = nullptr;

    return nova;
}

Celula *insere(Celula *cel, char *chave)
{
    if(cel == nullptr) return criaCelula(chave);

    if(strcmp(chave, cel->nome) < 0)
    {
        cel->esquerda = insere(cel->esquerda, chave);
    }
    else if(strcmp(chave, cel->nome) > 0)
        cel->direita = insere(cel->direita, chave);

    return cel;
}

Celula *pesquisa(Celula *cel, char *chave)
{
    if(cel == nullptr)
    {
        cout<<"Não tem nada na arvore"<<endl;
        return nullptr;
    }
    if(strcmp(cel->nome, chave) == 0){
     cout<<cel->nome<<" | ";
     return cel; // strings iguais
    }
    if(strcmp(chave, cel->nome) < 0) return pesquisa(cel->esquerda, chave); // caractere que difere é menor em chave.
    if(strcmp(chave, cel->nome) > 0) return pesquisa(cel->direita, chave); // caractere que difere é maior em chave.

    return nullptr;
}

void imprime(Celula *impressor)
{
    if(impressor != nullptr){
        imprime(impressor->esquerda);
        cout << impressor->nome << " | ";
        imprime(impressor->direita);

    }
}

void deletaTudo(Celula *apagador)
{
    if(apagador != nullptr){
        deletaTudo(apagador->esquerda);
        deletaTudo(apagador->direita);
        delete apagador;
    }
}


