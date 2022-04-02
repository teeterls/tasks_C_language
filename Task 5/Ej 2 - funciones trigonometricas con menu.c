/*Programa: programa 2
 * Descripcion: Funciones trigonometricas
 * Revision: 04-10-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1416

float Seno (float angulo, int n);
float Coseno (float angulo, int n);
float Tangente (float angulo, int n);
int Factorial (int num);

int main(void)
{
    float angulo_grad; //ANGULO EN GRADOS
    float angulo_rad; //ANGULO EN RADIANES
    int precision; //NUMERO DE TERMINOS DE DESARROLLO DEL POLINOMIO
    int opcion; //menu
    int seno;
    int coseno;
    int tangente;
    
    printf("\n Introduzca el angulo en grados:");
    scanf("%f", &angulo_grad);
    angulo_rad=angulo_grad*PI/180;
    printf("\n El angulo en radianes es: %f", angulo_rad);
    printf("\n Introduzca la precision:");
    scanf("%d",&precision);
    
    //MENU EN BUCLE CON DO WHILE Y CON SWITCH
    do{
        printf("\n MENU:\n");
        printf("\n1. Calcular seno");
        printf("\n2. Calcular coseno");
        printf("\n3. Calcular tangente");
        printf("\n4. Salir");
        
        printf("\n Escoja una opcion:");
        scanf("%d", &opcion);
        
        switch (opcion)
        {
            case 1:
                seno= Seno (angulo_rad, precision); //EMPEZAMOS A LLAMAR A LAS FUNCIONES
                printf("\n El seno del angulo %f es %d", angulo_rad, seno);
                break;
            
            case 2:
                coseno= Coseno ( angulo_rad,  precision);
                printf("\n El coseno del angulo %f es %d", angulo_rad, coseno);
                break;
            
            case 3:
                tangente= Tangente ( angulo_rad, precision);
                printf("\n La tangente del angulo %f es %d", angulo_rad, tangente);
                break;
                
            case 4:
                printf("\n Fin del programa.");
                break;
            
            default:
            printf ("\n Opcion de menu erronea.");
        }   
    }while (opcion!=4);
	
	return 0;
}

//FUNCIONES
float Seno (float angulo, int n)
{
    int i;
    float serie;
    serie=0;
    for (i=0;i<n;i++)
    {
        serie=serie+pow(angulo,2*i+1)*pow(-1,i)/Factorial (2*i+1); //FACTORIAL OTRA FUNCION 
    }
    return serie; //NO ES VOID
}

float Coseno (float angulo, int n)
{
    int i;
    float serie;
    serie=0;
    for(i=0;i<n;i++)
    {
        serie=serie+pow(angulo,2*i)*pow(-1,i)/Factorial (2*i);
    }
   return serie;
}

float Tangente (float angulo, int n)
{
   return  Seno ( angulo,  n)/Coseno ( angulo, n); //HAGO LA OPERACION DIRECTAMENTE CON LAS FUNCIONES SEN/COS=TG
 
}

int Factorial (int num)
{
    int f;
    int i;
    f=1;
    for (i=1;i<=num;i++)
    {
        f=f*i;
    }
    return f;
}

/*
AL EJECUTAR

 Introduzca el angulo en grados:45

 El angulo en radianes es: 0.785400
 Introduzca la precision:3

 MENU:

1. Calcular seno
2. Calcular coseno
3. Calcular tangente
4. Salir
 Escoja una opcion:1

 El seno del angulo 0.785400 es 0
 MENU:

1. Calcular seno
2. Calcular coseno
3. Calcular tangente
4. Salir
 Escoja una opcion:3

 La tangente del angulo 0.785400 es 0
 MENU:

1. Calcular seno
2. Calcular coseno
3. Calcular tangente
4. Salir
 Escoja una opcion:4

 Fin del programa.
*/