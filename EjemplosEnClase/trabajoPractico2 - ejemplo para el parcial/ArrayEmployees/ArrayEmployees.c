#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "../ArrayEmployees/ArrayEmployees.h"

#define MAX 1000
#define MAXSEC 5
#define MAXCARAC 30
#define TRUE 1
#define FALSE 0


int menu()
{
    int opcion;
    system("cls");
    printf("\tADMINISTRAR NOMINAS DE EMPLEADOS\n\n\n");
    printf("1- Altas\n");
    printf("2- Bajas\n");
    printf("3- Modificar\n");
    printf("4- Informar\n");
    printf("5- Salir\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


void initEmployees(Employee* list, int len)
{
    int i;

    for(i = 0 ; i < len ; i++)
    {
        list[i].isEmpty = TRUE;
    }

}

void mostrarInit(Employee list[], int len)
{
    int i;

    printf("\tInicializacion\n");

    for(i = 0 ; i < len ; i++)
    {
        printf("\n#%d ---> %d",i+1,list[i].isEmpty);
    }

    printf("\n\n");
    system("pause");
    system("cls");
}



int buscarEspacioLibre(Employee* list, int len)
{
    int i;
    int retorno = -1; // Retorta -1 si no encontró un espacio

    for(i = 0 ; i < len ; i++)
    {
        if(list[i].isEmpty == TRUE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

void wait()
{
    printf("\n\n\n");
    system("pause");
}

int esSoloLetras(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return -1;
        i++;
    }
    return 0;
}

int getStringV(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char aux[256];
    int valida;

    printf("%s", message);
    fflush(stdin);
    gets(aux);

    valida = esSoloLetras(aux);

    if(valida == -1)
    {
        printf("\n>>> Solo se permiten letras!\n");
        return valida;

    }


    if(strlen(aux) < lowLimit || strlen(aux)>hiLimit)
    {
        printf("%s", eMessage);
        valida = -1;

        while(valida == -1)
        {
            valida = getStringV(input, message, eMessage, lowLimit, hiLimit);
        }

    }
    else
    {
        strcpy(input,aux);
    }

    return 0;
}

int esNumerico (char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return -1;
        i++;
    }
    return 0; //retorna [0] si NO es numero // [1] si no es numero.
}

int getFloatV(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    float aux;

    printf("%s", message);
    scanf("%f", &aux);

    if(aux < lowLimit || aux >hiLimit)
    {
        printf("%s",eMessage);
        wait();
        return -1;
    }
    else
    {
        *input = aux;
        return 0;
    }

}

int getIntV(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int aux;

    printf("%s", message);
    scanf("%d", &aux);
    if(aux < lowLimit || aux > hiLimit)
    {
        printf("%s", eMessage);
        return -1;
    }
    else
    {
        *input = aux;
        return 0;
    }

}

int SiguienteID(Employee* list, int len)
{
    int retorno = 0;
    int i;
    if(len > 0 && list != NULL)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == FALSE)
            {
                if(list[i].id > retorno)
                {
                    retorno=list[i].id;
                }

            }
        }
    }

    return retorno+1;
}


int funChequeoNumero(char num[])
{
    int i = 0, cont;
    int flag = 0;
    cont = strlen(num);
    while (i<cont && flag == 0)
    {
        if(isdigit(num[i])!=0)
        {
            i++;
        }
        else
        {
            flag = 1;
        }
    }
    return flag;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector, int index)
{
    int i;

    for(i = 0 ; i < len ; i++)
    {
        strcpy(list[index].name, name);
        strcpy(list[index].lastName, lastName);
        list[index].salary = salary;
        list[index].sector = sector;
        list[index].id = id;
    }

    return 0;
}

void hardcodeo(Employee* list, int len)
{
    int i;

    Employee hardcodeo[5] =
    {
        {1, "Juan", "Gomez", 10500.50, 1, FALSE},
        {2, "Lucas", "Diaz", 12000.25, 3, FALSE},
        {3, "Ana", "Acosta", 25000.80, 2, FALSE},
        {4, "Mario", "Lopez", 14500, 3, FALSE},
        {5, "Lucia", "Diaz", 21000, 5, FALSE}

    };


    for(i = 0 ; i < len ; i++)
    {
        list[i] = hardcodeo[i];
    }



}


int alta(Employee* list, int len)
{
    // Variables auxiliares para al final reemplazar en la estructura
    int index;
    int retorno = -1;
    char auxName[31];
    char auxLastName[31];
    float auxSalary;
    int auxSector;
    int auxId;
    int auxIsEmpty;
    int r;

    system("cls");
    printf("\tALTA DE EMPLEADO\n\n");

    // Index recibe el indice que representa el espacio libre
    index = buscarEspacioLibre(list, len);

    if(index != -1) // [-1] si no encuentra espacio libre
    {
        r = getStringV(auxName,"Ingresa nombre: ", "\n>>> Error! superaste el largo del nombre\n",0,MAXCARAC);
        if(r == 0)
        {
            r = getStringV(auxLastName,"Ingresa apellido: ", "\n>>> Error! superaste el largo del apellido\n",0,MAXCARAC);

            if(r == 0)
            {
                r = getFloatV(&auxSalary,"Ingresa salario: ", "\nError! superaste el limite del salario!\n",0.0,1000000.0);

                if( r == 0)
                {
                    r = getIntV(&auxSector,"Ingresa sector: ", "\nError! superaste el limite de los sectores!\n",0,MAXSEC);

                    if(r == 0)
                    {
                        auxIsEmpty = FALSE;
                        auxId = SiguienteID(list, len);
                        list[index].isEmpty = auxIsEmpty; // Pasamos el estado a ocupado [FALSE]

                        // Pasamos todos los datos mediante la funcion que pidieron en el tp
                        addEmployee(list, len, auxId, auxName, auxLastName, auxSalary, auxSector, index);
                        printf("\n\n>>> Empleado agregado!");
                    }
                }
            }
        }


        retorno = 0;
    }
    else
    {
        system("cls");
        printf("\tALTA DE PERSONA\n\n");
        printf("\n>>> NO HAY ESPACIO DISPONIBLE\n");
    }


    return retorno;
}

int printEmployees(Employee* list, int length)
{
    int i, vacio = -1;
    printf("LASTNAME  NAME\t\tID\tSALARY\t\t\tSECTOR\n");

    for(i = 0 ; i < length ; i++)
    {
        if(list[i].isEmpty == FALSE)
        {
            printf("\n%s\t  %s\t\tID: %d \tSalary: %.2f \tSector: %d",list[i].lastName, list[i].name, list[i].id, list[i].salary, list[i].sector);
            vacio = 0;
        }
    }

    if(vacio == -1)
    {
        printf("\n\n>>> NO HAY EMPLEADOS QUE MOSTRAR.\n\n");
        system("pause");
        system("cls");
    }



    return vacio;
}

void showEmployee(Employee* list, int i)
{
    printf("\n%s %s \tID: %d\tSalary: %.2f \tSector: %d",list[i].name, list[i].lastName, list[i].id, list[i].salary, list[i].sector);
}

int findEmployeeById(Employee* list, int len, int auxID)
{
    int retorno = -1;
    int i;

    for(i = 0 ; i < len ; i++)
    {
        if(list[i].isEmpty == FALSE && list[i].id == auxID)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}


int modificar(Employee* list, int len)
{
    int auxID, flag, encontrado, opcion;
    char confirma;
    char auxName[31];
    char auxLastName[31];
    float auxSalary;
    int auxSector;
    int salir = 0;

    system("cls");
    printf("\tMODIFICAR EMPLEADO\n\n");
    flag = printEmployees(list, len);

    if(flag != -1)
    {
        printf("\n\nIngrese ID del Empleado: ");
        scanf("%d",&auxID);

        // findEmployeeById Funcion que pedia el tp
        encontrado = findEmployeeById(list, len, auxID);

        if(encontrado != -1)
        {
            system("cls");
            printf("\tMODIFICAR EMPLEADO\n");
            showEmployee(list, encontrado);
            do
            {
                printf("\n\nConfirma Modificacion? [S|N]: ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
            }
            while(confirma != 's' && confirma != 'n');

            if(confirma == 's')
            {
                do
                {
                    system("cls");
                    printf("\tMODIFICAR EMPLEADO\n\n");

                    printf("1- Modificar Name.\n");
                    printf("2- Modificar Last Name.\n");
                    printf("3- Modificar Salary.\n");
                    printf("4- Modificar Sector.\n");
                    printf("5- Salir.\n\n");
                    printf("Ingrese opcion: ");
                    scanf("%d",&opcion);
                    switch(opcion)
                    {
                    case 1:
                        getStringV(auxName,"\nIngresa nuevo Name: ", "\n>>> Error! superaste el largo del nombre\n",0,MAXCARAC);
                        strcpy(list[encontrado].name, auxName);
                        salir = 1;
                        printf("\n\n>>> Se ha realizado la modificacion\n");
                        wait();
                        break;
                    case 2:
                        getStringV(auxLastName,"\nIngresa nuevo Last Name: ", "\n>>> Error! superaste el largo del last name\n",0,MAXCARAC);
                        strcpy(list[encontrado].lastName, auxLastName);
                        salir = 1;
                        printf("\n\n>>> Se ha realizado la modificacion\n");
                        wait();
                        break;
                    case 3:
                        getFloatV(&auxSalary,"\nIngresa Salario: ", "\nError! superaste el limite del salario!\n",0.0,1000000.0);
                        list[encontrado].salary = auxSalary;
                        salir = 1;
                        break;
                    case 4:
                        getIntV(&auxSector,"\nIngresa nuevo Sector: ", "\nError! superaste el limite de los sectores!\n",0,MAXSEC);
                        list[encontrado].sector = auxSector;
                        salir = 1;
                        printf("\n\n>>> Se ha realizado la modificacion\n");
                        wait();
                        break;
                    case 5:
                        salir = 1;
                        break;
                    }
                }
                while(salir != 1);
            }
            else
            {
                printf("\n\n>>> Se ha cancelado la modificacion\n");
                wait();
            }

        }
        else
        {
            printf("\n\n\n>>> NO SE ENCONTRO EL ID EN EL SISTEMA\n\n");
            system("pause");
            system("cls");
        }

    }

    return 0;
}

int removeEmployee(Employee* list, int len, int id)
{
    int retorno;
    char confirma;
    int encontrado;

    system("cls");
    printf("\tBAJA EMPLEADO\n");
    encontrado = findEmployeeById(list,len,id);

    if(encontrado != -1)
    {
        showEmployee(list, encontrado);
        do
        {
            printf("\n\nConfirma Baja? [S|N]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }
        while(confirma != 's' && confirma != 'n');

        if(confirma == 's')
        {
            list[encontrado].isEmpty = TRUE;
            retorno = 1;
        }
        else
        {
            printf("\n\n>>> Se ha cancelado la baja\n");
            wait();
        }
    }
    else
    {
        printf("\n\n\n>>> NO SE ENCONTRO EL ID EN EL SISTEMA\n\n");
        system("pause");
        system("cls");
    }




    return retorno;
}


int baja(Employee* list, int len)
{
    int auxID, flag;

    system("cls");
    printf("\tBAJA EMPLEADO\n\n");
    flag = printEmployees(list, len);

    if(flag != -1)
    {
        printf("\n\nIngrese ID del Empleado: ");
        scanf("%d",&auxID);

        // removeEmployee Funcion que pedia el tp
        removeEmployee(list, len, auxID);

    }

    return 0;
}


void informes(Employee* list, int len, float total, float promedio, int superaron)
{


    printf("\n>>> El total de sueldo es: $%.2f",total);
    printf("\n>>> El promedio de sueldo es: $%.2f",promedio);
    printf("\n>>> Empleados que superan el promedio: %d",superaron);
}

int sortEmployees(Employee* list, int len, int order)
{
    int i, j;
    Employee aux;

    if(order == 1)
    {
        for(i = 0 ; i < len-1 ; i++)
        {
            if(list[i].isEmpty == FALSE)
            {
                for(j=i+1 ; j<len ; j++)
                {
                    if(strcmp(list[i].lastName, list[j].lastName) > 0)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;

                    }
                    else
                    {
                        if(strcmp(list[i].lastName, list[j].lastName) == 0  && list[i].sector > list[j].sector)
                        {

                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;

                        }
                    }

                }
            }

        }

        printEmployees(list, len);

    }
    else if(order == 0)
    {
        for(i = 0 ; i < len-1 ; i++)
        {
            if(list[i].isEmpty == FALSE)
            {
                for(j=i+1 ; j<len ; j++)
                {
                    if(strcmp(list[i].lastName, list[j].lastName) < 0)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;

                    }
                    else
                    {
                        if(strcmp(list[i].lastName, list[j].lastName) == 0  && list[i].sector < list[j].sector )
                        {

                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;

                        }
                    }

                }
            }

        }

        printEmployees(list, len);



    }


    return 0;
}



int informarA(Employee* list, int len)
{
    int order;
    system("cls");
    printf("\tORDENAR EMPLEADOS\n\n");
    printf("Listado por Apellido y Sector:\n\n");
    printf("\nIngresa [1] para ordenar Ascendente\nIngresa [0] para ordenar Descendente\n\nIngresa opcion: ");
    scanf("%d",&order);

    printf("\n\n");
    sortEmployees(list, len, order);

    wait();
    return 0;
}


int informarB(Employee* list, int len)
{
    int order = 2;
    float acumulador = 0;
    float promedio;
    float employeeExiste = 0;
    int superaron = 0, i;

    system("cls");
    printf("\tORDENAR EMPLEADOS\n\n");
    printf("\nTotal y promedio de los salarios - Y salario promedio:\n\n");



    if(order == 2)
    {
        // Acumular todos los salarios
        for( i = 0 ; i < len ; i++)
        {
            if(list[i].isEmpty == FALSE)
            {
                employeeExiste++;
                acumulador += list[i].salary;
            }
        }


        // Sacar el promedio

        promedio = acumulador / employeeExiste;


        // Vemos quien superó el sueldo promedio
        for( i = 0 ; i < len ; i++)
        {

            if( (list[i].isEmpty == FALSE) && (list[i].salary > promedio))
            {
                superaron++;
            }
        }

        informes(list, len, acumulador, promedio, superaron);
        wait();

    }
    return 0;
}


void informarOPC(Employee* list, int len)
{
    int flag;

    system("cls");
    printf("\tORDENAR EMPLEADOS\n\n");
    flag = printEmployees(list, len);

    if(flag != -1)
    {
        char opcion;
        system("cls");
        printf("\tINFORMES DE EMPLEADOS\n\n\n");

        printf("4- Informar\n\n");
        printf("\tA- listado de los empleados ordenados alfabeticamente \n\t   por Apellido y Sector\n\n");
        printf("\tB- Total y promedio de los salarios, y cuantos empleados \n\t   superan el salario promedio\n");

        printf("\nIngrese opcion [A / B]: ");
        fflush(stdin);
        opcion = getche();

        if(opcion == 'a' || opcion == 'A')
        {
            informarA(list,len);

        }
        else if(opcion == 'b' || opcion == 'B')
        {
            informarB(list,len);
        }
        else
        {
            printf("\n\n>>> Opcion inexistente!");
            wait();
        }

    }
}
