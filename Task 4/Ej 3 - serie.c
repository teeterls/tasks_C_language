/*Programa: programa 3
 * Descripcion: Funcion Serie()
 * Revision: 27-09-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
#include <stdio.h>

float serie (float x, int nt);
float mipotencia (float base, int e);

int main(void)
{
    int n;
    float x, f;
    
	printf("\n introduce el valor de x: ");
    scanf ("%f", &x);
    
    do
    {
    printf ("\n introduce el numero de terminos: ");
    scanf ("%d", &n);            
        if (n<0){
            printf("\n Error, el numero de terminos debe ser positivo.");
        }
        }while (n<0);
    
f = serie (x,n);
    printf ("\n el valor de la funcion es: %f", f);
    printf ("\n\n\n");
	return 0;
}

// funcion

float serie (float x, int nt)
{
    int serie;
    int i;
    
    serie = 1;
    for (i=1; i<nt; i++)
    {
        serie = serie + mipotencia (-1,i)* mipotencia (x,i);
    }
    return serie;
} 

float mipotencia (float base, int exponente)
{
    
    float potencia;
    int i;
    
    potencia =1;
    for (i=1; i<=exponente; i++)
    {
        potencia = potencia*base; 
    }
    return potencia;
}

/*
AL EJECUTAR
 introduce el valor de x: 4
 introduce el numero de terminos: -3
 Error, el numero de terminos debe ser positivo.
 introduce el numero de terminos: 2
 el valor de la funcion es: -3.000000
  * /
