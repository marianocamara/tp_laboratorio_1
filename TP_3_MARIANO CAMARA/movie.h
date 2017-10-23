#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[1000];
    int puntaje;
    char linkImagen[1000];
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

