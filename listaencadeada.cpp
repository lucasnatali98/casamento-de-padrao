#include "listaencadeada.h"

#include <iostream>

using namespace std;


struct lista{
    lista_no* prim;
};

struct lista_no{
    char* elem;
    lista_no* prox;
};

ListaEncadeada* criaListaVazia(){
    ListaEncadeada* nova_lista = new ListaEncadeada;
    nova_lista->prim = nullptr;
    return nova_lista;
}

void insere_Lista_PrimeiraPosicao(ListaEncadeada* lista, char* elem){
    ListaEncadeadaNo* lista_no = new ListaEncadeadaNo;
    lista_no->elem = elem;
    lista_no->prox = lista->prim;
    lista->prim = lista_no;

}

void imprime_Lista(ListaEncadeada* lista){
    for (ListaEncadeadaNo* i = lista->prim; i != nullptr; i = i->prox){
        cout << i->elem << " ";
    }
    cout <<endl;
}

void insere_Lista_Ordenada(ListaEncadeada* lista, char* elem){
    ListaEncadeadaNo* aux_ant = nullptr;
    ListaEncadeadaNo* prim = lista->prim;

    while(prim != nullptr && prim->elem < elem){
        aux_ant = prim;
        prim = prim->prox;
    }

    ListaEncadeadaNo* novo_no = new ListaEncadeadaNo;
    novo_no->elem = elem;

    if (aux_ant == nullptr){
        insere_Lista_PrimeiraPosicao(lista, elem);
    }
    else{
        novo_no->prox = aux_ant->prox;
        aux_ant->prox = novo_no;
    }
}

void remove_Lista(ListaEncadeada* lista, char* elem){
    ListaEncadeadaNo* aux_ant = nullptr;
    ListaEncadeadaNo* prim = lista->prim;

    while(prim != nullptr && prim->elem != elem){
        aux_ant = prim;
        prim = prim->prox;
    }

    if (prim != nullptr){
        if (aux_ant == nullptr) lista->prim = prim->prox;
        else aux_ant->prox = prim->prox;
    }

    delete [] prim;
}

int verifica_Lista(ListaEncadeada* lista){
    return (lista->prim == nullptr);
}

void libera_Lista(ListaEncadeada* lista){
    ListaEncadeadaNo* prim = lista->prim;
    while(prim != nullptr){
        ListaEncadeadaNo* prox = prim->prox;
        delete prim;
        prim = prox;
    }
}

void insere_Lista_Final(ListaEncadeada* lista, char* elem){
    ListaEncadeadaNo* aux_ant = nullptr;
    ListaEncadeadaNo* prim = lista->prim;

    while(prim != nullptr){
        aux_ant = prim;
        prim = prim->prox;
    }

    ListaEncadeadaNo* novo_no = new ListaEncadeadaNo;
    novo_no->elem = elem;

    if(aux_ant == nullptr) insere_Lista_PrimeiraPosicao(lista, elem);
    else {
        aux_ant->prox = novo_no;
        novo_no->prox = nullptr;
    }
}

//Terminar Remoção final da Lista


void remove_Lista_Final(ListaEncadeada* lista){
    ListaEncadeadaNo* aux_ant = nullptr;
    ListaEncadeadaNo* prim = lista->prim;

    while(prim != nullptr){
        aux_ant = prim;
        prim = prim->prox;
    }

}


ListaEncadeada *busca(ListaEncadeada*lista, char *elem)
{
    if(lista->prim->elem == elem)
            return lista;

        if(lista->prim->prox != nullptr)
            return busca(lista, elem);

        return nullptr;
}
