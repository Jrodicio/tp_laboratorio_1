#include "parser.h"



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
	int lastID;
	char id[15];
	char nombre[128];
	char horasTrabajadas[15];
	char sueldo[15];
	Employee* pEmployee;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{

		while (!feof(pFile))
		{

			if(cantEmpleados > -1)
			{

//				fscanf(pFile, "%d,%[^,],%d,%d\n", &pEmployee->id, pEmployee->nombre, &pEmployee->horasTrabajadas, &pEmployee->sueldo);
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

				pEmployee = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
				ll_add(pArrayListEmployee,pEmployee);

				if(!getLastEmployeeID(&lastID) || atoi(id) > lastID)
				{
					saveLastEmployeeID(atoi(id));
				}

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
	int cantEmpleados = 0;
	int lastID;
	Employee* pEmployee;


	if(pFile != NULL && pArrayListEmployee != NULL)
	{

		while (!feof(pFile))
		{
			pEmployee = employee_Constructor();
			if(fread(pEmployee,sizeof(Employee),1,pFile))
			{
				ll_add(pArrayListEmployee,pEmployee);
				if(!getLastEmployeeID(&lastID) || (pEmployee)->id > lastID)
				{
					saveLastEmployeeID((pEmployee)->id);
				}
				cantEmpleados++;
			}
		}
	}
    return cantEmpleados;
}
