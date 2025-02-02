#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    srand(time(NULL));
    int pocetHvezdicek = 0, hracuvTip, kostka, body = 0, aktivace = 0;
    int *bonus = NULL;

    while (body < 500)
    {
        pocetHvezdicek = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                kostka = rand() % 20;

                if (kostka == 5)
                {
                    printf("*");
                    pocetHvezdicek++;
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        sleep(3);
        system("cls");
        printf("Hadej kolik bylo hvezdicek:\n");
        scanf("%d", &hracuvTip);
        getchar();

        if (hracuvTip == pocetHvezdicek)
        {
            printf("Uhadl si spravne pocet hvezdicek!\n");
            body++;
            aktivace++;
        }
        else if (bonus != NULL && abs(pocetHvezdicek - hracuvTip) <= 3)
        {
            printf("Diky bonusu si uhadl spravne pocet hvezdicek!\n");
            body++;
            aktivace++;
        }
        
        else
        {
            printf("Neuhadl si pocet hvezdicek!\n");
            free(bonus);
            aktivace = 0;
        }

        if (aktivace >= 3 && bonus == NULL)
        {
            printf("Ziskavas BONUS!!! Nyni mas toleranci +- 3. Ztratis ho kdyz uhadnes blbe.");
            bonus = (int *)malloc(sizeof(int));
        }
    }   


    if (bonus != NULL)
    {
        free(bonus);
    }
    
    return 0;
}
