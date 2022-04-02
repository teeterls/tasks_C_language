
/* Programa: programa 3
 * Descripcion: primer menú 
 * Revision: 20-09-17
 * Autor: Teresa Gonzalez Garcia
 * Clase 1º GITT */

#include <stdio.h>
#include <math.h>

int main(void)
{
    float a;
    float b;
    float mayor;
    float media;
    float diferencia;
    int opcion;
    
    printf("\nIntroduzca el primer numero real:");
    scanf("%f",&a);
    printf("\nIntroduzca el segundo numero real:");
    scanf("%f",&b);
    
    printf("El menu es el siguiente:\n");
    printf("\n1. Numero mayor al cuadrado");
    printf("\n2. Media");
    printf("\n3. Diferencia");
    printf("\n4.Salir");
   
    printf("\n Introduzca una opcion:");
    scanf("%d", &opcion);
    
    switch (opcion)
    {
        case 1:
        if (a>b)
        {
            mayor=pow(a,2);
            printf("El resultado es:%.2f\n",mayor);
        } else{
            mayor=pow(b,2);
            printf("El resultado es:%.2f\n",mayor);
        }
        break;
        
        case 2:
        media= (a+b)/2;
        printf("El resultado es:%.2f\n", media);
        break;
        
        case 3:
        diferencia= a-b;
        printf("El resultado es:%.2f\n", diferencia);
    break;
        
        case 4:
        printf ("Fin del programa\n");
        break;

        default: if (opcion>4)
        printf ("Error. Intente otro valor");
    }

    return 0;
}

/*

AL EJECUTAR
Introduzca el primer numero real:4

Introduzca el segundo numero real:5

El menu es el siguiente:

1. Numero mayor al cuadrado
2. Media
3. Diferencia
4.Salir
 Introduzca una opcion:1
El resultado es:25.00
-
Introduzca el primer numero real:3

Introduzca el segundo numero real:4
El menu es el siguiente:
1. Numero mayor al cuadrado
2. Media
3. Diferencia
4.Salir
 Introduzca una opcion:2
El resultado es:3.50
-
Introduzca el primer numero real:2

Introduzca el segundo numero real:2
El menu es el siguiente:

1. Numero mayor al cuadrado
2. Media
3. Diferencia
4.Salir
 Introduzca una opcion:3
El resultado es:0.00
-Introduzca el primer numero real:5

Introduzca el segundo numero real:4
El menu es el siguiente:

1. Numero mayor al cuadrado
2. Media
3. Diferencia
4.Salir
 Introduzca una opcion:4
Fin del programa
-Introduzca el primer numero real:4

Introduzca el segundo numero real:5
El menu es el siguiente:

1. Numero mayor al cuadrado
2. Media
3. Diferencia
4.Salir
 Introduzca una opcion:5
Error. Intente otro valor

*/
