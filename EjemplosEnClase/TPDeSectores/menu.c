#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "menu.h"

#define LIBRE 0
#define OCUPADO 1

int menu()
{
    int opcion;
    system("cls");
    printf("*** Menu del sistema ***\n\n");
    printf(">>> Menus\n1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- listar\n\n\n");

    printf(">>> Empleados\n5- Alta\n");
    printf("6- Baja\n");
    printf("7- Modificar\n");
    printf("8- listar\n\n\n");

    printf(">>> Almuerzos\n9- Alta\n");
    printf("10- Salir\n");


    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}



void wait()
{
    printf("\n\n\n");
    system("pause");
}


void hardcodeoMenus(eMenu lista[], int limite)
{
    int i;
    eMenu nuevo[10] =
    {
        {1,"Milanesas", 350.83, 1},
        {2,"Hamburguesa", 90.50, 1},
        {3,"Tortitas", 50.4, 1},
        {4,"Alverjas", 20.03, 1},
        {5,"Tomates", 85.90, 1},
        {6,"Verduras", 18.50, 1},
        {7,"Calamares", 85, 1},
        {8,"Ensalada", 35.10, 1},
        {9,"Milanesos", 350.83, 1},
        {10,"Berenjena", 13.60, 1}
    };

    for(i = 0 ; i < limite ; i++)
    {
        lista[i] = nuevo[i];
    }
}


void initMenu(eMenu lista[], int limite)
{
    int i;

    for(i = 0 ; i < limite ; i++)
    {
        lista[i].isEmpty = LIBRE;
    }

}

void mostrarInitMenu(eMenu lista[], int limite)
{
    int i;

    printf("\tInicializacion de Menus\n");

    for(i = 0 ; i < limite ; i++)
    {
        printf("\n#%d ---> %d",i+1,lista[i].isEmpty);
    }

    wait();
    system("cls");
}

int buscarEspacioLibreM(eMenu lista[], int limite)
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



int SiguienteID(eMenu lista[], int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && lista != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(lista[i].isEmpty == OCUPADO)
            {
                if(lista[i].codigo > retorno) // cambiar el codigo con el de la estructura
                {
                    retorno=lista[i].codigo;
                }

            }
        }
    }

    return retorno+1;
}

int mostrarMenus(eMenu lista[], int limite)
{
    int i, vacio = -1;
    int titulo = 0;


    for(i = 0 ; i < limite ; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            if(titulo == 0)
            {
                printf(" CODIGO  DESCRIPCION\t\tIMPORTE\n");
                titulo = -1;
            }
            printf("\n %d   \t %s\t\t$%.2f",lista[i].codigo, lista[i].descripcion, lista[i].importe);
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



int altaMenus(eMenu lista[], int limite)
{
    int retorno = -1;
    int r;
    int indice;
    eMenu aux;

    indice = buscarEspacioLibreM(lista, limite);

    if(indice == -1)
    {
        system("cls");
        printf("\tALTA DE MENUS\n\n");
        printf("\n>>> NO HAY ESPACIO DISPONIBLE\n");
        wait();
    }
    else
    {
        system("cls");
        printf("\tALTA DE MENUS\n\n");

        r = getStringV(aux.descripcion, "Ingresa descripcion: ", "Error", 0, 51);

        if( r == 0)
        {
            r = getFlotanteV(&aux.importe, "Ingresa importe: ", "Error");

            if( r == 0)
            {
                aux.codigo = buscarEspacioLibreM(lista, limite);
                aux.codigo++;
                aux.isEmpty = OCUPADO;
                retorno = 0;

                lista[indice] = aux;
            }

        }

    }


    return retorno;
}

int ordenarXImporteYDes(eMenu lista[], int limite) // Importe (descendente) - Descripcion (Ascendente)
{
    int retorno = -1;
    int i, j;
    eMenu aux;

    for(i=0; i<limite -1; i++)
    {
        for(j = i+1 ; j < limite; j++)
        {
            if( lista[i].importe < lista[j].importe)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
            else if( (lista[i].importe && lista[j].importe == 0) && strcmp(lista[i].descripcion, lista[j].descripcion) > 0)
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


void listarMenus(eMenu lista[], int limite)
{
    int r;
    system("cls");
    printf("\tLISTAR MENUS\n\n");
    printf("Ordenados por importe (descendente) y descripcion (ascendente)\n\n");
    ordenarXImporteYDes(lista, limite);
    r = mostrarMenus(lista, limite);

    if(r != -1)
    {
        wait();
    }

}

int buscarPorCodigo(eMenu lista[], int limite, int codigo)
{
    int i;
    for(i = 0 ; i < limite ; i++)
    {
        if(lista[i].codigo == codigo && lista[i].isEmpty == OCUPADO)
        {
            return i;
        }
    }
    return -1;
}


void mostrarUnMenu(eMenu menu[], int i)
{
    printf("CODIGO:%d  DESCRIPCION: %s     IMPORTE: $%.2f\n",menu[i].codigo, menu[i].descripcion, menu[i].importe);
}


int modificarMenus(eMenu lista[], int limite)
{
    int retorno = -1;
    int hay;
    int encontrado;
    int auxCodigo;
    float AuxImporte;
    char auxDes[51];
    int r, opcion;
    char confirma;
    int salir = 0;

    system("cls");
    printf("\tMODIFICAR MENUS\n\n");
    hay = mostrarMenus(lista, limite);

    if(hay != -1)
    {
        printf("\n\nIngrese Codigo del Menu: ");
        scanf("%d",&auxCodigo);

        encontrado = buscarPorCodigo(lista, limite, auxCodigo);

        if(encontrado != -1)
        {
            system("cls");
            printf("\tMODIFICAR MENU\n\n\n");
            mostrarUnMenu(lista, encontrado);
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
                    printf("\tMODIFICAR MENU\n\n");

                    printf("1- Modificar Descripcion.\n");
                    printf("2- Modificar Importe.\n");
                    printf("3- Salir.\n\n");
                    printf("Ingrese opcion: ");
                    scanf("%d",&opcion);
                    switch(opcion)
                    {
                    case 1:
                        r = getStringV(auxDes,"\nIngresa nuevo Descripcion: ", "\n>>> Error! superaste el largo del nombre\n",0,51);
                        if(r == 0)
                        {
                            strcpy(lista[encontrado].descripcion, auxDes);
                            salir = 1;
                            printf("\n\n>>> Se ha realizado la modificacion\n");
                            wait();
                            break;
                        }
                    case 2:
                        r = getFlotanteV(&AuxImporte,"\nIngresa nuevo Importe: ", "\nError!\n");
                        if(r == 0)
                        {
                            lista[encontrado].importe = AuxImporte;
                            salir = 1;
                            printf("\n\n>>> Se ha realizado la modificacion\n");
                            wait();
                            break;
                        }
                    case 3:
                        printf("\n>>> SALIENDO DEL SISTEMA");
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
            printf("\n\n\n>>> NO SE ENCONTRO EL CODIGO EN EL SISTEMA\n\n");
            system("pause");
            system("cls");
        }

    }
    return retorno;
}


int bajaMenus(eMenu lista[], int limite)
{
    int retorno;
    char confirma;
    int encontrado;

    system("cls");
    printf("\tBAJA MENU\n");


    int auxCodigo, flag;

    system("cls");
    printf("\tBAJA MENU\n\n");
    flag = mostrarMenus(lista, limite);

    if(flag != -1)
    {
        printf("\n\nIngrese Codigo del Menu: ");
        scanf("%d",&auxCodigo);

        encontrado = buscarPorCodigo(lista, limite, auxCodigo);

        if(encontrado != -1)
        {
            printf("\n\n");
           mostrarUnMenu(lista, encontrado);
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
            printf("\n\n\n>>> NO SE ENCONTRO EL CODIGO EN EL SISTEMA\n\n");
            system("pause");
            system("cls");
        }

    }


    return retorno;
}
