#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define NumClientes 10

int main()
{
    char nombres[NumClientes][50];  // 
    char mascotas[NumClientes][50];  // 
    int IDS[NumClientes]; // 
    int tiposMascota[NumClientes]; // 
    int edades[NumClientes]; // 
    float costosTotal[NumClientes] = {0.0}; // 
    int numClientes = 0; //
    int opcion; //

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

            if (numClientes < NumClientes)  // el if que se usa aqui es para ver si se alcanzo el numero maximo de clientes
            {
                ingresarDatos(nombres, mascotas, IDS, tiposMascota, edades, numClientes); // solicite al usuario que ingrese los datos relacionados con un cliente y su mascota, y los almacene en las variables correspondientes.
                numClientes++; // se incrementa en 1 al numero de clientes que hay 
            }
            else
            {
                printf("Se alcanzo el maximo de clientes\n"); // esto aparece si el numero maximo de clientes fue alcanzado
            }

            break;
        case 2:
            printf("== Seleccion de servicios ==\n"); 

            if (numClientes > 0) // esta condicion verifica si hay algun cliente ingresado, es necessario ingresa a almenos 1 cliente para iniciar este apartado
            {
                int clienteSeleccionado;
                printf("Seleccione un cliente (1-%d): ", numClientes);
                scanf("%d", &clienteSeleccionado);

                if (clienteSeleccionado >= 1 && clienteSeleccionado <= numClientes) // esta es una condicion donde pones el numero del cliente al que quieres ir, en caso de que no este el numero marca error
                {
                    seleccionarServicios(costosTotal, clienteSeleccionado - 1); // si el numero esta dentro del rango, vemos el apartado seleciona servicios 
                }
                else
                {
                    printf("Cliente invalido\n"); // este error 
                }
            }
            else
            {
                printf("No hay clientes ingresados\n"); // si no hay el numero del cliente salta este erro 
            }

            break;
        case 3:
            if (numClientes > 0) // veerifica nuevamente el numero de clientes 
            {
                imprimirFacturacion(nombres, mascotas, IDS, tiposMascota, edades, costosTotal, numClientes); // imprime estos datos en la factura 
            }
            else
            {
                printf("No hay clientes ingresados\n"); // si no se ingreso nada, salta este mensaje 
            }

            break;
        case 4:
            printf("== Salir ==\n"); 
            return 0;
        default:
            printf("Opcion invalida. Por favor, ingrese una opcion valida.\n"); // si marca algun numero que no esta especificado, salta este mensaje 
            break;
        }
    }

    return 0;
}
