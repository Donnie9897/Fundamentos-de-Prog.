#include <stdio.h>
#include <stdlib.h>
#define tam 10

typedef struct
{
    float *elementos;
    int posicion;
    int tamano;
    int otraposicion;

}Pila;



Pila* Iniciar();
void verificacion(Pila *pila);
void Push(Pila *pila,float valor);
float pull(Pila *pila);
short isEmpty(Pila *pila);
float otropop(Pila *pila);

int main()
{

    Pila *puntero;
    puntero = Iniciar(puntero);
    float valor;
    int cantidad = 0;


    do
    {
        printf("\nIngrese un valor ");
        scanf("%f",&valor);

        if(valor > 0)
            Push(puntero,valor);

    }while(valor > 0);

    printf("\n\n");

    while(!isEmpty(puntero))
    {
        valor = pull(puntero);
        printf("%.2f ",valor);
        cantidad++;
    }
    printf("\n\n");

    while(cantidad > 0)
    {
        valor = otropop(puntero);
        printf("%.2f ",valor);
        cantidad--;

    }


    return 0;
}

Pila* Iniciar()
{
    Pila *newstack = (Pila*)malloc(sizeof(Pila));
    newstack->posicion = 0;
    newstack->tamano = tam;
    newstack->elementos = (float*)malloc(tam*sizeof(float));
    newstack->otraposicion = 0;

    return newstack;
}

void verificacion(Pila *pila)
{
    if(pila->posicion > pila->tamano)
        return;

    pila->elementos = (float*)realloc(pila->elementos, pila->tamano + tam);
    pila->tamano = pila->tamano + tam;

}

void Push(Pila *pila,float valor)
{
    verificacion(pila);


    *(pila->elementos + pila->posicion) = valor;
    pila->posicion++;
}

float pull(Pila *pila)
{
    float retorno;

    retorno = *(pila->elementos + pila->posicion-1);
    pila->posicion--;

    return retorno;
}

float otropop(Pila *pila)
{
    float retorno;

    retorno = *(pila->elementos+pila->otraposicion);
    pila->otraposicion++;

    return retorno;
}



short isEmpty(Pila *pila)
{
    return pila -> posicion == 0;
}
