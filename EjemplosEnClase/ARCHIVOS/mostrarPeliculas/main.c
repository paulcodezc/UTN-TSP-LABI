#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

// Se crea una estructura de acuerdo al archivo a abrir
typedef struct
{
    int id;
    char titulo[30];
    char genero[30];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[500];
}eMovie;


// Cargamos el contenido de nuestro archivo en la estructura que creamos
int init(eMovie *movie, int length)
{
    FILE *fp;
    int i = 0;

    if (movie != NULL && length > 0)
    {
        fp = fopen("pelicula.dat","rb");
        if(fp == NULL)
        {
            return 0;
        }
        else
        {
            while(!feof(fp))
            {
                fread(&movie[i],sizeof(eMovie),1,fp); // Leemos los datos y lo guardamos en la estructura
                i++;
            }
            fclose(fp);
            return 1;
        }
    }//if (movie != NULL && length > 0)
    return -1;
}


void mostrar(eMovie *movie, int length)
{
    int i;
    for(i=0;(movie+i)->duracion != 0 && i < length;i++)
    {
        printf("%d--%s\n",i+1,(movie+i)->titulo);
    }
}

int main()
{
    eMovie movie[SIZE] = {};

    if(init(movie,SIZE) == 0) // Si es cero significa que es NULL
    {
        printf("No se pudo encontrar el archivo pelicula.dat!\n\n");
    }

    mostrar(movie, SIZE);
    return 0;
}
