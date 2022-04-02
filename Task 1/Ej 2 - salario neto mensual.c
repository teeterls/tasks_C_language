/*Programa: programa 2
 * Descripcion: calculo del salario mensual de un empleado 
 * Revision: 18-09-2017
 * Autor: Teresa Gonzalez Garcia
 * Clase: 1º GITT*/

  #include <stdio.h>
  int main(void)
    {
    int horas_trabajadas;
    float paga_hora;
    float paga_bruta;
    float impuestos;
    float paga_neta;
   
    printf ("\n Introduzca el numero de horas trabajo:");
    scanf ("%d", &horas_trabajadas);
    printf ("\n Introduzca su paga por hora: ");
    scanf ("%f", &paga_hora)
                          
    paga_bruta= horas_trabajadas* paga_hora;
    impuestos= paga_bruta*0.15;
    paga_neta= paga_bruta-impuestos;
    
    printf("\n El salario bruto es %.2f \n", paga_bruta);
    printf("\n Los impuestos son %.2f \n", impuestos);
    printf("\n El salario neto es %.2f\n", paga_neta);
    return 0;
 }
   
  /* AL EJECUTAR:

 Introduzca el numero de horas trabajadas: 2
 Introduzca su paga por hora: 5.50
 El salario bruto es: 11.00 
 Los impuestos son: 1.65
 El salario neto es: 9.35
*/