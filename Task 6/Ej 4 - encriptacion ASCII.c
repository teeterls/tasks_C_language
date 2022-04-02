/*Programa: programa 3
 * Descripcion: paso de cadenas a funciones
 * Revision: 04-10-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
#include <stdio.h>
#include <string.h>
#define N 100

void Rot13(char cad1[], char cad_en[]);

int main(void)
{
	char cad1[N];
    char cad_en[N];
    
   
    
    puts ("\nPor favor, escriba la frase que quiera encriptar (100 caracteres maximo):");
   // gets (cad1); //OJO SIN EL VECTOR
    fflush(stdin);
    fgets(cad1,100,stdin); //entonces tenemos que eliminar el salto de linea:
    if (cad1[strlen(cad1)-1]== '\n')
    {
    cad1 [strlen(cad1)-1]== '\0';
    } 
    Rot13 (cad1, cad_en); //llamar funcion//
    
    printf("\n La frase encriptada es %s", cad_en); //sin i porque es la cadena entera//
    
	return 0;
}
//LO VAMOS A HACER CON LA TABLA ACSII
void Rot13 (char cad1[], char cad_en[])
{ 
    int i;
    for (i=0;i<strlen(cad1);i++)
    {
      if (cad1[i]+13<=122) //<= z, todavia se puede restar sin tener que rotar
      {
          cad_en[i]=cad1[i]+13;
      }else{ //tiene que dar la vuelta 
          cad_en[i]=97+13 -(122- cad1[i])-1; //a+13-(z-cad1[i])-1. OJO HAY SEGUIR SUMANDOLE 13. RESTANDO DIFERENCIA ENTRE LA LETRA Y Z (ES LO QUE SE PASA DE Z) Y -1 LA DIFERENCIA ENTRE Z Y A
      }
    }
return;
}
/*
AL EJECUTAR
Por favor, escriba la frase que quiera encriptar (100 caracteres maximo):
hola que tal me llamo teresa
 La frase encriptada es ubyn-dhr-gny-zr-yynzb-grerfn
*/