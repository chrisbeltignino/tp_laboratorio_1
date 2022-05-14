#include <stdio.h>

/** \brief Función para encapsular el menu de opciones.
*/
void menu ();
void limpiarConsola(void);
void mostrarMenu(int* opcion);
void mostrarSeparador(void);
void mostrarPasajeros(Passenger* list, int len, Type* typeP, Status* status, int* flag);
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
*/
int sortPassengersByCode(Passenger* list, int len, int order);
void mostrarPromedio(Passenger* listaPasajeros,int size, Type* estadoPasajero, int sizeTipo, Status* estadoVuelo, int sizeV);
int printPassenger(Passenger* list, int len ,Type* typeP, Status* status);
void mostrarListaPasajerosActivos(Passenger* list,int len);
void mostrarListaPasajeros(Passenger* list,int len);
void mostrarUnPasajero(Passenger list);
void mostrarUnPasajeroConTipo(Passenger list, Type typeP);
void mostrarUnPasajeroConTodo(Passenger list, Type typeP, Status status);
void mostrarUnPasajeroConDescripcion(Passenger list, Type* typeP, Status* status);
void mostrarTipoPasajero(Type typeP[], int len);
void mostrarEstadoDeVuelo(Status status[], int len);
int descripcionTypePassengerr(Passenger list,Type* typeP, int tam);
int descripcionStatusFlight(Passenger list,Status* status, int tam);
