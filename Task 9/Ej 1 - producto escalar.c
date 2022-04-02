/*Programa: programa 1
 * Descripcion: Calculo del producto escalar de dos vectores
 * Revision: 4-11-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/

#include <stdio.h>
#include <stdlib.h>

void LeerVector (float *, int);
void ProductoEscalar (float*, float *, int, float *);
void ImprimirVector (float *, int);

int main(void)
{
	
    int n;
    float *v1; //SON PUNTEROS. son vectores creados de forma dinamica, lo contrario de estatica v1[100]
    float *v2;
    float  p_escalar; //NO ES UN PUNTERO. esta variable la creo en el main para que el resultado de la funcion apunte a esta variable
    
    //introducir el numero de elementos de los vectores, memoria que me guardara
    printf("\n Introduzca el numero de elementos de los vectores:");
    scanf ("%d",&n);
    
    //peticion de memoria dinamica
    v1=(float *)calloc (n, sizeof (float));
    v2=(float *)calloc (n, sizeof (float));
    
    
//comprobamos que la memoria es correcta
    if (v1==NULL || v2==NULL)
    {
        printf ("\n Error de memoria");
    }else{
        //LOS HE CREADO BIEN. CODIGO DEL PROGRAMA. 
        //CARGA DE LOS VECTORES. A PARTIR DE ESTE MOMENTO TRABAJO COMO UN VECTOR Y ME OLVIDO DE LOS PUNTEROS!!!
        printf ("\n Vector 1: ");
        LeerVector (v1, n);
        
        printf("\n Vector 2: ");
        LeerVector (v2,n);
        
        //PRODUCTO ESCALAR
        ProductoEscalar (v1, v2, n, &p_escalar); //OJO LE ESTOY PASANDO LA DIRECCION DE LA VARIABLE DONDE VOY A GUARDAR EL RESULTADO DEL PRODUCTO ESCALAR 
        //utilizo & y no * porque p_escalar no esta definido como variable puntero. solo indico su direccion. 

        //IMPRESION DE LOS VECTORES
        printf("\n Impresion de resultados obtenidos:");
        
        printf("\n Vector 1: ");
        ImprimirVector (v1, n);
        
        printf ("\n Vector 2: ");
        ImprimirVector (v2, n);
        
        printf("\n\n El resultado del producto escalar de ambos vectores es: %.2f", p_escalar);

    } //se cierra aqui el else, todas las instrucciones realizadas siempre y cuando la memoria asignada sea correcta
    
    //AHORA LIBERO MEMORIA, muy importante
    free (v1);
    free (v2);
    
	return 0;
}

//FUNCIONES

void LeerVector (float *v, int n)
{
    int i;
    for (i=0; i<n; i++) //rellenamos el vector
    {
        printf ("\n Introduzca el elemento %d del vector: ", i+1);
        scanf ("%f", &v[i]);
    }

  return;  
}

void ProductoEscalar (float *v1, float *v2, int n, float *p_escalar)
{
    int i;
    //acumulador que inicializo
    *p_escalar=0;
    for (i=0; i<n;i++)
    {
        *p_escalar+=v1[i]*v2[i]; //acumulador del producto escalar de cada elemento. LO GUARDA EN LA DIRECCION DEL PUNTERO.
    }
//NO DEVUELVE NADA PORQUE HA PASADO EL RESULTADO POR REFERENCIA.
return;
}

void ImprimirVector (float *v, int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("%.2f", v[i]);
        printf ("\t");
    }

 return;   
}
/*
AL EJECUTAR

 Introduzca el numero de elementos de los vectores:2

 Vector 1:
 Introduzca el elemento 1 del vector: 1

 Introduzca el elemento 2 del vector: 2

 Vector 2:
 Introduzca el elemento 1 del vector: 3

 Introduzca el elemento 2 del vector: 4

 Impresion de resultados obtenidos:
 Vector 1: 1.00 2.00
 Vector 2: 3.00 4.00

 El resultado del producto escalar de ambos vectores es: 11.00
*/