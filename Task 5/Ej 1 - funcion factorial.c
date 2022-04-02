/*Programa: programa 1
 * Descripcion: calculo de la funcion factorial
 * Revision: 04-10-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
#include <stdio.h>

int Factorial (int);
int main (void)
{
    int factorial; //variable donde se guardara el factorial//
    int num;
    
    printf("\n Introduzca el valor del numero del cual quiera saber si factorial:");
    scanf("%d",&num);
    
    factorial= Factorial (num); //se relaciona la funcion//
    
    printf("\n El factorial del numero es %d", factorial);
    
	return 0;
}

//FUNCION PARA CALCULAR EL FACTORIAL//
int Factorial (int n )
{
    int result;
    
    if (n<=1) //1 O 0 . SUS FACTORIALES SON 1 
    {
        result=1;
    }else{
        result= n* Factorial (n-1); //SE LLAMA ASI MISMA POR ESO ES RECURSIVA
    }
    
    return result;
}
/*
AL EJECUTAR
Introduzca el valor del numero del cual quiera saber si factorial:3
 El factorial del numero es 6
 `*/
