#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "GetValues.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{

	int opcionIngresada = 1;
    int i;
    int cantEmployee;
    Employee* auxEmployee;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
       // printMenu();


    	system("clear");
    	switch(opcionIngresada)
        {
    		case 1:
				cantEmployee = controller_loadFromText("data.csv",listaEmpleados);

				getLastEmployeeID(&i);
				printf("LastID: %d\n",i);
				controller_editEmployee(listaEmpleados);
				/* ListClients
				i = 0;
				while ((auxEmployee = (Employee*) ll_get(listaEmpleados, i)))
				{
					i++;
					printf("%5d | %10s | %5d | %7d\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
					if (i == 5)
						i = 1000;
				}*/

				if(cantEmployee > 0)
				{
					pausa("Se ha cargado la lista de empleados correctamente");
				}
				else
				{
					pausa("El archivo no posee empleados o no se ha podido leer.");
				}

				break;

            case 2:
            	pausa("AIUDA");
            	break;
            case 3:
            	if(controller_addEmployee(listaEmpleados))
            	{
            		pausa("Empleado cargado con éxito");
            	}
            	else
            	{
            		pausa("Cancelando alta de empleado");
            	}

            	break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;
            default:
            	pausa("Opción incorrecta");
            	break;
        }

        opcionIngresada = 10;

    }while(opcionIngresada != 10);
    return 0;
}
