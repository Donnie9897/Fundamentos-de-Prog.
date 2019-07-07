#include <stdio.h>
#include <stdlib.h>

void captam(int*);
void valores(int*, int*);
void mostrar(int*,int*);
void OrdenarInsercion(int*,int*);

int main()
{


    int tama;
    int *arreglo;
    captam(&tama);
    arreglo = (int*)calloc(tama,sizeof(int));
    valores(arreglo,tama);
    mostrar(arreglo,&tama);
    OrdenarInsercion(arreglo,&tama);
    printf("\n");
    mostrar(arreglo,&tama);



    return 0;
}


void captam(int *tama)
{
    do
    {
        printf("Ingrese el tama%co (positivo) del arreglo ",164);
        scanf("%d", tama);

    }
    while(*tama<=0);
}

void valores(int *arreglo, int *tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        printf("\nIngrese los valores del arreglo ");
        scanf("%d",(arreglo+i));

    }
}

void mostrar(int *arreglo,int *tam)
{
    int i;

    for(i=0; i<*tam; i++)
    {
        printf("%d \n",*(arreglo+i));

    }

}

void OrdenarInsercion(int *arreglo, int *tam)
{
    int i,j,valorActual;

    for(i = 1; i<*tam; i++)
    {
        valorActual = *(arreglo+i);
        j=i-1;
        while(j>=0 && *(arreglo+j) > valorActual)
        {
            *(arreglo+j+1) = *(arreglo + j);
            j--;

        }

        *(arreglo+j+1) = valorActual;
    }


}
