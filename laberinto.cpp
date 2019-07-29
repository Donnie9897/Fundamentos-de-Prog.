#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 12
#define numero 40//numero de cuadritos

int columna = 0;
int fila = tam-1;
int arrx[]={1,0,-1,0};//movimiento
int arry[]={0,1,0,-1};
int iter = 1;
void carga_tablero(int arry[][tam])
{
     int j,i;    
     for (j=0; j<tam; j++)
     {
         for (i=0; i<tam; i++)
         {arry[j][i] = 0;}
     }
}//carga

void mostrar(int arry[][tam])
{
     
     int j,i;       
     
     for (i=0; i<tam; i++)
     {
         for (j=0; j<tam; j++)
         {printf(" %2d |",arry[j][i]);}
         printf("\n\n");
     }

}//carga

void aleatorio(int arry[][tam])
{
     int i, x, y;
     srand(time(NULL));
     for (i=0; i<numero; i++)
     {
         x = rand()%tam;
         y = rand()%tam;
         if (x != columna && y != fila)
         arry[x][y] = -1;
         
     }    
}//aleatorio

void traspaso(int antes[][tam], int despues[][tam])
{
     int j,i;
     for (i=0; i<tam; i++)
     {
         for (j=0; j<tam; j++)
         {
             despues[j][i] = antes[j][i];
         }
     }
}//traspaso

int retroceder(int tab[][tam],int contador, int *x, int *y)
{
    int j,i;
    int x1, y1;
    
    for (j=0; j<tam; j++)
     {
         for (i=0; i<tam; i++)
         {
             if(tab[j][i]== contador -1)
             {
                 x1 = j;
                 y1 = i;
             }
            
         }
     }
     for(i=0; i<4;i++)
     {
          if (tab[x1+arrx[i]][y1+arry[i]]== tab[*x][*y])
          {tab[*x][*y]=0;
            *x = x1;
            *y = y1;
            return i;
          }
     }
     
    
}//retroceder

void movimiento(int tab[][tam], int tab_aux[][tam], int x, int y)
{

     int indice = 0;//vector
     int contador = 2;//pasos laberinto
     int solucion = 0;// no encontrada
     int newx, newy;
     int optima  = (tam*tam +1);//mejor ruta
     while(solucion == 0)
     {
                    
                    newx= x+arrx[indice];
                    newy= y+arry[indice];
                    if (tab[newx][newy] == 0 && newx < tam && newx >= 0 && newy < tam && newy >= 0 && indice != 4)
                    {
                         x = x+arrx[indice];
                         y = y+arry[indice];
                         tab[x][y] = contador;
                         if (columna == x && fila == y)//encontro la solucion
                         {    
                              mostrar(tab);
                              system("pause");
                              if (contador < optima)//solo la mejor ruta
                              {traspaso(tab,tab_aux);
                               optima = contador;                              
                              }
                              indice = retroceder(tab,contador, &x, &y)+1;    
                              
                         }else
                         {
                            contador+=1;
                            indice = 0;
                         }//else
                                                             
                    }//if
                    else
                    {
                        indice+=1;
                        if (indice > 3)
                        {
                               if (contador > 0)
                               {
                                   indice = retroceder(tab,contador-1, &x, &y)+1;    
                                   contador-=1; 
                               }
                               else
                               {
                                   mostrar(tab_aux);
                                   if (optima != tam*tam +1)
                                   printf("la mejor solucion en %d pasos\n",optima);
                                   else printf("no hay solucion!!!\n");
                                   solucion=1;
                               }//else                                  
                        }//if        
                    }//else
                    iter+=1;
     }//while
}//movimiento    


int main()
{
    int tablero[tam][tam];
    int tablero_aux[tam][tam];
    int x,y;
    carga_tablero(tablero);
    carga_tablero(tablero_aux);
    aleatorio(tablero);
    printf("                LABERINTO\n");
    mostrar(tablero);
    
    printf("columna: ");
    scanf("%d",&x);
    printf("fila: ");
    scanf("%d",&y);
    tablero[x][y]=1;
    
    movimiento(tablero,tablero_aux,x,y);
    printf("iteraciones -> %d\n",iter);

    system("pause");
    system("cls");
    main();
    return 0;
}
