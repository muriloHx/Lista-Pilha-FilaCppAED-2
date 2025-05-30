#ifndef LISTA_H

#define LISTA_H

//#include "tad.cpp"
#include "tad.h"
Node* criaLista();
int vaziaLista(Node *lista);
Node* insereIniLista(Node* lista, int elem);
void printLista(Node *lista);
Node* removeIniLista(Node *lista);
Node* esvaziarLista(Node *lista);
Node* insereFimLista(Node *lista, int elem);
Node* removeFimLista(Node *lista);
Node* insereOrdLista(Node *lista, int elem);
Node* removeElemLista(Node *lista, int elem);
Node* buscaElementoLista(Node *lista, int elem);
void setElementoLista(Node *pEdit, int edit);
int getElementoLista(Node *pAcess);

//listas novas implementadas
void percorreLista(Node *lista);
int minLista(Node *lista);
int maxLista(Node *lista);
float mediaLista(Node *lista);
int lenLista(Node *lista);
Node* appendLista(Node* L1,Node* L2);
Node* reverseLista(Node* lista);
int isSubLista(Node* L1, Node* L2);
int lenLista(Node *lista);


#endif // LISTA_H
