#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include "funciones.h"

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[])
{
    int aux;

    printf("%s", message);
    scanf("%d", &aux);

    *input = aux;
    return 0;

}

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[])
{
    float aux;

    printf("%s", message);
    scanf("%f", &aux);

    *input = aux;
    return aux;

}

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[])
{
    char aux[50];

    printf("%s", message);
    fflush(stdin);
    gets(aux);

    strcpy(input,aux);
    return 0;
}
