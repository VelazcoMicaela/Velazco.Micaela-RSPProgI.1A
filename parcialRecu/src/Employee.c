#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "LinkedList.h"
#include "employee.h"
#include "Controller.h"



eVehiculo* new_vehiculo()
{
	eVehiculo* aux;

	aux= (eVehiculo*) malloc (sizeof(eVehiculo));
	if(aux!=NULL)
	{
		aux->id=0;
		strcpy( aux->marca, " ");
		aux->tipo=0;
		aux->peso=0;
	}

	return aux;
}

/*
int employee_mostrarEmpleado(eVehiculo* emp)
{
	int error=-1;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	if(emp!=NULL)
	{
		if(employee_getId(emp, &id)==0 &&
			employee_getNombre(emp, nombre)==0 &&
			employee_getHorasTrabajadas(emp, &horasTrabajadas)==0 &&
			employee_getSueldo(emp,&sueldo)==0)
		{
			printf("%4d %3d   %5d %.2f\n", id, horasTrabajadas, sueldo,nombre);
		}

		error=0;
	}
    return error;
}*/

int vehiculo_setId(eVehiculo* this,int id)
{
    int error=1;

    if(this!=NULL && id>0)
    {
        this->id=id;
        error=0;
    }

    return error;
}
int vehiculo_setMarca(eVehiculo* this,char* marca)
{
    int error=1;

    if(this!=NULL && strlen(marca)<100 && strlen(marca)>1 )
    {
        strcpy(this->marca,marca);
        error=0;
    }

    return error;
}
int vehiculo_setTipo(eVehiculo* this,int tipo)
{
    int error=1;

    if(this!=NULL && tipo>1 && tipo<100)
    {
        this->tipo=tipo;
        error=0;
    }

    return error;
}
int vehiculo_setPeso(eVehiculo* this,float peso)
{
    int error=1;

    if(this!=NULL && peso>1000 && peso<1000000)
    {
        this->peso=peso;
        error=0;
    }

    return error;
}

int vehiculo_getId(eVehiculo* this,int* id)
{
    int error=1;

    if(this!=NULL && id!=NULL)
    {
        id=this->id;
        error=0;
    }

    return error;
}
int vehiculo_getMarca(eVehiculo this,char* marca)
{
    int error=1;

    if(this!=NULL && marca!=NULL)
    {
        strcpy(marca,this->marca);
        error=0;
    }

    return error;
}
int vehiculo_getTipo(eVehiculo* this,int* tipo)
{
    int error=1;

    if(this!=NULL && tipo!=NULL)
    {
        tipo=this->tipo;
        error=0;
    }

    return error;
}
int vehiculo_getPeso(eVehiculo this,float* peso)
{
    int error=1;

    if(this!=NULL && peso!=NULL)
    {
        *peso=this->peso;
        error=0;
    }

    return error;
}

eVehiculo* new_vehiculoParam(char* idStr,char* marcaStr,char* tipoStr, char* pesoStr)
{
    eVehiculo* auxVehiculo;
    auxVehiculo=new_vehiculo();

    if(auxVehiculo!=NULL && idStr!=NULL && marcaStr!=NULL && tipoStr!=NULL && pesoStr!=NULL)
    {
        if(!(vehiculo_setId(auxVehiculo,atoi(idStr))==0
            &&vehiculo_setMarca(auxVehiculo,marcaStr)==0
            &&vehiculo_setTipo(auxVehiculo,atoi(tipoStr))==0
            &&vehiculo_setPeso(auxVehiculo,atof(pesoStr))==0))
        {
            free(auxVehiculo);
            auxVehiculo=NULL;
        }
    }

    return auxVehiculo;
}

////// EMPIEZAN SET ///////



int employee_buscarMayorId(LinkedList* pArrayListEmployee, int* id)
{
	int error=-1;
	eVehiculo* aux;
	int mayor=0;
	int i;

	//tam=ll_len(pArrayListEmployee);

	if(pArrayListEmployee!=NULL && id!=NULL)// tam>=0 &&
	{
		for(i=0; i<ll_len(pArrayListEmployee); i++)
		{
			aux=(eVehiculo*)ll_get(pArrayListEmployee, i);
			if(i==0 || aux->id > mayor)
			{
				mayor=aux->id;
			}
		}

		*id=mayor+1;
		error=0;
	}

	return error;
}


eVehiculo* employee_buscarId(LinkedList* pArrayListEmployee, int tam, int id)
{
	eVehiculo* aux=NULL;

	if(pArrayListEmployee!=NULL && tam>0 && id>0 )
	{
		for(int i=0; i<tam; i++)
		{
			aux=(eVehiculo*) ll_get(pArrayListEmployee, i);

			if(aux->id==id && aux!=NULL)
			{
				break;
			}
			else
			{
				aux=NULL;
			}
		}
	}

	return aux;
}
/*
eVehiculo* employee_pedirIdyMostrar(LinkedList* pArrayListEmployee, int* indice)
{
	int tam;
	eVehiculo* aux=NULL;
	int id;
	int idRaiz;

	if(pArrayListEmployee!=NULL && indice!=NULL)
	{
		employee_buscarMayorId(pArrayListEmployee, &idRaiz);

		if(controller_ListEmployee(pArrayListEmployee)==0 &&
				utn_getNumeroEnteroConIntentos(&id, "Ingrese el id del empleado ",
				"ERROR reingrese id ", 0, idRaiz, 5)==0)
		{
			tam= ll_len(pArrayListEmployee);

			aux= employee_buscarId(pArrayListEmployee, tam, id);
			if(aux!=NULL)
			{
				employee_mostrarEmpleado(aux);
				*indice=ll_indexOf(pArrayListEmployee, aux);
			}
		}
	}

	return aux;
}*/

int menuErrores(int retorno, char* errorNegativo,  char* error0, char* error1, char* error2, char* error3, char* error4, char* error5)
{
	int error=-1;

	if(errorNegativo!=NULL&& error0!=NULL&& error1!=NULL&& error2!=NULL&& error3!=NULL&& error4!=NULL&& error5!=NULL)
	{
		switch(retorno)
		{
			case -1:
				printf("%s",errorNegativo);
				break;

			case 0:
				printf("%s",error0);
				break;

			case 1:
				printf("%s",error1);
				break;

			case 2:
				printf("%s",error2);;
				break;

			case 3:
				printf("%s",error3);
				break;

			case 4:
				printf("%s",error4);
				break;

			case 5:
				printf("%s",error5);
				break;
		}

		error=0;
	}

	return error;
}

char* ingresarPath(char* path)
{
	if(path!=NULL)
	{
		printf("Ingrese Path_  \n");
		fflush(stdin);
		gets(path);

	}

	return path;
}


