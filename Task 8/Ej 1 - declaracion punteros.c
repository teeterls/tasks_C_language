/*Programa: programa 1
 * Descripcion: declaracion de punteros
 * Revision: 19-10-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
#include <stdio.h>

int main(void)
{
	int i;
    int *pi;
    double d;
    double *pd;
    
    //hacer que las variables puntero apunten a las zonas de memoria de las variables normales//
    
    pi=&i;
    pd=&d; //OJO AQUI NO * SI NO & PORQUE INDICAMOS LA DIRECCION DE ESA FORMA
    
    //inicializar valores mediante asignaciones a las variables normales//
    
    i=5;
    d=5.2;
    
    //mostrar los valores asignados, utilizando las variables normales y las tipo puntero//
    
    printf("\n El valor de i es: %d y el valor de d es %lf", i, d);
    printf("\n El valor de i es: %d y el valor de d es %lf", *pi, *pd);
    
    //cambiar los valores utilizando las variables tipo puntero//
    
    *pi=*pi+5;
    *pd=*pd+3; //OJO CON LOS *
    
    //volver a mostrar los valores asignados, utilizando las variables normales y las tipo puntero//
    
    printf("\n El valor de i es: %d y el valor de d es %lf", i, d);
    printf("\n El valor de i es: %d y el valor de d es %lf", *pi, *pd);
    printf (“\n\n\n\n”);
        //EXTRA
    printf("\n Valor guardado en la variable i: %d", i);
    printf ("\n Posicion de la variable i: %x", &i);
    printf ("\n Valor guardado en el puntero pi: %d", *pi);
    printf("\n Posicion guardada en el puntero pi: %x", pi);
    
   printf (“\n\n\n\n”);
    
    printf("\n Valor guardado en la variable d: %lf", d);
    printf ("\n Posicion de la variable d: %x", &d);
    printf ("\n Valor guardado en el puntero pd: %lf", *pd);
    printf("\n Posicion guardada en el puntero pd: %x", pd);

    return 0;
}
/*
AL EJECUTAR
El valor de i es: 5 y el valor de d es 5.200000
El valor de i es: 5 y el valor de d es 5.200000
El valor de i es: 10 y el valor de d es 8.200000
El valor de i es: 10 y el valor de d es 8.200000
 
Valor guardado en la variable i: 10
Posicion de la variable i: 62fe3c
Valor guardado en el puntero pi: 10
Posicion guardada en el puntero pi: 62fe3c

Valor guardado en la variable d: 8.200000
Posicion de la variable d: 62fe30
Valor guardado en el puntero pd: 8.200000
Posicion guardada en el puntero pd: 62fe30
*/
