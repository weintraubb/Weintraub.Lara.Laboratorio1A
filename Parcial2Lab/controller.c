#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "LinkedList.h"
#include "parser.h"
#include "movie.h"


int controller_loadFromText(char* path, LinkedList* lista)
{
    int check = 0;
    FILE* f;
    if(path!=NULL && lista!=NULL)
    {
        f = fopen(path, "r");
        if(f!=NULL)
        {
            ll_clear(lista);
            parser_ArchivoFromText(f, lista);
            check = 1;
        }
        fclose(f);
    }
    return check;
}
void guardarArchivo(LinkedList* lista, char* archivo)
{
    FILE* f = fopen(archivo,"w");
    eMovie* aux;
    int tam = ll_len(lista);

    fprintf(f,"id_movie,titulo,genero,duracion\n\n");

    if(lista!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            aux=ll_get(lista,i);
            if(aux!=NULL)
            {
                fprintf(f,"%d,%s,%s,%d\n",aux->id_peli,aux->titulo,aux->genero,aux->duracion);
            }
        }

        fclose(f);
    }
}
