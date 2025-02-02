/*=============================
AUTOR: Tomáš Fojtík
=============================*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    // PRVNI CAST
    int cislo1, cislo2;

    printf("Napis dve cisla:\n");
    scanf("%d%d", &cislo1, &cislo2);

    if (cislo1 == cislo2)
    {
        printf("Cisla se rovnaji (%d)\n", cislo1);
    }
    else if (cislo1 > cislo2)
    {
        printf("Vetsi je cislo: %d\n", cislo1);
        printf("Mensi je cislo: %d\n", cislo2);
    }
    else
    {
        printf("Vetsi je cislo: %d\n", cislo2);
        printf("Mensi je cislo: %d\n", cislo1);
    }
    
    // DRUHA CAST
    int nahodne;
    srand(time(NULL));
    nahodne = rand()%10 - 6;
    
    printf("Nahodne cislo: %d\n", nahodne);
    
    if (nahodne % 2 == 0)
    {
        printf("Nahodne cislo %d je sude\n", nahodne);
    }
    else
    {
        printf("Nahodne cislo %d je liche\n", nahodne);
    }
    
    if (nahodne == 0)
    {
        printf("Nahodne cislo se rovna 0\n");
    }
    else if (nahodne > 0)
    {
        printf("Nahodne cislo je kladne\n");
    }
    else
    {
        printf("Nahodne cislo je zaporne\n");
    }
    
    // TRETI CAST
    char znak;
    printf("Napis nejaky znak:\n");
    scanf(" %c", &znak);

    if ((znak >= 65 && znak <= 90) || (znak >= 97 && znak <= 122))
    {
        printf("Je to pismeno abecedy\n");
    } else if (znak >= 48 && znak <= 57)
    {
        printf("Znak je cislice\n");
    }
    else
    {
        printf("Znak neni ani cislo ani pismeno abecedy\n");
    }
    

    if (znak >= 65 && znak <= 90)
    {
        printf("Je to velke pismeno\n");
    }
    else if (znak >= 97 && znak <= 122)
    {
        printf("Je to male pismeno\n");
    }
    
    int cislo3, cislo4, cislo5;
    printf("Zadej tri cisla:\n");
    scanf("%d%d%d", &cislo3, &cislo4, &cislo5);

    // doresit problem kdyz se dve cisla rovnaji
    if (cislo3 == cislo4 && cislo3 == cislo5)
    {
        printf("Cisla se rovnaji\n");
    }
    else if (cislo3 >= cislo4 && cislo3 >= cislo5)
    {
        if (cislo3 == cislo4)
        {
            printf("Cislo %i je nejvetsi a vyskytuje se zde dvakrat. Cislo %i je nejmensi\n", cislo3, cislo5);
        }
        else if (cislo3 == cislo5)
        {
            printf("Cislo %i je nejvetsi a vyskytuje se zde dvakrat. Cislo %i je nejmensi\n", cislo3, cislo4);
        }
        
        else if (cislo3 > cislo4 && cislo3 > cislo5)
        {
            printf("Cislo %i je nejvetsi", cislo3);
            if (cislo4 > cislo5)
            {
                printf(" Cislo %i je nejmensi\n", cislo5);
            }
            else
            {
                printf(" Cislo %i je nejmensi\n", cislo4);
            }
        }
    }
    else if (cislo4 >= cislo5 && cislo4 >= cislo3)
    {
        if (cislo4 == cislo5)
        {
            printf("Cislo %i je nejvetsi a vyskytuje se zde dvakrat. Nejmensi je cislo %i\n", cislo4, cislo3);
        }
        else if (cislo4 > cislo5)
        {
            printf("Cislo %i je nejvetsi", cislo4);
            if (cislo3 < cislo5)
            {
                printf(" Cislo %i je nejmensi\n", cislo3);
            }
            else
            {
                printf(" Cislo %i je nejmensi\n", cislo5);
            }   
        }
        
    }
    else if (cislo5 > cislo4 && cislo5 > cislo3)
    {
        printf("Cislo %i je nejvetsi.", cislo5);
        if (cislo4 > cislo3)
        {
            printf(" Cislo %i je nejmensi\n", cislo3);
        }
        else
        {
            printf(" Cislo %i je nejmensi\n", cislo4);
        }
        
    }
    
    
    int uhel1, uhel2, uhel3;
    printf("Zadej vsechny tri uhly trojuhelniku (napis pouze cislo):\n");
    scanf("%d%d%d", &uhel1, &uhel2, &uhel3);

    if (uhel1 + uhel2 + uhel3 == 180)
    {
        printf("Trojuhelnik lze sestrojit\n");
    }
    else
    {
        printf("Trojuhelnik nelze sestrojit\n");
    }
    

    return 0;
}
