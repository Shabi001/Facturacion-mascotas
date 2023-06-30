#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define NumClientes 10

void ingresarDatos(char nombres[][50], char mascotas[][50], int IDS[], int tiposMascota[], int edades[], int numClientes)
{
    printf("Ingrese su nombre: ");
    scanf("%s", nombres[numClientes]);

    printf("Ingrese el nombre de su mascota: ");
    scanf("%s", mascotas[numClientes]);

    printf("Ingrese el ID de la mascota: ");
    scanf("%d", &IDS[numClientes]);

    printf("Ingrese si es un perro o un gato (1 para perro, 2 para gato): ");
    scanf("%d", &tiposMascota[numClientes]);

    printf("Ingrese la edad de la mascota: ");
    scanf("%d", &edades[numClientes]);

    fflush(stdin);
    system("cls");
}

void seleccionarServicios(float costosTotal[], int clienteSeleccionado)
{
    int opcion;
    int seleccionarMasServicios = 1;

    while (seleccionarMasServicios)
    {
        printf("Servicios seleccionados:\n");
        printf("1. Bano para mascotas - $7.00\n");
        printf("2. Desparasitacion - $15.00\n");
        printf("3. Paseo para mascotas - $10.00\n");
        printf("4. Corte de pelo - $7.00\n");
        printf("5. salir \n");
        printf("Seleccione un servicio (1-5): ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            costosTotal[clienteSeleccionado] += 7.0;
            printf("Ha seleccionado bano para mascotas. El costo actual es $%.2f\n", costosTotal[clienteSeleccionado]);
            break;
        case 2:
            costosTotal[clienteSeleccionado] += 15.0;
            printf("Ha seleccionado desparasitacion. El costo actual es $%.2f\n", costosTotal[clienteSeleccionado]);
            break;
        case 3:
            costosTotal[clienteSeleccionado] += 10.0;
            printf("Ha seleccionado paseo para mascotas. El costo actual es $%.2f\n", costosTotal[clienteSeleccionado]);
            break;
        case 4:
            costosTotal[clienteSeleccionado] += 7.0;
            printf("Ha seleccionado corte de pelo. El costo actual es $%.2f\n", costosTotal[clienteSeleccionado]);
            break;
        case 5:
            seleccionarMasServicios = 0;
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }

        printf("\n");
        system("cls");
    }
}

void imprimirFacturacion(char nombres[][50], char mascotas[][50], int IDS[], int tiposMascota[], int edades[], float costosTotal[], int numClientes)
{
    int clienteSeleccionado;
    printf("Ingrese el ID del cliente: ");
    scanf("%d", &clienteSeleccionado);

    int clienteEncontrado = 0;
    for (int i = 0; i < numClientes; i++)
    {
        if (IDS[i] == clienteSeleccionado)
        {
            printf("== Facturacion ==\n");
            printf("Nombre del cliente: %s\n", nombres[i]);
            printf("Nombre de la mascota: %s\n", mascotas[i]);
            printf("ID de la mascota: %d\n", IDS[i]);
            printf("Edad de la mascota: %d\n", edades[i]);
            printf("Tipo de mascota: %s\n", tiposMascota[i] == 1 ? "Perro" : "Gato");
            printf("Costo total de los servicios seleccionados: $%.2f\n", costosTotal[i]);

            clienteEncontrado = 1;
            break;
        }
    }

    if (!clienteEncontrado)
    {
        printf("Cliente no encontrado\n");
    }
}