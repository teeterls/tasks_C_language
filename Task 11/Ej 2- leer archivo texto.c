/*Programa: programa 2
 * Descripcion: Leer datos del fichero temperaturas.txt y mostrar un informe
 * Revision: 17-11-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/

//LEER EL ARCHIVO DE TEXTO
#include <stdio.h>

int main(void)
{
	int dia;
    int ctrl;
    double temp;
    FILE *pf;
    
    pf=fopen ("E:/practica11/temperaturas.txt", "r"); //WRITE CREA EL NUEVO FICHERO SI NO LO HAY
    
    if (pf==NULL)
    {
        printf("\n Error al abrir el fichero");
    }else{
        printf ("\n LECTURA DEL FICHERO");
        printf ("\n=============\n");
       
 do
        {
            //CONTROLAR LA LECTURA ES MUY IMPORTANTE
            ctrl=fscanf(pf,"%d %lf\n", &dia, &temp); //LEE DOS VARIABLES!!!!
            //control de lectura. validarlo (numero de elementos correcto)
            if (ctrl==2)
            {
                printf("%d\t%.2f\n", dia, temp);
            }
        }while (ctrl==2);
        
        if (fclose(pf)!=0) //ver si cerramos bien el fichero. se puede poner directamente fclose(pf); 
            {
                printf("\n Error de cierre de fichero");
           }
    }
	return 0;
}

/*
AL EJECUTAR
LECTURA DEL FICHERO
=============
1       23.52
2       23.43
3       23.01
4       22.50
*/
