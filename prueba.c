#include <stdio.h>
#include <math.h>

int main()
{
    int parteEntera =0;
    float parteDecimal = 0.0;
    int index = 0;
    int resto[100] = {0};

    printf("Ingrese un numero entero: ");
    scanf("%f", &parteDecimal);
    parteEntera = (int)parteDecimal;
    parteDecimal = parteDecimal - parteEntera;
    while (parteDecimal != 0)
    {
        parteDecimal *= 2;
        resto[index] = (int)floor(parteDecimal);
        printf("%d\n", resto[index]);
        parteDecimal = parteDecimal - resto[index];
        index++;
    }
    printf("Resultado: \n");
    for (int i = 0; i <101; i++){
        printf("%d", resto[i]);
    }
}