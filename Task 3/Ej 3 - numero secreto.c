/* Programa: programa 3
 * Descripcion: adivinar un número secreto
 * Revision: 20-09-17
 * Autor: Teresa Gonzalez Garcia
 * Clase 1º GITT */
#include <stdio.h>
#define SECRETO 783

int main(int argc, char **argv)
{
	int numero;
    int num_intentos;
    
    num_intentos = 0;
    /*Pedimos al usuario que introduzca un número entero cualquiera*/
    do{
        printf("\nIntroduzca un numero entero: ");
        scanf("%d" ,&numero);
        num_intentos++;
        if (numero==SECRETO) {
            printf("\nEnhorabuena, ha acertado el numero.");
        }
         else{
            printf("\nLo siento ha fallado");
            if (numero<SECRETO){
                printf("\nIntroduzca un numero mayor");
            }
            else {
             printf("\nIntroduzca un numero menor al anterior");
            }
         }
    }while(numero != SECRETO );
     
        printf("El numero correcto es: %d, lo ha adivinado en %d intentos",SECRETO, num_intentos);
        return 0;
}

/*
AL EJECUTAR

Introduzca un numero entero: 5

Lo siento ha fallado
Introduzca un numero mayor
Introduzca un numero entero: 890

Lo siento ha fallado
Introduzca un numero menor al anterior
Introduzca un numero entero: 0

Lo siento ha fallado
Introduzca un numero mayor
Introduzca un numero entero: 87

Lo siento ha fallado
Introduzca un numero mayor
Introduzca un numero entero: 783

Enhorabuena, ha acertado el numero. el numero correcto es: 783, lo ha adivinado en 5 intentos
*/
