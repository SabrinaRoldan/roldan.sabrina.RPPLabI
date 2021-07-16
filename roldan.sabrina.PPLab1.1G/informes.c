#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juego.h"
#include "categoria.h"
#include "cliente.h"
#include "alquileres.h"
#include "roldan.h"

#include "informes.h"

void mostrarJuegosCategoriaMesa(eJuego juegos[],int tamJ,eCategoria categorias[],int tamC)
{
    system("cls");
    printf("\n --------------------------------------------------------------------------------------\n");
    printf("                              Lista de Juegos Categoria Mesa\n");
    printf("          Codigo     Descripcion     Importe    idCategoria    Descripcion");
    printf("\n --------------------------------------------------------------------------------------\n");

        for(int i=0;i<tamJ;i++)
        {
            if(juegos[i].idCategoria==100)
            {
                mostrarJuego(juegos[i],categorias,tamC);
            }
        }

    printf("\n\n");
}

void alquileresPorCliente(eAlquileres alquileres[],int tama,eCliente clientes[], int tamC,eJuego juegos[]
                          ,int tamJ,eCategoria categorias[],int tamCat,eLocalidad localidades[],int tamL)
{
    int flag=1;
    int id;
    char seguir='s';

    do
    {
        system("cls");
        mostrarClientes(clientes,tamC,localidades,tamL);

        if(!utn_getUnsignedInt("Ingrese el codigo del cliente a buscar: ","Error. ",1,4,300,304,4,&id))
        {
            printf("Dato ingresado no valido.\n");
        }

        printf("\n -----------------------------------------------------------------------------------------------------------------\n");
        printf("                                        Lista de Alquileres por cliente");
        printf("\n --------------------------------------------------------------------------------------------------------------------------------\n");
        printf("   Codigo    idCliente         Nombre        Apellido         Localidad idJuego   Descripcion   Precio   Categoria        Fecha ");
        printf("\n --------------------------------------------------------------------------------------------------------------------------------\n\n");

        for(int i=0;i<tama;i++)
        {
            if(alquileres[i].idCliente==id)
            {
            mostrarAlquiler(alquileres[i],clientes,tamC,juegos,tamJ,categorias,tamCat,localidades,tamL);
            flag=0;
            }
        }
        if(flag)
        {
            printf("No hay alquileres disponibles para el cliente seleccionado");
        }

        printf("\n\n");

        utn_getChar("Desea buscar alquileres de otro cliente?: ","Error.\n",1,2,4,&seguir);

        if(seguir!='s')
        {
            printf("\n\nSalida exitosa!\n\n");
        }
    }while(seguir=='s');

}

void totalAlquileresCliente(eAlquileres alquileres[],int tama,eCliente clientes[],int tamC,eJuego juegos[],int tamJ
                            ,eCategoria categorias[],int tamCat,eLocalidad localidades[],int tamL)
{
    float total=0;
    int flag=1;
    int id;

    system("cls");

    printf("\n ---------------------------------------------------------------------------------------------------\n");
    printf("                                 Total de Alquileres por cliente");
    printf("\n ---------------------------------------------------------------------------------------------------");

    mostrarClientes(clientes,tamC,localidades,tamL);
    if(!utn_getUnsignedInt("Ingrese el codigo del cliente a buscar: ","Error. ",1,4,300,304,4,&id))
    {
        printf("Dato ingresado no valido.\n");
    }

    printf("\n --------------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                              Lista de Alquileres");
    printf("\n --------------------------------------------------------------------------------------------------------------------------------\n");
    printf("   Codigo    idCliente         Nombre        Apellido         Localidad idJuego   Descripcion   Precio   Categoria        Fecha ");
    printf("\n --------------------------------------------------------------------------------------------------------------------------------\n\n");

    for(int i=0;i<tama;i++)
    {
        if(alquileres[i].idCliente==id)
        {
            mostrarAlquiler(alquileres[i],clientes,tamC,juegos,tamJ,categorias,tamCat,localidades,tamL);
            for(int j=0;j<tamJ;j++)
            {
                if(alquileres[i].idJuego==juegos[j].codigo)
                {
                    total+=juegos[j].importe;
                }
            }

            flag=0;
        }
    }

    printf("\nEl importe total correspondiente al cliente es: %.2f",total);
    if(flag)
    {
        printf("No hay alquileres disponibles para el cliente seleccionado");
    }

    printf("\n\n");


}

void clientesSinAlquileres(eAlquileres alquileres[],int tama,eCliente clientes[], int tamC,eLocalidad localidades[],int tamL)
{
    int flag=1;
    int indice[tamC];

    system("cls");
    mostrarClientes(clientes,tamC,localidades,tamL);

    printf("\n ---------------------------------------------------------------------------------------------------\n");
    printf("                                         Clientes Sin Alquileres");
    printf("\n ---------------------------------------------------------------------------------------------------\n");
    printf("    Codigo         Nombre        Apellido    Sexo                  Telefono              Localidad");
    printf("\n ---------------------------------------------------------------------------------------------------\n");

    for(int i=0;i<tamC;i++)
    {
        for(int j=0;j<tama;j++)
        {
            if(alquileres[j].idCliente==clientes[i].codigo)
            {
                indice[i]=alquileres[j].idCliente;
                break;
            }
        }

        if(indice[i]!=clientes[i].codigo)
        {
            mostrarCliente(clientes[i],localidades,tamL);
            flag=0;
        }

    }

    if(flag)
    {
        printf("\nNo hay clientes sin alquileres\n\n");
    }

    printf("\n\n");

}

void juegosSinAlquiler(eAlquileres alquileres[],int tama,eJuego juegos[],int tamJ,eCategoria categorias[],int tamCat)
{

    int flag=1;
    int indice[tamJ];

    system("cls");
    mostrarJuegos(juegos,tamJ,categorias,tamCat);

    printf("\n --------------------------------------------------------------------------------------\n");
    printf("                                   Juegos Sin Alquilar");
    printf("\n --------------------------------------------------------------------------------------\n");
    printf("          Codigo     Descripcion     Importe    idCategoria    Descripcion");
    printf("\n --------------------------------------------------------------------------------------\n");

    for(int i=0;i<tamJ;i++)
    {
        for(int j=0;j<tama;j++)
        {
            if(alquileres[j].idJuego==juegos[i].codigo)
            {
                indice[i]=alquileres[j].idJuego;
                break;
            }
        }

        if(indice[i]!=juegos[i].codigo)
        {
            mostrarJuego(juegos[i],categorias,tamCat);
            flag=0;
        }

    }

    if(flag)
    {
        printf("\nNo hay juegos sin alquilar\n\n");
    }

    printf("\n\n");
}

void listarJuegosAlquiladosPorMujeres(eCliente clientes[],int tamC,eAlquileres alquileres[],int tamA,eJuego juegos[],int tamJ,
                                      eCategoria categorias[],int tamCat)
{
    int flag=1;
    int indice[tamJ];

    system("cls");
    mostrarJuegos(juegos,tamJ,categorias,tamCat);

    printf("\n --------------------------------------------------------------------------------------\n");
    printf("                                Juegos Alquilados por mujeres");
    printf("\n --------------------------------------------------------------------------------------\n");
    printf("          Codigo     Descripcion     Importe    idCategoria    Descripcion");
    printf("\n --------------------------------------------------------------------------------------\n");

    for(int i=0;i<tamJ;i++)
    {
        for(int j=0;j<tamA;j++)
        {
            if(alquileres[j].idJuego==juegos[i].codigo)
            {
                for(int k=0;k<tamC;k++)
                {
                    if(alquileres[j].idCliente==clientes[k].codigo && clientes[k].sexo=='f')
                    {
                        indice[i]=alquileres[j].idJuego;
                        break;
                    }
                }
            }
        }

        if(indice[i]==juegos[i].codigo)
        {
            mostrarJuego(juegos[i],categorias,tamCat);
            flag=0;
        }

    }

    if(flag)
    {
        printf("\nNo hay juegos sin alquilar\n\n");
    }

    printf("\n\n");
}

void listarTelefonosPorFecha(eCliente clientes[],int tamC,eAlquileres alquileres[],int tamA,eLocalidad localidades[],int tamL)
{
    int flag=1;
    int dia;
    int mes;
    int anio;
    char seguir='s';

    do
    {
        system("cls");
        mostrarClientes(clientes,tamC,localidades,tamL);

        if(!getFecha("Ingrese la fecha de alquiler: ","Error."
                     ,&dia
                     ,&mes
                     ,&anio
                     ,1990,2100,4))
        {
            printf("Fecha ingresada no valida.\n");
        }

        printf("\n -----------------------------------------------------------------------------------------------------------------\n");
        printf("                                               Lista de Telefonos");
        printf("\n -----------------------------------------------------------------------------------------------------------------\n");
        printf("                Telefono ");
        printf("\n -----------------------------------------------------------------------------------------------------------------\n");

        for(int i=0;i<tamA;i++)
        {
            if(alquileres[i].fecha.dia==dia&&
               alquileres[i].fecha.mes==mes&&
               alquileres[i].fecha.anio==anio)
            {
                for(int j=0;j<tamC;j++)
                {
                    if(alquileres[i].idCliente==clientes[j].codigo)
                    {
                        printf("%21s\n",clientes[j].telefono);
                    }
                }
                flag=0;
            }
        }
        if(flag)
        {
            printf("No hay alquileres disponibles para la fecha seleccionada");
        }

        printf("\n\n");

        utn_getChar("Desea ingresar otra fecha?: ","Error.\n",1,2,4,&seguir);

        if(seguir!='s')
        {
            printf("\n\nSalida exitosa!\n\n");
        }
    }while(seguir=='s');

}

void juegosMasAlquiladosPorHombres(eCliente clientes[],int tamC,eAlquileres alquileres[],int tamA,eLocalidad localidades[],int tamL,
                                   eJuego juegos[],int tamJ,eCategoria categorias[],int tamCat)
{
    int cantJuegos[tamJ];
    int mayor;
    int flag=1;

    for(int i=0;i<tamJ;i++)
    {
        cantJuegos[i]=0;
    }

    system("cls");
    printf("\n --------------------------------------------------------------------------------------\n");
    printf("                          Juegos mas alquilados por hombres");
    printf("\n --------------------------------------------------------------------------------------\n");
    printf("          Codigo     Descripcion     Importe    idCategoria    Descripcion");
    printf("\n --------------------------------------------------------------------------------------\n");

    for(int i=0;i<tamC;i++)
    {
        for(int j=0;j<tamA;j++)
        {
            if(alquileres[j].idCliente==clientes[i].codigo && clientes[i].sexo=='m')
            {
                for(int k=0;k<tamJ;k++)
                {
                    if(juegos[k].codigo==alquileres[j].idJuego)
                    {
                        cantJuegos[k]++;
                    }
                }
            }
        }
    }

    for(int i=0;i<tamJ;i++)
    {
        if(flag || cantJuegos[i]>mayor)
        {
            mayor=cantJuegos[i];
            flag=0;
        }
    }

    for(int i=0;i<tamJ;i++)
    {
        if(cantJuegos[i]==mayor)
        {
            mostrarJuego(juegos[i],categorias,tamCat);
        }
    }

    printf("\n\n");

}

void listarClientesPorJuegos(eAlquileres alquileres[],int tama,eCliente clientes[], int tamC,eJuego juegos[]
                          ,int tamJ,eCategoria categorias[],int tamCat,eLocalidad localidades[],int tamL)
{
    int flag=1;
    int id;
    char seguir='s';

    do
    {
        system("cls");
        mostrarJuegos(juegos,tamJ,categorias,tamCat);

        if(!utn_getUnsignedInt("Ingrese el codigo del juego a buscar: ","Error. ",1,4,200,204,4,&id))
        {
            printf("Dato ingresado no valido.\n");
        }

        printf("\n ---------------------------------------------------------------------------------------------------\n");
        printf("                                   Lista de Clientes por Juego");
        printf("\n ---------------------------------------------------------------------------------------------------\n");
        printf("    Codigo         Nombre        Apellido    Sexo                  Telefono              Localidad");
        printf("\n ---------------------------------------------------------------------------------------------------\n");;

        for(int i=0;i<tama;i++)
        {
            if(alquileres[i].idJuego==id)
            {
                for(int j=0;j<tamC;j++)
                {
                    if(alquileres[i].idCliente==clientes[j].codigo)
                    {
                        mostrarCliente(clientes[j],localidades,tamJ);
                        flag=0;
                    }
                }
            }
        }
        if(flag)
        {
            printf("No hay clientes que hayan alquilado el juego buscado\n");
        }

        printf("\n\n");

        utn_getChar("Desea ingresar un nuevo codigo?: ","Error.\n",1,2,4,&seguir);

        if(seguir!='s')
        {
            printf("\n\nSalida exitosa!\n\n");
        }
    }while(seguir=='s');
}

void mostrarRecaudacionPorFecha(eAlquileres alquileres[],int tama,eCliente clientes[],int tamC,
                                eJuego juegos[],int tamJ,eCategoria categorias[],int tamCat,
                                eLocalidad localidades[],int tamL)
{
    int flag=1;
    int dia;
    int mes;
    int anio;
    float total=0;
    char seguir='s';

    do
    {
        system("cls");

        printf("\n -----------------------------------------------------------------------------------------------------------------\n");
        printf("                                               Fechas Disponibles");
        printf("\n -----------------------------------------------------------------------------------------------------------------\n");

        for(int i=0;i<tama;i++)
        {
            printf("%2d/%2d/%4d  -  ",
                   alquileres[i].fecha.dia,
                   alquileres[i].fecha.mes,
                   alquileres[i].fecha.anio);
        }

        printf("\n\n");

        mostrarJuegos(juegos,tamJ,categorias,tamCat);

        if(!getFecha("Ingrese la fecha a consultar: ","Error."
                     ,&dia
                     ,&mes
                     ,&anio
                     ,1990,2100,4))
        {
            printf("Fecha ingresada no valida.\n");
        }

        printf("\n --------------------------------------------------------------------------------------------------------------------------------\n");
        printf("                                               Lista de Alquileres");
        printf("\n --------------------------------------------------------------------------------------------------------------------------------\n");
        printf("   Codigo    idCliente         Nombre        Apellido         Localidad idJuego   Descripcion   Precio   Categoria        Fecha ");
        printf("\n --------------------------------------------------------------------------------------------------------------------------------\n\n");

        for(int i=0;i<tama;i++)
        {
            if(alquileres[i].fecha.dia==dia&&
               alquileres[i].fecha.mes==mes&&
               alquileres[i].fecha.anio==anio)
            {
                mostrarAlquiler(alquileres[i],clientes,tamC,juegos,tamJ,categorias,tamCat,localidades,tamL);
                for(int j=0;j<tamJ;j++)
                {
                    if(alquileres[i].idJuego==juegos[j].codigo)
                    {
                        total+=juegos[j].importe;
                    }
                }
                flag=0;
            }
        }

        if(flag)
        {
            printf("No hay alquileres disponibles para la fecha seleccionada");
        }
        else
        {
            printf("\n\nEl total de los importes para la fecha es de: $%2.f",total);
        }

        printf("\n\n");

        utn_getChar("Desea ingresar otra fecha?: ","Error.\n",1,2,4,&seguir);

        total=0;

        if(seguir!='s')
        {
            printf("\n\nSalida exitosa!\n\n");
        }
    }while(seguir=='s');

}

void mostrarClientesPorLocalidad(eCliente clientes[],int tamC,eLocalidad localidades[],int tamL)
{
    int flag=1;
    int id;
    char seguir='s';

    do
    {
        system("cls");
        mostrarLocalidades(localidades,tamL);

        if(!utn_getUnsignedInt("Ingrese el codigo de localidad a buscar: ","Error. ",1,4,700,704,4,&id))
        {
            printf("Dato ingresado no valido.\n");
        }

    printf("\n ---------------------------------------------------------------------------------------------------\n");
    printf("                                         Lista de Clientes");
    printf("\n ---------------------------------------------------------------------------------------------------\n");
    printf("    Codigo         Nombre        Apellido    Sexo                  Telefono              Localidad");
    printf("\n ---------------------------------------------------------------------------------------------------\n");

        for(int i=0;i<tamC;i++)
        {
            if(clientes[i].idLocalidad==id)
            {
                mostrarCliente(clientes[i],localidades,tamL);
                flag=0;
            }
        }
        if(flag)
        {
            printf("No hay clientes que hayan alquilado el juego buscado\n");
        }

        printf("\n\n");

        utn_getChar("Desea ingresar un nuevo codigo?: ","Error.\n",1,2,4,&seguir);

        if(seguir!='s')
        {
            printf("\n\nSalida exitosa!\n\n");
        }
    }while(seguir=='s');
}

void mostrarRecaudacionPorLocalidad(eLocalidad localidades[],int tamL,eCliente clientes[],int tamC,eAlquileres alquileres[],int tama,
                                    eJuego juegos[],int tamJ,eCategoria categorias[],int tamCat)
{
    float totalLocalidad=0;
    float total=0;

    system("cls");
    mostrarLocalidades(localidades,tamL);

    for(int i=0;i<tamL;i++)
    {
        printf("Localidad: %20s - ",localidades[i].descripcion);
        totalLocalidad=0;
            for(int j=0;j<tamC;j++)
            {
                if(localidades[i].id==clientes[j].idLocalidad)
                {
                    for(int k=0;k<tama;k++)
                    {
                        if(clientes[j].codigo==alquileres[k].idCliente)
                        {
                            for(int l=0;l<tamJ;l++)
                            {
                                if(alquileres[k].idJuego==juegos[l].codigo)
                                {
                                    totalLocalidad+=juegos[l].importe;
                                }
                            }
                        }
                    }
                }
            }

        printf("Total: $%.2f\n",totalLocalidad);
        total+=totalLocalidad;
    }
    printf("\n\nTotal Global: %.2f\n\n",total);
}

void juegosAlquiladosPorLocalidad(eCliente clientes[],int tamC,eAlquileres alquileres[],int tamA,eLocalidad localidades[],int tamL,
                                   eJuego juegos[],int tamJ,eCategoria categorias[],int tamCat)
{
    int flag=1;
    int id;
    char seguir='s';

    do
    {
        system("cls");
        mostrarLocalidades(localidades,tamL);

        if(!utn_getUnsignedInt("Ingrese el codigo de localidad a buscar: ","Error. ",1,4,700,704,4,&id))
        {
            printf("Dato ingresado no valido.\n");
        }

        printf("\n --------------------------------------------------------------------------------------\n");
        printf("                               Lista de Juegos por Localidad");
        printf("\n --------------------------------------------------------------------------------------\n");
        printf("          Codigo     Descripcion     Importe    idCategoria    Descripcion");
        printf("\n --------------------------------------------------------------------------------------\n");

        for(int i=0;i<tamC;i++)
        {
            if(clientes[i].idLocalidad==id)
            {
                for(int j=0;j<tamA;j++)
                {
                    if(clientes[i].codigo==alquileres[j].idCliente)
                    {
                        for(int k=0;k<tamJ;k++)
                        {
                            if(alquileres[j].idJuego==juegos[k].codigo)
                            {
                                mostrarJuego(juegos[k],categorias,tamCat);
                                flag=0;
                            }
                        }
                    }
                }
            }
        }
        if(flag)
        {
            printf("No hay juegos para esta localidad\n");
        }

        printf("\n\n");

        utn_getChar("Desea ingresar un nuevo codigo?: ","Error.\n",1,2,4,&seguir);

        if(seguir!='s')
        {
            printf("\n\nSalida exitosa!\n\n");
        }
    }while(seguir=='s');

}

void mostrarAlquileresPorLocalidad(eCliente clientes[],int tamC,eAlquileres alquileres[],int tamA,eLocalidad localidades[],int tamL,
                                   eJuego juegos[],int tamJ,eCategoria categorias[],int tamCat)
{
    int flag=1;
    int id;
    char seguir='s';

    do
    {
        system("cls");
        mostrarLocalidades(localidades,tamL);

        if(!utn_getUnsignedInt("Ingrese el codigo de localidad a buscar: ","Error. ",1,4,700,704,4,&id))
        {
            printf("Dato ingresado no valido.\n");
        }

    printf("\n -----------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                           Lista de Alquileres por Localidad");
    printf("\n ------------------------------------------------------------------------------------------------------------------------------\n");
    printf("   Codigo    idCliente         Nombre        Apellido         Localidad idJuego   Descripcion   Precio   Categoria        Fecha ");
    printf("\n ------------------------------------------------------------------------------------------------------------------------------\n\n");

        for(int i=0;i<tamC;i++)
        {
            if(clientes[i].idLocalidad==id)
            {
                for(int j=0;j<tamA;j++)
                {
                    if(clientes[i].codigo==alquileres[j].idCliente)
                    {
                        mostrarAlquiler(alquileres[j],clientes,tamC,juegos,tamJ,categorias,tamCat,localidades,tamL);
                        flag=0;
                    }
                }
            }
        }
        if(flag)
        {
            printf("No hay alquileres para esta localidad\n");
        }

        printf("\n\n");

        utn_getChar("Desea ingresar un nuevo codigo?: ","Error.\n",1,2,4,&seguir);

        if(seguir!='s')
        {
            printf("\n\nSalida exitosa!\n\n");
        }
    }while(seguir=='s');

}
