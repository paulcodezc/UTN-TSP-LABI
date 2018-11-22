#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 2

int buscarLibre(int[], int);
void mostrarAlumnos(int[], char[][20], int[], int[], float[], int);
float calcularPromedio(int, int);
int cargarAlumno(int[], char[][20], int[], int[], float[], int);
void modificarAlumnos(int[], char[][20], int[], int[], float[], int);
void bajaAlumnos(int[], char[][20], int[], int[], float[], int);
void ordenadorAlumnos(int[], char[][20], int[], int[], float[], int);

int main()
{
    int legajo[TAM]= {};
    char nombre[TAM][20];
    int nota1[TAM];
    int nota2[TAM];
    float promedio[TAM];
    int opcion;
    int index;
    int i;
    do
    {
        printf("\n\n1. ALTAS\n2. MOSTRAR\n3. MODIFICAR\n4. BAJA\n5. ORDENAR (por nombre)\n9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            index=cargarAlumno(legajo, nombre, nota1, nota2, promedio, TAM);
            if(index == -1)
            {
                printf("\nNo hay lugar\n");
            }
            else
            {
                printf("\nAlumno ingresado\n");
            }
            break;
        case 2:

            mostrarAlumnos(legajo, nombre, nota1, nota2, promedio, TAM);

            break;
        case 3:

            modificarAlumnos(legajo, nombre, nota1, nota2, promedio, TAM);

            break;
        case 4:

            bajaAlumnos(legajo, nombre, nota1, nota2, promedio, TAM);

            break;
        case 5:

            ordenadorAlumnos(legajo, nombre, nota1, nota2, promedio, TAM);

            break;
        }

    }
    while(opcion!=9);




    return 0;
}

int buscarLibre(int legajos[], int tam)
{
    int index=-1;
    int i;

    for(i=0; i<tam ; i++)
    {
        if(legajos[i] == 0)
        {
            index = i;
            break;
        }
    }


    return index;
}

int buscarLegajo(int legajo[], int leg, int tam)
{
    int index = -1;
    int i;

    for(i=0 ; i<tam ; i++)
    {
        if(legajo[i] == leg)
        {
            index = i;
        }
    }

    return index;
}

int cargarAlumno(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int index;
    index = buscarLibre(legajos, tam);
    if(index!=-1)
    {
            printf("\nIngresa Legajo: ");
            scanf("%d",&legajos[index]);
            printf("Ingresa Nombre: ");
            fflush(stdin);
            gets(nombres[index]);
            printf("Ingresa Nota 1: ");
            scanf("%d",&nota1[index]);
            printf("Ingresa Nota 2: ");
            scanf("%d",&nota2[index]);

            promedio[index] = calcularPromedio(nota1[index], nota2[index]);
    }
    return index;
}


float calcularPromedio(int nota1, int nota2)
{
    float promedio;
    promedio = (float)(nota1+nota2)/2;
    return promedio;
}

void mostrarAlumnos(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int i;
    printf("\n\n");
    for(i=0; i<tam; i++)
    {
        if(legajos[i]!=0)
        {
            printf("%d %s %d %d %f\n", legajos[i], nombres[i], nota1[i], nota2[i], promedio[i] );
        }

    }

}



void modificarAlumnos(int legajo[], char nombre[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int index, leg;
    printf("\nIngresa el LEGAJO para MODIFICAR: ");
    scanf("%d",&leg);

    index = buscarLegajo(legajo, leg, tam);

    if(index != -1)
    {
            printf("\n\nIngresa los datos a MODIFICAR");
            printf("\nIngresa Legajo: ");
            scanf("%d",&legajo[index]);
            printf("Ingresa Nombre: ");
            fflush(stdin);
            gets(nombre[index]);
            printf("Ingresa Nota 1: ");
            scanf("%d",&nota1[index]);
            printf("Ingresa Nota 2: ");
            scanf("%d",&nota2[index]);

            promedio[index] = calcularPromedio(nota1[index], nota2[index]);
    }
    else
    {
        printf("\nNo se encontro el Legajo\n");
    }
}

void bajaAlumnos(int legajo[], char nombre[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int leg, index;
    printf("\n\nIngresa el LEGAJO para dar de BAJA: ");
    scanf("%d",&leg);
    index = buscarLegajo(legajo, leg, tam);

    if(index != -1)
    {
            legajo[index] = 0;
            strcmp(nombre[index], " ");
            nota1[index] = 0;
            nota2[index] = 0;
            promedio[index] = 0;
            printf("\n\nEl Alumno fue dado de BAJA\n");

    }
    else
    {
        printf("\nNo se encontro el Legajo\n");
    }
}

void ordenadorAlumnos(int legajo[], char nombre[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int i, j;
    char auxiliarChar[20];
    int auxiliarInt;
    float auxiliarProm;

    for(i=0 ; i<tam-1 ; i++)
    {
        for(j=i+1 ; j<tam ; j++)
        {
            if(strcmp(nombre[i], nombre[j]) > 0)
            {
                strcpy(auxiliarChar, nombre[i]);
                strcpy(nombre[i], nombre[j]);
                strcpy(nombre[j], auxiliarChar);

                auxiliarInt = legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = auxiliarInt;

                auxiliarInt = nota1[i];
                nota1[i] = nota1[j];
                nota1[j] = auxiliarInt;

                auxiliarInt = nota2[i];
                nota2[i] = nota2[j];
                nota2[j] = auxiliarInt;

                auxiliarProm = promedio[i];
                promedio[i] = promedio[j];
                promedio[j] = auxiliarProm;

                mostrarAlumnos(legajo, nombre, nota1, nota2, promedio,tam);
            }
        }
    }
}
