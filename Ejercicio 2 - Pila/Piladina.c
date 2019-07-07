#include <stdio.h>
#include <string.h>
#include "Pilahea.h"

const int TAM = 10;

Pila* IniciarPila()
{
    Pila *nuevapila = (Pila*)malloc(sizeof(Pila));
    nuevapila->Posicionactual = 0;
    nuevapila->tamanopila = TAM;
    nuevapila->Pila = (float*)malloc(TAM* sizeof(float));
    return nuevapila;

}

void Verificarespacio(Pila *pila)
{
    if ((pila->Posicionactual + 1) < pila->tamanopila)
        return;

    pila->Pila  = (float*)realloc(pila->Pila, pila->tamanopila + TAM);
    pila->tamanopila = pila->tamanopila + TAM;
}

void Push(Pila *pila,float elemento)
{
    Verificarespacio(pila);
    *(pila->Pila+pila->Posicionactual) = elemento;
    pila->Posicionactual++;

}

float Pop(Pila *pila)
{
    float valor = *(pila->Pila+pila->Posicionactual-1);
    pila->Posicionactual--;
    return valor;
}

int Size (Pila *pila)
{
    return pila->Posicionactual;
}


short isEmpty(Pila *pila)
{
    return pila -> Posicionactual == 0;
}

float Peek(Pila *pila)
{
    float valor = Pop(pila);
    Push(pila,valor);
    return valor;
}
