/*Programa: programa 3
 * Descripcion: calculo del maximo y el minimo en una matriz
 * Revision: 04-10-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/

#include <stdio.h>
#include <math.h>
#define N 20
void Buscar(float mat[][N], int nf, int nc, float *pmax, float *pmin, int *pposmaxi, int *pposmaxj, int *pposmini, int *pposminj);

int main(void)
{
	float mat [N][N];
    int nf;
    int nc;
    float max;
    float min;
    int i, j;
    int posmaxi;
    int posmaxj;
    int posmini;
    int posminj;
   
    do
    {
       printf("\n Introduzca el numero de filas de la matriz (max 20):");
       scanf("%d", &nf);
       if (nf<1 || nf>20)
       {
           printf ("\n Error. Numero de filas entre 1 y 20");
       }
    }while (nf<1 || nf>20);
    
    do
    {
        printf("\n Introduzca el numero de columnas de la matriz (max     20):");
       scanf("%d", &nc);
       if (nc<1 || nc>20)
       {
           printf ("\n Error. Numero de colunas entre 1 y 20");
       }
    }while (nc<1 || nc>20);
    //RELLENAR MATRIZ
    for (i=0; i<nf; i++)
    {
        for (j=0; j<nc;j++)
        {
            printf("\n Introduzca un numero para fila %d y columna %d: ", i, j);
            scanf ("%f", &mat[i][j]);
        }
    }

    Buscar (mat, nf, nc, &max, &min, &posmaxi, &posmaxj, &posmini, &posminj); //EN MAIN NO HEMOS DECLARADO NINGUN PUNTERO OJO
    
    printf ("\n El valor mayor es %.2f en la fila %d columna %d" , max, posmaxi, posmaxj);
    printf("\n El valor menor es %.2f en la fila %d columna %d", min, posmini, posminj);
    
	return 0;
}

//FUNCION//

void Buscar(float mat[][N], int nf, int nc, float *pmax, float *pmin, int *pposmaxi, int *pposmaxj, int *pposmini, int *pposminj)
{
    int i,j;
    *pmax=mat[0][0]; //inicializamos//
    *pmin=mat[0][0];
    *pposmaxi= 0;
    *pposmaxj=0;
    *pposmini= 0;
    *pposminj= 0;
    
    for (i=0;i<nf;i++)
    {
        for (j=0;j<nc;j++)
        {
            if (*pmax< mat[i][j]) //va comparando el elemento con el siguiente de la matriz, si es menor hay un nuevo max
            {
                *pmax=mat[i][j];
                *pposmaxi= i;
                *pposmaxj=j;
            }
            
            if (*pmin> mat[i][j]) //va comparando el elemento con el siguiente de la matriz, si es mayor hay un nuevo min
            {
                *pmin=mat [i][j];
                *pposmini= i;
                *pposminj= j;
            }
        }
    }
    
return;
}
/*
AL EJECUTAR
Introduzca el numero de filas de la matriz (max 20):2
Introduzca el numero de columnas de la matriz (max 20):2

 Introduzca un numero para fila 0 y columna 0: 1
 Introduzca un numero para fila 0 y columna 1: 2
 Introduzca un numero para fila 1 y columna 0: 3
 Introduzca un numero para fila 1 y columna 1: 4

 El valor mayor es 4.00 en la fila 1 columna 1
 El valor menor es 1.00 en la fila 0 columna 0
*/