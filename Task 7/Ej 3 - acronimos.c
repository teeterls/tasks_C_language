3.	Código Fuente
/*Programa: programa 3
 * Descripcion: crear un acronimo
 * Revision: 19-10-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 100 
void Acronimo (char c[], char acron[]);

int main(void)
{
char cadena[TAM];
char acron[TAM];
	
printf("\nIntroduzca una cadena:");
fgets(cadena, TAM, stdin);
    
    if (cadena[strlen(cadena)-1] == '\n')
        {
cadena[strlen(cadena)-1] = '\0';
        }
	
Acronimo(cadena, acron);
	
printf("\n El acronimo es: %s", acron);
	
return 0 ;
}	

void Acronimo (char c[], char acron[])
{
int i;
int j;
int blanco;
	
i=0;
j = 0;
blanco = 1; //consideramos que empieza con un blanco
	
while (c[i] != '\0'){ //siempre que siga habiendo cadena 
if (blanco == 1)
{
if (c[i] != ' ')
{
if (c[i] >= 'A' && c[i] <= 'Z')
{
acron[j] = c[i];
j++;
}
blanco = 0;
}
else {
blanco = 1;
}
}
else 
{
if (c[i] == ' ')
{
blanco = 1;
}
}
i++;
}	
acron[j] = '\0'; //cerrar la cadena
return ;
}

/*
AL EJECUTAR
Introduzca una cadena:Organizacion de Naciones Unidas
 El acronimo es: ONU
 */
