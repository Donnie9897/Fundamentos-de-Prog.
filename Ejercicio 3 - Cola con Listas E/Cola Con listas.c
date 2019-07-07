#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    struct nodo* siguiente;
    int dato;

}Nodo;


Nodo *primer = NULL;
Nodo *ultimo = NULL;


void Push(int numero);
void Listado();
void MostrarEncabezadoHistograma();
void MostrarElementoHistograma(int,int,float);
void MostrarPieHistograma(int,int);



int main()
{
    int numero, i = 0;
    Nodo *puntero;
    float total = 0, cantidad = 0;

    do
    {
        printf("Ingrese un numero ");
        scanf("%d",&numero);

        if(numero>0)
        {
            Push(numero);
            total += numero;
            cantidad++;
        }


    }while(numero > 0);

    printf("\n\n");

    //Listado();

    MostrarEncabezadoHistograma();
    ultimo = primer;

    while(cantidad > 0)
    {
        i++;
        MostrarElementoHistograma(i,ultimo->dato,total);
        ultimo = ultimo->siguiente;
        cantidad--;

    }

    MostrarPieHistograma(i,total);



    return 0;
}


void Push(int numero)
{
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = numero;

    if(primer == NULL)
    {
        primer = nuevo;
        primer->siguiente = NULL;
        ultimo = nuevo;
    }

    else
    {
        ultimo->siguiente = nuevo;

        nuevo->siguiente = NULL;

        ultimo = nuevo;
    }
}



void MostrarEncabezadoHistograma()
{
    system("cls");
    printf("HISTOGRAMA\n\n");
    printf("No.:\tValor:\tProporci%cn:\n",162);
}

void MostrarElementoHistograma(int secuencia,int proporcion,float total)
{

    int cantidadCaracteres;
    printf("%d\t%d\t",secuencia,ultimo->dato);

    cantidadCaracteres = proporcion/total*100;

    while(cantidadCaracteres-- > 0)
        printf("%c",254);


    printf("%.2f%%\n",proporcion/total*100);

}

void MostrarPieHistograma(int cantidad,int total)
{
    printf("Se han mostrado %d elementos. Total : %d", cantidad,total);
}



