#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 1000, MIN = 0;

void capturarValores(int [], int);
void GenerarValores(int[],int);
long GenerarValoresRecursivo(int[],int, int);
void MostrarValores(int[],int);
int BusquedaLinealRecursiva(int [],int, int, int);
int BusquedaLinealNoRecursiva(int [],int, int);
int BusquedaBinaria(int [],int, int);
int BusquedaBinariaRecursiva(int[],int,int,int);
void MergeSortRecursivo(int [],int, int);
void Merge(int[],int,int,int[],int,int[],int);

int main()
{
    srand(time(NULL));
    int n, destino,posicion;
    printf("Digite el tama%co del arreglo. ",164);
    scanf("%d",&n);
    int arreglo[n];

    //capturarValores(arreglo,n);
    GenerarValores(arreglo,n);
    MostrarValores(arreglo,n);

    printf("Digite el valor que desea buscar: ");
    scanf("%d",&destino);

    MergeSortRecursivo(arreglo,0,n-1);
    MostrarValores(arreglo,n);

    posicion = BusquedaLinealNoRecursiva(arreglo,n,destino);
    printf("\n\n");
    if(posicion >= 0)
        printf("\nUsando Busqueda Lineal, el valor se ha encontrado en: %d",posicion+1);
    else
        printf("\nUsando Busqueda Lineal, el valor %d no existe en el listado",destino);

    posicion = BusquedaBinaria(arreglo,n,destino);
    printf("\n\n");
    if(posicion >= 0)
        printf("\nUsando Busqueda Binaria, el valor se ha encontrado en: %d",posicion+1);
    else
        printf("\nUsando Busqueda Binaria, el valor %d no existe en el listado",destino);


    printf("\n\n");

    return 0;
}

void capturarValores(int arreglo[], int tamano)
{
    int i;

    for(i=0; i<tamano; i++)
    {
        printf("%d: ",i+1);
        scanf("%d",&arreglo[i]);
    }

}

void GenerarValores(int arreglo[],int tamano)
{
    long sumatoria = GenerarValoresRecursivo(arreglo,tamano,0);
    printf("\nLa sumatoria de los aleatorios es: %1d\n",sumatoria);
}

long GenerarValoresRecursivo(int arreglo[],int tamano,int pos)
{
    if(pos >= tamano)
        return 0;

    arreglo[pos] =  rand() % (MAX - MIN + 1) + MIN;
    return arreglo[pos] + GenerarValoresRecursivo(arreglo,tamano,pos+1);
}

void MostrarValores(int arreglo[], int tamano)
{
    int i;
    printf("\nValores:\n");
    for(i=0; i<tamano; i++)
    {
        printf("%d\t",arreglo[i]);
    }
}

int BusquedaLinealNoRecursiva(int arreglo[],int tamano, int destino)
{
    return BusquedaLinealRecursiva(arreglo,tamano,destino, 0);
}


int BusquedaLinealRecursiva(int arreglo[],int tamano, int destino, int pos)
{
    if(pos >= tamano)
        return -1;

    return arreglo[pos] == destino ? pos : BusquedaLinealRecursiva(arreglo,tamano,destino,pos+1);
}

int BusquedaBinaria(int arreglo[], int tamano, int destino)
{
    return BusquedaBinariaRecursiva(arreglo,destino,0,tamano-1);
}

int BusquedaBinariaRecursiva(int arreglo[], int destino, int LimI, int LimS)
{
    int centro;
    if(LimI > LimS)
        return -1;

    centro = (float)LimI/2 + (float)LimS/2;

    if(arreglo[centro] == destino)
        return centro;

    else if(arreglo[centro]>destino) // asume que esta en orden creciente
        BusquedaBinariaRecursiva(arreglo,destino,LimI,centro-1);

    else
        BusquedaBinariaRecursiva(arreglo,destino,centro+1,LimS);
}
void MergeSortRecursivo(int arreglo[], int limI, int limS)
{
    int i;
    if(limI == limS)
        return;

    int nuevoTamanoIzquierdo, nuevoTamanoDerecho;

    if(((limS - limI) + 1) % 2)
    {
        nuevoTamanoIzquierdo = ((limS - limI) / 2);
        nuevoTamanoDerecho = ((limS - limI) / 2) + 1;
    }
    else
        nuevoTamanoIzquierdo = nuevoTamanoDerecho = (limS - limI) / 2 + 1;

    int izquierdo[nuevoTamanoIzquierdo],derecho[nuevoTamanoDerecho];

    //copiando la mitad izquierda:
    for(i=limI; i<nuevoTamanoIzquierdo; i++)
    {
        izquierdo[i-limI] = arreglo[i];
    }

    //copiando a la derecha
    for(; i<=limS; i++)
    {
        derecho[i-limI-nuevoTamanoIzquierdo] = arreglo[i];
    }

    MergeSortRecursivo(izquierdo, 0, nuevoTamanoIzquierdo-1);
    MergeSortRecursivo(derecho,0,nuevoTamanoDerecho-1);

    Merge(arreglo,limI,limS,izquierdo,nuevoTamanoIzquierdo,derecho,nuevoTamanoDerecho);
}


void Merge(int arreglo[],int limI,int limS,int izquierdo[],int TamanoI,int derecho[], int TamanoR)
{
    int i = 0,j  = 0;

    while(i < TamanoI && j < TamanoR)
    {
        if(izquierdo[i] <= derecho[j])
            arreglo[limI] = izquierdo[i++];

        else
            arreglo[limI] = derecho[j++];

        limI++;
    }

    //copiando los remanentes:
    while(i<TamanoI)
        arreglo[limI++] = izquierdo[i++];

    while(j<TamanoR)
        arreglo[limI++] = derecho[j++];

}

