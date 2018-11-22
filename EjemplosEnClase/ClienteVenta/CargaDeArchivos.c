#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "negocio.h"
#include "utn.h"
#include "CargaDeArchivos.h"
#include "Constructores.h"


int parser_ClientesDesdeTexto(FILE* pFile, LinkedList* pArrayListClientes)
{

    eCliente* auxCliente;
    char id[31];
    char nombre[31];
    char apellido[31];
    int cant, retorno = 1;

    fscanf(pFile,"%[^,],%[^,],%[^\n]\n", id, nombre, apellido);

    while(!feof(pFile))
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id, nombre, apellido);

        if(cant == 3)
        {
            if((auxCliente = cliente_newParametros(id, nombre, apellido)) != NULL)
            {
                ll_add(pArrayListClientes, auxCliente);
            }
        }
        else if(cant != 3)
        {
            if(feof(pFile))
            {
                break;
            }
            else
            {
                printf("\nNo se pudo leer el ultimo archivo\n");
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}


int parser_ClientesDesdeBinario(FILE* pFile, LinkedList* pArrayListClientes)
{
    int retorno = 0;
    int cant;
    char auxId[8];
    char auxNombre[128];
    char auxApellido[128];

    eCliente* cliente;
    eCliente newClienteParam;

    while(!feof(pFile))
    {
        cant = fread(&newClienteParam, sizeof(eCliente), 1, pFile);

        if(cant == 1)
        {
            sprintf(auxId, "%d", newClienteParam.id);
            strncpy(auxNombre, newClienteParam.nombre, sizeof(auxNombre));
            strncpy(auxApellido, newClienteParam.apellido, sizeof(auxApellido));

            cliente = cliente_newParametros(auxId, auxNombre, auxApellido);

            ll_add(pArrayListClientes, cliente);

        }
        else if (cant != 1)
        {
            if(!feof(pFile))
            {
                printf("\n>>> No se puede leer el ultimo registro\n");
                system("pause");
                break;
            }
            else
            {
                retorno = 1;
                break;
            }
        }
    }

    return retorno;
}

int cargarArchClientesTexto(char* path, LinkedList* pArrayListClientes)
{
    FILE* pArch;
    int retorno = -1;

    if((pArch = fopen(path,"r")) == NULL)
    {
        printf("\n>>> Hubo un error al abrir el archivo!\n");
        wait();
        return retorno;
    }
    else
    {
        parser_ClientesDesdeTexto(pArch, pArrayListClientes);
        retorno = 1;

    }
    fclose(pArch);
    return retorno;
}


int cargarArchClientesBinario(char* path, LinkedList* pArrayListClientes)
{
    FILE* pArch;
    int retorno;
    int cant;

    cant = ll_len(pArrayListClientes);

    if((pArch = fopen(path,"rb")) == NULL)
    {
        retorno = 0;
        return retorno;
    }

    if( cant > 0)
    {
        ll_clear(pArrayListClientes);
    }

    if(parser_ClientesDesdeBinario(pArch, pArrayListClientes) == 1)
    {
        retorno = 1;
    }
    else
    {
        printf("Error de Archivo");
    }
    fclose(pArch);

    return retorno;
}




int guardarClientesComoTexto(char* path, LinkedList* pArrayListClientes)
{
    FILE* pArch;
    eCliente* auxCliente;
    int i, cant;

    cant = ll_len(pArrayListClientes);
    pArch = fopen(path,"w");

    if(pArch != NULL && pArrayListClientes != NULL)
    {
        rewind(pArch);
        fprintf(pArch,"id,nombre,apellido\n");

        for(i = 0 ; i < cant; i++)
        {
            auxCliente = ll_get(pArrayListClientes, i);
            fprintf(pArch,"%d,%s,%s\n", auxCliente->id, auxCliente->nombre, auxCliente->apellido);
        }

    }
    fclose(pArch);
    return 1;
}


int guardarClientesComoBinario(char* path, LinkedList* pArrayListClientes)
{
    FILE *pArch;
    eCliente *cliente;
    int i, cant, retorno = 1;

    cant = ll_len(pArrayListClientes);
    pArch = fopen(path, "wb");

    if(pArch != NULL)
    {
        for(i = 0 ; i < cant ; i++)
        {
            cliente = (eCliente*)ll_get(pArrayListClientes, i);

            fwrite(cliente, sizeof(eCliente), 1, pArch);
        }
    }

    fclose(pArch);

    return retorno;
}


/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/
/****************************************************************************************/


int parser_VentasDesdeTexto(FILE* pFile, LinkedList* pArrayListVentas)
{

    eVenta* auxVenta;
    char idVenta[31];
    char idCliente[31];
    char precio[31];
    int cant, retorno = 1;

    fscanf(pFile,"%[^,],%[^,],%[^\n]\n", idVenta, idCliente, precio);

    while(!feof(pFile))
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idVenta, idCliente, precio);

        if(cant == 3)
        {
            if((auxVenta = venta_newParametros(idVenta, idCliente, precio)) != NULL)
            {
                ll_add(pArrayListVentas, auxVenta);
            }
        }
        else if(cant != 3)
        {
            if(feof(pFile))
            {
                break;
            }
            else
            {
                printf("\nNo se pudo leer el ultimo archivo\n");
                retorno = 0;
                break;
            }
        }
    }

    return retorno;
}


int parser_VentasDesdeBinario(FILE* pFile, LinkedList* pArrayListVentas)
{
    int retorno = 0;
    int cant;
    char auxIdVenta[31];
    char auxIdCliente[31];
    char auxprecio[31];

    eVenta* venta;
    eVenta newVentaParam;

    while(!feof(pFile))
    {
        cant = fread(&newVentaParam, sizeof(eVenta), 1, pFile);

        if(cant == 1)
        {
            sprintf(auxIdVenta, "%d", newVentaParam.idVenta);
            sprintf(auxIdCliente, "%d", newVentaParam.idCliente);
            sprintf(auxprecio, "%f", newVentaParam.precio);

            venta = venta_newParametros(auxIdVenta, auxIdCliente, auxprecio);

            ll_add(pArrayListVentas, venta);

        }
        else if (cant != 1)
        {
            if(!feof(pFile))
            {
                printf("\n>>> No se puede leer el ultimo registro\n");
                system("pause");
                break;
            }
            else
            {
                retorno = 1;
                break;
            }
        }
    }

    return retorno;
}

int cargarArchVentasTexto(char* path, LinkedList* pArrayListVentas)
{
    FILE* pArch;
    int retorno = -1;

    if((pArch = fopen(path,"r")) == NULL)
    {
        printf("\n>>> Hubo un error al abrir el archivo!\n");
        wait();
        return retorno;
    }
    else
    {
        parser_VentasDesdeTexto(pArch, pArrayListVentas);
        retorno = 1;

    }
    fclose(pArch);
    return retorno;
}


int cargarArchVentasBinario(char* path, LinkedList* pArrayListVentas)
{
    FILE* pArch;
    int retorno;
    int cant;

    cant = ll_len(pArrayListVentas);

    if((pArch = fopen(path,"rb")) == NULL)
    {
        retorno = 0;
        return retorno;
    }

    if( cant > 0)
    {
        ll_clear(pArrayListVentas);
    }

    if(parser_VentasDesdeBinario(pArch, pArrayListVentas) == 1)
    {
        retorno = 1;
    }
    else
    {
        printf("Error de Archivo");
    }
    fclose(pArch);

    return retorno;
}




int guardarVentasComoTexto(char* path, LinkedList* pArrayListVentas)
{
    FILE* pArch;
    eVenta* auxVenta;
    int i, cant;

    cant = ll_len(pArrayListVentas);
    pArch = fopen(path,"w");

    if(pArch != NULL && pArrayListVentas != NULL)
    {
        rewind(pArch);
        fprintf(pArch,"idVenta,idCliente,precio\n");

        for(i = 0 ; i < cant; i++)
        {
            auxVenta = ll_get(pArrayListVentas, i);
            fprintf(pArch,"%d,%d,%f\n", auxVenta->idVenta, auxVenta->idCliente, auxVenta->precio);
        }

    }
    fclose(pArch);
    return 1;
}


int guardarVentasComoBinario(char* path, LinkedList* pArrayListVentas)
{
    FILE *pArch;
    eVenta *venta;
    int i, cant, retorno = 1;

    cant = ll_len(pArrayListVentas);
    pArch = fopen(path, "wb");

    if(pArch != NULL)
    {
        for(i = 0 ; i < cant ; i++)
        {
            venta = (eVenta*)ll_get(pArrayListVentas, i);

            fwrite(venta, sizeof(eVenta), 1, pArch);
        }
    }

    fclose(pArch);

    return retorno;
}
