#include <math.h>
#include <stdio.h>

#include "treti.h"

int prvocislo(int x)
{
    for (int i = 2; i <= x - 1; i++)
    {
        if (x % i == 0)
        {
            // Neni prvocislo
            return 1;
        }
    }
    // je prvocislo
    return 0;
}

void kvadraticka_rovnice(int a, int b, int c, int x)
{
    int d = b * b - 4 * a * c;

    if (d < 0)
    {
        printf("Nema reseni v realnych cislech\n");
        return;
    }

    int x1 = (-b + (int)sqrt(d)) / (2 * a);
    int x2 = (-b - (int)sqrt(d)) / (2 * a);
    // zvolil jsem zde printf abych se vyhnul array, nebo jinym komplikacim :)
    printf("Kvadraticka rovnice ma koreny:\nx1 = %d\nx2 = %d\n", x1, x2);
    return;
}

int nejvetsi_spolecny_delitel(int x, int y)
{
    int spolecny_delitel_max = 1;
    for (int i = 2; i < (x < y ? x : y); i++)
    {
        if (x % i == 0 && y % i == 0)
        {
            spolecny_delitel_max = i;
        }
    }
    return spolecny_delitel_max;
}