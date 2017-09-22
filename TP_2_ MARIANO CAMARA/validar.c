#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"

#define MAX_INPUT_BUFFER 2207

// Funciones privadas
static int validarUnsignedInt(char* buffer);
static void myFgets(char* buffer, int limite ,FILE* archivo);
static int validarNombre(char* buffer);
//

int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char bufferNombre[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {
            myFgets(bufferNombre, limite,stdin);

            if(validarNombre(bufferNombre) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,bufferNombre,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


static int validarNombre(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] < 'a' || buffer[i] > 'z')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}


int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(validarUnsignedInt(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


static int validarUnsignedInt(char* buffer)
{
    int i=0;
    int retorno = 0;

    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9' )
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}


static void myFgets(char* buffer, int limite,FILE* archivo)
{
    int i=0;
    fgets(buffer, limite,archivo);
    buffer[limite-1] = '\0';
    while(buffer[i] != '\0')
    {
        if(buffer[i] == 10)//10 -> LF
        {
            buffer[i] = '\0';
            break;
        }
        i++;
    }
}
