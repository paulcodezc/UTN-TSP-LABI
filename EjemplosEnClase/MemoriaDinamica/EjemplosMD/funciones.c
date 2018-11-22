#include "funciones.h"


/** \brief Crea un puntero de tipo estructura, le asigna memoria dinamica, inicializa a 0
           los campos de la estructura y devuelve la direccion del bloque creado
 *
 * \return miPersona la direccion de memoria del comienzo del bloque creado
 *
 */
ePersona* nuevaPersona()
{
    ePersona * miPersona; //crea un puntero de tipo ePersona
    miPersona = (ePersona*) malloc(sizeof(ePersona)); // Asigna memoria dinamica del tipo ePersona

    if (miPersona != NULL) // Comprueba que no haya errores al crear
    {
        miPersona->id = 0; // Inicializa
        miPersona->edad = 0; // Inicializa
        strcpy(miPersona->nombre, " "); // Inicializa
    }//end if

    return miPersona; // Devuelve la direccion de memoria del bloque creado
}


ePersona* nuevaPersonaParametrizada(int id, char* nombre, int edad)
{
    ePersona* miPersona;
    miPersona = nuevaPersona();
    if (miPersona != NULL)
    {
        miPersona->id = id;
        miPersona->edad = edad;
        strcpy(miPersona->nombre, nombre);
    }//end if

    return miPersona;
}//end



void mostrarPersona (ePersona* personaParametro)
{
    printf("%d ----- %s ----- %d\n\n", personaParametro->id, personaParametro->nombre, personaParametro->edad);
}//end



int persona_getEdad (ePersona* personaParametro)
{
    int edad;
    edad = personaParametro->edad;

    return edad;
}//end



void persona_setEdad (ePersona* personaParametro, int edad)
{
    personaParametro->edad = edad;
}//end
