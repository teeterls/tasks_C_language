/* Programa: programa 1
 * Descripcion: calculo de raices de una ecuacion de segundo grado
 * Revision: 20-09-17
 * Autor: Teresa Gonzalez Garcia
 * Clase 1º GITT */
 
#include <stdio.h>
#include <math.h>

int main(void)
{ 
    float a;
    float b;
    float c;
    float discriminante;
    float x;
    float x1;
    float x2;
    
    printf("Introduzca el valor de a:");
    scanf("%f",&a);
    printf("\n Introduzca el valor de b:");
    scanf("%f",&b);
    printf("\n Introduzca el valor de c:");
    scanf("%f",&c);
    
    if (a==0 && b==0)
    {
        x=0;
        printf("La solucion es degenerada, c tiene que ser necesariamente 0\n");
    }else{
    
    if (a==0)
    {
        x=-c/b;
        printf("La solucion es lineal, x = %.2f\n",x);
        
    } else
    { discriminante= pow(b,2)- (4*a*c);
        if(discriminante==0)
        {
            printf("La solucion es doble\n");
            x=-b/2*a;
            printf("\n x= %.2f ",x);
        } 
        if(discriminante>0)
        {
            printf("Hay dos soluciones o raíces:\n");
            x1=(-b+discriminante)/2*a;
            x2=(-b-discriminante)/2*a;
            printf("\n x1= %.2f",x1);
            printf("\n x2= %.2f",x2);
        }
        if(discriminante<0)
        {
            printf("La solucion son raices complejas\n");
        }
   }
    }          
	return 0;
}

/*

AL EJECUTAR
Introduzca el valor de a:0

 Introduzca el valor de b:0

 Introduzca el valor de c:5

La solucion es degenerada, c tiene que ser necesariamente 0
-
Introduzca el valor de a:0

 Introduzca el valor de b:8

 Introduzca el valor de c:4

La solucion es lineal, x = -0.50
-
Introduzca el valor de a:1

 Introduzca el valor de b:-2

 Introduzca el valor de c:1
La solucion es doble

 x= 1.00
-
Introduzca el valor de a:-1

 Introduzca el valor de b:2

 Introduzca el valor de c:1

Hay dos soluciones o raíces:

 x1= -3.00
 x2= 5.00
-
Introduzca el valor de a:6

 Introduzca el valor de b:5

 Introduzca el valor de c:4

La solucion son raices complejas
*/


/* Programa: programa 2
 * Descripcion: calculo del IMC
 * Revision: 20-09-17
 * Autor: Teresa Gonzalez Garcia
 * Clase 1º GITT */

