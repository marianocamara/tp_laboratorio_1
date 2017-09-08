#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float numeroUno, numeroDos;
    float resultadoDivision;
    int flagNumeroUnoIngresado=0;
    int flagNumeroDosIngresado=0;

    while(seguir=='s')
    {
        system("cls");
        printf("\nElija una de las opciones del menu:\n\n");
        if(flagNumeroUnoIngresado==0)
        {
            printf("1- Ingresar 1er operando (A = x)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A = %.2f)\n",numeroUno);
        }
        if(flagNumeroDosIngresado==0)
        {
            printf("2- Ingresar 1er operando (B = x)\n");
        }
        else
        {
            printf("2- Ingresar 1er operando (B = %.2f)\n",numeroDos);
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n\n\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            numeroUno = obtenerFloat ("\nIngrese el primer numero: ");
            flagNumeroUnoIngresado=1;
            break;
        case 2:
            numeroDos = obtenerFloat ("\nIngrese el segundo numero: ");
            flagNumeroDosIngresado=1;
            break;
        case 3:
            if (flagNumeroUnoIngresado == 0 || flagNumeroDosIngresado == 0)
            {
                printf("Debe ingresar ambos operandos antes de realizar este calculo\n");
            }
            else
            {
                printf("\nEl resultado de la suma es %.2f\n", sumaDeNumeros (numeroUno, numeroDos));
            }
            break;
        case 4:
            if (flagNumeroUnoIngresado == 0 || flagNumeroDosIngresado == 0)
            {
                printf("Debe ingresar ambos operandos antes de realizar este calculo\n");
            }
            else
            {
                printf("\nEl resultado de la resta es %.2f\n", restaDeNumeros (numeroUno, numeroDos));
            }
            break;
        case 5:
            if (flagNumeroUnoIngresado == 0 || flagNumeroDosIngresado == 0)
            {
                printf("Debe ingresar ambos operandos antes de realizar este calculo\n");
            }
            else if (divisionDeNumeros (numeroUno, numeroDos, &resultadoDivision) != -1)
            {
                printf("\nEl resultado de la division es %.2f\n", resultadoDivision);
            }
            else
            {
                printf("\nERROR No se puede dividir por 0. Ingrese otro numero.\n");
            }
            break;
        case 6:
            if (flagNumeroUnoIngresado == 0 || flagNumeroDosIngresado == 0)
            {
                printf("Debe ingresar ambos operandos antes de realizar este calculo\n");
            }
            else
            {
                printf("\nEl resultado de la multiplicacion es %.2f\n", multiplicacionDeNumeros (numeroUno, numeroDos));
            }
            break;
        case 7:
            if (flagNumeroUnoIngresado == 0 )
            {
                printf("Debe ingresar el primer operando antes de realizar este calculo\n");
            }
            else if (factorialDeUnNumero(numeroUno) != -1)
            {
                printf("El factorial es %d\n", factorialDeUnNumero ( numeroUno));
            }
            else
            {
                printf("Esta funcion solo calcula el factorial de un numero entero positivo.\n");
            }
            break;
        case 8:
            if (flagNumeroUnoIngresado == 1 && flagNumeroDosIngresado == 0)
            {
                if (factorialDeUnNumero(numeroUno) != -1)
                {
                    printf("El factorial es %d\n", factorialDeUnNumero ( numeroUno));
                }
                else
                {
                    printf("Esta funcion solo calcula el factorial de un numero entero positivo.\n");
                }
                printf("Debe ingresar ambos operandos antes de realizar el resto de las operaciones\n");

            }
            else if (flagNumeroUnoIngresado == 1 && flagNumeroDosIngresado == 1)
            {
                printf("\nEl resultado de la suma es %.2f\n", sumaDeNumeros (numeroUno, numeroDos));
                printf("El resultado de la resta es %.2f\n", restaDeNumeros (numeroUno, numeroDos));
                if (divisionDeNumeros (numeroUno, numeroDos, &resultadoDivision) != -1)
                {
                    printf("El resultado de la division es %.2f\n", resultadoDivision);
                }
                else
                {
                    printf("ERROR No se puede dividir por 0. Ingrese otro numero.\n");
                }
                printf("El resultado de la multiplicacion es %.2f\n", multiplicacionDeNumeros (numeroUno, numeroDos));
                if (factorialDeUnNumero(numeroUno) != -1)
                {
                    printf("El factorial es %d\n", factorialDeUnNumero ( numeroUno));
                }
                else
                {
                    printf("Esta funcion solo calcula el factorial de un numero entero positivo.\n");
                }
            }
            else
            {
                 printf("Debe ingresar ambos operandos antes de realizar las operaciones\n");
            }
            break;
        case 9:
            seguir = 'n';
            break;
        default:
            printf("\nIngrese una opcion valida\n");
        }
        system("pause");
    }
    return 0;
}
