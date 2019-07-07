#include <stdlib.h>
#include "Clase.h"

const int tam = 100;
Cola* InicializarCola()
{
    Cola *nuevacola = (Cola*)malloc(sizeof(Cola));
    nuevacola->tamano= tam;
    nuevacola->primerIndice = 0;
    nuevacola->ultimoIndice = -1;
    nuevacola->elementos = (float*)calloc(tam,sizeof(float));
    nuevacola->cantidad = 0;

    return nuevacola;
}
void enqueue(Cola *cola,float elemento)
{
    ///Si no hay espacio redimensionar el arreglo.
    VerificarEspacio(cola);

    cola->ultimoIndice++;

    if(cola->ultimoIndice > cola->tamano)
        cola->ultimoIndice = 0;
        ///Si hay espacio a la derecha del ultimo.
        ///si hay espacio al principio

    //cola->elementos+cola->ultimoIndice = (float*)malloc(sizeof(float));
    *(cola->elementos+cola->ultimoIndice) = elemento;
    cola->ultimoIndice++;
    cola->cantidad++;
}

int TamanoCola(Cola* cola)
{
    return cola->cantidad;
}

void VerificarEspacio(Cola *cola)
{
    int i;
    if(TamanoCola(cola) < cola->tamano)
        return;

    float *nuevoEspacio = (float*)malloc(cola->tamano * 2);

    i = cola->primerIndice;
    while(i != cola->primerIndice)
    {
        *(nuevoEspacio++) = *(cola->elementos + i++);

        if(i == cola->tamano)
            i = 0;

    }

    cola->elementos = nuevoEspacio-cola->cantidad;
    cola->primerIndice = 0;
    cola->ultimoIndice = cola->cantidad;
    cola->tamano = cola->tamano * 2;
}


float dequeue(Cola *cola)
{
    if(isEmpty(cola))
        return 0;

    float respuesta = *(cola->elementos + cola->primerIndice);

    cola->primerIndice++;
    if(cola->primerIndice >= cola->tamano)
        cola->primerIndice = 0;

    cola->cantidad--;

    return respuesta;
}

short isEmpty(Cola *cola)
{
    return cola->cantidad == 0;
}

float getFront(Cola *cola)
{
    if(isEmpty(cola))
        return 0;

    return *(cola->elementos + cola->primerIndice);
}


/*
int TamanoCola(Cola* cola)
{
    return cola->cantidad;


    if(/cola->ultimoIndice < cola->tamano && cola->ultimoIndice > cola->primerIndice)
        return cola->ultimoIndice - cola->primerIndice;

    else if(cola->ultimoIndice < cola->primerIndice)
        return cola->tamano - (cola->primeIndice - cola->ultimoIndice)

}*/
