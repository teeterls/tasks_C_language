/*Programa: programa 2
 * Descripcion: Leer y escribir datos en una estructura II
 * Revision: 11-11-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
//LEER PASO POR VALOR
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

typedef struct
{
  float t_max;
  float t_min;
}T_MAXMIN;

typedef struct
{
    char nombre [N];
    float v_temp [N];
    int n;
    T_MAXMIN temperatura;
}T_CIUDAD;
T_CIUDAD Leer(); //OJO NO RECIBE NADA. DEVUELVE LOS DATOS DE LA CIUDAD. ES TIPO ESTRUCTURA 
void Mostrar(T_CIUDAD ciudad); 
void MaxMin(T_CIUDAD *pciudad); //le paso la referencia de la ciudad, porque tiene un *puntero

int main(void)
{
	T_CIUDAD ciudad;
    ciudad=Leer (); //OJO. MUY IMPORTANTE   
     MaxMin (&ciudad); //le paso la direccion de memoria, no lo declaro
     Mostrar (ciudad);
	return 0;
}

T_CIUDAD Leer (void)
{
    T_CIUDAD ciudad; //se devuelven sus valores que se guardan en ciudad del main
    int i;

    printf ("\n Introduce el nombre de la ciudad:");
    fflush (stdin);
    gets (ciudad.nombre);
    
    do
    {
        printf ("\n Introduce el numero de temperaturas:");
        scanf("%d",&ciudad.n);
        if (ciudad.n<0 || ciudad.n>N)
        {
            printf ("\n Error. Numero de temperaturas positivo y menor que 100");
        }
    }while (ciudad.n<0 || ciudad.n>N);
    
    for (i=0; i<ciudad.n; i++)
    {
        printf ("\n Introduce la temperatura %d de la ciudad %s:", i+1, ciudad.nombre);
        scanf ("%f",&ciudad.v_temp[i]);
    }
  return ciudad;  
}

void MaxMin(T_CIUDAD *pciudad)
{
  int i;
  
  //hacemos lo mismo pero utilizando el puntero. SIEMPRE
  pciudad->temperatura.t_min=pciudad->v_temp[0]; //(*pciudad).temperatura.t_min es lo mismo
  pciudad->temperatura.t_min=pciudad->v_temp[0];
  
  for (i=1; i<pciudad->n;i++) //OJO CON LA N. MUY IMPORTANTE TAMBIEN CON PUNTERO
  {
      if (pciudad->v_temp[i]>pciudad->temperatura.t_max)
      {
          pciudad->temperatura.t_max=pciudad->v_temp[i];
      }
      
      if (pciudad->v_temp[i]<pciudad->temperatura.t_min)
      {
          pciudad->temperatura.t_min=pciudad->v_temp[i];
      }
  }
    return;
}

void Mostrar (T_CIUDAD ciudad)
{
    int i;
    
    printf ("\n Datos obtenidos: ");
    printf("\n Nombre de la ciudad: %s", ciudad.nombre);
    printf("\n Numero de temperaturas medidas: %d", ciudad.n);
    printf ("\n Temperaturas medidas: ");
    for (i=0; i<ciudad.n; i++)
    {
        printf("\n Temperatura %d: %.2f", i+1, ciudad.v_temp[i]);
    }
    printf("\n La temperatura maxima de la ciudad %s es: %.2f", ciudad.nombre, ciudad.temperatura.t_max);
    printf("\n La temperatura minima de la ciudad %s es: %.2f", ciudad.nombre, ciudad.temperatura.t_min);

return;
}

/*
AL EJECUTAR
Introduce el nombre de la ciudad:Nueva York
 Introduce el numero de temperaturas:3
 Introduce la temperatura 1 de la ciudad Nueva York:20
 Introduce la temperatura 2 de la ciudad Nueva York:30
 Introduce la temperatura 3 de la ciudad Nueva York:40

 Datos obtenidos:
 Nombre de la ciudad: Nueva York
 Numero de temperaturas medidas: 3
 Temperaturas medidas:
 Temperatura 1: 20.00
 Temperatura 2: 30.00
 Temperatura 3: 40.00
 La temperatura maxima de la ciudad Nueva York es: 40.00
 La temperatura minima de la ciudad Nueva York es: 20.00
*/


//VERSION DE LA FUNCION LEER CON PASO POR REFERENCIA UTILIZANDO PUNTERO
//LEER PASO POR REFERENCIA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

typedef struct
{
  float t_max;
  float t_min;
}T_MAXMIN;

typedef struct
{
    char nombre [N];
    float v_temp [N];
    int n;
    T_MAXMIN temperatura;
}T_CIUDAD;

void Leer (T_CIUDAD *pciudad); //PASO POR REFERENCIA. VOID.
void Mostrar(T_CIUDAD ciudad); 
void MaxMin(T_CIUDAD *pciudad);

int main(void)
{
    T_CIUDAD ciudad;
    Leer(&ciudad); //PASO POR REFERENCIA
    MaxMin (&ciudad); //le paso la direccion de memoria, no lo declaro
     Mostrar (ciudad);
	return 0;
}

void Leer (T_CIUDAD *pciudad) 
{
    int i;
    printf ("\n Introduce el nombre de la ciudad:");
    fflush (stdin);
    gets (pciudad->nombre);
    
    do
    {
        printf ("\n Introduce el numero de temperaturas:");
        scanf("%d",&pciudad->n);
        if (pciudad->n<0 || pciudad->n>N)
        {
            printf ("\n Error. Numero de temperaturas positivo y menor que 100");
        }
    }while (pciudad->n<0 || pciudad->n>N);
    
    for (i=0; i<pciudad->n; i++)
    {
        printf ("\n Introduce la temperatura %d de la ciudad %s:", i+1, pciudad->nombre);
        scanf ("%f",&pciudad->v_temp[i]);
    ç
 return;   
}
