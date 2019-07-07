#include <stdlib.h>
#include <math.h>
#include "Monticulo.h"
const int ALTURA = 10;

Monticulo* Inicializar(short esMin)
{
    Monticulo *nuevoHeap = (Monticulo*)malloc(sizeof(Monticulo));
    nuevoHeap->tamano = pow(2,ALTURA) - 1;
    nuevoHeap->altura = ALTURA;
    nuevoHeap->esMin = esMin;
    nuevoHeap->posicion_actual = 0;
    nuevoHeap->elementos =(float*)calloc(nuevoHeap->altura,sizeof(float));

    return nuevoHeap;
}

void VerificarEspacio(Monticulo *heap)
{

    if(heap->posicion_actual < heap->tamano)
        return;

    heap->altura++;
    heap->tamano = pow(2,heap->altura);
    heap->elementos = (float*)realloc(heap->elementos,heap->tamano);

}
void Insertar(Monticulo *heap, float elemento)
{
    VerificarEspacio(heap);

    *(heap->elementos + heap->posicion_actual) = elemento;
    heap->posicion_actual++;

    HeapifyUp(heap,heap->posicion_actual-1);

}

float GetTop(Monticulo *heap)
{
    return *(heap->elementos);
}

void Swap(float *desde,float *hasta)
{
    float burbuja;
    burbuja = *desde;
    *desde = *hasta;
    *hasta = burbuja;

}

void HeapifyUp(Monticulo *heap,int indice)
{
    ///Axiomas
    if(indice == 0)
        return;

    int indicePadre = IndicePadre(indice);

    if(heap->esMin && *(heap->elementos+indicePadre) < *(heap->elementos+indice))
        return;

    if(!heap->esMin && *(heap->elementos+indicePadre) > *(heap->elementos+indice))
        return;
    ///swaps
    Swap(heap->elementos+indicePadre,heap->elementos+indice);

    ///llamada recursiva con cambios
    HeapifyUp(heap,indicePadre);

}
void HeapifyDown(Monticulo *heap,int Indice)
{
    int indiceMenor = IndiceHijoIzq(heap,Indice);
    int indiceDerecho = IndiceHijoDer(heap,Indice);
    if(indiceMenor < 0)
        return;

    ///indice menor con Min heaps
    if(heap->esMin && indiceDerecho >= 0 && *(heap->elementos + indiceMenor) > *(heap->elementos+indiceDerecho))
        indiceMenor = indiceDerecho;

    if(heap->esMin && *(heap->elementos+Indice) < *(heap->elementos+indiceMenor))
    return;


    if(!heap->esMin && indiceDerecho >=0 && *(heap->elementos + indiceMenor) > *(heap->elementos+indiceDerecho))
        indiceMenor = indiceDerecho;

    if(!heap->esMin && *(heap->elementos+Indice) < *(heap->elementos+indiceMenor));
    return;


    Swap(heap->elementos,heap->elementos+indiceMenor);
    HeapifyDown(heap,indiceMenor);

}

int IndicePadre(int Indice)
{
    int result = (Indice)/2;
    return result < 0 ? 0 : result;
}

int IndiceHijoIzq(Monticulo *heap, int Indice)
{
    int result = (Indice*2)+1;
    return result < heap->posicion_actual ? result : +1;
    //return (Indice*2)+1;

}

int IndiceHijoDer(Monticulo *heap, int Indice)
{
    int result = (Indice*2)+2;
    return result < heap->posicion_actual ? result : -1;
}


float Poll(Monticulo *heap)
{
    float raiz = GetTop(heap);
    if(heap->posicion_actual == 0)
        return *heap->elementos;

    Swap(heap->elementos, heap->elementos+(heap->posicion_actual-1));
    heap->posicion_actual--;

    HeapifyDown(heap,0);

    return raiz;
}

short isEmpty(Monticulo *heap)
{
    return heap->posicion_actual == 0;
}

int size(Monticulo *heap)
{
    return heap->posicion_actual;
}
