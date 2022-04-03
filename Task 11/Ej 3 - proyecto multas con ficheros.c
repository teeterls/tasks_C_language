/*Programa: programa 3
 * Descripcion: Proyecto (II)
 * Revision: 11-11-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} T_FECHA;

typedef struct
{
 T_FECHA fecha; //estructura anidada
    int idradar;
    char matricula [8];
    int velocidad;
    double multa;
} T_MULTA;


typedef struct
{
    int idradar;
    int vlimit;
    int umbral1;
    int umbral2;
    int umbral3;
} T_RADAR;

void CalculaNumRadares (FILE *pf_radares, int *num_radares);
void CargaRadaresFichero (FILE *pf_radares, T_RADAR *radares);
void CalculaNumMultas (FILE *pf_multas, int *num_multas);
void CargaMultasFichero (FILE *pf_multas, T_MULTA *multas);
float CalculaMultas (T_MULTA *multas, int num_multas, T_RADAR *radares, int num_radares);

int main(void)
{
	FILE *pf_radares; //punteros a ficheros
    FILE *pf_multas;
    T_RADAR *radares;//VARIABLE DE TIPO ESTRUCTURA. vectores tipo dinamicos
    T_MULTA *multas;
    int num_radares;
    int num_multas;
    float total_multas;
    
    //abrir archivos 
    pf_radares=fopen("E:/radares.txt","r"); //modo lectura, tiene que existir, si no da error
    if (pf_radares==NULL)
    {
        printf("\n Error al abrir el archivo.");
    }else{//si se puede abrir el archivo tiene lugar la funcion. si no, no se puede hacer nada en el programa.
        CalculaNumRadares (pf_radares, &num_radares); //OJO. FILE NO SE PONE CON * EN LA LLAMADA. 
        //ya tenemos el numero de radares
        printf("\n Hay %d radares\n", num_radares);
        //crear vector dinamico segun el numero de radares
        radares=(T_RADAR*)calloc(num_radares, sizeof(T_RADAR));
        if (radares==NULL)
        {
            printf("\n Error al asignar la memoria.");
        }else{ //si se puede crear el vector dinamico se podra cargar los radares en ese vector
            CargaRadaresFichero (pf_radares,radares); //*Radares o radares[], vector ya creado dinamicamente. ojo pf_radares sin *
            
            //ahora hacemos lo mismo con las multas, pero se mete dentro del else porque depende de los radares ("anidado")
            pf_multas=fopen("E:/multas.txt","r");
            if (pf_multas==NULL)
            {
                printf ("\n Error al abrir archivo.");
            }else{//solo pueden realizarse las funciones si se puede abrir el archivo
                CalculaNumMultas (pf_multas, &num_multas); //OJO pf_multas sin *
                //ya sabemos el numero de multas
                printf("\n Hay %d multas\n",num_multas);
                //ahora calculamos el vector dinamico que depende del numero de multas
                multas=(T_MULTA*)calloc(num_multas, sizeof (T_MULTA));
                if (multas==NULL)
                {
                    printf("\n Error al asignar memoria");
                }else{ //si no hay memoria no se puede realizar la siguiente funcion.
                    CargaMultasFichero (pf_multas, multas); //pf_multas sin *, multas[] o multas*
                    //ahora calculamos el total recaudado que depende de todo lo anterior
                    total_multas=CalculaMultas(multas, num_multas, radares, num_radares);
                    printf("\n El total recaudado por las multas es: %.2f\n",total_multas);
                    //ahora liberamos la memoria del vector
                        free (multas);
                }
                if (fclose(pf_multas)!=0)
                {
                    printf("\n Error de cierre de archivo.");
                }
            }
           free (radares);
        }
    }
     if (fclose(pf_radares)!=0)
     {
         printf("\n Error de cierre de fichero.");
     }
     
	return 0;
}

//CODIGO FUNCIONES
void CalculaNumRadares (FILE* pf_radares, int *num_radares)
{
    int ctrl; //hay que leer para que cuente los radares del fichero
    T_RADAR radar; //variable de apoyo donde se queda todo lo que se lee
    
    *num_radares= 0; //inicializar 
    printf("\n Radares:\n");
    //LEER
    do
    {
        ctrl=fscanf(pf_radares,"%d %d %d %d %d",&radar.idradar, &radar.vlimit, &radar.umbral1, &radar.umbral2, &radar.umbral3);
        if (ctrl==5)
        {
            printf("%d\t%d\t%d\t%d\t%d", radar.idradar, radar.vlimit, radar.umbral1, radar.umbral2, radar.umbral3);
            printf("\n");
            //vamos a ir contando los radares, que se pasan por referencia al numero de radares
            *num_radares=*num_radares+1; //se va acumulando
        }
    }while (ctrl==5);
    return;
}

void CargaRadaresFichero (FILE *pf_radares, T_RADAR radares[]) //radares[]
{
    //OJO. EL PUNTERO AHORA MISMO ESTA AL FINAL DEL ARCHIVO, PORQUE YA LO HA LEIDO. HAY QUE REBOBINAR
    int i;
    int ctrl; //HAY QUE LEER EL FICHERO
    T_RADAR radar; //variable tipo estructura donde se guarda lo que se lee
    //REBOBINAR
    rewind (pf_radares);
    i=0; //inicializar
    //LEER
    do
    {
        ctrl=fscanf(pf_radares, "%d %d %d %d %d", &radar.idradar, &radar.vlimit, &radar.umbral1, &radar.umbral2, &radar.umbral3);
        if (ctrl==5)
        {
            //COMO ESTA BIEN LEIDO AHORA SE PRODUCE EL CARGO DE LOS RADARES DEL FICHERO EN EL VECTOR
            radares[i]=radar; //TODA LA ESTRUCTURA. ES LO MISMO QUE radares[i].idradar=radar.idradar, radares[i].vlimit=radar.vlimit, etv
            i++;
        }
    }while (ctrl==5);
    return;
}

void CalculaNumMultas (FILE *pf_multas, int *num_multas)
{
    int ctrl; //HAY QUE LEER
    T_MULTA multa; //variable tipo estructura donde se guarda lo que voy a leer en el fichero
    *num_multas=0; //INICIALIZAR
    printf ("\n Multas:\n");
    do
    {
       ctrl= fscanf (pf_multas, "%d %d %d %d %s %d %lf", &multa.fecha.dia, &multa.fecha.mes, &multa.fecha.ano, &multa.idradar, multa.matricula, &multa.velocidad, &multa.multa ); //MULTA.MATRICULA SIN & PORQUE ES UN STRING
        if (ctrl==7)
        {
            printf("%d %d %d %d %s %d %lf", multa.fecha.dia, multa.fecha.mes, multa.fecha.ano, multa.idradar, multa.matricula, multa.velocidad, multa.multa);
            printf("\n");
            *num_multas=*num_multas+1;
        }
    }while (ctrl==7);
    return;
}
void CargaMultasFichero (FILE *pf_multas, T_MULTA multas[]) 
{
    //HAY QUE REBOBINAR, PORQUE EL PUNTERO ESTA AL FINAL DEL FICHERO
    int i;
    int ctrl; //HAY QUE LEER EL FICHERO PARA CARGAR LAS MULTAS
    T_MULTA multa; //variable donde se guarda lo que voy a leer
    
    rewind (pf_multas);
    i=0; //inicializar
    
    do
    {
    ctrl=fscanf(pf_multas, "%d %d %d %d %s %d %lf", &multa.fecha.dia, &multa.fecha.mes, &multa.fecha.ano, &multa.idradar, multa.matricula, &multa.velocidad, &multa.multa);
    if (ctrl==7)
    {
        //se copia toda la estructura 
        multas[i]=multa; //multas[i].fecha.dia=multa.fecha.dia es lo mismo, dato por dato
        i++;
    } 
    }while (ctrl==7);
    return;
}

float CalculaMultas (T_MULTA *multas, int num_multas, T_RADAR *radares, int num_radares)
{
    FILE *pf_informe;
    int i;
    int total;
    float umbral;
    float incremento;
    int idradar;
    
    total=0;
    pf_informe=fopen("E:/practica11/informe_extendido.txt", "w"); //crea el informe
    if (pf_informe==NULL)
    {
        printf("\n Error al abrir el archivo");
    }else{
        fprintf(pf_informe, "Informacion de cada multa:\n");
     //inicilizo contador

    for (i=0;i<num_multas;i++)
    {
        idradar=multas[i].idradar-1; //para la posicion 0 el radar 1. restamos una posicion y lo guardamos en el vector radares
        //si los radares no estuviesen ordenados, hay que buscar el indice de radar
        //INDICE_RADAR =BUSCARRADAR(MULTAS[I].IDRADAR, RADARES, NUM_RADARES)
        incremento=multas[i].velocidad -radares[idradar].vlimit;
        umbral = incremento *100 / radares [idradar].vlimit;
        if (umbral>0 && umbral<20)
        {
        multas[i].multa=radares[idradar].umbral1;
        }
        else
        {
            if (umbral>20 && umbral < 40)
            {
                multas[i].multa=radares[idradar].umbral2;
            }
            else
            {
                if (umbral >= 40)
                {
                multas[i].multa=radares[idradar].umbral;
                }
            }
        } 
        fprintf(pf_informe,"Multa:%d\n",i+1);
        fprintf(pf_informe,"Radar:%d\n",multas[i].idradar);
        fprintf(pf_informe,"Fecha: %d %d %d\n",multas[i].fecha.dia, multas[i].fecha.mes, multas[i].fecha.ano);
        fprintf(pf_informe, "Matricula: %s\n",multas[i].matricula);
        fprintf(pf_informe, "Velocidad: %d\n",multas[i].velocidad);
        fprintf(pf_informe,"Recaudacion de multa %d: %.2f\n", i+1,multas[i].multa);
        fprintf(pf_informe,"\n");
        total=total +multas[i].multa;
    //seria mejor hacerlo por filas por si hay que hacer algo con el fichero que se pueda leer mejor.
    //fprintf(pf_informe,"%d %d %d %d %s %d %f", multas[i].fecha.dia, multas[i].fecha.mes, multas[i].fecha.ano, multas[i].idradar, multas[i].matricula, 
    }
  }  
  if (fclose(pf_informe)!=0)
  {
      printf("\n Error de cierre de archivo.");
  }
    return total;
}
  
  /*   
AL EJECUTAR
Radares:
1       50      120     200     300
2       90      100     150     200
3       120     150     250     500
 Hay 3 radares

 Multas:
7 10 2017 1 6656GLV 75 0.000000
8 10 2017 3 3345FXR 150 0.000000
8 10 2017 2 6645GLV 120 0.000000
9 10 2017 1 1475HXT 80 0.000000
 Hay 4 multas
 
El total recaudado por las multas es: 1000.00

ARCHIVO EN RUTA E:/practica11/informe_extendido.txt -> cambiar para caso particular
*/
