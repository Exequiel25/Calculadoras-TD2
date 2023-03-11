// Programa para calcular la capacidad de memoria de un microcontrolador
// en función de el bus de datos y el bus de direcciones
// También calcula el bus de datos
// en función de la capacidad de memoria y el bus de direcciones
// Y calcula el bus de direcciones
// en función de la capacidad de memoria y el bus de datos

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float get_input(char *prompt)
{
    float input;
    printf("%s", prompt);
    scanf("%f", &input);
    return input;
}

int main()
{
    float bus_datos, bus_direcciones, capacidad_memoria;
    int option;
    
    printf("1. Calcular capacidad de memoria en función de bus de datos y bus de direcciones\n");
    printf("2. Calcular bus de datos en función de capacidad de memoria (en bits) y bus de direcciones\n");
    printf("3. Calcular bus de direcciones en función de capacidad de memoria (en bits) y bus de datos\n");
    printf("Elige una opción: ");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            bus_datos = get_input("Introduce el bus de datos: ");
            bus_direcciones = get_input("Introduce el bus de direcciones: ");
            capacidad_memoria = bus_datos * pow(2, bus_direcciones);
            printf("La capacidad de memoria es de %f bits\n", capacidad_memoria);
            break;
        case 2:
            capacidad_memoria = get_input("Introduce la capacidad de memoria (en bits): ");
            bus_direcciones = get_input("Introduce el bus de direcciones: ");
            bus_datos = capacidad_memoria / pow(2, bus_direcciones);
            printf("El bus de datos es de %f bits\n", bus_datos);
            break;
        case 3:
            capacidad_memoria = get_input("Introduce la capacidad de memoria (en bits): ");
            bus_datos = get_input("Introduce el bus de datos: ");
            if (bus_datos <= 0) {
                printf("Error: el bus de datos debe ser mayor que cero.\n");
                return 1;
            }
            bus_direcciones = log2(capacidad_memoria / bus_datos);
            printf("El bus de direcciones es de %f bits\n", bus_direcciones);
            break;
        default:
            printf("Opción incorrecta");
            break;
    }
}
