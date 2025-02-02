#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //==========================================================================================
    // kus kodu, do ktereho nezasahujte, slouzi k tomu, abychom mohli pracovat s aktualnim datem
    //==========================================================================================
    time_t s, val = 1;
    int den, mesic, rok;
    struct tm* datum;

    s = time(NULL);

    datum = localtime(&s);
    rok = datum->tm_year + 1900;

    //asi jedine dve promenne, se kterymi budete pracovat
    den = datum->tm_mday;
    mesic = datum->tm_mon + 1;

    //==========================================================================================
    // zde muze nasledovat Vas kod
    //==========================================================================================
    srand(time(NULL));

    //kontrolni vypis (overeni, ze vse funguje, muzete vymazat)
    printf("Je %d. %d. %d\n", den, mesic, rok);

    int *kalendar = (int *) malloc(24 * sizeof(int));

    // Naplni pole od 1 po 24
    for (int i = 0; i < 24; i++)
    {
        kalendar[i] = i + 1;
    }

    // zamicha pole
    for (int i = 0; i < 24; i++)
    {
        int cache;
        int rand_i = rand() % 24;

        cache = kalendar[i];
        kalendar[i] = kalendar[rand_i];
        kalendar[rand_i] = cache;
    }
    
    // vypsani kalendare
    for (int i = 0; i < 24; i++)
    {
        printf("%d\t", kalendar[i]);

        if ((i + 1) %  6 == 0 && i != 0)
        {
            printf("\n");
        }
    }

    int policko;
    while (1)
    {
        do
        {
            printf("Zadej, ktere policko chces otevrit (1 - 24). Pro ukonceni zadej 0:\n");
            scanf("%d", &policko);
        } while (policko < 0 || policko > 24);

        if (policko > den)
        {
            printf("Toto policko jeste nemuzes otevrit. Vrat se za %d dnu.\n", policko - den);
            continue;
        }
        
        if (policko == 0)
        {
            printf("Adventni kalendar se ukonci.\n");
            return 0;
        }
        
        if (kalendar[policko] == 0)
        {
            printf("Toto policko si uz otevrel. Policka nemuzes otevirat znovu.\n");
            continue;
        }
        
        printf("Tvoje odmena je na tomto odkazu: https://randme.me/\n");
        
        kalendar[policko] = 0;
    }
    

    free(kalendar);
    kalendar = NULL;

    return 0;
}