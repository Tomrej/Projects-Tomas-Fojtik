#include <stdio.h>

int cislo;
static int dalsiCislo = 2;

void vypis()
{
    printf("Extern cislo: %d\n", cislo);
    printf("Vypis static promene v druhem zdrojaku: %d\n", dalsiCislo);
}

void funkce()
{
    static int promena = 0;
    int dalsiPromena = 0;

    printf("Promena static: %d, standartni promena: %d\n", promena, dalsiPromena);

    promena++;
    dalsiPromena++;
}