#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "LinkedList.h"
#include "SetYGet.h"


int main()
{
    int opcion;
    LinkedList* listaPersonas = ll_newLinkedList();

    do
    {
        system("cls");
        opcion = menu();

        switch(opcion)
        {
        case 1:
            agregarPersona(listaPersonas);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            mostrarPersonas(listaPersonas);
            break;
        case 5:
            break;
        default:
            printf("\nOpcion Inexistente!\n");
            system("pause");
        }
    }while(opcion != 5);

    return 0;
}


//Desarrollo de funciones

void agregarPersona(LinkedList* pListaDePersonas)
{
    Persona* auxPersona = Persona_new();

    system("cls");
    printf("\t>>> AGREGAR PERSONA >>>\n\n");

    printf("Ingresa nombre: ");
    scanf("%s",auxPersona->nombre);
    printf("Ingresa apellido: ");
    scanf("%s",auxPersona->apellido);
    printf("Ingresa edad: ");
    scanf("%d",&auxPersona->edad);
    printf("Ingresa dni: ");
    scanf("%d",&auxPersona->dni);
    printf("Ingresa sexo: ");
    auxPersona->sexo = getche();

    ll_add(pListaDePersonas, auxPersona);
}

void mostrarPersonas(LinkedList* pListaDePersonas)
{
    int i;
    Persona* auxPersona;

    system("cls");
    printf("\t>>> LISTA DE PERSONAS >>>\n\n");

    if(pListaDePersonas->size > 0)
    {
         printf("%15s %15s %5s %4s %5s\n", "NOMBRE","APELLIDO","EDAD","DNI", "SEXO");
        for(i = 0 ; i < pListaDePersonas->size ; i++)
        {
            auxPersona = ll_get(pListaDePersonas, i);
            printf("%15s %15s %6d %6d %5c\n",auxPersona->nombre, auxPersona->apellido, auxPersona->edad, auxPersona->dni, auxPersona->sexo);
        }

    system("pause");

    }else
    {
        printf("\n>>> No hay personas agregadas.\n\n\n");
        system("pause");
    }
}

int menu()
{
    int opc;

    printf("\t\t>>> ADMIN DE PERSONAS >>>\n\n");
    printf("1. Agregar persona\n2. Eliminar persona\n3. Modificar persona\n4. Mostrar Personas\n\n");
    printf("Ingresa opcion: ");
    scanf("%d",&opc);

    return opc;
}
