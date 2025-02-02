/*================================
Autor: Tomáš Fojtík, I1B
================================*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int pocetKamenu = 20;
    int tahHrace = 0;
    int tahPocitace = 0;
    int pokracovat = 1;

    printf("|Hra s odebirani kamenu|\n\n");

    while (pokracovat == 1)
    {    
        printf("Nová hra\n");
        pocetKamenu = 20;
        while (pocetKamenu > 0)
        {
            printf("Aktualni pocet kamenu: %d\n\n", pocetKamenu);

            // Tah hrace
            do
            {
                printf("Kolik kamenu si vezmes? (moznosti: 1 , 2, 3 kameny)\nHodnota musi byt vetsi nez pocet kamenu!\n");
                scanf("%d", &tahHrace);
                getchar();
            } while (tahHrace < 1 || tahHrace > 3 || tahHrace > pocetKamenu);

            pocetKamenu -= tahHrace;

            if (pocetKamenu == 0)
            {
                printf("Protihrac vyhral!\n");
                break;
            }

            // tah počitače
            if (pocetKamenu > 3)
            {
                tahPocitace = srand() % 3 + 1;
            }
            else if (pocetKamenu == 3)
            {
                tahPocitace = 2;
            }
            else if (pocetKamenu == 2)
            {
                tahPocitace = 1;
            }
            else
            {
                tahPocitace = 1;
                printf("Vyhral si!\n");
                break;
            }
            printf("Pocet kamenu odebranych protihracem: %d\n\n", tahPocitace);
            pocetKamenu -= tahPocitace;
        }

        do
        {
            printf("Pokud chces hrat znovu zadej 1, jestli chces koncit zadej 0\n");
            scanf("%d", &pokracovat);
        } while (pokracovat < 0 || pokracovat > 1);
    }
    
    return 0;
}
