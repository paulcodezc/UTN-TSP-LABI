#include <stdio.h>
#include <stdlib.h>
#define MAX 5


int main()
{
    int vector[5] = {73, 43, 15, 3, 21};
    printf("Vamos a ordenar\n");

    int aux;

    for(int i = 0 ; i < MAX - 1 ; i++)
    {
        for(int j = i+1 ; j < MAX ; j++)
        {
            if(vector[i] > vector[j])
            {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }


    printf("\n\n ----- \n\n");

    for(int i = 0 ; i < MAX ; i++)
    {
        printf("\n%d",vector[i]);
    }

    printf("\n\n");
    system("pause");
    return 0;
}
