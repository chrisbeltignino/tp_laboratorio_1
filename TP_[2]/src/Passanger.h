#define TY 4
#define TS 3
#define MAX 300
#define LIBRE 0
#define OCUPADO 1

#include "inputs.h"

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int idType;
	int idStatusFlight;
	int isEmpty;
} Passenger;

/** \brief Indica la posicion del array del primer LIBRE
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int indicoPasajero(Passenger list[], int len);

/** \brief Harcodea todos los campos con los datos ingresados en cada variable y cambia el flag a 1
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param flag int*
*
*/
void cargaForzada(Passenger* list, int len, int* flag);

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger list[],int len);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(Passenger* list, int len, int order);

/** \brief Función para mostrar todos los pasajeros los pasajeros ACTIVOS.
 *
 * \param list Passenger*
 * \param len int
 *
*/
void mostrarListaPasajerosActivos(Passenger* list,int len);

/** \brief Función para mostrar todos los pasajeros con los ID de Type y Status.
 *
 * \param list Passenger*
 * \param len int
 *
*/
void mostrarListaPasajeros(Passenger* list,int len);

/** \brief Función para mostrar un pasajero.
 *
 * \param list Passenger*
 *
*/
void mostrarUnPasajero(Passenger list);
