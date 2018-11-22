#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    int edad;
    char nombre[50];
}ePersona;

ePersona* nuevaPersona();

ePersona* nuevaPersonaParametrizada(int, char*, int);

void mostrarPersona (ePersona*);

int persona_getEdad (ePersona*);

void persona_setEdad (ePersona*, int);
