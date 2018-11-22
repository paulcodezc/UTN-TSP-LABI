#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define ESC 27

typedef struct
{
    char nombre[31];
    int edad;
}ePersona;

int main()
{
    ePersona persona;
    ePersona persona2;
    FILE *pArch;
    int cantidad;

    if((pArch = fopen("cr7.dat","rb+")) == NULL)
    {
        printf("El archivo no existe...\n\n");
        system("pause");
        if((pArch = fopen("cr7.dat", "wb+")) == NULL)
        {
            printf("No se puede crear el archivo\n");
            exit(1);
        }
        system("cls");
        printf("El archivo fue creado con existo...\n");
        system("pause");
    }

    do
    {
        system("cls");
        printf("Ingresa nombre: ");
        fflush(stdin);
        gets(persona.nombre);


        printf("Ingresa edad: ");
        scanf("%d",&persona.edad);

        fseek(pArch,0L,SEEK_END);
        cantidad = fwrite(&persona, sizeof(ePersona), 1, pArch);

        if(cantidad != 1)
        {
            printf("Hubo un error");
            exit(2);
        }

        printf("\nESC para salir...");
    }while(getch() != ESC);

    printf("\n\n");
    rewind(pArch);

    while(!feof(pArch))
    {
        cantidad = fread(&persona2, sizeof(ePersona), 1, pArch);

        if(cantidad != 1)
        {
            if(feof(pArch))
            {
                break;
            }else
            {
                printf("No se pudo leer el ultimo archivo");
                break;
            }
        }

        printf("%s tiene %d anios\n",persona2.nombre, persona2.edad);
    }

    fclose(pArch);
    getch();
    return 0;
}
