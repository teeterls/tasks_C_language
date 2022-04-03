/*Programa: programa 2
 * Descripcion: Lectura de los datos del archivo binario
 * Revision: 06-12-2017
 * Autor: Teresa Gonzalez Garcia
* Clase: 1º GITT*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
typedef struct{
    int dia;
    int mes;
    int ano;    
}T_FECHA;

typedef struct{
    char titulo [N];    
     char autor [N];
T_FECHA fecha ;  
}T_LIBRO;

//prototipos

int BuscarlibrosdelAutor (FILE *pf, char autor[]);
T_LIBRO BuscarUltimoLibro (FILE *pf);
void MostrarLibros (FILE *pf);
int ActualizarDatos(FILE *pf, T_LIBRO libro);
int BuscarAntiguo (FILE *pf, T_LIBRO *libro);
void Descatalogar (FILE *pf, int posicion);
int Menu (void);

int main(void)
{	
    FILE *pf;
    char autor [N];
    int nlibros;
    int opcion;
    T_LIBRO libro;
    int encontrado;
    int posicion;
    
    //VARIABLE TIPO ESTRUCTURA
    
    //abrimos el fichero BINARIO
    pf=fopen("E:/practica12/biblioteca.dat", "rb+"); //      P
    if (pf==NULL)
    {
        printf ("\n Error al abrir el fichero.");
    }else{
       
       
  do
    {
        opcion=Menu(); 
            rewind (pf); //asi se vuelve a rebobinar el fichero cada vez que cambiemos de opcion, sin necesidad de ir poniendolo en cada opcion
            switch (opcion)
       {
           case 1:
    
            printf ("\n Introduce el nombre del autor:");
            fflush (stdin);
            gets(autor);
            nlibros= BuscarlibrosdelAutor (pf, autor); //en ficheros no se pone el asterisco!!!
            printf ("\n El numero de libros del autor %s es: %d",autor,nlibros);
            break;
           
            case 2:
           
            libro=BuscarUltimoLibro (pf); //DEVUELVE T_LIBRO.
            printf ("\n Datos del ultimo libro comprado:");
            printf ("\nTitulo: %s", libro.titulo);
            printf ("\nAutor:%s", libro.autor);
            printf ("\n Fecha de compra:%d/%d/%d",libro.fecha.dia,libro.fecha.mes,libro.fecha.ano);
            break;
            
            case 3:

            MostrarLibros (pf);
            printf ("\n");
            break;
            
            case 4:
     
             printf ("\n Introduce el titulo del libro que quieres actualizar:");
             fflush (stdin);
             gets (libro.titulo);
             printf ("\n Nuevo autor:");
             fgets (libro.autor,N,stdin);
             printf ("\n Nuevo dia de compra:");
             scanf ("%d",&libro.fecha.dia);
             printf ("\n Nuevo mes de compra:");
             scanf ("%d",&libro.fecha.mes);
             printf ("\n Nuevo ano de compra:");
             scanf ("%d",&libro.fecha.ano);
            encontrado=ActualizarDatos (pf, libro); 
            if (encontrado==0)
            {
              printf ("\n No hay libro a actualizar.");  
            }else{
                printf ("\n Los datos del libro %s se han actualizado correctamente.",libro.titulo);
            }
            break;
            
            case 5:

            posicion=BuscarAntiguo (pf, &libro); //PASA LIBRO CON ESTRUCTURA T_LIBRO POR REFERENCIA PORQUE VAMOS A COMPARAR OTRA VARIABLE CON ELLA
            printf ("\n Datos del libro a descatalogar:");
            printf ("\n Titulo:");
            fflush (stdin);
            fgets (libro.titulo,N,stdin);
            printf ("\n Autor:");
            fgets (libro.autor,N,stdin);
            printf ("\n Dia de compra:");
            scanf ("%d",&libro.fecha.dia);
            printf ("\n Mes de la compra:");
            scanf ("%d",&libro.fecha.mes);
            printf ("\n Ano de la compra:");
            scanf ("%d",&libro.fecha.ano);
            rewind (pf); //vamos a llamar a otra funcion
            Descatalogar (pf, posicion);
            rewind (pf);//vamos a llamar a otra funcion
            MostrarLibros (pf);
            
            break;
            case 6:
            
                printf ("\n Fin del programa.");
                 break;
          
            default:
            {
                printf ("\n Opcion incorrecta.");
                break;
            }
        }
    }while (opcion!=6);
        
       if (fclose(pf)!=0)
    {
        printf ("\n Error al cerrar el archivo. ");
    } 
    
    }
	return 0;
}

int Menu()
{
    int opc;
    printf ("\n ----MENU-----");
    printf ("\n 1. Buscar libros de un autor.");
    printf("\n 2.Buscar ultimo libro comprado.");
    printf ("\n3. Mostrar todos los libros almacenados.");
    printf ("\n 4.Actualizar los datos de un libro.");
    printf ("\n 5.Buscar el libro mas antiguo y descatalogarlo.");
    printf (“\n 6.Salir del programa”);
    
    printf ("\n Elige una opcion:");
    scanf ("%d",&opc);
    
    return opc;
}

int BuscarlibrosdelAutor (FILE *pf, char autor [N])
{
    //vamos a leer el fichero. necesitamos un ctrl
    int ctrl;
    T_LIBRO libros;
    int cont;
    cont=0; 
 
    do
    {
        ctrl=fread(&libros, sizeof(T_LIBRO),1,pf);
            if (strcmp(libros.autor,autor)==0)
            {
                cont++;
            }
        
    }while (ctrl==1);
return cont;
}

  
T_LIBRO BuscarUltimoLibro (FILE *pf)
{
    T_LIBRO nuevo;
    T_LIBRO aux;
    int ctrl;
    int fnueva;
    int fecha;
    
    fnueva=0;
    
    do
    {
       ctrl=fread(&aux, sizeof (T_LIBRO),1,pf);
       if (ctrl==1)
       {
           fecha=aux.fecha.ano*1000 + aux.fecha.mes*100 + aux.fecha.dia;
           if (fecha>fnueva)
           {
               fnueva=fecha;
               nuevo=aux;
           }
       }
    }while (ctrl==1);
return nuevo;
}

void MostrarLibros (FILE *pf)
{
    int ctrl;
    T_LIBRO libro;
    //system ("cls"); //BORRA PANTALLA
    
    //AHORA VAMOS A LEER EL FICHERO
    do
    {
        ctrl=fread(&libro, sizeof (T_LIBRO),1,pf);
        if (ctrl==1)
        {
           printf("\n Titulo :%s",libro.titulo);
           printf ("\n Autor: %s", libro.autor);
           printf("\n Dia: %d Mes: %d Ano: %d",libro.fecha.dia,libro.fecha.mes,libro.fecha.ano);
            printf ("\n");
        }
    }while (ctrl==1);
    
   return; 
}


 int ActualizarDatos (FILE *pf, T_LIBRO libro)
 {
     int ctrl;
     int encontrado;
     T_LIBRO aux;
     
     encontrado=0;
     do
     {
     ctrl=fread(&aux, sizeof (T_LIBRO),1,pf);
     if (ctrl==1)
     {
         if (strcmp(aux.titulo,libro.titulo)==0) //comparamos cadenas strcmp (cadena1,cadena2)
         {
           encontrado=1;
            fseek (pf,-1*(long)sizeof(T_LIBRO),SEEK_CUR); //el puntero ya una vez que lee pasa a la siguiente automaticamente, entonces tienes que colocarte en la posicion anterior
            //me va a escribir en el fichero el dato que yo he actualizado
            fwrite (&libro, sizeof(T_LIBRO),1,pf);
         }else{
             //si no ha encontrado el libro que tiene que actualizar sigue leyendo el fichero.
             ctrl=fread(&aux, sizeof(libro),1,pf);
         }
        }
    }while (ctrl==1 && encontrado==0);
 
 return encontrado;
 }
 
 int BuscarAntiguo (FILE *pf, T_LIBRO *aux)
 {
   int indice;
   int cont;
   int ctrl;
   T_LIBRO libro;
   
   do
   {
      ctrl=fread(&libro,sizeof(T_LIBRO),1,pf);
      *aux=libro; //primer libro que leo, lo considero que es el mas antiguo.
      cont=0;
      indice=0;
      if (ctrl==1)
      {
          if (libro.fecha.ano!=0 && libro.fecha.mes!=0 && libro.fecha.dia!=0) //no descatalogado
          {
              if (libro.fecha.ano<=aux->fecha.ano)
              {
                  if (libro.fecha.ano==aux->fecha.ano)
                  {
                      if (libro.fecha.mes<=aux->fecha.mes)
                      {
                          if (libro.fecha.mes==aux->fecha.mes)
                          {
                              if (libro.fecha.dia<aux->fecha.dia)
                              {
                                  *aux=libro;
                                  indice=cont;
                              }
                          }else{
                              *aux=libro; //ya es mayor por mes
                              indice=cont;
                          }
                      }
                  }else{ //ya es mayor por año 
                      *aux=libro;
                      indice=cont;
                  }
              }
           cont++;
           }
       }
    
   }while (ctrl==1);
return indice;
 }
 
 void Descatalogar (FILE *pf, int posicion)
 {
    T_LIBRO libro;
    //como ya se la posicion del libro que quiero descatalogar, no hace falta leer el archivo entero, usamos funcion fseek para posicionarlo
    fseek(pf, posicion*sizeof(T_LIBRO),SEEK_SET);//SE POSICIONA EN DICHA POSICION CON SEEK_SET.
    //AHORA LEEMOS EL REGISTRO DEL LIBRO DE DICHA POSICION
    fread (&libro, sizeof(T_LIBRO),1,pf);
    //ahora como ya hemos leido dicho libro, vamos a cambiar los datos para descatalogarlo.
    libro.fecha.dia=0;
    libro.fecha.mes=0;
    libro.fecha.ano=0;
    //ahora tengo que escribir esa nueva informacion. CUIDADO PORQUE UNA VEZ QUE LEO PASA AUTOMATICAMENTE A LA SIGUIENTE POSICION POR LO QUE HAY QUE RETROCEDER UNA POSICION    
    fseek (pf,-1*(long)sizeof(T_LIBRO),SEEK_CUR); //retrocede una posicion de la POSICION ACTUAL CON SEEK_CURR
    fwrite (&libro,sizeof(T_LIBRO),1,pf);

     return;
 }

/*
AL EJECUTAR
HAY FALLOS EN LA FUNCION DE ACTUALIZAR Y DE BUSCAR EL LIBRO MAS ANTIGUO
 ----MENU-----
 1. Buscar libros de un autor.
 2.Buscar ultimo libro comprado.
3. Mostrar todos los libros almacenados.
 4.Actualizar los datos de un libro.
 5.Buscar el libro mas antiguo y descatalogarlo.
 Elige una opcion:1

 Introduce el nombre del autor:Juan
 El numero de libros del autor Juan es: 1

 ----MENU-----
 1. Buscar libros de un autor.
 2.Buscar ultimo libro comprado.
3. Mostrar todos los libros almacenados.
 4.Actualizar los datos de un libro.
 5.Buscar el libro mas antiguo y descatalogarlo.
 
Elige una opcion:2
 Datos del ultimo libro comprado:
Titulo: La llamada
Autor:Juan
 Fecha de compra:2/3/2017
 
----MENU-----
 1. Buscar libros de un autor.
 2.Buscar ultimo libro comprado.
3. Mostrar todos los libros almacenados.
 4.Actualizar los datos de un libro.
 5.Buscar el libro mas antiguo y descatalogarlo.
 Elige una opcion:3

 Titulo :La llamada
 Autor: Juan
 Dia: 2 Mes: 3 Ano: 2017

 Titulo :La casa
 Autor: Teresa
 Dia: 3 Mes: 5 Ano: 2005

 Titulo :La lluvia
 Autor: Carmen
 Dia: 1 Mes: 1 Ano: 2001

 ----MENU-----
 1. Buscar libros de un autor.
 2.Buscar ultimo libro comprado.
3. Mostrar todos los libros almacenados.
 4.Actualizar los datos de un libro.
 5.Buscar el libro mas antiguo y descatalogarlo.
 Elige una opcion:4

 Introduce el titulo del libro que quieres actualizar:La casa
 Nuevo autor:Lucia
 Nuevo dia de compra:3
 Nuevo mes de compra:4
 Nuevo ano de compra:2006

 No hay libro a actualizar.
 ----MENU-----
 1. Buscar libros de un autor.
 2.Buscar ultimo libro comprado.
3. Mostrar todos los libros almacenados.
 4.Actualizar los datos de un libro.
 5.Buscar el libro mas antiguo y descatalogarlo.
 Elige una opcion:5

 Datos del libro a descatalogar:
 Titulo:La casa
 Autor:Teresa
 Dia de compra:3
 Mes de la compra:5
 Ano de la compra:2005

 Titulo :La llamada
 Autor: Juan
 Dia: 0 Mes: 0 Ano: 0

 Titulo :La casa
 Autor: Teresa
 Dia: 3 Mes: 5 Ano: 2005

 Titulo :La lluvia
 Autor: Carmen
 Dia: 1 Mes: 1 Ano: 2001

 ----MENU-----
 1. Buscar libros de un autor.
 2.Buscar ultimo libro comprado.
3. Mostrar todos los libros almacenados.
 4.Actualizar los datos de un libro.
 5.Buscar el libro mas antiguo y descatalogarlo.
 Elige una opcion:6

 Fin del programa.
*/