#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int cantEmpleados = -1;
	Employee* pEmployee;



	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while (!feof(pFile))
		{
			pEmployee = employee_new();
			fscanf(pFile, "\n");

			if(cantEmpleados > -1)
			{
				fscanf(pFile, "%d,%[^,],%d,%d\n", &pEmployee->id, pEmployee->nombre, &pEmployee->horasTrabajadas, &pEmployee->sueldo);
				ll_add(pArrayListEmployee,pEmployee);
			}
			else
			{
				fscanf(pFile, "%*[^\n]\n");
			}
			cantEmpleados++;
		}

	}
    return cantEmpleados;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
