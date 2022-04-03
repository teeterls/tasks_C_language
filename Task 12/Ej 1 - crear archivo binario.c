/*Programa: programa 1
 * Descripcion: crear el archivo binario (biblioteca)
 * Revision: 06-12-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
typedef struct{
    int dia;
    int mes;
    int ano;    
}T_FECHA;

typedef struct{
    char titulo [N];    
     char autor [N];
T_FECHA fecha ;  
}T_LIBRO;

T_LIBRO RellenarUnLibro (void);

int main(void)
{
    int nlibros;
    FILE *pf;
    int i;
    T_LIBRO libro; //VARIABLE TIPO ESTRUCTURA
    
    printf ("\n Introduce el numero de libros que hay en la biblioteca:");
    scanf ("%d",&nlibros);
    
    //abrimos el fichero BINARIO
    pf=fopen("E:/practica12/biblioteca.dat", "wb"); //MODO WB DE ESTRUCTURA
    if (pf==NULL)
    {
        printf ("\n Error al abrir el fichero.");
    }else{
       for (i=0;i<nlibros;i++) 
       {
           printf ("\n Introduce los datos del libro %d:",i+1);
           libro=RellenarUnLibro();
       
       //AHORA ESCRIBIMOS EN EL FICHERO
            fwrite (&libro, sizeof(T_LIBRO),1,pf); //cada vez que relleno un libro lo escribo en el fichero binario.
       }
        
       if (fclose(pf)!=0)
    {
        printf ("\n Error al cerrar el archivo. ");
    } 
    }
	return 0;
}
//CODIGO FUNCION
T_LIBRO RellenarUnLibro()
{
    T_LIBRO libro;
    
    printf ("\n Introduce el titulo del libro:");
    fflush (stdin);
    //OJO SCANF CON CADENAS DE CARACTERES NO
    gets (libro.titulo);
    printf ("\n Introduce el autor del libro:");
    fflush (stdin);
    gets (libro.autor);
    printf ("\n Introduce el dia de publicacion:");
    scanf ("%d",&libro.fecha.dia);
    printf ("\n Introduce el mes de publicacion:");
    scanf ("%d",&libro.fecha.mes);
    printf ("\n Introduce el ano de publicacion:");
    scanf ("%d",&libro.fecha.ano);
return libro;
}

/*
AL EJECUTAR 

 Introduce el numero de libros que hay en la biblioteca:3

 Introduce los datos del libro 1:
 Introduce el titulo del libro:La llamada
 Introduce el autor del libro:Juan
 Introduce el dia de publicacion:12
 Introduce el mes de publicacion:2
 Introduce el ano de publicacion:2017

 Introduce los datos del libro 2:
 Introduce el titulo del libro:La noche

 Introduce el autor del libro:Pedro
 Introduce el dia de publicacion:5
 Introduce el mes de publicacion:10
 Introduce el ano de publicacion:2010

 Introduce los datos del libro 3:
 Introduce el titulo del libro:La casa
 Introduce el autor del libro:Teresa
 Introduce el dia de publicacion:4
 Introduce el mes de publicacion:09
 Introduce el ano de publicacion:2007
FICHERO BINARIO CREADO en ruta E:/practica12/biblioteca.dat -> cambiar caso determinado
*/