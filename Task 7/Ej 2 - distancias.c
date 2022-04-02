/*Programa: programa 2
 * Descripcion: calcular la distancia existente entre varias capitales
 * Revision: 19-10-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/

#include<stdio.h>
#include<string.h>
#define N 8

void CargarCapitales(char ciudades[][30]);
void CargarKilometros(char ciudades[][30], float distancia[][N]); 
float BuscarKilometros(float distancia[][N], int i_origen, int i_destino);
int Validar(char ciudad[], char ciudades[][30]);

int main(void){
	char capitales[N][30];
	float kilometros[N][N];
	char origen[30];
	char destino[30];
	float km;
	int indice_origen, indice_destino, i, j;
			
	CargarCapitales(capitales);
	CargarKilometros(capitales, kilometros); 
	
	printf("\n\t\t\tTabla de kilometros");
	printf("\n\t\t\t===================");
	
	printf("\n\t\t\t");
	for (i=0;i<8;i++){
		printf("%-15s ", capitales[i]);
	}
	
	for (i=0;i <N;i++){
		printf("\n%15s ", capitales[i]);
		for (j=0;j<N;j++){
			printf("%15.0f", kilometros[i][j]);
		}
	}
	
		printf("\nIntroduzca Capital Origen: ");
		fflush(stdin);
		gets(origen);
		indice_origen=Validar(origen, capitales);
		if(indice_origen==-1){
			printf("\nNombre de ciudad incorrecta");
		}
	}while(indice_origen==-1);//Nombre de ciudad incorrecta
	
		do{
		printf("\nIntroduzca Capital Destino: ");
		fflush(stdin);
		gets(destino);
		indice_destino=Validar(destino, capitales);
		if(indice_destino==-1){
			printf("\nNombre de ciudad incorrecta");
		}
	}while(indice_destino==-1);//Nombre de ciudad incorrecta
		
	km=kilometros[indice_origen][indice_destino];
	printf("\nLa distancia entre %s y %s es %.2f", origen, destino, km);
	
	km=BuscarKilometros(kilometros, indice_origen, indice_destino);
	
	printf("\nLa distancia entre %s y %s es %.2f", origen, destino, km);
	
	return 0;
}
//CODIGOS FUNCIONES
void CargarCapitales(char ciudades[][30]){
	int i;
	printf("\nCarga de CAPITALES de Provicincia");
	/*
	printf("\n=================================");	
	for (i=0;i<N;i++){
		printf("\n Introduzca capital de provincia %d: ", i+1);
		gets(ciudades[i]);
	}
	*/
	/*Carga de las capitales por programa*/
	strcpy(ciudades[0], "Jaen");
	strcpy(ciudades[1], "Cordoba");
	strcpy(ciudades[2], "Sevilla");
	strcpy(ciudades[3], "Huelva");
	strcpy(ciudades[4], "Cadiz");
	strcpy(ciudades[5], "Malaga");
	strcpy(ciudades[6], "Granada");
	strcpy(ciudades[7], "Almeria");
	

	return ;
}
void CargarKilometros(char ciudades[][30], float distancia[][N]){
	int i, j;
	printf("\nCarga de KILOMETROS entre Capitales de Provincia");
	printf("\n================================================");	
	/*
	for (i=0;i <N;i++){
		for (j=0;j<N;j++){
			printf("\nIntroduzca los kilometros existentes entre %s y %s: ", 
			ciudades[i], ciudades[j]);
			scanf("%f", &distancia[i][j]);
		}
	}
	*/
	/*Carga de las kilometros por programa*/

	distancia[0][0]=0;
	distancia[0][1]=104;
	distancia[0][2]=242;
	distancia[0][3]=336;
	distancia[0][4]=367;
	distancia[0][5]=209;
	distancia[0][6]=99;
	distancia[0][7]=228;
	
	distancia[1][0]=104;
	distancia[1][1]=0;
	distancia[1][2]=138;
	distancia[1][3]=232;
	distancia[1][4]=263;
	distancia[1][5]=187;
	distancia[1][6]=166;
	distancia[1][7]=332;
	
	distancia[2][0]=242;
	distancia[2][1]=138;
	distancia[2][2]=0;
	distancia[2][3]=94;
	distancia[2][4]=125;
	distancia[2][5]=219;
	distancia[2][6]=256;
	distancia[2][7]=422;
	
	distancia[3][0]=336;
	distancia[3][1]=232;
	distancia[3][2]=94;
	distancia[3][3]=0;
	distancia[3][4]=219;
	distancia[3][5]=313;
	distancia[3][6]=350;
	distancia[3][7]=516;
	
	distancia[4][0]=367;
	distancia[4][1]=263;
	distancia[4][2]=125;
	distancia[4][3]=219;
	distancia[4][4]=0;
	distancia[4][5]=265;
	distancia[4][6]=335;
	distancia[4][7]=484;

	distancia[5][0]=209;
	distancia[5][1]=187;
	distancia[5][2]=219;
	distancia[5][3]=313;
	distancia[5][4]=265;
	distancia[5][5]=0;
	distancia[5][6]=129;
	distancia[5][7]=219;

	distancia[6][0]=99;
	distancia[6][1]=166;
	distancia[6][2]=256;
	distancia[6][3]=350;
	distancia[6][4]=335;
	distancia[6][5]=129;
	distancia[6][6]=0;
	distancia[6][7]=166;

	
	distancia[7][0]=228;
	distancia[7][1]=332;
	distancia[7][2]=422;
	distancia[7][3]=516;
	distancia[7][4]=484;
	distancia[7][5]=219;
	distancia[7][6]=166;
	distancia[7][7]=0;

	return ;
}
int Validar(char ciudad[], char ciudades[][30]){
	int i;
	i=0;
	
	while (i<N && strcmp(ciudad, ciudades[i])!=0)
	{
		i++;
	}
	
	if (strcmp(ciudad, ciudades[i])!=0)
	{
		i=-1;
	}
	return i;
}
	
	
float BuscarKilometros(float distancia[][N], int i_origen, int i_destino) {
	 
	 float distancia_real =-1;
	 
	 if (i_origen > 0 && i_origen <N && i_destino > 0 && i_destino<N) 
	 {
		 distancia_real= distancia[i_origen][i_destino];
	 }
	 return distancia_real;
 }
 
 /*

AL EJECUTAR
Carga de KILOMETROS entre Capitales de Provincia
================================================
                        Tabla de kilometros
                        ===================
                        Jaen            Cordoba         Sevilla         Huelva          Cadiz           Malaga          Granada         Almeria
           Jaen               0            104            242            336            367            209             99            228
        Cordoba             104              0            138            232            263            187            166            332
        Sevilla             242            138              0             94            125            219            256            422
         Huelva             336            232             94              0            219            313            350            516
          Cadiz             367            263            125            219              0            265            335            484
         Malaga             209            187            219            313            265              0            129            219
        Granada              99            166            256            350            335            129              0            166
        Almeria             228            332            422            516            484            219            166              0
Introduzca Capital Origen: Cadiz
Introduzca Capital Destino: Huelva
La distancia entre Cadiz y Huelva es 219.00
*/