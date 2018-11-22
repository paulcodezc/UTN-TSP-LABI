#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "negocio.h"
#include "Constructores.h"
#include "LinkedList.h"
#include "CargaDeArchivos.h"
#include "utn.h"

#define MAXCARACTERES 1024
#define ASC 1
#define DES 0

int fMenu(LinkedList* pArrayListClientes, LinkedList* pArrayListVentas)
{
    int option;

    printf("\t\tADMINISTRAR CLIENTES Y VENTAS\n");
    printf("*******************************************************************\n\n\n");
    printf("1. Administrar Clientes.\n");
    printf("2. Administrar Ventas.\n");
    printf("3. Informes\n");
    printf("4. Salir\n");
    printf("\nIngresa una opcion: ");
    scanf("%d", &option);

    switch(option)
    {
    case 1:
        fMenuClientes(pArrayListClientes);
        break;
    case 2:
        fMenuVentas(pArrayListVentas);
        break;
    }

    return option;
}

int fMenuClientes(LinkedList* pArrayListClientes)
{
    int option;
    int flag = 1;
    int flag2 = 1;
    char confirma;

    do
    {
        system("cls");
        printf("\t\tADMINISTRAR CLIENTES\n");
        printf("*******************************************************************\n\n\n");
        printf("1. Cargar datos desde el archivo dataCliente.csv (modo texto).\n");
        printf("2. Cargar datos desde el archivo dataClienteBin.csv (modo binario).\n");
        printf("3. Alta de cliente\n");
        printf("4. Modificar datos de cliente\n");
        printf("5. Baja de cliente\n");
        printf("6. Listar clientes\n");
        printf("7. Ordenar clientes\n");
        printf("8. Guardar los clientes en el archivo dataCliente.csv (modo texto).\n");
        printf("9. Guardar los clientes en el archivo dataClienteBin.csv (modo binario).\n");
        printf("10. Salir\n");
        printf("\nIngresa una opcion: ");
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            if(flag)
            {
                flag = 0;
                if(cargarArchClientesTexto("dataClientes.csv", pArrayListClientes) != -1)
                {
                    printf("\n\n>>> Datos cargados correctamente (modo texto)\n");
                    wait();
                }

            }
            else
            {
                system("cls");
                printf("\t\tCARGAR ARCHIVO EN MODO TEXTO\n\n\n>>> Los datos ya fueron cargados anteriormente, si desea volver a cargarlos\n>>> tome en cuenta que los cambios NO guardados se perderan!\n");
                do
                {
                    printf("\n>>> Desea cargar nuevamente el archivo?[S/N]: ");
                    fflush(stdin);
                    confirma = getche();
                    confirma = tolower(confirma);
                }
                while(confirma != 's' && confirma != 'n');
                if(confirma == 's')
                {
                    ll_deleteLinkedList(pArrayListClientes);
                    pArrayListClientes = ll_newLinkedList();
                    cargarArchClientesTexto("dataClientes.csv", pArrayListClientes);
                    printf("\n\n\n>>> Los datos fueron nuevamente cargados!");
                    wait();
                }
                else
                {
                    printf("\n\n\n>>> Cancelo la opcion de recargar los datos de los clientes!");
                    wait();
                }
            }
            break;
        case 2:
            if(flag2)
            {
                if(!(cargarArchClientesBinario("dataClientesBin.csv", pArrayListClientes)))
                {
                    printf("\n>>> No existe el archivo!\n");
                    wait();
                }
                else
                {
                    flag2 = 0;
                    printf("\n\n\n>>> Datos cargados correctamente (modo binario)\n");
                    wait();
                }
            }
            else
            {
                system("cls");
                printf("\t\tCARGAR ARCHIVO EN MODO BINARIO\n\n\n>>> Los datos ya fueron cargados anteriormente, si desea volver a cargarlos\n>>> tome en cuenta que los cambios NO guardados se perderan!\n");
                do
                {
                    printf("\n>>> Desea cargar nuevamente el archivo?[S/N]: ");
                    fflush(stdin);
                    confirma = getche();
                    confirma = tolower(confirma);
                }
                while(confirma != 's' && confirma != 'n');
                if(confirma == 's')
                {
                    ll_deleteLinkedList(pArrayListClientes);
                    pArrayListClientes = ll_newLinkedList();
                    cargarArchClientesBinario("dataClientesBin.csv", pArrayListClientes);
                    printf("\n\n\n>>> Los datos fueron nuevamente cargados!");
                    wait();
                }
                else
                {
                    printf("\n\n\n>>> Cancelo la opcion de recargar los datos de los clientes!");
                    wait();
                }
            }
            break;
        case 3:
            if(agregarCliente(pArrayListClientes) == 1)
            {
                printf("\n\n>>> El cliente fue dado de alta correctamente.");
                wait();
            }
            break;
        case 4:
            if(modificarCliente(pArrayListClientes) == 1)
            {
                printf("\n\n>>> El cliente fue modificado correctamente.");
                wait();
            }
            break;
        case 5:
            if(eliminarCliente(pArrayListClientes) == 1)
            {
                printf("\n\n>>> El cliente fue dado de baja correctamente.");
                wait();
            }
            break;
        case 6:
            if(listarClientes(pArrayListClientes))
            {
                wait();
            }
            break;
        case 7:
            if(ordenarClientes(pArrayListClientes) == 1)
            {
                printf("\n\n>>> Se ordeno correctamente.");
                wait();
            }
            break;
        case 8:
            if(flag == 0 || flag2 == 0)
            {
                if(guardarClientesComoTexto("dataClientes.csv", pArrayListClientes) == 1)
                {
                    printf("\n\n>>> Se Guardo correctamente (modo texto).");
                    wait();
                }
            }
            else
            {
                printf("\n\n>>> No hay ningun archivo cargado!");
                wait();
            }
            break;
        case 9:
            if(flag == 0 || flag2 == 0)
            {
                if(guardarClientesComoBinario("dataClientesBin.csv", pArrayListClientes) == 1)
                {
                    printf("\n\n>>> Se Guardo correctamente (modo binario).");
                    wait();
                }
            }
            else
            {
                printf("\n\n>>> No hay ningun archivo cargado!");
                wait();
            }
            break;
        case 10:
            printf("\n\n>>> Saliendo del sistema...\n\n");
            break;
        default:
            printf("\n\n>>> Opcion inexistente!\n");
            wait();
            break;
        }
    }
    while(option != 10);

    return 0;
}


/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/


int fMenuVentas(LinkedList* pArrayListVentas)
{
    int option;
    int flag = 1;
    int flag2 = 1;
    char confirma;

    do
    {
        system("cls");
        printf("\t\tADMINISTRAR VENTAS\n");
        printf("*******************************************************************\n\n\n");
        printf("1. Cargar datos desde el archivo dataVentas.csv (modo texto).\n");
        printf("2. Cargar datos desde el archivo dataVentasBin.csv (modo binario).\n");
        printf("3. Realizar una Venta\n");
        printf("4. Modificar datos de una Venta\n");
        printf("5. Baja de una Venta\n");
        printf("6. Listar Ventas\n");
        printf("7. Ordenar Ventas\n");
        printf("8. Guardar las ventas en el archivo dataVentas.csv (modo texto).\n");
        printf("9. Guardar las ventas en el archivo dataVentasBin.csv (modo binario).\n");
        printf("10. Salir\n");
        printf("\nIngresa una opcion: ");
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            if(flag)
            {
                flag = 0;
                if(cargarArchVentasTexto("dataVentas.csv", pArrayListVentas) != -1)
                {
                    printf("\n\n>>> Datos cargados correctamente (modo texto)\n");
                    wait();
                }

            }
            else
            {
                system("cls");
                printf("\t\tCARGAR ARCHIVO EN MODO TEXTO\n\n\n>>> Los datos ya fueron cargados anteriormente, si desea volver a cargarlos\n>>> tome en cuenta que los cambios NO guardados se perderan!\n");
                do
                {
                    printf("\n>>> Desea cargar nuevamente el archivo?[S/N]: ");
                    fflush(stdin);
                    confirma = getche();
                    confirma = tolower(confirma);
                }
                while(confirma != 's' && confirma != 'n');
                if(confirma == 's')
                {
                    ll_deleteLinkedList(pArrayListVentas);
                    pArrayListVentas = ll_newLinkedList();
                    cargarArchVentasTexto("dataVentas.csv", pArrayListVentas);
                    printf("\n\n\n>>> Los datos fueron nuevamente cargados!");
                    wait();
                }
                else
                {
                    printf("\n\n\n>>> Cancelo la opcion de recargar los datos de las ventas!");
                    wait();
                }
            }
            break;
        case 2:
            /*if(flag2)
            {
                if(!(cargarArchVentasBinario("dataVentasBin.csv", pArrayListVentas)))
                {
                    printf("\n>>> No existe el archivo!\n");
                    wait();
                }
                else
                {
                    flag2 = 0;
                    printf("\n\n\n>>> Datos cargados correctamente (modo binario)\n");
                    wait();
                }
            }
            else
            {
                system("cls");
                printf("\t\tCARGAR ARCHIVO EN MODO BINARIO\n\n\n>>> Los datos ya fueron cargados anteriormente, si desea volver a cargarlos\n>>> tome en cuenta que los cambios NO guardados se perderan!\n");
                do
                {
                    printf("\n>>> Desea cargar nuevamente el archivo?[S/N]: ");
                    fflush(stdin);
                    confirma = getche();
                    confirma = tolower(confirma);
                }
                while(confirma != 's' && confirma != 'n');
                if(confirma == 's')
                {
                    ll_deleteLinkedList(pArrayListVentas);
                    pArrayListVentas = ll_newLinkedList();
                    cargarArchVentasBinario("dataVentasBin.csv", pArrayListVentas);
                    printf("\n\n\n>>> Los datos fueron nuevamente cargados!");
                    wait();
                }
                else
                {
                    printf("\n\n\n>>> Cancelo la opcion de recargar los datos de las ventas!");
                    wait();
                }
            }
            break;*/
        case 3:
            /*if(agregarVenta(pArrayListVentas) == 1)
            {
                printf("\n\n>>> La venta fue realizada correctamente.");
                wait();
            }
            break;*/
        case 4:
            /*if(modificarVenta(pArrayListVentas) == 1)
            {
                printf("\n\n>>> La venta fue modificada correctamente.");
                wait();
            }
            break;*/
        case 5:
            /*if(eliminarVenta(pArrayListVentas) == 1)
            {
                printf("\n\n>>> La venta fue dada de baja correctamente.");
                wait();
            }
            break;*/
        case 6:
            /*if(listarVentas(pArrayListVentas))
            {
                wait();
            }
            break;*/
        case 7:
            /*if(ordenarVentas(pArrayListVentas) == 1)
            {
                printf("\n\n>>> Se ordeno correctamente.");
                wait();
            }
            break;*/
        case 8:
            /*if(flag == 0 || flag2 == 0)
            {
                if(guardarVentasComoTexto("dataVentas.csv", pArrayListVentas) == 1)
                {
                    printf("\n\n>>> Se Guardo correctamente (modo texto).");
                    wait();
                }
            }
            else
            {
                printf("\n\n>>> No hay ningun archivo cargado!");
                wait();
            }*/
            break;
        case 9:
            /*if(flag == 0 || flag2 == 0)
            {
                if(guardarVentasComoBinario("dataVentasBin.csv", pArrayListVentas) == 1)
                {
                    printf("\n\n>>> Se Guardo correctamente (modo binario).");
                    wait();
                }
            }
            else
            {
                printf("\n\n>>> No hay ningun archivo cargado!");
                wait();
            }*/
            break;
        case 10:
            printf("\n\n>>> Saliendo del sistema...\n\n");
            break;
        default:
            printf("\n\n>>> Opcion inexistente!\n");
            wait();
            break;
        }
    }
    while(option != 10);

    return 0;
}



int agregarCliente (LinkedList* pArrayListClientes)
{
    eCliente* cliente;
    int retorno = 1;
    int auxId;
    char bufferId[MAXCARACTERES];
    char bufferNombre[MAXCARACTERES];
    char bufferApellido[MAXCARACTERES];

    system("cls");
    printf("\tALTA DE CLIENTE\n\n");

    // Pedimos todos datos del cliente a dar de alta
    auxId = getIDV(pArrayListClientes, "ingresa ID: ");
    itoa(auxId,bufferId,10);

    if(retorno)
    {
        if((retorno = getStringV(bufferNombre,"ingresa nombre: ","hubo un error",0, MAXCARACTERES)) != -1)
        {
            if((retorno = getStringV(bufferApellido,"ingresa apellido: ","hubo un error",0, MAXCARACTERES)) != -1)
            {
                if((cliente = cliente_newParametros(bufferId, bufferNombre, bufferApellido)) != NULL)
                {
                    ll_add(pArrayListClientes, cliente);
                    retorno = 1;
                }
            }
            else
            {
                retorno = 0;
            }
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}

int listarClientes(LinkedList* pArrayListClientes)
{
    eCliente* cliente;
    int retorno = -1;
    int cant;
    int i;

    system("cls");
    printf("\t\tLISTA DE CLIENTES\n\n");

    cant = ll_len(pArrayListClientes);

    if(pArrayListClientes != NULL && cant > 0)
    {
        printf("%5s %15s %16s\n", "ID","NOMBRE","APELLIDO");
        for(i=0; i < cant; i++)
        {
            cliente= ll_get(pArrayListClientes, i);
            printf("%4d %16s %16s \n", cliente->id, cliente->nombre, cliente->apellido);
        }
        retorno = 1;
    }
    else
    {
        system("cls");
        printf("\t\tLISTA DE CLIENTES\n\n");
        printf(">>> No hay ningun archivo cargado!");

    }
    return retorno;
}


int modificarCliente(LinkedList* pArrayListCliente)
{
    int idModificar;
    int opc, auxId, cant, retorno;
    char bufferNombre[MAXCARACTERES];
    char bufferApellido[MAXCARACTERES];

    eCliente *clienteEncontrado;
    clienteEncontrado = cliente_new();

    cant = ll_len(pArrayListCliente);

    if(pArrayListCliente != NULL && cant > 0)
    {
        system("cls");
        printf("\t\tMODIFICAR CLIENTE\n");

        listarClientes(pArrayListCliente);
        printf("\nIngrese el id del cliente a modificar: ");
        scanf("%d",&idModificar);

        // Buscamos si existe
        if((clienteEncontrado = cliente_searchID(pArrayListCliente, idModificar)) != NULL)
        {
            system("cls");
            printf("\t\tMODIFICAR CLIENTE\n\n");
            printf("CLIENTE encontrado: \n\n");
            printf("%4s %16s %16s\n", "ID","NOMBRE","APELLIDO");
            printf("%4d %16s %16s", clienteEncontrado->id, clienteEncontrado->nombre, clienteEncontrado->apellido);
            printf("\n\n\n1- Modificar ID");
            printf("\n2- Modificar Nombre");
            printf("\n3- Modificar Apellido");
            printf("\n4- Volver al menu");
            printf("\n\nIngrese opcion: ");
            scanf("%d",&opc);
            fflush(stdin);
            printf("\n*********************************************************************\n\n");

            switch(opc)
            {
            case 1:
                auxId = getIDV(pArrayListCliente, "ingresa nuevo ID: ");
                cliente_setId(clienteEncontrado, auxId);
                retorno = 1;
                break;
            case 2:
                getStringV(bufferNombre,"ingresa nuevo nombre: ","hubo un error",0, MAXCARACTERES);
                cliente_setNombre(clienteEncontrado, bufferNombre);
                retorno = 1;
                break;
            case 3:
                getStringV(bufferApellido,"ingresa nuevo apellido: ","hubo un error",0, MAXCARACTERES);
                cliente_setApellido(clienteEncontrado, bufferApellido);
                retorno = 1;
                break;
            case 4:
                printf("\n>>> Volviendo al menu principal!");
                retorno = 0;
                wait();
                break;
            default:
                printf("\n>>> Opcion inexistente!\n");
                break;
            }
        }
        else
        {
            system("cls");
            printf("\t\tMODIFICAR CLIENTE\n");
            printf("\n\n>>> El ID no se encuentra en el sistema!");
            wait();
        }
    }
    else
    {
        system("cls");
        printf("\t\tMODIFICAR CLIENTES\n");
        printf("\n>>> No hay ningun archivo cargado!");
        wait();
    }
    return retorno;
}


int eliminarCliente(LinkedList* pArrayListClientes)
{
    int idBaja;
    int cant, posicion, retorno = -1;
    char confirma;
    eCliente *clienteEncontrado;

    clienteEncontrado = cliente_new();
    cant = ll_len(pArrayListClientes);

    system("cls");
    printf("\t\tBAJA DE CLIENTE\n");

    if(pArrayListClientes!= NULL && cant > 0)
    {
        listarClientes(pArrayListClientes);
        printf("\nIngrese el id del cliente a dar de baja: ");
        scanf("%d",&idBaja);

        // Buscamos si existe
        if((clienteEncontrado = cliente_searchID(pArrayListClientes, idBaja)) != NULL)
        {
            system("cls");
            printf("\t\tBAJA CLIENTE\n\n");
            printf("Cliente encontrado: \n\n");
            printf("%5s %15s %15s\n", "ID","NOMBRE","APELLIDO");
            printf("%4d %16s %16s", clienteEncontrado->id, clienteEncontrado->nombre, clienteEncontrado->apellido);

            do
            {
                printf("\n\nConfirma Baja? [S|N]: ");
                fflush(stdin);
                confirma = getche();
                confirma = tolower(confirma);
            }
            while(confirma != 's' && confirma != 'n');

            if(confirma == 's')
            {
                posicion = ll_indexOf(pArrayListClientes, clienteEncontrado);
                ll_remove(pArrayListClientes, posicion);
                retorno = 1;
            }
            else
            {
                printf("\n\n>>> Cancelaste el dado de baja!");
                retorno = -1;
                wait();
                return retorno;
            }

        }
        else
        {
            system("cls");
            printf("\t\tBAJA CLIENTE\n");
            printf("\n\n>>> El ID no se encuentra en el sistema!");
            wait();
        }
    }
    else
    {
        system("cls");
        printf("\t\tBAJA EMPLEADO\n\n");
        printf(">>> No hay ningun archivo cargado!");
        wait();
    }

    return retorno;
}


int ordenarClientes(LinkedList* pArrayListClientes)
{
    int retorno = -1;
    int opc = 0, cant;

    cant = ll_len(pArrayListClientes);

    if(pArrayListClientes != NULL && cant > 0)
    {
        system("cls");
        printf("\t\tORDENAR CLIENTES\n");
        printf("\n1- Ordenar por Id(Creciente)");
        printf("\n2- Ordenar por Id(Decreciente)");
        printf("\n\n3- Ordenar por Nombre(Creciente)");
        printf("\n4- Ordenar por Nombre(Decreciente)");
        printf("\n\n5- Ordenar por Apellido (Creciente)");
        printf("\n6- Ordenar por Apellido (Decreciente)");
        printf("\n\n7- Volver al menu principal\n");
        printf("\nIngrese opcion: ");
        scanf("%d",&opc);

        switch(opc)
        {
        case 1:
            ll_sort(pArrayListClientes, cliente_sortById, ASC);
            retorno = 1;
            break;
        case 2:
            ll_sort(pArrayListClientes, cliente_sortById, DES);
            retorno = 1;
            break;
        case 3:
            ll_sort(pArrayListClientes, cliente_sortByNombre, ASC);
            retorno = 1;
            break;
        case 4:
            ll_sort(pArrayListClientes, cliente_sortByNombre, DES);
            retorno = 1;
            break;
        case 5:
            ll_sort(pArrayListClientes, cliente_sortByApellido, ASC);
            retorno = 1;
            break;
        case 6:
            ll_sort(pArrayListClientes, cliente_sortByApellido, DES);
            retorno = 1;
            break;
        case 7:
            printf("\n\n>>> Volviendo al menu principal...\n\n");
            wait();
            break;
        default:
            printf("\n>>> Opcion inexistente!\n");
            break;
        }
    }
    else
    {
        system("cls");
        printf("\t\tORDENAR CLIENTES\n");
        printf("\n>>> No hay ningun archivo cargado!");
        wait();
    }

    return retorno;
}

/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/


int realizarVenta (LinkedList* pArrayListVentas)
{
    eVenta* venta;
    int retorno = 1;
    int auxIdVenta;
    int auxIdCliente;
    float auxPrecio;

    system("cls");
    printf("\tREALIZAR VENTA\n\n");

    // Pedimos todos datos de la venta a realizar
    auxIdVenta = getIDV(pArrayListVentas, "ingresa ID de la Venta: ");
    itoa(auxIdVenta,bufferId,10);

    auxIdCliente = getIDV(pArrayListVentas, "ingresa ID del Cliente: ");
    itoa(auxIdCliente,bufferId,10);

    if((retorno = getFlotanteV(auxPrecio,"ingresa precio: ")) == 0)
            {
                if((venta = venta_newParametros(auxIdVenta, auxIdCliente, auxPrecio)) != NULL)
                {
                    ll_add(pArrayListVentas, venta);
                    retorno = 1;
                }
            }

    return retorno;
}

int listarVentas(LinkedList* pArrayListVentas)
{
    eVenta* venta;
    int retorno = -1;
    int cant;
    int i;

    system("cls");
    printf("\t\tLISTA DE VENTAS\n\n");

    cant = ll_len(pArrayListVentas);

    if(pArrayListVentas!= NULL && cant > 0)
    {
        printf("%5s %5s %8s\n", "IDVENTA","IDCLIENTE","PRECIO");
        for(i=0; i < cant; i++)
        {
            venta = ll_get(pArrayListVentas, i);
            printf("%5d %6d %8f \n", venta->idVenta, venta->idCliente, venta->precio);
        }
        retorno = 1;
    }
    else
    {
        system("cls");
        printf("\t\tLISTA DE VENTAS\n\n");
        printf(">>> No hay ningun archivo cargado!");

    }
    return retorno;
}


int modificarVenta(LinkedList* pArrayListVentas)
{
    int idModificar;
    int opc, auxIdVenta, cant, retorno;
    int auxIdCliente;
    float auxPrecio;

    eVenta *ventaEncontrado;
    VentaEncontrado = venta_new();

    cant = ll_len(pArrayListVentas);

    if(pArrayListVentas != NULL && cant > 0)
    {
        system("cls");
        printf("\t\tMODIFICAR VENTA\n");

        listarVentas(pArrayListVentas);
        printf("\nIngrese el id de la venta a modificar: ");
        scanf("%d",&idModificar);

        // Buscamos si existe
        if((ventaEncontrado = cliente_searchID(pArrayListVentas, idModificar)) != NULL)
        {
            system("cls");
            printf("\t\tMODIFICAR VENTA\n\n");
            printf("Venta encontrado: \n\n");
            printf("%4s %5s %8s\n", "IDVENTA","IDCLIENTE","PRECIO");
            printf("%4d %6d %8f", ventaEncontrado->idVenta, ventaEncontrado->idCliente, ventaEncontrado->precio);
            printf("\n\n\n1- Modificar ID Venta");
            printf("\n2- Modificar ID Cliente");
            printf("\n3- Modificar Precio");
            printf("\n4- Volver al menu");
            printf("\n\nIngrese opcion: ");
            scanf("%d",&opc);
            fflush(stdin);
            printf("\n*********************************************************************\n\n");

            switch(opc)
            {
            case 1:
                auxIdVenta = getIDV(pArrayListVentas, "ingresa nuevo ID Venta: ");
                venta_setIdVenta(ventaEncontrado, auxIdVenta);
                retorno = 1;
                break;
            case 2:
                auxIdCliente = getIDV(pArrayListVentas, "ingresa nuevo ID Cliente: ");
                venta_setIdCliente(ventaEncontrado, auxIdVenta);
                retorno = 1;
                break;
            case 3:
                getFlotanteV(auxPrecio,"ingresa nuevo Precio: ");
                auxPrecio = atof(auxPrecio);
                venta_setPrecio(ventaEncontrado, auxPrecio);
                retorno = 1;
                break;
            case 4:
                printf("\n>>> Volviendo al menu principal!");
                retorno = 0;
                wait();
                break;
            default:
                printf("\n>>> Opcion inexistente!\n");
                break;
            }
        }
        else
        {
            system("cls");
            printf("\t\tMODIFICAR CLIENTE\n");
            printf("\n\n>>> El ID no se encuentra en el sistema!");
            wait();
        }
    }
    else
    {
        system("cls");
        printf("\t\tMODIFICAR CLIENTES\n");
        printf("\n>>> No hay ningun archivo cargado!");
        wait();
    }
    return retorno;
}


int eliminarCliente(LinkedList* pArrayListClientes)
{
    int idBaja;
    int cant, posicion, retorno = -1;
    char confirma;
    eCliente *clienteEncontrado;

    clienteEncontrado = cliente_new();
    cant = ll_len(pArrayListClientes);

    system("cls");
    printf("\t\tBAJA DE CLIENTE\n");

    if(pArrayListClientes!= NULL && cant > 0)
    {
        listarClientes(pArrayListClientes);
        printf("\nIngrese el id del cliente a dar de baja: ");
        scanf("%d",&idBaja);

        // Buscamos si existe
        if((clienteEncontrado = cliente_searchID(pArrayListClientes, idBaja)) != NULL)
        {
            system("cls");
            printf("\t\tBAJA CLIENTE\n\n");
            printf("Cliente encontrado: \n\n");
            printf("%5s %15s %15s\n", "ID","NOMBRE","APELLIDO");
            printf("%4d %16s %16s", clienteEncontrado->id, clienteEncontrado->nombre, clienteEncontrado->apellido);

            do
            {
                printf("\n\nConfirma Baja? [S|N]: ");
                fflush(stdin);
                confirma = getche();
                confirma = tolower(confirma);
            }
            while(confirma != 's' && confirma != 'n');

            if(confirma == 's')
            {
                posicion = ll_indexOf(pArrayListClientes, clienteEncontrado);
                ll_remove(pArrayListClientes, posicion);
                retorno = 1;
            }
            else
            {
                printf("\n\n>>> Cancelaste el dado de baja!");
                retorno = -1;
                wait();
                return retorno;
            }

        }
        else
        {
            system("cls");
            printf("\t\tBAJA CLIENTE\n");
            printf("\n\n>>> El ID no se encuentra en el sistema!");
            wait();
        }
    }
    else
    {
        system("cls");
        printf("\t\tBAJA EMPLEADO\n\n");
        printf(">>> No hay ningun archivo cargado!");
        wait();
    }

    return retorno;
}


int ordenarClientes(LinkedList* pArrayListClientes)
{
    int retorno = -1;
    int opc = 0, cant;

    cant = ll_len(pArrayListClientes);

    if(pArrayListClientes != NULL && cant > 0)
    {
        system("cls");
        printf("\t\tORDENAR CLIENTES\n");
        printf("\n1- Ordenar por Id(Creciente)");
        printf("\n2- Ordenar por Id(Decreciente)");
        printf("\n\n3- Ordenar por Nombre(Creciente)");
        printf("\n4- Ordenar por Nombre(Decreciente)");
        printf("\n\n5- Ordenar por Apellido (Creciente)");
        printf("\n6- Ordenar por Apellido (Decreciente)");
        printf("\n\n7- Volver al menu principal\n");
        printf("\nIngrese opcion: ");
        scanf("%d",&opc);

        switch(opc)
        {
        case 1:
            ll_sort(pArrayListClientes, cliente_sortById, ASC);
            retorno = 1;
            break;
        case 2:
            ll_sort(pArrayListClientes, cliente_sortById, DES);
            retorno = 1;
            break;
        case 3:
            ll_sort(pArrayListClientes, cliente_sortByNombre, ASC);
            retorno = 1;
            break;
        case 4:
            ll_sort(pArrayListClientes, cliente_sortByNombre, DES);
            retorno = 1;
            break;
        case 5:
            ll_sort(pArrayListClientes, cliente_sortByApellido, ASC);
            retorno = 1;
            break;
        case 6:
            ll_sort(pArrayListClientes, cliente_sortByApellido, DES);
            retorno = 1;
            break;
        case 7:
            printf("\n\n>>> Volviendo al menu principal...\n\n");
            wait();
            break;
        default:
            printf("\n>>> Opcion inexistente!\n");
            break;
        }
    }
    else
    {
        system("cls");
        printf("\t\tORDENAR CLIENTES\n");
        printf("\n>>> No hay ningun archivo cargado!");
        wait();
    }

    return retorno;
}
