#include "Nexo.h"

void altaPasajeros(Passenger* list, int len, Type* typeP, Status* status, int* flag)
{
	int respuestaCargar;
	respuestaCargar = cargarPasajero(list, MAX, typeP, status);

	if(respuestaCargar==-1)
	{
		printf("No se pudo cargar el pasajero\n");
		system("pause");
	}
	else
	{
		printf("Carga realizada con exito\n");
		*flag=1;
		system("pause");
	}
	system("pause");
	limpiarConsola();
}

int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int idtype, int idStatusFlight, char flycode[], Type typeP[], Status status[])
{
	int retorno;
	int indice;

	if(list!= NULL && len > 0)
	{
		indice = indicoPasajero(list,len);
		if(indice != -1)
		{
			list[indice].id = id;
			SizeString(name);
			strcpy(list[indice].name, name);
			SizeString(lastName);
			strcpy(list[indice].lastName, lastName);
			list[indice].price = price;
			list[indice].idType = idtype;
			list[indice].idStatusFlight = idStatusFlight;
			strcpy(list[indice].flycode, flycode);

			printf("\nEl pasajero a AGREGAR es...\n\n"
				   " ___________________________________________________________________________________________________________________\n"
				   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|%-20s|\n"
				   "|=====|===============|===============|=============|=====================|====================|====================|",
				     "ID",     "Nombre",      "Apellido",     "Precio",   "Tipo de pasajero",    "Estado de Vuelo",   "Codigo de vuelo");
			mostrarUnPasajero(list[indice]);
			printf("\n|_____|_______________|_______________|_____________|_____________________|____________________|____________________|\n");

			if(!verificarConfirmacion("\nIngrese 's' para confirmar el alta del producto: "))
			{
				list[indice].isEmpty = OCUPADO;
				retorno = 0;
			}else
			{
				retorno = -1;
			}
		}
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

int cargarPasajero(Passenger* list, int len, Type* typeP, Status* status)
{
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigodeVuelo[10];
	int idTipo;
	int idEstadoVuelo;
	int retorno;

	if(list!= NULL && len > 0)
	{
		retorno = indicoPasajero(list,len);
		if (retorno != -1)
		{
			id = retorno + 1;
			utn_getString(nombre, "Ingrese nombre: ", "ERROR. Ingrese nombre nuevamente, hasta 51 caracteres, reingrese: ", 51, 3);
			utn_getString(apellido, "Ingrese apellido: ", "ERROR. Ingrese apellido nuevamente, hasta 51 caracteres, reingrese: ", 51, 3);
			utn_getFloat(&precio, "Ingrese precio: ", "ERROR. Ingrese precio nuevamente : ", 1, 1000000000, 3);
			mostrarTipoPasajero(typeP, TY);
			utn_getInt(&idTipo, "Ingrese el tipo (Turistica = 1, Economica = 2, Business = 3, Primera clase = 4): ", "ERROR. Ingrese el tipo nuevamente (Turistica = 1, Economica = 2, Business = 3, Primera clase = 4): ", 0, 4, 3);
			mostrarEstadoDeVuelo(status, TS);
			utn_getInt(&idEstadoVuelo, "Ingrese el estado de vuelo (Activo = 1, Inactivo = 2, Demorado = 3): ", "ERROR. Ingrese el estado de vuelo (Activo = 1, Inactivo = 2, Demorado = 3): ", 0, 3, 3);
			pedirCadena(codigodeVuelo, "Ingrese codigo de vuelo: ", "ERROR. Ingrese codigo de vuelo nuevamente: ", 10);
			retorno = addPassenger(list,len,id,nombre,apellido,precio,idTipo,idEstadoVuelo,codigodeVuelo,typeP,status);
		}
	}
	return retorno;
}

void modificarPasajeros(Passenger* list, int len, Type* typeP, Status* status, int* flag)
{
	int respuestaModificar;
	if(*flag==1)
	{
		respuestaModificar = modificoPasajero(list, MAX, typeP, status);
		if(respuestaModificar == -1)
		{
			printf("No se pudo realizar la modificacion\n");
			system("pause");
		}
		else if(respuestaModificar == 1)
		{
			printf("Se cancelo la modificacion\n");
			system("pause");
		}
		else
		{
			printf("Modificacion realizada correctamente\n");
			system("pause");
		}
	}
	else
	{
		printf("Error, debe tener cargado minimo 1 pasajero para ingresar a esta opcion.\n");
		system("pause");
	}
}

int modificoPasajero(Passenger* list, int len, Type* typeP, Status* status)
{
	int retorno; //0 si no se pudo borrar, 1 si se pudo borrar
	int index;
	char nombre[51];
	char apellido[51];
	float precio;
	int idTipo;
	int idEstadoVuelo;
	int opcion;
	Passenger aux;

	if (list != NULL && len > 0)
	{
		printPassenger(list, len ,typeP, status);
		index = findPassengerById(list, len);
		aux = list[index];
		if(index!=-1)
		{
			retorno=0;
			printf("\nEl pasajero a MODOFICAR es...\n"
				   " ___________________________________________________________________________________________________________________\n"
				   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|%-20s|\n"
				   "|=====|===============|===============|=============|=====================|====================|====================|",
				   	 "ID",     "Nombre",      "Apellido",    "Precio",     "Tipo de pasajero",   "Estado de Vuelo",   "Codigo de vuelo");
			mostrarUnPasajeroConDescripcion(list[index], typeP, status);
			printf("\n|_____|_______________|_______________|_____________|_____________________|____________________|____________________|\n");

			pedirEntero(&opcion, "-------------------------------------\n"
								 "1. Nombre Pasajero\n"
								 "2. Apellido Pasajero\n"
								 "3. Precio Pasajero\n"
								 "4. Tipo de Pasajero Pasajero\n"
								 "5. Codigo de vuelo Pasajero\n"
								 "6. No quiero modificar nada\n"
								 "-------------------------------------\n"
								 "Ingrese que desea modificar: ",
								 "-------------------------------------\n"
								 "1. Nombre Pasajero\n"
								 "2. Apellido Pasajero\n"
								 "3. Precio Pasajero\n"
								 "4. Tipo de Pasajero Pasajero\n"
								 "5. Codigo de vuelo Pasajero\n"
								 "6. No quiero modificar nada\n"
								 "-------------------------------------\n"
								 "Opcion invalida, reingrese: ", 1, 6);
			switch(opcion)
			{
			case 1:
				limpiarConsola();
				utn_getString(nombre, "Ingrese un nuevo nombre: ", "ERROR. Ingrese nombre nuevamente, hasta 51 caracteres, reingrese: ", 51, 3);
				SizeString(nombre);
				strcpy(aux.name, nombre);
				break;
			case 2:
				limpiarConsola();
				utn_getString(apellido, "Ingrese un nuevo apellido: ", "ERROR. Ingrese nombre nuevamente, hasta 51 caracteres, reingrese: ", 51, 3);
				SizeString(apellido);
				strcpy(aux.lastName, apellido);
				break;
			case 3:
				limpiarConsola();
				utn_getFloat(&precio, "Ingrese un nuevo precio: ", "ERROR. Ingrese precio nuevamente : ", 1, 1000000000, 3);
				aux.price = precio;
				break;
			case 4:
				limpiarConsola();
				mostrarTipoPasajero(typeP, TY);
				utn_getInt(&idTipo, "Ingrese el tipo (Turistica = 1, Economica = 2, Business = 3, Primera clase = 4): ", "ERROR. Ingrese el tipo nuevamente (Turistica = 1, Economica = 2, Business = 3, Primera clase = 4): ", 0, 4, 3);
				aux.idType = idTipo;
				break;
			case 5:
				limpiarConsola();
				mostrarEstadoDeVuelo(status, TS);
				utn_getInt(&idEstadoVuelo, "Ingrese el estado de vuelo (Activo = 1, Inactivo = 2, Demorado = 3): ", "ERROR. Ingrese el estado de vuelo (Activo = 1, Inactivo = 2, Demorado = 3): ", 0, 3, 3);
				aux.idStatusFlight = idEstadoVuelo;
			break;
			case 6:
				printf("Saliendo");
			break;
			default:
				printf("Opcion no valida");
			}

			if(retorno==0)
			{
				printf("\nEl pasajero a modificar va a quedar de la siguiente manera:...\n"
					   " ___________________________________________________________________________________________________________________\n"
					   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|%-20s|\n"
					   "|=====|===============|===============|=============|=====================|====================|====================|",
					      "ID",   "Nombre",       "Apellido",     "Precio",    "Tipo de pasajero",   "Estado de Vuelo",   "Codigo de vuelo");
				mostrarUnPasajeroConDescripcion(aux, typeP, status);
				printf("\n|_____|_______________|_______________|_____________|_____________________|____________________|____________________|\n");

				if(!verificarConfirmacion("\nIngrese 's' para confirmar la modificacion del pasajero: "))
				{
					list[index]=aux;
				}
				else
				{
					printf("\nNo se realizo la modificacion");
					retorno = 1;
				}
			}
		}
		else
		{
			retorno = -1;
		}
	}
	else
	{
		retorno=-1;
	}

	return retorno;
}

void bajaPasajeros(Passenger* list, int len, Type* typeP, Status* status, int* flag)
{
	int respuestaBorrar;
	if(*flag == 1)
	{
		respuestaBorrar = removePassenger(list, MAX, typeP, status);
		if(respuestaBorrar == -1)
		{
			printf("No se pudo Borrar al pasajero\n");
			system("pause");
		}
		else
		{
			printf("Pasajero borrado con exito\n");
			system("pause");
		}
	}
	else
	{
		printf("Error, debe tener cargado minimo 1 pasajero para ingresar a esta opcion.\n");
		system("pause");
	}
	system("pause");
	limpiarConsola();
}

int removePassenger(Passenger* list, int len, Type* typeP, Status* status)
{
	int retorno=-1; //0 si no se pudo borrar, 1 si se pudo borrar
	int index;

	printPassenger(list, len ,typeP, status);
	index = findPassengerById(list,len);

	if(index!=-1)
	{
		printf("\nEl pasajero que quiere ELIMINAR es: \n"
			   " ___________________________________________________________________________________________________________________\n"
			   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|%-20s|\n"
			   "|=====|===============|===============|=============|=====================|====================|====================|",
			     "ID",     "Nombre",      "Apellido",    "Precio",     "Tipo de pasajero",   "Estado de Vuelo",   "Codigo de vuelo");
		mostrarUnPasajeroConDescripcion(list[index], typeP, status);
		printf("\n|_____|_______________|_______________|_____________|_____________________|____________________|____________________|\n");
		if(!verificarConfirmacion("\nIngrese 's' para confirmar la baja del pasajero: "))
		{
			retorno = 0;
			list[index].isEmpty = LIBRE;
		}
		else
		{
			printf("\nNo se realizo la baja");
			retorno = -1;
		}
	}
	return retorno;
}

void mostrarPasajeros(Passenger* list, int len, Type* typeP, Status* status, int* flag)
{
	int opcionListado;
	int orden;
	int respuestaMostrar;
	int respuestaMostrarAlfabeticamente;
	if(*flag==1)
	{
		do
		{
			pedirEntero(&opcionListado, "-------------------------------------\n"
										 "1. Listado de los pasajeros ordenados alfabéticamente.\n"
										 "2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
										 "3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n"
										 "4. SALIR\n"
										 "-------------------------------------\n"
										 "Ingrese una opcion: ",
										 "-------------------------------------\n"
										 "1. Listado de los pasajeros ordenados alfabéticamente.\n"
										 "2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
										 "3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n"
										 "4. SALIR\n"
										 "-------------------------------------\n"
										 "Opcion invalida, reingrese: ", 1, 4);
			switch(opcionListado)
			{
				case 1:
					respuestaMostrar = printPassenger(list, MAX, typeP, status);
					do
					{
						pedirEntero(&orden, "-------------------------------------\n"
											 "1. Listado de los pasajeros ordenados alfabéticamente ASCENDENTE.\n"
											 "2. Listado de los pasajeros ordenados alfabéticamente DESCENDENTE.\n"
											 "3. SALIR\n"
											 "-------------------------------------\n"
											 "Ingrese una opcion: ",
											 "-------------------------------------\n"
											 "1. Listado de los pasajeros ordenados alfabéticamente ASCENDENTE.\n"
											 "2. Listado de los pasajeros ordenados alfabéticamente DESCENDENTE.\n"
											 "3. SALIR\n"
											 "-------------------------------------\n"
											 "Opcion invalida, reingrese: ", 1, 3);
						switch(orden)
						{
							case 1:
								respuestaMostrarAlfabeticamente = sortPassengers(list, MAX, 0);
								if(respuestaMostrarAlfabeticamente == 0)
								{
									printPassenger(list, MAX, typeP, status);
									system("pause");
								}
							break;
							case 2:
								respuestaMostrarAlfabeticamente = sortPassengers(list, MAX, 1);
								if(respuestaMostrarAlfabeticamente == 0)
								{
									printPassenger(list, MAX, typeP, status);
									system("pause");
								}
							break;
						}
					}while(orden!=3);

					if(respuestaMostrar == -1)
					{
						printf("No se pueden mostrar los pasajeros\n");
						system("pause");
					}

				break;
				case 2:
					mostrarPromedio(list, MAX, typeP, TY, status, TS);
					system("pause");

				break;
				case 3:
					respuestaMostrar = printPassenger(list, MAX, typeP, status);
					do
					{
						pedirEntero(&orden, "-------------------------------------\n"
											 "1. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ ASCENDENTE.\n"
											 "2. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ DESCENDENTE.\n"
											 "3. SALIR\n"
											 "-------------------------------------\n"
											 "Ingrese una opcion: ",
											 "-------------------------------------\n"
											 "1. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ ASCENDENTE.\n"
											 "2. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ DESCENDENTE.\n"
											 "3. SALIR\n"
											 "-------------------------------------\n"
											 "Opcion invalida, reingrese: ", 1, 3);
						switch(orden)
						{
						case 1:
							respuestaMostrarAlfabeticamente = sortPassengersByCode(list, MAX, 0);
							if(respuestaMostrarAlfabeticamente == 0)
							{
								mostrarListaPasajerosActivos(list, MAX);
								system("pause");
							}
						break;
						case 2:
							respuestaMostrarAlfabeticamente = sortPassengersByCode(list, MAX, 1);
							if(respuestaMostrarAlfabeticamente == 0)
							{
								mostrarListaPasajerosActivos(list, MAX);
								system("pause");
							}
						break;
						}
					}while(orden!=3);

					if(respuestaMostrar == -1)
					{
						printf("No se pueden mostrar los pasajeros\n");
						system("pause");
					}
				break;
			}
		}while(opcionListado!=4);
	}else
	{
		printf("Error, debe tener cargado minimo 1 pasajero para ingresar a esta opcion.\n");
		system("pause");
	}
}


int printPassenger(Passenger* list, int len ,Type* typeP, Status* status)
{
	int i;
	printf("\nMostrando lista de pasajeros...\n\n"
		   " ______________________________________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|%-20s|%-10s|\n"
		   "|=====|===============|===============|=============|=====================|====================|====================|==========|",
		      "ID",    "Nombre",      "Apellido",     "Precio",    "Tipo de pasajero",   "Estado de Vuelo",   "Codigo de vuelo",  "ESTADO");
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			mostrarUnPasajeroConDescripcion(list[i], typeP, status);
		}
	}
	printf("\n|_____|_______________|_______________|_____________|_____________________|____________________|____________________|__________|\n");
	return 0;
}

void mostrarUnPasajeroConTipo(Passenger list, Type typeP)
{
	printf("\n|%-5d|",list.id);
	printf("%-15s|",list.name);
	printf("%-15s|",list.lastName);
	printf("%-13.2f|",list.price);
	printf("%-21d|",typeP.idType);
	printf("%-20d|",list.idStatusFlight);
	printf("%-20s|",list.flycode);
}

void mostrarUnPasajeroConTodo(Passenger list, Type typeP, Status status)
{
	printf("\n|%-5d|",list.id);
	printf("%-15s|",list.name);
	printf("%-15s|",list.lastName);
	printf("%-13.2f|",list.price);
	printf("%-21d|",typeP.idType);
	printf("%-20d|",status.idStatusFlight);
	printf("%-20s|",list.flycode);
}

void mostrarUnPasajeroConDescripcion(Passenger list, Type* typeP, Status* status)
{
    int tipoPasajero;
    int estadoVuelo;

    if(list.isEmpty == OCUPADO)
	{
    	estadoVuelo = descripcionStatusFlight(list, status, TS);
		tipoPasajero = descripcionTypePassengerr(list, typeP, TY);
		printf("\n|%-5d|",list.id);
		printf("%-15s|",list.name);
		printf("%-15s|",list.lastName);
		printf("%-13.2f|",list.price);
		printf("%-21s|",typeP[tipoPasajero].typePassenger);
		printf("%-20s|",status[estadoVuelo].statusFlight);
		printf("%-20s|",list.flycode);
	}
}

int descripcionStatusFlight(Passenger list,Status* status, int tam)
{
    int index;

    for(int i=0;i<tam;i++)
    {
        if(list.idStatusFlight==status[i].idStatusFlight)
        {
            index=i;
            break;
        }
    }
    return index;
}

int descripcionTypePassengerr(Passenger list,Type* typeP, int tam)
{
    int index;

    for(int i=0;i<tam;i++)
    {
        if(list.idType==typeP[i].idType)
        {
            index=i;
            break;
        }
    }
    return index;
}

void mostrarPromedio(Passenger* list,int len, Type* typeP, int lenT, Status* status, int lenS)
{
	float precioTotal = 0;
	float promedio;
	float contadorPasajeros = 0;
	for(int i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
		 precioTotal = list[i].price + precioTotal;
		 contadorPasajeros++;
		}
	}
	promedio = precioTotal/contadorPasajeros;
	printf("\nPrecio total de los pasajes: %.2f\nPrecio promedio de los pasajes: %.2f\n",precioTotal,promedio);

	printf("\nPasajeros con promedio mayor al precio de pasaje...\n"
		   " ___________________________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|%-20s|\n"
		   "|=====|===============|===============|=============|=====================|====================|====================|",
		      "ID",   "Nombre",       "Apellido",    "Precio",     "Tipo de pasajero",   "Estado de Vuelo",   "Codigo de vuelo");
	for(int i = 0; i < len; i++)
	{
		for(int j = 0;j<lenT;j++)
		{
			for(int z = 0;z<lenS;z++)
			{
				if(list[i].isEmpty == OCUPADO && list[i].price > promedio && list[i].idType ==  typeP[j].idType && list[i].idStatusFlight == status[z].idStatusFlight)
				{
					mostrarUnPasajeroConTodo(list[i], typeP[j], status[z]);
				}
			}
		}
	}
	printf("\n|_____|_______________|_______________|_____________|_____________________|____________________|____________________|\n");
}
