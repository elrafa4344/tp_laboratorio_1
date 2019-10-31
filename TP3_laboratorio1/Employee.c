#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "utn.h"
#include "LinkedList.h"

/** \brief Reserva espacio en memoria para un empleado
 * \param void vacio
 * \return Employee* un puntero al espacio reservado para cargar un empleado
 */
Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

/** \brief Valida los elementos que contiene un empleado y los carga en una variable Employee
 *
 * \param idStr char* id del empleado.
 * \param nombreStr char* nombre  del empleado.
 * \param horasTrabajadasStr char* horas trabajadas del empleado..
 * \param sueldo char* sueldo del empleado..
 * \return Employee* pAuxEmployee, devuelve - NULL si puntero a idStr/nombreStr/horasTrabajdasStr/sueldo NULL,
 *                                 devuelve - puntero al empleado si valido sus elementos.
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* pEmployee = employee_new();
    Employee* retorno = NULL;

    if(pEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        if(!employee_setIdStr(pEmployee, idStr) &&
                !employee_setNombre(pEmployee, nombreStr) &&
                !employee_setHorasTrabajadasStr(pEmployee, horasTrabajadasStr) &&
                !employee_setSueldoStr(pEmployee, sueldoStr))
        {
            retorno = pEmployee;
        }
        else
        {
            employee_delete(pEmployee);
        }
    }
    return retorno;
}

/** \brief Libera el espacio reservado en memoria para un empleado.
 *
 * \param Employee* this puntero al empleado
 * \return int retorno -1 si this NULL,
*                       0 si logro liberar el espacio reservado.
 *
 */
void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        return free(this);
    }
}

/** \brief Valida el elemento id del Empleado y lo carga en la estructura Employee
 *
 * \param this Employee* puntero al empleado
 * \param id int id del Empleado
 * \return int retorno -1 si no pudo validar el ID
 *                      0 si pudo validar y cargar el ID:
 *
 */
int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el id de un empleado.
 *
 * \param this Employee* puntero a empleado.
 * \param resultado int* id de Employee
 * \return int retorno -1 si this es NULL o id es NULL,
 *                      0 si se obtuvo el id.
 *
 */
int employee_getId(Employee* this,int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida el elemento nombre del Empleado y lo carga en la estructura Employee.
 *
 * \param this Employee* puntero al empleado.
 * \param nombre char* nombre del Empleado.
 * \return int retorno -1 si no pudo validar el nombre.
 *                      0 si pudo validar y cargar el nombre.
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el nombre de un empleado.
 *
 * \param this Employee* puntero a empleado.
 * \param resultado char* nombre de Employee
 * \return int retorno -1 si this es NULL o nombre es NULL,
 *                      0 si se obtuvo el nombre.
 *
 */
int employee_getNombre(Employee* this,char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->nombre);
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida el elemento horasTrabajadas del Empleado y lo carga en la estructura Employee
 *
 * \param this Employee* puntero al empleado
 * \param horasTrabajadas int horasTrabajadas del Empleado.
 * \return int retorno -1 si no pudo validar la/las horasTrabajadas.
 *                      0 si pudo validar y cargar la/las horasTrabajadas.
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene las horasTrabajadas de un empleado.
 *
 * \param this Employee* puntero a empleado.
 * \param resultado int* horasTrabajadas de Employee
 * \return int retorno -1 si this es NULL o id es NULL,
 *                      0 si se obtuvo las horasTrabajadas.
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida el elemento sueldo del Empleado y lo carga en la estructura Employee
 *
 * \param this Employee* puntero al empleado
 * \param sueldo int sueldo del Empleado.
 * \return int retorno -1 si no pudo validar el sueldo.
 *                      0 si pudo validar y cargar el sueldo.
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el sueldo de un empleado.
 *
 * \param this Employee* puntero a empleado.
 * \param resultado int* sueldo de Employee
 * \return int retorno -1 si this es NULL o id es NULL,
 *                      0 si se obtuvo el sueldo.
 *
 */
int employee_getSueldo(Employee* this,int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida el elemento id string del Empleado y lo carga en la estructura Employee.
 *
 * \param this Employee* puntero al empleado.
 * \param id char* id del Empleado.
 * \return int retorno -1 si no pudo validar el id.
 *                      0 si pudo validar y cargar el id.
 *
 */
int employee_setIdStr(Employee* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL && !validarNumero(id))//Valido que recibo un entero
    {
        retorno = employee_setId(this,atoi(id));
    }
    return retorno;
}

/** \brief Obtiene el id de tipo string de un empleado.
 *
 * \param this Employee* puntero a empleado.
 * \param resultado char* ID de Employee
 * \return int retorno -1 si this es NULL o ID es NULL,
 *                      0 si se obtuvo el ID.
 *
 */
int employee_getIdStr(Employee* this, char* resultado)
{
    int retorno = -1;
    int bufferInt; // para no usar el operador flecha
    if(this != NULL && resultado != NULL)
    {
        employee_getId(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida el elemento horasTrabajadas del Empleado de tipo string y lo carga en la estructura Employee.
 *
 * \param this Employee* puntero al empleado.
 * \param horasTrabajadas char* horasTrabajadas del Empleado.
 * \return int retorno -1 si no pudo validar la/las horasTrabajadas.
 *                      0 si pudo validar y cargar la/las horasTrabajadas.
 *
 */
int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL && !validarNumero(horasTrabajadas))//Valido que recibo un entero
    {
        retorno = employee_setHorasTrabajadas(this,atoi(horasTrabajadas));
    }
    return retorno;
}

/** \brief Obtiene las horasTrabajadas de tipo string de un empleado.
 *
 * \param this Employee* puntero a empleado.
 * \param resultado char* ID de Employee
 * \return int retorno -1 si this es NULL o ID es NULL,
 *                      0 si se obtuvo la/las HorasTrabajadas.
 *
 */
int employee_getHorasTrabajadasStr(Employee* this,char* resultado)
{
    int retorno = -1;
    int bufferInt; // para no usar el operador flecha
    if(this != NULL && resultado != NULL)
    {
        employee_getHorasTrabajadas(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida el elemento sueldo del ip Empleado y lo carga en la estructura Employee.
 *
 * \param this Employee* puntero al empleado.
 * \param sueldo char* sueldo del Empleado.
 * \return int retorno -1 si no pudo validar el sueldo.
 *                      0 si pudo validar y cargar el sueldo.
 *
 */
int employee_setSueldoStr(Employee* this,char* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL && !validarNumero(sueldo))//Valido que reciba un entero.
    {
        retorno = employee_setSueldo(this,atoi(sueldo));
    }
    return retorno;
}

/** \brief Obtiene el sueldo de tipo string de un empleado.
 *
 * \param this Employee* puntero a empleado.
 * \param resultado char* ID de Employee
 * \return int retorno -1 si this es NULL o ID es NULL,
 *                      0 si se obtuvo el sueldo.
 *
 */
int employee_getSueldoStr(Employee* this,char* resultado)
{
    int retorno = -1;
    int bufferInt; // para no usar el operador flecha
    if(this != NULL && resultado != NULL)
    {
        employee_getSueldo(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        retorno = 0;
    }
    return retorno;
}

/** \brief Compara entre dos nombres de la lista de empleados.
 *
 * \param this1 void* primer empleado.
 * \param this2 void* segundo empleado
 * \return int retorno: -1 si el segundo nombre es el mayor,
 *                       1 si el primer nombre es el mayor,
 *                       0 si son iguales.
 *
 */
int employee_compararPorNombre(void* this1, void* this2)
{
    char auxNombreA[4096];
    char auxNombreB[4096];

    employee_getNombre((Employee*)this1, auxNombreA);
    employee_getNombre((Employee*)this2, auxNombreB);


    if(strcmp(auxNombreA, auxNombreB) > 0)
    {
        return 1;
    }
    if(strcmp(auxNombreA, auxNombreB) < 0)
    {
        return -1;
    }
    return 0;
}

/** \brief Recorre la lista de empleados, busca el id maximo y lo incrementa en uno al retornarlo
 *
 * \param LinkedList* pArrayEmployee puntero al arreglo de empleados.
 * \return retunr el id maximo incrementado en uno.
 *
 */

int employee_lastId(LinkedList* pArrayListEmplyee)
{
    int i;
    int IdAux;
    int IdMax;
    Employee* pEmployee;

    if(pArrayListEmplyee != NULL)
    {
        for(i=0 ; i<ll_len(pArrayListEmplyee); i++)
        {
            pEmployee = ll_get(pArrayListEmplyee, i);
            if(pEmployee != NULL)
            {
                employee_getId(pEmployee, &IdAux);
                if(IdAux > IdMax)
                {
                    IdMax = IdAux;
                }
                else
                {
                    continue;
                }
            }
        }

    }
    return IdMax+1;
}

/** \brief busca la posicion en la que se encuentra un ID que solicita al usuario.
*
* \param LinkedList* pArrayEmployee puntero al arreglo de empleados.
* \param posicionId int* puntero al ID a buscar.
* \return int retorno -1 si pArrayEmployee NULL, si pEmployee es NULL, o el ID a buscar no existe en la lista.
*                      0 si encontro el ID buscado, y como parametro por referencia la posicion del mismo.
*
*/

int Employee_findById(LinkedList* pArrayListEmployee, int *posicionId, int id)
{
    int i;
    int ret = -1;
    int idAux;
    Employee *pEmployee = NULL;

    if(pArrayListEmployee != NULL && posicionId >= 0 && id >= 0)
    {
        for(i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            if(pEmployee != NULL)
            {
                employee_getId(pEmployee, &idAux);
                if(id == idAux)
                {
                    *posicionId = i;
                    ret = 0;
                }
            }
        }
    }
    return ret;
}









