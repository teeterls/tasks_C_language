/*Programa: programa 3
 * Descripcion: Copiar los numeros primos de un vector a otro
 * Revision: 4-11-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
#include <stdio.h>
#include <stdlib.h>

void LeerVector (int *vector, int n); 
void ContarPrimos (int *v1, int n, int *num_primos);
void CopiaPrimos (int *v1, int *v2, int n);
void Mostrar (int *v, int n);

int main(void)
{
	int longitud;
	int num_primos;
	int *v1, *v2;
	printf("\nIntroduzca la longitud de los vectores: ");
	scanf("%d",&longitud);
	
	//Peticion de memoria dinamica
	v1=(int *)calloc(longitud,sizeof(int));
	if(v1==NULL){
		printf("\nError de asignacion de memoria");
	}else{
		//Cargar vector
		printf("\nVector1: ");
		LeerVector (v1, longitud); 
		ContarPrimos (v1, longitud, &num_primos);	
		
		//Peticion de memoria dinamica
		v2=(int *)calloc(num_primos,sizeof(int));
		if (v2==NULL){
			printf("\nError de asignacion de memoria");
		}else{
			//Copia de los primos de v1 a v2
			CopiaPrimos (v1, v2, longitud);
			
			//Impresion de los vectores
			printf("\n Resultados obtenidos \n");
			printf("\nVector 1: ");
			Mostrar (v1,longitud);
			printf("\nVector 2: ");
			Mostrar (v2, num_primos);
		}
		free(v1);
		free(v2);
	}
	return 0;
}
//CODIGOS FUNCIONES
void LeerVector (int *vector, int n)
{
	int i;
	for(i=0;i<n;i++){
		printf("\nIntroduzca elemento %d del vector: ", i+1);
		scanf("%d",&vector[i]);
	}
	return;
}
void ContarPrimos (int *v1, int n, int *num_primos)
{
	int i, divisor;
	*num_primos=0;
	int primo;
	for (i=0;i<n;i++)
        {
		primo=0;
		for(divisor=2;divisor<=v1[i]/2 && primo==0;divisor++)
            {
			if (v1[i]%divisor==0)
                {
				primo=1;
			}
		}
		if(primo==0)
            {
			*num_primos=*num_primos+1;
		}
	}
	return;	
}

void CopiaPrimos (int *v1, int *v2, int n)
{
	int i;
	int j;;
	int primo, divisor;
	j=0;
	for (i=0;i<n;i++)
        {
		primo=0;
		for(divisor=2;divisor<=v1[i]/2 && primo==0;divisor++)
            {
			if (v1[i]%divisor==0)
                {
				primo=1;
			}
		}
		if(primo==0)
            {
			v2[j]=v1[i];
			j++;
		}
	}
	return;	
}

void Mostrar (int *v, int n)
{
	int i;
	//printf("\n");
	for(i=0;i<n;i++)
        {
		printf("%d ", v[i]);
	}
	return;
}

/*
AL EJECUTAR
Introduzca la longitud de los vectores: 3
Vector1:
Introduzca elemento 1 del vector: 1
Introduzca elemento 2 del vector: 15
Introduzca elemento 3 del vector: 17
 
Resultados obtenidos
Vector 1: 1 15 17
Vector 2: 1 17

*/