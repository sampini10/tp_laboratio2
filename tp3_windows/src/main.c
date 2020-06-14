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
    int option = 0;


    LinkedList* listaEmpleados = ll_newLinkedList();

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
    									"\n10-Salir\n",
    									"\nError opcion invalida\n",1,10,2))
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

            }
        }while(option != 10);
        return 0;
}

