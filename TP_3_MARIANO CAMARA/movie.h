#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int flagOcupado;
    int id;
}EMovie;


#endif // MOVIE_H_INCLUDED

#define MOVIE_LIBRE 0
#define MOVIE_OCUPADO 1


int mov_init (EMovie* listaMovies, int lenLista);
int mov_buscarPosicionLibre (EMovie* listaMovies,int lenLista);
int mov_alta(EMovie* listaMovies, int lenLista);
int mov_modificar(EMovie* listaMovies, int lenLista);
int mov_listarMovies (EMovie* listaMovies,int lenListaMovies);
int mov_bajaMovie(EMovie* listaMovies, int lenListaMovies);

int mov_escribirArchivoBinario(EMovie* listaMovies,int lenListaMovies);
int mov_LeerArchivoBinario(EMovie* listaMovies,int lenListaMovies);

int mov_generarArchivoHtml (EMovie* listaMovies,int lenListaMovies);




/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[]);
