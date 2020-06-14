#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * Recibe los datos de una archivo de texto, los toma como char, usa fscanf para parsear los datos
 * Valida lo recibido en employee_newparametrosTxt, luego ll_add lo agrega a la lista de empleados
 * Retorna la cantidad de empleados leidos del archivo
 *
 *
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
        int retorno = -1;
		Employee* auxiliarEmpleado;
		char auxiliarId[1024];
		char auxiliarNombre[1024];
		char auxiliarHsTrabajadas[1024];
		char auxiliarSueldo[1024];
		int cantidadLeida = 0;


		if(pFile != NULL && pArrayListEmployee != NULL)
		{
			do
			 {
				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxiliarId,auxiliarNombre,auxiliarHsTrabajadas,auxiliarSueldo)== 4)
					{
				       auxiliarEmpleado = employee_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarHsTrabajadas,auxiliarSueldo);

					    if(auxiliarEmpleado != NULL)
					    {
							if(!ll_add(pArrayListEmployee,auxiliarEmpleado))
							{
								cantidadLeida++;
							}
		                 }
						else
						{
							break;
						}

					}
			  }while(!feof(pFile));
			retorno = cantidadLeida;

		  }
				return retorno;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * Recibe los datos de una archivo binario, los toma como char, usa fread para parsear los datos
 * Valida lo recibido en employee_newparametrosTxt, luego ll_add lo agrega a la lista de empleados
 * Retorna la cantidad de empleados leidos del archivo
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
	Employee* auxiliarEmpleado=NULL;
	char auxiliarId[1024];
	char auxiliarNombre[1024];
	char auxiliarHsTrabajadas[1024];
	char auxiliarSueldo[1024];
	int cantidadLeida = 0;


	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		 {
			auxiliarEmpleado=employee_new();
			if(fread(auxiliarEmpleado,sizeof(Employee),1,pFile)==1)
				{
				    if(auxiliarEmpleado != NULL)
				    {
				    	if(employee_getNombre(auxiliarEmpleado,auxiliarNombre) == 0 &&
				    		employee_getSueldoStr(auxiliarEmpleado,auxiliarSueldo) == 0 &&
							employee_getHorasTrabajadasStr(auxiliarEmpleado,auxiliarHsTrabajadas) == 0 &&
							employee_getIdStr(auxiliarEmpleado,auxiliarId) == 0)
						{
				    		auxiliarEmpleado= employee_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarHsTrabajadas,auxiliarSueldo);
				    		if(auxiliarEmpleado != NULL)
				    		 {
				    			if(!ll_add(pArrayListEmployee,auxiliarEmpleado))
				    			{
				    				cantidadLeida++;
				    			}
				    		 }
						}
	                }
					else
					{
						break;
					}

				}
		  }while(!feof(pFile));
          retorno = cantidadLeida;
	  }
			return retorno;
}
