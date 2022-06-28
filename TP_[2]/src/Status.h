/*
 * Status.h
 *
 *  Created on: 27 jun. 2022
 *      Author: 54115
 */

#ifndef STATUS_H_
#define STATUS_H_

#include "inputs.h"

typedef struct
{
    int idStatusFlight;
    char statusFlight[20];
} Status;

/** \brief Función para mostrar la lista de Estado de vuelo.
 *
 * \param list Status
 * \param len int
 *
*/
void mostrarEstadoDeVuelo(Status status[], int len);

#endif /* STATUS_H_ */
