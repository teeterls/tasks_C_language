3.	Código Fuente
/*Programa: programa 3
 * Descripcion: numeros primos
 * Revision: 04-10-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
//PRIMERA PARTE -> numero primo o no
#include <stdio.h>
int Primo  (int num);
int main (void) 
{
    int n;
    int primo;
 
    printf("\nIntroduce un numero del cual quieres saber si es un numero primo o no:");
    scanf("%d", &n);
 
    primo= Primo (n);
    if (primo==1)
    {
        printf ("El numero %d es un numero primo\n",n);
    }
    else{
        printf ("El numero %d no es un numero primo\n",n);
    }
 return 0;
}

int Primo (int num)
 {
     int i;
     int a;
        int resultado;
        
        a=0;
        for (i=1; i<=num; i++)
        {
            if (num%i==0) 
            {
                a++;   
            }
            
            if (a==2)
            {
               resultado=1; 
            } else{
                resultado=0;
            }
        }
    return resultado;
    }
    /*
AL EJECUTAR
Introduce un numero del cual quieres saber si es un numero primo o no:2
El numero 2 es un numero primo.

Introduce un numero del cual quieres saber si es un numero primo o no:4
El numero 4 no es un numero primo
*/

//PARTE 2 -> valor inicial a partir del cual calcular numeros primos
#include <stdio.h>
int Primo (int num); //llamar a la funcion 
int main(void)
{
    int ni;
    int nf;
    int i;
    int resultado;

    printf("\n Introduzca el primer valor inicial a partir del cual quiera saber que numeros son primos:");
    scanf("%d",&ni);
    printf("\n Introduzca el numero final:");
    scanf("%d",&nf);
    
    for (i=ni;i<=nf;i++)
    {
        resultado= Primo (i); //LLAMAMOS A LA FUNCION. ES EL PRIMO DE I
        if (resultado==1)
        {
            printf ("\n El numero %d es un numero primo",i);
        }else{
            printf("\n El numero %d no es un numero primo",i);
        }
    }
    
	return 0;
}

int Primo (int num) //FUNCION
{
    int a;
    int j;
    int resultado1;
    
    
    a=0; //INICIALIZAMOS
    for (j=1;j<=num;j++) //EMPEZAMOS CON EL NUMERO 1
    { //AQUI CALCULAMOS LOS DIVISORES
        if (num%j==0)
        {
            a++;
        }
        //ANALIZAMOS LOS CASOS
        if (a==2) //DIVISOR EL 1 Y EL MISMO
        {
            resultado1=1;
        }else{
            resultado1=0;
        }
    }
 return resultado1; //DEVUELVE ALGO!!!!   
}

/*
AL EJECUTAR
 Introduzca el primer valor inicial a partir del cual quiera saber que numeros son primos:1
 Introduzca el numero final:10
 El numero 1 no es un numero primo
 El numero 2 es un numero primo
 El numero 3 es un numero primo
 El numero 4 no es un numero primo
 El numero 5 es un numero primo
 El numero 6 no es un numero primo
 El numero 7 es un numero primo
 El numero 8 no es un numero primo
 El numero 9 no es un numero primo
 El numero 10 no es un numero primo
*/