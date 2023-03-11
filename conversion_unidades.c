// Programa para convertir bits en bytes, kilobytes, megabytes,
// gigabytes, terabytes, petabytes, exabytes, zettabytes y yottabytes
// y viceversa
// También convierte bits en KiB, MiB, GiB, TiB, PiB, EiB, ZiB y YiB
// y viceversa

#include <stdio.h>
#include <math.h>

int main() {
    char *decimal_units[] = {"bits", "B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
    char *binary_units[] = {"bits", "B", "KiB", "MiB", "GiB", "TiB", "PiB", "EiB", "ZiB", "YiB"};
    float decimal_conversions[] = {1, 8, 1e3 * 8, 1e6 * 8, 1e9 * 8, 1e12 * 8, 1e15 * 8, 1e18 * 8, 1e21 * 8, 1e24 * 8};
    float binary_conversions[] = {1, 8, pow(2, 10) * 8, pow(2, 20) * 8, pow(2, 30) * 8, pow(2, 40) * 8, pow(2, 50) * 8, pow(2, 60) * 8, pow(2, 70) * 8, pow(2, 80) * 8};
    int num_decimal_units = sizeof(decimal_units) / sizeof(decimal_units[0]);
    int num_binary_units = sizeof(binary_units) / sizeof(binary_units[0]);
    int option;
    float cantidad, resultado;
    
    printf("1. Convertir bits en ");
    for (int i = 1; i < num_decimal_units; i++) {
        printf("%s, ", decimal_units[i]);
    }
    printf("y viceversa\n");
    printf("2. Convertir ");
    for (int i = 1; i < num_decimal_units; i++) {
        printf("%s, ", decimal_units[i]);
    }
    printf("en bits\n");
    printf("3. Convertir bits en ");
    for (int i = 2; i < num_binary_units; i++) {
        printf("%s, ", binary_units[i]);
    }
    printf("y viceversa\n");
    printf("4. Convertir ");
    for (int i = 2; i < num_binary_units; i++) {
        printf("%s, ", binary_units[i]);
    }
    printf("en bits\n");
    printf("Elige una opción: ");
    scanf("%d", &option);
    
    switch(option) {
        case 1:
            printf("Introduce la cantidad de bits: ");
            scanf("%f", &cantidad);
            for (int i = 1; i < num_decimal_units; i++) {
                resultado = cantidad / decimal_conversions[i];
                printf("La cantidad de %s es de %f\n", decimal_units[i], resultado);
            }
            break;
        case 2:
            printf("Introduce la cantidad: ");
            scanf("%f", &cantidad);
            for (int i = 1; i < num_decimal_units; i++) {
                resultado = cantidad * decimal_conversions[i];
                printf("La cantidad de %s es de %f bits\n", decimal_units[i], resultado);
            }
            break;
        case 3:
            printf("Introduce la cantidad de bits: ");
            scanf("%f", &cantidad);
            for (int i = 2; i < num_binary_units; i++) {
                resultado = cantidad / binary_conversions[i];
                printf("La cantidad de %s es de %f\n", binary_units[i], resultado);
            }
            break;
        case 4:
            printf("Introduce la cantidad: ");
            scanf("%f", &cantidad);
            for (int i = 2; i < num_binary_units; i++) {
                resultado = cantidad * binary_conversions[i];
                printf("La cantidad de %s es de %f bits\n", binary_units[i], resultado);
            }
            break;
        default:
            printf("Opción inválida\n");
    }
    return 0;
}
