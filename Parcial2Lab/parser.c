#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "movie.h"
#include "LinkedList.h"

int parser_ArchivoFromText(FILE* pFile, LinkedList* lista)
{
    int check = 0;
    char idStr[50];
    char titulo[100];
    char genero[50];
    char duracionStr[50];
    eMovie* aux;

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, titulo, genero, duracionStr);
    do
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, titulo, genero, duracionStr);
        aux = movie_newParam(idStr, titulo, genero, duracionStr);
        if(aux!=NULL)
        {
            ll_add(lista, aux);
            check = 1;
        }
    }while(!feof(pFile));

    return check;
}
