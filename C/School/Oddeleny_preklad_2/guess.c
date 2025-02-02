#include "common.h"

int guess()
{
    srand(time(NULL));
    int cislo = rand() % 101; // prehodit opet na 100
    int vstup = 999;
    int pocet_pokusu = 0;

    while (vstup != cislo)
    {
        printf("\nHadej cislo (0 - 100):\n");
        scanf("%d", &vstup);
        pocet_pokusu++;
        if (pocet_pokusu % 3 == 0)
        {
            napoveda(cislo);
        }
        
    }
    printf("Uhodnuto\n");
    return pocet_pokusu;
}

void napoveda(int cislo)
{
    switch (rand() % 5)
    {
    case 0:
        printf("| Cislo %s sude\n", cislo % 2 == 0 ? "je" : "neni");
        break;
    
    case 1:
        printf("| Cislo je %s nez 50\n", cislo >= 50 ? "vetsi nebo rovna se" : "mensi");
        break;
    
    case 2:
        printf("| Cislo %s delitelne tremi.\n", cislo % 3 == 0 ? "je" : "neni");
        break;

    case 3:
        printf("| Cislo %s delitelne deseti.\n", cislo % 10 == 0 ? "je" : "neni");
        break;

    default:
        break;
    }
}