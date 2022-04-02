/*Programa: programa 2
 * Descripcion: Funcion MiPotencia()
 * Revision: 27-09-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
#include <stdio.h>
float MiPotencia (float base , int e);
int main(void)
{
	float b;
    int exponente;
    float potencia;
    
    do{
      printf ("\nIntroduzca la base:") ;
      scanf ("%f",&b);
      printf ("\n Introduzca el exponente:");
      scanf ("%d", &exponente);
        if (exponente<0)
        {
            printf("\n Error, el exponente debe ser positivo");
        }
    }while (exponente<0);
    
    potencia= MiPotencia  (b, exponente);
    printf ("El resultado de la potencia es: %.2f", potencia);
    
	return 0;
}

    float MiPotencia (float base, int e)
    {
        int i;
        float result;
    //inicializando variables//
        result =base;
        for (i=1; i<e; i++)
        {
        result=result*base;
        }
    return result;
    }
    
/*
AL EJECUTAR
Introduzca la base:2

 Introduzca el exponente:-3

 Error, el exponente debe ser positivo
Introduzca la base:2

 Introduzca el exponente:3
El resultado de la potencia es: 8.00
Press any key to continue.
*/
