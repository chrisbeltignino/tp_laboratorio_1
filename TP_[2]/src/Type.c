#include "Type.h"

void mostrarTipoPasajero(Type typeP[], int len)
{
    int i;

	printf(" ___________________________\n"
		   "|%-5s|%-21s|\n"
		   "|=====|=====================|\n",
		     "ID",   "Tipo de pasajero");

    for(i=0;i<len;i++)
    {
        printf("|%-5d|%-21s|\n", typeP[i].idType, typeP[i].typePassenger);
    }
    printf("|_____|_____________________|\n");
}

