/*Programa: programa 1
 * Descripcion: calculo de la altura de una persona
 * Revision: 27-09-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/

#include <stdio.h>
#include <ctype.h>
double CalculaAlt (double, char); //funcion prototipo
int main(void)
{
	double tib;
    double alt_m;
    char sex;
    char cont;
    
    // contestar SI O NO
    
    do{
        do{ //validacion de datos
            printf ("\n Introduce la longitud de la tibia (en cm):");
            scanf ("%lf",&tib);
            if (tib<0){
                printf("Valor erroneo de la tibia, debe ser positivo\n");
                }
        }while (tib<0);
    
        do{
            printf ("\n Introduce el sexo (H/M):");
            fflush (stdin);
            scanf ("%c", &sex);
            sex= toupper (sex); // convierte el caracter a mayusculas si es que la persona lo puso en minusculas
        }while (sex!= 'H' && sex!= 'M');
        
        alt_m= CalculaAlt(tib,sex); //llama a la funcion
        printf ("Altura obtenida: %.2lf", alt_m);
        
        printf("\nDesea realizar otros calculos? (S/N)");
        fflush (stdin);
        cont= getchar(); //es igual que scanf("%c",&cont)

    }while (cont== 'S');
    
    return 0;
}

double CalculaAlt (double long_tibia, char sexo)
{
    double altura;
    
    if (sexo=='H')
    {
        altura= 69.089 + 2.238* long_tibia; //CALCULOS
    }else{
        altura= 61.412 + 2.317* long_tibia;
    }
    altura=altura/100;
    return (altura); // PONER LO QUE QUIERO QUE ME DEVUELVA. 
}

/*AL EJECUTAR:

 Introduce la longitud de la tibia (en cm):30

 Introduce el sexo (H/M):H
Altura obtenida: 1.36
Desea realizar otros calculos? (S/N)S

 Introduce la longitud de la tibia (en cm):40

 Introduce el sexo (H/M):M
Altura obtenida: 1.54
Desea realizar otros calculos? (S/N)N
*/