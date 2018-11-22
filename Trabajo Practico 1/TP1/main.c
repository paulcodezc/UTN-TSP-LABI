#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int flag_1 = 0;
    int flag_2 = 0;
    int opcion = 0;
    float numero_1;
    float numero_2;
    char seguir = 's';

    while(seguir == 's')
    {
        printf("\t>>> Calculadora <<<\n\n\n");
        if(flag_1 == 0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A=%.2f)\n",numero_1);
        }
        if(flag_2 == 0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%.2f)\n",numero_2);
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones.\n");
        printf("9- Salir\n\nIngresa una opcion: ");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            numero_1 = pedir_Numero_1();
            flag_1= 1;
            break;
        case 2:
            numero_2 = pedir_Numero_2();
            flag_2 = 1;
            break;
        case 3:
            sumar_Numeros(numero_1, numero_2);
            break;
        case 4:
            restar_Numeros(numero_1, numero_2);
            break;
        case 5:
            dividir_Numeros(numero_1, numero_2);
            break;
        case 6:
            multiplicar_Numeros(numero_1, numero_2);
            break;
        case 7:
            factorial_Numeros(numero_1);
            break;
        case 8:
            calcular_Todo(numero_1, numero_2);
            break;
        case 9:
            printf("\nSaliste Correctamente!\n\n");
            seguir = 'n';
            break;
        default:
            printf("\n\tOpcion inexistente\n\n");
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
