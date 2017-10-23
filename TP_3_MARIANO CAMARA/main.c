#include <stdio.h>
#include <stdlib.h>
#include "movie.h"
#include "validar.h"

#define LEN_MOVIES 5


int main()
{

    char bufferOpcion[10];

    EMovie listaMovies[LEN_MOVIES];
    mov_init(listaMovies,LEN_MOVIES);
    mov_LeerArchivoBinario(listaMovies,LEN_MOVIES);

    do
    {
        val_getUnsignedInt(bufferOpcion,"\n1- Agregar pelicula\n2- Borrar pelicula\n3- Modificar pelicula\n4- Generar pagina web\n5- Salir\n\nIngrese una opcion: ","\nIngrese una opcion valida.\n",3,10);

        switch(atoi(bufferOpcion))
            {
            case 1:
                if (mov_alta(listaMovies,LEN_MOVIES) == 0)
                    mov_escribirArchivoBinario(listaMovies,LEN_MOVIES);
                break;
            case 2:
                mov_listarMovies(listaMovies,LEN_MOVIES);
                if (mov_bajaMovie(listaMovies,LEN_MOVIES) == 0)
                    mov_escribirArchivoBinario(listaMovies,LEN_MOVIES);
                break;
            case 3:
                mov_listarMovies(listaMovies,LEN_MOVIES);
                if(mov_modificar(listaMovies,LEN_MOVIES) == 0)
                    mov_escribirArchivoBinario(listaMovies,LEN_MOVIES);
                break;
            case 4:
                if (mov_generarArchivoHtml(listaMovies,LEN_MOVIES) == 0)
                    printf("\nSe ha generado un archivo index.html\n");
                break;
            case 5:
                printf("\nHasta luego!\n");
                break;
            default:
                printf("\nIngrese un numero que se encuentre dentro de las opciones.\n");
                break;
            }
    }while( atoi(bufferOpcion) != 5);

    return 0;
}
