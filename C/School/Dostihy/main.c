#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void pokracovat();
void setup(char draha[]);
void generace_prekazek(char draha[]);
void vypis_drahy(char draha[]);
void uvod();
void beh_koni(char draha[], int penize);

const int POCET_PREKAZEK = 4;
const int DELKA_DRAHY = 20;

int main()
{
    srand(time(NULL));

    int penize = 10000;
    char draha[DELKA_DRAHY];

    setup(draha);
    generace_prekazek(draha);

    uvod();

    beh_koni(draha, penize);

    return 0;
}

void pokracovat()
{
    int vstup;
    printf("\nPro pokracovani stistkni jakoukoliv klavesu...\n");
    vstup = getch();
    if (vstup == 'q')
    {
        printf("Konec");
        exit(0);
    }
    
}

void uvod()
{
    system("cls");
    printf("\t\t=======================\n\t\t\tDOSTIHY\n\t\t=======================\n");
    printf("\nV teto hre zavodi proti sobe dva kone a ty muzes na ne vsadit svoje drahocene penize.\nPro ukonceni stistkni ve vyberu 'q'\n");
    printf("Nachazi se zde draha, ktera ma toto znaceni\n\t- _ = obycejna cesta drahy\n\t- H = prekazka\n\t- 1 = kun 1 se nachazi na teto pozici\n\t- 2 = Kun 2 se nachazi na teto pozici\n\n");
    pokracovat();
}

void setup(char draha[])
{
    for (int i = 0; i < DELKA_DRAHY; i++)
    {
        draha[i] = '_';
    }
}

void generace_prekazek(char draha[])
{
    int rand_pos = 0;
    for (int i = 0; i < POCET_PREKAZEK; i++)
    {
        do
        {
            rand_pos = rand() % 18 + 1;
        } while (draha[rand_pos] == 'H');
        
        draha[rand_pos] = 'H';
    }
}

void vypis_drahy(char draha[])
{
    for (int i = 0; i < DELKA_DRAHY; i++)
    {
        printf("%c ", draha[i]);
    }
    printf("\n");    
}

void beh_koni(char draha[], int penize)
{
    int pozice_k1;
    int pozice_k2;

    int kun;
    int sazka;

    do
    {
        pozice_k1 = 0;
        pozice_k2 = 0;
        printf("\n\t\t\tZACINAJI DOSTIHY\n");
        printf("\t- Stav penez: %d ,-\n\n", penize);

        do
        {
            printf("\nNa jakeho kone si chces vsadit (1 nebo 2)?\n");
            scanf("%d", &kun);
            getchar();
        } while (kun != 1 && kun != 2);

        do
        {
            printf("Kolik si chces vsadit na toho kone (max %d, min 1000)\n", penize);
            scanf("%d", &sazka);
            getchar();
        } while (sazka >= penize || sazka < 1000);


        while (pozice_k1 != 19 && pozice_k2 != 19)
        {
            system("cls");

            pozice_k1 += rand() % 3 + 1;
            pozice_k2 += rand() % 3 + 1;

            if (pozice_k1 > 19)
            {
                pozice_k1 = 19;
            }
            if (pozice_k2 > 19)
            {
                pozice_k2 = 19;
            }     

            if (draha[pozice_k1] == 'H')
            {
                printf("Kun cislo 1 skoncil na prekazce! Vraci se zpatky na zacatek.\n");
                pozice_k1 = 0;
                draha[0] = '1';
            }
            else
            {
                draha[pozice_k1] = '1';
            }


            if (draha[pozice_k2] == 'H')
            {
                printf("Kun cislo 2 skoncil na prekazce! Vraci se zpatky na zacatek.\n");
                pozice_k2 = 0;
                draha[0] = '2';
            }
            else
            {
                draha[pozice_k2] = '2';
            }

            if (pozice_k1 == pozice_k2)
            {
                draha[pozice_k1] = 'O';
            }

            printf("\n- Kun 1 se dostal na pozici: %d\n- Kun 2 se dostal na pozici: %d\n\n", pozice_k1 + 1, pozice_k2 + 1);
            vypis_drahy(draha);
            draha[pozice_k1] = '_';
            draha[pozice_k2] = '_';
            pokracovat();
        }

        if (pozice_k1 > pozice_k2)
        {
            printf("Kun cislo 1 vyhrava!\n");
            penize += (kun == 1 ? sazka * 2 : -sazka);
        }
        else if (pozice_k1 < pozice_k2)
        {
            printf("Kun cislo 2 vyhrava!\n");
            penize += (kun == 2 ? sazka * 2 : -sazka);
        }
        else
        {
            printf("Je to neuveritelne, ale oba kone dobehli soucasne!\n");
        }
        setup(draha);
        generace_prekazek(draha);


    } while (penize > 1000);
    printf("Prisel si o vsechny penize! Hra konci!\n");
}