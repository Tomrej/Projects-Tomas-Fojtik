#include <stdio.h>

#define SUDOSTLICHOST(CISLO) (CISLO) % 2 == 0 ? "SUDE" : "LICHE"
#define PI 3.14
#define VETSIMENSI(NUM1, NUM2) (NUM1) > (NUM2) ? (NUM1) : (NUM2)

int main(int argc, char const *argv[])
{
    printf("Tento program ti rekne, jestli je tvoje cislo sude nebo liche.\nJake je tvoje cislo?\n");
    int cislo;
    scanf("%d", &cislo);
    printf("Tvoje cislo je %s\n\n", SUDOSTLICHOST(cislo));

    int NUM1, NUM2;
    printf("A nyni zade dve cisla a porvname, ktere je vetsi.\nJake je tvoje prvni cislo?\n");
    scanf("%d", &NUM1);
    printf("Zadej druhe cislo\n");
    scanf("%d", &NUM2);

    printf("Vetsi je cislo: %d\n", VETSIMENSI(NUM1, NUM2));
    printf("A tady je vypsane PI tak jak ho vidim ja: %f\n", PI);

    return 0;
}