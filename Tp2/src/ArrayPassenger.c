/*
 * ArrayPassenger.c
 *
 *  Created on: 9 may. 2022
 *      Author: Sampini
 */
#include "ArrayPassenger.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int initPassengers(Passenger *list, int len)
{
	int retorno = -1;
	int i;
	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int printOnePassenger(Passenger *pElemento)
{
	int retorno = -1;
	if (pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno = 0;
		printf(
				"\nID: %d | Nombre: %s | Apellido: %s | Precio: %.2f | Tipo de Pasajero: %d | Estado de Vuelo: %d | Codigo de Vuelo: %s \n",
				pElemento->id, pElemento->name, pElemento->lastName,
				pElemento->price, pElemento->typePassenger,
				pElemento->statusFlight, pElemento->flycode);
	}
	return retorno;
}
int printOnePassengerLastName(Passenger *pElemento)
{
	int retorno = -1;

	if (pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno = 0;
		printf("\n| Apellido: %s | Tipo de Pasajero: %d |\n",
				pElemento->lastName, pElemento->typePassenger);
	}
	return retorno;
}
int printOnePassengerCode(Passenger *pElemento)
{
	int retorno = -1;

	if (pElemento != NULL && pElemento->isEmpty == 0
			&& pElemento->statusFlight == 1)
	{
		retorno = 0;
		printf("\n| Codigo de Vuelo: %s | Estado de Vuelo: %d |\n",
				pElemento->flycode, pElemento->statusFlight);
	}
	return retorno;
}
int printPassenger(Passenger *list, int len)
{
	int retorno = -1;
	int i;
	if (list != NULL && len > 0)
	{
		retorno = 0;
		for (i = 0; i < len; i++)
		{
			printOnePassenger(&list[i]);
		}
	}

	return retorno;
}
int printPassengerByLastName(Passenger *list, int len)
{

	int retorno = -1;
	int i;
	if (list != NULL && len > 0)
	{
		retorno = 0;
		for (i = 0; i < len; i++)
		{
			printOnePassengerLastName(&list[i]);
		}
	}

	return retorno;
}
int printPassengerByCode(Passenger *list, int len)
{

	int retorno = -1;
	int i;
	if (list != NULL && len > 0)
	{
		retorno = 0;
		for (i = 0; i < len; i++)
		{
			printOnePassengerCode(&list[i]);
		}
	}

	return retorno;
}

int getEmptyIndex(Passenger *list, int len)
{
	int retorno = -1;
	int i;
	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int addPassenger(Passenger *list, int len, int *id, int indice)
{
	int retorno = -1;
	Passenger bufferPassenger;

	if (list != NULL && len > 0 && indice < len && indice >= 0 && id != NULL)
	{
		if (utn_getNombre(bufferPassenger.name, LEN_NOMBRE,
				"\nIngrese nombre\n", "\nNo es valido", 2) == 0
				&& utn_getNombre(bufferPassenger.lastName, LEN_NOMBRE,
						"\nIngrese apellido\n", "\nNo es valido", 2) == 0
				&& utn_getNumeroFlotante(&bufferPassenger.price,
						"\nIngrese precio\n", "\nNo es valido", 1, 999999, 2)
						== 0
				&& utn_getNombre(bufferPassenger.flycode, LEN_NOMBRE,
						"\nIngrese codigo\n", "\nNo es valido", 2) == 0
				&& utn_getNumero(&bufferPassenger.typePassenger,
						"\nIngrese tipo de pasajero(1-5)\n", "\nNo es valido",
						1, 5, 2) == 0
				&& utn_getNumero(&bufferPassenger.statusFlight,
						"\nIngrese Estado de Vuelo(0-1)\n", "\nNo es valido", 0,
						1, 2) == 0)

		{
			retorno = 0;
			bufferPassenger.id = *id;
			bufferPassenger.isEmpty = 0;
			list[indice] = bufferPassenger;
			(*id)++;

		}

	}

	return retorno;
}

int findPassengerById(Passenger *list, int len, int id)
{
	int respuesta = -1;
	int i;
	if (list != NULL && len > 0 && id >= 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].id == id && list[i].isEmpty == 0)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

int changeName(Passenger *list, int len, int indice)
{
	int respuesta = -1;
	Passenger bufferPassenger;

	if (list != NULL && len > 0 && indice < len && indice >= 0
			&& list[indice].isEmpty == 0)
	{
		if (utn_getNombre(bufferPassenger.name, LEN_NOMBRE,
				"\nIngrese Nombre\n", "\nERROR\n", 2) == 0)
		{
			respuesta = 0;
			strncpy(bufferPassenger.lastName, list[indice].lastName,
			LEN_NOMBRE);
			strncpy(bufferPassenger.flycode, list[indice].flycode, LEN_CODE);
			bufferPassenger.price = list[indice].price;
			bufferPassenger.typePassenger = list[indice].typePassenger;
			bufferPassenger.id = list[indice].id;
			bufferPassenger.isEmpty = 0;
			list[indice] = bufferPassenger;
		}
	}
	return respuesta;
}
int changeLastName(Passenger *list, int len, int indice)
{
	int respuesta = -1;
	Passenger bufferPassenger;

	if (list != NULL && len > 0 && indice < len && indice >= 0
			&& list[indice].isEmpty == 0)
	{
		if (utn_getNombre(bufferPassenger.lastName, LEN_NOMBRE,
				"\nIngrese Apellido\n", "\nERROR\n", 2) == 0)
		{
			respuesta = 0;
			strncpy(bufferPassenger.name, list[indice].name, LEN_NOMBRE);
			strncpy(bufferPassenger.flycode, list[indice].flycode, LEN_CODE);
			bufferPassenger.price = list[indice].price;
			bufferPassenger.typePassenger = list[indice].typePassenger;
			bufferPassenger.id = list[indice].id;
			bufferPassenger.isEmpty = 0;
			list[indice] = bufferPassenger;
		}
	}
	return respuesta;
}
int changePrice(Passenger *list, int len, int indice)
{
	int respuesta = -1;
	Passenger bufferPassenger;

	if (list != NULL && len > 0 && indice < len && indice >= 0
			&& list[indice].isEmpty == 0)
	{
		if (utn_getNumeroFlotante(&bufferPassenger.price, "\nIngrese precio\n",
				"\nNo es valido", 1, 999999, 2) == 0)
		{
			respuesta = 0;
			strncpy(bufferPassenger.name, list[indice].name, LEN_NOMBRE);
			strncpy(bufferPassenger.lastName, list[indice].lastName,
			LEN_NOMBRE);
			strncpy(bufferPassenger.flycode, list[indice].flycode, LEN_CODE);
			bufferPassenger.typePassenger = list[indice].typePassenger;
			bufferPassenger.id = list[indice].id;
			bufferPassenger.isEmpty = 0;
			list[indice] = bufferPassenger;
		}
	}
	return respuesta;
}
int changeType(Passenger *list, int len, int indice)
{
	int respuesta = -1;
	Passenger bufferPassenger;

	if (list != NULL && len > 0 && indice < len && indice >= 0
			&& list[indice].isEmpty == 0)
	{
		if (utn_getNumero(&bufferPassenger.typePassenger,
				"\nIngrese tipo de pasajero(1-5)\n", "\nNo es valido", 1, 5, 2)
				== 0)
		{
			respuesta = 0;
			strncpy(bufferPassenger.name, list[indice].name, LEN_NOMBRE);
			strncpy(bufferPassenger.lastName, list[indice].lastName,
			LEN_NOMBRE);
			strncpy(bufferPassenger.flycode, list[indice].flycode, LEN_CODE);
			bufferPassenger.price = list[indice].price;
			bufferPassenger.id = list[indice].id;
			bufferPassenger.isEmpty = 0;
			list[indice] = bufferPassenger;
		}
	}
	return respuesta;
}
int changeCode(Passenger *list, int len, int indice)
{
	int respuesta = -1;
	Passenger bufferPassenger;

	if (list != NULL && len > 0 && indice < len && indice >= 0
			&& list[indice].isEmpty == 0)
	{
		if (utn_getNombre(bufferPassenger.flycode, LEN_NOMBRE,
				"\nIngrese codigo\n", "\nNo es valido", 2) == 0)
		{
			respuesta = 0;
			strncpy(bufferPassenger.name, list[indice].name, LEN_NOMBRE);
			strncpy(bufferPassenger.lastName, list[indice].lastName,
			LEN_NOMBRE);
			bufferPassenger.price = list[indice].price;
			bufferPassenger.typePassenger = list[indice].typePassenger;
			bufferPassenger.id = list[indice].id;
			bufferPassenger.isEmpty = 0;
			list[indice] = bufferPassenger;
		}
	}
	return respuesta;
}
int removePassenger(Passenger *list, int len, int indice)
{
	int respuesta = -1;
	if (list != NULL && len > 0 && indice < len && indice >= 0
			&& list[indice].isEmpty == 0)
	{
		list[indice].isEmpty = 1;

		respuesta = 0;
	}
	return respuesta;
}
int sortPassengers(Passenger *list, int len, int order)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Passenger bufferPassenger;

	if (list != NULL && len > 0)
	{
		do
		{
			flagSwap = 0;
			for (i = 0; i < len - 1; i++)
			{
				if (list[i].isEmpty || list[i + 1].isEmpty)
				{
					continue;
				}
				if (strncmp(list[i].lastName, list[i + 1].lastName, LEN_NOMBRE)
						> order)
				{
					flagSwap = 1;
					bufferPassenger = list[i];
					list[i] = list[i + 1];
					list[i + 1] = bufferPassenger;
				}
			}
			len--;
		} while (flagSwap);
	}
	return respuesta;
}
int sortPassengersByCode(Passenger *list, int len, int order)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Passenger bufferPassenger;

	if (list != NULL && len > 0)
	{
		do
		{
			flagSwap = 0;
			for (i = 0; i < len - 1; i++)
			{
				if (list[i].isEmpty || list[i + 1].isEmpty)
				{
					continue;
				}
				if (strncmp(list[i].flycode, list[i + 1].flycode, LEN_CODE)
						> order)
				{
					flagSwap = 1;
					bufferPassenger = list[i];
					list[i] = list[i + 1];
					list[i + 1] = bufferPassenger;
				}
			}
			len--;
		} while (flagSwap);
	}
	return respuesta;
}
int info_totalPassege(Passenger *list, int len)
{
	int retorno = -1;
	int i;
	float auxiliarTotal = 0;
	int contador = 0;
	float auxiliarPromedio;
	int cantPromedios;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty)
			{
				continue;
			}
			else
			{
				auxiliarTotal = auxiliarTotal + list[i].price;
				contador++;
			}
		}
		retorno = 0;
		printf("\nTotal precio pasajes: %.2f", auxiliarTotal);
		auxiliarPromedio = auxiliarTotal / contador;
		printf("\nPromedio de los pasajes: %.2f", auxiliarPromedio);
		cantPromedios = info_countPassege(list, len, auxiliarPromedio);
		printf("\nPasajeros que superan el promedio: %d\n", cantPromedios);

	}
	return retorno;
}
int info_countPassege(Passenger *list, int len, float promedio)
{
	int retorno = -1;
	int i;
	int auxiliarCantPro = 0;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty)
			{
				continue;
			}
			if (list[i].price > promedio)
			{
				auxiliarCantPro++;
			}
		}

		retorno = auxiliarCantPro;
	}

	return retorno;
}
int info_cargaActiva(Passenger *list, int len)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == 0)
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}
int info_addForce(Passenger* list, int len, int indice, int* id, char* name, char* lastname, float price, char* flycode, int type, int status)
{
	int respuesta = -1;
		Passenger bufferPassenger;

		if(list != NULL && len > 0 && indice < len && indice >= 0 && id != NULL)
		{
				strncpy(bufferPassenger.name,name,LEN_NOMBRE);
				strncpy(bufferPassenger.lastName,lastname,LEN_NOMBRE);
				strncpy(bufferPassenger.flycode,flycode,LEN_CODE);
				bufferPassenger.price = price;
				bufferPassenger.typePassenger = type;
				bufferPassenger.statusFlight = status;
				bufferPassenger.id = *id;
				bufferPassenger.isEmpty = 0;
				list[indice] = bufferPassenger;
				(*id)++;
				respuesta = 0;
		}
		return respuesta;




}
