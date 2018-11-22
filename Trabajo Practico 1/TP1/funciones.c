#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

float pedir_Numero_1()
{
    float numero_1;
    printf("\n\tIngresa el 1\247 numero: ");
    scanf("%f",&numero_1);
    return numero_1;
}


float pedir_Numero_2()
{
    float numero_2;
    printf("\n\tIngresa el 2\247 numero: ");
    scanf("\n%f",&numero_2);
    return numero_2;
}


float sumar_Numeros(float numero_1, float numero_2)
{
    float resultado;
    resultado = numero_1 + numero_2;
    printf("\tLa suma es: %.2f \n", resultado);
    return resultado;
}



float restar_Numeros(float numero_1, float numero_2)
{
    float resultado;
    resultado = numero_1 - numero_2;
    printf("\n\tLa resta es: %.2f\n",resultado);
    return resultado;
}



float dividir_Numeros(float numero_1, float numero_2)
{
    float resultado;
    if(numero_2 == 0)
    {
        printf("\n\tNo es posible dividir por cero!!!\n");
    }
    else
    {
        resultado = numero_1 / numero_2;
        printf("\n\tLa division es: %.2f\n",resultado);
    }
    return resultado;
}



float multiplicar_Numeros(float numero_1, float numero_2)
{
    float resultado;
    resultado = numero_1 * numero_2;
    printf("\n\tLa multiplicacion es: %.2f\n",resultado);
    return resultado;
}



long factorial_Numeros(long numero_1)
{
    int i;
    long factorial = 1;
    if(numero_1<0)
    {
        printf("\n\tNo existe factorial de un negativo\n");
    }
    else
    {
        for(i = numero_1 ; i >= 1 ; i--)
        {
            factorial = factorial * i;
        }
        printf("\n\tEl factorial de A es: %ld \n\n",factorial);
    }
    return factorial;
}



void calcular_Todo(float numero_1, float numero_2)
{
    sumar_Numeros(numero_1, numero_2);
    restar_Numeros(numero_1, numero_2);
    dividir_Numeros(numero_1, numero_2);
    multiplicar_Numeros(numero_1, numero_2);
    factorial_Numeros(numero_1);
}
