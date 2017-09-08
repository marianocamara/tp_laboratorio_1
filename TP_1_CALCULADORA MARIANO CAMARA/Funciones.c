#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief pide ingresar un numero flotante
 *
 * \param mensaje para el usuario
 * \return devuelve el numero ingesado
 *
 */

float obtenerFloat (char mensaje[])
{
    float numero;

    printf("%s", mensaje);
    scanf("%f",&numero);

    return numero;
}

/** \brief Suma dos numeros
 *
 * \param numero uno ingresado por el usuario
 * \param numero dos ingresado por el usuario
 * \return resultado de la suma
 *
 */


float sumaDeNumeros (float numeroUno, float numeroDos)
{
    float resultadoSuma = numeroUno + numeroDos;
    return resultadoSuma;
}

/** \brief Resta dos numeros
 *
 * \param numero uno
 * \param numero dos
 * \return resultado de la resta
 *
 */


float restaDeNumeros (float numeroUno, float numeroDos)
{
    float resultadoResta = numeroUno - numeroDos;
    return resultadoResta;
}

/** \brief Multiplica dos numeros
 *
 * \param numero uno
 * \param numero dos
 * \return resultado de la multiplicacion
 *
 */


float multiplicacionDeNumeros (float numeroUno,float numeroDos)
{
    float resultadoMultiplicacion = numeroUno * numeroDos;
    return resultadoMultiplicacion;
}

/** \brief Divide el primer numero por el segundo
 *
 * \param numero uno
 * \param numero dos
 * \param pasa por referencia el resultado
 * \return ERROR -1 division por cero || 0 sin error
 *
 */

int divisionDeNumeros (float numeroUno, float numeroDos, float *pResultadoDivision)
{
    int retorno = -1;

    if (numeroDos != 0)
    {
      *pResultadoDivision = numeroUno / numeroDos;
      retorno = 0;
    }

    return retorno ;
}

/** \brief calcula el factorial de un numero
 *
 * \param numeroUno
 * \param
 * \return -1 ERROR (numero es con decimal o negativo) , cualquier numero positivo es valido y es el resultado (1 si el numero es 0 o 1)
 *
 */

int factorialDeUnNumero (float numeroUno)
{
    int resultadoParcialFactorial = 1;
    int resultadoFactorial,i;
    int validarEntero;

    validarEntero = (int)numeroUno;

    if (numeroUno == validarEntero && numeroUno >= 0)
    {
        for(i = numeroUno;i>1;i--)
        {
            resultadoParcialFactorial = resultadoParcialFactorial * i;
        }
    }
    else
    {
        resultadoParcialFactorial = -1;
    }
    resultadoFactorial = resultadoParcialFactorial;
    return resultadoFactorial;

}










