#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char nombre[31];
  int edad;

}Epersona;

int main()
{
    int cant;
    Epersona auxiliar;
    FILE *punt;

    punt = fopen("pelota.dat","wb");

    if(punt == NULL)
    {
        exit(1);
    }

    printf("Ingresa nombre: ");
    fflush(stdin);
    scanf("%s",auxiliar.nombre);

    printf("Ingresa edad: ");
    scanf("%d",&auxiliar.edad);

    cant = fwrite(&auxiliar, sizeof(Epersona), 1, punt);

    if(cant != 1)
    {
        printf("hubo un error");
        exit(2);
    }

    fclose(punt);

    return 0;
}
