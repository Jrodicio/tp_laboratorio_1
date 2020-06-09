#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "GetValues.h"
#include "Validations.h"
#include "Menu.h"

/*Create*/
Employee* employee_new()
{
	/*Crea y retorna pEmployee sin datos.*/

	Employee* pEmployee;

	pEmployee = (Employee*) malloc(sizeof(Employee));

	return pEmployee;
}


Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas,int sueldo)
{
	//Crea pEmployee. Setea datos y retorna.

	Employee* pEmployee;
	pEmployee = employee_new();

	employee_setId(pEmployee,id);
	employee_setNombre(pEmployee,nombre);
	employee_setHorasTrabajadas(pEmployee,horasTrabajadas);
	employee_setSueldo(pEmployee, sueldo);

	return pEmployee;
}

/*Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	//Crea pEmployee. Setea datos y retorna.

	Employee* pEmployee;
	pEmployee = employee_new();

	employee_setId(pEmployee,(int) *idStr));
	employee_setNombre(pEmployee,nombreStr);
	employee_setHorasTrabajadas(pEmployee,(int) *horasTrabajadasStr);
	employee_setSueldo(pEmployee, (int) *sueldoStr);

	return pEmployee;
}*/

int employee_delete(Employee* this)
{
	int retorno = 0;

	if(this != NULL)
	{
		free(this);
		retorno = 1;
	}

	return retorno;
}

/*Setters & Getters*/
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = 0;
	if(this != NULL && nombre != NULL && stringIsAlpha(nombre))
	{
		strcpy(this->nombre,nombre);
		retorno = 1;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 1;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = 0;
	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		retorno = 1;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = 0;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 1;
	}
	return retorno;
}

int employee_setId(Employee* this,int id)
{
	int retorno = 0;
	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}
	return retorno;
}
int employee_getId(Employee* this,int* id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = 0;
	if(this != NULL && horasTrabajadas >= 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = 0;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}
	return retorno;
}

/*Compare*/
int employee_CompareByName(Employee* firstEmployee, Employee* secondEmployee)
{
	int retorno = 0;
	if (firstEmployee != NULL && secondEmployee != NULL)
    {
		retorno = strcmp(firstEmployee->nombre, secondEmployee->nombre);
    }
	return retorno;
}

int employee_CompareById(Employee* firstEmployee, Employee* secondEmployee)
{
	int retorno = -2;
	if (firstEmployee != NULL && secondEmployee != NULL)
	{
		if(firstEmployee->id > secondEmployee->id)
		{
			retorno = 1;
		}
		else if (firstEmployee->id == secondEmployee->id)
		{
			retorno = 0;
		}
		else
		{
			retorno = -1;
		}
	}
	return retorno;
}

int saveLastEmployeeID (int lastID)
{
	FILE* logFile;
	int retorno = 0;
	logFile = fopen("lastID.log","w");

	if(logFile != NULL)
	{
		fprintf(logFile,"%d",lastID);
		retorno = 1;
	}
	fclose(logFile);

	return retorno;

}

int getLastEmployeeID (int* ID)
{
	FILE* pFileID;
	int retorno = 0;
	*ID = 0;
	pFileID = fopen("lastID.log","r");

	if (pFileID != NULL && ID != NULL)
	{
		fscanf(pFileID, "%d[^\n]\n",ID);
	}
	return retorno;
}

void getNewID(int* newID)
{
	getLastEmployeeID(newID);
	(*newID)++;
}

int inputName(char* name)
{
	inputArray(name,128,"Ingrese nombre del empleado: ");
	upperFirstLetters(name);

	return stringIsAlpha(name);
}

int inputWorkedHours(int* workedHours)
{
	return inputPositiveInt("Ingrese horas trabajadas: ", workedHours);
}

int inputSalary(int* salary)
{
	return inputPositiveInt("Ingrese sueldo: ", salary);
}


int editEmployee(Employee* myEmployee)
{
	int option;
	char* name;
	int workedHours;
	int salary;
	int retorno = -1;
	int salir = 0;
	int edicionesSinGuardar = 0;
	char* menu[128] = {"Editar nombre", "Editar horas trabajadas", "Editar salario", "Guardar cambios", "Salir"};

	employee_getNombre(myEmployee,name);
	employee_getHorasTrabajadas(myEmployee,&workedHours);
	employee_getSueldo(myEmployee,&salary);

	do
	{
		option = inputMenuOption(menu);
		switch(option)
		{
			case 1:
				while(!inputName(name))
				{
					pausa("El nombre es inválido");
				}
				edicionesSinGuardar = 1;
				break;
			case 2:
				while(!inputWorkedHours(&workedHours))
				{
					pausa("Las horas trabajadas deben ser mayores a 0");
				}
				edicionesSinGuardar = 1;
				break;

			case 3:
				while(!inputSalary(&salary))
				{
					pausa("El salario debe ser mayor a 0");
				}
				edicionesSinGuardar = 1;
				break;
			case 4:
				if(edicionesSinGuardar)
				{
					if(msjConfirm("Se sobreescribirán los datos del empleado, ¿está seguro?"))
					{
						employee_setNombre(myEmployee,name);
						employee_setHorasTrabajadas(myEmployee, workedHours);
						employee_setSueldo(myEmployee,salary);
						edicionesSinGuardar = 0;
						retorno = 1;
						pausa("Los cambios se han guardado");
					}
				}
				break;
			case 5:
				if(edicionesSinGuardar)
				{
					if(msjConfirm("Hay cambios sin guardar, los mismos serán descartados, ¿está seguro?"))
					{
						salir = 1;
					}
				}
				else
				{
					salir = 1;
				}
				break;
		}

	}while(!salir);

	return retorno;
}

