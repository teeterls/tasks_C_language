/*Programa: programa 1
 * Descripcion: Leer y escribir datos en una estructura I
 * Revision: 11-11-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/

#include <stdio.h>
#include <string.h>
#define N 100

//codigo de estructuras

typedef struct
{
    float t_max;
    float t_min;

} T_MAXMIN; //nuevo tipo de dato, como int ,float... pero que corresponde a la estructura de datos

typedef struct
{
    char nombre [N]; //vector de caracteres. necesita biblioteca string especifica
    float temp [N]; //vector de decimales.
    int n;
    T_MAXMIN temperatura; //asignar variable con el nuevo tipo de dato creado en la estructura anterior. ESTRUCTURAS ANIDADAS.

}T_CIUDAD; //nuevo tipo de dato

int main(void)
{
	//declaracion de variables
    T_CIUDAD ciudad; //asignar variable con el tipo de dato creado en la segunda estructura
    int i;
   
    //introducir nombre de ciudad
    printf("\n Introduce el nombre de la ciudad: ");
    gets (ciudad.nombre); //NOS REFERIMOS A UN ELEMENTO DENTRO DE UNA ESTRUCTURA CON UN PUNTO
    
    //introducir y validar numero de temperaturas
    do
    {
        printf("\n Introduce el numero de temperaturas de la ciudad %s: ", ciudad.nombre);
        scanf ("%d", &ciudad.n);
        
        if (ciudad.n<0 || ciudad.n>N)
        {
            printf("\n Error. El numero de temperaturas de la ciudad debe ser positivo y menor que 100");
        }
        
    }while (ciudad.n<0 || ciudad.n>N);
    
    //meter temperaturas, rellenar vectores
    for (i=0; i<ciudad.n; i++)
    {
        printf ("\n Introduzca la temperatura %d de la ciudad %s:", i+1, ciudad.nombre);
        scanf("%f", &ciudad.temp[i]);
    }
  
    //busqueda maximo y minimo entre las temperaturas
    ciudad.temperatura.t_max=ciudad.temp[0];
    ciudad.temperatura.t_min=ciudad.temp[0];
    
    for (i=0;i<ciudad.n;i++)
    {
        if (ciudad.temp[i]>ciudad.temperatura.t_max)
        {
            ciudad.temperatura.t_max=ciudad.temp[i];
        }
        if (ciudad.temp[i]<ciudad.temperatura.t_min)
        {
            ciudad.temperatura.t_min=ciudad.temp[i];
        }
    }
   
    //mostramos en pantalla los datos obtenidos 
    printf ("\n Datos obtenidos: ");
    printf("\n Nombre de la ciudad: %s", ciudad.nombre);
    printf("\n Numero de temperaturas medidas: %d", ciudad.n);
    printf ("\n Temperaturas medidas: ");
    for (i=0; i<ciudad.n; i++)
    {
        printf("\n Temperatura %d: %.2f", i+1, ciudad.temp[i]);
    }
    printf("\n La temperatura maxima de la ciudad %s es: %.2f", ciudad.nombre, ciudad.temperatura.t_max);
    printf("\n La temperatura minima de la ciudad %s es: %.2f", ciudad.nombre, ciudad.temperatura.t_min);
    
	return 0;
}

/*
AL EJECUTAR
 Introduce el nombre de la ciudad: Mexico

 Introduce el numero de temperaturas de la ciudad Mexico: -2

 Error. El numero de temperaturas de la ciudad debe ser positivo y menor que 100
 Introduce el numero de temperaturas de la ciudad Mexico: 102
 Error. El numero de temperaturas de la ciudad debe ser positivo y menor que 100
 Introduce el numero de temperaturas de la ciudad Mexico: 5
 Introduzca la temperatura 1 de la ciudad Mexico:30
 Introduzca la temperatura 2 de la ciudad Mexico:34
 Introduzca la temperatura 3 de la ciudad Mexico:38
 Introduzca la temperatura 4 de la ciudad Mexico:40
 Introduzca la temperatura 5 de la ciudad Mexico:39

 Datos obtenidos:
 Nombre de la ciudad: Mexico
 Numero de temperaturas medidas: 5
 Temperaturas medidas:
 Temperatura 1: 30.00
 Temperatura 2: 34.00
 Temperatura 3: 38.00
 Temperatura 4: 40.00
 Temperatura 5: 39.00
 La temperatura maxima de la ciudad Mexico es: 40.00
 La temperatura minima de la ciudad Mexico es: 30.00
*/