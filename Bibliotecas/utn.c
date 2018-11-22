#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "utn.h"



/**
 * \brief Valida que un string que se le pasa sea numerico
 * \param str[] string a validar
 * \param
 * \return devuelve [1] si es numerico, de lo contrrario [0]
 *
 */
int esNumerico(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1; //retorna [1] si es numero // [0] si no es numero.
}



/**
 * \brief Valida que un string contenga solo espacios, letras y numeros
 * \param char str[] string a validar
 * \param
 * \return devuelve [1] si contiene solo espacio o letras y numeros, de lo contrario [0]
 *
 */
int esAlfaNumerico(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1; //retorna [1] si contiene solo espacio o letras y numeros // [0] si no
}



/**
 * \brief Valida que un string contenga solo letras
 * \param char str[] string a validar
 * \param
 * \return devuelve [1] si contiene solo letras , de lo contrario [0]
 *
 */
int esSoloLetras(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}


/**
 * \brief Valida que sea entero
 * \param char str[] string a validar
 * \param
 * \return devuelve [1] si es un digito, [0] si no lo es
 *
 */
int esEntero(char lista[])
{
    int i;
    int index;
    int limite;

    limite=strlen(lista);

    for (i=0; i<limite; i++)
    {
        index=isdigit(lista[i]);

        if (index==0)
        {
            break;
        }
    }
    return index;
}


/**
 * \brief Valida que sea entero flotante
 * \param char str[] string a validar
 * \param
 * \return devuelve [1] si es un digito, [0] si no lo es
 *
 */
int validarFlotante(char lista[])
{
    int i;
    int flagpunto = 0;
    int index;
    int limite;
    int contador = 0;

    limite=strlen(lista);

    for (i=0; i<limite; i++)
    {
        index=isdigit(lista[i]);

        // Valida que ingrese cuando haya 2 puntos decimales
        if (index==0 && lista[i] == '.' && contador == 1 && flagpunto == 1)  // Va a ingresar cuando encuentre un punto, y lo deja pasar
        {
            index = -1;
            break;
        }


        if (index==0 && lista[i] == '.' && contador == 0)  // Ingresar cuando encuentre un punto, y lo deja pasar
        {
            contador++;
            flagpunto++;
        }


        if(index == 0 && contador != 1) // Al encontrar algun caracter rompe el for
        {
            break;
        }

    }
    return index;
}

/**
 * \brief Cuenta los caracteres de un string que le pasamos
 * \param campo[] string a contar
 * \param tamano el tamaño que no puede superar
 * \return flag [0] si NO supero el tamaño, caso contrario [-1]
 *
 */
int contarCaracteres(char campo[], int tamano)
{
    int flag = 0;
    int cont;
    cont = strlen(campo);
    if (cont > tamano)
    {
        flag = -1;
    }
    return flag;
}


int getFecha(int* inputD, int* inputM, int* inputA, char messageD[], char messageM[], char messageA[])
{
    int retorno = 0;

    // Variables string para comprobar que sea números y no letras
    char auxD[3];
    int validarD;
    char auxM[3];
    int validarM;
    char auxA[5];
    int validarA;

    // Variables para establecer mínimos y máximos permitidos en las fechas
    int maxDia = 31;
    int minDia = 1;
    int maxMes = 12;
    int minMes = 1;
    int maxAnio = 2018;
    int minAnio = 1990;

    // Variables para convertir los string a int
    int diaNumero;
    int mesNumero;
    int anioNumero;


    // Ingresamos y Validamos DIA
    printf("%s",messageD);
    fflush(stdin);
    gets(auxD);

    validarD = esEntero(auxD);
    diaNumero = atoi(auxD);

    while((diaNumero < minDia || diaNumero > maxDia) || validarD == 0)
    {
        printf("\nError... Para DIA solo se permiten numeros (1 al 31)\nRe%s ",messageD);
        fflush(stdin);
        gets(auxD);
        validarD = esEntero(auxD);
        diaNumero = atoi(auxD);
    }


    // Ingresamos y Validamos MES
    printf("%s",messageM);
    fflush(stdin);
    gets(auxM);

    validarM = esEntero(auxM);
    mesNumero = atoi(auxM);

    while((mesNumero < minMes || mesNumero > maxMes) || validarM == 0)
    {
        printf("\nError... Para MES solo se permiten numeros (1 al 12)\nRe%s ",messageM);
        fflush(stdin);
        gets(auxM);
        validarM = esEntero(auxM);
        mesNumero = atoi(auxM);
    }


    // Ingresamos y Validamos AÑO
    printf("%s",messageA);
    fflush(stdin);
    gets(auxA);

    validarA = esEntero(auxA);
    anioNumero = atoi(auxA);

    while((anioNumero < minAnio || anioNumero > maxAnio) || validarA == 0)
    {
        printf("\nError... Para ANIO solo se permiten numeros (1990 al 2018)\nRe%s ",messageA);
        fflush(stdin);
        gets(auxA);
        validarA = esEntero(auxA);
        anioNumero = atoi(auxA);
    }

    *inputD = diaNumero;
    *inputM = mesNumero;
    *inputA = anioNumero;

    return retorno;

}

/**
 * Valida que el dato ingresado sea solo numeros positivos enteros
 * \param num[] char variable donde se guardan los datos
 * \param
 * \return flag [1] si no esta compuesto de numeros positivos o caracteres, [0] si son numeros positivos
 *
 */
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



/**
 * \brief Valida que sea entero
 * \param char str[] string a validar
 * \param
 * \return [0] si NO es caracter, [-1] SI ES un caracter
 *
 */
int esCaracter(char letra)
{
    int index=-1;
    if (isalpha(letra) == 0)
    {
        index=0;
    }
    return index;
}


/**
 * \brief Obtiene un string con algunas validaciones en cuenta - que sean solo letras y respete los limites
 * \param input donde cargara el string
 * \param message[] el mensaje a ser mostrado
 * \param eMessage[] el mensaje a ser mostrado en caso de error
 * \param lowLimit el limite minimo permitido
 * \param hiLimit el limite maximo permitido
 * \return [0] si salio todo bien, caso contrario [-1]
 *
 */
int getStringV(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char aux[256];
    int valida;

    printf("%s", message);
    fflush(stdin);
    gets(aux);

    valida = esSoloLetras(aux);

    if(valida == 0)
    {
        printf("\n>>> Solo se permiten letras!\n");
        printf(">>> No se pudo dar de alta el empleado!");
        printf("\n\n\n");
        system("pause");
        valida = -1;
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
        valida = 1;
    }

    return valida;
}




/**
 * \brief Obtiene un string con algunas validaciones en cuenta - que sean solo letras y respete los limites
 * \param input donde cargara el string
 * \param message[] el mensaje a ser mostrado
 * \param eMessage[] el mensaje a ser mostrado en caso de error
 * \param lowLimit el limite minimo permitido
 * \param hiLimit el limite maximo permitido
 * \return [0] si salio todo bien, caso contrario [-1]
 *
 */
int getStringAlfanumericoV(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char aux[256];
    int valida;

    printf("%s", message);
    fflush(stdin);
    gets(aux);

    valida = esSoloLetras(aux);

    if(!esAlfaNumerico(aux))
    {
        printf("\n>>> Solo se permiten letras o numeros!\n");
        printf("\n\n\n");
        system("pause");
        valida = -1;
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




/**
 * \brief Obtiene un entero que tenga en cuenta los limites
 * \param input donde cargara el entero
 * \param message[] el mensaje a ser mostrado
 * \param eMessage[] el mensaje a ser mostrado en caso de error
 * \param lowLimit el limite minimo permitido
 * \param hiLimit el limite maximo permitido
 * \return [0] si salio todo bien, caso contrario [-1]
 *
 */
int getIntV(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char auxiliar[50];
    int validacion = 0;
    int longitudDeValidacion = 0;

    printf("%s",message);
    fflush(stdin);
    gets(auxiliar);
    validacion = esEntero(auxiliar);
    longitudDeValidacion = strlen(auxiliar);

    while((longitudDeValidacion< lowLimit && longitudDeValidacion > hiLimit) || validacion == 0)
    {
        printf("%s\n",eMessage);
        system("pause");
        fflush(stdin);
        gets(auxiliar);
        validacion=esEntero(auxiliar);
        longitudDeValidacion=strlen(auxiliar);
    }
    *input =atoi(auxiliar);
    return validacion;

}



/**
 * \brief Obtiene un flotante verificando que sea flotante
 * \param input donde cargara el flotante
 * \param message[] el mensaje a ser mostrado
 * \param eMessage[] el mensaje a ser mostrado en caso de error
 * \return [0] si salio todo bien, caso contrario [-1]
 *
 */
int getFlotanteV(char *input, char *message)
{
    char cadena[50];
    int retorno = 0;
    int validaNumero;

    printf("%s",message);
    fflush(stdin);
    gets(cadena);

    validaNumero = validarFlotante(cadena);

    if(validaNumero == 1) // 1 Cuando es un numero flotante
    {
        retorno = 0;
    }
    else if(validaNumero == 0)
    {
        printf("\n>>> Error!... Solo se permiten numeros > 0");
        printf("\n>>> No se pudo dar de alta el empleado!");
        printf("\n\n\n");
        system("pause");
        retorno = -1;
        return retorno;
    }
    else if(validaNumero == -1)
    {
        printf("\n>>> Error!.. Ingresaste mas de un punto decimal");
        printf(">>> No se pudo dar de alta el empleado!");
        printf("\n\n\n");
        system("pause");
        retorno = -1;
        return retorno;
    }

    strcpy(input,cadena);

    return retorno;
}




/**
 * \brief Obtiene un char y tiene en cuenta los limites
 * \param input donde cargara el char en caso de salir todo bien
 * \param message[] el mensaje a ser mostrado
 * \param eMessage[] el mensaje a ser mostrado en caso de error
 * \param lowLimit el limite minimo permitido
 * \param hiLimit el limite maximo permitido
 * \return [0] si salio todo bien, caso contrario [-1]
 *
 */
int getCharV(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    char auxiliar;
    int validacion = 0;

    printf("%s", message);
    fflush(stdin);
    scanf("%c",&auxiliar);
    validacion = esCaracter(auxiliar); // [-1] si salio todo bien

    while(validacion == 0 || (lowLimit > toupper(auxiliar) && hiLimit < toupper(auxiliar)))
    {
        printf("%s",eMessage);
        fflush(stdin);
        scanf("%c",&auxiliar);
        validacion=esCaracter(auxiliar);
    }

    validacion = 0;

    *input=auxiliar;

    return validacion;

}



/**
 * \brief Obtiene un caracter validando que sea S o N
 * \param input donde cargara el caracter
 * \param message[] el mensaje a ser mostrado
 * \param eMessage[] el mensaje a ser mostrado en caso de error
 * \return [1] si salio todo bien, caso contrario [0]
 *
 */
int getSN(char* input, char message[], char eMessage[])
{
    char aux;
    printf("%s", message);
    aux = tolower(getche());
    if(aux != 's' && aux != 'n')
    {
        printf("%s", eMessage);
        return 0;
    }
    else
    {
        *input = aux;
        return 1;
    }
}



int getUnoOCero(int* input, char message[])
{
    int aux;

    printf("%s", message);
    scanf("%d",&aux);

    while(aux != 1 && aux != 0)
    {
        printf("\n>>> Solo se permite 1 o 0\n");
        printf("REingresa: ");
        fflush(stdin);
        scanf("%d",&aux);
    }

    return 1;
}


int getIDV(LinkedList* pArrayListEmployee, char *mensaje)
{
    int cant;
    int auxId;
    int flag = 1;

    cant = ll_len(pArrayListEmployee);

    printf("%s",mensaje);
    scanf("%d",&auxId);

    while(flag)
    {
        if(auxId < 0)
        {
            printf(">>> El ID NO puede ser negativo!\n\n");
            printf("RE%s: ",mensaje);
            scanf("%d",&auxId);
        }
        else if(auxId <= 0 && cant == 0)
        {
            printf(">>> El ID NO puede ser cero (0)\n\n");
            printf("RE%s: ",mensaje);
            scanf("%d",&auxId);
        }
        else if(auxId <= cant)
        {
            printf(">>> El ID ya se encuentra registrado, ultimo ID %d\n\n",cant);
            printf("RE%s: ",mensaje);
            scanf("%d",&auxId);
        }
        else
        {
            flag = 0;
        }
    }

    return auxId;
}


int getHorasTrabajadasV(LinkedList* pArrayListEmployee, char *mensaje)
{
    int auxHT;
    int flag = 1;

    printf("%s",mensaje);
    scanf("%d",&auxHT);

    while(flag)
    {
        if(auxHT < 0)
        {
            printf(">>> Las HORAS TRABAJADAS NO pueden ser negativos!\n\n");
            printf("RE%s: ",mensaje);
            scanf("%d",&auxHT);
        }
        else if(auxHT == 0 && auxHT <= 0)
        {
            printf(">>> Las HORAS TRABAJADAS deben ser mayor a cero!\n\n");
            printf("RE%s: ",mensaje);
            scanf("%d",&auxHT);
        }
        else
        {
            flag = 0;
        }
    }

    return auxHT;
}

int validarNumeroDesdeHasta(char *mensaje, int desde, int hasta, int* numero)
{
    printf("%s",mensaje);
    scanf("%d",numero);

    while(*numero < desde || *numero > hasta)
    {
        printf("\n\n>>> Minimo %d y Maximo %d\nREingrese: ",desde, hasta);
        scanf("%d",numero);
    }

    return 1;
}

void wait()
{
    printf("\n\n\n");
    system("pause");
}
