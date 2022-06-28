#include "Status.h"

void mostrarEstadoDeVuelo(Status status[], int len)
{
    int i;
	printf(" __________________________\n"
		   "|%-5s|%-20s|\n"
		   "|=====|====================|\n",
		      "ID",  "Estado de Vuelo");

    for(i=0;i<len;i++)
    {
        printf("|%-5d|%-20s|\n", status[i].idStatusFlight, status[i].statusFlight);
    }
    printf("|_____|____________________|\n");
}
