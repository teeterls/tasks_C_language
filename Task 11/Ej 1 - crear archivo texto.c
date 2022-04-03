/*Programa: programa 1
 * Descripcion: crear el archivo de texto (temperaturas)
 * Revision: 17-11-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
//CREAR EL ARCHIVO DE TEXTO
#include <stdio.h>

int main(void)
{
    //variables dentro del fichero
    int dia;
    double temp;
    //me declaro el puntero al fichero
    FILE *pf;
   
 //FUNCION ABRIR FICHERO
    pf=fopen ("E:/practica11/temperaturas.txt", "w"); //WRITE CREA EL NUEVO FICHERO SI NO LO HAY
 
    //validar fichero
    if (pf==NULL)
    {
        printf("\n Error al abrir el fichero");
    }else{
        //CODIGO
            do
            {
            printf ("\n Introduzca dia a registrar (terminar con 0):");
            scanf ("%d",&dia);
            if (dia!=0)
            {
                printf ("\n Introduzca temperatura correspondiente al dia %d:",dia);
            scanf("%lf",&temp);
            
            //escribimos en el fichero
            fprintf(pf,"%.2d  %.2f\n",dia,temp);
            }
            }while (dia!=0);
            
            //cerramos el fichero
            
            if (fclose(pf)!=0) //ver si cerramos bien el fichero
            {
                printf("\n Error de cierre de fichero");
            } 
    }
	return 0;
}
/*
AL EJECUTAR

 Introduzca dia a registrar (terminar con 0):1
 Introduzca temperatura correspondiente al dia 1:23.52
 
Introduzca dia a registrar (terminar con 0):2
 Introduzca temperatura correspondiente al dia 2:23.43
 
Introduzca dia a registrar (terminar con 0):3
 Introduzca temperatura correspondiente al dia 3:23.01
 
Introduzca dia a registrar (terminar con 0):4
 Introduzca temperatura correspondiente al dia 4:22.50
 
Introduzca dia a registrar (terminar con 0):0

SE GUARDA EN FICHERO ruta E:/practica11/temperaturas.txt -> cambiar para caso particular
*/
 

