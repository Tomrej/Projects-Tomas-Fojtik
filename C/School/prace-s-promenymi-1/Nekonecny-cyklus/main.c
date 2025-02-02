#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char znak;
    int casovac = 20;

    while (1)
    {
        printf("Uzivatel nereaguje. \n");
        if (kbhit())
        {
            printf("Uzivatel stiskl klavesu.\n");
            znak = getch();

            if (znak == 'a')
            {
                printf("Vyborne, bomba deaktivovana\n");
                break;
            }
            else
            {
                printf("Nepsravna klavesa\n");
            }
            

            printf("Uzivatel stiskl klavesu %c.\n", znak);
            
        }
        casovac--;
        sleep(1);

    }
    return 0;
}