/*Programa: programa 1
 * Descripcion: calculo de la resistencia equivalente de dos resistencias conectadas en serie y en paralelo
 * Revision: 18-09-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
#include <stdio.h>
int main(void)
{
    float r1;//valor de la resistencia 1//
    float r2;// valor de la resistencia 2//
    float req_serie; //valor de la resistencia en serie//
    float req_par; //valor de la resistencia en paralelo//
    
    printf ("\nIntroduzca el valor de la resistencia 1:");
    scanf ("%f", &r1);
    printf ("\nIntroduzca el valor de la resistencia 2:");
    scanf ("%f", &r2);

    req_serie= r1+r2;
    req_par= (r1*r2)/req_serie;
    
    printf ("\nLa resistencia equivalente en conexion serie es %.2f\n", req_serie);
    printf ("\nLa resistencia equivalente en conexion en paralelo es %.2f\n", req_par)	
	return 0;
}
AL EJECUTAR:
Introduzca el valor de la resistencia 1:2
Introduzca el valor de la resistencia 2:1

La resistencia equivalente en conexion serie es 3.00
La resistencia equivalente en conexion en paralelo es 0.67

