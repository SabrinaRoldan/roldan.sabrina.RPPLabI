#include <stdio.h>
#include <stdlib.h>
#include "roldan.h"
#include "categoria.h"
#include "cliente.h"
#include "alquileres.h"
#include "juego.h"
#include "informes.h"

#define TAM_CAT 5
#define TAM_CLIENTE 5
#define TAM_ALQUILERES 15
#define TAM_JUEGOS 5
#define TAM_LOCALIDAD 5

int main()
{
    eCliente clientes[TAM_CLIENTE];
    eAlquileres alquileres[TAM_ALQUILERES];
    eJuego juegos[TAM_JUEGOS];
    eCategoria categorias[TAM_CAT];
    eLocalidad localidades[TAM_LOCALIDAD];
    char seguir='s';

    int nextIdCliente=300;
    int nextIdAlquileres=400;

    inicializarClientes(clientes,TAM_CLIENTE);
    inicializarAlquileres(alquileres,TAM_ALQUILERES);
    hardcodearClientes(clientes,TAM_CLIENTE,5,&nextIdCliente);
    hardcodearAlquileres(alquileres,TAM_ALQUILERES,15,&nextIdAlquileres);
    hardcodearJuegos(juegos,TAM_JUEGOS,5);
    hardcodearCategorias(categorias,TAM_CAT,5);
    hardcodearLocalidad(localidades,TAM_LOCALIDAD,5);

   do
    {
        switch(menu())
        {
            case 1:
                if(altaCliente(clientes,TAM_CLIENTE,&nextIdCliente,localidades,TAM_LOCALIDAD))
                {
                    printf("\n\nAlta exitosa!\n\n");
                }
                else
                {
                    printf("Error al dar de alta al cliente.\n");
                }
                break;

            case 2:
                if(modificarCliente(clientes,TAM_CLIENTE,localidades,TAM_LOCALIDAD))
                {
                    printf("\n\nModificacion exitosa!\n\n");
                }
                else
                {
                    printf("Error al modificar cliente.\n");
                }
                break;

            case 3:
                if(bajaCliente(clientes,TAM_CLIENTE,localidades,TAM_LOCALIDAD))
                {
                    printf("\n\nBaja exitosa!\n\n");
                }
                else
                {
                    printf("Error al dar de baja al cliente.\n");
                }
                break;

            case 4:
                if(ordenarClientes(clientes,TAM_CLIENTE))
                {
                    system("cls");
                    mostrarClientes(clientes,TAM_CLIENTE,localidades,TAM_LOCALIDAD);
                }
                else
                {
                    printf("Error al ordenar y listar los clientes\n");
                }
                break;

            case 5:
                if(altaAlquileres(alquileres,TAM_ALQUILERES,clientes,TAM_CLIENTE,juegos,TAM_JUEGOS,categorias,TAM_CAT
                               ,localidades,TAM_LOCALIDAD,&nextIdAlquileres))
                {
                    printf("\n\nAlta de alquiler realizada con exito!\n");
                }
                else
                {
                    printf("Error al dar de alta al cliente.\n");
                }
                break;

            case 6:
                system("cls");
                mostrarAlquileres(alquileres,TAM_ALQUILERES,clientes,TAM_CLIENTE,juegos,TAM_JUEGOS,categorias,TAM_CAT,
                                  localidades,TAM_LOCALIDAD);
                break;

            case 7:
                mostrarJuegosCategoriaMesa(juegos,TAM_JUEGOS,categorias,TAM_CAT);
                break;

            case 8:
                alquileresPorCliente(alquileres,TAM_ALQUILERES,clientes,TAM_CLIENTE,juegos,TAM_JUEGOS,categorias,TAM_CAT,
                                     localidades,TAM_LOCALIDAD);
                break;

            case 9:
                totalAlquileresCliente(alquileres,TAM_ALQUILERES,clientes,TAM_CLIENTE,juegos,TAM_JUEGOS,categorias,TAM_CAT,
                                       localidades,TAM_LOCALIDAD);
                break;

            case 10:
                clientesSinAlquileres(alquileres,TAM_ALQUILERES,clientes,TAM_CLIENTE,localidades,TAM_LOCALIDAD);
                break;

            case 11:
                juegosSinAlquiler(alquileres,TAM_ALQUILERES,juegos,TAM_JUEGOS,categorias,TAM_CAT);
                break;

            case 12:
                listarTelefonosPorFecha(clientes,TAM_CLIENTE,alquileres,TAM_ALQUILERES,localidades,TAM_LOCALIDAD);
                break;

            case 13:
                listarJuegosAlquiladosPorMujeres(clientes,TAM_CLIENTE,alquileres,TAM_ALQUILERES,juegos,TAM_JUEGOS,categorias,TAM_CAT);
                break;

            case 14:
                juegosMasAlquiladosPorHombres(clientes,TAM_CLIENTE,alquileres,TAM_ALQUILERES,localidades,TAM_LOCALIDAD,
                                              juegos,TAM_JUEGOS,categorias,TAM_CAT);
                break;

            case 15:
                listarClientesPorJuegos(alquileres,TAM_ALQUILERES,clientes,TAM_CLIENTE,juegos,TAM_JUEGOS,categorias,TAM_CAT,
                                        localidades,TAM_LOCALIDAD);
                break;

            case 16:
                mostrarRecaudacionPorFecha(alquileres,TAM_ALQUILERES,clientes,TAM_CLIENTE,juegos,TAM_JUEGOS,
                                           categorias,TAM_CAT,localidades,TAM_LOCALIDAD);
                break;

            case 17:
                mostrarClientesPorLocalidad(clientes,TAM_CLIENTE,localidades,TAM_LOCALIDAD);
                break;

            case 18:
                mostrarRecaudacionPorLocalidad(localidades,TAM_LOCALIDAD,clientes,TAM_CLIENTE,alquileres,TAM_ALQUILERES,
                                               juegos,TAM_JUEGOS,categorias,TAM_CAT);
                break;

            case 19:
                juegosAlquiladosPorLocalidad(clientes,TAM_CLIENTE,alquileres,TAM_CLIENTE,localidades,TAM_LOCALIDAD,juegos,TAM_JUEGOS
                                             ,categorias,TAM_CAT);
                break;

            case 20:
                mostrarAlquileresPorLocalidad(clientes,TAM_CLIENTE,alquileres,TAM_CLIENTE,localidades,TAM_LOCALIDAD,juegos,TAM_JUEGOS,
                                              categorias,TAM_CAT);
                break;

            case 21:
                seguir='n';
                break;

            default:
                printf("Opcion no valida\n");
                fflush(stdin);
                break;

        }
        system("pause");

    }while(seguir=='s');

    return 0;
}
