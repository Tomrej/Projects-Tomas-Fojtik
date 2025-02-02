#include "ctvrty.h"

void prevod_dm(float x)
{
    printf("Decimetry na kilometry: \t%f\n", x / 10000);
    printf("Decimetry na metry: \t%f\n", x / 10);
    printf("Decimetry na centimetry: \t%f\n", x * 10);
    printf("Decimetry na milimetry: \t%f\n", x * 100);
}

void prevod_litry(float x)
{
    printf("Litry na hektolitry: \t%f\n", x * 0.01);
    printf("Litry na decilitry: \t%f\n", x * 10);
    printf("Litry na mililiry: \t%f\n", x * 1000);
}

void prevod_hodiny(float x)
{
    printf("Hodina na dny: \t%f\n", x / 24);
    printf("Hodina na tydny: \t%f\n", x / 24 / 7);
    printf("Hodina na minuty: \t%f\n", x * 60);
    printf("Hodina na vteriny: \t%f\n", x * 3600);
}