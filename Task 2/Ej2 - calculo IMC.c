
/* Programa: programa 2
 * Descripcion: calculo del IMC
 * Revision: 20-09-17
 * Autor: Teresa Gonzalez Garcia
 * Clase 1º GITT */

#include <stdio.h>
#include <math.h>

int main(void)
{
    float peso;
    float altura;
    float IMC;
    
    printf ("\nIntroduzca su peso en kilogramos:");
    scanf("%f",&peso);
    printf ("\nIntroduzca su altura en metros:");
    scanf("%f",&altura);
    
    IMC=peso/pow(altura,2);
    printf ("\nSu indice de masa corporal equivale a: %.2f\n",IMC);
    
    if(IMC<18.5)
    {
        printf("\nSu estado nutricional es de infrapeso\n ");
        
    }else{
        if(IMC>=18.5 && IMC<25)
        {
          printf("\nSu estado nutricional es normal\n");  
        }else{
            if(IMC>=25 && IMC<30)
            {
                printf("\nSu estado nutricional es de sobrepeso\n");
            }else{
                if(IMC>=30)
                {
                    printf("\nSu estado nutricional es de obesidad\n");
                }
            }
        }
    }
    return 0;
}

/*
AL EJECUTAR
Introduzca su peso en kilogramos:70

Introduzca su altura en metros:1.30

Su indice de masa corporal equivale a: 41.42

Su estado nutricional es de obesidad
-
Introduzca su peso en kilogramos:40

Introduzca su altura en metros:1.60

Su indice de masa corporal equivale a: 15.63

Su estado nutricional es de infrapeso
-
Introduzca su peso en kilogramos:60

Introduzca su altura en metros:1.70

Su indice de masa corporal equivale a: 20.76

Su estado nutricional es normal

*/

