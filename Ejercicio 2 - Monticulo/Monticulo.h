#include <stdlib.h>

#ifndef _Monticuloh
#define _Monticuloh


typedef struct
{
    int tamano;
    int posicion_actual;
    int altura;
    short esMin;
    float *elementos;

}Monticulo;

Monticulo* Inicializar(short esMin);
void VerificarEspacio(Monticulo *heap);
void Insertar(Monticulo *heap, float elemento);
float GetTop(Monticulo *heap);
float Poll(Monticulo *heap);
void HeapifyUp(Monticulo *heap,int indice);
void HeapifyDown(Monticulo *heap,int Indice);
int IndicePadre(int Indice);
int IndiceHijoIzq(Monticulo *heap,int Indice);
int IndiceHijoDer(Monticulo *heap,int Indice);
void Swap(float *desde,float *hasta);






#endif // _Monticuloh
