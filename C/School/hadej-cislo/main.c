#include <stdio.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int hracuvTip, nahodneCislo = (rand() % 100) + 1, pocetPokusu = 0;

    while(hracuvTip != nahodneCislo)
    {
        pocetPokusu++;
        printf("hadej cislo (1-100): ");
        scanf("%d", &hracuvTip);

        if(hracuvTip > nahodneCislo)
        {
            printf("Vedle! Hledane cislo je mensi.\n");
        }
        else if(hracuvTip < nahodneCislo)
        {
            printf("Vedle! Hledane cislo je vetsi.\n");
        }
        else
        {
            printf("Máš to!\n");
            printf("Gratuluji, uhadl si cislo! Cislo bylo %d. Počet pokusů: %d\n", nahodneCislo, pocetPokusu);
            break;
        }

        if(abs(nahodneCislo - hracuvTip) < 11)
        {
            printf("Jsi blizko! Hádej s cisli, ktere jsou mezi cisli o 10 vetsi\n");
        }
        
    }
    
    return 0;
}