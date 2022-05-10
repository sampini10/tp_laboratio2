/*
 * ArrayPassenger.h
 *
 *  Created on: 9 may. 2022
 *      Author: Sampini
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#define LEN_NOMBRE 51
#define LEN_CODE 10

typedef struct
{
	int id;
	char name[LEN_NOMBRE];
	char lastName[LEN_NOMBRE];
	float price;
	char flycode[LEN_CODE];
	int typePassenger;
	int statusFlight;
	int isEmpty;

}Passenger;

int initPassengers(Passenger* list, int len);
int printPassenger(Passenger* list, int len);
int printOnePassenger(Passenger* pElemento);
int getEmptyIndex(Passenger* list, int len);
int addPassenger(Passenger* list, int len, int* id, int indice);
int findPassengerById(Passenger* list, int len,int id);
int changeName(Passenger* list, int len, int indice);
int info_cargaActiva(Passenger* list,int len);


#endif /* ARRAYPASSENGER_H_ */
