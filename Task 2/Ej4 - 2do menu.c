/* Programa: programa 4
 * Descripcion: segundo menú 
 * Revision: 20-09-17
   * Autor: Teresa Gonzalez Garcia
 * Clase 1º GITT */
#include <stdio.h>
#include <math.h>
#define PI 3.1416
int main(void)
{
    float r;
    float lc;
    float lt;
    float area;
    float perc;
    float pert;
    char opción;
    
    printf("El menu es el siguiente:\n");
    printf("\nA. Area de una circunferencia");
    printf("\nB. Perimetro de un cuadrado");
    printf("\nC. Perimetro de un triangulo");
    printf("\nD.Salir");
   
    printf("\n Introduzca una opcion:");
     fflush(stdin);
     scanf("%c", &opcion);
   
    switch (opcion)
    {
        case 'A':
        case 'a':
        printf("\nIntroduzca el radio de la circunferencia:");
        scanf("%f", &r);
        area= PI* pow(r,2);
        printf("El resultado del area es:%.2f", area);
        break;
        
        case 'B':
        case 'b':
        printf("\nIntroduzca el lado del cuadrado:");
        scanf("%f", &lc);
        perc=4*lc;
        printf("El resultado del perimetro del cuadrado es:%.2f", perc);
        break;
        
        case 'C':
        case 'c':
        printf("\nIntroduzca el lado del triangulo:");
        scanf("%f", &lt);
        pert=3*lt;
        printf("El resultado del perimetro del triangulo es:%.2f",pert);
        break;
        
        case 'D':
        case 'd':
        printf ("Fin del programa\n");
        break;
        
        default: 
        printf("Error. Introduzca una opcion valida\n");
        
    }
    return 0;
}

/*
AL EJECUTAR
El menu es el siguiente:

A. Area de una circunferencia
B. Perimetro de un cuadrado
C. Perimetro de un triangulo
D.Salir
 Introduzca una opcion:A

Introduzca el radio de la circunferencia:2
El resultado del area es:12.57
-
El menu es el siguiente:

A. Area de una circunferencia
B. Perimetro de un cuadrado
C. Perimetro de un triangulo
D.Salir
 Introduzca una opcion:E
Error. Introduzca una opcion valida
-
El menu es el siguiente:

A. Area de una circunferencia
B. Perimetro de un cuadrado
C. Perimetro de un triangulo
D.Salir
 Introduzca una opcion:B

Introduzca el lado del cuadrado:4
El resultado del perimetro del cuadrado es:16.00
-
El menu es el siguiente:

A. Area de una circunferencia
B. Perimetro de un cuadrado
C. Perimetro de un triangulo
D.Salir
 Introduzca una opcion:B

Introduzca el lado del cuadrado:4
El resultado del perimetro del cuadrado es:16.00

*/