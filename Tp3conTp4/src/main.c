#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option;
    int option2;

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* subList;
    LinkedList* listFiltrada;

    do{
        	if(!utn_getNumero(&option,"\nMENU"
    									"\n1-Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
    									"\n2-Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
    									"\n3-Alta de empleado"
    									"\n4-Modificar datos de empleado"
    									"\n5-Baja de empleado"
    									"\n6-Listar empleados"
    									"\n7-Ordenar empleados por sueldo"
    									"\n8-Guardar los datos de los empleados en el archivo data.csv (modo texto)."
    									"\n9-Guardar los datos de los empleados en el archivo data.csv (modo binario)."
    									"\n10-PruebaLinkedList"
        								"\n11-Salir\n",
    									"\nError opcion invalida\n",1,11,2))
            switch(option)
            {
                case 1:
					controller_loadFromText("data.csv",listaEmpleados);//Cargo archivo de texto original.
					//controller_loadFromText("data2.csv",listaEmpleados);//Copia del archivo original
                    break;
                case 2:
                	controller_loadFromBinary("data2.bin",listaEmpleados);//Cargo archivo binario
                    break;
                case 3:
                    controller_addEmployee(listaEmpleados);//Agrego un empleado
                 	break;
                case 4:
                	controller_editEmployee(listaEmpleados);//Edito datos del empleado
                    break;
                case 5:
                	controller_removeEmployee(listaEmpleados);//Remuevo un empleado de la lista
                    break;
                case 6:
                	controller_ListEmployee(listaEmpleados);//Imprime la lista de empleados
                    break;
                case 7:
                    controller_sortEmployee(listaEmpleados);//Ordenada los empleados por sueldo
                    break;
                case 8:
                	controller_saveAsText("data2.csv",listaEmpleados);//Guarda en copia el archivo original modificado
                    break;
                case 9:
                	controller_saveAsBinary("data2.bin",listaEmpleados);//Guarda en archivo binario
                    break;
                case 10:
                	do{
                		if(!utn_getNumero(&option2,"\nLinkedList"
                		    									"\n1-Prueba Clear"
                		    									"\n2-Prueba DeleteLinkedList"
                		    									"\n3-Prueba IsEmpty"
                		    									"\n4-Prueba Push"
                		    									"\n5-Prueba Pop"
                		    									"\n6-Prueba ContainsAll"
                		    									"\n7-Prueba Clone"
																"\n8-Prueba Map"
																"\n9-Prueba Filter"
																"\n10-Imprimir Listas"
                		        								"\n11-Salir\n",
                		    									"\nError opcion invalida\n",1,11,2))
                		switch(option2)
                		{
                			case 1:
                				controller_clear(listaEmpleados);
                				break;
                			case 2:
                                controller_deleteLinkedList(listaEmpleados);
                				break;
                			case 3:
                				controller_isEmpty(listaEmpleados);
                				break;
                			case 4:
                				controller_push(listaEmpleados);
                				break;
                			case 5:
                				controller_pop(listaEmpleados);
                				break;
                			case 6:
                                 controller_containsAll(listaEmpleados,subList);
                				break;
                			case 7:
                				subList = controller_clone(listaEmpleados);
                				break;
                			case 8:
                                //ll_map(listaEmpleados,employee_imprimirMap);
                                ll_map(listaEmpleados,employee_ajustesSueldo);
                				break;
                			case 9:
                				listFiltrada = ll_filter(listaEmpleados,employee_obtenerHsMayores);
                				ll_map(listFiltrada,employee_imprimirMap);
                				ll_count(listFiltrada,employee_calcularSueldos);
                				break;
                			case 10:
                				controller_ListEmployee(listaEmpleados);
                				controller_ListEmployee(subList);
                		        break;



                		}

                	}while(option2 != 11);

            }
        }while(option != 11);
        return 0;
}

