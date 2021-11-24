#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "movie.h"
#include "LinkedList.h"
#include <time.h>

/** \brief crea espacio para una pelicula
 *
 * \return eMovie*
 *
 */
eMovie* movie_new()
{
    eMovie* movie;

    movie = (eMovie*)malloc(sizeof(eMovie));

    return movie;
}

/** \brief se le asignan parametros a una pelicula
 *
 * \param idStr char*
 * \param titulo char*
 * \param genero char*
 * \param char*duracionStr
 * \return eMovie*
 *
 */
eMovie* movie_newParam(char* idStr, char* titulo, char* genero, char*duracionStr)
{
    eMovie* movie;
    movie = movie_new();
    if(movie!=NULL)
    {
        movie_setId(movie, atoi(idStr));
        movie_setTitulo(movie, titulo);
        movie_setGenero(movie, genero);
        movie_setDuracion(movie, atoi(duracionStr));
    }
    return movie;
}

/** \brief setter del id
 *
 * \param movie eMovie*
 * \param id int
 * \return int
 *
 */
int movie_setId(eMovie* movie, int id)
{
    int check=0;
    if(movie!=NULL)
    {
        check=1;
        movie->id_peli=id;
    }
    return check;
}

/** \brief setter del titulo
 *
 * \param movie eMovie*
 * \param titulo char*
 * \return int
 *
 */
int movie_setTitulo(eMovie* movie, char* titulo)
{
    int check = 0;
    if(movie!=NULL)
    {
        check = 1;
        strcpy(movie->titulo, titulo);
    }
    return check;
}

/** \brief setter del genero
 *
 * \param movie eMovie*
 * \param genero char*
 * \return int
 *
 */
int movie_setGenero(eMovie* movie, char* genero)
{
    int check = 0;
    if(movie!=NULL)
    {
        check = 1;
        strcpy(movie->genero, genero);
    }
    return check;
}

/** \brief setter de duracion
 *
 * \param movie eMovie*
 * \param duracion int
 * \return int
 *
 */
int movie_setDuracion(eMovie* movie, int duracion)
{
    int check = 0;
    if(movie!=NULL)
    {
        check = 1;
        movie->duracion = duracion;
    }
    return check;
}

/** \brief menu principal
 *
 * \return int
 *
 */
int menu()
{
    int opcion;

    system("cls");
    printf("    MENU DE OPCIONES\n\n");
    printf("    1. Cargar archivo\n");
    printf("    2. Imprimir lista\n");
    printf("    3. Asignar tiempos\n");
    printf("    4. Filtrar por genero\n");
    printf("    5. Mostrar duraciones\n");
    printf("    6. Guardar peliculas\n");
    printf("    7. Salir\n\n");
    printf("    Seleccione una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

/** \brief muestra una pelicula
 *
 * \param movie eMovie*
 * \return void
 *
 */
void mostrarMovie(eMovie* movie)
{
    if(movie!=NULL)
    {
        printf("|  %2d  |   %30s   |   %15s   |    %3d     |\n", movie->id_peli, movie->titulo, movie->genero, movie->duracion);
    }
}

/** \brief muestra listado de peliculas
 *
 * \param lista LinkedList*
 * \return int
 *
 */
int mostrarMovies(LinkedList* lista)
{
    int check = 0;
    int tam;
    if(lista!=NULL)
    {
        tam = ll_len(lista);
        system("cls");
        printf("                       ****    LISTADO DE PELICULAS    ****\n\n");
        printf("|  ID  |               TITULO               |        GENERO       |  DURACION  |\n");
        printf("================================================================================\n");
        for(int i=0; i<tam; i++)
        {
            mostrarMovie(ll_get(lista, i));
        }
        printf("================================================================================\n");
        check = 1;
    }
    return check;
}

/** \brief asigna duracion de forma random
 *
 * \param element void*
 * \return void*
 *
 */
void* asignarTiempos(void* element)
{
    eMovie* movie = NULL;
    int duracion;
    int min = 100;
    int max = 240;

    movie = (eMovie*) element;
    if(movie!=NULL)
    {
        duracion = rand()%(max-min+1)+1;

        movie->duracion = duracion;
    }
    return movie;
}


/** \brief ordena peliculas por genero y duracion
 *
 * \param movie1 void*
 * \param movie2 void*
 * \return int
 *
 */
int ordenarDuracion(void* movie1, void* movie2)
{
    int retorno= 0;
    int compararPorGenero;
    eMovie* m1;
    eMovie* m2;

    if(movie1!=NULL && movie2!=NULL)
    {
        m1 = (eMovie*)movie1;
        m2 = (eMovie*)movie2;

        compararPorGenero = strcmp(m1->genero, m2->genero);
        if(compararPorGenero!=0)
        {
            retorno = compararPorGenero;
        }
        else if(compararPorGenero == 0 && m1->duracion < m2->duracion)
        {
            retorno = -1;
        }
        else if(compararPorGenero == 0 && m1->duracion > m2->duracion)
        {
            retorno = 1;
        }
    }
    return retorno;
}


/** \brief filtra por genero adventure
 *
 * \param element void*
 * \return int
 *
 */
int filterAdventure(void* element)
{
    int retorno = 0;
    if(!strcmp(((eMovie*)element)->genero, "Adventure"))
    {
        retorno = 1;
    }
    return retorno;
}

/** \brief filtra por genero horror
 *
 * \param element void*
 * \return int
 *
 */
int filterHorror(void* element)
{
    int retorno = 0;
    if(!strcmp(((eMovie*)element)->genero, "Horror"))
    {
        retorno = 1;
    }
    return retorno;
}

/** \brief filtra por genero drama
 *
 * \param element void*
 * \return int
 *
 */
int filterDrama(void* element)
{
    int retorno = 0;
    if(!strcmp(((eMovie*)element)->genero, "Drama"))
    {
        retorno = 1;
    }
    return retorno;
}

/** \brief filtra por genero musical
 *
 * \param element void*
 * \return int
 *
 */
int filterMusical(void* element)
{
    int retorno = 0;
    if(!strcmp(((eMovie*)element)->genero, "Musical"))
    {
        retorno = 1;
    }
    return retorno;
}
