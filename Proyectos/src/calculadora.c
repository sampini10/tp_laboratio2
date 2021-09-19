/*
 * calculadora.c
 *
 *  Created on: 19 sep. 2021
 *      Author: Sampini
 */
#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

/*Funcion que realiza la suma de dos numeros, que devuelve el resultado de dicha suma */
float suma(float operando1, float operando2) {
	float auxResultado;
	return auxResultado = operando1 + operando2;
}
float resta(float operando1, float operando2) {
	float auxResultado;
	return auxResultado = operando1 - operando2;
}
/*Funcion que realiza la division de dos numeros, verificando que el divisor sea distinto de 0
 * Devuelvo el 0 como resultado para poder validar que no se pudo realizar la division y dar informe al usuario
 * Caso contrario, se devuelve el resultado de la division
 * */

float division(float operando1, float operando2) {
	float auxResultado;

	if (operando2 == 0) {
		auxResultado = 0;
	} else {
		auxResultado = operando1 / operando2;
	}

	return auxResultado;
}
float multiplicacion(float operando1, float operando2) {
	float auxResultado;
	return auxResultado = operando1 * operando2;
}
float factorial(float operando1) {
	float auxResultado;
	int auxNum;
	if (operando1 != 0) {
		auxNum = 1;
		for (int i = 1; i <= operando1; i++) {
			auxNum = auxNum * i;
			auxResultado = auxNum;
		}

	} else {
		auxResultado = 1;
	}

	return auxResultado;

}
