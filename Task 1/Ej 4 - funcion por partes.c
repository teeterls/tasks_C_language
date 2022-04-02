/*Programa: programa 4
 * Descripcion: calculo de la funcion definida por partes
 * Revision: 18-09-2017
 * Autor: Teresa Gonzalez Garcia
 * Clase: 1º GITT*/

#include <stdio.h>
#include <math.h> //vamos a usar la funcion de pow//

  int main(void)
  {
	float a;
    float x;
    printf("\n Introduzca el valor de x: ");
    scanf("%f", &a);
    if (a<=3) {
        x = pow(a,2);
   }
    
    else {
        x = (2*a)/3;
    }
    printf("\n El valor de x es: %.2f \n", x);
	return 0;
}

  AL EJECUTAR

Introduzca el valor de x: 4

 El valor de x es: 2.67
_
Introduzca el valor de x: 2

 El valor de x es: 4.00


