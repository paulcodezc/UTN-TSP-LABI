#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Constructores.h"
#include "CargaDeArchivos.h"
#include "utn.h"

int main()
{

    LinkedList* listaClientes = ll_newLinkedList();
    LinkedList* listaVentas = ll_newLinkedList();

   fMenu(listaClientes, listaVentas);

    return 0;
}
