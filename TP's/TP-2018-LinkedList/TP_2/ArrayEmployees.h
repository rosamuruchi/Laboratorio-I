#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

typedef struct
{
    int id;
    char descripcion[20];
} eSector;

int menu();

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length);

/** \brief Harcodea algunos empleados para poder hacer el tp
 *
 * \param list Employee*
 * \return void no devuelve nada
 *
 */
void harcodearEmpleados(Employee* list);

/** \brief busca el siguiente id libre de la lista
 *
 * \param list
 * \param lenght del List
 * \return devuelve el indice del siguiente id
 *
 */
int nextId (Employee* list, int len);
/** \brief corrobora si la inicializacion fue hecha
 *
 * \param list Employee*
 * \param len int
 * \return void no devuelve nada
 *
 */
void corroborarInicializacion(Employee* list, int len);
/** \brief busca un lugar libre de la lista
 *
 * \param list Employee*
 * \param len int
 * \return int devuelve el indice del lugar libre
 *
 */
int findEmployeeFree(Employee* list, int len); //buscarLugarLibre

/** \brief imprime un empleado buscado por Id
 *
 * \param list Employee*
 * \param len int
 * \param id int El id a buscar
 * \return void no devuelve nada
 *
 */
void printAEmployeeFound(Employee* list,int len,int id);
/** \brief busca el empleado por el salario dado
 *
 * \param list Employee*
 * \param len int
 * \param salary float salario a comparar
 * \return int devuelve el id del salario encontrado
 *
 */
int findEmployeeBySalary(Employee* list, int len,float salary);
/** \brief da de Alta a los empleados
 *
 * \param list
 * \param int len de la list
 * \return no devuelve nada
 *
 */
void altaEmpleados (Employee* list, int len);
/** \brief Modifica a los empleados name,last name,salary,
 *
 * \param list
 * \param int len de la list
 * \return no devuelve nada
 *
 */
void modificarEmpleados (Employee* list, int len);
/** \brief da de Baja a un empleado
 *
 * \param list
 * \param int len de la list
 * \return no devuelve nada
 *
 */
void bajaEmpleados (Employee* list, int len);

/** \brief Hace toda la recaudacion de empleados y promedios
 *
 * \param list Employee*
 * \param limite int
 * \return void no devuelve nada
 *
 */
void recaudacionTotal( Employee* list, int limite);
/** \brief es un submenu para el punto 4
 *
 * \param list employee
 * \param int len del Employee
 * \return no devuelve nada
 *
 */
void subMenuListados (Employee* list,int len);
