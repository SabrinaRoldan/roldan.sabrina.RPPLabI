#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roldan.h"
#include "fecha.h"
#include "alquileres.h"
#include "cliente.h"
#include "juego.h"

//Valores a hardcodear.
int idJuego[15]=  {203,202,200,204,200,200,200,201,201,202,202,202,203,203,203};

int idCliente[15]={300,302,300,303,301,303,304,300,300,301,303,300,301,300,303};

eFecha fecha[15]={
     {2,3,2001}
    ,{13,12,2003}
    ,{01,10,2013}
    ,{23,8,1999}
    ,{30,05,1998}
    ,{13,10,2003}
    ,{01,10,2004}
    ,{27,8,1999}
    ,{30,05,2008}
    ,{15,12,2013}
    ,{01,10,2015}
    ,{15,01,1999}
    ,{30,05,1997}
    ,{19,9,1996}
    ,{19,9,1996}
};

/***********************************************************************/

int hardcodearAlquileres(eAlquileres alquileres[],int tam, int cant,int* pId)
{
    int total=0;

    if(alquileres!=NULL && tam>0 && cant >= 0 && cant<=tam)
    {
        for(int i=0;i<cant;i++)
        {
             alquileres[i].codigo=*pId;
             (*pId)++;
             alquileres[i].idJuego=idJuego[i];
             alquileres[i].idCliente=idCliente[i];
			 alquileres[i].fecha=fecha[i];
             alquileres[i].isEmpty=0;
			 total++;
        }
    }
    return 1;
}

void inicializarAlquileres(eAlquileres alquileres[],int tam)
{
   for(int i=0;i<tam;i++)
    {
        alquileres[i].isEmpty=1;
    }
}

int buscarLibreAlquileres(eAlquileres alquileres[],int tam)
{
    int indice=-1;

    if(alquileres!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
       {
           if(alquileres[i].isEmpty==1)
           {
               indice=i;
               break;
           }
       }
    }
    return indice;
}

int altaAlquileres(eAlquileres alquileres[],int tama,eCliente clientes[],int tam
                   ,eJuego juegos[],int tamJ,eCategoria categorias[],int tamC
                   ,eLocalidad localidades[],int tamLoc, int* pIdAlquileres)
{
    int retorno=0;
    int indice;
    int idCliente;
    int idJuego;

    eAlquileres nuevoAlquileres;

    if(clientes!=NULL && tam>0 && alquileres!=NULL && tama>0 && juegos!=NULL && tamJ>0 && pIdAlquileres!=NULL)
    {
        indice=buscarLibreAlquileres(alquileres,tama);
        if(indice==-1)
        {
            system("cls");
            printf("        Alta Alquileres\n\n");
            printf("No hay lugar para mas alquileres\n");
        }
        else
        {
            system("cls");
            printf("        Alta Alquileres\n\n");
            printf("id Alquileres: %d\n",*pIdAlquileres);
            nuevoAlquileres.codigo=*pIdAlquileres;

            //Cargar cliente
            mostrarClientes(clientes,tam,localidades,tamLoc);
            printf("Ingrese id del cliente: ");
            scanf("%d",&idCliente);

            while(buscarCliente(clientes,tam,idCliente)==-1)
            {
                printf("No es un cliente valido. Reingrese id de cliente: ");
                scanf("%d",&idCliente);
            }
            nuevoAlquileres.idCliente=idCliente;


            //Cargar juego
            mostrarJuegos(juegos,tamJ,categorias,tamC);
            printf("Ingrese id del juego: ");
            scanf("%d",&idJuego);

            while(buscarJuego(juegos,tamJ,idJuego)==-1)
            {
                printf("No es un juego valido. Reingrese id de juego: ");
                scanf("%d",&idJuego);
            }
            nuevoAlquileres.idJuego=idJuego;

            //Cargar fecha
            if(!getFecha("Ingrese fecha: ","Error."
                     ,&nuevoAlquileres.fecha.dia
                     ,&nuevoAlquileres.fecha.mes
                     ,&nuevoAlquileres.fecha.anio
                     ,1990,2100,4))
            {
                printf("Error al cargar la fecha.\n");
                return 0;
            }

            nuevoAlquileres.isEmpty=0;

            alquileres[indice]=nuevoAlquileres;

            (*pIdAlquileres)++;

            retorno=1;
        }
    }
    return retorno;
}

void mostrarAlquiler(eAlquileres unAlquiler,eCliente clientes[],int tam
                     ,eJuego juegos[],int tamJ,eCategoria categorias[],int tamC,
                     eLocalidad localidades[],int tamL)
{
    char nombre[20];
    char apellido[20];
    char descripcion[20];
    char descripcionCategoria[20];
    char descripcionLocalidad[20];
    float importe;

    if(cargarNombreCliente(unAlquiler.idCliente,clientes,tam,nombre) &&
       cargarApellidoCliente(unAlquiler.idCliente,clientes,tam,apellido) &&
       cargarDescripcionJuego(unAlquiler.idJuego,juegos,tamJ,descripcion)&&
       cargarImporteJuego(unAlquiler.idJuego,juegos,tamJ,&importe)&&
       cargarDescripcionJuegoCategoria(unAlquiler.idJuego,juegos,tamJ,categorias,tamC,descripcionCategoria)&&
       cargarDescripcionLocalidadPorCliente(unAlquiler.idCliente,clientes,tam,localidades,tamL,descripcionLocalidad))
    {

        printf("    %3d          %3d     %10s      %10s     %15s     %3d    %10s   %.2f  %10s   %2d/%2d/%2d\n"
               ,unAlquiler.codigo
               ,unAlquiler.idCliente
               ,nombre
               ,apellido
               ,descripcionLocalidad
               ,unAlquiler.idJuego
               ,descripcion
               ,importe
               ,descripcionCategoria
               ,unAlquiler.fecha.dia
               ,unAlquiler.fecha.mes
               ,unAlquiler.fecha.anio);
    }
    else
    {
       printf("Error al cargar la descripcion del alquiler\n");
    }
}

void mostrarAlquileres(eAlquileres alquileres[],int tama,eCliente clientes[],int tamC
                       ,eJuego juegos[],int tamJ,eCategoria categorias[],int tamCat,
                       eLocalidad localidades[],int tamL)
{
    int flag=1;

    printf("\n -----------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                              Lista de Alquileres");
    printf("\n ------------------------------------------------------------------------------------------------------------------------------\n");
    printf("   Codigo    idCliente         Nombre        Apellido         Localidad idJuego   Descripcion   Precio   Categoria        Fecha ");
    printf("\n ------------------------------------------------------------------------------------------------------------------------------\n\n");

    for(int i=0;i<tama;i++)
    {
        if(!alquileres[i].isEmpty)
        {
            mostrarAlquiler(alquileres[i],clientes,tamC,juegos,tamJ,categorias,tamCat,localidades,tamL);
            flag=0;
        }
    }
    if(flag)
    {
        printf("No hay alquileres disponibles");
    }

    printf("\n\n");
}

void mostrarAlquileresCliente(eAlquileres alquileres[],int tama,eCliente clientes[],int tamC
                              ,eJuego juegos[],int tamJ,eCategoria categorias[],int tamCat
                              ,eLocalidad localidades[],int tamLoc)
{
    int idCliente;

    printf("       Alquileres Cliente\n\n");
    mostrarClientes(clientes,tamC,localidades,tamLoc);

    printf("Ingrese Id de Cliente: ");
    scanf("%d",&idCliente);

    while(buscarCliente(clientes,tamC,idCliente)==-1)
    {
        printf("Id invalido. Reingrese Id: ");
        scanf("%d",&idCliente);
    }

}

int bajaAlquiler(eAlquileres lista[], int tama,eCliente clientes[],int tamC
                 ,eJuego juegos[],int tamJ,eCategoria categorias[],int tamCat,
                 eLocalidad localidades[],int tamL)
{
    int retorno=0;
    int indice;
    int codigo;
    char confirma;

    system("cls");
    printf("        Baja Alquiler\n");
    mostrarAlquileres(lista,tama,clientes,tamC,juegos,tamJ,categorias,tamCat,localidades,tamL);
    printf("Ingrese codigo: ");
    scanf("%d",&codigo);

    indice=buscarAlquiler(lista,tama,codigo);

    if(indice==-1)
    {
        printf("No existe un alquiler con el codigo: %d\n", codigo);
    }
    else
    {
        mostrarAlquiler(lista[indice],clientes,tamC,juegos,tamJ,categorias,tamCat,localidades,tamL);
        printf("Confirma baja?: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma=='s')
        {
            lista[indice].isEmpty=1;
            retorno=1;
        }
        else
        {
            printf("Baja cancelada por el usuario\n");
        }
    }

    return retorno;
}

int buscarAlquiler(eAlquileres lista[],int tam, int codigo)
{
    int indice=-1;

    if(lista!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
       {
           if(!lista[i].isEmpty && lista[i].codigo==codigo)
           {
               indice=i;
               break;
           }
       }
    }
    return indice;
}
