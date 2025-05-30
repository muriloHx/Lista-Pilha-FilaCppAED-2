#include <iostream>
#include "fila.h"
using namespace std;

/*
FUNÇÃO: criaFila
RESUMO: Cria uma nova fila vazia
PARAM: void
RETORNO: Fila* (ponteiro para a fila criada)
*/
Fila* criaFila()
{
    //armazena o espaço para a fila
    Fila* fila = new Fila;
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

/*
FUNÇÃO: vazia
RESUMO: verifica se a fila está vazia
PARAM: Fila* fila (ponteiro para a fila)
RETORNO: int (valor de teste para a condição de vazio)
*/
int vaziaFila(Fila *fila)
{
    if(fila->inicio == NULL)
        return 1;
    else return 0;
}

/*
FUNÇÃO: enqueue
RESUMO: insere elemento no fim da fila
PARAM: Fila* fila (ponteiro para a fila), int valor (valor a ser inserido)
RETORNO: void
*/
void enqueue(Fila* fila, int valor)
{
    Node* novo = new Node;
    novo->info = valor;
    novo->prox = NULL; //inserido no final
    if(vaziaFila(fila))
    {
        fila->inicio = novo;
        fila->fim = novo;
    }
    else
    {
        (fila->fim)->prox = novo;
        fila->fim = novo;
    }
}

/*
FUNÇÃO: dequeue
RESUMO: remove e retorna o elemento do início da fila
PARAM: Fila* fila (ponteiro para a fila)
RETORNO: int (valor removido da fila)
*/
int dequeue(Fila* fila)
{
    Node* aux;
    int valor;
    aux = fila->inicio;
    valor = aux->info;
    fila->inicio = aux->prox;
    //se esvaziou a fila, fila->fim tbm tem que ficar nula
    if(vaziaFila(fila))
        fila->fim = NULL;
    delete(aux);
    return valor;
}

/*
FUNÇÃO: first
RESUMO: retorna o elemento do início da fila
PARAM: Fila* fila (ponteiro para a fila)
RETORNO: int (valor da cabeça da fila)
*/
int first(Fila* fila)
{
    if (!vaziaFila(fila))
        return (fila->inicio)->info;
}

/*
FUNÇÃO: destroiFila
RESUMO: exclui todo conteúdo da fila
PARAM: Fila* (ponteiro para a fila)
RETORNO: nada
*/
void destroiFila(Fila *fila)
{
    while(!vaziaFila(fila))
        dequeue(fila);
}

/*
FUNÇÃO: print
RESUMO: imprime a fila (ERRADO, apenas para controle)
PARAM: Fila* (ponteiro para a fila)
RETORNO: void
*/
void printFilaControle(Fila* fila)
{
    Node* aux = fila->inicio;
    cout << "Início: ";
    while(aux)
    {
        cout << "| " << aux->info << " |-->";
        aux = aux->prox;
    }
    cout << "X" << endl;
}

int editFila(Fila *fila, int edit, int val){ //edita apenas o primeiro que encontrar, nao todos
    if(vaziaFila(fila)){
        return 0;
    }
    Node *aux = fila->inicio;

    while(aux){
        if(aux->info == edit){
            aux->info = val;
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

int buscarRemoverFila(Fila* fila, int valor){ // remove apenas UM elemento, o mais proximo do inicio
    if(vaziaFila(fila)){
        return 0;
    }
    Fila *aux = criaFila();
    int res = 0;
    while(!vaziaFila(fila)){
        if(((fila->inicio)->info != valor) || (res == 1)){
            enqueue(aux, (dequeue(fila)));

        }else{
            res = 1;
            dequeue(fila);
        }

    }
    while(!vaziaFila(aux)){
        enqueue(fila, dequeue(aux));
    }
    return res;
}
int removerParesFila(Fila *fila){
    if(vaziaFila(fila)){
        return 0;
    }
    Fila *aux = criaFila();
    int res = 0;
    while(!vaziaFila(fila)){
        if((fila->inicio)->info % 2 != 0){
            enqueue(aux, dequeue(fila));
        }else{
            dequeue(fila);
            res = 1;
        }
    }
    while(!vaziaFila(aux)){
        enqueue(fila, dequeue(aux));
    }
    return res;
}

int estaNaFila(Fila *fila, int v){
    if(vaziaFila(fila)){
        return 0;
    }
    Fila *aux = criaFila();
    int res = 0, x = 0;
    while(!vaziaFila(fila)){
        x = dequeue(fila);
        if(x == v){
            res = 1;
        }
        enqueue(aux, x);
    }
    while(!vaziaFila(aux)){
        enqueue(fila, dequeue(aux));
    }
    delete aux;
    return res;
}

int removerRepetidoFila(Fila *fila){
    if(vaziaFila(fila)){
        return 0;
    }
    Fila *aux = criaFila();
    int v = 0;
    int res = 0;
    while(!vaziaFila(fila)){
        v = dequeue(fila);
        if(estaNaFila(fila, v)){
            continue;
        }else{
            enqueue(aux, v);
            res = 1;
        }
    }
    while(!vaziaFila(aux)){
        v = dequeue(aux);
        enqueue(fila, v);
    }
    delete aux;
    return res; // se ha algum repetido, se alterou a fila, retorna 1. caso nao, 0.
}




