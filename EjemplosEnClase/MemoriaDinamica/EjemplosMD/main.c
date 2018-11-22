#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int edadPersonaUno;

    ePersona * primerPersona;
    ePersona * segundaPersona;


    /** ACA ASIGNO A LAS PERSONAS HARDCODEO*/
    primerPersona = nuevaPersonaParametrizada(1, "Lucho", 18);
    segundaPersona = nuevaPersonaParametrizada(2, "Danni", 18);


    printf("\nACA MUESTRO LAS PERSONAS: \n");
    /** ACA MUESTRO LAS PERSONAS */
    printf("ID ---  NOMBRE  --- EDAD\n\n");
    mostrarPersona(primerPersona); //Llamamos a la funcion mostrarPersona recibe un puntero de la estructura ePersona
    mostrarPersona(segundaPersona);


    printf("\n\nACA MUESTRO LA EDAD DE LA PRIMER PERSONA: \n");
    /** ACA MUESTRO LA EDAD DE LA PRIMER PERSONA */
    edadPersonaUno = persona_getEdad(primerPersona);
    printf("La edad de la persona uno es: %d\n\n", edadPersonaUno);


    printf("\n\nACA SETEO LA EDAD DE LA PRIMER PERSONA Y LA MUESTRO: \n");
    /** ACA SETEO LA EDAD DE LA PRIMER PERSONA Y LA MUESTRO */
    persona_setEdad(primerPersona, 20);
    mostrarPersona(primerPersona);

    return 0;
} // end
