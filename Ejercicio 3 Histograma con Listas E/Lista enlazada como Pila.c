#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    struct nodo* siguiente;
    int dato;

}Nodo;


Nodo *primer = NULL;
Nodo *aux = NULL;



void Push(int numero);
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


    MostrarEncabezadoHistograma();


    //aux = primer;

        while(cantidad > 0)
        {
            i++;
            MostrarElementoHistograma(i,aux->dato,total);
            aux = aux->siguiente;
            cantidad--;

        }


    MostrarPieHistograma(i,total);





    return 0;
}


void Push(int numero)
{
    aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = numero;

    if(primer == NULL)
    {
        primer=aux;
        aux->siguiente = NULL;
    }

    else
    {
        aux->siguiente = primer;
        primer = aux;
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
    printf("%d\t%d\t",secuencia,aux->dato);

    cantidadCaracteres = proporcion/total*100;

    while(cantidadCaracteres-- > 0)
            printf("%c",254);


    printf("%.2f%%\n",proporcion/total*100);

}

void MostrarPieHistograma(int cantidad,int total)
{
    printf("Se han mostrado %d elementos. Total : %d", cantidad,total);
}



