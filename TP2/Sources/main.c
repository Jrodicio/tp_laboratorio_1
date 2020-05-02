#include <stdio.h>
#include "../Headers/ArrayEmployees.h"
#include "../Headers/Menu.h"
#include "../Headers/GetValues.h"
#define OPCIONESMENUPRINCIPAL 4
#define OPCIONESMENUINFORMAR 2
#define MAXIMOEMPLEADOS 10


int main()
{
	eMenu menuPrincipal = {"Menú principal",4,{"ALTAS","MODIFICAR","BAJA","INFORMAR"}};

	int lastEmployeeId = 0;
	Employee listaEmpleados[MAXIMOEMPLEADOS];
	int opcionIngresada;
	int retornoFuncion;
	Employee auxEmployee;

	//Inicializamos lista empleados
	initEmployees(listaEmpleados,MAXIMOEMPLEADOS);

	do
	{
		system("clear");
		printMenu(menuPrincipal);
		opcionIngresada = getIntValidacion("Ingrese una opción: ","Opción inválida, vuelva a intentarlo: ",1,OPCIONESMENUPRINCIPAL);

		switch(opcionIngresada)
		{
			case 1:

				//id
				lastEmployeeId++;
				auxEmployee.id = lastEmployeeId;

				//nombre
				inputEmployeeName(auxEmployee);

				//apellido
				inputEmployeeLastName(auxEmployee);

				//sueldo
				inputEmployeeSalary(auxEmployee);

				//sector
				inputEmployeeSector(auxEmployee);

				//una vez ingresados los datos, ejecutamos addEmployee
				retornoFuncion = addEmployee(listaEmpleados, MAXIMOEMPLEADOS,auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector);
				if (retornoFuncion == 0)
				{
					pausa("Empleado dado de alta correctamente. Pulse <Enter> para continuar...");
				}
			break;
		}

	}while (1==0);

	return 0;
}


