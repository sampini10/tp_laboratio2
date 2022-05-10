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
int removePassenger(Passenger* list, int len, int indice);
int findPassengerById(Passenger* list, int len,int id);
int changeName(Passenger* list, int len, int indice);
int changeLastName(Passenger* list, int len, int indice);
int changePrice(Passenger* list, int len, int indice);
int changeType(Passenger* list, int len, int indice);
int changeCode(Passenger* list, int len, int indice);
int sortPassengers(Passenger* list, int len, int order);
int sortPassengersByCode(Passenger *list, int len, int order);
int printPassengerByLastName(Passenger* list, int len);
int printOnePassengerLastName(Passenger *pElemento);
int printPassengerByCode(Passenger* list, int len);
int printOnePassengerCode(Passenger *pElemento);
int info_totalPassege(Passenger* list, int len);
int info_countPassege(Passenger *list, int len, float promedio);
int info_cargaActiva(Passenger* list,int len);
int info_addForce(Passenger* list, int len, int indice, int* id, char* name, char* lastname, float price, char* flycode, int type, int status);

#endif /* ARRAYPASSENGER_H_ */
