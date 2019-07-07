#include <stdio.h>
#include <stdlib.h>


int main(int pfil, int pcol)
{

    ///jacked array es el nombre de las matrices en ingles

    const int FIL = 8, COL = 8;
    int **tablero = calloc(FIL, sizeof(int*));
    int i, j;

    printf("Escriba la posicion en que quiere a la reina \n");
    scanf("%d %d", &pfil,&pcol);

    pfil -= 1;
    pcol -= 1;
    printf("\n");

    for(i=0; i<FIL; i++)
    {

        *(tablero+i) = calloc(COL,sizeof(int));

        for(j=0; j<COL; j++)
        {
            if(i == pfil && j == pcol)
                *(*(tablero+i)+j) = '*';

            else if(i == pfil || j == pcol)
                *(*(tablero+i)+j) = '*';

            else if(i+j == pfil+pcol || i-j == pfil-pcol)
                    *(*(tablero+i)+j) = '*';

            else
                *(*(tablero+i)+j) = '0';


            }
    }

    *(*(tablero+pfil)+pcol) = 'R';

    for(i=0;i<FIL;i++)
    {
        for(j=0;j<COL;j++)
            printf("%c ",*(*(tablero+i)+j));

        printf("\n");

    }


    return 0;
}
//#endif
