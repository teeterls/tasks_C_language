/*Programa: programa 3
 * Descripcion: proyecto 3
 * Revision: 06-12-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int dia;
    int mes;
    int ano;
} T_FECHA;

typedef struct{
    T_FECHA fecha;
    int id_radar;
    char matricula[8];
    int velocidad;
    double multa;
}T_MULTA;

typedef struct{
    int id_radar;
    int velocidad_limite;
    int umbral20;
    int umbral40;
    int umbral_resto;
}T_RADAR;

typedef struct{
    char matricula[8];
    float sancion;
    int pagado;
} T_PAGO;

void calcularNumRadares(FILE *fr, int *n);
void cargarRadaresAutomatico(FILE *fr, T_RADAR *r);
void cargarRadaresManual(T_RADAR *r, int n);

void calcularNumMultas(FILE *fm, int *n);
void cargarMultasAutomatico(FILE *fm, T_MULTA *m);
void cargarMultasManual(T_MULTA *m, int n);

double calculaMultas(T_MULTA *m,int nm,T_RADAR *r,int nr);
void descargarInforme(FILE *informe, T_RADAR *r, int nr, T_MULTA *m, int nm, double x);

void RellenarFicheroPagoMultas(FILE *fpagos, T_MULTA *multas, int n_multas);
int PagarMulta(FILE *fpagos, char matricula[], float importe);

int main(void)
{
    T_MULTA *multas;
    int n_multas;
    int n_radares;
    T_RADAR *radares;
    FILE *fmultas;
    FILE *fradares;
    FILE *informe;
    FILE *fpagos;
    int opcion;
    double total;
    char matri[8];
    float importe;
    int i;
    int c;
    
    c=0;
    do{
        printf("\n1.Introducir los datos automaticamente.");
        printf("\n2.Introducir los datos manualmente.");
        printf("\nSeleccione una opcion:");
        scanf ("%d",&opcion);
        switch(opcion){
            case 1:
                fmultas=fopen("E:/multas.txt","r");
                if(fmultas==NULL){
                    printf("\nError al abrir el fichero multas.txt");
                } else{
                    printf("\n Fichero de multas abierto con exito");
                    fradares=fopen("E:/radares.txt","r");
                    if(fradares==NULL){
                        printf("\nError al abrir el fichero radares.txt");
                    } else{
                        printf("\nFichero de radares abierto con exito");
                        
                        informe=fopen("E:/informe_extendido.txt","w");
                        if(informe==NULL){
                            printf("\nError al crear el fichero de informe extendido");
                        } else {
                            printf("\nFichero de informe extendido creado con exito");
                            
                            calcularNumRadares(fradares,&n_radares);
                            rewind(fradares);
                            radares=(T_RADAR *)calloc(n_radares,sizeof(T_RADAR));
                            if (radares==NULL){
                                printf("\nError al asignar memoria");
                            } else {
                                cargarRadaresAutomatico(fradares,radares);
                                
                                calcularNumMultas(fmultas,&n_multas);
                                rewind(fmultas);
                                multas=(T_MULTA *)calloc(n_multas,sizeof(T_MULTA));
                                if (multas==NULL){
                                    printf("\nError al asignar memoria");
                                } else {
                                    cargarMultasAutomatico(fmultas,multas);
                                    total=calculaMultas(multas,n_multas,radares,n_radares);
                                    
                                    
                                }
                            }
                        }
                        if (fclose(fradares)!=0)
                        {
                            printf ("\n Error al cerrar el archivo.");
                        }
                   }
                   if (fclose(fmultas)!=0)
                   {
                       printf ("\n Error al cerrar el archivo.");
                   }
                }
            break;
            
            case 2:
                do{
                    printf("\nIntroduce el numero de radares:");
                    scanf("%d",&n_radares);
                    if(n_radares<=0){
                        printf("\n\El numero de radares debe ser positivo");
                    }
                } while(n_radares<=0);
            
                radares=(T_RADAR *)calloc(n_radares,sizeof(T_RADAR));
            
                if (radares==NULL){
                    printf("\nError al asignar memoria");
                } else{ //radares ya funciona como un vector normal
                    cargarRadaresManual(radares,n_radares);
                    do{
                        printf("\nIntroduce el numero de multas:");
                        scanf("%d",&n_multas);
                        if(n_multas<=0){
                            printf("\nEl numero de multas debe ser positivo");
                        }
                    } while(n_multas<=0);
                
                    multas=(T_MULTA *)calloc(n_multas,sizeof(T_MULTA));
                
                    if (multas==NULL){
                        printf("\nError al asignar memoria memoria");
                    } else {
                        cargarMultasManual(multas,n_multas);
                        total=calculaMultas(multas,n_multas,radares,n_radares);
                        c=1;
                        
                    }
                }
            break;
            default:
                printf("\nOpcion erronea.");
        }
                
    } while (opcion!=1 && opcion!=2);
    
    if (c==1)
    {
        descargarInforme (informe,radares,n_radares,multas,n_multas,total);
        if (fclose(informe)!=0)
        {
            printf ("\n Error al cerrar el informe");
        }
    }
        
        fpagos=fopen("pago_multas.dat","wb+");
        if(fpagos==NULL){
            printf("\nError al abrir archivo pago_multas.dat");
        } else {
            RellenarFicheroPagoMultas(fpagos,multas,n_multas);
            do{
                rewind(fpagos);
                system("cls");
                printf("\nIntroduce la matricula para pagar su multa (poner 000 para finalizar): ");
                fflush(stdin);
                gets(matri);
                if(strcmp(matri,"000")!=0){
                    printf("\nIntroduce el importe de la multa a pagar: ");
                    scanf("%f",&importe);
                    i=PagarMulta(fpagos,matri,importe);
                    if(i==1){
                        printf("\n");
                        system("pause");
                    } else {
                        if(i==0){
                            printf("\nEl coche con matricula ");
                            puts(matri);
                            printf("No ha pagado el importe total de su multa.\n");
                        }
                        if(i==-1){
                            printf("\nEl coche con matricula ");
                            puts(matri);
                            printf(" No tiene ninguna multa pendiente.\n");
                        }
                        system("pause");
                    }
                }
            } while(strcmp(matri,"000")!=0);
            printf("\nFin del programa");
        }
        fclose(fpagos);
   
  
    return 0;
    }


void calcularNumRadares(FILE *fr, int *n){
    int i;
    int x;
    for(i=0;(fscanf(fr,"%d %d %d %d %d",&x,&x,&x,&x,&x))==5;i++);
    *n=i;
}
void cargarRadaresAutomatico(FILE *fr, T_RADAR *r){
    int ctrl;
    int i;
    i=0;
    do{
        ctrl=fscanf(fr,"%d %d %d %d %d",&r[i].id_radar,&r[i].velocidad_limite,&r[i].umbral20,&r[i].umbral40,&r[i].umbral_resto);
        if(ctrl==5){
            i++;
        }
    } while (ctrl==5);
}
void cargarRadaresManual(T_RADAR *r, int n){
    int i;
    
    for(i=0;i<n;i++){
        printf("\nIntroduce el numero de identificacion del radar %d ",i+1);
        scanf("%d",&(r[i].id_radar));
        printf("\nIntroduce la velocidad limite para el radar %d",r[i].id_radar);
        scanf("%d",&(r[i].velocidad_limite));
        printf("\nIntroduce el importe de la multa para un umbral menor al 20%");
        scanf("%d",&(r[i].umbral20));
        printf("\nIntroduce el importe de la multa para un umbral entre 20% y 40%");
        scanf("%d",&(r[i].umbral40));
        printf("\nIntroduce el importe de la multa para un umbral mayor al 40%");
        scanf("%d",&(r[i].umbral_resto));
    }
}

void calcularNumMultas(FILE *fm, int *n){
    int i;
    int x;
    char y[8];
    for(i=0;(fscanf(fm,"%d %d %d %d %s %d",&x,&x,&x,&x,y,&x))==6;i++);
    *n=i;
}
void cargarMultasAutomatico(FILE *fm, T_MULTA *m){
    int ctrl;
    int i;
    i=0;
    do{
        ctrl=fscanf(fm,"%d %d %d %d %s %d",&m[i].fecha.dia,&m[i].fecha.mes,&m[i].fecha.ano,&m[i].id_radar,m[i].matricula,&m[i].velocidad);
        if(ctrl==6){
            i++;
        }
    } while (ctrl==6);
}
void cargarMultasManual(T_MULTA *m, int n){
    int i;
    
    for(i=0;i<n;i++){
        printf("\nIntroduzca dia de la multa %d: ",i+1);
        scanf("%d",&(m[i].fecha.dia));
        printf("\nIntroduzca mes de la multa %d: ",i+1);
        scanf("%d",&(m[i].fecha.mes));
        printf("\nIntroduzca a%co de la multa %d: ",164,i+1);
        scanf("%d",&(m[i].fecha.ano));
        printf("\nIntroduce el numero de identificacion del radar: ");
        scanf("%d",&(m[i].id_radar));
        printf("\nIntroduce la matricula: ");
        fflush(stdin);
        fgets((m[i].matricula),8,stdin);
        printf("\nIntroduce la velocidad: ");
        scanf("%d",&(m[i].velocidad));
    }
}

double calculaMultas(T_MULTA *m,int nm,T_RADAR *r,int nr){
    int i,j;
    int x;
    double y;
    y=0;
    x=0;
    
    for(i=0;i<nm;i++){
        j=0;
        while(m[i].id_radar!=r[j].id_radar){
            j++;
        }
        if(m[i].velocidad<r[j].velocidad_limite){
            m[i].multa=0;
        } else {
            x=((m[i].velocidad*100)/r[j].velocidad_limite)-100;
            if(x>0 && x<20){
                m[i].multa=r[j].umbral20;
            } else {
                if(x>20 && x<40){
                    m[i].multa=r[j].umbral40;
                } else {
                    if(x>=40){
                        m[i].multa=r[j].umbral_resto;
                    }
                }
            }
        }
        y=y+m[i].multa;
    }
    return y;
}
void descargarInforme(FILE *fi_e, T_RADAR *r, int nr, T_MULTA *m, int nm, double x){
    int i;
    int j;
            fprintf(fi_e,"Multas:\n=======\n");
            fprintf(fi_e,"\nFecha    \tMatricula\tId del radar\tVelocidad limite\tVelocidad\tMulta");
            
            for(i=0;i<nm;i++){
                j=0;
                while(m[i].id_radar!=r[j].id_radar){
                    j++;
                }
                fprintf(fi_e,"\n%2d/%-2d/%-4d\t%s \t%-12d\t%-16d\t%-9d\t%-3.2f EUR.",m[i].fecha.dia,m[i].fecha.mes,m[i].fecha.ano,m[i].matricula,m[i].id_radar,r[j].velocidad_limite,m[i].velocidad,m[i].multa);
            }
            fprintf(fi_e,"\n\nLa recaudacion total es: %.2f EUR.",x);
    printf("\ninforme_extendido.txt ha sido descargado con exito\n==================================================");
    
}

void RellenarFicheroPagoMultas(FILE *fpagos, T_MULTA *multas, int n_multas){
    typedef struct{
        char matricula[8];
    } T_CMULTA;
    
    int i,j,t;
    T_PAGO m;
    int k,c;
    c=0;
    T_CMULTA copia[n_multas];
    
    for(i=0;i<n_multas;i++){
        t=0;
        for(j=0;j<=c;j++){
            if(strcmp(multas[i].matricula,copia[j].matricula)==0){
                t++;
            }
        }
        if(t==0){
            strcpy(m.matricula,multas[i].matricula);
            m.sancion=0;
            m.pagado=0;
            k=0;
            for(j=0;j<n_multas;j++){
                if(strcmp(m.matricula,multas[j].matricula)==0){
                    m.sancion=m.sancion+multas[j].multa;
                    k++;
                }
            }
            
            if(k<=1){
                fwrite(&m,sizeof(m),1,fpagos);
            } else{
                fwrite(&m,sizeof(m),1,fpagos);
                strcpy(copia[c].matricula,m.matricula);
                c++;
            }
        
        }
    }
}

int PagarMulta(FILE *fpagos, char matricula[], float importe){
    int i,ctrl;
    T_PAGO multa;
    char opcion;
    i=-1;
    ctrl=0;
    rewind(fpagos);
    do{
        ctrl=fread(&multa,sizeof(multa),1,fpagos);
        i++;
    } while(strcmp(matricula,multa.matricula)!=0 && ctrl!=0);
    fseek(fpagos,i*sizeof(multa),SEEK_SET);
    fread(&multa,sizeof(multa),1,fpagos);
    if(strcmp(matricula,multa.matricula)==0){
        if(multa.pagado==0){
            if(multa.sancion>importe){
                i=0;
            } else {
                printf("\nMulta de %.2f euros acaba de ser pagada.",multa.sancion);
                multa.pagado=1;
                fseek(fpagos,-1*(long)sizeof(multa),SEEK_CUR);
                fwrite(&multa,sizeof(multa),1,fpagos);
                i=1;
            }
        } else {
            printf("\nLa multa ya habia sido pagada.");
            i=1;
        }
        
    } else {
        i=-1;
    }
    fseek(fpagos,-1*(long)sizeof(multa),SEEK_CUR);
    fwrite(&multa,sizeof(multa),1,fpagos);
    if(i==1){
        printf("\nDesea borrar la multa? (SI,NO): ");
        fflush(stdin);
        scanf("%c",&opcion);
        opcion=toupper(opcion);
        if(opcion=='SI'){
            do{
                ctrl=fread(&multa,sizeof(multa),1,fpagos);
                if(ctrl==1){
                    fseek(fpagos,-2*(long)sizeof(multa),SEEK_CUR);
                    fwrite(&multa,sizeof(multa),1,fpagos);
                    fseek(fpagos,1*sizeof(multa),SEEK_CUR);
                }
            
            } while(ctrl!=0);
            fseek(fpagos,-1*(long)sizeof(multa),SEEK_CUR);
            strcpy(multa.matricula,"000");
            multa.pagado=1;
            multa.sancion=0;
            fwrite(&multa,sizeof(multa),1,fpagos);
            printf("\nMulta borrada");
        }
    }
    return i;
}

/*
AL EJECUTAR
FALLO -> no aparece el total de multas calculado
1.Introducir los datos automáticamente.
2.Introducir los datos manualmente.
Seleccione una opcion:1
Introduce la matricula para pagar su multa (poner 000 para finalizar): 6656GLV
Introduce el importe de la multa a pagar: 100
El coche con matricula 6656GLV
No ha pagado el importe total de su multa.
Introduce la matricula para pagar su multa (poner 000 para finalizar): 000
Fin del programa
//INFORME AGREGADO -> rutas E:/multas.txt , E:/radares.txt, E:/informe_extendido.txt -> Cambiar caso particular
*/

