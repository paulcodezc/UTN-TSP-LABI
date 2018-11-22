#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "menu.h"
#include "empleados.h"

#define LIBRE 0
#define OCUPADO 1



void initEmpleados(eEmpleado lista[], int limite)
{
    int i;

    for(i = 0 ; i < limite ; i++)
    {
        lista[i].isEmpty = LIBRE;
    }

}



void hardcodeoEmpleados(eEmpleado lista[], int limite)
{
    int i;

    eEmpleado nuevo[5] =
    {
        {1, "Juan", "Gomez", 'm', 10500.50, {12, 3, 2011}, 1, OCUPADO},
        {2, "Lucas", "Diaz", 'm', 12000.25, {3, 5, 1999}, 3, OCUPADO},
        {3, "Sofia", "Goux", 'f', 25000.80, {30, 2, 2002}, 2, OCUPADO},
        {4, "Jose", "Lopez", 'm', 14500, {14, 5, 2015}, 3, OCUPADO},
        {5, "Lucia", "Diaz", 'f', 21000, {23, 11, 2006}, 5, OCUPADO}

    };


    for(i = 0 ; i < limite ; i++)
    {
        lista[i] = nuevo[i];
    }

}

void mostrarInitEmpleados(eEmpleado lista[], int limite)
{
    int i;

    printf("\tInicializacion de Empleados\n");

    for(i = 0 ; i < limite ; i++)
    {
        printf("\n#%d ---> %d",i+1,lista[i].isEmpty);
    }

    wait();
    system("cls");
}


int buscarEspacioLibreE(eEmpleado lista[], int limite)
{
    int i;
    int retorno = -1; // Retorta -1 si no encontró un espacio

    for(i = 0 ; i < limite ; i++)
    {
        if(lista[i].isEmpty == LIBRE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


int mostrarEmpleados(eEmpleado lista[], int limite)
{
    int i, vacio = -1;
    int titulo = 0;


    for(i = 0 ; i < limite ; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            if(titulo == 0)
            {
                printf("LEGAJO  APELLIDO  NOMBRE  SEXO     SALARIO       FECHA INGRESO  IDSECTOR");
                titulo = -1;
            }
            printf("\n   %d  \t %s    %s     %c \t  $%.2f \t  %d/%d/%d \t  %d",lista[i].legajo, lista[i].apellido, lista[i].nombre, lista[i].sexo, lista[i].salary, lista[i].fIngreso.dia, lista[i].fIngreso.mes, lista[i].fIngreso.anio, lista[i].idSector);
            vacio = 0;
        }
    }

    if(vacio == -1)
    {
        printf(">>> NADA QUE MOSTRAR.\n\n");
        system("pause");
        system("cls");
    }

    return vacio;
}


int getFecha(int* inputD, int* inputM, int* inputA, char messageD[], char messageM[], char messageA[])
{
    int retorno = 0;

    // Variables string para comprobar que sea números y no letras
    char auxD[3];
    int validarD;
    char auxM[3];
    int validarM;
    char auxA[5];
    int validarA;

    // Variables para establecer mínimos y máximos permitidos en las fechas
    int maxDia = 31;
    int minDia = 1;
    int maxMes = 12;
    int minMes = 1;
    int maxAnio = 2018;
    int minAnio = 1990;

    // Variables para convertir los string a int
    int diaNumero;
    int mesNumero;
    int anioNumero;


    // Ingresamos y Validamos DIA
    printf("%s",messageD);
    fflush(stdin);
    gets(auxD);

    validarD = esEntero(auxD);
    diaNumero = atoi(auxD);

    while((diaNumero < minDia || diaNumero > maxDia) || validarD == 0)
    {
        printf("\nError... Para DIA solo se permiten numeros (1 al 31)\nRe%s ",messageD);
        fflush(stdin);
        gets(auxD);
        validarD = esEntero(auxD);
        diaNumero = atoi(auxD);
    }


    // Ingresamos y Validamos MES
    printf("%s",messageM);
    fflush(stdin);
    gets(auxM);

    validarM = esEntero(auxM);
    mesNumero = atoi(auxM);

    while((mesNumero < minMes || mesNumero > maxMes) || validarM == 0)
    {
        printf("\nError... Para MES solo se permiten numeros (1 al 12)\nRe%s ",messageM);
        fflush(stdin);
        gets(auxM);
        validarM = esEntero(auxM);
        mesNumero = atoi(auxM);
    }


    // Ingresamos y Validamos AÑO
    printf("%s",messageA);
    fflush(stdin);
    gets(auxA);

    validarA = esEntero(auxA);
    anioNumero = atoi(auxA);

    while((anioNumero < minAnio || anioNumero > maxAnio) || validarA == 0)
    {
        printf("\nError... Para ANIO solo se permiten numeros (1990 al 2018)\nRe%s ",messageA);
        fflush(stdin);
        gets(auxA);
        validarA = esEntero(auxA);
        anioNumero = atoi(auxA);
    }

    *inputD = diaNumero;
    *inputM = mesNumero;
    *inputA = anioNumero;

    return retorno;

}


int altaEmpleado(eEmpleado lista[], int limite, eSector sectores[], int limiteS)
{
    int retorno = -1;
    int r;
    int indice;
    eEmpleado aux;

    indice = buscarEspacioLibreE(lista, limite);

    if(indice == -1)
    {
        system("cls");
        printf("\tALTA DE EMPLEADOS\n\n");
        printf("\n>>> NO HAY ESPACIO DISPONIBLE\n");
        wait();
    }
    else
    {
        system("cls");
        printf("\tALTA DE EMPLEADOS\n\n");

        r = getStringV(aux.nombre, "Ingresa nombre: ", "Error", 0, 51);

        if( r == 0)
        {
            r = getStringV(aux.apellido, "Ingresa apellido: ", "Error", 0, 51);

            if( r == 0)
            {
                r = confirmaSexo(&aux.sexo, "Ingresa sexo [m/f]: ");

                if( r == 0)
                {
                    r = getFlotanteV(&aux.salary, "Ingresa salario: ", "Error");

                   if( r == 0)
                   {
                       printf("\n\n>>> FECHA DE INGRESO\n\n");
                       r = getFecha(&aux.fIngreso.dia, &aux.fIngreso.mes, &aux.fIngreso.anio, "ingresa dia: ","ingresa mes: ","ingresa anio: ");

                       if(r == 0)
                       {
                           aux.idSector = elegirSector(sectores, limiteS);
                           aux.legajo = buscarEspacioLibreE(lista, limite);
                           aux.legajo++;
                           aux.isEmpty = OCUPADO;

                           lista[indice] = aux;
                       }
                   }
                }
            }

        }

    }


    return retorno;
}



int buscarPorLegajo(eEmpleado lista[], int limite, int legajo)
{
    int i;
    for(i = 0 ; i < limite ; i++)
    {
        if(lista[i].legajo == legajo && lista[i].isEmpty == OCUPADO)
        {
            return i;
        }
    }
    return -1;
}


void mostrarUnEmpleado(eEmpleado lista[], int i)
{
    printf("\nLEGAJO:%d \nAPELLIDO: %s \nNOMBRE: %s\nSEXO: %c\nSALARIO: %.2f\nFECHA INGRESO: %d/%d/%d\nIDSECTOR: %d\n",lista[i].legajo, lista[i].apellido, lista[i].nombre, lista[i].sexo, lista[i].salary, lista[i].fIngreso.dia, lista[i].fIngreso.mes, lista[i].fIngreso.anio, lista[i].idSector);
}

int bajaEmpleado(eEmpleado lista[], int limite)
{
    int retorno;
    char confirma;
    int encontrado;

    system("cls");
    printf("\tBAJA EMPLEADO\n");


    int auxLegajo, flag;

    system("cls");
    printf("\tBAJA EMPLEADO\n\n");
    flag = mostrarEmpleados(lista, limite);

    if(flag != -1)
    {
        printf("\n\nIngrese legajo del empleado: ");
        scanf("%d",&auxLegajo);

        encontrado = buscarPorLegajo(lista, limite, auxLegajo);

        if(encontrado != -1)
        {
            printf("\n\n");
           mostrarUnEmpleado(lista, encontrado);
            do
            {
                printf("\n\nConfirma Baja? [S|N]: ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
            }
            while(confirma != 's' && confirma != 'n');

            if(confirma == 's')
            {
                lista[encontrado].isEmpty = LIBRE;
                retorno = 0;
            }
            else
            {
                printf("\n\n>>> SE AH CANCELADO LA BAJA\n");
                retorno = -1;
                wait();
            }
        }
        else
        {
            printf("\n\n\n>>> NO SE ENCONTRO EL LEGAJO EN EL SISTEMA\n\n");
            system("pause");
            system("cls");
        }

    }

    return retorno;
}


int modificarEmpleados(eEmpleado lista[], int limite, eSector sectores[], int limiteS)
{
    int retorno = -1;
    int hay;
    int encontrado;
    int auxLegajo;
    char auxSexo;
    int auxIDSector;
    float AuxSalario;
    char auxApellido[51];
    char auxNombre[51];
    int r, opcion;
    char confirma;
    int salir = 0;

    system("cls");
    printf("\tMODIFICAR EMPLEADO\n\n");
    hay = mostrarEmpleados(lista, limite);

    if(hay != -1)
    {
        printf("\n\nIngrese Legajo del Empleado: ");
        scanf("%d",&auxLegajo);

        encontrado = buscarPorLegajo(lista, limite, auxLegajo);

        if(encontrado != -1)
        {
            system("cls");
            printf("\tMODIFICAR EMPLEADO\n\n\n");
            mostrarUnEmpleado(lista, encontrado);
            do
            {
                printf("\n\nConfirma Modificacion? [S|N]: ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
            }
            while(confirma != 's' && confirma != 'n');

            if(confirma == 's')
            {
                do
                {
                    system("cls");
                    printf("\tMODIFICAR EMPLEADO\n\n");

                    printf("1- Modificar Apellido.\n");
                    printf("2- Modificar Nombre.\n");
                    printf("3- Modificar Sexo.\n");
                    printf("4- Modificar Salario.\n");
                    printf("5- Modificar Fecha de Ingreso.\n");
                    printf("6- Modificar Sector.\n");
                    printf("7- Salir.\n\n");
                    printf("Ingrese opcion: ");
                    scanf("%d",&opcion);
                    switch(opcion)
                    {
                    case 1:
                        r = getStringV(auxApellido,"\nIngresa nuevo Apellido: ", "\n>>> Error! superaste el largo del nombre\n",0,51);
                        if(r == 0)
                        {
                            strcpy(lista[encontrado].apellido, auxApellido);
                            salir = 1;
                            printf("\n\n>>> Se ha realizado la modificacion\n");
                            wait();
                            break;
                        }
                    case 2:
                        r = getStringV(auxNombre,"\nIngresa nuevo Nombre: ", "\n>>> Error! superaste el largo del nombre\n",0,51);
                        if(r == 0)
                        {
                            strcpy(lista[encontrado].nombre, auxNombre);
                            salir = 1;
                            printf("\n\n>>> Se ha realizado la modificacion\n");
                            wait();
                            break;
                        }
                    case 3:
                            r = confirmaSexo(&auxSexo, "Ingresa nuevo Sexo [m/f]: ");
                        if(r == 0)
                        {
                            lista[encontrado].sexo = auxSexo;
                            salir = 1;
                            printf("\n\n>>> Se ha realizado la modificacion\n");
                            wait();
                            break;
                        }
                    case 4:
                        r = getFlotanteV(&AuxSalario,"\nIngresa nuevo Salario: ", "\nError!\n");
                        if(r == 0)
                        {
                            lista[encontrado].salary = AuxSalario;
                            salir = 1;
                            printf("\n\n>>> Se ha realizado la modificacion\n");
                            wait();
                            break;
                        }
                    case 5:
                        printf("\n>>> FECHA DE INGRESO\n\n");
                        r = getFecha(&lista[encontrado].fIngreso.dia, &lista[encontrado].fIngreso.mes, &lista[encontrado].fIngreso.anio, "ingresa nuevo dia: ", "ingresa nuevo mes: ", "ingresa nuevo anio: ");
                        if(r == 0)
                        {
                            salir = 1;
                            printf("\n\n>>> Se ha realizado la modificacion\n");
                            wait();
                            break;
                        }
                    case 6:
                        auxIDSector = elegirSector(sectores, limiteS);
                        r =  buscarPorSector(sectores, limiteS, auxIDSector);

                        if(r == 0)
                        {
                            salir = 1;
                            lista[encontrado].idSector = auxIDSector;
                            printf("\n\n>>> Se ha realizado la modificacion\n");
                            wait();
                            break;
                        }else if(r == -1)
                        {
                            salir = 1;
                            printf("\n\n>>> EL IDSECTOR NO EXISTE\n");
                            wait();
                            break;
                        }
                    case 7:
                        printf("\n\n>>> SALIENDO DEL SISTEMA...");
                        wait();
                        salir = 1;
                        break;
                    }
                }
                while(salir != 1);
            }
            else
            {
                printf("\n\n>>> Se ha cancelado la modificacion\n");
                wait();
            }

        }
        else
        {
            printf("\n\n\n>>> NO SE ENCONTRO EL IDSECTOR EN EL SISTEMA\n\n");
            system("pause");
            system("cls");
        }

    }
    return retorno;
}



int ordenarXApellidoYNombre(eEmpleado lista[], int limite) // Importe (descendente) - Descripcion (Ascendente)
{
    int retorno = -1;
    int i, j;
    eEmpleado aux;

    for(i=0; i<limite -1; i++)
    {
        for(j = i+1 ; j < limite; j++)
        {
            if( strcmp(lista[i].apellido, lista[j].apellido) > 0)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
            else if((strcmp(lista[i].apellido, lista[j].apellido) == 0) && strcmp(lista[i].nombre, lista[j].nombre) > 0)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
                retorno = 0;
            }
        }
    }


    return retorno;
}


void listarEmpleados(eEmpleado lista[], int limite)
{
    int r;

    system("cls");
    printf("\tLISTAR EMPLEADOS\n\n");
    printf("Ordenados por apellido (ascendente) y nombre (ascendente)\n\n");
    ordenarXApellidoYNombre(lista, limite);
    r = mostrarEmpleados(lista, limite);

    if(r != -1)
    {
        wait();
    }
}
