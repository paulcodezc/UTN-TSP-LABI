#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define LIBRE 1
#define OCUPADO 0

void init(EPersona lista[],int limite)
{
    int i;

        for(i = 0 ; i < limite ; i++)
        {
            lista[i].isEmpty = LIBRE;
        }
}

void mostrarInit(EPersona lista[], int limite)
{
	int i;

        printf("\tInicializacion\n");
	    for(i = 0 ; i < limite ; i++)
        {
            printf("\n#%d ---> %d",i+1,lista[i].isEmpty);
        }

    printf("\n\n");
    system("pause");
    system("cls");
}

void esperar()
{
    printf("\n");
    system("pause");
    system("cls");
}

int buscarEspacioLibre(EPersona lista[], int limite)
{
    int i;
    int retorno = -1; // Retorta -1 si no encontró un espacio

    for(i = 0 ; i < limite ; i++)
    {
        if(lista[i].isEmpty == LIBRE)
        {
            retorno = i; // Retorna el INDICE del espacio libre
            break;
        }
    }
    return retorno;
}


int esSoloLetras(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        return 0;
        i++;
    }
    return 1;
}

void getString(char mensaje[], char input[])
{
    printf(mensaje);
    fflush(stdin);
    gets(input);
}

int getStringLetras(char mensaje[], char input[]) //Necesitas de 2 funciones mas para usarla)
{
    char auxiliar[256];
    getString(mensaje, auxiliar); // (Se llama a la funcion de arriba)
    if(esSoloLetras(auxiliar))
    {
        strcpy(input, auxiliar);
        return 1;
    }

    return 0;
}

int buscarDNI(EPersona listado[], int limite, int dniaBuscar)
{
    int retorno = -1;
    int i;

    for(i = 0 ; i < limite ; i++)
    {
        if(listado[i].isEmpty == LIBRE && listado[i].dni == dniaBuscar)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int alta(EPersona lista[], int limite)
{
    int index;
    int comprobacion;
    int retorno = -1;

    system("cls");
    printf("\tALTA DE PERSONA\n\n");

    index = buscarEspacioLibre(lista, limite);

    if(index != -1)
    {
        comprobacion = getStringLetras("Ingresa el nombre: ", lista[index].nombre);
        while(comprobacion != 1)
        {
            comprobacion = getStringLetras("\n>>> Se aceptan solo numeros...Reingrese: ", lista[index].nombre);
        }

        comprobacion = getStringLetras("Ingresa el apellido: ", lista[index].apellido);
        while(comprobacion != 1)
        {
            comprobacion = getStringLetras("\n>>> Se aceptan solo numeros...Reingrese: ", lista[index].nombre);
        }

        // Me falta terminar de hacer el alta para poder usar la funcion de buscarDNI como filtro

        lista[index].isEmpty = OCUPADO;
        retorno = 1;
    }
    else
    {
        system("cls");
        printf("\tALTA DE PERSONA\n\n");
        printf("\n>>> NO HAY ESPACIO DISPONIBLE\n");
        esperar();
    }

    return retorno;
}

int mostrarPersonas(EPersona lista[], int len)
{
    int i, vacio = -1;

    for(i = 0 ; i < len ; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            printf("\n%s %s \tDNI: %ld \tFecha de nacimiento: %d/%d/%d",lista[i].apellido,lista[i].nombre,lista[i].dni,lista[i].feNac.dia,lista[i].feNac.mes,lista[i].feNac.anio);
            vacio = 0;
        }
    }

    if(vacio == -1)
    {
        printf("\nAun no hay personas\n\n");
        system("pause");
        system("cls");
    }



 return vacio;
}



int baja(EPersona lista[], int len)
{

    int dniAux, i, flag, encontro, retorno = -1;

    system("cls");
    printf("\tBORRAR PERSONA\n\n");
    flag = mostrarPersonas(lista, len);

    if(flag != -1)
    {
        printf("\n\nIngrese DNI: ");
        scanf("%d",&dniAux);

        for(i = 0 ; i < len ; i++)
        {
            if(dniAux == lista[i].dni)
            {
                lista[i].isEmpty = LIBRE;
                encontro = 0;
                printf("\n>>> %s %s fue dado de baja\n\n",lista[i].apellido, lista[i].nombre);
                system("pause");
                system("cls");
                break;
            }
        }

            if(encontro != 0)
        {
            printf("\n\n\n>>> NO SE ENCONTRO EL DNI\n\n");
            system("pause");
            system("cls");
        }
    }


}
