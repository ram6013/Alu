#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
// Definicion de funciones:
int OperacionesBasicas(int contador);
float OperacionesDecimales(int contador);
int operacionesLogicas(int contador, int *array1, int *array2, int *array3);
int verDatos(int *array, int size);
void rellenarDatos(int *array, int size);
void Not(int *array1);
void desplazamiento(int *array1, int numero, int contador);
void calcularBinario(int numero, int *binario);
void funcionesAdicionales(int contador);
void invertir(int *array);
int NormaIEEE754();
void binarioDecimal(int i);
int convertirDecimal(int *array);
int ca2Decimnal(int *array);
void operacionesCa2(int contador);

// Funciones:
int verDatos(int *array, int size)
{
    printf("Su array es el siguiente: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (array[i] != 0 && array[i] != 1)
        {
            printf("\nLos valores son distintos de 1 o 0. No puede ser.\n");
            return 1;
        }
    }
    printf("\n");
    return 0;
}

void rellenarDatos(int *array, int size)
{

    printf("Dame 16 valores para rellenar el array: ");
    for (int i = 0; i < size; i++)
    {

        scanf("%d", &array[i]);
    }
}

int OperacionesBasicas(int contador)
{
    int valor1 = 0, valor2 = 0;
    printf("Dame un valor: ");
    scanf("%d", &valor1);
    printf("Dame otro valor: ");
    scanf("%d", &valor2);
    switch (contador)
    {
    case 1:
        return valor1 + valor2;
    case 2:
        return valor1 - valor2;
    case 3:
        return valor1 * valor2;
    case 4:
        return valor1 / valor2;
    default:
        return 0;
    }
}
float OperacionesDecimales(int contador)
{
    float valor1 = 0.0, valor2 = 0.0;
    printf("Dame un valor: ");
    scanf("%f", &valor1);
    printf("Dame otro valor: ");
    scanf("%f", &valor2);
    switch (contador)
    {
    case 5:
        return valor1 + valor2;
    case 6:
        return valor1 - valor2;
    case 7:
        return valor1 * valor2;
    case 8:
        return valor1 / valor2;
    default:
        return 0;
    }
}

int operacionesLogicas(int contador, int *array1, int *array2, int *array3)
{
    rellenarDatos(array1, 16);
    rellenarDatos(array2, 16);
    int check = verDatos(array1, 16);
    int check1 = verDatos(array2, 16);
    if (check == 1 || check1 == 1)
    {
        return 0;
    }

    switch (contador)
    {
    case 1: // AND
        for (int i = 0; i < 16; i++)
        {
            array3[i] = (array1[i] && array2[i]);
        }
        break;
    case 2: // OR
        for (int i = 0; i < 16; i++)
        {
            array3[i] = (array1[i] || array2[i]);
        }
        break;
    case 3: // XOR
        for (int i = 0; i < 16; i++)
        {
            if (array1[i] != array2[i])
            {
                array3[i] = 1;
            }
            else
            {
                array3[i] = 0;
            }
        }
        break;
    }
    return 0;
}
void Not(int *array1)
{
    for (int i = 0; i < 16; i++)
    {
        array1[i] = (!array1[i]);
    }
}

void desplazamiento(int *array1, int numero, int contador)
{
    switch (contador)
    {
    case 5: // Desplazamiento izquierda
        for (int i = numero; i < 16; i++)
        {
            array1[i - numero] = array1[i];
            array1[i] = 0;
        }
        break;
    case 6: // Desplazamiento derecha
        for (int i = 0; i < numero; i++)
        {
            array1[i + numero] = array1[i];
            array1[i] = 0;
        }
        break;
    case 7:
    { // Rotacion izquerda
        int array2[16];
        for (int i = 0; i < numero; i++)
        {
            array2[i] = array1[16 + i - numero];
            array1[16 + i - numero] = array1[i];
            array1[i] = array2[i];
        }
        break;
    }
    case 8:
    { // Rotacion derecha
        int array3[16];
        for (int i = 16 - numero; i < 16; i++)
        {
            array3[i] = array1[-16 + i + numero];
            array1[-16 + i + numero] = array1[i];
            array1[i] = array3[i];
        }
        break;
    }
    default:
        printf("Error: problemas con la operacion");
        break;
    }
}
void calcularBinario(int numero, int *binario)
{

    int index = 0;
    numero = abs(numero);
    while (numero > 0)
    {
        binario[15 - index] = numero % 2;
        numero = numero / 2;
        index++;
    }
}
void invertir(int *array)
{
    for (int i = 0; i < 16; i++)
    {
        if (array[i] == 0)
        {
            array[i] = 1;
        }
        else if (array[i] == 1)
        {
            array[i] = 0;
        }
        else
            (printf("Error en invertir"));
    }
}
void funcionesAdicionales(int contador)
{
    int numero = 0;
    int array1[16] = {0};
    printf("Dame un numero entero: ");
    scanf("%d", &numero);
    if (numero > 32767 || numero < -32768)
    {
        printf("El numero no puede ser mayor a 32767 o menor a -32767 debido a la capacidad de un array de 16 posiciones");
    }
    calcularBinario(numero, array1);
    if (numero < 0)
    {
        switch (contador)
        {
        case 1: // signo y magnitud
            printf("Resultado signo y magnitud: \n");
            break;

        case 2: // Complemento a 1
            invertir(array1);
            printf("Complemento a 1: \n");
            break;
        case 3: // Complemento a 2
            invertir(array1);
            printf("Complemento a 1: \n");
            verDatos(array1, 16);
            for (int i = 15; i < 16; i--)
            {
                if (array1[i] == 0)
                {
                    array1[i] = 1;
                    break;
                }
                else if (array1[i] == 1)
                {
                    array1[i] = 0;
                }
            }
            printf("complemento a 2: \n");
            break;
        default:
            printf("Error: problemas con la operacion\n");
            break;
        }
        array1[0] = 1;
    }
    verDatos(array1, 16);
}
int NormaIEEE754()
{
    int array[32] = {0};
    float decimal = 0.0;
    int parteEntera = 0;
    float parteDecimal = 0.0;
    int resto[23] = {0};
    int estandar = 0;
    float positivo = 0;
    int numeroEntero2 = 0;
    int comaFlotante = 0;
    int indexprueba = 0;
    printf("Dame un numero decimal: ");
    scanf("%f", &decimal);
    if (decimal >= 0)
    {
        array[0] = 0;
    }
    else
    {
        array[0] = 1;
    }
    positivo = fabs(decimal);
    // Cojo el valor entero del numero decimal.
    parteEntera = (int)floor(positivo);
    numeroEntero2 = parteEntera;
    // Calculo su binario.
    int index = 0;
    while (parteEntera > 0)
    {
        resto[index] = parteEntera % 2;
        printf("%d", resto[index]);
        parteEntera = parteEntera / 2;
        index++;
    }
    comaFlotante = index - 1;

    int arrayordenado[23] = {0};
    // ordeno la mantisa
    int i = 0;
    printf("\nQue añadimos\n");
    for (index; index >= 2; index--)
    {
        printf("\neste es el valor del iindex %d", index);
        arrayordenado[i] = resto[index-2];
        printf("valor added: %d", arrayordenado[i]);
        i++;
    }
    // Calculo el binario del decimal.
    index = 0;
    int arraynuevo[32] = {0};
    parteDecimal = positivo - numeroEntero2;
    while (parteDecimal != 0.00)
    {
        parteDecimal *= 2;
        arraynuevo[index] = (int)floor(parteDecimal);
        if (parteDecimal >= 1)
        {
            parteDecimal = parteDecimal - arraynuevo[index];
        }
        index++;
        if (index > 23)
        {
            printf("Error1: el numero decimal no cumple con el estandar IEEE 754\n");
            return 1;
        }
    }
    for (index; index >= 0; index--)
    {
        arrayordenado[i] = arraynuevo[index];
        i++;
    }

    // Sacamos el binario del estandar es decir el exponente
    estandar = comaFlotante + 127;
    int index2 = 8;
    while (estandar > 0)
    {
        array[index2] = estandar % 2;
        estandar = estandar / 2;
        index2--;
        if (index2 < 0)
        {
            printf("Error2: el numero decimal no cumple con el estandar IEEE 754\n");
            return 1;
        }
    }
    // rellenamos con la matisa
    index = 9;
    index2 = 0;
    for (index; index < 33; index++)
    {
        array[index] = arrayordenado[index2];
        index2++;
    }
    verDatos(array, 32);
    return 0;
}
int convertirDecimal(int *array)
{
    int contador = 0;
    int num = 0;
    for (int i = 15; i > 0; i--)
    {
        num += array[i] * pow(2, contador);
        contador++;
    }
    return num;
}
void binarioDecimal(int contador)
{
    int check = 0;
    int num = 0;
    int array[16] = {0};
    rellenarDatos(array, 16);
    check = verDatos(array, 16);
    if (check == 1)
    {
        return;
    }
    if (array[0] == 1)
    {
        switch (contador)
        {
        case 1:
        {
            int contador = 0;
            num = convertirDecimal(array);
            num = -(num);
            printf("El decimal de tu signo y magintud es: %d\n", num);
            break;
        }
        case 2:
            invertir(array);
            num = convertirDecimal(array);
            num = -num;
            printf("El decimal de tu complemento a 1 es: %d\n", num);
            break;
        case 3:
            for (int i = 16; i > 0; i--)
            {
                if (array[i] == 1)
                {
                    array[i] = 0;
                    break;
                }
                else if (array[i] == 0)
                {
                    array[i] = 1;
                }
            }
            invertir(array);
            num = convertirDecimal(array);
            if (array[0] == 0)
            {
                num = -num;
            }
            printf("El decimal de tu complemento a 2 es: %d\n", num);
        default:
            break;
        }
    }
    else if (array[0] == 0)
    {
        num = convertirDecimal(array);
        printf("El decimal es: %d\n", num);
    }
}
int ca2Decimnal(int *array)
{
    int num = 0;
    if (array[0] == 1)
    {
        for (int i = 15; i > 0; i--)
        {
            if (array[i] == 1)
            {
                array[i] = 0;
                break;
            }
            else if (array[i] == 0)
            {
                array[i] = 1;
            }
        }
        invertir(array);
        num = convertirDecimal(array);
        num = -num;
    }
    else if (array[0] == 0)
    {
        num = convertirDecimal(array);
    }

    return num;
}
void operacionesCa2(int contador)
{
    int array1[16], array2[16] = {0};
    int num1, num2 = 0;
    printf("Dame el ca2 en 16 bits\n");
    rellenarDatos(array1, 16);
    verDatos(array1, 16);
    num1 = ca2Decimnal(array1);
    printf("El ca2 en decimal es: %d\n", num1);
    rellenarDatos(array2, 16);
    verDatos(array2, 16);
    num2 = ca2Decimnal(array2);
    printf("El ca2 en decimal es: %d\n", num2);
    switch (contador)
    {
    case 1:
        printf("El resultado de la suma es: %d\n", num1 + num2);
        break;
    case 2:
        printf("El resultado de la resta es: %d\n", num1 - num2);
        break;
    case 3:
        printf("El resultado de la multiplicacion es: %d\n", num1 * num2);
        break;
    case 4:
        printf("El resultado de la division es: %d\n", num1 / num2);
        break;
    default:
        break;
    }
}

int main()
{
    int respuesta;
    printf("Bienvenido a nuestra ALU\n");
    printf("Que tipo de operacion quieres?\n Hay tres tipos: operacion Aritmetica(1), operacion Logica(2) o funciones adicionales(3): ");
    scanf("%d", &respuesta);
    if (respuesta == 1)
    {
        printf("Como quieres dar los datos en decimal(1) o Ca2(2)?\n");
        scanf("%d", &respuesta);
        if (respuesta == 1)
        {
            printf("Que operacion quieres hacer?\n Estas son las opciones:\n sumar(1), restar(2), multiplicar(3), division(4), suma Decimal(5), resta Decimal(6), multiplicar Decimal(7), dividir Decimal(8)\n");
            scanf("%d", &respuesta);
            for (int i = 1; i < 8; i++)
            {
                if (i <= 4 && i == respuesta)
                {

                    printf("El resultado de la operacion es: %d\n", OperacionesBasicas(i));
                    break;
                }
                else if (i > 4 && i == respuesta)
                {
                    printf("El resultado de la operacion es: %f\n", OperacionesDecimales(i));
                    break;
                }
            }
        }
        else if (respuesta == 2)
        {
            printf("Que operacion quieres hacer?\n Estas son las opciones:\n sumar(1), restar(2), multiplicar(3), division(4)\n");
            scanf("%d", &respuesta);
            for (int i = 1; i <= 4; i++)
            {
                if (i == respuesta)
                {
                    operacionesCa2(i);
                }
            }
        }
    }
    else if (respuesta == 2)
    {
        int array1[16], array2[16], array3[16];
        printf("Seleccione que operacion quiere siendo posibles: \nAND(1), OR(2), XOR(3), NOT(4), Desplazamiento iquierda(5), Desplazamiento derecha(6), Rotacion izquierda(7), Rotacion derecha(8)\n Las puedes llamar por su respectivo numero: ");
        scanf("%d", &respuesta);
        for (int i = 1; i <= respuesta; i++)
        {
            if (i < 4 && i == respuesta)
            {

                operacionesLogicas(i, array1, array2, array3);
                printf("Resultado de la operacion:\n");
                verDatos(array3, 16);
                break;
            }
            else if (i == 4 && i == respuesta)
            {
                rellenarDatos(array1, 16);
                verDatos(array1, 16);
                Not(array1);
                printf("Resultado de la operacion:\n");
                verDatos(array1, 16);
                break;
            }
            else if (i > 4 && i == respuesta)
            {
                int numero = 0;
                printf("Dime un valor entero: ");
                scanf("%d", &numero);
                if (numero < 0 || numero > 15)
                {
                    printf("Los datos no son correctos");
                    return 0;
                }
                rellenarDatos(array1, 16);
                int check = verDatos(array1, 16);
                if (check == 1)
                {
                    printf("Los datos no son correctos");
                    return 0;
                }
                desplazamiento(array1, numero, i);
                printf("El resultado de tu operacion es:\n");
                verDatos(array1, 16);
                break;
            }
        }
    }
    else if (respuesta == 3)
    {
        int res = 0;
        printf("Que tipo de datos quieres ingresar? \n Entero(1), binario(2)\n");
        scanf("%d", &respuesta);
        if (respuesta == 1)
        {
            printf("Que tipo de funcion quiere hacer?\n signo y maginutd(1), complemento a 1(2), complemento a 2(3), Norma IEE 754(4): ");
            scanf("%d", &respuesta);
            for (int i = 1; i <= respuesta; i++)
            {
                if (i <= 3 && i == respuesta)
                {
                    funcionesAdicionales(i);
                    break;
                }
                if (i > 3 && i == respuesta)
                {
                    res = NormaIEEE754();
                    if (res == 1)
                    {
                        printf("No se completo con exito\n");
                    }
                    else
                    {
                        printf("Se completo con exito\n");
                    }
                }
            }
        }
        else if (respuesta == 2)
        {
            printf("Que tipo de funcion quiere hacer?\n de signo y maginutd a decimal(1), complemento a 1 a decimal(2), complemento a 2 a decimal(3)\n");
            scanf("%d", &respuesta);
            for (int i = 1; i <= respuesta; i++)
            {
                if (i == respuesta)
                {
                    binarioDecimal(i);
                }
            }
        }
    }
}