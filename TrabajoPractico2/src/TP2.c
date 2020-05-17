/*
 ============================================================================
 Name        : TP2.c
 Author      : Sampini
 Enunciado: Enunciado
Una empresa requiere un sistema para administrar su nómina de empleados. Se sabe que
dicha nómina bajo ninguna circunstancia superara los 1000 empleados.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn.h"
#include <string.h>

#define QTY_EMPLOYEES 1000





int main(void) {
	setbuf(stdout,NULL);

	Employee arrayEmployees[QTY_EMPLOYEES];

	int idEmpleado = 0;
	int auxiliarIndice;
	int auxiliarId;
	int opcion;
	int opcion2;
	int opcion3;

    emp_initEmployees(arrayEmployees,QTY_EMPLOYEES);
   /*if (emp_initEmployees(arrayEmployees,QTY_EMPLOYEES)==0)
   {
	   printf("Array inicializado correctamente. \n");
   }*/
   emp_altaForzadaArray(arrayEmployees,QTY_EMPLOYEES,0,&idEmpleado,"nicolas","sampini",20,1);//Cargas forzadas
   emp_altaForzadaArray(arrayEmployees,QTY_EMPLOYEES,1,&idEmpleado,"julio","gonzalez",30,2);
   emp_altaForzadaArray(arrayEmployees,QTY_EMPLOYEES,2,&idEmpleado,"martin","garcia",50,3);
   emp_altaForzadaArray(arrayEmployees,QTY_EMPLOYEES,3,&idEmpleado,"gerardo","rodriguez",20,2);
   emp_altaForzadaArray(arrayEmployees,QTY_EMPLOYEES,4,&idEmpleado,"roberto","tojo",10,5);
   emp_altaForzadaArray(arrayEmployees,QTY_EMPLOYEES,5,&idEmpleado,"ramiro","falcon",30,4);
   emp_altaForzadaArray(arrayEmployees,QTY_EMPLOYEES,6,&idEmpleado,"german","perez",50,3);
   emp_altaForzadaArray(arrayEmployees,QTY_EMPLOYEES,7,&idEmpleado,"pablo","abidal",50,2);


   do
   {
	   if(!utn_getNumero(&opcion,
	   							"\n1.Alta de empleado"
	   							"\n2.Modificar empleado"
	   							"\n3.Baja de empleado"
	   							"\n4.Informes"
	   							"\n5.Salir\n",
	   					        "\nError opcion invalida",1,5,2) )
	   {
		   switch(opcion)
		   {
		   /*
		    * Agregar empleado, primero busca lugar vacio donde ingresar y luego pide datos.
		    */
		   case 1:
			   auxiliarIndice = emp_getEmptyIndex(arrayEmployees,QTY_EMPLOYEES);
			   	if(auxiliarIndice >= 0)
			   {

			   	if(emp_addEmployee(arrayEmployees,QTY_EMPLOYEES,auxiliarIndice,&idEmpleado)==0)
			          {
				        printf("\nCarga realizada con exito\n");
			           }
			   	}
		   break;
          /*
           * Verifica que haya cargado con anterioridad un empleado, si cargo entra a un switch donde elegir que modificar de un empleado
           */
		   case 2:
			   if(info_cargaActiva(arrayEmployees,QTY_EMPLOYEES)==0)
			   {
			   do{
			   	  if(!utn_getNumero(&opcion2,"\nSeleccione que desea modificar:"
								  			    "\n1.Nombre"
								  			     "\n2.Apellido"
								  			      "\n3.Salario"
								  			       "\n4.Sector"
								  			        "\n5.Salir al menu\n",
								  			   	     "\nError opcion invalida",1,5,2))
			   						{switch(opcion2)

			   						  {
			   						    case 1:
			   				           	emp_printEmployees(arrayEmployees,QTY_EMPLOYEES);
			   						     if(!utn_getNumero(&auxiliarId,"\nIngrese ID empleado:\n","\nID invalido",0,idEmpleado,2))
			   						      {
			   							    auxiliarIndice = emp_findEmployeeById(arrayEmployees,QTY_EMPLOYEES,auxiliarId);
			   						      if(auxiliarIndice >= 0 &&
			   								  !emp_modificarNombre(arrayEmployees,QTY_EMPLOYEES,auxiliarIndice))
			   						        {
			   							      printf("\nSe modifico nombre de empleado %d correctamente\n",auxiliarIndice);
			   						        }
			   						      }
			   						      break;
			   						    case 2:
			   						    	emp_printEmployees(arrayEmployees,QTY_EMPLOYEES);
			   						    	 if(!utn_getNumero(&auxiliarId,"\nIngrese ID empleado:\n","\nID invalido",0,idEmpleado,2))
			   						    	 {
			   						    	   auxiliarIndice = emp_findEmployeeById(arrayEmployees,QTY_EMPLOYEES,auxiliarId);
			   						    	   if(auxiliarIndice >= 0 &&
			   						    	       !emp_modificarApellido(arrayEmployees,QTY_EMPLOYEES,auxiliarIndice))
			   						    	     {
			   						    	       printf("\nSe modifico apellido de empleado %d correctamente\n",auxiliarIndice);
			   						              }
			   						         }
                                          break;
			   						    case 3:
			   						    	emp_printEmployees(arrayEmployees,QTY_EMPLOYEES);
			   						    	 if(!utn_getNumero(&auxiliarId,"\nIngrese ID empleado:\n","\nID invalido",0,idEmpleado,2))
			   						    	  {
			   						    			 auxiliarIndice = emp_findEmployeeById(arrayEmployees,QTY_EMPLOYEES,auxiliarId);
			   						    			  if(auxiliarIndice >= 0 &&
			   						    				   !emp_modificarSalario(arrayEmployees,QTY_EMPLOYEES,auxiliarIndice))
			   						    			   {
			   						    			   printf("\nSe modifico saladio de empleado %d correctamente\n",auxiliarIndice);
			   						    			   }
			   						    	   }
			   						    	 break;
			   						    case 4:
			   						    	emp_printEmployees(arrayEmployees,QTY_EMPLOYEES);
			   						    		if(!utn_getNumero(&auxiliarId,"\nIngrese ID empleado:\n","\nID invalido",0,idEmpleado,2))
			   						    			{
			   						    			   auxiliarIndice = emp_findEmployeeById(arrayEmployees,QTY_EMPLOYEES,auxiliarId);
			   						    				  if(auxiliarIndice >= 0 &&
			   						    				   		!emp_modificarSector(arrayEmployees,QTY_EMPLOYEES,auxiliarIndice))
			   						    				   	 {
			   						    				   		 printf("\nSe modifico saladio de empleado %d correctamente\n",auxiliarIndice);
			   						    				   	 }
			   						    			 }
			   						    		break;
			                            }
			   						}
			   					}while (opcion2 != 5);
			           }
	                   else
		   		      {
		   		    	 printf("\nNo hay clientes ingresados\n");
		   		      }

			   break;
			   /*
			    * Verifica que se haya cargado un empleado, si se cargo, se ingresa el ID del empleado a dar de baja
			    */
		       case 3:
		    	   if(info_cargaActiva(arrayEmployees,QTY_EMPLOYEES)==0)
		    	   {
		    	   emp_printEmployees(arrayEmployees,QTY_EMPLOYEES);
		    	   if(!utn_getNumero(&auxiliarId,"\nIngrese ID empleado:","\nID invalido",0,idEmpleado,2))
		    	   	{
		    	   	   auxiliarIndice = emp_findEmployeeById(arrayEmployees,QTY_EMPLOYEES,auxiliarId);
		    	   		 if(auxiliarIndice >= 0 &&
		    	   				 !emp_bajaArray(arrayEmployees,QTY_EMPLOYEES,auxiliarIndice))
		    	   		 {
		    	   			 printf("\nBaja realizada\n");
		    	   		 }
		    	   	}
		    	   }
		    	   else
		    	   {
		    	    printf("\nNo hay clientes ingresados\n");
		    	   }
				break;
				/*
				 * Verifica que se haya cargado un empleado, si se cargo, entra a un menu para poder imprimir informacion de empleados
				 */
		       case 4:
		    	   if(info_cargaActiva(arrayEmployees,QTY_EMPLOYEES)==0)
		    	   {
                     do{
                    	 if(!utn_getNumero(&opcion3,"\nInformes:"
                    									  "\n1.Empleados organizados por Apellido y sector correspondiente"
                    									  	"\n2.Total de salario, sueldo promedio y sueldos superiores al promedio"
                    									  	"\n3.Salir\n",
                    									  	 "\nError opcion invalida",1,3,2))
                    	 {
                    		switch(opcion3)
                    		{
                    		case 1:
                    			emp_ordenarPorApellido(arrayEmployees,QTY_EMPLOYEES);
                    			emp_printEmployeesApellidos(arrayEmployees,QTY_EMPLOYEES);
                    			break;
                    		case 2:
                    			info_totalSueldos(arrayEmployees,QTY_EMPLOYEES);
                    			break;

                    		}
                    	 }
                     }while(opcion3 != 3);
               	   }
		    	     else
		    	     {
		    		    printf("\nNo hay clientes ingresados\n");
		    	      }
		          break;

		   }

	   }

   }while(opcion != 5);


	return EXIT_SUCCESS;
}
