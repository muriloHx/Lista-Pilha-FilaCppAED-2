#ifndef PILHA_H

#define PILHA_H

//#include "tad.cpp"
#include "tad.h"
Pilha* criaPilha();
int vaziaPilha(Pilha* pilha);
Pilha* push(Pilha* pilha, int valor);
int pop(Pilha* pilha);
int top(Pilha* pilha);
void destroiPilha(Pilha* pilha);
void printPilhaControle(Pilha* pilha);

//pilhas novas implementadas
int buscaElemPilha(Pilha *pilha, int elm);
void removeElemPilha(Pilha *pilha, int elm);
void removeParesPilha(Pilha *pilha);
void removeRepetidoPilha(Pilha *pilha);
int estaNaPilha(Pilha *pilha, int valor);
Pilha* copiarPilha(Pilha* original);

#endif // PILHA_H
