struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

/**\fn initEmployess
 * \brief	To indicate that all position in the array are empty,
*			this function put the flag (isEmpty) in TRUE in all
*			position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);


/**\fn addEmployee
 * \brief 	add in a existing list of employees the values received as parameters
* 			in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

void inputEmployeeName(Employee myEmployee);
void inputEmployeeLastName(Employee myEmployee);
void inputEmployeeSalary(Employee myEmployee);
void inputEmployeeSector(Employee myEmployee);

/*\fn findEmptyEmployee
 * \brief find the first empty position of an Employee array.
 * \param list Employee*: Employee array.
 * \param len int: length of array.
 * \return int Return (-1) if there are no empty elements in the array. Else, return index of first empty element.
 * */
int findEmptyEmployee(Employee* list, int len);


/**\fn findEmployeeById
 * \brief find an Employee by Id and returns the index position in array.
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*/
int findEmployeeById(Employee* list, int len,int id);




/**\fn removeEmployee
* \brief Remove a Employee by Id (put isEmpty Flag in 1)
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*/
int removeEmployee(Employee* list, int len, int id);


/**\fn sortEmployees
* \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortEmployees(Employee* list, int len, int order);

/**\fn orderEmployeesASC
* \brief Sort the elements in the array of employees by lastName & sector ASC
* \param list Employee*
* \param len int
* \return void
*/
void orderEmployeesASC (Employee* list, int len);


/**\fn orderEmployeesDESC
* \brief Sort the elements in the array of employees by lastName & sector DESC
* \param list Employee*
* \param len int
* \return void
*/
void orderEmployeesDESC (Employee* list, int len);

/**\fn printEmployees
* \brief print the content of employees array
* \param list Employee*
* \param length int
* \return int
*/
int printEmployees(Employee* list, int length);

/*\fn printEmployee
 * \brief print a Employee.
 * \param myEmployee Employee
 * \return void
 * */
void printEmployee(Employee myEmployee);
