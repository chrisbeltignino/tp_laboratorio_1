/*
 * Nexo.h
 *
 *  Created on: 27 jun. 2022
 *      Author: 54115
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "Type.h"
#include "Status.h"
#include "Passanger.h"
#include "outputs.h"
#include "inputs.h"

/** \brief Valida la ALTA y cambia el flag a 1 una vez dada la primera alta
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param list Type* Pointer to array of types
* \param list Status* Pointer to array of status
* \param flag int*
*
*/
void altaPasajeros(Passenger* list, int len, Type* typeP, Status* status, int* flag);
/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
		  free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int idtype, int idStatusFlight, char flycode[], Type typeP[], Status status[]);
/** \brief Llena todas las variables auxiliares con los datos que el usuario ingrese y lleva como parametro a la funcion "addPassenger[]"
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param list Type* Pointer to array of types
* \param list Status* Pointer to array of status
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int cargarPasajero(Passenger* list, int len, Type* typeP, Status* status);

/** \brief Valida la BAJA una vez que el flag es 1
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param list Type* Pointer to array of types
* \param list Status* Pointer to array of status
* \param flag int*
*
*/
void bajaPasajeros(Passenger* list, int len, Type* typeP, Status* status, int* flag);
/** \brief Valida la MODIFICACION una vez que el flag es 1
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param list Type* Pointer to array of types
* \param list Status* Pointer to array of status
* \param flag int*
*
*/
void modificarPasajeros(Passenger* list, int len, Type* typeP, Status* status, int* flag);
/** \brief Llena todas las variables auxiliares con los datos que el usuario ingrese y modifica los campos de la
 * posicion de la ID ingresada para cambiar
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param list Type* Pointer to array of types
* \param list Status* Pointer to array of status
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int modificoPasajero(Passenger* list, int len, Type* typeP, Status* status);
/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, Type* typeP, Status* status);
/** \brief Función para mostrar todos los pasajeros.
 *
 * \param list Passenger*
 * \param len int
 * \param list Type*
 * \param list Status*
 * \param flag int*
 *
*/
void mostrarPasajeros(Passenger* list, int len, Type* typeP, Status* status, int* flag);
/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \param list Type*
* \param list Status*
* \return int
*/
int printPassenger(Passenger* list, int len ,Type* typeP, Status* status);
/** \brief Función para devolver la posicion del indice de la estructura Type.
 *
 * \param list Passenger
 * \param len int
 * \param list Type*
 * \return int posicion del indicie
*/
int descripcionTypePassengerr(Passenger list,Type* typeP, int tam);
/** \brief Función para devolver la posicion del indice de la estructura Status.
 *
 * \param list Passenger
 * \param len int
 * \param list Status*
 * \return int posicion del indicie
*/
int descripcionStatusFlight(Passenger list,Status* status, int tam);
/** \brief Función para calcaular el promedio de los pasajeros, el total de
 * 		   precios de todos los pasajeros y los pasajeros con promedio mayor al precio de pasaje .
 *
 * \param list Passenger*
 * \param length Passenger int
 * \param list Type*
 * \param length Type int
 * \param list Status*
 * \param length Status int
 *
*/
void mostrarPromedio(Passenger* list,int len, Type* typeP, int lenT, Status* status, int lenS);
/** \brief Función para mostrar un pasajero con la ID de la estructura Type.
 *
 * \param list Passenger
 * \param list Type
 *
*/
void mostrarUnPasajeroConTipo(Passenger list, Type typeP);
/** \brief Función para mostrar todos los pasajeros con la ID de Type y Status.
 *
 * \param list Passenger
 * \param list Type
 * \param list Status
 *
*/
void mostrarUnPasajeroConTodo(Passenger list, Type typeP, Status status);
/** \brief Función para mostrar todos los pasajeros con la descripcion de Type y Status.
 *
 * \param list Passenger
 * \param list Type*
 * \param list Status*
 *
*/
void mostrarUnPasajeroConDescripcion(Passenger list, Type* typeP, Status* status);

#endif /* NEXO_H_ */
