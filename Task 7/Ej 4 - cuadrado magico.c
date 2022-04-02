/*Programa: programa 4
 * Descripcion: crear un cuadrado magico
* Revision: 19-10-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/

#include <stdio.h>
#define N 25
void CuadradoMagico(int cua[N][N], int dim);
void MostrarMagico(int cua[N][N], int dim);

int main(void)
{
int cuadrado[N][N];
int dim;
	
do 
{
printf("\nIntrdozca un valor impar y menor que 25: ");
scanf("%d", &dim);
} while (dim <= 0 || dim > N || dim%2 == 0);

CuadradoMagico(cuadrado, dim);
MostrarMagico(cuadrado, dim);

return 0;
}	

void CuadradoMagico(int cua[N][N], int dim)
{
int valor;
int f;
int c;
	
f = 0;
c = dim / 2;
for (valor = 1; valor <= dim*dim; valor++)
{
cua[f][c] = valor;
if (valor % dim == 0)
{			
f = (f + 1)%dim;
}
else 
{
f = f - 1;
if (f < 0)
{
f = f + dim;
}	
			
//c = (c + 1) % dim;
c=c + 1;
if (c==dim)
{
c=0;
}
}
}
}

void MostrarMagico(int cua[N][N], int dim)
{
int i;
int j;
	
for (i=0; i < dim; i++)
{
for (j=0; j < dim ; j++)
{
printf("%3d ", cua[i][j]);
}
printf("\n");
}
return ;
}	

/*
AL EJECUTAR
Intrdozca un valor impar y menor que 25: 3
  8   1   6
  3   5   7
  4   9   2


Introduzca un valor impar y menor que 25: 5
 17  24   1   8  15
 23   5   7  14  16
  4   6  13  20  22
 10  12  19  21   3
 11  18  25   2   9
*/
