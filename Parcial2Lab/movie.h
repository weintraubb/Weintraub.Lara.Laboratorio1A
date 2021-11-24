#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
   int id_peli;
   char titulo[100];
   char genero[50];
   int duracion;
}eMovie;

#endif // MOVIE_H_INCLUDED

eMovie* movie_new();
eMovie* movie_newParam(char* idStr, char* titulo, char* genero, char*duracionStr);
int movie_setId(eMovie* movie, int id);
int movie_setTitulo(eMovie* movie, char* titulo);
int movie_setGenero(eMovie* movie, char* genero);
int movie_setDuracion(eMovie* movie, int duracion);
int menu();
void mostrarMovie(eMovie* movie);
int mostrarMovies(LinkedList* lista);
void* asignarTiempos(void* element);
int filtrarPorGenero(void* element);
int ordenarDuracion(void* movie1, void* movie2);

