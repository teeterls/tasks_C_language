/* Programa: programa 1
 * Descripcion: suma de una serie
 * Revision: 20-09-17
 * Autor: Teresa Gonzalez Garcia
 * Clase 1º GITT */

#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    float x;
    float suma;
    float termino;
    int i;
    
    do{
        printf ("\nIntroduzca el numero de terminos:");
        scanf("%d",&n);
        if (n<=0)
        {
            printf("el valor de n debe ser positivo\n");
        }
    }while (n<=0);
    
    do{
        printf("\nIntroduce un valor x comprendido entre 0 y 1:");
        scanf("%f",&x);
        if (x<0 || x>1)
        {
            printf("El valor de x debe estar comprendido entre 0 y 1");
        }
    }while(x<0 || x>1);
    
    //primera forma//
    suma=1;
    termino=-x;
    for (i=2;i<n;i++){
        suma= suma + termino;
        termino = termino *2;
    }
    printf ("El resultado de la suma es %.2f",suma);
    
    //segunda forma//
    for (i=1; i<= n; i++){
        termino= pow(x, i-1);
        termino = pow(-1, i-1) * pow(x, i-1);
        suma = suma + termino;
    }
	return 0;
}
/*
AL EJECUTAR
Introduzca el numero de terminos:4

Introduce un valor x comprendido entre 0 y 1:0.5

El resultado de la suma es -0.50
*/
