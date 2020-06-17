#include "Controller.h"

#define PATHCSV "data.csv"
#define PATHBIN "data.bin"
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
	int opcionIngresada;
    int auxRetornoFuncion;
    int salir = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    char* opcionesMenu[128] =	{		"Cargar los datos de los empleados desde el archivo data.csv (modo texto)",
    									"Cargar los datos de los empleados desde el archivo data.bin (modo binario)",
										"Alta de empleado",
										"Modificar datos de empleado",
										"Baja de empleado",
										"Listar empleados",
										"Ordenar empleados",
										"Guardar los datos de los empleados en el archivo data.csv (modo texto)",
										"Guardar los datos de los empleados en el archivo data.bin (modo binario)",
										"Salir"
    							};

    do{
    	system("clear");

    	opcionIngresada = inputMenuOption(opcionesMenu);
    	if(intRange(opcionIngresada,4,9) && !ll_len(listaEmpleados))
    	{
    		pausa("No tiene empleados cargados en sistema aún.\n");
    		continue;
    	}

    	switch(opcionIngresada)
        {
    		case 1:
    			auxRetornoFuncion = controller_loadFromText(PATHCSV,listaEmpleados);

				switch(auxRetornoFuncion)
				{
					case -1:
						pausa("No se han cargado los datos del archivo.\n");
					break;
					case 0:
						pausa("El archivo no existe o no tiene acceso al mismo.\n");
					break;
					case 1:
						pausa("Archivo cargado correctamente.\n");
					break;
				}
				break;

            case 2:
            	auxRetornoFuncion = controller_loadFromBinary(PATHBIN,listaEmpleados);
				switch(auxRetornoFuncion)
				{
					case -1:
						pausa("No se han cargado los datos del archivo.\n");
					break;
					case 0:
						pausa("El archivo no existe o no tiene acceso al mismo.\n");
					break;
					case 1:
						pausa("Archivo cargado correctamente.\n");
					break;
				}
            	break;

            case 3:
            	auxRetornoFuncion = controller_addEmployee(listaEmpleados);
            	switch(auxRetornoFuncion)
            	{
            		case -1:
            			pausa("Cancelando alta de empleado.\n");
            			break;
            		case 0:
            			pausa("Hubo un error al intentar dar de alta al empleado.\n");
            			break;
            		case 1:
            			pausa("Empleado cargado con éxito.\n");
            			break;
            	}
            	break;

            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;

            case 5:
            	if(controller_removeEmployee(listaEmpleados))
            	{
            		pausa("El empleado se ha eliminado correctamente de la lista.\n");
            	}
            	break;

            case 6:
            	controller_ListEmployee(listaEmpleados);
				break;

            case 7:
            	controller_sortEmployee(listaEmpleados);
            	break;

            case 8:
            	if(controller_saveAsText(PATHCSV,listaEmpleados))
            	{
					pausa("La lista de empleados se guardo correctamente.\n");
				}
            	else
            	{
            		pausa("No se ha podido guardar la lista de empleados.\n");
            	}
            	break;

            case 9:
            	if(controller_saveAsBinary(PATHBIN,listaEmpleados))
            	{
            		pausa("La lista de empleados se guardo correctamente.\n");
            	}
            	else
				{
					pausa("No se ha podido guardar la lista de empleados.\n");
				}
            	break;

            case 10:
            	if(msjConfirm("Se perderán todos los cambios no guardados, ¿esta seguro?"))
            	{
            		ll_deleteLinkedList(listaEmpleados);
            		salir = 1;
            	}
            	break;

            default:
            	pausa("Opción incorrecta.\n");
            	break;
        }

    }while(!salir);
    return 0;
}
