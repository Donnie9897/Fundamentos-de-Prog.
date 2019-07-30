#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 10000000, MIN = 0;

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
void QuickSort(int[],int);
void QuickSortRecursivo(int[],int,int);
int Particionar(int[],int,int);
void Swap(int[],int,int);
void SwapPunteros(int*,int*);
void OrdenarBurbuja(int arreglo[], int tam);
void OrdenarSeleccion(int arreglo[], int tam);
void OrdenarInsercion(int arreglo[], int tam);

int main()
{
    srand(time(NULL));
    int  destino,posicion;
  //  printf("Digite el tama%co del arreglo. ",164);
    //scanf("%d",&n);
    const int n = 200000;
    int arreglo[n];

    //capturarValores(arreglo,n);
    GenerarValores(arreglo,n);
    //MostrarValores(arreglo,n);

    //printf("Digite el valor que desea buscar: ");
    //scanf("%d",&destino);


    //OrdenarInsercion(arreglo, n);
    //OrdenarSeleccion(arreglo, n);
    //OrdenarBurbuja(arreglo,n);
    //MergeSortRecursivo(arreglo,0,n-1);
    QuickSort(arreglo,n);
    //MostrarValores(arreglo,n);

    /*posicion = BusquedaLinealNoRecursiva(arreglo,n,destino);
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
    */


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

void QuickSort(int arreglo[], int tamano)
{
    QuickSortRecursivo(arreglo,0,tamano-1);
}

void QuickSortRecursivo(int arreglo[], int limI, int limS)
{
    int IndicePivote;

    if(limI>=limS)
        return;

    IndicePivote = Particionar(arreglo,limI,limS);
    QuickSortRecursivo(arreglo,limI,IndicePivote-1);
    QuickSortRecursivo(arreglo,IndicePivote+1,limS);
}

int Particionar(int arreglo[], int limI, int limS)
{
    int pivote = arreglo[limI];
    int i = limI+1;
    int j = i;

    for(; i<=limS;i++)
    {
        if(arreglo[i] < pivote)
        {
            Swap(arreglo, i, j);
            j++;
        }
    }
    SwapPunteros(&arreglo[limI], &arreglo[j-1]);
    return j-1;
}

void Swap(int arreglo[],int indiceInicio, int indiceFinal)
{
    int burbuja;
    burbuja = arreglo[indiceInicio];
    arreglo[indiceInicio] = arreglo[indiceFinal];
    arreglo[indiceFinal] = burbuja;

}

void SwapPunteros(int *a,int *b)
{
    int *burbuja = (int*)malloc(sizeof(int));
    *burbuja = *a;
    *a = *b;
    *b = *burbuja;
}

void OrdenarBurbuja(int arreglo[], int tam)
{
    int i,j,pasos = 0;
    int aux;
    pasos++;


    for(i=0;i<tam;i++)
    {
        for(j=0;j<tam-1;j++)
        {
            if(arreglo[j+1] < arreglo[j])
            {
                aux = arreglo[j+1];
                arreglo[j+1] = arreglo[j];
                arreglo[j] = aux;
            }
            pasos++;
        }

            pasos++;
    }


    printf("\nCantidad de pasos = %d\n\n",pasos);

}

void OrdenarSeleccion(int arreglo[], int tam)
{
    int i,j,aux,min;
    int pasos = 1;

    for(i=0;i<tam;i++)
    {
        min = i;
        for(j=i+1;j<tam;j++)
        {
            if(arreglo[j] < arreglo[min])
                min = j;

            pasos++;
        }
        aux = arreglo[i];
        arreglo[i] = arreglo[min];
        arreglo[min] = aux;

        pasos++;
    }

    printf("\nCantidad de pasos = %d\n\n",pasos);
}

void OrdenarInsercion(int arreglo[], int tam)
{
    int i,j,valorActual;
    int pasos = 1;

    for(i = 0; i<tam; i++)
    {
        valorActual = arreglo[i];
        j=i-1;
        while(j>=0 && arreglo[j] > valorActual)
        {
            arreglo[j+1] = arreglo[j];
            j--;

            pasos++;
        }

        arreglo[j+1] = valorActual;

        pasos++;
    }



    printf("\nCantidad de pasos = %d\n\n",pasos);
}
