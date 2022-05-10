/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "utn.h"

#define LEN_PASSENGER 2000



int main(void) {
	setbuf(stdout,NULL);

	Passenger arrayPassenger[LEN_PASSENGER];

	int idPassenger = 0;
	int auxiliarIndice;
	int auxiliarId;
	int opcion;
	int opcion2;

	initPassengers(arrayPassenger,LEN_PASSENGER);



	do
	   {
		   if(!utn_getNumero(&opcion,
		   							"\n1.Alta de Pasajero"
		   							"\n2.Modificar Pasajero"
		   							"\n3.Baja de Pasajero"
		   							"\n4.Informes"
		   							"\n5.Salir\n",
		   					        "\nError opcion invalida",1,5,2) )
		   {
			   switch(opcion)
			   {

			   case 1:
				   	   auxiliarIndice = getEmptyIndex(arrayPassenger, LEN_PASSENGER);
				   	   if(auxiliarIndice >= 0)
				   	   {
				   		   if(addPassenger(arrayPassenger, LEN_PASSENGER, &idPassenger, auxiliarIndice) == 0)
				   				   {
				   			   	   	   printf("\nCarga realizada con exito\n");
				   			   	   	   printPassenger(arrayPassenger, LEN_PASSENGER);
				   				   }
				   	   }
				   	   break;
			   case 2:
				   if(info_cargaActiva(arrayPassenger,LEN_PASSENGER) == 0)
				   {
					   do
					   {
						   if(!utn_getNumero(&opcion2,
						   		   							"\n1.Modificar Nombre "
						   		   							"\n2.Modificar Apellido"
						   		   							"\n3.Modificar Precio"
						   		   							"\n4.Modificar Tipo de Pasajero"
								   	   	   	   	   	   	   	"\n5.Modificar Codigo de Vuelo"
						   		   							"\n6.Salir\n",
						   		   					        "\nError opcion invalida",1,6,2) )
						   {
						   switch(opcion2)
						   {
						   case 1:
							   if(!utn_getNumero(&auxiliarId, "\nIngrese ID del Pasajero:\n","\nID invalido",0,idPassenger,2))
							   {
								   auxiliarIndice = findPassengerById(arrayPassenger, LEN_PASSENGER, auxiliarId);
								   if(auxiliarIndice >= 0 &&
										   !changeName(arrayPassenger, LEN_PASSENGER, auxiliarIndice))
								   {
									   printf("\nSe modifico nombre de Pasajero %d correctamente\n",auxiliarIndice);
								   }
							   }
							   break;
						   }
						   }
					   }while(opcion2 != 5);
				   }
				   break;
			   case 3:
				   break;
			   case 4:
				   printPassenger(arrayPassenger, LEN_PASSENGER);
				   break;

			   }
		   }

	   }while(opcion != 5);



	return EXIT_SUCCESS;
}
