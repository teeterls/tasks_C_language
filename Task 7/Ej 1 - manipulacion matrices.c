/*Programa: programa 1
 * Descripcion: calcular una matriz y su traspuesta
 * Revision: 19-10-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/

#include <stdio.h>
#define N 10

void RellenarMatriz (int m[][N], int dim);
void Mostrar (int m[][N], int dim);
void Trasponer (int m[][N], int trasp[][N], int dim);
void Mostrar1 (int trasp[][N], int dim);
int SumaDiag (int m[][N], int dim);
int SumaDiag1 (int trasp[][N], int dim);
                                                                                        
int main(void)

{
    int mat [N][N]; //MATRIZ CUADRADA CON IGUALES DIMENSIONES
    int trasp [N][N];
    int dim;

    do
    {
        printf("\n Introduzca la dimension de la matriz:");
        scanf("%d",&dim);
        if (dim<=0 || dim>10)

        {
            printf("\n Error. Introduzca otro valor de la dimension.");
        }
    }while (dim<=0 || dim>10);
    
    RellenarMatriz (mat,dim); //LLAMAR A LA FUNCION//
    printf("\n La matriz es:\n");
    Mostrar (mat,dim);
    
    printf("\n");
 
    Trasponer (mat, trasp, dim); //OJO//
    printf("\n La matriz traspuesta es:\n");
    Mostrar1 (trasp, dim);

    SumaDiag (mat, dim);

    SumaDiag1 (trasp,dim);

    printf ("\n La suma de la diagonal inversa de la matriz es %d\n",SumaDiag(mat, dim));

    printf ("\n La suma de la diagonal inversa de la matriz traspuesta es %d",SumaDiag1(trasp, dim));
    return 0;

}
    //FUNCIONES//

    void RellenarMatriz (int m[][N], int dim)
    {
    int i; //filas//
    int j; //columnas//

    for (i=0; i<dim; i++) //<DIM PORQUE EMPIEZA EN 0
    {
     for (j=0; j<dim; j++)
     {
         printf ("\n Introduce el elemento %d,%d de la matriz:",i,j);
         scanf ("%d", &m[i][j]);
     }
    }
    return;
   }
   
    void Mostrar (int m[][N], int dim)
    {
    int i;
    int j;

    //IMPRIMO LA MATRIZ//

    for (i=0; i<dim; i++)
    {
      for (j=0; j<dim; j++)
      {
       printf ("%d", m[i][j]);  
      }
       printf ("\n"); //SALTO DE LINEA POR CADA FILA//
    }
    return;
    }

    void Trasponer (int m[][N], int trasp[][N], int dim)
    {
    int i;
    int j;

    //REALIZO TRASPOSICION DE LA MATRIZ//

    for (i=0;i<dim;i++)
    {
        for (j=0;j<dim;j++)
        {

            trasp[j][i]= m[i][j]; //OPERACION TRASPONER, CAMBIAR FILA POR COLUMNA//
       }
    }
    return;    
    }
    void Mostrar1 (int trasp[][N], int dim)
    {
    int i;
    int j;

    //IMPRIMO LA MATRIZ//
    
    for (i=0; i<dim; i++)
    {
      for (j=0; j<dim; j++)
      {
       printf ("%d", trasp[i][j]);  

      }
        printf ("\n"); //SALTO DE LINEA POR CADA FILA//
   }
    return;
    }

    int SumaDiag (int m[][N], int dim)
    {
    int i;
    int suma;

    suma=0; //INICIALIZAR//
    for (i=dim-1;i>=0;i--)
    {
        suma=suma + m[i][dim-i-1];
    }

    Return suma;
}

     int SumaDiag1 (int trasp[][N], int dim)
    {
    int i;
    int suma;

    suma=0; //INICIALIZAR//
    for (i=dim-1;i>=0;i--)
    {
       suma=suma + trasp[i][dim-i-1];
    }
    return suma;
    }

/*
AL EJECUTAR

 Introduzca la dimension de la matriz:2
 Introduce el elemento 0,0 de la matriz:1
 Introduce el elemento 0,1 de la matriz:2
 Introduce el elemento 1,0 de la matriz:3
 Introduce el elemento 1,1 de la matriz:4
 La matriz es:
12
34

 La matriz traspuesta es:
13
24

 La suma de la diagonal inversa de la matriz es 5
 La suma de la diagonal inversa de la matriz traspuesta es 5
*/
