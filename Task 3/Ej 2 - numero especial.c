/* Programa: programa 2
 * Descripcion: número especial
 * Revision: 20-09-17
 * Autor: Teresa Gonzalez Garcia
 * Clase 1º GITT */


#include <stdio.h>

int main(int argc, char **argv)
{
   int n;
   int especial;
   int i;
   
   do{
       printf("\nIntroduce un numero: ");
       scanf("%d" ,&n);
       if(n<=0){
           printf("\nValor incorrecto");
       }
   }while(n<=0);
   
  
   for(i=2;i<=n; i++) {
       especial=1;
       especial = especial + i;
   }
   
       if(especial==n-1){
           printf("\nEl valor %d es especial",n);
       }
       else{
           printf("\nEl valor %d no es especial",n);
       }
   
	return 0;
}

/*AL EJECUTAR:
Introduce un numero: 34
El valor 34 no es especial
Press any key to continue.
*/
