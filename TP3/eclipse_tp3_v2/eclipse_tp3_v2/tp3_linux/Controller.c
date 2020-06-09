#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "GetValues.h"
#include "Validations.h"
#include "Menu.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* employeeFileCSV;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		ll_clear(pArrayListEmployee);
		employeeFileCSV = fopen(path,"r");
		if (employeeFileCSV != NULL)
		{
			retorno = parser_EmployeeFromText(employeeFileCSV,pArrayListEmployee);
		}
		fclose(employeeFileCSV);
	}
	return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
	return 1;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int newID;
	char* newName = "0";
	int newWorkedHours;
	int newSalary;
	Employee* newEmployee;

	if (pArrayListEmployee != NULL)
	{
		getNewID(&newID);

		while(!inputName(newName))
		{
			pausa("El nombre es inválido");
		}

		while(!inputWorkedHours(&newWorkedHours))
		{
			pausa("Las horas trabajadas deben ser mayores a 0");
		}

		while(!inputSalary(&newSalary))
		{
			pausa("El salario debe ser mayor a 0");
		}

		if(msjConfirm("¿Quiere guardar al nuevo empleado?"))
		{
			newEmployee = employee_newParametros(newID,newName,newWorkedHours,newSalary);
			ll_add(pArrayListEmployee, newEmployee);
			retorno = 1;
		}
	}
	return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int index;
	int opcionIngresada;
	Employee* myEmployee;
	char* opciones[128] = {"Buscar empleado por ID","Volver al menú anterior"};

	if(pArrayListEmployee != NULL)
	{
		do
		{
			opcionIngresada = inputMenuOption(opciones);
			switch(opcionIngresada)
			{
				case 1:
						index = controller_findEmployeeByID(pArrayListEmployee,myEmployee);
						if (index == -1)
						{
							pausa("No se encontraron empleados con el ID ingresado");
						}
						else
						{
							editEmployee(myEmployee);
						}
					break;
				case 2:
					pausa("Volviendo al menú anterior");
					break;
				default:
					pausa("Opción incorrecta");
					break;
			}
		}while((opcionIngresada != 1 && opcionIngresada != 2) || (opcionIngresada == 1 && index == -1));
	}

	return retorno;
}


int controller_findEmployeeByID(LinkedList* pArrayListEmployee, Employee* myEmployee)
{
	int id;
	int i;
	int retorno = -1;
	int len;

	if (pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		inputInt("Ingrese ID a buscar: ",&id);
		for(i=0;i<len;i++)
		{
			myEmployee = (Employee*) ll_get(pArrayListEmployee,i);
			if(myEmployee->id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
	return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
	return 1;
}
