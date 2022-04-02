/*Programa: programa 3
 * Descripcion: calculo del area de un trapecio
 * Revision: 18-09-2017
 * Autor: Teresa Gonzalez Garcia
 * Clase: 1º GITT*/

   #include <stdio.h>
   int main(void)
   {
    float B; //base mayor trapecio//
    float b; //base menor trapecio//
    float h; //altura trapecio//
    float a; //area trapecio//
    
    printf("\n Introduzca el valor de la base mayor:");
    scanf("%f", &B);
    printf("\nIntroduzca el valor de la base menor:");
    scanf("%f", &b);
    printf("\nIntroduzca el valor de la altura:");
    scanf("%f",&h);

   a=(B+b)*(h/2);
    printf("\nEl valor del area del trapecio es:%.2f”,                              a)
	return 0;
}
   AL EJECUTAR
Introduzca el valor de la base mayor:8

Introduzca el valor de la base menor:6

Introduzca el valor de la altura:4

 El valor del area del trapecio es 28.00
