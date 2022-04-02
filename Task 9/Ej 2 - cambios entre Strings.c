/*Programa: programa 2
 * Descripcion: Copiar la segunda palabra de una cadena en otra
 * Revision: 4-11-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Prototipos
void ContarPalabra(char frase1[], int *plongitud);
void Transformar(char frase1[], char frase2[]);

int main(void){
	char frase1[100];
	char *frase2;
	int longitud;
	
	printf("\nIntroduzca la frase 1: ");
	fflush(stdin);
	fgets(frase1, 100, stdin);
	
	ContarPalabra(frase1, &longitud);
	
	if (longitud==-1){
		printf("\nLa frase 1 no tiene segunda palabra");
	}else{
		frase2= (char *) calloc(longitud+1, sizeof(char));
		if(frase2==NULL){
			printf("\nError de asignacion de memoria");
		}else{
			Transformar(frase1, frase2);
			printf("\nFrase1: ");
			printf("%s", frase1);
			printf("\nFrase2: ");
			printf("%s", frase2);
			
		}
	}
	free(frase2);
	return 0;
}
void ContarPalabra(char frase1[], int *plongitud)
{
	int i;
	i=0;
	//Voy hasta la primera letra que no sea blanco
	while(frase1[i]==' ')
        {
		i++;
	}
	//Voy hasta el final de la primera palabra
	while(frase1[i]!=' ' && frase1[i]!='\0' && frase1[i]!='\n')
        {
		i++;
	}
	
	if (frase1[i]=='\0' || frase1[i]=='\n' )
        { // No hay segunda palabra
		*plongitud=-1;
	}else{
		*plongitud=0;
		i++;
		while(frase1[i]!=' ' && frase1[i]!='\0'&& frase1[i]!='\n')
            {
			i++;
			*plongitud=*plongitud+1;
		}	
	}
	return;
}

void Transformar(char frase1[], char frase2[])
{
	int i;
    int j;
	i=0;
	//Voy hasta la primera letra que no sea blanco
	while(frase1[i]==' '){
		i++;
	}
	//Voy hasta el final de la primera palabra
	while(frase1[i]!=' ' && frase1[i]!='\0'){
		i++;
	}
	
	i++;
	j=0;
	while(frase1[i]!=' ' && frase1[i]!='\0' && frase1[i]!='\n'){
		frase2[j]=frase1[i];	
		i++;
		j++;
	}
	frase2[j]='\0';
	
  return ;
}
/*
AL EJECUTAR
Introduzca la frase 1: hola que tal estas yo muy bien
Frase1: hola que tal estas yo muy bien
Frase2: que*/

