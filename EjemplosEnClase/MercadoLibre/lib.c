#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"
#include "funciones.h"
#define TAMANIO 10
#define OCUPADO 1
#define LIBRE 0

int eUsuario_init(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado = LIBRE;
            listado[i].idGenerica= i;
        }
    }
    return retorno;
}

int eProducto_init(eProducto listadoP[],int limiteP)
{
    int retorno = -1;
    int i;
    if(limiteP > 0 && listadoP != NULL)
    {
        retorno = 0;
        for(i=0; i<limiteP; i++)
        {
            listadoP[i].estado = LIBRE;
            listadoP[i].idProducto = i;
        }
    }
    return retorno;
}

void hardcodeUsuarios(eUsuario listado[], int limite)
{
    int i;
    //Inicializar 10 nombres
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Lucia","Ana","Gisele","Dario","Lucio"};
    char pass[][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Lucia","Ana","Gisele","Dario","Lucio"};
    int idProducto[10] = {13, 14, 11, 14, 19, 19, 15, 17, 12, 17}; //ID del producto que compraron

    for(i=0; i<10; i++)
    {
        listado[i].idProducto = idProducto[i];
        listado[i].estado = OCUPADO;
        strcpy(listado[i].nombre, nombre[i]);
        strcpy(listado[i].password, pass[i]);
    }
}

void hardcodeProductos(eProducto listado[], int limiteP)
{
    int i;
    //Inicializar 10 electrodomesticos
    char nombre[][50]= {"Cafetera","Computadora","Heladera","Estufa V","Lavadora","Licuadora","Televisor","Tostadora","Ventilador","Celular"};
    char usuario[][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Lucia","Ana","Gisele","Dario","Lucio"};
    float precio[10] = {6000, 9980, 8000, 6500.90, 1800, 6600, 8650, 5815, 7500, 3170};
    int ventas[10] = {0};
    int stock[10] = {21, 3, 7, 9, 3, 6, 1, 3, 5, 7};
    int id[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19}; //ID que pertenece a cada producto

    for(i=0; i<10; i++)
    {
        listado[i].precio = precio[i];
        listado[i].stock = stock[i];
        listado[i].cantVentas = ventas[i];
        listado[i].idProducto = id[i];
        listado[i].estado = OCUPADO;
        strcpy(listado[i].nombre, nombre[i]);
        strcpy(listado[i].usuario, usuario[i]);
    }
}

void menu()
{
    printf("\tMODELO DE PARCIAL\n\n1. ALTA DE USUARIO\n2. MODIFICAR DATOS DEL USUARIO\n3. BAJA DEL USUARIO\n4. PUBLICAR PRODUCTO\n5. MODIFICAR PUBLICACION\n6. CANCELAR PUBLICACION\n7. COMPRAR PRODUCTO\n8. LISTAR PUBLICACION DE USUARIO\n9. LISTAR PUBLICACIONES\n10. LISTAR USUARIOS\n");

}

int eUsuario_buscarLugarLibre(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProducto_buscarLugarLibre(eProducto listadoP[],int limiteP)
{
    int retorno = -1;
    int i;
    if(limiteP > 0 && listadoP != NULL)
    {
        retorno = -2;
        for(i=0; i<limiteP; i++)
        {
            if(listadoP[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eUsuario_siguienteId(eUsuario listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                if(listado[i].idGenerica>retorno)
                {
                    retorno=listado[i].idGenerica;
                }

            }
        }
    }

    return retorno+1;
}

int validarId(eUsuario listado[], int limite, int id)
{
    int i;

    for(i = 0 ; i < limite ; i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            if(id == listado[i].idGenerica)
            {
                printf("\n>>> El id ya se encuentra registado.\n\n");
                return -1;
            }
        }
    }
    return 0;
}

int eUsuario_alta(eUsuario listado[],int limite)
{
    int i;

    system("cls");
    printf("\tALTA DE USUARIO\n\n");

    i = eUsuario_buscarLugarLibre(listado,limite);
    if(i == -2)
    {
        printf(">>> Error. Ya no hay mas espacio.\n\n");
        return -2;
    }

    getString(listado[i].nombre,"Ingrese el nombre: ");
    getString(listado[i].password,"Ingrese el password: ");

    /*if(aux == -1)
    {
        strcpy(listado[i].nombre,"\0");
        strcpy(listado[i].password,"\0");
        listado[i].estado = LIBRE;
        return -1;
    }*/
    listado[i].estado = OCUPADO;

    return 0;
}

int eUsuario_buscarPorId(eUsuario listado[],int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2; //Devuelve [-2] si no lo encontró
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idGenerica == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int getSN(char* input, char message[], char eMessage[])
{
    char aux;
    printf("%s", message);
    aux = toupper(getche());
    if(aux != 'S' && aux != 'N')
    {
        printf("%s", eMessage);
        return -1;
    }
    else
    {
        *input = aux;
        return 1;
    }
}

int eUsuario_mostrarLista(eUsuario listado[], int limite)
{
    int i;

    for(i = 0 ; i < limite ; i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            printf("\nNombre: %s \t ID: %d", listado[i].nombre, listado[i].idGenerica);
        }
    }

    return 0;
}

int eProducto_mostrarLista(eProducto listado[], int limiteP)
{
    int i;

    for(i = 0 ; i < limiteP ; i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            printf("\n%s \t precio: %.2f \t stock %d \t usuario %s",listado[i].nombre, listado[i].precio, listado[i].stock, listado[i].usuario);
        }
    }
    printf("\n\n");

    return 0;
}

int eUsuario_baja(eUsuario listado[], int limite)
{
    int id;
    char password[50];
    int retorno = -1;
    char resp='N';
    system("cls");
    printf("\tBAJA DEL USUARIO\n\n");

    eUsuario_mostrarLista(listado, limite);

    getInt(&id, "\n\nIngrese el ID del usuario a borrar: ");
    id = eUsuario_buscarPorId(listado, limite, id);

    if(id == -2)
    {
        printf("\n>>> ID NO ENCONTRADO!\n\n");
        return retorno;
    }
    else
    {
        printf("Ingrese el Password del usuario a borrar: ");
        fflush(stdin);
        gets(password);

        if(strcmp(listado[id].password, password) == 0)
        {
            system("cls");
            printf("\tBAJA DEL USUARIO\n\n");
            printf("Nombre: %s \nID: %d", listado[id].nombre, listado[id].idGenerica);
            getSN(&resp,"\n\nEsta seguro que desea eliminar? S/N: ","\n\nError. Opcion no valida");
            if(resp == 'S')
            {
                strcpy(listado[id].nombre,"\0");
                strcpy(listado[id].password,"\0");
                listado[id].idGenerica = LIBRE;
                listado[id].estado = LIBRE;
                retorno = 0;
            }
            else
            {
                printf("\n\n>>> El usuario NO fue borrado!\n\n\n");
            }
        }
        else
        {
            printf("\n\n>>> Password ingresado no coincide con el de %s\n\n\n", listado[id].nombre);
        }

    }
    return retorno;
}

int eUsuario_modificar(eUsuario listado[],int limite)
{
    int id, opc;
    char password[50];
    int retorno = -1;

    system("cls");
    printf("\t MODIFICAR DATOS DEL USUARIO\n\n");
    eUsuario_mostrarLista(listado, limite);

    getInt(&id, "\n\nIngresa el ID a modificar: ");
    id = eUsuario_buscarPorId(listado, limite, id);

    if(id == -2)
    {
        printf("\n>>> ID NO ENCONTRADO!\n\n");
        return retorno;
    }
    else
    {
        printf("Ingrese el Password del usuario a modificar: ");
        fflush(stdin);
        gets(password);

        if(stricmp(listado[id].password, password) == 0)
        {
            system("cls");
            printf("\t MODIFICAR DATOS DEL USUARIO\n\n");
            do
            {
                printf("\nNombre: %s \nID: %d", listado[id].nombre, listado[id].idGenerica);
                printf("\n\n1. Modificar nombre\n2. Modificar password\n3. Modificar id\n4. Salir\n\nElije una opcion: ");
                scanf("%d",&opc);

                switch(opc)
                {
                case 1:
                    system("cls");
                    printf("\t MODIFICAR DATOS DEL USUARIO\n\n");
                    getString(listado[id].nombre,"\nIngrese el nuevo nombre: ");
                    break;
                case 2:
                    system("cls");
                    printf("\t MODIFICAR DATOS DEL USUARIO\n\n");
                    getString(listado[id].password,"Ingrese el nuevo password: ");
                    break;
                case 3:
                    system("cls");
                    printf("\t MODIFICAR DATOS DEL USUARIO\n\n");
                    getInt(&listado[id].idGenerica,"Ingrese el nuevo ID: ");
                    break;
                }
            }
            while(opc!=4);

        }
        else
        {
            printf("\n\n>>> El Password ingresado no coincide con el de %s\n\n\n", listado[id].nombre);
        }

    }
    return retorno;

}


int eProducto_publicarProducto(eUsuario listado[],int limite, eProducto listadoP[], int limiteP)
{
    int libre, id;
    char password[50];
    int retorno = -1;

    system("cls");
    printf("\tPUBLICAR PRODUCTO\n\n");

    libre = eProducto_buscarLugarLibre(listadoP,limiteP);
    if(libre == -2)
    {
        printf("Error. Ya no hay mas espacio.\n\n");
        return -2;
    }

    eUsuario_mostrarLista(listado, limite);

    getInt(&id, "\n\nIngresa el ID del usuario: ");
    id = eUsuario_buscarPorId(listado, limite, id);

    if(id == -2)
    {
        printf("\n>>> ID NO ENCONTRADO!\n\n");
        return retorno;
    }
    getString(password, "Ingrese el password del usuario: ");

    if(strcmp(listado[id].password, password) == 0)
    {
        system("cls");
        printf("\tPUBLICAR PRODUCTO\n\n");
        getString(listadoP[libre].nombre, "Ingresa nombre del producto: ");
        getFloat(&listadoP[libre].precio, "Ingresa precio del producto: ");
        getInt(&listadoP[libre].stock, "Ingresa stock del producto %d : ");

        listadoP[libre].estado = OCUPADO;
        listadoP[libre].cantVentas = 0;
        retorno = 0;
    }
    else
    {
        printf("\n>>> Passwords no son las mismas!\n\n");
    }

    return retorno;
}

int eProducto_modificarPublicacion(eProducto listadoP[], int limiteP, eUsuario listado[], int limite)
{
    int id, idAux;
    float nuevoprecio;
    int retorno = -1;

    system("cls");
    printf("\tMODIFICAR PUBLICACION\n\n");
    eUsuario_mostrarLista(listado, limite);

    getInt(&idAux, "\n\nIngresa el ID del usuario: ");
    id = eUsuario_buscarPorId(listado, limite, idAux); //el id termine conteniendo el indice del usuario encontrado

    if(id == -2)
    {
        printf("\n>>> ID NO ENCONTRADO!\n\n");
        return retorno;
    }
    mostrarProductosdeUsuarios(listadoP, limiteP, listado, limite, id);

    int idProductoAmodificar;

    getInt(&idProductoAmodificar, "\n\nIngresa el ID del producto a modificar: ");
    if(idProductoAmodificar == listado[id].idProducto)
    {
        int p, q;

        for(p = 0 ; p < limiteP ; p++)
        {
            if(listadoP[p].idProducto == idProductoAmodificar) //Compara el ID de la lista de productos que coincida con el id ingresado
            {
                q = p;
                break;
            }
        }

        printf("Ingresa el nuevo stock: ");scanf("%d",&listadoP[q].stock);
        printf("Ingresa el nuevo precio: ");scanf("%f",&listadoP[q].precio);

        retorno = 0;
    }
    else
    {
        printf("\n>>> El ID no corresponde a ninguna compra de %s\n",listado[id].nombre);
        return retorno;
    }

    return retorno;
}


int mostrarProductosdeUsuarios(eProducto listadoP[], int limiteP, eUsuario listado[], int limite, int id)
{
    int i;

    printf("\nProductos de %s:\n",listado[id].nombre);
    printf("\nID \t Nombre \t Precio \t CantidadVendida \t Stock");
    for (i = 0; i<limiteP; i++)
    {
        if (listado[id].idProducto == listadoP[i].idProducto)
        {
            printf("\n%d \t %s \t %.2f \t\t %d \t\t   %d",listadoP[i].idProducto, listadoP[i].nombre, listadoP[i].precio, listadoP[i].cantVentas, listadoP[i].stock);

        }

    }

    return 0;
}

int eProducto_cancelarPublicacion(eProducto listadoP[], int limiteP, eUsuario listado[], int limite)
{
    int id, idAux;
    int retorno = -1;

    system("cls");
    printf("\tCANCELAR PUBLICACION\n\n");
    eUsuario_mostrarLista(listado, limite);

    getInt(&idAux, "\n\nIngresa el ID del usuario: ");
    id = eUsuario_buscarPorId(listado, limite, idAux); //el id termine conteniendo el indice del usuario encontrado

    if(id == -2)
    {
        printf("\n>>> ID NO ENCONTRADO!\n\n");
        return retorno;
    }
    mostrarProductosdeUsuarios(listadoP, limiteP, listado, limite, id);

    int idProductoAcancelar;

    getInt(&idProductoAcancelar, "\n\nIngresa el ID del producto a cancelar: ");
    if(idProductoAcancelar == listado[id].idProducto)
    {
        int p, q;

        for(p = 0 ; p < limiteP ; p++)
        {
            if(listadoP[p].idProducto == idProductoAcancelar) //Compara el ID de la lista de productos que coincida con el id ingresado
            {
                q = p;
                break;
            }
        }

        strcpy(listadoP[q].nombre,"\0");
        listadoP[q].idProducto = 0;
        listadoP[q].estado = LIBRE;
        listadoP[q].precio = 0;
        listadoP[q].stock = 0;
        listadoP[q].cantVentas = 0;

        retorno = 0;
    }
    else
    {
        printf("\n>>> El ID no corresponde a ninguna compra de %s\n",listado[id].nombre);
        return retorno;
    }

    return retorno;
}


/*
    int p;

    ////////////////////////////////////////////////////////////////////////////////
    // Para comprobar que se guarda cada publicacion que se hace
    ////////////////////////////////////////////////////////////////////////////////
    for(p = 0 ; p < limiteP ; p++)
    {
        if(listadoP[p].estado == OCUPADO)
        printf("\nNombre: %s\nID: %d\nPrecio: %.2f\nStock: %d\nComprador: %s\n\n",listadoP[p].nombre, listadoP[p].idProducto, listadoP[p].precio, listadoP[p].stock, listado[id].nombre);
    }

*/
