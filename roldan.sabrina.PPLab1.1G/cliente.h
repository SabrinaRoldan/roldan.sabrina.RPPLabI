#include "localidad.h"

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int codigo;
    char nombre[52];
    char apellido[52];
    char sexo;
    char telefono[22];
    int isEmpty;
    int idLocalidad;
}eCliente;

#endif // CLIENTE_H_INCLUDED

/** \brief                          Muestra el menú general del programa y toma una opcion elegida por el usuario.
 *
 * \return int                      Retorna la opcion elegida por el usuario.
 *
 */
int menu();

/** \brief                          Toma los datos ingresados por el usuario, al analizarlos y estos cumplir las condiciones
 *                                  necesarias de una estructura cliente lo retorna al espacio de memoria del puntero
 *                                  para el alta en el sistema.
 *
 * \param lista[] eCliente       	Array de clientes.
 * \param tam int                   Tamaño del array clientes.
 * \param pId int*                  Puntero al espacio memoria donde se dejará el resultado de la función.
 * \param localidades[] eLocalidad  Array de localidades.
 * \param tamL int                  Tamaño del array localidades.
 * \return int                      Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int altaCliente(eCliente lista[], int tam, int* pId,eLocalidad localidades[],int tamL);

/** \brief                          Recorre el array y al encontrar el primer cliente con el campo isEmpty en
 *                                  true retorna el índice de este.
 *
 * \param lista[] eCliente          Array de clientes.
 * \param tam int                   Tamaño correspondiente al array clientes.
 * \return int                      Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int buscarLibre(eCliente lista[], int tam);

/** \brief                          Inicializa todos los clientes con el campo isEmpty en true
 *
 * \param lista[] eCliente          Array de clientes.
 * \param tam int                   Tamaño correspondiente al array clientes.
 * \return void                     No retorna ningún valor.
 *
 */
void inicializarClientes(eCliente lista[],int tam);

/** \brief                          Muestra la información de un cliente.
 *
 * \param unCliente eCliente        Estructura de cliente.
 * \param localidades[] eLocalidad  Array de localidades.
 * \param int tam                   Tamaño del array de localidades.
 * \return                          No retorna ningún valor.
 *
 */
void mostrarCliente(eCliente unCliente, eLocalidad localidades[],int tam);

/** \brief                          Recorre el array y muestra la información de todos los clientes.
 *
 * \param lista[] eCliente          Array de clientes.
 * \param tam int                   Tamaño del array clientes.
 * \param localidades[] eLocalidad  Array de localidades.
 * \param tamLoc int                Tamaño del array localidades.
 * \return void                     No retorna ningún valor.
 *
 */
void mostrarClientes(eCliente lista[],int tam,eLocalidad localidades[],int tamLoc);

/** \brief                          Busca un cliente al comparar con el id ingresado.
 *
 * \param lista[] eCliente          Array de clientes.
 * \param tam int                   Tamaño correspondiente al array clientes.
 * \param codigo int                Entero ingresado a comparar.
 * \return int                      Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int buscarCliente(eCliente lista[],int tam, int codigo);

/** \brief                          Toma el id ingresado por el usuario, al analizarlo y encontrar el espacio ocupado
 *                                  consulta para dar de baja al cliente. Al confirma la baja inicializa el campo isEmpty a true.
 *
 * \param lista[] eCliente          Array de clientes.
 * \param tam int                   Tamaño correspondiente al array clientes.
 * \param localidades[] eLocalidad  Array de localidades.
 * \param tamLoc int                Tamaño correspondiente al array localidades.
 * \return int                      Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int bajaCliente(eCliente lista[], int tam,eLocalidad localidades[], int tamLoc);

/** \brief                          Recorre el array de clientes en busca del codigo ingresado por el usuario.
 *                                  Se consulta el campo a modificar y al cumplir con las condiciones necesarias
 *                                  se modifica el campo del cliente con los datos ingresados.
 *
 * \param lista[] eCliente          Array de clientes.
 * \param tam int                   Tamaño correspondiente al array clientes.
 * \param localidades[] eLocalidad  Array de localidades.
 * \param tamLoc int                Tamaño correspondiente al array localidades.
 * \return int                      Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int modificarCliente(eCliente lista[], int tam,eLocalidad localidades[],int tamLoc);

/** \brief                          Ordena empleados por nombre de manera ascendente.
 *
 * \param lista[] eCliente          Array de clientes.
 * \param tam int                   Tamaño correspondiente al array clientes.
 * \return void                     No retorna ningún valor.
 *
 */
int ordenarClientes (eCliente lista[],int tam);

/** \brief                          Recorre el array cliente. Al encontrar el codigo ingresado y teniendo el campo isEmpty en
 *                                  false, modifica el nombre de este.
 *
 * \param codigo int                Entero ingresado a comparar.
 * \param clientes[] eCliente       Array de clientes.
 * \param tam int                   Tamaño correspondiente al array clientes.
 * \param nombre[] char             Cadena de caracteres a copiar.
 * \return int                      Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int cargarNombreCliente(int codigo,eCliente clientes[], int tam, char nombre[]);

/** \brief                      	Hardcodea un array de clientes con datos.
 *
 * \param clientes[] eCliente	    Array de clientes.
 * \param tam int               	Tamaño correspondiente al array clientes.
 * \param cant int             		Cantidad aceptada a mostrar.
 * \param pId int*          	    Puntero al espacio memoria donde se dejará el resultado de la función.
 * \return int                  	Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int hardcodearClientes(eCliente clientes[],int tam, int cant,int* pId);

/** \brief                          Recorre el array cliente. Al encontrar el codigo ingresado y teniendo el campo isEmpty en
 *                                  false, modifica el apellido de este.
 *
 * \param codigo int                Entero ingresado a comparar.
 * \param clientes[] eCliente       Array de clientes.
 * \param tam int                   Tamaño correspondiente al array clientes.
 * \param apellido[] char           Cadena de caracteres donde se copia la descripcion buscada.
 * \return int                      Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int cargarApellidoCliente(int codigo,eCliente clientes[], int tam, char apellido[]);


/** \brief                          Recorre el array cliente. Al encontrar el codigo ingresado y compara contra el codigo de
 *                                  la localidad. Una vez encontrado, carga la descripción en una variable.
 *
 * \param id int                    Entero ingresado a comparar.
 * \param clientes[] eCliente       Array de clientes.
 * \param tamC int                  Tamaño correspondiente al array clientes.
 * \param localidades[] eLocalidad  Array de localidades.
 * \param tam int                   Tamaño correspondiente al array localidades.
 * \param descripcion[] char        Cadena de caracteres donde se copia la descripcion buscada.
 * \return int                      Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int cargarDescripcionLocalidadPorCliente(int id,eCliente clientes[],int tamC,eLocalidad localidades[], int tam, char descripcion[]);
