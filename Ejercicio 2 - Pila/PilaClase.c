#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilahea.h"

//Pila estatica
void MostrarEncabezadoHistograma();
void MostrarElementoHistograma(int,float,float);
void MostrarPieHistograma(int,float);

int main()
{
    int cantidad = 0;
    float nuevoValor,total = 0;
    Pila *miPila;
    miPila = IniciarPila(miPila);

    do
    {
        printf("Digite un valor (-1 para terminar):");
        scanf("%f",&nuevoValor);


        if(nuevoValor >=0)
        {
         Push(miPila,nuevoValor);
         total += nuevoValor;
         //cantidad++;
        }
    }while(nuevoValor >=0 );


    MostrarEncabezadoHistograma();
    while(!isEmpty(miPila))
    {
        cantidad++;
        nuevoValor = Pop(miPila);
        MostrarElementoHistograma(cantidad,nuevoValor,nuevoValor/total*100);
    }
    MostrarPieHistograma(cantidad,total);
    return 0;
}

void MostrarEncabezadoHistograma()
{
    system("cls");
    printf("HISTOGRAMA\n\n");
    printf("No.:\tValor:\tProporci%cn:\n",162);
}
void MostrarElementoHistograma(int secuencia,float valor,float proporcion)
{
    int cantidadCaracteres = (int)proporcion;
    printf("%d\t%.2f\t",secuencia,valor);

    while(cantidadCaracteres-- > 0)
        printf("%c",254);

    printf("%.2f%%\n",proporcion);

}
void MostrarPieHistograma(int cantidad,float total)
{
    printf("Se han mostrado %d elementos. Total : %.2f", cantidad,total);
}





    /*Push(miPila,16);
    Push(miPila,22);
    Push(miPila,8);*/
    /*
        printf("%.2f ",pop(miPila));
        printf("%.2f ",pop(miPila));
        printf("%.2f ",pop(miPila));
    */

/*
    while(!isEmpty(miPila))
    {
        printf("%.2f\t",pop(miPila));
    }
*/
