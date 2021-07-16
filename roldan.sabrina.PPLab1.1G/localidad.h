#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];

}eLocalidad;

#endif // LOCALIDAD_H_INCLUDED

/** \brief                              Hardcodea un array de localidades con datos.
 *
 * \param localidades[] eLocalidad      Array de localidades.
 * \param tam int                       Tamaño del array localidades.
 * \param cant int                      Cantidad aceptada a mostrar.
 * \return int                          Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int hardcodearLocalidad(eLocalidad localidades[],int tam, int cant);

/** \brief                              Muestra la información de una localidad.
 *
 * \param unaLocalidad eLocalidad       Estructura de localidad.
 * \return void                         No retorna ningún valor.
 *
 */
void mostrarLocalidad(eLocalidad unaLocalidad);

/** \brief                              Recorre el array y muestra la información de todas las localidades.
 *
 * \param localidades[] eLocalidad      Array de localidades.
 * \param tam int                       Tamaño del array localidades.
 * \return void                         No retorna ningún valor.
 *
 */
void mostrarLocalidades(eLocalidad localidades[],int tam);

/** \brief                              Busca una localidad al comparar con el id ingresado.
 *
 * \param localidades[] eLocalidad      Array de localidades.
 * \param tam int                       Tamaño del array localidades.
 * \param id int                        Entero ingresado a comparar.
 * \return int                          Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int buscarLocalidad(eLocalidad localidades[],int tam, int id);

/** \brief                              Recorre el array localidades. Al encontrar el codigo ingresado
                                        carga la descripcion correspondiente en la variable.
 *
 * \param id int                        Entero ingresado a comparar.
 * \param localidades[] eLocalidad      Array de localidades.
 * \param tam int                       Tamaño del array localidades.
 * \param descripcion[] char            Cadena de caracteres donde se copia la descripcion buscada.
 * \return int                          Retorna 1 si el dato ingresado es correcto, 0 si no lo es.
 *
 */
int cargarDescripcionLocalidad(int id,eLocalidad localidades[], int tam, char descripcion[]);


