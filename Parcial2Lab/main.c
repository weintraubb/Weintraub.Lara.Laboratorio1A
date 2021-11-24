#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "movie.h"

int main()
{
    int salir = 0;
    int flagCarga = 0;
    int genero;

    LinkedList* lista = ll_newLinkedList();
    LinkedList* filtrada;

    do
    {
        switch(menu())
        {
        case 1:
            if(controller_loadFromText("movies.csv", lista))
            {
                printf("\n    Archivo cargado con exito!!\n\n");
                flagCarga = 1;
            }
            else
            {
                printf("\n    Hubo un problema al cargar el archivo.\n\n");
            }
            break;
        case 2:
            if(flagCarga)
            {
                mostrarMovies(lista);
            }
            else
            {
                printf("Primero debe cargar un archivo\n\n");
            }
            break;
        case 3:
            if(flagCarga)
            {
                if(ll_map(lista, asignarTiempos)!=NULL)
                {
                    printf("\n    Tiempos asignados con exito!!\n\n");
                }
                else
                {
                    printf("\n    Hubo un ptoblema al asignar los tiempos\n\n");
                }
            }
            break;
        case 4:
            if(flagCarga)
            {
                printf("    Seleccione un genero:\n\n");
                printf("    1. Adventure\n");
                printf("    2. Horror\n");
                printf("    3. Drama\n");
                printf("    4. Musical\n");
                scanf("%d", &genero);
                switch(genero)
                {
                case 1:
                    filtrada = ll_filter(lista, filterAdventure);
                    mostrarMovies(filtrada);
                    break;
                case 2:
                    filtrada = ll_filter(lista, filterHorror);
                    mostrarMovies(filtrada);
                    break;
                case 3:
                    filtrada = ll_filter(lista, filterDrama);
                    mostrarMovies(filtrada);
                    break;
                case 4:
                    filtrada = ll_filter(lista, filterMusical);
                    mostrarMovies(filtrada);
                    break;
                }
                break;
            }
            else
            {
                printf("\n\n    Primero debe cargar el archivo\n\n");
            }
        case 5:
            if(flagCarga)
            {
                ll_sort(lista, ordenarDuracion, 1);
                mostrarMovies(lista);
            }
            else
            {
                printf("\n\n    Primero debe cargar el archivo\n\n");
            }
            break;
        case 6:
            if(flagCarga)
            {
                guardarArchivo(lista, "movies.csv");
            }
            else
            {
                printf("\n\n    Primero debe cargar el archivo\n\n");
            }
            break;
        case 7:
            salir = 1;
            break;
        }
        system("pause");
    }
    while(salir == 0);
    return 0;
}
