/*Programa: programa 2
 * Descripcion: lectura y proceso de una frase
 * Revision: 12-10-2017
 * Autor: Teresa Gonzalez Garcia
 * Clase: 1º GITT*/

#include <stdio.h>
#define N 100
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char frase[N];
    int cont_pal; //contador de palabras//
    int cont_let; //contador de letras//
    int cont_voc; //contador de vocales//
    int i;
    
    printf("\n Introduzca una frase menor de 100 caracteres:");
    //gets (frase);//
    fgets(frase,N,stdin);
    // SIEMPRE CON FGETS PORQUE ES MUY FIABLE, ESO SI, INCLUYE SIEMPRE EL SALTO DE LINEA QUE HAY QUE QUITAR
    if (frase[strlen(frase)-1]== '\n')
    {
    frase [strlen(frase)-1]== '\0';
    } //CONVERTIR EL PENULTIMO CARACTER DE ESPACIO EN FIN DE CADENA PORQUE SIEMPRE GUARDA UN ESPACIO AL FINAL ANTES DEL 0

    //printf("\n La frase es: %s", frase);// //PONGO S PORQUE ES UNA CADENA DE CARACTERES
    puts(frase);
    
    //NUMERO DE PALABRAS QUE CONTIENE LA FRASE//
    cont_pal=0; //inicializo el contador//
    for (i=0;frase[i]!='\0';i++)  //'\0' ES EL FINAL DE LA FRASE
    //for (i=0;i<strlen(frase);i++); STRLEN ES LA LONGITUD DE LA FRASE
    {
        if (frase[i]==' ' || frase[i+1]=='\0') //si el caracter de la posicion es un blanco O EL CARACTER DE LA POSICION SIGUIENTE ES UN FIN DE CADENA ENTONCES SUMAREMOS UNA PALABRA//
        {
            cont_pal++; //se cuenta una palabra mas//
        }
    }
    
    if (i==0)
    {
        printf("\n Ls frase esta vacia");
    }else{
        printf ("\n %s tiene %d palabras", frase, cont_pal);
    }
    
    //numero de letras//
    cont_let=0;
    for(i=0;frase[i]!='\0';i++) 
    {
        if (toupper(frase[i])>='A'&& toupper (frase[i])<='Z'&& frase[i]!=' ')
        {
         cont_let++;   
        }
    }
    
    printf("\n %s tiene %d letras", frase, cont_let);
    
//numero de vocales//
    cont_voc=0;
    for (i=0;frase[i]!='\0';i++)
    {
        if (toupper(frase[i])=='A'|| toupper (frase[i])=='E'|| toupper (frase[i])=='I'|| toupper (frase[i])== 'O' || toupper (frase[i])=='U')
        {
            cont_voc++;
        }
    }
    
    printf("\n %s tiene %d vocales", frase, cont_voc);

	return 0;
}
/*

AL EJECUTAR
 Introduzca una frase menor de 100 caracteres:hola que tal yo muy bien y tu
hola que tal yo muy bien y tu

hola que tal yo muy bien y tu
 tiene 8 palabras

 hola que tal yo muy bien y tu
 tiene 22 letras

hola que tal yo muy bien y tu
 tiene 10 vocales
*/