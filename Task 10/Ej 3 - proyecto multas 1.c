/*Programa: programa 3
 * Descripcion: Proyecto (I)
 * Revision: 11-11-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
#include <stdio.h>
#include <stdlib.h>

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

//prototipos 
void Cargaradaresmanual (T_RADAR *radares,int nradares);
void Cargamultasmanual (T_MULTA *multas, int nmultas);
double Calcularmultas (T_MULTA *multas,int nmultas, T_RADAR *radares, int nradares);

int main(void)
{
    int nradares;
    int nmultas;
    T_RADAR *radares; //punteros que representan los vectores que crearemos con memoria dinamica
    T_MULTA *multas;
    double recaudado;
    int i;

    do 
    {
        //pedimos el tamaño del vector radares antes de crearlo dinamicamente
        printf ("\n introduce el numero de radares:");
        scanf ("%d", &nradares);

        if (nradares<=0)
        {
            printf ("\n el valor tiene que ser mayor que 0");
        }

    }while (nradares<=0);

    //asignamos memoria dinamica al vector radares
    radares=(T_RADAR*)calloc(nradares,sizeof(T_RADAR));

    if (radares == NULL)
    {
    printf ("\n error al asignar memoria");
    }else
    { //CODIGO
        Cargaradaresmanual (radares, nradares);
       do
       {
            //pedimos el tamaño del vector multas antes de crear el vector dinamico
           printf ("\n introduce el numero de multas:");
           scanf ("%d", &nmultas);
           if (nmultas <= 0)
           {
            printf("\n el valor tiene que ser mayor que 0.");
           }

       } while (nmultas<=0);

        //memoria dinamica
        multas=(T_MULTA*)calloc(nmultas,sizeof(T_MULTA));
        if (multas==NULL)
        {
        printf ("\n error al asignar memoria");
        }else
        {
        Cargamultasmanual (multas,nmultas);
        //calculamos el valor total de las multas
        recaudado=Calcularmultas(multas,nmultas,radares,nradares);
        printf ("\n el dinero recaudado en multas total es:  %.2lf", recaudado);
        printf ("\nMULTAS:");

            for (i=0;i<nmultas;i++)
            {
                printf ("\n fecha de la multa: %d/%d/%d",multas[i].fecha.dia,multas[i].fecha.mes,multas[i].fecha.ano);
                printf ("\n identificador de radar: %d",multas[i].idradar);
                printf ("\n matricula: %s", multas[i].matricula);
                printf ("\n velocidad: %d", multas[i].velocidad);
                printf ("\n multa: %.2f", multas[i].multa);
                printf ("\n");
            }
        }
        free(radares);//liberamos la memoria
        free(multas);
    }
return 0;
}

//CODIGOS FUNCIONES
void Cargaradaresmanual (T_RADAR radares[], int nradares)
{
    int i;
    for (i=0;i<nradares;i++)
    {
        printf ("\n introduce el identificador del radar:");
        scanf ("%d", &(radares[i].idradar));
        printf ("\n introduce la velocidad limite: ");
        scanf ("%d", &(radares[i].vlimit));
        printf ("\n introduce el umbral 20: ");
        scanf ("%d", &(radares[i].umbral1));
        printf ("\n introduce el umbral 30:");
        scanf ("%d", &(radares[i].umbral2));
        printf ("\n introduce el umbral>40 ");
        scanf ("%d", &(radares[i].umbral3));
    }
    return;
}

void Cargamultasmanual (T_MULTA multas[], int nmultas)
{
    int i;
    for (i=0;i<nmultas;i++)
    {
        printf ("\n introduce el dia de la multa:");
        scanf ("%d", &(multas[i].fecha.dia));
        printf ("\n introduce el mes de la multa:");
        scanf ("%d", &(multas[i].fecha.mes));
        printf ("\n introduce el ano de la multa:");
        scanf ("%d", &(multas[i].fecha.ano));
        printf ("\n introduce el radar:");
        scanf ("%d", &(multas[i].idradar));
        fflush (stdin);
        printf ("\n introduce la matricula del vehiculo:");
        fgets ((multas[i].matricula),8,stdin);
        printf ("\n introduce la velocidad: ");
        scanf ("%d", &(multas[i].velocidad));
    } 
    return;
}

double Calcularmultas(T_MULTA multas[], int nmultas,T_RADAR radares[], int nradares)
{
    int i;
    int total;
    float umbral;
    float incremento;
    int idradar;

    total=0; //inicilizo contador

    for (i=0;i<nmultas;i++)
    {
        idradar=multas[i].idradar-1;
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
                multas[i].multa=radares[idradar].umbral3;
                }
            }
        }
        total=total +multas[i].multa;
    }
    return total;
}

/*
AL EJECUTAR
 introduce el numero de radares:3
 introduce el identificador del radar:1
 introduce la velocidad limite: 50
 introduce el umbral 20: 120
 introduce el umbral 30:200
 introduce el umbral>40 300
 
introduce el identificador del radar:2
 introduce la velocidad limite: 90
 introduce el umbral 20: 100
 introduce el umbral 30:150
 introduce el umbral>40 200

 introduce el identificador del radar:3
 introduce la velocidad limite: 120
 introduce el umbral 20: 150
 introduce el umbral 30:250
 introduce el umbral>40 500
 
introduce el numero de multas:4
 introduce el dia de la multa:7
 introduce el mes de la multa:10
 introduce el ano de la multa:2017
 introduce el radar:1
 introduce la matricula del vehiculo:6645GLV
 introduce la velocidad: 75

 introduce el dia de la multa:8
 introduce el mes de la multa:10
 introduce el ano de la multa:2017
introduce el radar:3
 introduce la matricula del vehiculo:3345FXR
 introduce la velocidad: 150

 introduce el dia de la multa:8
 introduce el mes de la multa:10
 introduce el ano de la multa:2017
 introduce el radar:2
 introduce la matricula del vehiculo:6645GL
 introduce la velocidad: 120

 introduce el dia de la multa:9
 introduce el mes de la multa:10
 introduce el ano de la multa:2017
 introduce el radar:1
 introduce la matricula del vehiculo:1475HXT
 introduce la velocidad: 80

 el dinero recaudado en multas total es:  1000.00
MULTAS:
 fecha de la multa: 7/10/2017
 identificador de radar: 1
 matricula: 6645GLV
 velocidad: 75
 multa: 300.00

 fecha de la multa: 8/10/2017
 identificador de radar: 3
 matricula: 3345FXR
 velocidad: 150
 multa: 250.00

 fecha de la multa: 8/10/2017
 identificador de radar: 2
 matricula: 6645GLV
 velocidad: 120
 multa: 150.00

 fecha de la multa: 9/10/2017
 identificador de radar: 1
 matricula: 1475HXT
 velocidad: 80
 multa: 300.00
*/