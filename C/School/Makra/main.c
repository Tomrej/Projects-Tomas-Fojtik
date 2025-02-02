#include <stdio.h>
// Musel jsem pridat limits pro CELECISLO_MIN a CELECISLO_MAX
#include <limits.h>

#define POKUS 65
#define START {
#define KONEC }
#define NACTI scanf
#define VYPIS printf
#define HLAVNIFUNKCE main
#define PLUS +
#define ULOZ =
#define STREDNIK ;
#define CELECISLO int

CELECISLO HLAVNIFUNKCE(CELECISLO argc, char const *argv[])
START
    VYPIS("CAST 1\n")STREDNIK
    VYPIS("Aktualni radek: %d\n", __LINE__)STREDNIK
    VYPIS("Minimalni hodnota: %d\n", INT_MIN)STREDNIK
    VYPIS("Maximalni hodnota CELECISLO32: %d\n", INT_MAX)STREDNIK
    VYPIS("Nazev souoru: %s\n", __FILE__)STREDNIK
    VYPIS("Aktualni datum: %s\n", __DATE__)STREDNIK
    VYPIS("Aktualni cas: %s\n", __TIME__)STREDNIK

    VYPIS("\nCAST 2\n")STREDNIK
    VYPIS("Pokus jako CELECISLO: %d\n", POKUS)STREDNIK
    VYPIS("Pokus jako char: %c\n", POKUS)STREDNIK
    VYPIS("Pokus jako float: %f\n", POKUS)STREDNIK
    VYPIS("Program pro soucet dvou cisel\n")STREDNIK

    CELECISLO cislo1, cislo2 STREDNIK

    VYPIS("Jake je tvoje prvni cislo?\n")STREDNIK
    NACTI("%d", &cislo1)STREDNIK
    VYPIS("Jake je tvoje druhe cislo?\n")STREDNIK
    NACTI("%d", &cislo2)STREDNIK
    VYPIS("Soucet dvou cisel je: %d\n", cislo1 PLUS cislo2)STREDNIK




    return 0 STREDNIK
KONEC
