/*Programa: programa 1
 * Descripcion: Manejo de vectores
 * Revision: 12-10-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
#include <stdio.h>
#define N 50
int main(void)
{
    int alumnos;
    int i;
    float notas [N]; //VECTOR DECLARADO DE 50 POSICIONES DE TIPO FLOAT
    //PEDIR NUMERO DE ALUMNOS CON VALIDACION//
    do{
        printf("\n Introduzca el numero de alumnos (maximo 50):");
        scanf("%d",&alumnos);
        if (alumnos<=0 || alumnos>50) //SE USA OR EN VEZ DE AND PORQUE SE REPITE CON CUALQUIERA DE LOS DOS CASOS//
        {
            printf("\n Numero de alumnos incorrecto. El numero debe ser positivo y menor que 50\n");
        }
    }while (alumnos<=0 || alumnos>50); 
   
    for (i=0;i<alumnos;i++) 
    {
        printf ("\nIntroduzca la nota del alumno %d:", i+1); //TE SALE: INTRODUCE LA NOTA DEL ALUMNO 0+1, 1+1, 2+1....
        scanf ("%f",&notas[i]); 
    }
  
    // MENU
    char opcion;
    float media;
    float maxima;
    float minima;
    int posicion;
    int cont;
    
    printf("Este es el menu:\n");
    printf ("a. Calcular la media de las notas\n");
    printf("b. Calcular la maxima nota entre los alumnos\n");
    printf("c. Calcular la minima nota entre los alumnos\n");
    printf("d. Salir");
    
    do{
    fflush (stdin);
    printf("\n Introduce la opcion:");
    scanf ("%c", &opcion); //opcion=getchar();
           
        switch (opcion)
        {
            case 'A': //media//
            case 'a':
            
                media =0; // INICIALIZAR EL CONTADOR PORQUE TIENE QUE IR SUMANDO TODAS LAS NOTAS   
                for (i=0;i<alumnos;i++) //APARECEN TODAS LAS NOTAS
                {
                    media=media+ notas[i];
                }
                media=media/alumnos; //MEDIA= NUMERO TOTAL/NUMERO 
                printf("\n Las media es: %.2f", media);
                break;
            
            case 'B': //nota maxima//
            case 'b':
            
                maxima=notas[0];//INICIALIZO MAXIMA CON LA PRIMERA NOTA DEL VECTOR, es la primera que considera maxima
                posicion=0; //indice del alumno con la unica maxima nota//
                cont=0; //contador para notas maximas de varios alumnos//
                
                //voy a comprobar si la nota siguiente es mayor o igual a la anterior//
                for (i=0;i<alumnos;i++)
                {
                    if (notas [i]>=maxima) 
                    {
                       if (notas [i]>maxima) //nuevo maximo
                       {
                           cont=1; //1 NUEVO MAXIMO//
                           maxima=notas[i];
                           posicion=i; //POSICION DEL NUEVO MAXIMO
                       }else{ //OTRO MAXIMO MAS POR ESO SE SUMA UNO AL CONTADOR INICIAL
                            cont=cont+1;
                        }
                    }
                }
                
                if (cont==1) //SOLO HA HABIDO UN MAXIMO DE UN ALUMNO//
    
                {
                    printf ("\n La nota maxima es %.2f correspondiente al alumno %d", maxima, posicion+1); //muestro con indice la posicion de i+1
                }else{ //HA HABIDO MAS MAXIMOS DE OTROS ALUMNOS PERO NO PONEMOS DE QUIEN//
                    printf ("\n La nota maxima es %.2f", maxima); //solo muestro la nota en el cont    
                }
                break;
                
            case 'C': //nota minima//
            case 'c':
            
                minima=notas[0]
                posicion=0;
                cont=0; 
                
                for (i=0;i<alumnos;i++)
                {
                    if (notas [i]<=minima) 
                    {
                       if (notas [i]<minima) //nuevo maximo
                       {
                           cont=1; 
                           minima=notas[i];
                           posicion=i;                       }else{ 
                            cont=cont+1;
                        }
                    }
                }
                if (cont==1)
                {
                    printf ("\n La nota minima es %.2f correspondiente al alumno %d", minima, posicion+1); //muestro con indice la posicion de i+1
                }else{ 
                  printf ("\n La nota minima es %.2f", minima);    
                }
                break;                                                                                                                                                                                 
            case 'D': //salida//
            case 'd':
                printf("\n Fin del programa.");
                break;
                
            default:
            printf("\n Opcion de menu erronea");
        }
    }while (opcion!= 'D' && opcion!= 'd');
    
	return 0;
}
/*

AL EJECUTAR

 Introduzca el numero de alumnos (maximo 50):-1
 Numero de alumnos incorrecto. El numero debe ser positivo y menor que 50
 Introduzca el numero de alumnos (maximo 50):3
Introduzca la nota del alumno 1:1
Introduzca la nota del alumno 2:2
Introduzca la nota del alumno 3:3
Este es el menu:
a. Calcular la media de las notas
b. Calcular la maxima nota entre los alumnos
c. Calcular la minima nota entre los alumnos
d. Salir
 Introduce la opcion:a

 Las media es: 2.00
 Introduce la opcion:b

 La nota maxima es 3.00 correspondiente al alumno 3
 Introduce la opcion:c

 La nota minima es 1.00 correspondiente al alumno 1
 Introduce la opcion:d

 Fin del programa.

*/