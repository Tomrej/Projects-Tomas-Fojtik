/*=============================
AUTOR: Tomáš Fojtík, I1B
=============================*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int tahHrace, tahSoupere;

    printf("Kamen, nuzky, papir!\n===========================\n");
    printf("Zadej:\n1) pro kamen\n2) pro nuzky\n3) pro pair\n");

    do
    {
        printf("Zadej cislo od 1 po 3\n");
        scanf("%d", &tahHrace);
    } while (tahHrace < 1 || tahHrace > 3);

    srand(time(NULL));
    tahSoupere = rand()%3+1;

    // Kamen
    if (tahHrace == 1)
    {
        if (tahSoupere == 1)
        {
            printf("Remiza! Oba jste zvolili kamen\n");
        }
        else if (tahSoupere == 2)
        {
            printf("Vyhral jsi! Zvolil si kamen a protivnik zvolil nuzky");
        }
        else
        {
            printf("Prohral jsi! Zvolil si kamen a souper zvolil papir!");
        }
    }
    // Nuzky
    else if (tahHrace == 2)
    {
        if (tahSoupere == 2)
        {
            printf("Remiza! Oba jste zvolili nuzky\n");
        }
        else if (tahSoupere == 3)
        {
            printf("Vyhral jsi! Zvolil si nuzky a protivnik zvolil papir");
        }
        else
        {
            printf("Prohral jsi! Zvolil si nuzky a souper zvolil kamen!");
        }
    }
    // Papir
    else if (tahHrace == 3)
    {
        if (tahSoupere == 3)
        {
            printf("Remiza! Oba jste zvolili papir\n");
        }
        else if (tahSoupere == 1)
        {
            printf("Vyhral jsi! Zvolil si papir a protivnik zvolil kamen");
        }
        else
        {
            printf("Prohral jsi! Zvolil si papir a souper zvolil nuzky!");
        }
    }

    return 0;
}