/*================================
Autor: Tomáš Fojtík, I1B
================================*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int vylosuj_kartu();
    int losovani(int hrac);
    int karta(int hodnota);
    int soucet_hrace = 0;
    int soucet_protivnika = 0;
    int losovat_znovu;

    srand(time(NULL));


    printf("==========================\n\tBLACK JACK\n==========================\n");

    // Hrac
    printf("Prvni dve karty hrace jsou:\n");
    for (int i = 0; i < 2; i++)
    {
        soucet_hrace += losovani(1);
    }
    printf("Soucet karet hrace: %i\n", soucet_hrace);

    printf("Prvni dve karty protivnika jsou:\n");

    // Protivnik
    for (int i = 0; i < 2; i++)
    {
        soucet_protivnika += losovani(0);
    }
    printf("Soucet karet protivnika: %i\n", soucet_protivnika);

    for (int i = 0; i < 2; i++)
    {
        if (soucet_hrace > 21)
        {
            printf("Prohral si! Presahl si hodnotu 21! Tvuj soucet byl %i a od protivnika %i\n", soucet_hrace, soucet_protivnika);
            exit(0);
        }
        else if (soucet_protivnika > 21)
        {
            printf("Vyhral si! Protivnik presahl hodnotu 21! Tvuj soucet byl %i a od protivnika %i\n", soucet_hrace, soucet_protivnika);
            exit(0);
        }
        
        if (i < 1)
        {
            // jinak zeptat se na dalsi kartu
            printf("Chces losovat novou kartu? (1 = ano, 0 = ne)\n");
            scanf("%i", &losovat_znovu);
    
            if (losovat_znovu == 1)
            {
                printf("Hrac:\n");
                soucet_hrace += losovani(1);
            }
            
            // pokud je cislo soupere < 14 pribere si kartu
            if (soucet_protivnika < 14)
            {
                printf("Protivnik:\n");
                soucet_protivnika += losovani(0);
            }
            printf("Soucet karet hrace je: %i\n", soucet_hrace);
            printf("Soucet karet protivnika je: %i\n", soucet_protivnika);
        }
    }

    if (soucet_hrace > soucet_protivnika)
    {
        printf("Vyhral si! Tvuj soucet byl %i a od protivnika %i\n", soucet_hrace, soucet_protivnika);
    }
    else if (soucet_hrace < soucet_protivnika)
    {
        printf("Prohral si! Tvuj soucet byl %i a od protivnika %i\n", soucet_hrace, soucet_protivnika);
    }
    else
    {
        printf("Remiza! Tvuj soucet byl %i a od protivnika %i\n", soucet_hrace, soucet_protivnika);
    }
    
    return 0;
}

vylosuj_kartu()
{
    return rand()%13+1;
}

karta(hodnota)
{
    if (hodnota == 1)
    {
        printf("Eso\n");
    }
    else if (hodnota > 1 && hodnota < 11)
    {
        printf("Karta s hodnotou: %i\n", hodnota);
    }
    else if (hodnota == 11)
    {
        printf("Junak\n");
    }
    else if (hodnota == 12)
    {
        printf("Dama\n");
    }
    else if (hodnota == 13)
    {
        printf("Kral\n");
    }
    else
    {
        printf("Chyba hodnoty\n");
    }    
}

losovani(hrac)
{
    int vylosovana_hodnota;
    if (hrac == 1)
    {
        vylosovana_hodnota = vylosuj_kartu();
        karta(vylosovana_hodnota);
        return vylosovana_hodnota;
    }
    else if (hrac == 0)
    {
        vylosovana_hodnota = vylosuj_kartu();
        karta(vylosovana_hodnota);
        return vylosovana_hodnota;
    }   
}