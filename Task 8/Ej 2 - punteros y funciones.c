/*Programa: programa 2
 * Descripcion: punteros y funciones
 * Revision: 19-10-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
#include <stdio.h>
#include <math.h>
double CalcularSerie (double, int);  //DEVUELVE ALGO
void CalcularSeriePunt (double, int, double *); //NO DEVUELVE NADA. INDICA LA POSICION

int main(void)
{
	double x;
    int n;
    double serie; 
    
    printf("\n Introduzca un numero real:");
    scanf("%lf", &x); //manualmente por variablr
    printf ("\n Introduzca el numero de terminos de la serie a sumar:");
    scanf ("%d", &n);
    //serie = CalcularSerie (x,n);
    printf("\n El resultado de la serie es %.2lf", CalcularSerie(x,n)); //LLAMO LA FUNCION
    //printf("\n .......", serie);
    
    CalcularSeriePunt(x,n, &serie); //es void. no se puede poner de otra forma porque no devuelve nada. pasa por referencia el valor de serie.
    printf("\n El resultado de la serie es %.2lf ", serie ); // LLAMO A LA FUNCION CON EL PUNTERO
    
	return 0;
}

//FUNCION SIN PUNTERO
double CalcularSerie (double x, int n)
{
    int i;
    double serie;
    serie =0; //inicializo el contador//
    //cuando el termino es impar (i), resultado tiene que ser positivo, y viceversa)
    for (i=1; i<=n; i++)
    {
        serie= serie+ pow (-1, i+1)/ pow (x,i); //serie= serie + es = a serie+=
    }
    
    return serie;
}

//FUNCION CON PUNTERO
void CalcularSeriePunt (double x, int n, double *pserie) //TRABAJA SOBRE LA VARIABLE SERIE DE MI MAIN;
{
    int i;
    *pserie=0; //OJO CON EL PUNTERO. EN LA VARIABLE SERIE DE MI MAIN VOY ALMACENANDO LA SERIE//
    for (i=1; i<=n; i++)
    {
        *pserie=*pserie + pow (-1, i+1)/ pow (x,i); //*pserie*=
    }

return; //NO DEVUELVE NADA PORQUE *PSERIE YA ASIGNA EL RESULTADO A LA SERIE DEL MAIN, PORQUE APUNTA A SU DIRECCION EN EL MAIN//
}

/*
AL EJECUTAR
Introduzca un numero real:5
Introduzca el numero de terminos de la serie a sumar:4

El resultado de la serie es 0.17
El resultado de la serie es 0.17
//hay dos resultados porque hicimos dos funciones, pero el resultado demuestra que el programa es correcto.
*/