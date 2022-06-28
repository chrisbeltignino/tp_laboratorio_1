/*
 * Type.h
 *
 *  Created on: 27 jun. 2022
 *      Author: 54115
 */

#ifndef TYPE_H_
#define TYPE_H_

#include "inputs.h"

typedef struct
{
    int idType;
    char typePassenger[20];
} Type;

/** \brief Función para mostrar la lista de Tipo de Pasajeros.
 *
 * \param list Type
 * \param len int
 *
*/
void mostrarTipoPasajero(Type typeP[], int len);

#endif /* TYPE_H_ */
