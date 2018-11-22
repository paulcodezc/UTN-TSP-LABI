#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define ESC 27

typedef struct
{
    char nombre[31];
    char apellido[31];
    int edad;
} ePersona;

int main()
{
    ePersona nuevaPersona;
    FILE *pArch;
    int cantidad, auxEdad;

    if((pArch = fopen("lista.dat","rb+")) == NULL)
    {
        if( (pArch = fopen("lista.dat", "wb+")) == NULL)
        {
            printf("Hubo un error\n");
            exit(1);
        }
    }

    do
    {
        system("cls");
        printf("Ingresa nombre: ");
        fflush(stdin);
        gets(nuevaPersona.nombre);

        printf("Ingresa apellido: ");
        fflush(stdin);
        gets(nuevaPersona.apellido);

        printf("Ingresa edad: ");
        scanf("%d",&nuevaPersona.edad);

        fseek(pArch, 0L, SEEK_END);

        cantidad = fwrite(&nuevaPersona, sizeof(ePersona), 1, pArch);

        if(cantidad != 1)
        {
            printf("Hubo un error\n");
            exit(1);
        }

        printf("\n\nESC para salir...");
    }
    while(getch() != ESC);

    printf("\n\n");
    rewind(pArch);

    // Vamos a buscar y modificar una persona

    system("cls");
    printf("\tBusqueda por edad\n\n");
    printf("Ingresa edad a buscar: ");
    scanf("%d",&auxEdad);

    while(!feof(pArch))
    {
        cantidad = fread(&nuevaPersona, sizeof(ePersona), 1, pArch);

        if(cantidad != 1)
        {
            if(feof(pArch))
            {
                break;
            }
            else
            {
                printf("No se pudo leer el ultimo registro\n");
                break;
            }
        }

        if(nuevaPersona.edad == auxEdad)
        {
            printf("\nIngresa nuevo nombre: ");
            fflush(stdin);
            gets(nuevaPersona.nombre);

            printf("Ingresa nueva edad: ");
            scanf("%d",&nuevaPersona.edad);

            fseek(pArch,(long) (-1)*sizeof(ePersona), SEEK_CUR);
            cantidad = fwrite(&nuevaPersona,sizeof(ePersona), 1, pArch);

            if(cantidad != 1)
            {
                exit(1);
            }
            break;
        }

    }

    rewind(pArch);

    system("cls");

    while(!feof(pArch))
    {
        cantidad = fread(&nuevaPersona, sizeof(ePersona), 1, pArch);

        if(cantidad != 1)
        {
            if(feof(pArch))
            {
                break;
            }else
            {
                printf("Hubo un error en el ultimo registro\n");
                break;
            }
        }
        printf("%s %s tiene %d de edad\n",nuevaPersona.nombre, nuevaPersona.apellido, nuevaPersona.edad);
    }

    fclose(pArch);
    getch();
    return 0;
}
