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

int main(void)
{
	setbuf(stdout, NULL);

	Passenger arrayPassenger[LEN_PASSENGER];

	int idPassenger = 0;
	int auxiliarIndice;
	int auxiliarId;
	int opcion;
	int opcion2;
	int opcion3;

	initPassengers(arrayPassenger, LEN_PASSENGER);

	info_addForce(arrayPassenger, LEN_PASSENGER, 0, &idPassenger, "Nicolás", "Rodriguez", 50000, "JEWQ", 5, 1);
	info_addForce(arrayPassenger, LEN_PASSENGER, 1, &idPassenger, "Fausto", "Alvarez", 50000, "JEWQ", 5, 1);
	info_addForce(arrayPassenger, LEN_PASSENGER, 2, &idPassenger, "Rafael", "Simon", 50000, "JETQ", 5, 1);
	info_addForce(arrayPassenger, LEN_PASSENGER, 3, &idPassenger, "Miguel", "Perez", 50000, "JEWTQ", 5, 1);
	info_addForce(arrayPassenger, LEN_PASSENGER, 4, &idPassenger, "Julian", "Hilo", 50000, "JEWQA", 5, 1);
	info_addForce(arrayPassenger, LEN_PASSENGER, 5, &idPassenger, "Federico", "Terna", 50000, "XWQ", 5, 1);
	info_addForce(arrayPassenger, LEN_PASSENGER, 6, &idPassenger, "Marcos", "Filipo", 50000, "AEWQ", 5, 1);
	info_addForce(arrayPassenger, LEN_PASSENGER, 7, &idPassenger, "Vicente", "Scheiner", 50000, "BEWQ", 5, 1);
	info_addForce(arrayPassenger, LEN_PASSENGER, 8, &idPassenger, "Carlos", "Rudolf", 50000, "JEWQ", 5, 1);
	info_addForce(arrayPassenger, LEN_PASSENGER, 9, &idPassenger, "Ramiro", "Willian", 50000, "CEWQ", 5, 1);
	info_addForce(arrayPassenger, LEN_PASSENGER, 10, &idPassenger, "Kevin", "Bale", 50000, "JTWQ", 5, 1);


	do
	{
		if (!utn_getNumero(&opcion, "\n1.Alta de Pasajero"
				"\n2.Modificar Pasajero"
				"\n3.Baja de Pasajero"
				"\n4.Informes"
				"\n5.Salir\n", "\nError opcion invalida", 1, 5, 2))
		{
			switch (opcion)
			{

			case 1:
				auxiliarIndice = getEmptyIndex(arrayPassenger, LEN_PASSENGER);
				if (auxiliarIndice >= 0)
				{
					if (addPassenger(arrayPassenger, LEN_PASSENGER,
							&idPassenger, auxiliarIndice) == 0)
					{
						printf("\nCarga realizada con exito\n");
						printPassenger(arrayPassenger, LEN_PASSENGER);
					}
				}
				break;
			case 2:
				if (info_cargaActiva(arrayPassenger, LEN_PASSENGER) == 0)
				{
					do
					{
						if (!utn_getNumero(&opcion2, "\n1.Modificar Nombre "
								"\n2.Modificar Apellido"
								"\n3.Modificar Precio"
								"\n4.Modificar Tipo de Pasajero"
								"\n5.Modificar Codigo de Vuelo"
								"\n6.Salir\n", "\nError opcion invalida", 1, 6,
								2))
						{
							switch (opcion2)
							{

							case 1:
								if (!utn_getNumero(&auxiliarId,
										"\nIngrese ID del Pasajero:\n",
										"\nID invalido", 0, idPassenger, 2))
								{
									auxiliarIndice = findPassengerById(
											arrayPassenger, LEN_PASSENGER,
											auxiliarId);
									if (auxiliarIndice >= 0
											&& !changeName(arrayPassenger,
											LEN_PASSENGER, auxiliarIndice))
									{
										printf(
												"\nSe modifico nombre de Pasajero %d correctamente\n",
												auxiliarIndice);
									}
								}
								break;
							case 2:
								if (!utn_getNumero(&auxiliarId,
										"\nIngrese ID del Pasajero:\n",
										"\nID invalido", 0, idPassenger, 2))
								{
									auxiliarIndice = findPassengerById(
											arrayPassenger, LEN_PASSENGER,
											auxiliarId);
									if (auxiliarIndice >= 0
											&& !changeLastName(arrayPassenger,
											LEN_PASSENGER, auxiliarIndice))
									{
										printf(
												"\nSe modifico apellido de Pasajero %d correctamente\n",
												auxiliarIndice);
									}
								}
								break;
							case 3:
								if (!utn_getNumero(&auxiliarId,
										"\nIngrese ID del Pasajero:\n",
										"\nID invalido", 0, idPassenger, 2))
								{
									auxiliarIndice = findPassengerById(
											arrayPassenger, LEN_PASSENGER,
											auxiliarId);
									if (auxiliarIndice >= 0
											&& !changePrice(arrayPassenger,
											LEN_PASSENGER, auxiliarIndice))
									{
										printf(
												"\nSe modifico el precio de Pasajero %d correctamente\n",
												auxiliarIndice);
									}
								}
								break;
							case 4:
								if (!utn_getNumero(&auxiliarId,
										"\nIngrese ID del Pasajero:\n",
										"\nID invalido", 0, idPassenger, 2))
								{
									auxiliarIndice = findPassengerById(
											arrayPassenger, LEN_PASSENGER,
											auxiliarId);
									if (auxiliarIndice >= 0
											&& !changeType(arrayPassenger,
											LEN_PASSENGER, auxiliarIndice))
									{
										printf(
												"\nSe modifico tipo de Pasajero %d correctamente\n",
												auxiliarIndice);
									}
								}
								break;
							case 5:
								if (!utn_getNumero(&auxiliarId,
										"\nIngrese ID del Pasajero:\n",
										"\nID invalido", 0, idPassenger, 2))
								{
									auxiliarIndice = findPassengerById(
											arrayPassenger, LEN_PASSENGER,
											auxiliarId);
									if (auxiliarIndice >= 0
											&& !changeCode(arrayPassenger,
											LEN_PASSENGER, auxiliarIndice))
									{
										printf(
												"\nSe modifico codigo de Pasajero %d correctamente\n",
												auxiliarIndice);
									}
								}
								break;

							}
						}
					} while (opcion2 != 6);
				}
				break;
			case 3:
				if (info_cargaActiva(arrayPassenger, LEN_PASSENGER) == 0)
				{
					if (!utn_getNumero(&auxiliarId,
							"\nIngrese ID del Pasajero:\n", "\nID invalido", 0,
							idPassenger, 2))
					{
						auxiliarIndice = findPassengerById(arrayPassenger,
						LEN_PASSENGER, auxiliarId);
						if (auxiliarIndice >= 0
								&& !removePassenger(arrayPassenger,
								LEN_PASSENGER, auxiliarIndice))
						{
							printf(
									"\nSe dio de baja de Pasajero %d correctamente\n",
									auxiliarIndice);
						}
					}
				}
				break;
			case 4:
				if (info_cargaActiva(arrayPassenger, LEN_PASSENGER) == 0)
				{
					do
					{
						if (!utn_getNumero(&opcion3,
								"\n1.Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero. "
										"\n2.Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio."
										"\n3.Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’"
										"\n4.Listado completo"
										"\n5.Salir\n",
								"\nError opcion invalida", 1, 5, 2))
						{
							switch (opcion3)
							{

							case 1:
								sortPassengers(arrayPassenger, LEN_PASSENGER,0);
								printPassengerByLastName(arrayPassenger,LEN_PASSENGER);
								break;
							case 2:
								info_totalPassege(arrayPassenger, LEN_PASSENGER);
								break;
							case 3:
								sortPassengersByCode(arrayPassenger, LEN_PASSENGER,1);
								printPassengerByCode(arrayPassenger,
										LEN_PASSENGER);
								break;
							case 4:
								printPassenger(arrayPassenger, LEN_PASSENGER);
								break;
							}
						}
					} while (opcion3 != 5);
				}

				break;

			}
		}

	} while (opcion != 5);

	return EXIT_SUCCESS;
}
