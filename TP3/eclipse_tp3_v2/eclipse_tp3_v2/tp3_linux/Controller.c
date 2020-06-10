#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "GetValues.h"
#include "Validations.h"
#include "Menu.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int cargarArchivo = 1;
	FILE* employeeFileCSV;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		if(!ll_isEmpty(pArrayListEmployee))
		{
			if(msjConfirm("Ya se ha leído un archivo previamente, ¿quiere sobreescribir los datos?"))
			{
				ll_clear(pArrayListEmployee);
			}
			else
			{
				cargarArchivo = 0;
			}
		}
		if(cargarArchivo)
		{
			employeeFileCSV = fopen(path,"r");
			if (employeeFileCSV != NULL)
			{
				retorno = parser_EmployeeFromText(employeeFileCSV,pArrayListEmployee);
				fclose(employeeFileCSV);
			}

			if (retorno > 0)
			{
				retorno = 1;
			}
		}

	}
	return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{

	int retorno = 0;
	int cargarArchivo = 1;
	FILE* employeeFileBIN;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		if(!ll_isEmpty(pArrayListEmployee))
		{
			if(msjConfirm("Ya se ha leído un archivo previamente, ¿quiere sobreescribir los datos?"))
			{
				ll_clear(pArrayListEmployee);
			}
			else
			{
				cargarArchivo = 0;
			}
		}
		if(cargarArchivo)
		{
			employeeFileBIN = fopen(path,"rb");
			if (employeeFileBIN != NULL)
			{
				retorno = parser_EmployeeFromBinary(employeeFileBIN,pArrayListEmployee);
				fclose(employeeFileBIN);
			}

			if (retorno > 0)
			{
				retorno = 1;
			}
		}

	}
	return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	Employee* newEmployee;

	if (pArrayListEmployee != NULL)
	{
		newEmployee = employee_new();

		if(msjConfirm("¿Quiere guardar al nuevo empleado?"))
		{
			ll_add(pArrayListEmployee, newEmployee);
			retorno = 1;
		}
		else
		{
			free(newEmployee);
		}
	}
	return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
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
						myEmployee = controller_findEmployeeByID(pArrayListEmployee);
						if (myEmployee == NULL)
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
		}while((opcionIngresada != 1 && opcionIngresada != 2) || (opcionIngresada == 1 && myEmployee == NULL));
	}

	return retorno;
}


Employee* controller_findEmployeeByID(LinkedList* pArrayListEmployee)
{
	int id;
	int i;
	int len;
	Employee* myEmployee;


	if (pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		inputInt("Ingrese ID a buscar: ",&id);
		for(i=0;i<len;i++)
		{
			myEmployee = (Employee*) ll_get(pArrayListEmployee,i);
			if(myEmployee->id == id)
			{
				break;
			}
			if(i == len-1)
			{
				myEmployee = NULL;
			}
		}
	}
	return myEmployee;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int opcionIngresada;
	Employee* myEmployee;
	int salir = 0;
	char* opciones[128] = {"Buscar empleado por ID","Volver al menú anterior"};

	if(pArrayListEmployee != NULL)
	{
		do
		{
			opcionIngresada = inputMenuOption(opciones);
			switch(opcionIngresada)
			{
				case 1:
						myEmployee = controller_findEmployeeByID(pArrayListEmployee);
						if (myEmployee == NULL)
						{
							pausa("No se encontraron empleados con el ID ingresado");
						}
						else
						{
							printEmployeeHeader();
							printEmployee(myEmployee);
							if(msjConfirm("¿Está seguro que quiere eliminar al empleado?"))
							{
								ll_remove(pArrayListEmployee,ll_indexOf(pArrayListEmployee,myEmployee));
								salir = 1;
							}
						}
					break;
				case 2:
					pausa("Volviendo al menú anterior");
					salir = 1;
					break;
				default:
					pausa("Opción incorrecta");
					break;
			}
		}while(!salir);
	}
	return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int i;
	int maxReg;
	int page = 1;
	int len = ll_len(pArrayListEmployee);
	int maxPage = (len+99)/100;

	do
	{
		i = (page-1)*100;
		maxReg = (page*100);
		printEmployeeHeader();
		for(i=(page-1)*100 ; i < maxReg && i < len; i++)
		{
			auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			printEmployee(auxEmployee);
		}
		printf("Mostrando página %d/%d",page,maxPage);
		do
		{
			inputInt("Ingrese página o '0' para salir: ",&page);

		}while(page>maxPage);

	}while(page != 0);


	return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	char* opciones[128] = {"Ordenar por nombre ASC", "Ordenar por nombre DESC", "Ordenar por ID ASC", "Ordenar por ID DESC", "Volver al menú anterior"};
	int opcionIngresada;

	do
	{
		opcionIngresada = inputMenuOption(opciones);
		switch(opcionIngresada)
		{
			case 1:
				ll_sort(pArrayListEmployee,employee_CompareByName,1);
				break;
			case 2:
				ll_sort(pArrayListEmployee,employee_CompareByName,0);
				break;
			case 3:
				ll_sort(pArrayListEmployee,employee_CompareById,1);
				break;
			case 4:
				ll_sort(pArrayListEmployee,employee_CompareById,0);
				break;
			case 5:
				pausa("Volviendo al menú anterior.");
				break;
			default:
				pausa("Opción inválida. Vuelva a intentarlo.");
				break;
		}

	}while(opcionIngresada != 5);

	return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
	int i;
	int len;
	FILE* employeeFileCSV;
	Employee* auxEmployee;

	int retorno = 0;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		employeeFileCSV = fopen(path,"w");
		if (employeeFileCSV != NULL)
		{
			fprintf(employeeFileCSV, "id,nombre,horasTrabajadas,sueldo\n");
			for(i=0;i<len;i++)
			{
				auxEmployee = ll_get(pArrayListEmployee,i);
				fprintf(employeeFileCSV, "%d,%s,%d,%d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
			}
			retorno = i;
		}
		fclose(employeeFileCSV);
	}
	return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
	int i;
	int len;
	FILE* employeeFileBIN;
	Employee* auxEmployee;

	int retorno = 0;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		employeeFileBIN = fopen(path,"wb");
		if (employeeFileBIN != NULL)
		{
			for(i=0;i<len;i++)
			{
				auxEmployee = ll_get(pArrayListEmployee,i);
				fwrite(auxEmployee, sizeof(Employee),1,employeeFileBIN);
				//fprintf(employeeFileBIN, "%d,%s,%d,%d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
			}
			retorno = i;
		}
		fclose(employeeFileBIN);
	}
	return retorno;
}
