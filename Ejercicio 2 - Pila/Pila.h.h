// definir variables
#include <stdlib.h>
#include ""
#ifndef _piladisnamica
#define _piladisnamica

 typedef struct
{
    int tamanopila;
    float *Pila;
    int Posicionactual;
}Pila;

Pila* IniciarPila();
void Push(Pila*,float);
void Verificarespacio(Pila*);
float Pop(Pila*);
int Size (Pila*);
short isEmpty(Pila*);
float Peek(Pila*);

#endif // _piladisnamica

