#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* puntero al archivo a cargar
 * \param pArrayListEmployee LinkedList* puntero al arreglo de empleados.
 * \return int ret -1 si el puntero path es NULL o el puntero pArrayListEmployee es NULL,
                    0 si logra cargar los datos.
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int ret = -1;
    FILE* pFileAux = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFileAux = fopen(path, "r");
        if(pFileAux !=NULL)
        {
            if(!parser_EmployeeFromText(pFileAux, pArrayListEmployee))
            {
                printf("\tCARGA EXITOSA!\n");
                ret = 0;
            }
        }
    }
    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* puntero al archivo a cargar
 * \param pArrayListEmployee LinkedList* puntero al arreglo de empleados.
 * \return int ret -1 si el puntero path es NULL o el puntero pArrayListEmployee es NULL,
                    0 si logra cargar los datos.
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ret = -1;
    FILE* pFileAux = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFileAux = fopen(path, "rb");
        if(pFileAux !=NULL)
        {
            if(!parser_EmployeeFromBinary(pFileAux, pArrayListEmployee))
            {
                printf("\tCARGA EXITOSA!\n");
                ret = 0;
            }
        }
    }
    return ret;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* puntero al arreglo de empleados.
 * \return int ret -1 si no puede dar de alta un empleado por error en algun dato,
                    0 si logra dar de alta.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret = -1;
    Employee* pAuxEmpleado = employee_new();
    int bufferId;
    char bufferNombre[128];
    int bufferHorasTrabajas;
    int bufferSueldo;


    if(pAuxEmpleado!= NULL && pArrayListEmployee != NULL)
    {
        if(!getString(bufferNombre, "Ingrese Nombre: ", "Error al ingresar nombre. Reintente. ", 1, 128, 2) &&
                !getInt(&bufferHorasTrabajas, "Ingrese cantidad de horas trabajas: ", "Error al ingresar horas. Reintente ", 0,100,2) &&
                !getInt(&bufferSueldo, "Ingrese sueldo: ", "Error al ingresar sueldo. Reintente.", 1,100000,2))
        {
            employee_setNombre(pAuxEmpleado, bufferNombre);
            employee_setHorasTrabajadas(pAuxEmpleado, bufferHorasTrabajas);
            employee_setSueldo(pAuxEmpleado, bufferSueldo);
            bufferId = employee_lastId(pArrayListEmployee);
            employee_setId(pAuxEmpleado, bufferId);

            ll_add(pArrayListEmployee, pAuxEmpleado);
            ret=0;
            printf("\tCARGA EXITOSA!\n");
        }
        else
        {
            employee_delete(pAuxEmpleado);
        }
    }
    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* puntero al arreglo de empleados.
 * \return int ret -1 si no puede editar un empleado por error en algun dato,
                    0 si logra editar un empleado.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ret = -1;
    int bufferId;
    int posId;
    Employee* pAuxEmployee = NULL;
    int opcion;
    char bufferNombre[1000];
    int BufferHorasTrabajadas;
    int bufferSueldo;

    if(pArrayListEmployee != NULL)
    {
        if(!getInt(&bufferId,"Ingrese un ID a modificar: ", "Error reingresar ID:", 0, ll_len(pArrayListEmployee),2))
        {
            if(!Employee_findById(pArrayListEmployee, &posId, bufferId))
            {
                pAuxEmployee = ll_get(pArrayListEmployee, posId);
                if(pAuxEmployee!= NULL)
                {
                    do
                    {
                        getInt(&opcion, "Ingrese opcion a modificar:\n 1-Nombre.\n 2-Horas trabajadas.\n 3-Sueldo.\n 4-Salir de modificacion.\n", "Error. Debe ingresar una opcion valida", 1,4,2);
                        system("cls");
                    }
                    while (opcion<1 || opcion>4);

                    switch(opcion)
                    {
                    case 1:
                        if (!getString(bufferNombre,"Ingrese nuevo nombre del empleado: \n","Error, nombre no valido.\n",2,1000,2))
                        {
                            employee_setNombre(pAuxEmployee,bufferNombre);
                            printf("\nSe modifico el nombre.\n");
                            ret=0;
                        }
                        else
                            printf ("\nError al modificar el nombre.\n");
                        break;

                    case 2:
                        if (!getInt(&BufferHorasTrabajadas,"Ingrese nuevas horas trabajadas del empleado: \n","Error, horas no validas.\n",2,1000,2))
                        {
                            employee_setHorasTrabajadas(pAuxEmployee,BufferHorasTrabajadas);
                            printf("\nSe modificaron las horas trabajadas.\n");
                            ret=0;
                        }
                        else
                            printf ("\nError al modificar las horas trabajadas.\n");
                        break;
                    case 3:
                        if (!getInt(&bufferSueldo,"Ingrese nuevo sueldo del empleado: \n","Error, sueldo no valido.\n",2,1000000,2))
                        {
                            employee_setSueldo(pAuxEmployee,bufferSueldo);
                            printf("\nSe modifico el sueldo.\n");
                            ret=0;
                        }
                        else
                            printf ("\nError al modificar sueldo.\n");
                        break;
                    case 4:
                        break;

                    }
                }
            }
        }
    }
    return ret;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* puntero al arreglo de empleados.
 * \return int ret -1 si no puede eliminar un empleado,
                    0 si logra eliminar un empleado.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ret = -1;
    int bufferId;
    int posId;
    Employee* pAuxEmployee = NULL;

    if(pArrayListEmployee!= NULL)
    {
        if(!getInt(&bufferId,"Ingrese un ID a borrar: ", "Error al ingresar ID. Reintente", 0, ll_len(pArrayListEmployee),2))
        {
            if(!Employee_findById(pArrayListEmployee, &posId, bufferId))
            {
                pAuxEmployee = ll_pop(pArrayListEmployee, posId);
                if(pAuxEmployee!= NULL)
                {
                    employee_delete(pAuxEmployee);
                    printf("\nEMPLEADO DADO DE BAJA.\n\n");
                    ret = 0;
                }
            }
        }

    }
    return ret;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* puntero al arreglo de empleados.
 * \return int ret -1 si no puede mostar toda la lista de los empleados,
                    0 si logra mostar toda la lista de los empleados.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int ret = -1;
    Employee* pEmployee = NULL;
    char bufferId[1000];
    char bufferNombre[1000];
    char BufferHorasTrabajadas[1000];
    char bufferSueldo[100000];

    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        pEmployee = ll_get(pArrayListEmployee, i);
        if(pEmployee != NULL)
        {
            if(!employee_getIdStr(pEmployee, bufferId) &&
                    !employee_getNombre(pEmployee, bufferNombre) &&
                    !employee_getHorasTrabajadasStr(pEmployee, BufferHorasTrabajadas)&&
                    !employee_getSueldoStr(pEmployee, bufferSueldo))
            {
                printf("NOMBRE : %s ID: %s HORAS: %s SUELDO: %s\n", bufferNombre, bufferId, BufferHorasTrabajadas, bufferSueldo);
                ret = 0;
            }
        }

    }
    return ret;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* puntero al arreglo de empleados.
 * \return int ret -1 si no puede ordenar la lista de los empleados,
                    0 si logra ordenar la lista de los empleados.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ret = -1;

    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee, employee_compararPorNombre, 1);
        ret=0;
    }
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* puntero al archivo a guardar
 * \param pArrayListEmployee LinkedList* puntero al arreglo de empleados.
 * \return int ret -1 si el puntero si no puede guardar los datos,
 *                  0 si logra guardar los datos.
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int i;
    int ret = -1;
    FILE* pFileAux = NULL;
    Employee * pEmployee = NULL;
    char bufferId[1000];
    char bufferNombre[1000];
    char bufferHorasTrabajadas[1000];
    char bufferSueldo[100000];

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFileAux = fopen(path, "w");
        if(pFileAux != NULL)
        {
            for(i=0; i<ll_len(pArrayListEmployee); i++)
            {
                pEmployee = ll_get(pArrayListEmployee, i);
                if(!employee_getIdStr(pEmployee, bufferId) &&
                        !employee_getNombre(pEmployee,bufferNombre) &&
                        !employee_getHorasTrabajadasStr(pEmployee, bufferHorasTrabajadas) &&
                        !employee_getSueldoStr(pEmployee, bufferSueldo))
                {
                    fprintf(pFileAux, "%s, %s, %s, %s\n", bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
                    ret = 0;
                }
                else
                {
                    employee_delete(pEmployee);
                }
            }
        }
        fclose(pFileAux);
    }
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.scv (modo binario).
 *
 * \param path char* puntero al archivo a guardar
 * \param pArrayListEmployee LinkedList* puntero al arreglo de empleados.
 * \return int  ret -1 si el puntero si no puede guardar los datos,
 *                   0 si logra guardar los datos.
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int i;
    int ret = -1;
    FILE* pFileAux = NULL;
    Employee * pEmployee = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFileAux = fopen(path, "wb");
        if(pFileAux != NULL)
        {
            for(i =0 ; i<ll_len(pArrayListEmployee) ; i++)
            {
                pEmployee = ll_get(pArrayListEmployee, i);
                if(pEmployee != NULL)
                {
                    fwrite(pEmployee, sizeof(Employee), 1, pFileAux);
                }
            }
            ret = 0;
            fclose(pFileAux);
        }
    }
    return ret;
}



