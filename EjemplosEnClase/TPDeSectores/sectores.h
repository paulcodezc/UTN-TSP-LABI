#ifndef SECTORES_H_INCLUDED
#define SECTORES_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[51];
    int isEmpty;

}eSector;


void hardcodeoSectores(eSector lista[], int limite);

int elegirSector(eSector sectores[], int tam);

int buscarPorSector(eSector lista[], int limite, int sector);

void mostrarInitSectores(eSector lista[], int limite);


#endif // SECTORES_H_INCLUDED
