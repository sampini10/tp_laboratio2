/*
 * ArrayEmployees.c
 *
 *  Created on: 25 abr. 2020
 *      Author: sampini
 */

#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"



/* Inicio el array
 * ingresando un valor a isEmpty
 *
 */
int emp_initEmployees(Employee* array, int limite)
{
	int retorno = -1;
	int i;
	if(array !=NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}
/*
 * recorro el array para en cada posicion, verificar que hay un
 * empleado y asi imprimir su info.
 */
int emp_printEmployees(Employee* array, int limite)
{
	int retorno = -1;
		int i;
		if(array != NULL && limite > 0)
		{
			retorno = 0;
			for(i=0;i<limite;i++)
			{
				emp_imprimir(&array[i]);
			}
		}


	 return retorno;
}
/*
 * Funcion para agregar empleado, que solicito datos al user
 * y asigno automaticamente id
 */
int emp_addEmployee(Employee* array, int limite,int indice , int* id)
{
	int retorno = -1;
	Employee bufferEmpleado;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(utn_getNombre(bufferEmpleado.name,NAME_LEN,"\nIngrese nombre\n","\nNo es valido",2)==0 &&
				utn_getNombre(bufferEmpleado.lastName,LAST_LEN,"\nIngrese apellido\n","\nNo es valido",2)==0 &&
				utn_getNumeroFlotante(&bufferEmpleado.salary,"\nIngrese salario\n","\nNo es valido",1,999999,2)==0 &&
				utn_getNumero(&bufferEmpleado.sector,"\nIngrese sector(1-5)\n","\nNo es valido",1,5,2)==0)

		{
			retorno = 0;
						bufferEmpleado.id= *id;
						bufferEmpleado.isEmpty = 0;
						array[indice] = bufferEmpleado;
						(*id)++;

		}


	}



	return retorno;
}
/*
 * funcion que verifica que este cargado un cliente con isEmpty
 * y imprime sus datos
 */
int emp_imprimir(Employee* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d | Nombre: %s | Apellido: %s | Salario: %.2f | Sector: %d \n",pElemento->id,pElemento->name,pElemento->lastName,pElemento->salary,pElemento->sector);
	}
	return retorno;
}
/*
 * Funcion que recorre el array, buscando un lugar libre para guardar proximo empleado
 */
int emp_getEmptyIndex(Employee* array,int limite)
{
	int retorno = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/*
 * Recorre el array, buscando un Id que se ingreso. Verifica que haya sido cargado
 */
int emp_findEmployeeById(Employee* array, int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado && array[i].isEmpty==0)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}
/*
 * Funcion que modifica el nombre del empleado, guardando los datos anteriormente cargados
 */
int emp_modificarNombre(Employee* array,int limite, int indice)
{
	int respuesta = -1;
	Employee bufferEmpleado;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(utn_getNombre(bufferEmpleado.name,NAME_LEN,"\nIngrese Nombre\n","\nERROR\n",2) == 0)
		{
			respuesta = 0;
			strncpy(bufferEmpleado.lastName,array[indice].lastName,LAST_LEN);
			bufferEmpleado.salary = array[indice].salary;
			bufferEmpleado.sector = array[indice].sector;
			bufferEmpleado.id = array[indice].id;
			bufferEmpleado.isEmpty = 0;
			array[indice] = bufferEmpleado;
		}
	}
	return respuesta;
}
/*
 * Funcion que modifica el apellido del empleado, guardando los datos anteriormente cargados
 */
int emp_modificarApellido(Employee* array,int limite, int indice)
{
	int respuesta = -1;
	Employee bufferEmpleado;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(utn_getNombre(bufferEmpleado.lastName,LAST_LEN,"\nIngrese Apellido\n","\nERROR\n",2) == 0)
		{
			respuesta = 0;
			strncpy(bufferEmpleado.name,array[indice].name,NAME_LEN);
			bufferEmpleado.salary = array[indice].salary;
			bufferEmpleado.sector = array[indice].sector;
			bufferEmpleado.id = array[indice].id;
			bufferEmpleado.isEmpty = 0;
			array[indice] = bufferEmpleado;
		}
	}
	return respuesta;
}
/*Funcion que modifica el salario del empleado, guardando los datos anteriormente cargados
 *
 */
int emp_modificarSalario(Employee* array,int limite, int indice)
{
	int respuesta = -1;
	Employee bufferEmpleado;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(utn_getNumeroFlotante(&bufferEmpleado.salary,"\nIngrese salario","\nNo es valido",1,999999,2) == 0)
		{
			respuesta = 0;
			strncpy(bufferEmpleado.name,array[indice].name,NAME_LEN);
			strncpy(bufferEmpleado.lastName,array[indice].lastName,LAST_LEN);
			bufferEmpleado.sector = array[indice].sector;
			bufferEmpleado.id = array[indice].id;
			bufferEmpleado.isEmpty = 0;
			array[indice] = bufferEmpleado;
		}
	}
	return respuesta;
}
/*
 * Funcion que modifica el sector del empleado, guardando los datos anteriormente cargados
 */
int emp_modificarSector(Employee* array,int limite, int indice)
{
	int respuesta = -1;
	Employee bufferEmpleado;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(utn_getNumero(&bufferEmpleado.sector,"\nIngrese sector(1-5)","\nNo es valido",1,5,2) == 0)
		{
			respuesta = 0;
			strncpy(bufferEmpleado.name,array[indice].name,NAME_LEN);
			strncpy(bufferEmpleado.lastName,array[indice].lastName,LAST_LEN);
			bufferEmpleado.salary = array[indice].salary;
			bufferEmpleado.id = array[indice].id;
			bufferEmpleado.isEmpty = 0;
			array[indice] = bufferEmpleado;
		}
	}
	return respuesta;
}
/*
 * Funcion que recibe un indice, que modifica en dicho indice el dato isEmpty para dar de baja al empleado
 */
int emp_bajaArray(Employee* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;

		respuesta = 0;
	}
	return respuesta;
}
/*
 * Funcion que fuerza un alta de empleado para verificar funcionamiento
 * de las otras funciones, ingresando los datos en el main
 */
int emp_altaForzadaArray(Employee* array,int limite, int indice, int* id,char* nombre,char* apellido,float salario,int sector)

{
	int respuesta = -1;
	Employee bufferEmpleados;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
			strncpy(bufferEmpleados.name,nombre,NAME_LEN);
			strncpy(bufferEmpleados.lastName,apellido,LAST_LEN);
			bufferEmpleados.salary = salario;
			bufferEmpleados.sector = sector;
			respuesta = 0;
			bufferEmpleados.id = *id;
			bufferEmpleados.isEmpty = 0;
			array[indice] = bufferEmpleados;
			(*id)++;
	}
	return respuesta;
}
/*
 * Funcion que recorre el array de empleados, verificando que se haya ingresado
 * y compara los apellidos, ordenando alfabeticamente
 */
int emp_ordenarPorApellido(Employee* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Employee bufferEmpleados;

	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].lastName,array[i+1].lastName,LAST_LEN) > 0)
				{
					flagSwap = 1;
					bufferEmpleados = array[i];
					array[i] = array[i+1];
					array[i+1]=bufferEmpleados;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}
/*
 * Funcion que imprime despues de organizar alfabeticamente, el apellido y sector de cada empleado
 */
int emp_imprimirApellidoSector(Employee* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d | Apellido: %s | Sector: %d \n",pElemento->id,pElemento->lastName,pElemento->sector);
	}
	return retorno;
}
/*
 * Funcion que recorre el array, llamando a funcion que imprimi cada empleado con su apellido y sector
 */
int emp_printEmployeesApellidos(Employee* array, int limite)
{
	int retorno = -1;
		int i;
		if(array != NULL && limite > 0)
		{
			retorno = 0;
			for(i=0;i<limite;i++)
			{
				emp_imprimirApellidoSector(&array[i]);
			}
		}


	 return retorno;
}
/*
 * Recorre el array, verificando que se haya ingresado datos, cuando valida, suma todos los sueldos de los empleados
 * generando un total de sueldos, luego sacando un porcentaje y llamando a otra funcion que indica la cantidad de empleados
 * con sueldo mayor al promedio
 */
int info_totalSueldos(Employee* array,int limite)
{
	int retorno = -1;
	int i;
	float auxiliarSueldoTotal = 0;
	int contador = 0;
	float auxiliarPromedio;
	int cantSueldosPromedios;


	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty)
			{
				continue;
			}
			else
				{
				auxiliarSueldoTotal = auxiliarSueldoTotal + array[i].salary;
				contador++;
				}
		}
		retorno = 0;
		printf("\nTotal de salarios: %.2f",auxiliarSueldoTotal);
		auxiliarPromedio = auxiliarSueldoTotal/contador;
		printf("\nPromedio de salarios: %.2f",auxiliarPromedio);
		cantSueldosPromedios = info_sueldosPromedios(array,limite,auxiliarPromedio);
		printf("\nEmpleados con mayor sueldo al promedio: %d\n",cantSueldosPromedios);

	}
	return retorno;
}
/*
 * Recorre el array, verificando que este ingresado datos cargados, comparando que el salario en la posicion de i en el array sea
 * mayor al sueldo promedio, cuando sea mayor, se incrementa el contador
 */
int info_sueldosPromedios(Employee* array,int limite,float promedio)
{
	int retorno = -1;
	int i;
	int auxiliarCantPro = 0;

	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty)
			{
				continue;
			}
			if(array[i].salary > promedio)
			{
				auxiliarCantPro++;
			}
		}

		retorno = auxiliarCantPro;
	}




		return retorno;
}
/*
 * funcion que verifica que el array tenga algun dato valido de empleado
 * verificando el isEmpty
 *
 */
int info_cargaActiva(Employee* array,int limite)
{
	int retorno = -1;
	int i;

	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 0)
			{
				retorno = 0;
			}
		}


	}

	return retorno;
}
