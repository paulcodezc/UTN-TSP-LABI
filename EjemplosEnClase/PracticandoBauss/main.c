#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[31];
    float sueldo;
    int idSector;
    int isEmpty;

}eEmpleado;

typedef struct
{
    int id;
    char descripcion[31];

}eSector;

// Prototipos de funciones

void harcodearEmpleados(eEmpleado x[]);
void mostrarEmpleadosConSusSectores(eEmpleado empleados[], int tamEmpleados, eSector sectores[], int tamSectores);


// Empieza el MAIN
int main()
{
    int opc;

    eEmpleado nuevoEmpleado[5];
    eSector sectores[] =
    {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
    };
    harcodearEmpleados(nuevoEmpleado);



    printf("1- Mostrar empleados con su sector\n");
    scanf("%d",&opc);

    switch(opc)
    {
        case 1:
        mostrarEmpleadosConSusSectores(nuevoEmpleado, 7, sectores, 5);
        break;
    }




    return 0;
}



void harcodearEmpleados(eEmpleado x[])
{

    eEmpleado y[]=
    {
        {1111, "ana", 15000, 5, 1},
        {3333, "luis",  25000, 4, 1},
        {4444, "alberto", 10000, 5, 1},
        {5555, "julia", 30000, 1, 1},
        {1313, "julieta", 23000, 2, 1},
        {4545, "andrea",  31000, 5, 1},
        {3232, "mauro",  27000, 5, 1},
    };

    for(int i=0; i<7; i++)
    {
        x[i] = y[i];
    }

}


void mostrarEmpleadosConSusSectores(eEmpleado empleados[], int tamEmpleados, eSector sectores[], int tamSectores)
{
    printf("Hola\n");
}
