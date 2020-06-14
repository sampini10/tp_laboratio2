#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define NOMBRE_LEN 100


typedef struct
{
    int id;
    char nombre[NOMBRE_LEN];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametrosTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
Employee* employee_newParametros(int id,char* nombreStr,int horasTrabajadas,int sueldo);
void employee_delete();
int employee_imprimir(Employee* this);
int employee_ordenarSueldo(void* pElemento,void* pElemento2);

int employee_setId(Employee* this,int id);
int employee_setIdStr(Employee* this,char* id);
int employee_getId(Employee* this,int* id);
int employee_getIdStr(Employee* this,char* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_getHorasTrabajadasStr(Employee* this,char* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_setSueldoStr(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_getSueldoStr(Employee* this,char* sueldo);

#endif // employee_H_INCLUDED
