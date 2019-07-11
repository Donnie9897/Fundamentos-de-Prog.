#include <stdio.h>
#include <stdlib.h>
#ifndef _Practica.h
#define _Practica.h
#endif // _Practica

typedef struct sNodo
{
    int data;
    struct sNodo *siguiente;
}Nodo;

typedef struct
{
    Nodo *Cabeza;
    int tamano;

}Lista;

Lista* IniciarlizarLista();
void AgregarEnCola(Lista*, int);
void Intercambiar(Nodo *,Nodo *);
