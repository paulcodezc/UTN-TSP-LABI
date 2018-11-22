#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    char nombre[150];
    int edad;
} persona;

int main()
{
    int cant;
    persona nueva;
    FILE *puntero;

    puntero = fopen("abrime.dat", "wb");

    if(puntero == NULL)
    {
        exit(1);
    }

    do
    {
        printf("\nIngresa tu nombre: ");
        fflush(stdin);
        fgets(nueva.nombre, 31, stdin);

        printf("Ingresa tu edad: ");
        scanf("%d",&nueva.edad);


        cant = fwrite(&nueva, sizeof(persona), 1, puntero);

        if(cant != 1)
        {
            printf("Hubo un error");
            exit(1);
        }

        printf("El programa fue escrito correctamente!\n");
        printf("Para seguir escribiendo pulsa s: ");
    }
    while((getch())=='s');

    fclose(puntero);

    system("cls");
    puntero = fopen("abrime.dat","rb");
    if(puntero == NULL)
    {
        printf("Hubo algun error!");
        exit(1);
    }

    while(!feof(puntero))
    {
        cant = fread(&nueva, sizeof(nueva), 1, puntero);

        if(cant != 1)
        {


            if(feof(puntero))
            {
                break;
            }
            else
            {
                printf("Hubo un problema con el ultimo registro!");
                break;
            }
        }
        printf("\n%s %d",nueva.nombre, nueva.edad);
    }

    fclose(puntero);

    getch();
    return 0;
}
