#include <stdio.h>
#include <stdlib.h>

typedef struct
{
   char nombre[31];
   int edad;
}Epersona;


int main()
{
    Epersona auxiliar;
    int cant;
    FILE *p;

    p = fopen("pelota.dat", "rb");

    if(p == NULL)
    {
        exit(1);
    }
    while(!feof(p))
    {
        cant = fread(&auxiliar, sizeof(Epersona), 1, p);

        if(cant != 1)
        {
            if(feof(p))
					break;
				else
				{
					printf("No leyo el ultimo registro");
					break;
				}
        }
        printf("%s tiene %d de edad",auxiliar.nombre, auxiliar.edad);
        }

    fclose(p);


    return 0;
}
