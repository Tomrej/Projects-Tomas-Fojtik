#include <stdio.h> 
#include "common.h"
#include "guess.h"
#include "reward.h"

typedef struct hrac {
    int id;
    int pokusy;
    int body;
} hrac;

int main(int argc, char const *argv[])
{
    int pocet_hracu = 0, pocet_bodu;
    int aktualni_hrac = 0;

    printf("====================\n\tHRA\n====================\n");
    
    printf("Zadej pocet hracu (2-4):\n");
    do
    {
        scanf("%d", &pocet_hracu);
    } while (pocet_hracu < 2 || pocet_hracu > 4);

    pocet_hracu -= 1;
    
    hrac hraci[pocet_hracu + 1];

    for (int i = 0; i <= pocet_hracu; i++)
    {
        hraci[i].body = 0;
        hraci[i].id = i;
        hraci[i].pokusy = 0;
    }
    
    printf("\nZadej pocet bodu pro vitezstvi:\n");
    scanf("%d", &pocet_bodu);
    
    for (int i = 1; ; i++)
    {
        printf("Hraje hrac %d\n", aktualni_hrac + 1);
        
        hraci[aktualni_hrac].pokusy = guess();

        aktualni_hrac++;
        if (aktualni_hrac > pocet_hracu)
        {
            aktualni_hrac = 0;
        }

        if (i % (pocet_hracu + 1) == 0) 
        {
            int nejlepsi_hrac = 0;

            for (int j = 1; j <= pocet_hracu; j++)
            {
                if (hraci[j].pokusy > hraci[nejlepsi_hrac].pokusy)
                {
                    nejlepsi_hrac = j;
                }                
            }
            
            hraci[nejlepsi_hrac].body += 1;

            for (int j = 0; j <= pocet_hracu; j++)
            {
                if (hraci[j].pokusy == hraci[nejlepsi_hrac].pokusy && j != nejlepsi_hrac)
                {
                    hraci[j].body += 1;
                    printf("Hrac %d dostava bod.\n");
                }
            }
            
            if (hraci[nejlepsi_hrac].body >= pocet_bodu)
            {
                printf("Hrac %d vyhral! Gratuluji! Tady je tvoje odmena formou vtipu:\n\n", nejlepsi_hrac + 1);
                reward();
                return 0;
            }
        }
    }
    
    return 0;
}