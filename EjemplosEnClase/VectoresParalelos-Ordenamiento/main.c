#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

int buscarLibre(int[], int);
void mostrarAlumnos(int[], char[][20], int[], int[], float[], int);
float calcularPromedio(int, int);
int cargarAlumno(int[], char[][20], int[], int[], float[], int);
void ordenarXnombre(int[], char[][20], int[], int[], float[], int);

int main()
{
    int legajo[TAM]= {5, 8, 3, 1, 6};
    char nombre[TAM][20] = {"Samuel", "Esteban", "Armando", "Luciana", "Karina"};
    int nota1[TAM] = {2, 4, 6, 5, 4};
    int nota2[TAM] = {6, 8, 7, 3, 3};
    float promedio[TAM] = {3.5, 5.25, 5, 6.90, 9.5};
    int opcion;
    int index;
    //int i;
    do
    {
        printf("\n1. ALTAS\n2. MOSTRAR\n3. MODIFICAR\n4. BAJA\n5. ORDENAR (por nombre)\n9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            index=cargarAlumno(legajo, nombre, nota1, nota2, promedio, TAM);
            if(index == -1)
            {
                printf("No hay lugar");
            }
            else
            {
                printf("Alumno ingresado");
            }
            break;
        case 2:

            mostrarAlumnos(legajo, nombre, nota1, nota2, promedio, TAM);




            break;
        case 5:

            ordenarXnombre(legajo, nombre, nota1, nota2, promedio, TAM);

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

    for(i = 0 ; i < tam ; i++)
    {
        if(legajos[i] == 0)
        {
            index = 0;
        }
    }



    return index;
}

int cargarAlumno(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int index ;
    //int i;
    index = buscarLibre(legajos, tam);
    if(index!=-1)
    {
        /*for(i = 0; i < tam ; i++)
        {
            printf("\nIngresa legajo: ");
            scanf("%d",&legajos[i]);
            printf("Ingresa nombre: ");
            fflush(stdin);
            gets(nombres[i]);
            printf("Ingresa nota 1: ");
            scanf("%d",&nota1[i]);
            printf("Ingresa nota 2: ");
            scanf("%d",&nota2[i]);
            promedio[i] = calcularPromedio(nota1[i], nota2[i]);

        }*/
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
    printf("\n\nLEGAJO\t NOMBRE\t      NOTA1\t NOTA2 \t  PROMEDIO\n\n");
    for(i=0; i<tam; i++)
    {

        if(legajos[i]!=0)
        {
            printf("%d \t %s \t %d \t   %d \t  %.2f\n", legajos[i], nombres[i], nota1[i], nota2[i], promedio[i]);
        }

    }

}

void ordenarXnombre(int legajo[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int auxInt;
    char auxChar[20];
    float auxFlotante;
    int i, j;

    for(i = 0 ; i < tam-1 ; i++)
    {
        for(j = i+1 ; j < tam ; j++)
        {
            if (strcmp(nombres[i],nombres[j]) > 0)
            {
                strcpy(auxChar, nombres[i]);
                strcpy(nombres[i], nombres[j]);
                strcpy(nombres[j], auxChar);

                auxInt=legajo[i];
                legajo[i]=legajo[j];
                legajo[j]=auxInt;

                auxInt=nota1[i];
                nota1[i]=nota1[j];
                nota1[j]=auxInt;

                auxInt=nota2[i];
                nota2[i]=nota2[j];
                nota2[j]=auxInt;

                auxFlotante= promedio[i];
                promedio[i]= promedio[j];
                promedio[j]= auxFlotante;

            }
        }
    }

    printf("\n\nLEGAJO\t NOMBRE\t      NOTA1\t NOTA2\n\n");
    for(i=0; i<tam; i++)
    {

        if(legajo[i]!=0)
        {
            printf("%d \t %s \t %d \t   %d \t  %.2f\n", legajo[i], nombres[i], nota1[i], nota2[i], promedio[i]);
        }

    }

}
