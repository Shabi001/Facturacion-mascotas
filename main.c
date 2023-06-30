#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define NumClientes 10

int main()
{
    char nombres[NumClientes][50];
    char mascotas[NumClientes][50];
    int IDS[NumClientes];
    int tiposMascota[NumClientes];
    int edades[NumClientes];
    float costosTotal[NumClientes] = {0.0};
    int numClientes = 0;
    int opcion;

    while (1)
    {
        printf("=== MENU ===\n");
        printf("1. Ingrese los Datos\n");
        printf("2. Seleccion de servicios\n");
        printf("3. Facturacion\n");
        printf("4. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        system("cls");

        switch (opcion)
        {
        case 1:
            printf("== Ingreso de datos ==\n");

            if (numClientes < NumClientes)
            {
                ingresarDatos(nombres, mascotas, IDS, tiposMascota, edades, numClientes);
                numClientes++;
            }
            else
            {
                printf("Se alcanzo el maximo de clientes\n");
            }

            break;
        case 2:
            printf("== Seleccion de servicios ==\n");

            if (numClientes > 0)
            {
                int clienteSeleccionado;
                printf("Seleccione un cliente (1-%d): ", numClientes);
                scanf("%d", &clienteSeleccionado);

                if (clienteSeleccionado >= 1 && clienteSeleccionado <= numClientes)
                {
                    seleccionarServicios(costosTotal, clienteSeleccionado - 1);
                }
                else
                {
                    printf("Cliente invalido\n");
                }
            }
            else
            {
                printf("No hay clientes ingresados\n");
            }

            break;
        case 3:
            if (numClientes > 0)
            {
                imprimirFacturacion(nombres, mascotas, IDS, tiposMascota, edades, costosTotal, numClientes);
            }
            else
            {
                printf("No hay clientes ingresados\n");
            }

            break;
        case 4:
            printf("== Salir ==\n");
            return 0;
        default:
            printf("Opcion invalida. Por favor, ingrese una opcion valida.\n");
            break;
        }
    }

    return 0;
}
