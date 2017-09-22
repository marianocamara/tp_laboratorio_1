#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "validar.h"

// Funciones privadas
static int buscarPersonaPorDni (ePersona* arrayPersonas, int longitud);
static void OrdenarAlfabeticamentePorNombre(ePersona* arrayPersonas, int longitud);
//

int persona_initPersona (ePersona* arrayPersonas, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPersonas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayPersonas[i].estado = PERSONA_LIBRE;
        }
    }
    return retorno;
}

int persona_buscarPosicionPersonaLibre (ePersona* arrayPersonas, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPersonas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPersonas[i].estado == PERSONA_LIBRE)
            {
                retorno =  i;
                break;
            }
        }
    }
    return retorno;
}


int persona_CargarPersona (ePersona* arrayPersonas, int index)
{
    int retorno = -1;
    char bNombre[51];
    char bEdad[51];
    char bDni [51];

    if(arrayPersonas != NULL && index >= 0)
    {
        if(val_getNombre(bNombre,"\nIngrese el nombre de la persona: ","\nHa ocurrido un error, ingrese el nombre nuevamente. \n",3,51) == 0)
        {

            if(val_getUnsignedInt(bEdad,"Ingrese la edad de la persona: ","\nHa ocurrido un error, ingrese la edad nuevamente. \n",3,51) == 0)
            {
                if (val_getUnsignedInt(bDni,"Ingrese el dni de la persona: ","\nSolo se permite ingresar numeros sin punto, ingrese el dni nuevamente. \n",3,51) == 0)
                {
                    strncpy(arrayPersonas[index].nombre,bNombre,51);
                    strncpy(arrayPersonas[index].dni,bDni,51);
                    arrayPersonas[index].edad = atoi(bEdad);
                    arrayPersonas[index].estado = PERSONA_OCUPADO;
                    retorno = 0;
                }
            }
        }

    }
    return retorno;
}

int persona_printPersona (ePersona* arrayPersonas, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPersonas!= NULL && longitud > 0)
    {
        OrdenarAlfabeticamentePorNombre(arrayPersonas,longitud);
        for(i=0; i<longitud ; i++)
        {
            if(arrayPersonas[i].estado == PERSONA_OCUPADO)
            {
                printf("\nNombre: %s\nEdad: %d\nDni:%s\n",arrayPersonas[i].nombre,arrayPersonas[i].edad,arrayPersonas[i].dni);
                retorno = 0;
            }
        }
    }
    return retorno;
}

static int buscarPersonaPorDni (ePersona* arrayPersonas, int longitud)
{
    int retorno = -1;
    int i;
    char bDniIngresado [51];

    val_getUnsignedInt(bDniIngresado,"\nIngrese el DNI de la persona que desea borrar: ","\nIngrese un DNI valido. ",3,40);

    if(arrayPersonas!= NULL && longitud > 0)
    {
        for(i=0 ; i<longitud ; i++)
        {
            if(strcmp(bDniIngresado,arrayPersonas[i].dni) == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int persona_borrarPersonaPorDni (ePersona* arrayPersonas, int longitud)
{
    int retorno = -1;
    int index;
    if(arrayPersonas!= NULL && longitud > 0)
    {

        index = buscarPersonaPorDni(arrayPersonas,longitud);

        if(index != -1)
        {
            arrayPersonas[index].estado = PERSONA_LIBRE;
            printf("\nSe ha borrado a la persona exitosamente.\n");
        }
        else
        {
            printf("\nNo se ha encontrado el DNI ingresado.\n");
        }
    retorno = 0;
    }
    return retorno;
}


static void OrdenarAlfabeticamentePorNombre(ePersona* arrayPersonas, int longitud)
{
    int i, j;
    ePersona temporal;
    for (i = 1; i < longitud; i++)
    {
        temporal = arrayPersonas[i];
        j = i-1;

        while (j >= 0 && strcmp(temporal.nombre,arrayPersonas[j].nombre)<0)
        {
            arrayPersonas[j+1]=arrayPersonas[j];
            --j;
        }
        arrayPersonas[j+1] = temporal;
    }
}

int persona_imprimirGraficoEdades(ePersona* arrayPersonas,int longitud)
{
    int retorno = -1;
    int contador18oMenor=0;
    int contadorEntre19y35=0;
    int contadormayor35=0;
    int i;
    int j;
    int graficoEjeY;

    if(arrayPersonas!= NULL && longitud > 0)
    {

    for(i=0; i<longitud; i++)
    {
        if(arrayPersonas[i].estado== PERSONA_OCUPADO)
        {

            if (arrayPersonas[i].edad <= 18)
            {
                contador18oMenor++;
            }
            else if (arrayPersonas[i].edad > 35)
            {
                contadormayor35++;
            }
            else if(arrayPersonas[i].edad > 18 && arrayPersonas[i].edad <= 35 )
            {
                contadorEntre19y35++;
            }
        }
    }

    if(contador18oMenor > contadorEntre19y35 && contador18oMenor > contadormayor35)
    {
        graficoEjeY = contador18oMenor;
    }
    else if(contadorEntre19y35 > contadormayor35)
    {
        graficoEjeY = contadorEntre19y35;
    }
    else
    {
        graficoEjeY = contadormayor35;
    }

    for (j = graficoEjeY; j > 0 ; j--)
    {
        if (contador18oMenor >= j)
        {
            printf("\t  *");
        }
        else
        {
            printf("\t   ");
        }
        if (contadorEntre19y35 >= j)
        {
            printf("\t  *");
        }
        else
        {
            printf("\t     ");
        }
        if (contadormayor35 >= j)
        {
            printf("\t  *\n");
        }
        else
        {
            printf("\t \n");
        }
    }
    printf("\t<18\t19-35\t>35");
    retorno = 0;
    }
    return retorno;
}






















