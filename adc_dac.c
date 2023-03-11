#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate_conversion_value(double adc_bits, double adc_max, double adc_min, double conversion_value) {
    return (pow(2, adc_bits) / (adc_max - adc_min)) * (conversion_value - adc_min);
}

double calculate_output_value(double adc_bits, double adc_max, double adc_min, double conversion_value) {
    return ((adc_max - adc_min) / pow(2, adc_bits)) * conversion_value + adc_min;
}

int main() {
    int option;
    double adc_bits, adc_max, adc_min, conversion_value;

    printf("1. Obtener el valor del registro de conversión\n");
    printf("2. Obtener el valor de la variable de salida\n");
    printf("Elige una opción: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Introduce el número de bits del ADC: ");
            scanf("%lf", &adc_bits);
            printf("Introduce el valor máximo: ");
            scanf("%lf", &adc_max);
            printf("Introduce el valor mínimo: ");
            scanf("%lf", &adc_min);
            printf("Introduce el valor de salida: ");
            scanf("%lf", &conversion_value);
            printf("El valor del registro de conversión es: %lf\n", calculate_conversion_value(adc_bits, adc_max, adc_min, conversion_value));
            break;
        case 2:
            printf("Ingrese el número de bits del ADC: ");
            scanf("%lf", &adc_bits);
            printf("Ingrese el valor máximo: ");
            scanf("%lf", &adc_max);
            printf("Ingrese el valor mínimo: ");
            scanf("%lf", &adc_min);
            printf("Ingrese el valor del registro de conversión: ");
            scanf("%lf", &conversion_value);
            printf("El valor de la variable de salida es: %lf\n", calculate_output_value(adc_bits, adc_max, adc_min, conversion_value));
            break;
        default:
            printf("Opción no válida\n");
            break;
    }
    return 0;
}
