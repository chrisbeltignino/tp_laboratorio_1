#include "outputs.h"

void limpiarConsola(void)
{
	printf("\n\n\n\n");
}

void mostrarSeparador(void)
{
	printf("--------------\n");
}

void mostrarMenu(int* opcion)
{
	pedirEntero(opcion, "-------------------------------------\n"
								 "1. ALTA Pasajero\n"
								 "2. MODIFICAR Pasajero\n"
								 "3. BAJA Pasajero\n"
								 "4. LISTADO Pasajero\n"
	    						 "5. ALTA FORZADA Pasajero\n"
								 "6. SALIR\n"
								 "-------------------------------------\n"
								 "Ingrese una opcion: ",
								 "-------------------------------------\n"
								 "1. ALTA Pasajero\n"
								 "2. MODIFICAR Pasajero\n"
								 "3. BAJA Pasajero\n"
								 "4. LISTADO Pasajero\n"
								 "5. ALTA FORZADA Pasajero\n"
								 "6. SALIR\n"
								 "-------------------------------------\n"
								 "Opcion invalida, reingrese: ", 1, 6);
}
