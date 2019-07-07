#include <stdlib.h>
#ifndef _Colah
#define _Colah

typedef struct
{
    float *elementos;
    int tamano;
    int primerIndice;
    int ultimoIndice;
    int cantidad;
}Cola;

Cola* InicializarCola();
short isEmpty(Cola *cola);
float getFront(Cola *cola);
void enqueue(Cola *cola,float);
float dequeue(Cola *cola);
void VerificarEspacio(Cola *cola);
int TamanoCola(Cola *cola);
#endif // _Colah
