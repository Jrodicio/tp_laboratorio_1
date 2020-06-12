#include "Employee.h"


/*Create*/

Employee* employee_Constructor()
{
	return (Employee*) malloc(sizeof(Employee));
}


Employee* employee_new()
{
	/*Crea y retorna pEmployee*/

	int newID;
	char newName[128] = " ";
	int newWorkedHours = 0;
	int newSalary = 0;

	Employee* pEmployee = employee_Constructor();

	getNewID(&newID);
	employee_setId(pEmployee,newID);
	employee_setNombre(pEmployee,newName);
	employee_setHorasTrabajadas(pEmployee,newWorkedHours);
	employee_setSueldo(pEmployee,newSalary);

	printEmployeeHeader();
	printEmployee(pEmployee);

	inputName(newName);
	employee_setNombre(pEmployee,newName);
	system("clear");

	printEmployeeHeader();
	printEmployee(pEmployee);

	inputWorkedHours(&newWorkedHours);
	employee_setHorasTrabajadas(pEmployee,newWorkedHours);
	system("clear");

	printEmployeeHeader();
	printEmployee(pEmployee);

	inputSalary(&newSalary);
	employee_setSueldo(pEmployee,newSalary);
	system("clear");

	return pEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* pEmployee = employee_Constructor();

	employee_setId(pEmployee,atoi(idStr));
	employee_setNombre(pEmployee,nombreStr);
	employee_setHorasTrabajadas(pEmployee,atoi(horasTrabajadasStr));
	employee_setSueldo(pEmployee,atoi(sueldoStr));

	return pEmployee;
}

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
	if(this != NULL && sueldo >= 0)
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
int employee_CompareByName(void* e1, void* e2)
{
	Employee* firstEmployee = (Employee*) e1;
	Employee* secondEmployee = (Employee*) e2;
	int retorno;
	int compare;

	if (firstEmployee != NULL && secondEmployee != NULL)
    {
		compare = strcmp(firstEmployee->nombre, secondEmployee->nombre);
		if(compare > 0)
		{
			retorno = 1;
		}
		else if (compare < 0)
		{
			retorno = -1;
		}
		else
		{
			retorno = 0;
		}
    }
	return retorno;
}

int employee_CompareById(void* e1, void* e2)
{
	int retorno = -2;
	Employee* firstEmployee = (Employee*) e1;
	Employee* secondEmployee = (Employee*) e2;

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
		fclose(logFile);
		retorno = 1;
	}
	return retorno;

}

int getLastEmployeeID (int* ID)
{
	FILE* pFileID;
	int retorno = 0;
	pFileID = fopen("lastID.log","r");

	if (pFileID != NULL && ID != NULL)
	{

		fscanf(pFileID, "%d",ID);
		retorno = 1;
		fclose(pFileID);
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
	int nombreCorrecto = 1;
	do
	{
		inputArray(name,127,"Ingrese nombre del empleado: ");
		upperFirstLetters(name);
		if(!stringIsAlpha(name))
		{
			pausa("El nombre no es correcto, vuelva a intentarlo.\n");
			nombreCorrecto = 0;
		}
		else
		{
			nombreCorrecto = 1;
		}
	} while (!nombreCorrecto);

	return nombreCorrecto;
}

int inputWorkedHours(int* workedHours)
{
	int retorno = 0;

	while(!inputPositiveInt("Ingrese horas trabajadas: ", workedHours))
	{
		pausa("Las horas trabajadas no pueden ser menores a 0.\n");
	}
	retorno = 1;
	return retorno;
}

int inputSalary(int* salary)
{
	int retorno = 0;
	while(!inputPositiveInt("Ingrese sueldo: ", salary))
	{
		pausa("El salario no puede ser menor a 0.\n");
	}
	retorno = 1;
	return retorno;
}


int editEmployee(Employee* myEmployee)
{
	int option;
	char name[128];
	int id;
	int workedHours;
	int salary;
	int retorno = -1;
	int salir = 0;
	int edicionesSinGuardar = 0;
	Employee auxEmployee;
	char* menu[128] = {"Editar nombre", "Editar horas trabajadas", "Editar salario", "Guardar cambios", "Salir"};

	employee_getId(myEmployee,&id);
	employee_getNombre(myEmployee,name);
	employee_getHorasTrabajadas(myEmployee,&workedHours);
	employee_getSueldo(myEmployee,&salary);

	employee_setId(&auxEmployee,id);
	employee_setNombre(&auxEmployee,name);
	employee_setHorasTrabajadas(&auxEmployee,workedHours);
	employee_setSueldo(&auxEmployee,salary);

	do
	{
		system("clear");
		printEmployeeHeader();
		printEmployee(myEmployee);
		printEmployee(&auxEmployee);

		option = inputMenuOption(menu);
		switch(option)
		{
			case 1:
				inputName(name);
				employee_setNombre(&auxEmployee,name);
				edicionesSinGuardar = 1;
				break;

			case 2:
				inputWorkedHours(&workedHours);
				employee_setHorasTrabajadas(&auxEmployee,workedHours);
				edicionesSinGuardar = 1;
				break;

			case 3:
				inputSalary(&salary);
				employee_setSueldo(&auxEmployee,salary);
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
						pausa("Los cambios se han guardado\n");
					}
					else
					{
						pausa("No se han aplicado modificaciones.\n");
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

void printEmployeeHeader(void)
{
	printf("%5s | %15s | %16s | %8s \n","ID","Nombre","Horas trabajadas","Sueldo");
}
void printEmployee(Employee* myEmployee)
{
	printf("%5d | %15s | %16d | %7d\n", myEmployee->id, myEmployee->nombre, myEmployee->horasTrabajadas, myEmployee->sueldo);
}

