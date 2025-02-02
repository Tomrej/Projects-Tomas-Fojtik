/*=====================
Tomáš Fojtík, I1B
=====================*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    char pokracovat = 'y';
    int tip, skorapka;

    srand(time(NULL));

    printf("\t\t\t|Skorapky - terminalova hra|\n\n");

    while (pokracovat == 'y' || pokracovat == 'Y')
    {
        printf("Pro spusteni hry stiskni jakoukoliv klavesu.");
        getchar();

        for (int i = 0; i < 12; i++)
        {
            system("cls");

            skorapka = rand() % 3 + 1;

            if (skorapka == 1)
            {
                printf("\t\t\t(*)\t\t\t( )\t\t\t( )\n");
            }
            else if (skorapka == 2)
            {
                printf("\t\t\t( )\t\t\t(*)\t\t\t( )\n");
            }
            else if (skorapka == 3)
            {
                printf("\t\t\t( )\t\t\t( )\t\t\t(*)\n");
            }

            usleep(150000);
        }

        system("cls");
        printf("Kde je kulicka?\n");
        do
        {
            printf("Zadej kde je kulicka. (1-3)\n");
            scanf("%d", &tip);
            getchar();
        } while (tip < 1 || tip > 3);
        
        if (tip == skorapka)
        {
            printf("Uhadl si kde je kulicka!\n");
        }
        else
        {
            printf("Spatne! Kulicka byla pod %d skorapkou.\n", skorapka);
        }
        
        printf("Pokud chces pokracovat, zadej \'y\', pro ukonceni zadej \'n\'\n");
        scanf(" %c", &pokracovat);
    }
    
    return 0;
}
