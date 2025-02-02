/*
Pointery a  fuknce 1
====================
Zpracoval Tomáš Fojtík
I2B
21.11.2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void petinasobek(float *a);
void rozdil(float *a, float *b);
void vzorec(float *a, float *b);
void prumer(float *a, float *b);
void tretiMocnina(float *a, float *b);

int main()
{
    srand(time(NULL));

    float a = 3.14;
    float b = 1.618;

    int opakovani = 0;

    do
    {
        printf("Zadej kolikrat se ma cyklus opakovat (vetsi nez 1): ");
        scanf("%d", &opakovani);
        getchar();
    } while (opakovani <= 1);
    printf("\n");

    for (int i = 0; i < opakovani; i++)
    {
        switch (rand() % 5 + 1)
        {
        case 1:
            petinasobek(&a);
            break;
        
        case 2:
            rozdil(&a, &b);
            break;
        
        case 3:
            vzorec(&a, &b);
            break;
        
        case 4:
            prumer(&a, &b);
            break;
        
        case 5:
            tretiMocnina(&a, &b);
            break;
        
        default:
            break;
        }
        printf("\n");

    }
    printf("Aktualni hodnota a: %f\n", a);
    printf("Aktualni hodnota b: %f\n", b);

    return 0;
}

void petinasobek(float *a)
{
    *a *= 5;
    printf("Hodnota a byla zpetinasobena. Aktualne se rovna %f.\n", *a);
}

void rozdil(float *a, float *b)
{
    *b = fabs(*a - *b);
    printf("Rozdil promene a a promene b byl ulozen do b. Aktualne se rovna %f.\n", *b);
}

void vzorec(float *a, float *b)
{
    *a = (*a + 2 * *b) / *a;
    printf("Hodnota a byl zmenena vzorcem (a + 2 * b) / 2. Aktualne se rovna %f.\n", *a);
}

void prumer(float *a, float *b)
{
    *b = (*a + *b) / 2;
    printf("Hodnota b byla zmenena na prumer promene a a promene b. Aktualne se rovna %f.\n", *b);
}

void tretiMocnina(float *a, float *b)
{
    *a += *b * *b * *b;
    printf("K hodnote a byla prictena treti mocnina hodnoty b. Aktualne se rovna %f.\n", *a);
}
