/*
 ============================================================================
 Name        : TP1C : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "calculadora.h"

int main(void) {
	setbuf(stdout, NULL);

	int option;
	float operando1;
	float operando2;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	float resultadoFactorial1;
	float resultadoFactorial2;
	int flag = 0;
	int flag1 = 0;

	do {
		option = menu();

		switch (option) {
		case 1:
			printf("\nIngrese el primer operando\n");
			scanf("%f", &operando1);
			flag = 1;
			break;

		case 2:
			printf("\nIngrese el segundo operando\n");
			scanf("%f", &operando2);
			flag1 = 1;
			break;

		case 3:
			if(flag == 1 && flag1 == 1)
			{
			resultadoSuma = suma(operando1, operando2); //llama a funcion suma, guarda lo devuelto por la funcion en la variable resultadoSuma
			resultadoResta = resta(operando1, operando2);
			resultadoDivision = division(operando1, operando2);
			resultadoMultiplicacion = multiplicacion(operando1, operando2);
			resultadoFactorial1 = factorial(operando1);
			resultadoFactorial2 = factorial(operando2);
			printf("\nOperaciones realizadas\n");
			}
			else
			{
				printf("\nUsted no informo numeros\n");
			}
			break;

		case 4:
			if(flag == 1 && flag1 == 1){

			printf("\nEl resultado de la suma %.2f + %.2f es: %.2f\n",
					operando1, operando2, resultadoSuma); //imprimo el resultado obtenido de la funcion suma
			printf("El resultado de la resta %.2f - %.2f es: %.2f\n", operando1,
					operando2, resultadoResta);
			if (resultadoDivision == 0) {
				printf("No es posible dvidir por cero\n");
			} else {
				printf("El resultado de la division %.2f / %.2f es: %.2f\n",
						operando1, operando2, resultadoDivision);
			}
			printf("El resultado de la multiplicacion %.2f * %.2f es: %.2f\n",
					operando1, operando2, resultadoMultiplicacion);
			printf("El resultado factorial de %.2f es: %.2f\n", operando1,
					resultadoFactorial1);
			printf("El resultado factorial de %.2f es: %.2f\n", operando2,
					resultadoFactorial2);
			}
			else
			{
				printf("\nUsted no informo numeros\n");
			}
			break;

		case 5:
			printf("\nSaliendo del programa...");
			break;

		default:
			printf("\nNo es una opcion correcta\n");
		}

	} while (option != 5);

	return EXIT_SUCCESS;
}
