#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char marca[20];
    int tipo;
    float peso;
}eVehiculo;

eVehiculo* new_vehiculo();
eVehiculo* new_vehiculoParam(char* idStr,char* marcaStr,char* tipoStr, char* pesoStr);
void employee_delete();

int vehiculo_setId(eVehiculo* this,int id);
int vehiculo_getId(eVehiculo* this,int* id);

int vehiculo_getMarca(eVehiculo this,char* marca);
int employee_getNombre(eVehiculo* this,char* nombre);

int vehiculo_setTipo(eVehiculo* this,int tipo);
int vehiculo_getTipo(eVehiculo* this,int* tipo);

int vehiculo_setPeso(eVehiculo* this,float peso);
int vehiculo_getPeso(eVehiculo this,float* peso);

int employee_mostrarEmpleado(eVehiculo* emp);
int employee_buscarMayorId(LinkedList* pArrayListEmployee, int* id);

eVehiculo* employee_buscarId(LinkedList* pArrayListEmployee, int tam, int id);

int employee_menuModificar(eVehiculo* empleado);
eVehiculo* employee_pedirIdyMostrar(LinkedList* pArrayListEmployee, int* indice);

int employee_empleadoCmpSueldo(void* a, void* b);
int employee_empleadoCmpHsTrab(void* a, void* b);
int employee_empleadoCmpNombre(void* a, void* b);

int menuErrores(int retorno, char* errorNegativo, char* error0, char* error1, char* error2, char* error3, char* error4, char* error5);
char* ingresarPath(char* path);

#endif // employee_H_INCLUDED
