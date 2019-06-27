#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

typedef struct lista ListaEncadeada;
typedef struct lista_no ListaEncadeadaNo;

ListaEncadeada* criaListaVazia();
void insere_Lista_PrimeiraPosicao(ListaEncadeada* lista, char* elem);
void imprime_Lista(ListaEncadeada* lista);
void insere_Lista_Ordenada(ListaEncadeada* lista, char* elem);
void remove_Lista(ListaEncadeada* lista, char* elem);
int verifica_Lista(ListaEncadeada* lista);
void libera_Lista(ListaEncadeada* lista);
void insere_Lista_Final(ListaEncadeada* lista, char* elem);
void remove_Lista_Final(ListaEncadeada* lista);

ListaEncadeada *busca(ListaEncadeada *lista, char*);


#endif // LISTAENCADEADA_H
