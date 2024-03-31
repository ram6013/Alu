#include <stdio.h>

// ESPACIO DONDE ESTAN TODAS LAS FUNCIONES DE TODAS LAS OPCIONES

// FUNCIONES PARA LAS OPERACIONES ARITMETICAS SIN DECIMALES
int suma_entera(int a, int b) {
    return a + b;
}

int resta_entera(int a, int b) {
    return a - b;
}

int multiplicacion_entera(int a, int b) {
    return a * b;
}

void division_entera(int a, int b, int* cociente, int* resto) {
    *cociente = a / b;
    *resto = a % b;
}

//  FUNCIONES PARA LAS OPERACIONES ARITMETICAS CON DECIMALES
float suma_decimal(float a, float b) {
    return a + b;
}

float resta_decimal(float a, float b) {
    return a - b;
}

float multiplicacion_decimal(float a, float b) {
    return a * b;
}


float division_decimal(float a, float b) {  // Lo añadido es que si divides entre 0 te dara un error
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: División por cero.\n");
        return 0;
    }
}


// FUNCION PARA AND
void AND_16bits(int* resultado, int* array1, int* array2) {
    for (int i = 0; i < 16; i++) {
        resultado[i] = array1[i] & array2[i];
    }
}

// FUNCION PARA OR
void OR_16bits(int* resultado, int* array1, int* array2) {
    for (int i = 0; i < 16; i++) {
        resultado[i] = array1[i] | array2[i];
    }
}

// FUNCION PARA XOR
void XOR_16bits(int* resultado, int* array1, int* array2) {
    for (int i = 0; i < 16; i++) {
        resultado[i] = array1[i] ^ array2[i];
    }
}

// FUNCION PARA NOT
void NOT_16bits(int* resultado, int* array) {
    for (int i = 0; i < 16; i++) {
        resultado[i] = !array[i];
    }
}

// FUNCION PARA HACER DESPLAZAMIENTO DE BITS A LA IZQUIERDA
void desplazamiento_izquierda(int* resultado, int* array, int n) {
    for (int i = 0; i < 16; i++) {
        resultado[i] = (i < n) ? 0 : array[i - n];
    }
}

// FUNCION PARA HACER DESPLAZAMIENTO DE BITS A LA DERECHA
void desplazamiento_derecha(int* resultado, int* array, int n) {
    for (int i = 0; i < 16; i++) {
        resultado[i] = (i + n >= 16) ? 0 : array[i + n];
    }
}

//  FUNCION PARA HACER ROTACION DE BITS A LA IZQUIERDA
void rotacion_izquierda(int* resultado, int* array, int n) {
    for (int i = 0; i < 16; i++) {
        resultado[i] = array[(i + n) % 16];
    }
}

//  FUNCION PARA HACER ROTACION DE BITS A LA DERECHA
void rotacion_derecha(int* resultado, int* array, int n) {
    for (int i = 0; i < 16; i++) {
        resultado[i] = array[(16 + i - n) % 16];
    }
}

// FUNCION PARA CONVERTIR UN NUMERO ENTERO EN UN BINARIO USANDO SIGNO Y MAGNITUD
void signo_magnitud(int* resultado, int numero) {
    if (numero >= -32768 && numero <= 32767) {
        if (numero >= 0) {
            resultado[0] = 0;
        } else {
            resultado[0] = 1;
            numero *= -1;
        }
        for (int i = 15; i > 0; i--) {
            resultado[i] = numero % 2;
            numero /= 2;
        }
    } else {
        printf("Error: No se puede representar el número en 16 bits usando signo y magnitud.\n");
    }
}

//  FUNCION PARA CONVERTIR UN NUMERO ENTERO EN UN VINARIO USANDO A1
void complemento_a_1(int* resultado, int numero) {
    if (numero >= -32768 && numero <= 32767) {
        if (numero >= 0) {
            resultado[0] = 0;
        } else {
            resultado[0] = 1;
            numero *= -1;
        }
        for (int i = 15; i > 0; i--) {
            resultado[i] = !(numero % 2);
            numero /= 2;
        }
    } else {
        printf("Error: No se puede representar el número en 16 bits usando complemento a 1.\n");
    }
}

// FUNCION PARA CONVERTIR UN NUMERO ENTERO EN UN VINARIO USANDO A2
void complemento_a_2(int* resultado, int numero) {
    if (numero >= -32768 && numero <= 32767) {
        if (numero >= 0) {
            resultado[0] = 0;
        } else {
            resultado[0] = 1;
            numero *= -1;
            numero = ~numero;
            numero += 1;
        }
        for (int i = 15; i > 0; i--) {
            resultado[i] = numero % 2;
            numero /= 2;
        }
    } else {
        printf("Error: No se puede representar el número en 16 bits usando complemento a 2.\n");
    }
}
// AQUI DEBERIA ESTAR IEE PERO NO SE COMO FUNCIONA

int main() {
    int opcion;

    printf("Seleccione el tipo de operación:\n");
    printf("1. Operaciones aritméticas\n");
    printf("2. Operaciones lógicas\n");
    printf("3. Funciones adicionales\n");
    scanf("%d", &opcion);

    if (opcion == 1) {
         printf("Seleccione el tipo de operación aritmética:\n");
        printf("1. Suma entera\n");
        printf("2. Resta entera\n");
        printf("3. Multiplicación entera\n");
        printf("4. División entera\n");
        printf("5. Suma decimal\n");
        printf("6. Resta decimal\n");
        printf("7. Multiplicación decimal\n");
        printf("8. División decimal\n");

        int seleccion;
        printf("Seleccione la operación aritmética:\n");
        scanf("%d", &seleccion);

        int resultado_entero, cociente, resto;
        float resultado_decimal;
        int numero1, numero2;
        float numero1_dec, numero2_dec;
        switch (seleccion) {
            case 1:
                printf("Ingrese el primer número entero: ");
                scanf("%d", &numero1);
                printf("Ingrese el segundo número entero: ");
                scanf("%d", &numero2);
                resultado_entero = suma_entera(numero1, numero2);
                printf("El resultado de la suma entera es: %d\n", resultado_entero);
                break;
            case 2:
                printf("Ingrese el primer número entero: ");
                scanf("%d", &numero1);
                printf("Ingrese el segundo número entero: ");
                scanf("%d", &numero2);
                resultado_entero = resta_entera(numero1, numero2);
                printf("El resultado de la resta entera es: %d\n", resultado_entero);
                break;
            case 3:
                printf("Ingrese el primer número entero: ");
                scanf("%d", &numero1);
                printf("Ingrese el segundo número entero: ");
                scanf("%d", &numero2);
                resultado_entero = multiplicacion_entera(numero1, numero2);
                printf("El resultado de la multiplicación entera es: %d\n", resultado_entero);
                break;
            case 4:
                printf("Ingrese el primer número entero: ");
                scanf("%d", &numero1);
                printf("Ingrese el segundo número entero: ");
                scanf("%d", &numero2);
                division_entera(numero1, numero2, &cociente, &resto);
                printf("El cociente de la división entera es: %d\n", cociente);
                printf("El resto de la división entera es: %d\n", resto);
                break;
            case 5:
                printf("Ingrese el primer número decimal: ");
                scanf("%f", &numero1_dec);
                printf("Ingrese el segundo número decimal: ");
                scanf("%f", &numero2_dec);
                resultado_decimal = suma_decimal(numero1_dec, numero2_dec);
                printf("El resultado de la suma decimal es: %.2f\n", resultado_decimal);
                break;
            case 6:
                printf("Ingrese el primer número decimal: ");
                scanf("%f", &numero1_dec);
                printf("Ingrese el segundo número decimal: ");
                scanf("%f", &numero2_dec);
                resultado_decimal = resta_decimal(numero1_dec, numero2_dec);
                printf("El resultado de la resta decimal es: %.2f\n", resultado_decimal);
                break;
            case 7:
                printf("Ingrese el primer número decimal: ");
                scanf("%f", &numero1_dec);
                printf("Ingrese el segundo número decimal: ");
                scanf("%f", &numero2_dec);
                resultado_decimal = multiplicacion_decimal(numero1_dec, numero2_dec);
                printf("El resultado de la multiplicación decimal es: %.2f\n", resultado_decimal);
                break;
            case 8:
                printf("Ingrese el primer número decimal: ");
                scanf("%f", &numero1_dec);
                printf("Ingrese el segundo número decimal: ");
                scanf("%f", &numero2_dec);
                resultado_decimal = division_decimal(numero1_dec, numero2_dec);
                printf("El resultado de la división decimal es: %.2f\n", resultado_decimal);
                break;
            default:
                printf("Opción no válida.\n");
                return 1;
        }
    } else if (opcion == 2) {
printf("Seleccione el tipo de operación lógica:\n");
        printf("9. AND lógico de 16 bits\n");
        printf("10. OR lógico de 16 bits\n");
        printf("11. XOR lógico de 16 bits\n");
        printf("12. NOT lógico de 16 bits\n");

        int seleccion;
        printf("Seleccione la operación lógica:\n");
        scanf("%d", &seleccion);

        int resultado_logico[16];
        int array1[16], array2[16];
        switch (seleccion) {
            case 9:
                printf("Ingrese el primer número binario de 16 bits: ");
                for (int i = 0; i < 16; i++) {
                    scanf("%d", &array1[i]);
                }
                printf("Ingrese el segundo número binario de 16 bits: ");
                for (int i = 0; i < 16; i++) {
                    scanf("%d", &array2[i]);
                }
                AND_16bits(resultado_logico, array1, array2);
                printf("El resultado del AND lógico es: ");
                for (int i = 0; i < 16; i++) {
                    printf("%d", resultado_logico[i]);
                }
                printf("\n");
                break;
            case 10:
                printf("Ingrese el primer número binario de 16 bits: ");
                for (int i = 0; i < 16; i++) {
                    scanf("%d", &array1[i]);
                }
                printf("Ingrese el segundo número binario de 16 bits: ");
                for (int i = 0; i < 16; i++) {
                    scanf("%d", &array2[i]);
                }
                OR_16bits(resultado_logico, array1, array2);
                printf("El resultado del OR lógico es: ");
                for (int i = 0; i < 16; i++) {
                    printf("%d", resultado_logico[i]);
                }
                printf("\n");
                break;
            case 11:
                printf("Ingrese el primer número binario de 16 bits: ");
                for (int i = 0; i < 16; i++) {
                    scanf("%d", &array1[i]);
                }
                printf("Ingrese el segundo número binario de 16 bits: ");
                for (int i = 0; i < 16; i++) {
                    scanf("%d", &array2[i]);
                }
                XOR_16bits(resultado_logico, array1, array2);
                printf("El resultado del XOR lógico es: ");
                for (int i = 0; i < 16; i++) {
                    printf("%d", resultado_logico[i]);
                }
                printf("\n");
                break;
            case 12:
                printf("Ingrese el número binario de 16 bits para aplicar NOT lógico: ");
                for (int i = 0; i < 16; i++) {
                    scanf("%d", &array1[i]);
                }
                NOT_16bits(resultado_logico, array1);
                printf("El resultado del NOT lógico es: ");
                for (int i = 0; i < 16; i++) {
                    printf("%d", resultado_logico[i]);
                }
                printf("\n");
                break;
            default:
                printf("Opción no válida.\n");
                return 1;
        }
    } else if (opcion == 3) {
        printf("Funciones adicionales disponibles:\n");
        printf("13. Signo y magnitud\n");
        printf("14. Complemento a 1\n");
        printf("15. Complemento a 2\n");
        printf("16. Norma IEEE 754\n");

        int seleccion;
        printf("Seleccione la función adicional:\n");
        scanf("%d", &seleccion);

        int resultado[32], numero;
        switch (seleccion) {
            case 13:
                printf("Ingrese el número entero para representar en signo y magnitud: ");
                scanf("%d", &numero);
                signo_magnitud(resultado, numero);
                printf("El resultado en signo y magnitud es: ");
                for (int i = 0; i < 16; i++) {
                    printf("%d", resultado[i]);
                }
                printf("\n");
                break;
            case 14:
                printf("Ingrese el número entero para representar en complemento a 1: ");
                scanf("%d", &numero);
                complemento_a_1(resultado, numero);
                printf("El resultado en complemento a 1 es: ");
                for (int i = 0; i < 16; i++) {
                    printf("%d", resultado[i]);
                }
                printf("\n");
                break;
            case 15:
                printf("Ingrese el número entero para representar en complemento a 2: ");
                scanf("%d", &numero);
                complemento_a_2(resultado, numero);
                printf("El resultado en complemento a 2 es: ");
                for (int i = 0; i < 16; i++) {
                    printf("%d", resultado[i]);
                }
                printf("\n");
                break;
            case 16:
                printf("LAMENTABLEMENTE ESTE NO ESTA CARLOS\n");
                break;
            default:
                printf("Opción no válida.\n");
                return 1;
        }
    } else {
        printf("Opción no válida.\n");
        return 1;
    }

    return 0;
}
