#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menus.h"
#include "Utn.h"

int Menu()
{
	int opciones;
	pedirEntero(&opciones,
				"------------------------------------>-MENU-<------------------------------------\n"
				"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
				"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
				"3. Alta de pasajero\n"
				"4. Modificar datos de pasajero\n"
				"5. Baja de pasajero\n"
				"6. Listar pasajeros\n"
				"7. Ordenar pasajeros\n"
				"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
				"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
				"10. Salir\n"
				"--------------------------------------------------------------------------------\n"
				"Ingrese una opcion: ",
				"--------------------------------------------------------------------------------\n"
				"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
				"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
				"3. Alta de pasajero\n"
				"4. Modificar datos de pasajero\n"
				"5. Baja de pasajero\n"
				"6. Listar pasajeros\n"
				"7. Ordenar pasajeros\n"
				"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
				"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
				"10. Salir\n"
				"--------------------------------------------------------------------------------\n"
				"Error, opcion invalida: ",1,10);

	return opciones;
}

int Passenger_menuModify()
{
	int opciones;
	pedirEntero(&opciones,
				"------------------>-MENU MODIFICACIONES-<-------------------\n"
				"1. Nombre Pasajero\n"
				"2. Apellido Pasajero\n"
				"3. Precio Pasajero\n"
				"4. Tipo de Pasajero Pasajero\n"
				"5. Codigo de vuelo Pasajero\n"
				"6. Salir\n"
				"-------------------------------------\n"
				"Ingrese que desea modificar: ",
				"-------------------------------------\n"
				"1. Nombre Pasajero\n"
				"2. Apellido Pasajero\n"
				"3. Precio Pasajero\n"
				"4. Tipo de Pasajero Pasajero\n"
				"5. Codigo de vuelo Pasajero\n"
				"6. Salir\n"
				"-----------------------------------------------------------\n"
				"Opcion invalida, reingrese: ",1,6);

	return opciones;
}

int Passenger_menuOrden()
{
	int opciones;

	pedirEntero(&opciones,  "----------------------------------------->-MENU ORDEN-<--------------------------------------------\n"
							"1. Listado de los pasajeros ordenados alfabéticamente.\n"
							"2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
							"3. Listado de los pasajeros por Código de vuelo y estados de vuelos\n"
							"4. Mostrar listado ordenado\n"
							"5. SALIR\n"
							"-------------------------------------\n"
							"Ingrese una opcion: ",
							"-------------------------------------\n"
							"1. Listado de los pasajeros ordenados alfabéticamente.\n"
							"2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
							"3. Listado de los pasajeros por Código de vuelo y estados de vuelos\n"
							"4. Mostrar listado ordenado\n"
							"5. SALIR\n"
							"---------------------------------------------------------------------------------------------------\n"
							"Opcion invalida, reingrese: ", 1, 5);

	return opciones;
}

int Passenger_subMenuOrden()
{
	int opciones;

	pedirEntero(&opciones,  "------------------------>-CRITERIO DE ORDEN-<---------------------\n"
							"0. Listado de los pasajeros ordenados alfabéticamente DESCENDENTE.\n"
							"1. Listado de los pasajeros ordenados alfabéticamente ASCENDENTE.\n"
							"2. SALIR\n"
							"-------------------------------------\n"
							"Ingrese una opcion: ",
							"-------------------------------------\n"
							"0. Listado de los pasajeros ordenados alfabéticamente DESCENDENTE.\n"
							"1. Listado de los pasajeros ordenados alfabéticamente ASCENDENTE.\n"
							"2. SALIR\n"
							"-------------------------------------\n"
							"Opcion invalida, reingrese: ", 0, 2);

	return opciones;
}
