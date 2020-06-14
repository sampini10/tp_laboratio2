#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "Controller.h"

static int esNumerica(char* cadena, int limite);
static int isValidNombre(char* cadena,int longitud);

/*
 * Crea un lugar en memoria para un Empleado
 * Devolviendo el puntero a ese empleado
 */
Employee* employee_new(void)
{
	Employee* auxiliarEmpleado = NULL;
	auxiliarEmpleado = (Employee*) malloc(sizeof(Employee));
	return auxiliarEmpleado;
}
/*
 * Recibe un puntero de employee_new
 * Valida con los set los datos del empleado que recibio
 * Si estan bien, devuelve el puntero del empleado
 * Si no valida los datos, elimina el espacio de memoria reservado con employee_delete y el puntero recibido por employee_new
 */
Employee* employee_newParametros(int id,char* nombreStr,int horasTrabajadas,int sueldo)
{
	Employee* punteroEmpleado = NULL;
		punteroEmpleado = employee_new();
		int flag = 0;
		if(punteroEmpleado != NULL)
		{
			if(employee_setId(punteroEmpleado,id) == 0 &&
					employee_setNombre(punteroEmpleado,nombreStr) == 0 &&
					employee_setHorasTrabajadas(punteroEmpleado,horasTrabajadas) == 0 &&
					employee_setSueldo(punteroEmpleado,sueldo)== 0)
			{
				flag = 1;
			}

			if(flag == 0)
			{
				employee_delete(punteroEmpleado);
				punteroEmpleado=NULL;
			}
		}
		return punteroEmpleado;

}
/*
 * Recibe un puntero de employee_new
 * Valida con los set(texto) los datos del empleado que recibio (los obtiene como char* por el archivo de texto)
 * Si estan bien, devuelve el puntero del empleado
 * Si no valida los datos, elimina el espacio de memoria reservado con employee_delete y el puntero recibido por employee_new
 *
 *
 *
 */
Employee* employee_newParametrosTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* punteroEmpleado = NULL;
	punteroEmpleado = employee_new();
	int flag = 0;
	if(punteroEmpleado != NULL)
	{
		if(employee_setIdStr(punteroEmpleado,idStr) == 0 &&
				employee_setNombre(punteroEmpleado,nombreStr) == 0 &&
				employee_setHorasTrabajadasStr(punteroEmpleado,horasTrabajadasStr) == 0 &&
				employee_setSueldoStr(punteroEmpleado,sueldoStr)== 0)
		{
			flag = 1;
		}

		if(flag == 0)
		{
			employee_delete(punteroEmpleado);
			punteroEmpleado=NULL;
		}
	}
	return punteroEmpleado;

}
/*
 * Funcion que recibe el puntero de un empleado
 * Se hace un free, liberando el espacio de memorio que se genero para el
 */
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
	  free(this);

	}
}
/*
 * Funcion que recibe un puntero de empleado
 * Imprime los datos de cada campo del empleado
 *
 */
int employee_imprimir(Employee* this)
{
	int retorno = -1;
    char auxiliarId[2048];
	char auxiliarNombre[2048];
	char auxiliarHsTrabajadas[2048];
	char auxiliarSueldo[2048];

	if(this != NULL)
	{
		employee_getHorasTrabajadasStr(this,auxiliarHsTrabajadas);
		employee_getIdStr(this,auxiliarId);
		employee_getNombre(this,auxiliarNombre);
		employee_getSueldoStr(this,auxiliarSueldo);
		printf("ID: %s | Nombre: %s | Sueldo: %s | Hs.Trabajadas: %s\n",auxiliarId,auxiliarNombre,auxiliarSueldo,auxiliarHsTrabajadas);
		retorno = 0;
	}


	return retorno;
}


/**
 ****SETS Y GETS***
 ***/
int employee_setId(Employee* this,int id)
{
	int retorno = -1;
    if(this != NULL && id >= 0)
		{
			retorno = 0;
			this->id = id;
		}
		return retorno;
}
int employee_setIdStr(Employee* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,10))
		{
			retorno = 0;
			this->id = atoi(id);
		}
	}
return retorno;
}
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}
int employee_getIdStr(Employee* this,char* id)
{
	int retorno = -1;
    if(this != NULL && id != NULL)
	{
		retorno = 0;
		sprintf(id,"%d",this->id);
	}
		return retorno;
}
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
    if(this != NULL && nombre != NULL)
		{
		 if(isValidNombre(nombre,NOMBRE_LEN))
			{
			  retorno = 0;
			  strncpy(this->nombre,nombre,NOMBRE_LEN);
			}
		}
		return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,NOMBRE_LEN);
	}
	return retorno;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
   int retorno = -1;
   if(this != NULL && horasTrabajadas >= 0)
   		{
   			retorno = 0;
   			this->horasTrabajadas = horasTrabajadas;
   		}
   		return retorno;
}
int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		if(esNumerica(horasTrabajadas,10))
	        {
	         	retorno = 0;
	   			this->horasTrabajadas = atoi(horasTrabajadas);
	   		}
	}
	   return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas >= 0)
	{
	      retorno = 0;
		  *horasTrabajadas = this->horasTrabajadas;
	}
	return retorno;
}
int employee_getHorasTrabajadasStr(Employee* this,char* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
	  retorno = 0;
	  sprintf(horasTrabajadas,"%d",this->horasTrabajadas);
	}
		   return retorno;
}
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo >= 0)
	   {
	   	 retorno = 0;
	   	 this->sueldo = sueldo;
	   }
	return retorno;
}
int employee_setSueldoStr(Employee* this,char* sueldo)
{
    int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		if(esNumerica(sueldo,10))
	        {
	         	retorno = 0;
	   			this->sueldo = atoi(sueldo);
	   		}
	}
	   return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo >= 0)
		{
		  retorno = 0;
	     *sueldo = this->sueldo;
		}
		return retorno;
}
int employee_getSueldoStr(Employee* this,char* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
		{
		  retorno = 0;
		  sprintf(sueldo,"%d",this->sueldo);
		}
		return retorno;
}

/****
*****STATIC****
***/
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1;
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}

		}

	}
	return retorno;
}
static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '-' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/*
 * Funcion criterio de  ll_sort
 * Recibe del sort dos punteros a empleados
 * Y en el campo sueldo los compara, devolviendo 0,1,-1
 * Cada valor que devuelve a sort, le indica cual es mayor, menor o si son iguales
 *
 */
int employee_ordenarSueldo(void* pElemento,void* pElemento2)
{
	int retorno = -2;
	Employee* auxiliarEmpleado;
	Employee* auxiliarEmpleado2;
	int auxiliarSueldo;
	int auxiliarSueldo2;

	if(pElemento != NULL && pElemento2 != NULL)
	{
		auxiliarEmpleado = (Employee*)pElemento;
		auxiliarEmpleado2 = (Employee*)pElemento2;
		if(auxiliarEmpleado != NULL && auxiliarEmpleado2 != NULL)
		{
		  if(!employee_getSueldo(auxiliarEmpleado,&auxiliarSueldo) &&
				  !employee_getSueldo(auxiliarEmpleado2,&auxiliarSueldo2))
		  {
			  if(auxiliarSueldo > auxiliarSueldo2)
			  {
				  retorno = 1;
			  }
			  if(auxiliarSueldo < auxiliarSueldo2)
			  {
				  retorno = -1;
			  }
			  if(auxiliarSueldo == auxiliarSueldo2)
			  {
				  retorno = 0;
			  }

		  }

		}
	}


	return retorno;
}



