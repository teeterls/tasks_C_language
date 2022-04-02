/*Programa: programa 4
 * Descripcion: producto de dos vectores
 * Revision: 19-10-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#define N 100

//prototipos de las funciones
void LeerVector (float vector [], int n);
void ImprimirVector (float vector[], int n); //void ImprimirVector (float *v, int n);
void Producto(float vec1[], float vec2[], float producto[][N], int n); //void Producto(float *v1, float *v2, float p[][TAM], int n);
void ImprimirMat (float producto[][N], int n); 

int main(void)

{
    float vec1[N];
    float vec2[N];
    float producto[N][N];
    int n;
 
    do{
        printf("\nIntroducir el numero de elementos: ");
        scanf("%d",&n);
        if(n<1||n>N)
        {
            printf("\nEl numero de elementos debe estar entre 1 y %d..",N);
        }
    }  while (n<1||n>N);
    
    //Lectura del vector 1
    printf("\nLectura del vector 1: ");
    LeerVector(vec1,n);
    
    //Escritura del vector 1
    printf("\nEl vector 1 es: ");
    ImprimirVector(vec1,n);
    
    //Lectura del vector 2
    printf("\nLectura del vector 2: ");
    LeerVector(vec2,n);

    //Escritura del vector 2
    printf("\nEl vector 2 es: ");
    ImprimirVector(vec2,n);
   
    Producto(vec1,vec2,producto,n);
    
    //Escritura del resultado 
    printf("\n\nEl producto de los vectores es la matriz: \n\n"); //Calculo del producto de los vectores
    
    ImprimirMat(producto,n);
return 0;
}
/*Función : LeerVector */
void LeerVector (float vector[], int n)
{
    int i;
    
    for(i=0;i<n;i++)
    {
        printf("\nIntroducir elemento %d:", i+1);
        scanf("%f",&vector[i]);
    }
return;
}

/*Función : ImprimirVector */
void ImprimirVector (float vector[], int n)
{
    int i;
    
    for(i=0; i<n;i++)
    {
        printf("%.2f", vector[i]);
    }
return;
}

/*Función : Producto */
void Producto(float vec1[], float vec2[], float producto[][N], int n) //void Producto(float *v1, float *v2, float p[][TAM], int n);
{
    int f,c;
    for(f=0;f<n;f++)
    {
        for(c=0;c<n;c++)
        {
            producto[f][c]=vec1[f]*vec2[c];
        }
    }
return;
}

/*Función : ImprimirMat */
void ImprimirMat (float producto[][N], int n)
{
    int f,c;
    
    for(f=0;f<n;f++)
    {
        for(c=0;c<n;c++)
        {
            printf("%.2f",producto[f][c]);
        }
        printf("\n");
    }
return;
}

/*
AL EJECUTAR
Introducir el numero de elementos: 2

Lectura del vector 1:
Introducir elemento 1:1
Introducir elemento 2:2

El vector 1 es: 1.00 2.00

Lectura del vector 2:
Introducir elemento 1:3
Introducir elemento 2:4

El vector 2 es: 3.00 4.00

El producto de los vectores es la matriz:
3.00 4.00
6.00 8.00
*/