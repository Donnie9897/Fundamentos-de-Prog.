#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int dato;
    struct Nodo *siguiente;
    struct Nodo *anterior;

} Nodo;


Nodo *primer = NULL;
Nodo *ultimo = NULL;
int cantidad = 0;

Nodo *crearNodo(int dato);
int InsertarInicio(Nodo **cabeza, int dato);
void imprimirLista(Nodo *cabeza);
int InsertarFinal(Nodo **cabeza, int dato);
void ordenarLista(Nodo *cabeza);
int InsertarMedio(Nodo **cabeza, int dato, int posicion);


int main ()
{
    // int numero, cantidad = 0;
    Nodo *cabeza = NULL;
    int numero, cantidad = 0, resp, otraresp;

    do
    {
        printf("Ingrese un numero en la lista ");
        scanf("%d",&numero);

        if(numero > 0)
        {
            printf("\nEn que parte de la lista desea insertar? (1) para el inicio y (2) para el final ");
            resp = getch() - 48;

            if(resp == 1)
            {
                InsertarInicio(&cabeza,numero);
                printf("\nEl elemento ha sido insertado con exito ");
                cantidad++;
            }
            else if(resp = 2)
            {
                InsertarFinal(&cabeza,numero);
                printf("\nEl elemento ha sido insertado con exito ");
                cantidad++;
            }
            printf("\n\n");
        }

    }while(numero > 0);

    printf("\n\n");
    //ordenarLista(cabeza);
    InsertarMedio(&cabeza, 72, 2);
    imprimirLista(cabeza);



    return 0;
}


Nodo *crearNodo(int dato)
{
    Nodo *nNodo = (Nodo*)malloc(sizeof(Nodo));

    if(nNodo != NULL)
    {
        nNodo->dato = dato;
        nNodo->siguiente = NULL;
        nNodo->anterior = NULL;

    }

    return nNodo;


}

int InsertarInicio(Nodo **cabeza, int dato)
{
    Nodo *nuevo;
    nuevo = crearNodo(dato);

    if(nuevo != NULL)
    {
        nuevo->siguiente = *cabeza;
        nuevo->anterior = NULL;

        if(*cabeza != NULL)
            (*cabeza)->anterior = nuevo;

        *cabeza = nuevo;
         cantidad++;
        return 1;


    }

    return 0;
}

void imprimirLista(Nodo *cabeza)
{
    Nodo *aux = cabeza;

    while(aux != NULL)
    {
        printf("%d ",aux->dato);
        aux = aux->siguiente;
    }
}


int InsertarFinal(Nodo **cabeza, int dato)
{
    Nodo *nuevo = NULL;
    Nodo *aux = *cabeza;
    nuevo = crearNodo(dato);


    if(nuevo != NULL)
    {
        while(aux->siguiente != NULL)
            aux = aux->siguiente;

        nuevo->anterior = aux;
        aux->siguiente = nuevo;
        cantidad++;

        return 1;
    }

    return 0;
}

void ordenarLista(Nodo *cabeza)
{
    Nodo *aux = cabeza;
    Nodo *otroaux = cabeza;
    Nodo *temp;
    otroaux = otroaux->siguiente;

    if(cabeza->dato > otroaux->dato)
    {
        temp = cabeza;
        cabeza = otroaux;
        otroaux = cabeza;
    }

/*    while(aux->siguiente != NULL && otroaux != NULL)
    {
        if(aux->dato > otroaux->dato)
        {
            temp = aux->dato;
            aux->dato = otroaux->dato;
            otroaux = temp;
        }

        aux = aux->siguiente;
        otroaux = otroaux->siguiente;

    }
*/


}


int InsertarMedio(Nodo **cabeza, int dato, int posicion)
{
    Nodo *temp;
    temp = crearNodo(dato);
    int i;

    if(posicion > 1 && posicion <cantidad )
    {
        Nodo *aux, *aux2;
        aux = *cabeza;

        for(i=0;i<posicion;i++)
        {
            aux2 = aux;
            aux = aux->siguiente;
        }

        aux2->siguiente = temp;
        temp->siguiente = aux;

    }
}
