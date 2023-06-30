#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define NumClientes 10

void ingresarDatos(char nombres[][50], char mascotas[][50], int IDS[], int tiposMascota[], int edades[], int numClientes)
{

    // apartado para ingresar los datos de los clientes 
    printf("Ingrese su nombre: ");          // su nombre            
    scanf("%s", nombres[numClientes]); // lee lo que se puso y lo alamcena en un arreglo llamado nombres en la parte de numclientes

    printf("Ingrese el nombre de su mascota: "); //nombre de la mascota
    scanf("%s", mascotas[numClientes]);

    printf("Ingrese el ID de la mascota: "); //id de la mascota
    scanf("%d", &IDS[numClientes]);

    printf("Ingrese si es un perro o un gato (1 para perro, 2 para gato): ");   // tiene que especificar si es perro o gato 
    scanf("%d", &tiposMascota[numClientes]);

    printf("Ingrese la edad de la mascota: "); // edad de la mascota 
    scanf("%d", &edades[numClientes]);

    fflush(stdin); // vacia el bufer de entrada (evita errores)
    system("cls"); // limpia el cmd
}

void seleccionarServicios(float costosTotal[], int clienteSeleccionado)
{
    int opcion;
    int seleccionarMasServicios = 1;

    while (seleccionarMasServicios)
    {
        printf("Servicios seleccionados:\n");              // en esta parte tenemos el menu de los servicios 
        printf("1. Bano para mascotas - $7.00\n");         // cada uno con su precio 
        printf("2. Desparasitacion - $15.00\n");
        printf("3. Paseo para mascotas - $10.00\n");
        printf("4. Corte de pelo - $7.00\n");
        printf("5. salir \n");
        printf("Seleccione un servicio (1-5): ");   
        scanf("%d", &opcion);

        switch (opcion)  
        {
        case 1:
            costosTotal[clienteSeleccionado] += 7.0; // costo total ess un arreglo que almacena los costos de los servicios 
            printf("Ha seleccionado bano para mascotas. El costo actual es $%.2f\n", costosTotal[clienteSeleccionado]);
            break;
        case 2:
            costosTotal[clienteSeleccionado] += 15.0; // el += en cada arreglo que suma a la varriable de antes
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
            seleccionarMasServicios = 0; // ya no quieres mas servicios selecionamos el caso 5 que ddevuelve 0 
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }

        printf("\n");

    }
}

void imprimirFacturacion(char nombres[][50], char mascotas[][50], int IDS[], int tiposMascota[], int edades[], float costosTotal[], int numClientes)
{
    int clienteSeleccionado;
    printf("Ingrese el ID del cliente: ");  //esto lee la id del perro
    scanf("%d", &clienteSeleccionado); // escanea la id mejor dicho recolecta

    int clienteEncontrado = 0; // cliente encontrado es una variable que busca los datos guardados, hay que buscar lo por la id 
    for (int i = 0; i < numClientes; i++) // el for analiza todos los clientes añadidos y seleciona al que tenga la misma id 
    {
        if (IDS[i] == clienteSeleccionado) // iDS es un arreglo  que basicamente almecena loss ids puestos, ademas verifica si el id del cliente esta dentro de la variable i   
        {
            printf("== Facturacion ==\n");
            printf("Nombre del cliente: %s\n", nombres[i]);
            printf("Nombre de la mascota: %s\n", mascotas[i]);
            printf("ID de la mascota: %d\n", IDS[i]);
            printf("Edad de la mascota: %d\n", edades[i]);
            printf("Tipo de mascota: %s\n", tiposMascota[i] == 1 ? "Perro" : "Gato");
            printf("Costo total de los servicios seleccionados: $%.2f\n", costosTotal[i]);

            clienteEncontrado = 1; // esto le dice al programa que se encontro al cliente y lo hace si le regresa un 1 
            break;
        }
    }

    if (!clienteEncontrado) // esto verifica si se encontro o no al cliente, si no muestra el mensaje de abajo 
    {
        printf("Cliente no encontrado\n");
    }
}