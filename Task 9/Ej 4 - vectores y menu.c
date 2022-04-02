/*Programa: programa 4
 * Descripcion: Vector de codigos de producto (repaso)
 * Revision: 4-11-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/

#include <stdio.h>
#define N 100
void Eliminar (int *n, float codigos_producto[N]);
void Insertar (int *n, float codigos_producto[N]);
void Mostrar (int n, float codigos_producto[N]);
int main(void)
{
	
    float codigos_producto [N];
    int n;
    int opcion;
    int i;
    
    do
    {
        printf("\n Introduce el numero de codigos de producto (>0):");
        scanf("%d",&n);
        if (n<=0)
        {
            printf("\n Numero erroneo. Debe ser mayor que 0");
        }
    }while (n<=0);
    
    printf ("\n Lectura de los codigos de producto de forma creciente:");
    for (i=0;i<n;i++)
    {
        printf("\n Introduzca el codigo %d: " , i+1);
        scanf ("%f",&codigos_producto[i]);
    }
    
    do
    {
        printf("\n----- Este es el menu------:");
        printf ("\n 1. Eliminar codigo.");
        printf ("\n 2. Insertar codigo.");
        printf ("\n 3. Salir");
        printf("\n\n");
        printf("\n Introduzca la opcion:");
        scanf("%d",&opcion);
        
        switch (opcion)
        {
            case 1:
        
            Eliminar ( &n, codigos_producto); //ALTERA LA VARIABLE N PORQUE SE RESTA UN CODIGO
            Mostrar (n, codigos_producto);
            break;
            
            case 2:
            
            Insertar  (&n,codigos_producto); //SE ALTERA N 
            Mostrar (n, codigos_producto);
            break;
            
            case 3:
            printf("\n Fin del programa.");
            break;
            
            default:
            printf ("\n Opcion erronea.");
        }
          
    }while (opcion!=3);
    
	return 0;
}

void Eliminar (int *n, float codigos_producto[N])
{
    int i;
    float codigo_eliminado;
    int posicion;
    
    printf("\n Introduzca el codigo que desee eliminar:");
    scanf("%f",&codigo_eliminado);
    i=0; //inicializo contadores
    posicion=0;
    while (i<*n)
    {
        if (codigos_producto[i]==codigo_eliminado)
        {
            posicion=i;
        }
    i++;
    }
    
    for (i=posicion;i<*n;i++)
    {
        codigos_producto[i]=codigos_producto[i+1]; //se adelanta una posicion porque hay un codigo menos
    }
    *n=*n-1; //hay un elemento menos
    
    return;
}

void Insertar (int *n, float codigos_producto[N])
{
   int i;
   int posicion;
   float codigo_insertado;
   
   printf("\n Introduzca la posicion del codigo que quiera insertar:");
   scanf("%d",&posicion);
   printf ("\n Introduzca el nuevo codigo:");
   scanf("%f",&codigo_insertado);
   
   for (i=*n;i>posicion-1;i--) //se añade un nuevo codigo por lo que se retrasa una posicion
    {
        codigos_producto[i]=codigos_producto[i-1];
    }
     codigos_producto[posicion-1]=codigo_insertado;
    *n=*n+1; //se añade una nueva posicion 
    return;
}
void Mostrar (int n, float codigos_producto[N])
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("\n %f",codigos_producto[i]);
    }
return;
}
/*AL EJECUTAR

 Introduce el numero de codigos de producto (>0):3
 Lectura de los codigos de producto de forma creciente:
 Introduzca el codigo 1: 123
 Introduzca el codigo 2: 234
 Introduzca el codigo 3: 345

----- Este es el menu------:
 1. Eliminar codigo.
 2. Insertar codigo.
 3. Salir
 Introduzca la opcion:1

 Introduzca el codigo que desee eliminar:234

 123.000000
 345.000000
----- Este es el menu------:
 1. Eliminar codigo.
 2. Insertar codigo.
 3. Salir

 Introduzca la opcion:2
 Introduzca la posicion del codigo que quiera insertar:2
 Introduzca el nuevo codigo:567

 123.000000
 567.000000
 345.000000

----- Este es el menu------:
 1. Eliminar codigo.
 2. Insertar codigo.
 3. Salir

 Introduzca la opcion:3
 Fin del programa.
*/

