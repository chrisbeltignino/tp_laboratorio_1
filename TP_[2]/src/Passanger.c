#include "Passanger.h"

int indicoPasajero(Passenger list[], int len)
{
	int i;
	int index=-1;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == LIBRE)
		{
			index = i;
			break;
		}
	}
	return index;
}

int initPassengers(Passenger list[], int len)
{
	int i;
	int index = -1;

	if(len == MAX)
	{
		for(i=0; i<len; i++)
		{
			list[i].isEmpty = LIBRE;
			index = 0;
		}
	}
	return index;
}

int findPassengerById(Passenger* list, int len)
{
	int i;
	int numero;
	int loEncontre=-1; //fuera de indice

	utn_getInt(&numero, "Ingrese el id a buscar: ", "ERROR, no se encontro la ID\n", 0, MAX, 3);
	for(i=0; i<len; i++)
	{
		if(numero == list[i].id && list[i].isEmpty == OCUPADO)
		{
			loEncontre=i;
		}
	}
	return loEncontre;
}

void cargaForzada(Passenger* list, int len, int* flag)
{
    int id[] = {1,2,3,4};
    char name[][51]={"Christian","Matias","Juliana","Leo"};
    char lastName[][51]= {"Tignino","Peron","Hernandez","Elizalde"};
    float price[]={50000,25000,60000,30000};
    char flycode[][10]={"23c23r","dwq3e23","awd223r","thtr345"};
    int typePassenger[]={1,4,1,2};
    int statusFlight[]={1,3,2,1};
    int isEmpty[]={1,1,1,1};

    for(int i=0;i<4;i++)
    {
    	list[i].id = id[i];
        strcpy(list[i].name, name[i]);
        strcpy(list[i].lastName, lastName[i]);
        list[i].price = price[i];
        strcpy(list[i].flycode, flycode[i]);
        list[i].idType = typePassenger[i];
        list[i].idStatusFlight = statusFlight[i];
        list[i].isEmpty = isEmpty[i];
    }
    *flag = 1;
    printf("Carga Forzada EXITOSA\n");
    system("pause");
}

void mostrarListaPasajerosActivos(Passenger* list,int len)
{
	int i;
	printf("\nMostrando lista de pasajeros ACTIVOS...\n\n"
		   " ___________________________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|%-20s|\n"
		   "|=====|===============|===============|=============|=====================|====================|====================|",
		      "ID",    "Nombre",      "Apellido",     "Precio",    "Tipo de pasajero",   "Estado de Vuelo",   "Codigo de vuelo");
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idStatusFlight == 1)
		{
			mostrarUnPasajero(list[i]);
		}
	}
	printf("\n|_____|_______________|_______________|_____________|_____________________|____________________|____________________|\n");
}

void mostrarListaPasajeros(Passenger* list,int len)
{
	int i;
	printf("\nMostrando lista de pasajeros...\n\n"
		   " ___________________________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|%-20s|\n"
		   "|=====|===============|===============|=============|=====================|====================|====================|",
		     "ID",     "Nombre",      "Apellido",     "Precio",    "Tipo de pasajero",   "Estado de Vuelo",   "Codigo de vuelo");
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			mostrarUnPasajero(list[i]);
		}
	}
	printf("\n|_____|_______________|_______________|_____________|_____________________|____________________|____________________|\n");
}

void mostrarUnPasajero(Passenger list)
{
	printf("\n|%-5d|",list.id);
	printf("%-15s|",list.name);
	printf("%-15s|",list.lastName);
	printf("%-13.2f|",list.price);
	printf("%-21d|",list.idType);
	printf("%-20d|",list.idStatusFlight);
	printf("%-20s|",list.flycode);
}

int sortPassengers(Passenger* list, int len, int order)
{
	int i;
	int j;
	Passenger aux;
	if(list != NULL && len > 0 && (order == 0 || order == 1))
	{
		for(i=0; i<len-1; i++)
		{
			for(j=i+1; j<len; j++)
			{
				if(list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
				{
					if(strcmp(list[i].lastName, list[j].lastName) < 0 && (list[i].idType < list[j].idType) && order == 1)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}else if(strcmp(list[i].lastName, list[j].lastName) > 0 && (list[i].idType > list[j].idType) && order == 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
		}
	}
	return 0;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
	int i;
	int j;
	Passenger aux;
	if(list != NULL && len > 0 && (order == 0 || order == 1))
	{
		for(i=0; i<len-1; i++)
		{
			for(j=i+1; j<len; j++)
			{
				if(list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
				{
					if(strcmp(list[i].flycode, list[j].flycode) < 0 && order == 1)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}else if(strcmp(list[i].flycode, list[j].flycode) > 0 && order == 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
		}
	}
	return 0;
}
