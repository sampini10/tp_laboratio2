/*
 * ArrayEmployees.h
 *
 *  Created on: 25 abr. 2020
 *      Author: sampini
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define NAME_LEN 51
#define LAST_LEN 51


typedef struct
{
	int id;
	char name[NAME_LEN];
	char lastName[LAST_LEN];
	float salary;
	int sector;
	int isEmpty;

}Employee;

int emp_initEmployees(Employee* array, int limite);
int emp_printEmployees(Employee* array, int limite);
int emp_addEmployee(Employee* array, int limite,int indice, int* id);
int emp_imprimir(Employee* pElemento);
int emp_getEmptyIndex(Employee* array,int limite);
int emp_findEmployeeById(Employee* array, int limite, int valorBuscado);
int emp_modificarNombre(Employee* array,int limite, int indice);
int emp_modificarApellido(Employee* array,int limite, int indice);
int emp_modificarSalario(Employee* array,int limite, int indice);
int emp_modificarSector(Employee* array,int limite, int indice);
int emp_bajaArray(Employee* array,int limite, int indice);
int emp_altaForzadaArray(Employee* array,int limite, int indice, int* id,char* nombre,char* apellido,float salario,int sector);
int emp_ordenarPorApellido(Employee* array,int limite);
int emp_imprimirApellidoSector(Employee* pElemento);
int emp_printEmployeesApellidos(Employee* array, int limite);
int info_totalSueldos(Employee* array,int limite);
int info_sueldosPromedios(Employee* array,int limite,float promedio);
int info_cargaActiva(Employee* array,int limite);

#endif /* ARRAYEMPLOYEES_H_ */
