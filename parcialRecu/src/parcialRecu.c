/*
 ============================================================================
 Name        : parcialRecu.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

int main(void) {

	setbuf(stdout,NULL);
	int opcion;
	char salir;
	int error;
	int idNext=1;
	char path[50];

	LinkedList* listaEmpleados = ll_newLinkedList();
	if(listaEmpleados!=NULL)
		{
		   do{
			   if(utn_getNumeroEnteroConIntentos(&opcion, "\nIngrese una opcion\n 1-Cargar modo texto\n 2-Cargas modo binario\n "
					   "3-Alta\n 4-Modificacion\n 5-Baja\n 6-Listar\n 7-Ordenar\n 8-Inserta un empleado dado de baja en la lista de activos\n "
					   "9-Pasa a nueva lista un rango de empleados \n 10-Clonar lista\n"
					   " 11-Guardar modo texto\n 12-Guardar modo binario\n 13-Salir",
					   "ERROR ingrese una opcion entre 1-13 ", 1, 13, 5)==0)
			   {
					switch(opcion)
					{
						case 1:
							printf("\nCargar datos (modo texto)\n");//utilizacion de ll_IsEmpty, ll_clear
							ingresarPath(path);

							error=controller_loadFromText(path,listaEmpleados, &idNext);

							menuErrores(error, "ERROR hubo un problema\n", "Empleados cargados exitosamente\n", "ERROR hubo un problema para cargar el empleado\n",
												"ERROR hubo un problema en el parseo\n", "ERROR hubo un problema con el levantar datos\n", "ERROR hubo problema al abrir\n",
												"Datos no sobreescritos\n");
							break;

						case 2:
							printf(" Cargar datos (modo binario)\n");//utilizacion de ll_IsEmpty, ll_clear
							ingresarPath(path);
							error=controller_loadFromBinary(path,listaEmpleados,  &idNext);
							menuErrores(error, "ERROR hubo un problema\n", "Empleados cargados exitosamente\n", "ERROR hubo un problema para cargar el empleado\n",
												"ERROR hubo un problema en el parseo\n", "ERROR hubo un problema con el levantar datos\n", "ERROR hubo problema al abrir\n",
												"Datos no sobreescritos\n");
							break;





						case 11:
							printf(" Guardar datos (modo texto)\n");
							ingresarPath(path);
							error=controller_saveAsText(path, listaEmpleados);

							menuErrores(error, "ERROR hubo un problema\n", "Empleados guardados exitosamente\n", "ERROR hubo problema en el fprintf\n",
												"ERROR hubo problema en abrir el archivo\n", "Archivo no guardado. Datos no sobreescritos", " ", " ");
							break;

						case 12:
							printf(" Guardar datos (modo binario)\n");
							ingresarPath(path);
							error=controller_saveAsBinary(path, listaEmpleados);
							menuErrores(error, "ERROR hubo un problema\n", "Empleados guardados exitosamente\n", "ERROR hubo problema en el guardado\n",
												"ERROR hubo problema en abrir el archivo\n", "Archivo no guardado. Datos no sobreescritos", " ", " ");
							break;

						case 13:
							printf(" Salir\n");
							if(utn_getCaracterCorroboraDosCarac(&salir, "Desea salir? S/N\n", "ERROR Ingrese S para salir o N para quedarse", 's', 'n')==0)
							{
								if(salir=='s')
								{
									printf("Hasta luego\n");
								}
							}
							break;
					}
			   }

			}while(salir !='s');
		}

	   ll_deleteLinkedList(listaEmpleados);

	return EXIT_SUCCESS;
}
