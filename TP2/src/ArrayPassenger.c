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


int initPassengers(Passenger* list, int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}
int printOnePassenger(Passenger* pElemento)
{
	int retorno=-1;
		if(pElemento != NULL && pElemento->isEmpty == 0)
		{
			retorno=0;
			printf("\nID: %d | Nombre: %s | Apellido: %s | Precio: %.2f | Tipo de Pasajero: %d | Estado de Vuelo: %d | Codigo de Vuelo: %s \n",pElemento->id,pElemento->name,pElemento->lastName,pElemento->price,pElemento->typePassenger,pElemento->statusFlight,pElemento->flycode);
		}
		return retorno;
}
int printPassenger(Passenger* list, int len)
{
	int retorno = -1;
			int i;
			if(list != NULL && len > 0)
			{
				retorno = 0;
				for(i=0;i<len;i++)
				{
					printOnePassenger(&list[i]);
				}
			}


		 return retorno;
}
int getEmptyIndex(Passenger* list, int len)
{
	int retorno = -1;
		int i;
		if(list != NULL && len > 0)
		{
			for(i=0;i<len;i++)
			{
				if(list[i].isEmpty == 1)
				{
					retorno = i;
					break;
				}
			}
		}
		return retorno;
}
int addPassenger(Passenger* list, int len, int* id, int indice)
{
	int retorno = -1;
	Passenger bufferPassenger;

	if(list != NULL && len > 0 && indice < len && indice >= 0 && id != NULL)
		{
			if(utn_getNombre(bufferPassenger.name,LEN_NOMBRE,"\nIngrese nombre\n","\nNo es valido",2)==0 &&
					utn_getNombre(bufferPassenger.lastName,LEN_NOMBRE,"\nIngrese apellido\n","\nNo es valido",2)==0 &&
					utn_getNumeroFlotante(&bufferPassenger.price,"\nIngrese precio\n","\nNo es valido",1,999999,2)==0 &&
					utn_getNombre(bufferPassenger.flycode,LEN_NOMBRE,"\nIngrese codigo\n","\nNo es valido",2)==0 &&
					utn_getNumero(&bufferPassenger.typePassenger,"\nIngrese tipo de pasajero(1-5)\n","\nNo es valido",1,5,2)==0 &&
					utn_getNumero(&bufferPassenger.statusFlight,"\nIngrese Estado de Vuelo(1-5)\n","\nNo es valido",0,1,2)==0)


			{
				retorno = 0;
							bufferPassenger.id= *id;
							bufferPassenger.isEmpty = 0;
							list[indice] = bufferPassenger;
							(*id)++;

			}

		}



	return retorno;
}
int findPassengerById(Passenger* list, int len,int id)
{
	int respuesta = -1;
		int i;
		if(list != NULL && len > 0 && id >= 0)
		{
			for(i=0;i<len;i++)
			{
				if(list[i].id == id && list[i].isEmpty==0)
				{
					respuesta = i;
					break;
				}
			}
		}
		return respuesta;
}
int changeName(Passenger* list, int len, int indice)
{
	int respuesta = -1;
	Passenger bufferPassenger;

		if(list != NULL && len > 0 && indice < len && indice >= 0 && list[indice].isEmpty == 0)
		{
			if(utn_getNombre(bufferPassenger.name,LEN_NOMBRE,"\nIngrese Nombre\n","\nERROR\n",2) == 0)
			{
				respuesta = 0;
				strncpy(bufferPassenger.lastName,list[indice].lastName,LEN_NOMBRE);
				strncpy(bufferPassenger.flycode,list[indice].flycode,LEN_CODE);
				bufferPassenger.price = list[indice].price;
				bufferPassenger.typePassenger = list[indice].typePassenger;
				bufferPassenger.id = list[indice].id;
				bufferPassenger.isEmpty = 0;
				list[indice] = bufferPassenger;
			}
		}
		return respuesta;
}
int info_cargaActiva(Passenger* list,int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}
