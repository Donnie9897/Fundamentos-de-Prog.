#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int dato;
    struct Nodo *siguiente;
} Nodo;

Nodo *primer = NULL;
Nodo *ultimo = NULL;
int cantidad = 0;

void Insertar(int dato);
void Imprimir();
void buscar();
void eliminarNodo();

int main()
{


    Insertar(7);
    Insertar(8);
    Insertar(9);
    Insertar(10);
    Imprimir();
    // buscar();
    eliminarNodo();
    Imprimir();


    return 0;
}

void Insertar(int dato)
{
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = dato;

    if(primer == NULL)
    {
        primer = nuevo;
        nuevo->siguiente = primer;
        ultimo = primer;
        cantidad++;
    }

    else
    {
        ultimo->siguiente = nuevo;
        nuevo->siguiente = primer;
        ultimo = nuevo;
        cantidad++;
    }

}


void Imprimir()
{
    Nodo *aux = primer;

    if(primer != NULL)
    {
        printf("%d ",aux->dato);
        aux = aux->siguiente;

        while(aux != primer)
        {
            printf("%d ",aux->dato);
            aux = aux->siguiente;
        }
    }
    else
        printf("La lista esta vacia.");
}


void buscar()
{
    Nodo *aux = NULL;
    aux = primer;
    int numero, posicion = 1;

    printf("\nCual numero desea buscar? ");
    scanf("%d",&numero);

    if(aux != NULL)
    {
        if(aux->dato == numero)
        {
            printf("\nEl numero %d se encuentra en la posicion %d",numero,posicion);
            return;
        }

        else
        {
            posicion++;
            aux = aux->siguiente;

            do
            {

                if(aux->dato == numero)
                {
                    printf("\nEl numero %d se encuentra en la posicion %d",numero,posicion);
                    return;
                }


                posicion++;
                aux = aux->siguiente;

            }
            while(aux != primer  && posicion <= cantidad);

            printf("\nEl numero buscado no esta en la lista ");
        }
    }
}


void eliminarNodo()
{
    Nodo *aux = NULL;
    aux = primer;

    Nodo *anterior = NULL;
    int Nodobuscado = 0, encontrado = 0;

    printf("\nCual Nodo desea eliminar? ");
    scanf("%d",&Nodobuscado);

    if(aux != NULL)
    {
        do
        {
            if(aux->dato == Nodobuscado)
            {
                if(aux == primer)
                {
                    primer = primer->siguiente;
                    ultimo->siguiente = primer;
                }
                else if(aux == ultimo)
                {
                    anterior->siguiente = primer;
                    ultimo = anterior;

                }
                else
                    anterior->siguiente = aux->siguiente;

                encontrado = 1;

            }
            anterior = aux;
            aux = aux->siguiente;

        }while(aux != primer && encontrado != 1);

        if(encontrado == 0)
            printf("\nEl nodo no esta en la lista");

        else
            free(anterior);


    }
}


