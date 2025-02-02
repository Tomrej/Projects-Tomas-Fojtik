/* Zbytecne jsem to zkomplikoval diky tomu ze hrace si muze vybrat mezi 1 - 3 krtky.
Jeste me napadlo takove chytre reseni ze je zbytecne komplikovane :) */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int postup(int posloupnost, int x, int y);
int fibonaci(int x, int y);
int slozity_postup(int x);
int trojuhelnikove_cislo(int x);


int nasobek;

int main()
{
    srand(time(NULL));
    nasobek = rand() % 3 + 2;
    int pocet_zivych_krtku = 0;

    printf("==============================\n\tVALKA S KRTKY\n==============================\n");
    printf("\nZadej kolik chces mit krtku (1 - 3):\n");

    // Kolik krtku bude ve hre
    do
    {
        scanf("%d", &pocet_zivych_krtku);
        getchar();
    } while (pocet_zivych_krtku < 1 || pocet_zivych_krtku > 3);

    int krtek_postup[pocet_zivych_krtku];
    int krtek_pozice_aktualni[pocet_zivych_krtku];
    int krtek_pozice_predchozi[pocet_zivych_krtku];
    int krtek_zivy[pocet_zivych_krtku];
    int tmp[] = {0, 0, 0};
    int hadani_krtka = 0;
    int pocet_pokusu = 0;
    
    // Nastaveni pred zacatkem
    for (int i = 0; i < pocet_zivych_krtku; i++)
    {
        krtek_postup[i] = rand() % 2;
        krtek_pozice_aktualni[i] = 1;
        krtek_pozice_predchozi[i] = 0;
        krtek_zivy[i] = 1;
    }

    krtek_postup[rand() % 3] = 2;

    // prvni tri pozice
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < pocet_zivych_krtku; j++)
        {
            krtek_pozice_predchozi[j] = tmp[j];
            tmp[j] = krtek_pozice_aktualni[j];

            krtek_pozice_aktualni[j] = postup(krtek_postup[j], krtek_pozice_aktualni[j], krtek_pozice_predchozi[j]);
            printf("Krtek cislo %d je na pozici %d.\n\n", j+1, krtek_pozice_aktualni[j]);
        }
    }
    

    // hlavni herni cyklus
    while (pocet_zivych_krtku > 0 && pocet_pokusu < 15)
    {
        printf("POCET ZIVYCH: %d\n", pocet_zivych_krtku);
        printf("--------------\n");
        pocet_zivych_krtku = 3;

        for (int j = 0; j < 3; j++)
        {
            printf("Kretek se pohybuje pomoci %d\n", krtek_postup[j]);
            // Pokud uz je krtek mrtvy, tak se jeho tah preskoci
            if (krtek_zivy[j] == 0)
            {
                continue;
            }

            // Uzivatel hada, kde krtek je
            printf("Zadej, kde se krtek cislo %d nachazi:\n", j+1);
            scanf("%d", &hadani_krtka);
            getchar();

            // Pro Fibonacciho postup predchozi hodnota
            krtek_pozice_predchozi[j] = tmp[j];
            tmp[j] = krtek_pozice_aktualni[j];

            // Posun krtka
            krtek_pozice_aktualni[j] = postup(krtek_postup[j], krtek_pozice_aktualni[j], krtek_pozice_predchozi[j]);

            // Uzivatel uhadl, kde krtek je
            if (hadani_krtka == krtek_pozice_aktualni[j])
            {
                printf("Uhadl si, kde krtek je!\n");
                // Styl postupu, ktery krtek pouzival
                if (krtek_postup[j] == 0)
                {
                    printf("Krtek se pohyboval pomoci Fibonacciho posloupnost\n");
                }
                else if (krtek_postup[j] == 1)
                {
                    printf("Krtek se pohyboval pomoci vzorce %d * x\n", nasobek);
                }
                else
                {
                    printf("Krtek se pohyboval pomoci trojuhelnikoveho cisla\n");
                }

                // Krtek se oznaci jako mrtvy
                krtek_zivy[j] = 0;
                pocet_zivych_krtku = 3;
                // Pokud jsou jeste krtci zivy, vypise se jejich pocet
                for (int i = 0; i < 3; i++)
                {
                    printf("Krtek %d\n", i+1);
                    if (krtek_zivy[i] == 0)
                    {
                        printf("Krtek %d je mrtvy\n", i+1);
                        pocet_zivych_krtku--;
                    }
                }
                printf("Pocet zivych krtku je: %d\n", pocet_zivych_krtku);
            }
            else
            {
                printf("Krtek cislo %d je na pozici %d.\n\n", j+1, krtek_pozice_aktualni[j]);
            }
        }
        pocet_pokusu++;
    }

    if (pocet_zivych_krtku > 0)
    {
        printf("Skoda %d krtku je stale zivych!\n", pocet_zivych_krtku);

        for (int j = 0; j < pocet_zivych_krtku; j++)
        {
            if (krtek_postup[j] == 0)
            {
                printf("Krtek se pohyboval pomoci Fibonacciho posloupnost\n");
            }
            else if (krtek_postup[j] == 1)
            {
                printf("Krtek se pohyboval pomoci vzorce %d * x\n", nasobek);
            }
            else
            {
                printf("Krtek se pohyboval pomoci trojuhelnikoveho cisla\n");
            }
        }
    }
    else
    {
        printf("===========\nJSI VYHERCE\n===========\n");
    }

    return 0;
}

int postup(int posloupnost, int x, int y)
{
    if (posloupnost == 0)
    {
        return fibonaci(x, y);
    }
    else if (posloupnost == 1)
    {
        return slozity_postup(x);
    }
    else if (posloupnost == 2)
    {
        return trojuhelnikove_cislo(x);
    }

}

int fibonaci(int x, int y)
{
    return x + y;
}

int slozity_postup(int x)
{
    return (nasobek * x);
}

int trojuhelnikove_cislo(int x)
{
    static int pozice = 1;
    pozice++;
    return x + pozice;
}