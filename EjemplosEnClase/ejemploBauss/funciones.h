#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

typedef struct
{
    char nombre[20];
    int legajo;
    float sueldo;
    int idSector;
    char sexo;
    int isEmpty;

}eEmpleado;

typedef struct
{
    int id;
    int descripcion[30];

}eSector;

int menu();
void init(eEmpleado lista[], int limite);
void mostrarInit(eEmpleado lista[], int limite);
int alta(eEmpleado lista[], int limite);

#endif // INPUT_H_INCLUDED
