#include <stdio.h>
#include <stdlib.h>
#include "Monticulo.h"


int main()
{

    Monticulo *miHeap;
    miHeap = Inicializar(1);
    ///5,10,20,35,2,8,15,100,9,1

    Insertar(miHeap,5);

    Insertar(miHeap,10);

    Insertar(miHeap,20);

    Insertar(miHeap,35);

    Insertar(miHeap,2);

    Insertar(miHeap,8);

    Insertar(miHeap,15);

    Insertar(miHeap,100);

    Insertar(miHeap,9);

    Insertar(miHeap,1);

    while(!isEmpty(miHeap))
    {
        printf("%.2f ",Poll(miHeap));
    }








    return 0;
}
