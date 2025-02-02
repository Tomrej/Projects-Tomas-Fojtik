/*================================
Autor: Tomáš Fojtík, I1B
================================*/

// ! Předělat všechna cat a clear na type pro windows
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{   
    srand(time(NULL));
    //* Priprava
    int lokace = 1;
    int cas = 10;
    // HRAC
    int zdravi = 100;
    int silaUtoku = 1;
    int presvedcivost; // !bez funkce
    int nenapadnost; // !bez funkce
    int stesti = 1;

    int inventar[4] = {0, 0, 0, 0};

    int input;
    // Jeskyne
    int truhlaJeskyne[2] = {1, 2};
    int vychodJeskyne = 0;
    // Herni funkce
    int generaceStesti(int stesti);
    int boj(char jmeno[], int BossHp, int hracHp, int sila, int stesti);
    int utok(int sila, int stesti);
    void text(char zprava[]);
    void next();
    int potvrzeni();
    int inventarMenu(int inventar[]);
    int kamDal(int mozneVolby[]);

    //* Uvod
    system("cat ASCII/title.txt");
    printf("\n\n\n");

    printf("1) NOVA HRA\n");
    printf("2) NACIST HRU\n");
    printf("3) KONEC\n");

    do
    {
        printf("\nVaše volba (1-3): ");
        scanf("%d", &input);
        getchar();
    } while (input < 1 || input > 3);

    if (input == 1)
    {
        printf("\nSpousti se nova hra!\n");
        system("clear");
    }
    else if (input == 2)
    {
        // TODO: Pridat nacitani hry
    }
    else
    {
        printf("\nKonec hry\n");
        exit(0);
    }
    
    



    printf("Vitej ve hre!\n");
    sleep(5);

    //printf("PRIDEJ PRIBEH\n"); // TODO: Pridat pribeh - viz classroom, nebo !vlastni!
    text("Vy: Kde to jsem?\n");
    // TODO: pridat cekani mezi zpravy
    text("Vy: Au, moje hlava... moc si toho nepamatuji... jak jsem se tady dostal?\n");

    text("???: Tenhle les je proklety zlym carodejem...\n");
    text("???: Potrebujeme tvoji pomoc.\n");
    text("???: Ja te tady prenesla, aby si nas zachranil!\n");

    text("Vy: Kdo vlastne jsi? A proc ja?\n");

    text("Vila: Jejda, promin, zapomnela jsem se predstavit... Jsem vila, ktera je v rebelii proti carodejnikovi.\n");
    text("Vila: Zatim ti nemuzu rict svoje jmeno a vic informaci, jenom si vezmi veci, ktere jsme ti schovala do truhly.\n");
    text("Vila: Musim zmizet.\n");
    text("...\n");

    text("Vy: Pockej! Ja tady nechci byt! Nedokazu vam pomoct! Jsem obycejny clovek a nemam tady co delat!\n");

    /* Uvod konec*/

    text("Vy: Zmizela... Co mi zbyva, musim se podivat na tu truhlu, treba zjistim vic\n");
    next();

    //* Hlavni cyklus hry
    while (cas > 0)
    {   
        cas  -= 1;
        switch (lokace)
        {
        case 1:
            // Jeskyne v lese kde se probudi postava
            // vykresli tady pomoci asci nejak tu jeskyni
            system("cat ASCII/Locations/cave.txt");
            system("cat ASCII/Text/cave.txt");
            printf("\n-V teto jeskyni je jedna truhla\n");
            
            while (1==1)
            {
                printf("\nCo chces provest ted? Jsou zde dve moznosti interakce:\n1) Truhla\n2) Vychod\n");
                input = 0;
                do
                {
                    printf("\nVaše volba (1-2): ");
                    scanf("%d", &input);
                    getchar();
                } while (input < 1 || input > 2);

                // truhla
                if (input == 1)
                {            
                    text("Vy: Tak tady je ta truhla, tak jo asi bych se mel do ni podivat.\n");
                    if (potvrzeni("Chces se podivat na obsah truhly?") == 1)
                    {
                        text("Vy: Tak co je tady v teto truhle?\n");

                        if (truhlaJeskyne[0] == 1 && truhlaJeskyne[1] == 2)
                        {
                            printf("\n-----  -------\n");
                            printf("|MEC|  |DOPIS|\n");
                            printf("-----  -------\n");

                            if (potvrzeni("Chces si vzit mec do inventare?") == 1)
                            {
                                inventar[0] = 1;
                                truhlaJeskyne[0] = 0;
                                printf("|Mec pridan do inventare\n");
                            }
                            if (potvrzeni("Chces si precist dopis?") == 1)
                            {
                                truhlaJeskyne[1] = 0;
                                system("cat Dopis/truhla-cave.txt");
                                text("Vy: Tak to bude jeste prace. Proc zrovna ja?\n");
                            }
                        }
                        else if (truhlaJeskyne[0] == 1)
                        {
                            text("Vy: Co jsem to tady nechal?");

                            printf("\n----\n");
                            printf("|MEC|\n");
                            printf("-----\n");

                            if (potvrzeni("Chces si vzit mec do inventare?") == 1)
                            {
                                truhlaJeskyne[0] = 0;
                                inventar[0] = 1;
                                printf("|Mec pridan do inventare\n");
                            }
                        }
                        else if (truhlaJeskyne[1] == 2)
                        {
                            text("Vy: Co jsem to tady nechal?");

                            printf("\n------\n");
                            printf("|DOPIS|\n");
                            printf("-------\n");

                            if (potvrzeni("Chces si precist dopis?") == 1)
                            {
                                truhlaJeskyne[1] = 0;
                                system("cat Dopis/truhla-cave.txt");
                                text("\nVy: Tak to bude jeste prace. Proc zrovna ja?\n");
                            }
                        }
                        else
                        {
                            text("Vy: Hm... tato truhla je prazdna.\n");
                        }     
                    }
                }
                // vychod
                else if (input == 2)
                {
                    if (vychodJeskyne == 0 && inventar[0] != 1)
                    {
                        text("Vy: Vchod je necim zadelany...\n");
                        text("Vy: Rukou to nezvladnu strhnout.\n");
                    }
                    else if (vychodJeskyne == 0 && inventar[0] == 1)
                    {
                        text("Vy: Vchod je necim zadelany...\n");
                        text("Vy: Ale mam mec. Co kdyz to tim preseknu?\n");
                        text("Vy: Ha! Fungovalo to! Nejsem zas tak k nicemu. No ale tady to hadam teprve zacina... \n");
                        break;
                    }
                    else
                    {
                        text("Vy: To je teda vune lesa! Tu uz jsem dlouho necitil.\n");
                    }
                }
            }
            
            break;
        case 2:
            // Pocestný
            system("cat ASCII/Locations/pilgrim.txt");
            system("cat ASCII/Text/pilgrim.txt");
            printf("\nV teto jeskyni je jedna truhla\n");
            break;
        case 3:
            // Bažina
            system("cat ASCII/Locations/swamp.txt");
            system("cat ASCII/Text/swamp.txt");
            printf("\nV teto jeskyni je jedna truhla\n");
            break;
        case 4:
            // Secret cesta na vrchol hory
            system("cat ASCII/Locations/cave.txt");
            system("cat ASCII/Text/cave.txt");
            printf("\nV teto jeskyni je jedna truhla\n");
            break;
        case 5:
            // Žabí údolí
            system("cat ASCII/Locations/frog.txt");
            system("cat ASCII/Text/frog.txt");
            printf("\nV teto jeskyni je jedna truhla\n");
            break;
        case 6:
            // Prázdná vesnice
            system("cat ASCII/Locations/village.txt");
            system("cat ASCII/Text/village.txt");
            printf("\nV teto jeskyni je jedna truhla\n");
            break;
        case 7:
            // Důl
            system("cat ASCII/Locations/mine.txt");
            system("cat ASCII/Text/mine.txt");
            printf("\nV teto jeskyni je jedna truhla\n");
            break;
        case 8:
            // Makové pole
            system("cat ASCII/Locations/poppy.txt");
            system("cat ASCII/Text/poppy.txt");
            printf("\nV teto jeskyni je jedna truhla\n");
            break;
        case 9:
            // Hlavní rozcestí
            system("cat ASCII/Locations/crossroad.txt");
            system("cat ASCII/Text/crossroad.txt");
            printf("\nV teto jeskyni je jedna truhla\n");
            break;
        case 10:
            // Konec
            system("cat ASCII/Locations/tower.txt");
            system("cat ASCII/Text/tower.txt");
            printf("\nV teto jeskyni je jedna truhla\n");
            break;
        
        default:
            break;
        }
        next();  
    }
    

    return 0;
}

int generaceStesti(int stesti)
{
    return rand() % 10 + stesti;
}

int boj(char jmeno[22], int BossHp, int hracHp, int sila, int stesti)
{
    char soubor[] = ("cat Bosss/%s/info.txt", jmeno);
    int tah = 0;
    system("clear");

    system(soubor);
    printf("Tvoje statistiky:\nzdravi: %d hp\nsila: %d\n", hracHp, sila);

    
    if (generaceStesti(stesti) < 5)
    {
        printf("|Jsi prvni na tahu.\n");
        int tah = 0;
    }
    else
    {
        printf("|Prvni je na tahu souper.\n");
        int tah = 1;
    }
    
    int i = 0;
    while (BossHp > 0 && hracHp > 0)
    {
        i++;
        if (tah == 0)
        {
            /* code */
        }
        else
        {
            /* code */
        }
    }
    
}


int utok(int sila, int stesti)
{
    int volba;
    // TODO: zjistit data z inventare

    printf("------  --------  ------\n");
    printf("|UTOK|  |MLUVIT|  |ITEM|\n");
    printf("------  --------  ------\n");
    printf(" (1)      (2)       (3) \n");
    
    do
    {
        printf("Zvol jednu možnost pomocí čísel (1-3): ");
        scanf("%d", &volba);
        getchar();
    } while (volba < 1 || volba > 3);
    
    

    if (volba == 1)
    {
        printf("Utok: %d\n", sila * generaceStesti(stesti));
    } else if (volba == 2)
    {
        printf("Mluveni\n");
    } else if (volba == 3)
    {
        printf("Item\n");
    } else
    {
        printf("Nečekaná chyba!\n");
    }
    
    return 0;
}

void text(char zprava[])
{
    printf("%s", zprava);
    sleep(0); // ! Nastavit na 3
}

void next()
{
    int input;

    printf("\n|Pro pokracovani napis jakykoliv znak...");
    scanf("%i", &input);
    getchar();
    system("clear");
}

int potvrzeni(char zprava[])
{
    int input;

    printf("\n%s", zprava);
    do
    {
        printf("\n1) ANO\n2) NE\nTvuj vyber: ");
        scanf("%i", &input);
        getchar();
    } while (input < 1 || input > 2);

    return input;
}

int inventarMenu(int inventar[])
{
    int itemPozice;
    int input;

    for (int i = 0; i < 4; i++)
    {
        printf("Pozice v inventari: %d\n", i+1);
        printf("-----------\n");
        if (inventar[i] == 0)
        {
            printf(" *** \n");
        }
        else if (inventar[i] == 1)
        {
            printf(" mec \n");
        }
        else if (inventar[i] == 2)
        {
            printf(" dopis 1 \n");
        }
        printf("-----------\n\n");
    }
    

    do
    {
        printf("Možnosti:\n1)pouzit item \n2) Odstranit item z inventare\n3) Odejit z inventare\nVase volba: ");

        scanf("%i", &input);
        getchar();
    } while (input < 1 || input > 3);

    if (input == 3)
    {
        return 0;
    }
    else
    {
        do
        {
            printf("Ktery item (1-4): ");

            scanf("%i", &itemPozice);
            getchar();
        } while (itemPozice < 1 || itemPozice > 4);
    }

    if (input == 2)
    {
        printf("Item na pozici %d bude odstranen (nenavratne)!\n", itemPozice); //! pridat system kde se item vyhodi a jde opet vzit
        inventar[itemPozice - 1] = 0;
    }
    else if (input == 1)
    {
        if (inventar[itemPozice - 1] == 0)
        {
            printf("Na teto pozici nic nemas.\n");
        }
        if (inventar[itemPozice - 1] == 1)
        {
            printf("Mec\n");
            return inventar[itemPozice - 1]; // ! vyresit return
        }
        if (inventar[itemPozice - 1] == 2)
        {
            system("cat Dopis/truhla-cave.txt");
        }
    }
    
    
    return 0;   
}

int kamDal(int mozneVolby[])
{
    int input;
    int length = sizeof(mozneVolby) / sizeof(mozneVolby[0]);
    
    for (int i = 0; i < length; i++)
    {
        switch (mozneVolby[i])
        {
            case 1:
                printf("1) Jeskyne\n");
                break;
            case 2:
                printf("2) Lesni cesta\n");
                break;
            case 3:
                printf("3) Jezirko\n");
                break;
            case 4:
                printf("4) Vrchol hory\n");
                break;
            case 5:
                printf("5) Zabi udoli\n");
                break;
            case 6:
                printf("6) Vesnice\n");
                break;
            case 7:
                printf("7) Dul\n");
                break;
            case 8:
                printf("8) Makove pole\n");
                break;
            case 9:
                printf("9) Hlavni rozcesti\n");
                break;
            case 10:
                printf("10) Vez\n");
                break;

            default:
            printf("Necekana chyba!\n");
                break;
        }
    }
    while (1==1)
    {
        printf("Kam ted?");
        printf("\nVyber jednu z lokaci\n");
        scanf("%i", &input);
        getchar();
        for (int i = 0; i < length; i++)
        {
            if (mozneVolby[i] == input)
            {
                return input;
            }
            
        }
    }
}
