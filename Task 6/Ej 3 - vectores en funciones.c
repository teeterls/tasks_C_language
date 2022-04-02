/*Programa: programa 3
 * Descripcion: paso de vectores a funciones
 * Revision: 12-10-2017
 * Autor: Teresa Gonzalez Garcia
 * Clase: 1º GITT*/
#include <stdio.h>
#define N 100
void Pedir_Datos (int codigos[], float saldos[], int n);
void Movimientos (int codigos[], float saldos[], int n);
int Buscar_Clientes(int codigos[], float saldos[], int n, float limite, int buscados[]);
void Mostrar_Datos_Enteros (int codigos[], int n);
void Mostrar_Datos_Reales (float saldos[], int n);

 //NO DEVUELVE NADA POR ESO ES VOID. NO ES NINGUN RESULTADO
int main(void)
{
	int n;
    int codigos [N]; //primer vector
    float saldos [N]; //segundo vector NUMEROS REALES
    int i;
    char opcion;
    float limite;
    int buscados [N];

    do
    {
    printf("\n Introduzca el numero de clientes:");
    scanf("%d",&n);
        if (n<0 || n>100)
        {
            printf("Error. El numero de clientes debe ser positivo y menor de 100");
        }
    }while ((n<0) || (n>100));
    
    //AHORA INICIALIZAMOS LOS VECTORES
    

    Pedir_Datos(codigos,saldos,n); //ESTOY LLAMANDO A LA FUNCION. NO DEVUELVE NADA. PUNTO Y COMA
    
    //AHORA MOSTRAR POR PANTALLA EL RESULTADO DE LA FUNCION
    
    for (i=0;i<n;i++)
    {
        printf("\n El codigo del cliente %d es: %d", i+1, codigos[i]); //OJO I+1 PORQUE LA POSICION EMPIEZA EN 0 Y ACABA EN N-1
        printf("\n El saldo del cliente %d es: %.2f", i+1, saldos[i]);
    }
    
    do
    {
      printf ("\n Este es el menu:");  
      printf("\n a. Ingresar dinero");
      printf("\n b. Buscar clientes");
      printf("\n c. Ver datos");
      printf("\n d. Salir del programa");
      
      printf("\n Introduzca la opcion:");
      fflush(stdin);
      scanf("%c", &opcion);
      
      switch (opcion)
      {
        case 'a':
        case 'A':
        
        Movimientos (codigos, saldos, n);
        break;
        
        case 'b':
        case 'B':
        
        printf("\n Introduzca la cantidad limite de dinero:");
        scanf("%f",&limite);
        
        printf("\n Los clientes que superan el limite de dinero son:");
        Buscar_Clientes (codigos, saldos, n, limite, buscados);
        
        break;
        
        case 'c':
        case 'C':
        
        printf("\n Los codigos de los clientes son: ");
        Mostrar_Datos_Enteros (codigos, n);
        
        printf("\n Los saldos de los cientes son:");
        Mostrar_Datos_Reales (saldos, n);
        
        break;
        
        case 'd':
        case 'D':
        
        printf("\n Fin del programa");
        
        break;
        
        default:
        printf("\n Opcion erronea");
    
      }
    
    }while (opcion!='d' && opcion!= 'D');
	return 0;
}


void Pedir_Datos (int codigos[], float saldos[], int n) //SIN PUNTO Y COMA PORQUE YA NO ES UNA LLAMADA SI NO LA PROPIA FUNCION
//CON LOS VECTORES SE TRABAJA CON LOS ORIGINALES MIENTRAS QUE DE LAS VARIABLES SOLO SE GUARDA EL VALOR//
{
    int i;
    
    printf ("\n Peticion de datos:");
    printf ("\n============");
    
    for (i=0;i<n;i++)
    {
        do
        {
            printf("\n\nIntroduce el codigo del cliente %d: ",i + 1);
            scanf("%d", &codigos[i]); //OJO CODIGOS ES UN VECTOR
            if (codigos[i]<0)
            {
                printf("Error. El codigo debe ser positivo");
            }
        
        }while (codigos[i]<0);
        do
        {
            printf("\n\n Introduce el saldo del cliente %d:", i+1);
            scanf("%f", &saldos[i]); //OJO SALDOS ES UN VECTOR
            if (saldos[i]<0)
            {
               printf("\nError. El saldo debe ser positivo");
            }
        }while (saldos[i]<0);
    
    }
    
    return;
}

void Movimientos (int codigos[], float saldos[], int n)
{
   float dinero;
    int codigo_c;
    int i;
    int opc;
    
    
    printf("\n Introduzca el codigo del cliente:");
    scanf("%d", &codigo_c);
    for (i=0;i<n;i++) //pasar posicion de cada cliente//
    {
        do{
    printf("\n Este es el menu:");
    printf("\n1. Sacar dinero");
    printf("\n2. Depositar dinero");
    
    printf("\n Introduzca la opcion:");
    scanf("%d",&opc);
    
    switch (opc)
    {
        case 1:
        
        for (i=0;i<n;i++)
        {
            if (codigo_c==codigos[i])
            {
                do{
                printf("\n Introduce la cantidad de dinero que quieras sacar:");
                scanf("%f", &dinero);
                if (dinero>saldos[i])
                {
                    printf("\n Error. El dinero sacado debe ser menor que el saldo");
                }
                }while (dinero>saldos[i]);
            }
        
            saldos[i]= saldos[i] - dinero;
            
            printf("\n El dinero sacado es %.2f", dinero);
            printf("\n El saldo que queda en la cuenta del cliente %d es %f", codigo_c, saldos[i]);
        }
        break;
        
        case 2:
    
        for (i=0;i<n;i++)
        {
            if (codigo_c==codigos[i])
            {
                
                    printf("\n Introduce la cantidad de dinero que quieres depositar:");
                    scanf("%f",&dinero);
            }
        saldos[i]= saldos[i] + dinero;
        }
        
        printf("\n El dinero depositado es %.2f", dinero);
        printf("\n El saldo total que hay en la cuenta del cliente %d es %f", codigo_c, saldos[i]);
        break;
        
        default:
        printf("\n Opcion erronea");
    }
}while (codigo_c==codigos[i]);
    }
    
    return;
}


int Buscar_Clientes (int codigos[], float saldos[], int n, float limite, int buscados[])
{
  int i;
  int j;
  j=0; //inicializar el contador, saber los clientes que superan el limite//
  for (i=0;i<n;i++)
  {
      if (saldos[i]> limite)
      {
          j++;
          buscados[i]=codigos[i];
      }
  }
  
  Mostrar_Datos_Enteros (codigos, n);
  return buscados[i];
}   

void Mostrar_Datos_Enteros(int codigos[], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf ("\n Codigo del cliente %d : %d", i+1, codigos[i]);
    }
    
return;
}

void Mostrar_Datos_Reales (float saldos[], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("\n Saldo del cliente %d : %f", i+1, saldos [i]);
    }

return;
}
   

/*
AL EJECUTAR: con ERRORES

 Introduzca el numero de clientes:2

 Peticion de datos:
============

Introduce el codigo del cliente 1: 123
Introduce el saldo del cliente 1:20
Introduce el codigo del cliente 2: 234
Introduce el saldo del cliente 2:40

 El codigo del cliente 1 es: 123
 El saldo del cliente 1 es: 20.00
 El codigo del cliente 2 es: 234
 El saldo del cliente 2 es: 40.00
 
Este es el menu:
 a. Ingresar dinero
 b. Buscar clientes
 c. Ver datos
 d. Salir del programa
 Introduzca la opcion:a

 Introduzca el codigo del cliente:123

 Este es el menu:
1. Sacar dinero
2. Depositar dinero
 Introduzca la opcion:1

 Introduce la cantidad de dinero que quieras sacar:20

 El dinero sacado es 20.00
 El saldo que queda en la cuenta del cliente 123 es 0.000000
 El dinero sacado es 20.00
 El saldo que queda en la cuenta del cliente 123 es 20.000000
 
 Este es el menu:
 a. Ingresar dinero
 b. Buscar clientes
 c. Ver datos
 d. Salir del programa
 Introduzca la opcion:c

 Los codigos de los clientes son:
 Codigo del cliente 1 : 123
 Codigo del cliente 2 : 234
 Los saldos de los cientes son:
 Saldo del cliente 1 : 0.000000
 Saldo del cliente 2 : 20.000000
 
Este es el menu:
 a. Ingresar dinero
 b. Buscar clientes
 c. Ver datos
 d. Salir del programa
 Introduzca la opcion:b

 Introduzca la cantidad limite de dinero:20

 Los clientes que superan el limite de dinero son:
 Codigo del cliente 1 : 123
 Codigo del cliente 2 : 234
 
Este es el menu:
 a. Ingresar dinero
 b. Buscar clientes
 c. Ver datos
 d. Salir del programa
 Introduzca la opcion:d

 Fin del programa
*/
