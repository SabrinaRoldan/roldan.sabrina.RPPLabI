#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

/** \brief                              Muestra todos los juegos de la categor�a mesa.
 *
 * \param juegos[] eJuego               Array de juegos.
 * \param tamJ int                      Tama�o del array juegos.
 * \param categorias[] eCategoria       Array de categorias.
 * \param tamC int                      Tama�o del array categorias.
 * \return void                         No retorna ning�n valor.
 *
 */
void mostrarJuegosCategoriaMesa(eJuego juegos[],int tamJ,eCategoria categorias[],int tamC);

/** \brief                              Busca los alquileres realizados por un determinado cliente.
 *
 * \param alquileres[] eAlquileres      Array de alquileres.
 * \param tama int                      Tama�o del array alquileres.
 * \param clientes[] eCliente           Array de clientes.
 * \param tamC int                      Tama�o del array clientes.
 * \param juegos[] eJuego               Array de juegos.
 * \param tamJ int                      Tama�o del array juegos.
 * \param categorias[] eCategoria       Array de categorias.
 * \param tamCat int                    Tama�o del array categorias.
 * \param localidades[] eLocalidad      Array de localidades.
 * \param tamL int                      Tama�o del array localidades.
 * \return void                         No retorna ning�n valor.
 *
 */
void alquileresPorCliente(eAlquileres alquileres[],int tama,eCliente clientes[], int tamC,eJuego juegos[],int tamJ,
                          eCategoria categorias[],int tamCat,eLocalidad localidades[],int tamL);

/** \brief                              Muestra los alquileres de un cliente y el importe total de los mismos.
 *
 * \param alquileres[] eAlquileres      Array de alquileres.
 * \param tama int                      Tama�o del array alquileres.
 * \param clientes[] eCliente           Array de clientes.
 * \param tamC int                      Tama�o del array clientes.
 * \param juegos[] eJuego               Array de juegos.
 * \param tamJ int                      Tama�o del array juegos.
 * \param categorias[] eCategoria       Array de categorias.
 * \param tamCat int                    Tama�o del array categorias.
 * \param localidades[] eLocalidad      Array de localidades.
 * \param tamL int                      Tama�o del array localidades.
 * \return void                         No retorna ning�n valor.
 *
 */
void totalAlquileresCliente(eAlquileres alquileres[],int tama,eCliente clientes[],int tamC,eJuego juegos[],int tamJ,
                            eCategoria categorias[],int tamCat,eLocalidad localidades[],int tamL);

/** \brief                              Muestra una lista de clientes sin alquileres registrados.
 *
 * \param alquileres[] eAlquileres      Array de alquileres.
 * \param tama int                      Tama�o del array alquileres.
 * \param clientes[] eCliente           Array de clientes.
 * \param tamC int                      Tama�o del array clientes.
 * \param localidades[] eLocalidad      Array de localidades.
 * \param tamL int                      Tama�o del array localidades.
 * \return void                         No retorna ning�n valor.
 *
 */
void clientesSinAlquileres(eAlquileres alquileres[],int tama,eCliente clientes[], int tamC,eLocalidad localidades[],int tamL);

/** \brief                              Muestra una lista de juegos que no hayan sido alquilados.
 *
 * \param alquileres[] eAlquileres      Array de alquileres.
 * \param tama int                      Tama�o del array alquileres.
 * \param juegos[] eJuego               Array de juegos.
 * \param tamJ int                      Tama�o del array juegos.
 * \param categorias[] eCategoria       Array de categorias.
 * \param tamCat int                    Tama�o del array categorias.
 * \return void                         No retorna ning�n valor.
 *
 */
void juegosSinAlquiler(eAlquileres alquileres[],int tama,eJuego juegos[],int tamJ,eCategoria categorias[],int tamCat);

/** \brief                              Muestra una lista de juegos que fueron alquilados por mujeres.
 *
 * \param clientes[] eCliente           Array de clientes.
 * \param tamC int                      Tama�o del array clientes.
 * \param alquileres[] eAlquileres      Array de alquileres.
 * \param tamA int                      Tama�o del array alquileres.
 * \param juegos[] eJuego               Array de juegos.
 * \param tamJ int                      Tama�o del array juegos.
 * \param categorias[] eCategoria       Array de categorias.
 * \param tamCat int                    Tama�o del array categorias.
 * \return void                         No retorna ning�n valor.
 *
 */
void listarJuegosAlquiladosPorMujeres(eCliente clientes[],int tamC,eAlquileres alquileres[],int tamA,eJuego juegos[],
                                      int tamJ,eCategoria categorias[],int tamCat);

/** \brief                              Muestra los telefonos de los clientes que hayan realizado alg�n alquiler
 *                                      en la fecha ingresada a buscar.
 *
 * \param clientes[] eCliente           Array de clientes.
 * \param tamC int                      Tama�o del array clientes.
 * \param alquileres[] eAlquileres      Array de alquileres.
 * \param tamA int                      Tama�o del array alquileres.
 * \param localidades[] eLocalidad      Array de localidades.
 * \param tamL int                      Tama�o del array localidades.
 * \return void                         No retorna ning�n valor.
 *
 */
void listarTelefonosPorFecha(eCliente clientes[],int tamC,eAlquileres alquileres[],int tamA,eLocalidad localidades[],int tamL);

/** \brief                              Lista los juegos con m�s alquileres por clientes hombres.
 *
 * \param clientes[] eCliente           Array de clientes.
 * \param tamC int                      Tama�o del array clientes.
 * \param alquileres[] eAlquileres      Array de alquileres.
 * \param tamA int                      Tama�o del array alquileres.
 * \param localidades[] eLocalidad      Array de localidades.
 * \param tamL int                      Tama�o del array localidades.
 * \param juegos[] eJuego               Array de juegos.
 * \param tamJ int                      Tama�o del array juegos.
 * \param categorias[] eCategoria       Array de categorias.
 * \param tamCat int                    Tama�o del array categorias.
 * \return void                         No retorna ning�n valor.
 *
 */
void juegosMasAlquiladosPorHombres(eCliente clientes[],int tamC,eAlquileres alquileres[],int tamA,eLocalidad localidades[],
                                   int tamL,eJuego juegos[],int tamJ,eCategoria categorias[],int tamCat);

/** \brief                              Muestra una lista de clientes que alquilaron el juego ingresado.
 *
 * \param alquileres[] eAlquileres      Array de alquileres.
 * \param tama int                      Tama�o del array alquileres.
 * \param clientes[] eCliente           Array de clientes.
 * \param tamC int                      Tama�o del array clientes.
 * \param juegos[] eJuego               Array de juegos.
 * \param tamJ int                      Tama�o del array juegos.
 * \param categorias[] eCategoria       Array de categorias.
 * \param tamCat int                    Tama�o del array categorias.
 * \param localidades[] eLocalidad      Array de localidades.
 * \param tamL int                      Tama�o del array localidades.
 * \return void                         No retorna ning�n valor.
 *
 */
void listarClientesPorJuegos(eAlquileres alquileres[],int tama,eCliente clientes[], int tamC,eJuego juegos[],
                             int tamJ,eCategoria categorias[],int tamCat,eLocalidad localidades[],int tamL);

/** \brief                              Muestra la recaudaci�n en una fecha elegida por el usuario.
 *
 * \param alquileres[] eAlquileres      Array de alquileres.
 * \param tama int                      Tama�o del array alquileres.
 * \param clientes[] eCliente           Array de clientes.
 * \param tamC int                      Tama�o del array clientes.
 * \param juegos[] eJuego               Array de juegos.
 * \param tamJ int                      Tama�o del array juegos.
 * \param categorias[] eCategoria       Array de categorias.
 * \param tamCat int                    Tama�o del array categorias.
 * \return void                         No retorna ning�n valor.
 *
 */
void mostrarRecaudacionPorFecha(eAlquileres alquileres[],int tama,eCliente clientes[],int tamC,
                                eJuego juegos[],int tamJ,eCategoria categorias[],int tamCat,
                                eLocalidad localidades[],int tamL);

/** \brief                              Muestra una lista de clientes pertenecientes a una localidad seleccionada
 *                                      por el usuario.
 *
 * \param clientes[] eCliente           Array de clientes.
 * \param tamC int                      Tama�o del array clientes.
 * \param localidades[] eLocalidad      Array de localidades.
 * \param tamL int                      Tama�o del array localidades.
 * \return void                         No retorna ning�n valor.
 *
 */
void mostrarClientesPorLocalidad(eCliente clientes[],int tamC,eLocalidad localidades[],int tamL);

/** \brief                              Muestra la recaudacion total por cada localidad y la recaudacion global.
 *
 * \param localidades[] eLocalidad      Array de localidades.
 * \param tamL int                      Tama�o del array localidades.
 * \param clientes[] eCliente           Array de clientes.
 * \param tamC int                      Tama�o del array clientes.
 * \param alquileres[] eAlquileres      Array de alquileres.
 * \param tama int                      Tama�o del array alquileres.
 * \param juegos[] eJuego               Array de juegos.
 * \param tamJ int                      Tama�o del array juegos.
 * \param categorias[] eCategoria       Array de categorias.
 * \param tamCat int                    Tama�o del array categorias.
 * \return void                         No retorna ning�n valor.
 *
 */
void mostrarRecaudacionPorLocalidad(eLocalidad localidades[],int tamL,eCliente clientes[],int tamC,eAlquileres alquileres[],
                                    int tama,eJuego juegos[],int tamJ,eCategoria categorias[],int tamCat);

/** \brief                              Muestra por pantalla los juegos alquilados por localidad.
 *
 * \param clientes[] eCliente           Array de clientes.
 * \param tamC int                      Tama�o del array clientes.
 * \param alquileres[] eAlquileres      Array de alquileres.
 * \param tamA int                      Tama�o del array alquileres.
 * \param localidades[] eLocalidad      Array de localidades.
 * \param tamL int                      Tama�o del array localidades.
 * \param juegos[] eJuego               Array de juegos.
 * \param tamJ int                      Tama�o del array juegos.
 * \param categorias[] eCategoria       Array de categorias.
 * \param tamCat int                    Tama�o del array categorias.
 * \return void                         No retorna ning�n valor.
 *
 */
void juegosAlquiladosPorLocalidad(eCliente clientes[],int tamC,eAlquileres alquileres[],int tamA,eLocalidad localidades[],int tamL,eJuego juegos[]
                                  ,int tamJ,eCategoria categorias[],int tamCat);

/** \brief                              Muestra por pantalla la lista de alquileres seg�n la localidad.
 *
 * \param clientes[] eCliente           Array de clientes.
 * \param tamC int                      Tama�o del array clientes.
 * \param alquileres[] eAlquileres      Array de alquileres.
 * \param tamA int                      Tama�o del array alquileres.
 * \param localidades[] eLocalidad      Array de localidades.
 * \param tamL int                      Tama�o del array localidades.
 * \param juegos[] eJuego               Array de juegos.
 * \param tamJ int                      Tama�o del array juegos.
 * \param categorias[] eCategoria       Array de categor�as.
 * \param tamCat int                    Tama�o del array categor�as.
 * \return void                         No retorna ning�n valor.
 *
 */
void mostrarAlquileresPorLocalidad(eCliente clientes[],int tamC,eAlquileres alquileres[],int tamA,eLocalidad localidades[],
                                   int tamL,eJuego juegos[],int tamJ,eCategoria categorias[],int tamCat);
