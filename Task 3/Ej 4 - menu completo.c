/* Programa: programa 4
 * Descripcion: programa con menú
 * Revision: 20-09-17
 * Autor: Teresa Gonzalez Garcia
 * Clase 1º GITT */

#include <stdio.h>
#define PI 3.1416

int main(void)
{
    float longitud;
    float altura;
    float area;
    float lado;
    float radio;
    float base;
    float altura1;
    char opcion;
        
    do{
        fflush(stdin);
        printf("\nCalculo de areas de distintas figuras");
        printf("\nMenu de opciones:  ");
        printf("\nR,r:Calcular area de un rectangulo");
        printf("\nS,s:Calcular area de un cuadrado");
        printf("\nC,c:Calcular area de un circulo");
        printf("\nT,t:Calcular area de un triangulo");
        printf("\nE,e:Salir del programa");
        printf("\nIntroduzca la opcion:  ");
        scanf("%c" , &opcion);
 
        switch(option) {
            
            case 'r':
            case 'R':
                printf("\nIntroduzca la longitud del rectangulo: ");
                scanf("\%f" ,&longitud);
                printf("\nIntroduzca la altura del rectangulo: ");
                scanf("\%f" ,&altura);
                area = altura*longitud;
                printf("\nEl area del rectangulo es: %f ", area);
                break;

            case 's':
            case 'S':
                printf("\nIntroduzca el lado del cuadrado: ");
                scanf("\%f" ,&lado);
                area = lado*lado;
                printf("\nEl area del cuadrado es: %f", area);
                break;
                
            case 'c':
            case 'C':
                printf("\nIntroduzca el radio del circulo: ");
                scanf("\%f" ,&radio);
                area = PI*radio*radio;
                printf("\nEl area del circulo es: %f", area);
                break;
                
            case 't':
            case 'T':
                printf("\nIntroduzca la base del triangulo: ");
                scanf("\%f" ,&base);
                printf("\nIntroduzca la altura del triangulo: ");
                scanf("\%f" ,&altura1);
                area = altura*base;
                printf("\nEl area del triangulo es: %f", area);
                break;
                
            case 'e':
            case 'E':
                printf("\nHa solicitado salir del programa");
                break;
        default:
            printf("\nError: opcion no existente");
        }  
    }while( option != 'e' && option != 'E');
   
   return 0;
}
AL EJECUTAR

Calculo de areas de distintas figuras
Menu de opciones:
R, r:Calculo area de un rectangulo
S, s:Calculo area de un cuadrado
C, c:Calculo area de un circulo
T, t:Calculo area de un triangulo
E, e:Salir del programa
Introduzca la opcion:  s

Introduzca el lado del cuadrado: 6

El area del cuadrado es: 36.00
Calculo de areas de distintas figuras
Menu de opciones:
R, r:Calculo area de un rectangulo
S, s:Calculo area de un cuadrado
C, c:Calculo area de un circulo
T, t:Calculo area de un triangulo
E, e:Salir del programa
Introduzca la opcion:  f

Error: opcion no existente
Calculo de areas de distintas figuras
Menu de opciones:
R, r:Calculo area de un rectangulo
S, s:Calculo area de un cuadrado
C, c:Calculo area de un circulo
T, t:Calculo area de un triangulo
E, e:Salir del programa
Introduzca la opcion:  e

Ha solicitado salir del programa



