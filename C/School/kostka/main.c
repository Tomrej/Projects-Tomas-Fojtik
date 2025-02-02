/*================================
Autor: Tomáš Fojtík, I1B
================================*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int hodHrace, hodProtivnika, poziceHrace, poziceProtivnika;
    int cisloHrace, cisloProtivnika = 0;

    printf("Hra s kostkou!\n==============\n");

    for (int i = 0; i < 3; i++)
    {
        srand(time(NULL));
        hodHrace = rand() % 6 + 1;

        printf("\nHodil jsi: %i\n", hodHrace);

        printf("Na jakou pozici chces cislo zapsat?\n");
        printf("1) pozice stovek\n2) pozice desitek\n3) pozices jednotek\n");

        while (1==1)
        {
            do
            {
                printf("Zadej cislo od 1 do 3 a vyber si tak pozici, kde chces cislo vlozit\n");
                scanf("%i", &poziceHrace);
            } while (poziceHrace < 1 || poziceHrace > 3);

            if (poziceHrace == 1 && cisloHrace / 100 == 0)
            {
                break;
            }
            else if (poziceHrace == 2 && cisloHrace % 100 / 10 == 0)
            {
                break;
            }
            else if (poziceHrace == 3 && cisloHrace % 10 == 0)
            {
                break;
            }
            else if (cisloHrace == 0)
            {
                break;
            }
            else
            {
                printf("Davej pozor! misto je jiz obsazene!\n");
            }
        }

        if (poziceHrace == 1)
        {
            cisloHrace += hodHrace * 100;
        }
        else if (poziceHrace == 2)
        {
            cisloHrace += hodHrace * 10;
        }
        else
        {
            cisloHrace += hodHrace;
        }

        printf("Cislo hrace: %i\n", cisloHrace);

        // protivnik
        hodProtivnika = rand() % 6 + 1;
        
        while (1==1)
        {
            poziceProtivnika = rand() % 3 + 1;

            if (poziceProtivnika == 1 && cisloProtivnika / 100 == 0)
            {
                break;
            }
            else if (poziceProtivnika == 2 && cisloProtivnika % 100 / 10 == 0)
            {
                break;
            }
            else if (poziceProtivnika == 3 && cisloProtivnika % 10 == 0)
            {
                break;
            }
            else if (cisloHrace == 0)
            {
                break;
            }
        }

        if (poziceProtivnika == 1)
        {
            cisloProtivnika += hodProtivnika * 100;
        }
        else if (poziceProtivnika == 2)
        {
            cisloProtivnika += hodProtivnika * 10;
        }
        else
        {
            cisloProtivnika += hodProtivnika;
        }

        printf("Cislo protivnika: %i\n", cisloProtivnika);
        }

    if (cisloHrace > cisloProtivnika)
    {
        printf("Vyhral jsi!\n");
    }
    else if (cisloHrace < cisloProtivnika)
    {
        printf("Prohral jsi!\n");
    }
    else
    {
        printf("Remiza!\n");
    }
    
    return 0;
}

// Lepsi by bylo vytvorit funkci nez dvakrat opakovat podminky pro urcovani pozice cisla  