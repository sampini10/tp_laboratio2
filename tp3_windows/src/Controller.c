#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

#define NOMBRE_LEN 100
static int controller_buscarIdMaximo(LinkedList* pArrayListEmployee, int* id);
/*
 * Funcion que recibe el archivo y lo lee en modo texto
 * Llama a funcion parser texto
 * Imprimiendo la cantidad cargada
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;
	int cantidadCargada = 0;

	    if(path != NULL && pArrayListEmployee != NULL)
	    {
	    	pFile = fopen(path,"r");
	    	if(pFile != NULL && !parser_EmployeeFromText(pFile,pArrayListEmployee))
					{
						printf("\nArchivo cargado exitosamente\n");
						cantidadCargada = parser_EmployeeFromText(pFile, pArrayListEmployee);
						printf("Cargados %d \n", cantidadCargada);
						retorno = 0;

					}
					else
					{
					printf("El archivo no puede abrirse\n");
					}

	    	}
	    fclose(pFile);


	    return retorno;
}

/*
 * Funcion que recibe el archivo y lo lee en modo binario
 * Llama a funcion parser binario
 * Imprimiendo la cantidad cargada
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;
	int cantidadCargada = 0;

	    if(path != NULL && pArrayListEmployee != NULL)
	    {
	    	pFile = fopen(path,"rb");
	    	if(pFile != NULL)
	    	{
	    		cantidadCargada = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
	    		printf("\nArchivo cargado exitosamente\n");
				printf("Cargados %d \n", cantidadCargada);
				retorno = 0;

	    	}
	    	else
	    	{
	    		printf("El archivo no puede abrirse\n");
	    	}
	    fclose(pFile);
	    }

	    return retorno;
}
/*
 * Funcion para agregar un empleado, solicito los datos del mismo
 * Valido que sean correctos, llamando a employee_newparametros
 * y ll_add
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* auxiliarEmpleado;
    char auxiliarNombre[NOMBRE_LEN];
    int auxiliarSueldo;
    int auxiliarHsTrabajas;
    int auxiliarId;

    if(pArrayListEmployee != NULL)
    {
    	if(utn_getNombre(auxiliarNombre,NOMBRE_LEN,"\nIngrese nombre del empleado \n","\nNombre invalido",2)==0 &&
    			 utn_getNumero(&auxiliarSueldo,"\nIngrese sueldo del empleado: \n","\nSueldo invalido \n",1,99999,2)==0 &&
				 utn_getNumero(&auxiliarHsTrabajas,"\nIngrese horas trabajadas del empleado: \n","\nHoras invalidas \n",0,1000,2)==0 &&
				 controller_buscarIdMaximo(pArrayListEmployee,&auxiliarId)== 0)
    	   {
			   auxiliarId = auxiliarId + 1;
			   auxiliarEmpleado = employee_newParametros(auxiliarId,auxiliarNombre,auxiliarHsTrabajas,auxiliarSueldo);
             if(auxiliarEmpleado != NULL)
            {
        	   if(!ll_add(pArrayListEmployee,auxiliarEmpleado))
        	   {
        		   printf("\nCarga de empleado correcta\n");
        	   }
            }

    	  }
    	else
		   {
			   printf("\nCarga de empleado incorrecta\n");
		   }
    }

        return retorno;
}

/*
 * Funcion para editar un empleado, busco por id
 * Recorro la lista de empleados comparando el Id
 * Solicito los datos nuevos y los validos
 * Modifico el empleado
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxiliarEmpleado;
	char auxiliarNombre[NOMBRE_LEN];
	int auxiliarSueldo;
	int auxiliarHsTrabajas;
	int auxiliarId;
	int i;

	if(pArrayListEmployee != NULL)
	{
		if(!utn_getNumero(&auxiliarId,"\nIngrese ID de empleado a modificar: \n","\nId invalido",0,100000,2))
		{
		   for (i=0;i<ll_len(pArrayListEmployee);i++)
		   {
			   auxiliarEmpleado = ll_get(pArrayListEmployee,i);

			   if(auxiliarEmpleado != NULL && auxiliarEmpleado->id == auxiliarId)
			   {
				   if(utn_getNombre(auxiliarNombre,NOMBRE_LEN,"\nIngrese nombre del empleado \n","\nNombre invalido",2)==0 &&
    			 utn_getNumero(&auxiliarSueldo,"\nIngrese sueldo del empleado: \n","\nSueldo invalido \n",1,99999,2)==0 &&
				 utn_getNumero(&auxiliarHsTrabajas,"\nIngrese horas trabajadas del empleado: \n","\nHoras invalidas \n",0,1000,2)==0)
				   {
					   retorno = 0;
					   employee_setNombre(auxiliarEmpleado,auxiliarNombre);
					   employee_setSueldo(auxiliarEmpleado,auxiliarSueldo);
					   employee_setHorasTrabajadas(auxiliarEmpleado,auxiliarHsTrabajas);
					   printf("\nModificacion realizada.\n");
				       break;
				   }
				   else
					   printf("\nNo se pudo realizar modificacion\n");
				       break;
			   }
		   }
		}
	}

    return retorno;
}

/*
 * Funcion que pide ID de empleado a eliminar
 * Recorro la lista buscando el ID
 * Elimino el empleado con el Free de employee_delete
 * LL_Remove elimina de la lista de empleados
 *
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxiliarEmpleado;
	int auxiliarId;
	int i;

	if(pArrayListEmployee != NULL)
	{
		if(!utn_getNumero(&auxiliarId,"\nIngrese ID de empleado a eliminar: \n","\nId invalido",0,100000,2))
		{
			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				auxiliarEmpleado = ll_get(pArrayListEmployee,i);
			 if(auxiliarEmpleado != NULL && auxiliarEmpleado->id == auxiliarId)
			 {
				 ll_remove(pArrayListEmployee,i);
				 employee_delete(auxiliarEmpleado);
				 retorno = 0;
				 printf("\nEmpleado eliminado\n");
				 break;
			 }

			}
		}

	}
    return retorno;
}

/*
 *Funcion que recorre la lista de empleados
 *Luego imprime los datos del empleado con employee_imprimir
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxiliarEmpleado;
	int i;

	if(pArrayListEmployee != NULL)
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxiliarEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
			employee_imprimir(auxiliarEmpleado);
		}
	}

    return retorno;
}

/*
 * Funcion para ordenar a los empleados en la lista por sueldo
 * Llama a ll_sort que utiliza la funcion criterio de Employee_ordenar sueldo
 * y con un orden de 1 los ordena en forma creciente
 *
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int ordenar = 1;

	if(pArrayListEmployee != NULL)
	{
      if(!ll_sort(pArrayListEmployee,employee_ordenarSueldo,ordenar))
      {
    	  retorno = 0;
    	  printf("\nEmpleados ordenados por sueldo\n");

      }

	}

    return retorno;
}

/*
 *Funcion para guardar en archivo de texto
 *Recorre la lista de empleados
 *Copia en el archivo empleado por empleado
 *Imprime contador con la cantidad copiada
 *
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxiliarEmpleado;
	FILE* pFile;
	int i;
	int auxiliarId;
	char auxiliarNombre[NOMBRE_LEN];
	int auxiliarHsTrabajadas;
	int auxiliarSueldo;
	int contador = 0;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				auxiliarEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
				if(auxiliarEmpleado != NULL)
				{
					if(!employee_getNombre(auxiliarEmpleado,auxiliarNombre) &&
							!employee_getId(auxiliarEmpleado,&auxiliarId) &&
								!employee_getHorasTrabajadas(auxiliarEmpleado,&auxiliarHsTrabajadas) &&
									!employee_getSueldo(auxiliarEmpleado,&auxiliarSueldo))
					{
						fprintf(pFile,"%d,%s,%d,%d\n",auxiliarId,auxiliarNombre,auxiliarHsTrabajadas,auxiliarSueldo);
						contador++;
					}
				}
			}
			printf("Se guardo correctamente archivo Texto con  %d empleados \n",contador);
		}

	}
	else
	{
		printf("No se pudo guardar archivo \n");
	}

	fclose(pFile);
    return retorno;
}

/**
 * Funcion para guardar en archivo binario
 *Recorre la lista de empleados
 *Copia en el archivo empleado por empleado
 *Imprime contador con la cantidad copiada
 *
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pFile;
	Employee* auxiliarEmpleado;
	int i;
	int contador = 0;

	if(path != NULL && pArrayListEmployee != NULL)
	{

		pFile=fopen(path,"wb");

	if(pFile!= NULL)
		{

			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				auxiliarEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
				fwrite(auxiliarEmpleado,sizeof(Employee),1,pFile);
				contador++;
			}
			printf("Se guardo correctamente archivo Binario con %d empleados \n",contador);
		}
		else
		{
			printf("No se pudo guardar archivo \n");
		}

	}fclose(pFile);

	    return retorno;
}
/*
 * Funcion que busca un Idmaximo de la lista
 * Para asignarlo en la creacion de un nuevo empleado
 * Recorre la lista, buscando el idMaximo
 *
 *
 */
int controller_buscarIdMaximo(LinkedList* pArrayListEmployee, int* id)
{
    int retorno = -1;
    Employee* auxiliarEmpleado;
    int auxiliarIdMaximo = 0;
    int i;

    if(pArrayListEmployee != NULL)
    	{
    	for(i=0;i<ll_len(pArrayListEmployee);i++)
    			{
    				auxiliarEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
    				if(auxiliarEmpleado != NULL && auxiliarEmpleado->id > auxiliarIdMaximo)
    				{
    					auxiliarIdMaximo = auxiliarEmpleado->id;
    					retorno = 0;
    				}

    		     }
    	           *id = auxiliarIdMaximo;
    	            retorno = 0;
    	}

  return retorno;
}
