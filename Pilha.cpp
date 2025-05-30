#include <iostream>
#include "tad.h"
using namespace std;

/*
FUNÇÃO: criaPilha
RESUMO: Cria uma nova pilha vazia
PARAM: void
RETORNO: Pilha* (ponteiro para a pilha);
*/
Pilha* criaPilha()
{
    Pilha* p = new Pilha;
    p->topo = NULL;
    return p;
}

/*
FUNÇÃO: vazia
RESUMO: verifica se a pilha está vazia
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: int (1 se está vazia, 0 se não está)
*/
int vaziaPilha(Pilha* pilha)
{
    if( pilha->topo == NULL)
        return 1;
    else return 0;
}

/*
FUNÇÃO: push
RESUMO: empilha novo elemento na pilha
PARAM: Pilha* (ponteiro para a pilha), int (valor a ser empilhado);
RETORNO: Pilha* (ponteiro para a pilha);
*/
Pilha* push(Pilha* pilha, int valor)
{
    Node* novo = new Node;
    novo->info = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    return pilha;
}

/*
FUNÇÃO: pop
RESUMO: desempilha o elemento no topo da pilha e retorna seu valor
PARAM: Pilha* (ponteiro para a pilha), int (valor a ser desempilhado);
RETORNO: Pilha* (ponteiro para a pilha);
*/
int pop(Pilha* pilha)
{
    Node* aux = pilha->topo;
    int valor;
    if(!vaziaPilha(pilha))
    {
        valor = aux->info;
        pilha->topo = (pilha->topo)->prox;
        delete aux;
    }
    else cout << "pilha vazia!" << endl;
    return valor;
}

/*
FUNÇÃO: top
RESUMO: informa o valor do primeiro elemento da pilha
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: int (valor da informação do nó armazenado no topo)
*/
int top(Pilha* pilha)
{
    if (!vaziaPilha(pilha))
        return (pilha->topo)->info;
    else cout << "pilha vazia!";
}

/*
FUNÇÃO: destroiPilha
RESUMO: exclui todo conteúdo da pilha
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: nada
*/
void destroiPilha(Pilha* pilha)
{
    while (!vaziaPilha(pilha))
        pop(pilha);
    cout << "pilha destruída com sucesso!" << endl;
}
/*
FUNÇÃO: print
RESUMO: imprime a pilha
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: void
*/
void printPilhaControle(Pilha* pilha)
{
    Node* aux = pilha->topo;
    cout << "____" << endl;
    while(aux)
    {
        cout << "| " << aux->info << " |\n"<< "____" << endl;
        aux = aux->prox;
    }
    cout << "X" << endl;
}

int buscaElemPilha(Pilha *pilha, int elm)
{
    Node *aux = pilha->topo;
    while(aux){
        if(aux->info == elm){
            return elm;
        }
        aux = aux->prox;
    }
    return NULL;
}

void removeElemPilha(Pilha *pilha, int elm){
    Pilha aux;
    aux.topo = nullptr;
    int v = 0;
    while(!vaziaPilha(pilha)){
        v = pop(pilha);
        if(v == elm){
            break;
        }
        push(&aux, v);
    }
    while(!vaziaPilha(&aux)){
        v = pop(&aux);
        push(pilha, v);
    }
}

void removeParesPilha(Pilha *pilha){
    Pilha *aux = criaPilha();
    int v = 0;
    while(!vaziaPilha(pilha)){
        v = pop(pilha);
        if(v % 2 != 0){
            push(aux, v);
        }
    }
    while(!vaziaPilha(aux)){
        v = pop(aux);
        push(pilha, v);
    }
    delete aux;
}

Pilha* copiarPilha(Pilha* original) {
    Pilha* copia = criaPilha();
    Pilha* aux = criaPilha();

    // Desempilha da original para a auxiliar (inverte a ordem)
    while(!vaziaPilha(original)) {
        push(aux, pop(original));
    }

    // Reempilha na original e na cópia (restaura a ordem)
    while(!vaziaPilha(aux)) {
        int valor = pop(aux);
        push(original, valor);
        push(copia, valor);
    }

    delete aux;
    return copia;
}

int estaNaPilha(Pilha *pilha, int valor){
    Pilha *aux = criaPilha();
    int x = 0;
    int res = 0;
    while(!vaziaPilha(pilha)){
        x = pop(pilha);
        push(aux, x);
        if(x == valor){
            res = 1;
            break;
        }
    }
    while(!vaziaPilha(aux)){
        push(pilha, pop(aux));
    }
    delete aux;
    return res;
}

void removeRepetidoPilha(Pilha *pilha){ //remove os que foram inseridos por ultimo, mais proximos do topo
    Pilha *aux = criaPilha();
    int v = 0;
    while(!vaziaPilha(pilha)){
       v = pop(pilha);
       if(!estaNaPilha(pilha, v)){
            push(aux,v);

       }
    }
        while(!vaziaPilha(aux)){
        push(pilha, pop(aux));
    }
}


