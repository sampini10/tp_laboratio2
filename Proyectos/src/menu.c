/*
 * menu.c
 *
 *  Created on: 19 sep. 2021
 *      Author: Sampini
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu() {
	int auxOption;

	printf("\n---MENU---"
			"\n1-Ingresar primer operador(A)"
			"\n2-Ingresar segundo operador(B)"
			"\n3-Calcular todas las operaciones"
			"\n\ta) Calcular la suma (A+B)."
			"\n\tb) Calcular la resta (A-B)."
			"\n\tc) Calcular la division (A/B)."
			"\n\td) Calcular la multiplicacion (A*B)."
			"\n\te) Calcular el factorial (A!)."
			"\n4-Informar resultados"
			"\n5-Salir\n");

	scanf("%d", &auxOption);

	return auxOption;
}

