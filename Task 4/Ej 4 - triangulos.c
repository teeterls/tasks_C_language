/*Programa: programa 4
 * Descripcion: Funcion void
 * Revision: 27-09-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
#include <stdio.h>

void DibujarTriangulo (int h);
void DibujarLinea (void);

int main(int argc, char **argv)
{
    int altura;
    
    do{
        printf("\nIntroduzca la altura del triangulo: ");
        scanf("%d", &altura);
        if (altura<1) {
            printf("\nError, la alura debe ser mayor que 0..");
            printf("\n");
           }
       }while (altura<1);
        
    DibujarTriangulo(altura);
    return 0;
}

void DibujarTriangulo(int h )
{
    int i,j;
    for (i=0;i<h;i++)
    {
        for (j=h-i;j>=1;j--){
            DibujarLinea();
        }
         printf("\n");
    }
    return;
}

void DibujarLinea (void)
{  
  printf("*");
  return;
}

AL EJECUTAR
/*Introduzca la altura del triangulo: 5
*****
****
***
**
*
*/
