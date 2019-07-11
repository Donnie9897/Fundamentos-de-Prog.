#include <stdio.h>
#include <stdlib.h>
#include "Practica.h"

void Particionar(Lista*,int);

int main()
{
    int x,n,i;
    int numero;

    Lista *listado = IniciarlizarLista();
    Nodo *nodoActual;

    printf("Ingrese los valores de x y n ");
    scanf("%d %d",&x,&n);

    for(i=0;i<n;i++)
    {
        printf("%d - ",i+1);
        scanf("%d",&numero);
        AgregarEnCola(listado,numero);
    }



    Particionar(listado,x);
    nodoActual = listado->Cabeza;

    for(i=0;i<n;i++)
    {
        printf("%d\t",nodoActual->data);
        nodoActual = nodoActual->siguiente;
    }

    return 0;
}

void Particionar(Lista *listado, int pivote)
{
    Nodo *nodoActual = listado->Cabeza;
    Nodo *nodoPivote = nodoActual;

    while(nodoActual != NULL)
    {
        if(nodoActual->data < pivote)
        {
            Intercambiar(nodoActual,nodoPivote);
            nodoPivote = (nodoPivote->siguiente);
        }
        nodoActual = nodoActual->siguiente;
    }

}

