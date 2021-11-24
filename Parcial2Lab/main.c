#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "movie.h"

int main()
{
    int salir = 0;
    int flagCarga = 0;

    LinkedList* lista = ll_newLinkedList();

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
            break;
        case 5:
            ll_sort(lista, ordenarDuracion, 1);
            mostrarMovies(lista);
            break;
        case 6:
            guardarArchivo(lista, "movies.csv");
            break;
        case 7:
            salir = 1;
            break;
        }
        system("pause");
    }while(salir == 0);
    return 0;
}
