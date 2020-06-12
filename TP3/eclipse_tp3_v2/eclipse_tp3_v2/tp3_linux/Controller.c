#include "Controller.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
	int retorno = controller_loadFile(path,pArrayListEmployee,"r");
	return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
	int retorno = controller_loadFile(path,pArrayListEmployee,"rb");
	return retorno;
}

int controller_loadFile(char* path, LinkedList* pArrayListEmployee, char* typeRead)
{
	int retorno = 0;
	int cantEmployee = -1;
	int cargarArchivo = 1;
	FILE* employeeFile;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		if(!ll_isEmpty(pArrayListEmployee))
		{
			if(!msjConfirm("Ya se ha leído un archivo previamente, ¿quiere sobreescribir los datos?"))
			{
				cargarArchivo = 0;
			}
		}
		if(cargarArchivo)
		{
			employeeFile = fopen(path,typeRead);
			if (employeeFile != NULL)
			{
				ll_clear(pArrayListEmployee);
				if(!strcmp(typeRead,"rb"))
				{
					cantEmployee = parser_EmployeeFromBinary(employeeFile,pArrayListEmployee);
				}
				else if(!strcmp(typeRead,"r"))
				{
					cantEmployee = parser_EmployeeFromText(employeeFile,pArrayListEmployee);
				}
				fclose(employeeFile);
			}
		}

	}
	if (!cargarArchivo)
	{
		retorno = -1;
	}
	else if (cantEmployee == -1)
	{
		retorno = 0;
	}
	else
	{
		retorno = 1;
	}
	return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	Employee* newEmployee;

	if (pArrayListEmployee != NULL)
	{
		system("clear");
		newEmployee = employee_new();

		printEmployeeHeader();
		printEmployee(newEmployee);

		if(msjConfirm("¿Quiere guardar al nuevo empleado?"))
		{
			ll_add(pArrayListEmployee, newEmployee);
			retorno = 1;
		}
		else
		{
			free(newEmployee);
			retorno = -1;
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
			system("clear");
			opcionIngresada = inputMenuOption(opciones);
			switch(opcionIngresada)
			{
				case 1:
						myEmployee = controller_findEmployeeByID(pArrayListEmployee);
						if (myEmployee == NULL)
						{
							pausa("No se encontraron empleados con el ID ingresado\n");
						}
						else
						{
							editEmployee(myEmployee);
						}
					break;
				case 2:
					pausa("Volviendo al menú anterior\n");
					break;
				default:
					pausa("Opción incorrecta\n");
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
	int retorno = 0;
	char* opciones[128] = {"Buscar empleado por ID","Volver al menú anterior"};

	if(pArrayListEmployee != NULL)
	{
		do
		{
			system("clear");
			opcionIngresada = inputMenuOption(opciones);
			switch(opcionIngresada)
			{
				case 1:
						myEmployee = controller_findEmployeeByID(pArrayListEmployee);
						if (myEmployee == NULL)
						{
							pausa("No se encontraron empleados con el ID ingresado.\n");
						}
						else
						{
							printEmployeeHeader();
							printEmployee(myEmployee);
							if(msjConfirm("¿Está seguro que quiere eliminar al empleado?"))
							{
								retorno = !ll_remove(pArrayListEmployee,ll_indexOf(pArrayListEmployee,myEmployee));
								salir = 1;
							}
						}
					break;
				case 2:
					pausa("Volviendo al menú anterior.\n");
					salir = 1;
					break;
				default:
					pausa("Opción incorrecta.\n");
					break;
			}
		}while(!salir);
	}
	return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int i;
	int maxReg;
	int page = 1;
	int auxPage;
	int len = ll_len(pArrayListEmployee);
	int maxPage = (len+99)/100;

	do
	{
		system("clear");
		i = (page-1)*100;
		maxReg = (page*100);
		printEmployeeHeader();
		for(i=(page-1)*100 ; i < maxReg && i < len; i++)
		{
			auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			printEmployee(auxEmployee);
		}
		printf("Mostrando página %d/%d",page,maxPage);

		inputInt("Ingrese número de página ó '0' para salir: ",&auxPage);
		if(auxPage>maxPage || auxPage < 0)
		{
			pausa("Número de página inválida, vuelva a intentarlo.\n");
		}
		else
		{
			page = auxPage;
		}

	}while(page != 0);

	return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	char* opciones[128] = {"Ordenar por nombre ASC", "Ordenar por nombre DESC", "Ordenar por ID ASC", "Ordenar por ID DESC", "Volver al menú anterior"};
	int opcionIngresada;
	int order;

	do
	{
		system("clear");
		opcionIngresada = inputMenuOption(opciones);

		order = opcionIngresada%2;

		switch(opcionIngresada)
		{
			case 1:
			case 2:
				printf("Se está ordenando la lista...\n");
				ll_sort(pArrayListEmployee,employee_CompareByName,order);
				pausa("Lista ordenada correctamente.\n");
				break;
			case 3:
			case 4:
				printf("Se está ordenando la lista...\n");
				ll_sort(pArrayListEmployee,employee_CompareById,order);
				pausa("Lista ordenada correctamente.\n");
				break;
			case 5:
				pausa("Volviendo al menú anterior.\n");
				break;
			default:
				pausa("Opción inválida. Vuelva a intentarlo.\n");
				break;
		}

	}while(opcionIngresada != 5);

	return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
	int retorno = controller_saveFile(path, pArrayListEmployee,"w");
	return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
	int retorno = controller_saveFile(path, pArrayListEmployee,"wb");
	return retorno;
}

int controller_saveFile(char* path, LinkedList* pArrayListEmployee, char* typeOpen)
{
	int i;
	int len;
	FILE* employeeFile;
	Employee* auxEmployee;

	int retorno = 0;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		employeeFile = fopen(path,typeOpen);
		if (employeeFile != NULL)
		{
			for(i=0;i<len;i++)
			{
				auxEmployee = ll_get(pArrayListEmployee,i);
				if (!strcmp(typeOpen,"wb"))
				{
					fwrite(auxEmployee, sizeof(Employee),1,employeeFile);
				}
				else if (!strcmp(typeOpen,"w"))
				{
					if (i == 0)
					{
						fprintf(employeeFile, "id,nombre,horasTrabajadas,sueldo\n");
					}
					fprintf(employeeFile, "%d,%s,%d,%d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
				}
			}
			retorno = i;
			fclose(employeeFile);
		}
	}
	return retorno;
}
