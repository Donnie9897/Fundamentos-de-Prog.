#include <stdio.h>
#include <string.h>
#include "Pilatriple.h"
const int tamai = 99;

pilatriple* IniciarPila()
{

    pilatriple *nuevapila = (pilatriple*)malloc(sizeof(pilatriple));
    nuevapila->tamanopila = tamai;
    nuevapila->Pilatriple = (float*)calloc(tamai,sizeof(float));
    nuevapila->posiciones[0] = 0;
    nuevapila->posiciones[1] = tamai/3;
    nuevapila->posiciones[2] = 2*tamai/3;

    /*
    for(i=0;i<3;i++)
    {
    nuevapila->posicionespila[i] = i*tamai/3
    }    */
    return nuevapila;
}


void Push(pilatriple *triplepila ,int numeroPila, int elemento)
{
    Verificarespacio(triplepila, numeroPila);

    *(triplepila->Pilatriple+(triplepila->posiciones[numeroPila])) = elemento;
    triplepila->posiciones[numeroPila]++;
}


void Verificarespacio(pilatriple *triplepila,int numeroPila)
{
    ///Verificar si posicion e la pila llega al inicio de la siguiente pila.
    ///y no estoy al inicio de la pila actual.
    ///if(triplepila->posiciones[numeroPila]) == ((numeroPila + 1)*triplepila->tamanopila/3)

    if(triplepila->posiciones[numeroPila]%(triplepila->tamanopila/3) == 0
       && triplepila->posiciones[numeroPila] != numeroPila*triplepila->tamanopila/3)
    //if(triplepila->posiciones[numeroPila] == (numeroPila + 1)*triplepila->tamanopila/3)
    {

        //copiar
        float nuevoArreglo[triplepila->tamanopila * 3];
        int i,j;
        for(i=0; i<3; i++);
        {
            for(j=i*triplepila->tamanopila/3;j<triplepila->posiciones[i];j++)
            {
                nuevoArreglo[triplepila->tamanopila * i + j] = *(triplepila->Pilatriple + j);
            }

        }

        //Pila llena;
        triplepila->Pilatriple = (float*)realloc(triplepila->Pilatriple,triplepila->tamanopila * 2);
        triplepila->tamanopila *= 3;

    }



}


float Pop(pilatriple *triplepila, int numeroPila)
{
    if(isEmpty(triplepila, numeroPila))
        return 0;

    float resultado = *(triplepila->Pilatriple+triplepila->posiciones[numeroPila]);
    triplepila->posiciones[numeroPila]--;

    return *(triplepila->Pilatriple + triplepila->posiciones[numeroPila]);

}


short isEmpty(pilatriple *triplepila,int numeroPila)
{
    return triplepila->posiciones[numeroPila] == triplepila->tamanopila/3 * numeroPila;
}



float Peek(pilatriple *triplepila,int numeroPila)
{
    float valor = Pop(triplepila,numeroPila);
    Push(triplepila,numeroPila,valor);
    return valor;


}

int Size (pilatriple *triplepila, int numeroPila)
{
    return triplepila->posiciones[numeroPila]-1 % triplepila->tamanopila/3 + 1;
}
