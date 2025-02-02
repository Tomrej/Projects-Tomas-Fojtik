/*=====================
I1B, Tomáš Fojtík
=====================*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int denNarozeni, mesicNarozeni, rokNarozeni;
    int denDnes, mesicDnes, rokDnes;
    int pocetDni;

    printf("Kolik dni uz vlastne tady na zemi jsi?\n");

    // DATUM NAROZENI
    do
    {
        printf("Zadej den, kdy ses narodil (1-31): ");
        scanf("%d", &denNarozeni);
        getchar();
    } while (denNarozeni < 1 || denNarozeni > 31);

    do
    {
        printf("Zadej mesic, kdy ses narodil (1-12): ");
        scanf("%d", &mesicNarozeni);
        getchar();
    } while (mesicNarozeni < 1 || mesicNarozeni > 12);
    
    printf("Zadej rok, kdy ses narodil: ");
    scanf("%d", &rokNarozeni);
    getchar();

    printf("Narodil ses %d.%d.%d\n", denNarozeni, mesicNarozeni, rokNarozeni);

    // DNESNI DATUM
    do
    {
        printf("Zadej dnesni den (1-31): ");
        scanf("%d", &denDnes);
        getchar();
    } while (denDnes < 1 || denDnes > 31);

    do
    {
        printf("Zadej co je dnes za mesic (1-12): ");
        scanf("%d", &mesicDnes);
        getchar();
    } while (mesicDnes < 1 || mesicDnes > 12);
    
    printf("Zadej rok: ");
    scanf("%d", &rokDnes);
    getchar();

    printf("Dnes je %d.%d.%d\n", denDnes, mesicDnes, rokDnes);

    printf("Nyni spocitam kolik dni jiz zijes.\n");

    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".\n");
    sleep(1);

    pocetDni = (int)((rokDnes - rokNarozeni - 1) * 365.25); // pocet presnych roku ktere uz uzivatel prezil

    for (int i = 0; i < (12 - mesicNarozeni); i++)
    {
        if (12 - i == 1 || 12 - i == 3 || 12 - i == 5 || 12 - i == 7 || 12 - i == 8 || 12 - i == 10 || 12 - i == 12)
        {
            pocetDni += 31;
        }
        else if (12 - i == 4 || 12 - i == 6 || 12 - i == 9 || 12 - i == 11)
        {
            pocetDni += 30;
        }
        else if (12 - i == 2)
        {
            pocetDni += 28;
        }
    }
    
    
    for (int i = 0; i < (mesicDnes - 1); i++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
        {
            pocetDni += 31;
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11)
        {
            pocetDni += 30;
        }
        else if (i == 2)
        {
            pocetDni += 28;
        }
    }
    
    pocetDni += (31 - denNarozeni) + denDnes; // prida se soucet dnu

    printf("Neuveritelne! Uz je to %d dni!\n\n", pocetDni);
    sleep(3);
    printf("Na Merkuru by ti bylo %d roku\n", pocetDni / 88);
    sleep(1);
    printf("Na Venusi by ti bylo %d roku\n", pocetDni / 225);
    sleep(1);
    printf("Na Marsu by ti bylo %.3f roku\n", pocetDni / (float)687);
    sleep(1);
    printf("Na Jupiteru by ti bylo %.3f roku\n", pocetDni / (float)4332);
    sleep(1);
    printf("Na Saturnu by ti bylo %.3f roku\n", pocetDni / (float)10760);
    sleep(1);
    printf("Na Uranu by ti bylo %.3f roku\n", pocetDni / (float)30685);
    sleep(1);
    printf("Na Neptunu by ti bylo %.3f roku\n", pocetDni / (float)60191);

    return 0;
}
