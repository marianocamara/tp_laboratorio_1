#include <stdio.h>
#include <stdlib.h>
#include "movie.h"
#include "validar.h"
#include <string.h>

/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado en 0
 * \param puntero array de entidad
 * \param lenArray int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 */
int mov_init (EMovie* listaMovies, int lenLista)
{
    int retorno = -1;
    int i;
    if(listaMovies != NULL && lenLista > 0)
    {
        for(i=0; i<lenLista ; i++)
        {
            listaMovies[i].flagOcupado = MOVIE_LIBRE;
        }

    }
    return retorno;
}

/** \brief Genera un id(+1) a partir del ultimo encontrado
 * \param
 * \param
 * \return int el id generado
 */

int mov_GenerarNuevoId (EMovie* listaMovies, int lenLista)
{
    int idMax = -1;
    int i;
    if(listaMovies != NULL && lenLista > 0)
    {
        for(i=0; i<lenLista ; i++)
        {
            if(listaMovies[i].flagOcupado == MOVIE_OCUPADO && listaMovies[i].id > idMax)
            {
                idMax = listaMovies[i].id;
            }
        }
        idMax ++;
    }
    return idMax;
}

/** \brief busca el proximo index libre donde cargar la entidad
 * \param puntero array listaPantallas de estructura sPantalla
 * \param lenLista int Longitud del listaPantallas
 * \return int el primer index libre encontrado // -1 Error en parametros pasados o no hay posicion libre
 *
 */

int mov_buscarPosicionLibre (EMovie* listaMovies,int lenLista)
{
    int retorno = -1;
    int i;
    if(listaMovies != NULL && lenLista > 0)
    {
        for(i=0; i<lenLista ; i++)
        {
            if(listaMovies[i].flagOcupado == MOVIE_LIBRE)
            {
                retorno =  i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief busca el index de id pasado como parametro
 *
 * \param puntero listaMovies de entidad
 * \param lenLista int Longitud del listaMovies
 * \param int id para buscar su index
 * \return int index de la entidad donde se encuentra ese id // -1 Error de parametros pasados o no se encontro el index
 *
 */

int mov_buscarIndicePorId(EMovie* listaMovies, int lenLista, int id)
{
    int i;
    int retorno = -1;
    if(listaMovies != NULL && lenLista > 0 && id >= 0)
    {
        for(i=0; i<lenLista ; i++)
        {
            if(listaMovies[i].flagOcupado == MOVIE_OCUPADO)
            {
                if(id == listaMovies[i].id)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}

/** \brief Carga todos los campos de la entidad en un index vacio y genera su id, validando datos ingresados en cada caso
 *
 * \param puntero array listaMovies de entidad
 * \param lenLista int Longitud del listaMovies
 * \return 0 si pudo cargar los datos correctanmente, -1 error de carga o de parametros pasados
 *
 */

int mov_alta(EMovie* listaMovies, int lenLista)
{
    int retorno = -1;
    int indexVacio;
    int idNuevo;

    if(listaMovies != NULL && lenLista > 0)
    {
        indexVacio = mov_buscarPosicionLibre (listaMovies,lenLista);
        if (indexVacio >= 0)
        {
            char bufferTitulo[50];
            char bufferGenero[50];
            char bufferDuracion[50];
            char bufferDescripcion[50];
            char bufferPuntaje[50];
            char bufferLinkImagen[50];

            if (val_getNombre(bufferTitulo,"Ingrese titulo de la pelicula:\n","Ingrese un titulo valido:\n",2,50)!= -1)
            {
                if (val_getNombre(bufferGenero,"Ingrese genero de la pelicula:\n","Ingrese un genero valido:\n",2,50) != -1 )
                {
                    if (val_getUnsignedInt(bufferDuracion,"Ingrese la duracion de la pelicula:\n","Ingrese un numero valido:\n",2,50) != -1 )
                    {
                        if (val_getNombre(bufferDescripcion,"Ingrese la descripcion de la pelicula\n","\nIngrese una descripcion valida\n",2,50) != -1 )
                        {
                            if (val_getUnsignedInt(bufferPuntaje,"Ingrese el puntaje de la pelicula:\n","Ingrese un numero valido:\n",2,50) != -1 )
                            {
                                if (val_getLink(bufferLinkImagen,"Ingrese el link de la imagen de la pelicula\n","\nIngrese una link valido\n",2,50) != -1 )
                                {

                                    idNuevo = mov_GenerarNuevoId(listaMovies,lenLista);
                                    listaMovies[indexVacio].id = idNuevo;
                                    listaMovies[indexVacio].flagOcupado = MOVIE_OCUPADO;

                                    strncpy(listaMovies[indexVacio].titulo,bufferTitulo,50);
                                    strncpy(listaMovies[indexVacio].genero,bufferGenero,50);
                                    listaMovies[indexVacio].duracion = atoi(bufferDuracion);
                                    strncpy(listaMovies[indexVacio].descripcion,bufferDescripcion,50);
                                    listaMovies[indexVacio].puntaje = atoi(bufferPuntaje);
                                    strncpy(listaMovies[indexVacio].linkImagen,bufferLinkImagen,50);
                                    printf("\nSe han cargado los datos exitosamente.\n");

                                    retorno = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            printf("\nNo hay posiciones libres.");
        }
    }
    return retorno;
}


/** \brief Carga todos los campos de la entidad en un index vacio y genera su id, validando datos ingresados en cada caso
 *
 * \param puntero array listaMovies de entidad
 * \param lenLista int Longitud del listaMovies
 * \return 0 si pudo cargar los datos correctanmente, -1 error de carga o de parametros pasados
 *
 */

int mov_modificar(EMovie* listaMovies, int lenLista)
{
    int retorno = -1;
    char bufferIdModificar[50];

    if(listaMovies != NULL && lenLista > 0)
    {
        if (val_getUnsignedInt(bufferIdModificar,"\nIngrese ID de lapelicula a modificar:\n","\nIngese un ID valido\n",2,50) != -1)
        {

            int index = mov_buscarIndicePorId(listaMovies,lenLista,atoi(bufferIdModificar));

            if(index >= 0)

            {
                char bufferTitulo[50];
                char bufferGenero[50];
                char bufferDuracion[50];
                char bufferDescripcion[50];
                char bufferPuntaje[50];
                char bufferLinkImagen[50];

                if (val_getNombre(bufferTitulo,"Ingrese nuevo titulo de la pelicula:\n","Ingrese un titulo valido:\n",2,50)!= -1)
                {
                    if (val_getNombre(bufferGenero,"Ingrese nuevo genero de la pelicula:\n","Ingrese un genero valido:\n",2,50) != -1 )
                    {
                        if (val_getUnsignedInt(bufferDuracion,"Ingrese la nueva duracion de la pelicula:\n","Ingrese un numero valido:\n",2,50) != -1 )
                        {
                            if (val_getNombre(bufferDescripcion,"Ingrese la nueva descripcion de la pelicula\n","\nIngrese una descripcion valida\n",2,50) != -1 )
                            {
                                if (val_getUnsignedInt(bufferPuntaje,"Ingrese el nuevo puntaje de la pelicula:\n","Ingrese un numero valido:\n",2,50) != -1 )
                                {
                                    if (val_getLink(bufferLinkImagen,"Ingrese el nuevo link de la imagen de la pelicula\n","\nIngrese una link valido\n",2,50) != -1 )
                                    {

                                        strncpy(listaMovies[index].titulo,bufferTitulo,50);
                                        strncpy(listaMovies[index].genero,bufferGenero,50);
                                        listaMovies[index].duracion = atoi(bufferDuracion);
                                        strncpy(listaMovies[index].descripcion,bufferDescripcion,50);
                                        listaMovies[index].puntaje = atoi(bufferPuntaje);
                                        strncpy(listaMovies[index].linkImagen,bufferLinkImagen,50);
                                        printf("Se han modificado los datos exitosamente.");

                                        retorno = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                printf("\nEl ID ingresado no pertenece a ninguna pelicula.\n");
            }
        }

    }
    return retorno;
}




/** \brief realiza baja de una entidad colocando el flag estado en libre (0)
 *
 * \param puntero listaEMovie de entidad
 * \param lenLista int Longitud del listaMovie
 * \return 0 si dio de baja correctamente -1 error parametros o index no encontrado
 *
 */

int mov_bajaMovie(EMovie* listaMovies, int lenListaMovies)
{
    int retorno = -1;
    char bufferIdBaja[50];

    if(listaMovies != NULL && lenListaMovies > 0)
    {
        val_getUnsignedInt(bufferIdBaja,"\nIngrese ID de la pelicula a dar de baja:\n","\nIngese un ID valido:\n",2,50);
        int index = mov_buscarIndicePorId(listaMovies,lenListaMovies,atoi(bufferIdBaja));

        if(index >= 0)
        {
            listaMovies[index].flagOcupado = MOVIE_LIBRE;
            printf("\nSe ha dado de baja la pelicula seleccionada.\n");
            retorno = 0;
        }
        else
        {
            printf("\nNo se ha encontrado el ID ingresado.\n");
        }
    }
    return retorno;
}


int mov_listarMovies (EMovie* listaMovies,int lenListaMovies)
{
    int retorno = -1;
    int index;
    int contadorMovies = 0;
    printf("*************************************************************\n");
    printf("************************* PELICULAS *************************\n");
    printf("*************************************************************\n");
    if(listaMovies != NULL && lenListaMovies > 0 )
    {
        for (index=0; index<lenListaMovies; index++)
        {
            if(listaMovies[index].flagOcupado == MOVIE_OCUPADO)
            {
                contadorMovies++;
                printf("\nID Pelicula: %d\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink Imagen: %s\n",listaMovies[index].id,listaMovies[index].titulo,
                       listaMovies[index].genero,
                       listaMovies[index].duracion,
                       listaMovies[index].descripcion,
                       listaMovies[index].puntaje,
                       listaMovies[index].linkImagen);
                retorno = 0;
            }
        }
        printf("\n*************************************************************\n");
        printf("*************************************************************\n");
        if(contadorMovies == 0)
        {
            printf("\nNo hay ninguna pelicula cargada en el sistema.\n");
        }

    }
    return retorno;
}


/** \brief lee un archivo binario
 * \param puntero listaMovies de entidad
 * \param lenLista int Longitud del listaMovies
 * \return 0 OK / -1 ERROR
 *
 */

int mov_LeerArchivoBinario(EMovie* listaMovies,int lenListaMovies)
{
    int retorno = 0;
    FILE *pMovie;
    int cantMoviesLeidas;

    pMovie = fopen("InfoMovies.bin", "rb");

    if(pMovie == NULL)
    {
        printf("\nNo se pudo leer el archivo\n");
        retorno = -1;
    }
    cantMoviesLeidas = fread(listaMovies,sizeof(EMovie),lenListaMovies,pMovie);
    if(cantMoviesLeidas != lenListaMovies)
    {
        printf("\nError de lectura\n");
        retorno = -1;
    }
    fclose(pMovie);

    return retorno;
}


/** \brief escribe un archivo binario
 * \param puntero listaMovies de entidad
 * \param lenLista int Longitud del listaMovies
 * \return 0 OK / -1 ERROR
 *
 */
int mov_escribirArchivoBinario(EMovie* listaMovies,int lenListaMovies)
{
    int retorno=0;

    FILE *pMovie;
    int cantMoviesEscritas;

    pMovie = fopen("InfoMovies.bin", "wb");

    if(pMovie == NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
        retorno = -1;
    }
    else
    {
        cantMoviesEscritas = fwrite(listaMovies,sizeof(EMovie),lenListaMovies,pMovie);
        if(cantMoviesEscritas < lenListaMovies)
        {
            printf("\nError de escritura\n");
            retorno = -1;
        }
    }
    fclose(pMovie);

    return retorno;
}

/** \brief genera archivo html
 * \param puntero listaMovies de entidad
 * \param lenLista int Longitud del listaMovies
 * \return 0 si se realizo la carga correctamente o -1 si no se pudo
 *
 */
int mov_generarArchivoHtml (EMovie* listaMovies,int lenListaMovies)
{
    int retorno = -1;

    FILE *pAntes;
    FILE *pMovie;
    FILE *pContenido;
    FILE *pDespues;
    int i;
    char antes[1500];
    char contenido[500];
    char despues[1500];

    pMovie=fopen("index.html","w");

    if(pMovie!=NULL)
    {
        pAntes=fopen("html-antes.txt","r");
        fread(antes,sizeof(char),1500,pAntes);
        fclose(pAntes);
        fprintf(pMovie,"%s",antes);


        pContenido=fopen("html-contenido.txt","r");
        fread(contenido,sizeof(char),500,pContenido);
        fclose(pContenido);

        for(i=0; i<lenListaMovies; i++)
        {
            if(listaMovies[i].flagOcupado== MOVIE_OCUPADO)
            {
                fprintf(pMovie,contenido,(listaMovies+i)->linkImagen, (listaMovies+i)->titulo, (listaMovies+i)->genero,
                        (listaMovies+i)->puntaje, (listaMovies+i)->duracion, (listaMovies+i)->descripcion);
                retorno = 0;
            }
        }
        pDespues=fopen("html-despues.txt","r");
        fread(despues,sizeof(char),1500,pDespues);
        fclose(pDespues);
        fprintf(pMovie,"%s",despues);
    }

    fclose(pMovie);
    return retorno;
}

