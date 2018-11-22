#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} Employee;


typedef struct
{
    int id;
    char descripcion[30];

}Sector;

// Acá van los prototipos
int menu();
void wait();

void initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector, int index);
int removeEmployee(Employee* list, int len, int id);
int findEmployeeById(Employee* list, int len, int auxID);
int printEmployees(Employee* list, int length);

void mostrarInit(Employee list[], int len);
int buscarEspacioLibre(Employee list[], int len);
int SiguienteID(Employee* list, int len);
int showEmployees(Employee* list, int len);
void showEmployee(Employee* list, int i);
void hardcodeo(Employee* list, int len);
int alta(Employee* list, int len);
int baja(Employee* list, int len);
int modificar(Employee* list, int len);

#endif // INPUT_H_INCLUDED
