#include <stdio.h>
#include <stdlib.h>

#define ROZMER 10
#define POCET_MIN 14

struct pole
{
    char zobrazeni;
    int hodnota; // 9 = mina; zbytek pocet min
};

typedef struct pole pole;

void inicializace(pole hraciPole[ROZMER][ROZMER]);
void vykresli(pole hraciPole[ROZMER][ROZMER]);
void rozlozMiny(pole hraciPole[ROZMER][ROZMER]);
int jeHratelne(int x, int y);
void ohodnotPole(pole hraciPole[ROZMER][ROZMER]);
int tahHrace(pole hraciPole[ROZMER][ROZMER]);

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int hraciPole[ROZMER][ROZMER];
    
    inicializace(hraciPole);
    rozlozMiny(hraciPole);
    ohodnotPole(hraciPole);
    vykresli(hraciPole);

    /*while (1)
    {
        vykresli(hraciPole);

        tahHrace(hraciPole);
    }*/
    

    return 0;
}

void inicializace(pole hraciPole[ROZMER][ROZMER])
{
    for (int i = 0; i < ROZMER; i++)
    {
        for (int j = 0; j < ROZMER; j++)
        {
            hraciPole[i][j].zobrazeni = '.';
            hraciPole[i][j].hodnota = 0;
        }      
    }
}

void vykresli(pole hraciPole[ROZMER][ROZMER])
{
    printf("   ");
    for (int i = 0; i < ROZMER; i++)
    {
        printf("%d  ", i);
    }
    printf("\n");
    
    for (int i = 0; i < ROZMER; i++)
    {
        printf("%d ", i);

        for (int j = 0; j < ROZMER; j++)
        {
            printf(" %c ", hraciPole[i][j].zobrazeni);
        }
        printf("\n");
    }
}

void rozlozMiny(pole hraciPole[ROZMER][ROZMER])
{
    int poloha[] = {0, 0};

    for (int i = 0; i < POCET_MIN; i++)
    {
        do
        {
            poloha[0] = rand() % ROZMER;
            poloha[1] = rand() % ROZMER;
        } while (hraciPole[poloha[0]][poloha[1]].hodnota == 9);

        hraciPole[poloha[0]][poloha[1]].hodnota = 9;
    }
    
}

int jeHratelne(int x, int y)
{
    if (x >= 0 && x < ROZMER && y >= 0 && y < ROZMER)
    {
        return 1;
    }
    return 0;    
}

void ohodnotPole(pole hraciPole[ROZMER][ROZMER])
{
    for (int i = 0; i < ROZMER; i++)
    {
        for (int j = 0; j < ROZMER; j++)
        {
            if (hraciPole[i][j].hodnota == 9)
            {
                continue;
            }
            
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    if (jeHratelne(k - 1, l - 1) && hraciPole[k - 1][j - 1].hodnota == 9)
                    {
                        hraciPole[i][j].hodnota++;
                    }
                }
            }       
        }      
    }
}

int tahHrace(pole hraciPole[ROZMER][ROZMER])
{
    int poloha[] = {0, 0};
    system("cls");

    do
    {
        printf("Zadej radu, s kterou polem chces interagovat:\n");
        scanf("%d", poloha[0]);
        printf("Zadej sploupec s kterym chces intereagovat:\n");
        scanf("%d", poloha[1]);
    } while (!jeHratelne(poloha[0], poloha[1]));

    vykresli(hraciPole);

    printf("Zadej cislo moznosti:\n1) Oznacit pole\n2) Odkryt pole\n3) Vybrat jine pole\n");

}
