#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

char *getDynamicString(char *mensaje)
{
    char *pNuevo;
    char *aux;

    int len;

    printf("%s: ",mensaje);

    pNuevo = (char*) malloc(1024*sizeof(char));

    if(pNuevo != NULL)
    {
        gets(pNuevo);

        len = strlen(pNuevo);

        aux = (char*) realloc(pNuevo, sizeof(char)*(len+1));


        if(aux != NULL)
        {
            pNuevo = aux;
            return pNuevo;
        }

    }else
    {
        return NULL;
    }



return pNuevo;

}


int main()
{
    char *pNombre = getDynamicString("Ingresa tu nombre: ");

    if(pNombre != NULL)
    {
        printf("\nNombre correctamente!");
    }else
    {
        printf("\nERROR");
    }


    getch();
    return 0;
}

