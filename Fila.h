#ifndef FILA_H

#define FILA_H

#include "tad.h"

Fila* criaFila();
int vaziaFila(Fila *fila);
void enqueue(Fila* fila, int valor);
int dequeue(Fila* fila);
int first(Fila* fila);
void destroiFila(Fila *fila);
void printFilaControle(Fila* fila);

//filas novas implementadas
int editFila(Fila *fila, int edit, int val); //edit = valor a ser editado, val = novo valor;
int buscarRemoverFila(Fila *fila, int valor); // val = valor a ser buscado e deletado;
int removerParesFila(Fila *fila);
int removerRepetidoFila(Fila *fila);
int estaNaFila(Fila *fila, int v);


#endif

