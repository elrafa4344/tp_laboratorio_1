#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* puntero a archivo.
 * \param pArrayListEmployee LinkedList* puntero al arreglo de empleados.
* \return int ret -1 si el puntero pFile es NULL o el puntero pArrayListEmployee es NULL,
                   0 si logro cargar el archivo.
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ret = -1;
    char bufferId[400];
    char bufferNombre[400];
    char BufferHorasTrabajadas[400];
    char bufferSueldo[400];
    Employee *pAuxEmployee;


    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"\t%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,BufferHorasTrabajadas,bufferSueldo);
            pAuxEmployee = employee_newParametros(bufferId,bufferNombre,BufferHorasTrabajadas,bufferSueldo);
            if(pAuxEmployee != NULL)
            {
                ll_add(pArrayListEmployee, pAuxEmployee);
                ret = 0;
            }
        }
        fclose(pFile);
    }
    return ret;
}

/** \brief carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE* puntero a archivo.
 * \param pArrayListEmployee LinkedList* puntero al arreglo de empleados.
 * \return int ret -1 si pFile es NULL o pArrayListEmployee es NULL,
                    0 si logro cargar el archivo.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ret = -1;
    Employee auxEmployee;
    Employee* pEmployee= NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            pEmployee = employee_new();
            fread(&auxEmployee, sizeof(Employee), 1, pFile);
            if(!employee_setId(pEmployee, auxEmployee.id) &&
                    !employee_setNombre(pEmployee, auxEmployee.nombre) &&
                    !employee_setHorasTrabajadas(pEmployee, auxEmployee.horasTrabajadas) &&
                    !employee_setSueldo(pEmployee, auxEmployee.sueldo))
            {
                fread(&auxEmployee, sizeof(Employee), 1, pFile);
                if(pEmployee!= NULL)
                {
                    ll_add(pArrayListEmployee, pEmployee);
                    ret = 0;
                }

            }
            else
            {
                employee_delete(pEmployee);
            }

        }
        fclose(pFile);
    }
    return ret;
}




