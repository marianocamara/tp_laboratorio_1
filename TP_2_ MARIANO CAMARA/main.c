#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "validar.h"
#define CANTIDAD_PERSONAS 20



int main()
{
    ePersona arrayPersonas[CANTIDAD_PERSONAS];
    persona_initPersona (arrayPersonas, CANTIDAD_PERSONAS);
    char bufferOpcion[10];


    do
    {
        val_getUnsignedInt(bufferOpcion,"\n\n1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por  nombre\n4- Imprimir grafico de edades\n\n5- Salir\n\n","\nIngrese una opcion valida. \n",3,10);

        switch(atoi(bufferOpcion))
        {
            case 1:
                persona_CargarPersona(arrayPersonas,persona_buscarPosicionPersonaLibre(arrayPersonas,CANTIDAD_PERSONAS));
                break;
            case 2:
                persona_borrarPersonaPorDni(arrayPersonas,CANTIDAD_PERSONAS);
                break;
            case 3:
                persona_printPersona(arrayPersonas,CANTIDAD_PERSONAS);
                break;
            case 4:
                persona_imprimirGraficoEdades(arrayPersonas,CANTIDAD_PERSONAS);
                break;
        }


    }while(atoi(bufferOpcion) != 5);

    return 0;
}


