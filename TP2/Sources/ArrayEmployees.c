#include <stdio.h>
#include <string.h>
#include "../Headers/ArrayEmployees.h"
#include "../Headers/GetValues.h"
#define TRUE 1
#define FALSE 0

int initEmployees(Employee* list, int len)
{
	int retorno = 1;
	int i;
	//si len es válido y list es not null.
	for (i=0;i<len;i++)
	{
		//inicializo y retorno 1 luego
		list[i].isEmpty = TRUE;
	}
	//sino, retorno = 0.
	return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int i;
	int retorno = 0;

	i = findEmptyEmployee(list, len); //Buscar primer lugar libre en list

	if (i == -1)
	{
		retorno = i; //Si no hay espacio libre, retorna -1.
	}
	else //Cargar en list[freeIndex].datos los parametros.
	{
		list[i].id = id;
		strcpy(list[i].name,name);
		strcpy(list[i].lastName,lastName);
		list[i].salary = salary;
		list[i].sector = sector;
		list[i].isEmpty = FALSE;
	}

	return retorno;
}

void inputEmployeeName(Employee myEmployee)
{
	inputArray(myEmployee.name,51,"Ingrese nombre del empleado: ");
	UpperPrimerasLetras(myEmployee.name);
}

void inputEmployeeLastName(Employee myEmployee)
{
	inputArray(myEmployee.lastName,51,"Ingrese apellido del empleado: ");
	UpperPrimerasLetras(myEmployee.lastName);
}

void inputEmployeeSalary(Employee myEmployee)
{
	myEmployee.salary = getFloat("Ingrese el sueldo: ","Valor inválido, por favor vuelva a intentarlo: ", 0);
}

void inputEmployeeSector(Employee myEmployee)
{
	myEmployee.sector = getInt("Ingrese el sector: ");
}



int findEmptyEmployee(Employee* list, int len)
{
	int variableRetorno = -1;
	int i;
	for (i=0;i<len;i++)
	{
		if (list[i].isEmpty == TRUE)
		{
			variableRetorno = i;
			break;
		}
	}

	return variableRetorno;
}

int findEmployeeById(Employee* list, int len,int id)
{
	int variableRetorno = -1;
	int i;
	for (i=0;i<len;i++)
	{
		if (list[i].isEmpty == FALSE && list[i].id == id)
		{
			variableRetorno = i;
			break;
		}
	}
	return variableRetorno;
}

int removeEmployee(Employee* list, int len, int id)
{
	int retorno = 0;
	int index = findEmployeeById(list,len,id);

	if (index == -1)
	{
		retorno = -1;
	}
	else
	{
		list[index].isEmpty = TRUE;
	}

	return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{

	if(order)
	{
		orderEmployeesASC(list,len);
	}

	else
	{
		orderEmployeesDESC(list,len);
	}

	return 0;
}


void orderEmployeesASC (Employee* list, int len)
{
	int i;
	int j;
	Employee auxEmployee;

	for(i=0;i<len-1;i++)
	{
		if (list[i].isEmpty == TRUE)
		{
			continue;
		}

		for(j=i+1;j<len;j++)
		{
			if (list[j].isEmpty == TRUE)
			{
				continue;
			}

			if(strcmp(list[i].lastName,list[j].lastName)>0)
			{
				auxEmployee = list[i];
				list[i] = list[j];
				list[j] = auxEmployee;
			}
			else
			{
				if(strcmp(list[i].lastName,list[j].lastName)==0)
				{
					if(list[i].sector > list[j].sector)
					{
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					}
				}
			}
		}
	}
}



void orderEmployeesDESC(Employee* list, int len)
{
	int i;
	int j;
	Employee auxEmployee;

	for(i=0;i<len-1;i++)
	{
		if (list[i].isEmpty == TRUE)
		{
			continue;
		}

		for(j=i+1;j<len;j++)
		{
			if (list[j].isEmpty == TRUE)
			{
				continue;
			}

			if(strcmp(list[i].lastName,list[j].lastName)<0)
			{
				auxEmployee = list[i];
				list[i] = list[j];
				list[j] = auxEmployee;
			}
			else
			{
				if(strcmp(list[i].lastName,list[j].lastName)==0)
				{
					if(list[i].sector < list[j].sector)
					{
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					}
				}
			}
		}
	}
}




int printEmployees(Employee* list, int length)
{
	int i;
	printf("\n %10s %20s %20s %10s %10s","ID","Name","Surname","Salary","Sector");
	for(i=0;i<length;i++)
	{
		if (list[i].isEmpty == FALSE)
		{
			printEmployee(list[i]);
		}
	}
	return 0;
}


void printEmployee(Employee myEmployee)
{
	printf("\n %10d %20s %20s %10.2f %10d",	myEmployee.id,
											myEmployee.name,
											myEmployee.lastName,
											myEmployee.salary,
											myEmployee.sector);
}





