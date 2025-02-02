/*================================
Autor: Tomáš Fojtík, I1B
================================*/

// ! Předělat všechna cat a clear na type pro windows
// TODO: pridat barvy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{   
    srand(time(NULL));
    //* Priprava
    int lokace = 1;
    int cas = 10;
    int moznostiCesty[10];
    // HRAC
    int zdravi = 20;
    int silaUtoku = 1;
    int presvedcivost;
    int nenapadnost;
    int stesti = 0;

    int inventar[4];

    int input;
    // Jeskyne
    int truhlaJeskyne[2] = {1, 2};
    int vychodJeskyne = 0;
    // Herni funkce
    int generaceStesti(int stesti);
    int bojboj(char jmeno[22], int BossHp, int BossSila, int hracHp, int sila, int stesti, int utok(int sila, int stesti));
    int utok(int sila, int stesti);
    void text(char zprava[]);
    void next();
    int potvrzeni();
    int kouzlo();
    int inventarMenu(int inventar[]);
    int kamDal(int mozneVolby[]);

    //* Uvod
    system("clear");
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

    text("Vy: Kde to jsem?\n");
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
            printf("\n| V teto jeskyni je jedna truhla\n");
            
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
                        moznostiCesty[0] = 1;
                        moznostiCesty[1] = 2;
                        lokace = kamDal(moznostiCesty);
                        break;
                    }
                    else
                    {
                        text("Vy: To je teda vune lesa! Tu uz jsem dlouho necitil.\n");
                        moznostiCesty[0] = 1;
                        moznostiCesty[1] = 2;
                        lokace = kamDal(moznostiCesty);
                        break;
                    }
                }
            }
            
            break;
        case 2:
            // Pocestný
            system("cat ASCII/Locations/pilgrim.txt");
            system("cat ASCII/Text/pilgrim.txt");
            printf("\n|Kousek dal po ceste sedi pocestny\n");
            text("Vy (v hlave): Ten clovek vypada divne, nevim jestli bych se mu nemel radsi vyhnout...\n");

            if (potvrzeni("Chces si z pocestnym promluvit?") == 1)
            {
                text("Vy: Dobry den pane! Ze je dnes ale pekny den?\n");
                text("Pocestny: Dobry den priteli. Dlouho uz nebyl den dobry... od te doby co carodej seslal kletbu a ovladl kralovstvi, tak to clovek nevi co se mu stane.\n");
                text("Pocestny: Mohu-li poradit, priteli, tak nikomu never! Kazdy je tady proklety, ale ja vim ze nam chces pomoct a zachranis nas! Ty nejsi proklety.\n");
                text("Pocestny: Vypadas ze nas zvladnes doopravdy zachranit. To jsem rad.\n");
                text("Pocestny: Mam pro tebe neco co by se ti pozdeji mohlo hodit. Az budes jednou moc zraneny tak to vypij. Pomuze ti to.\n");
                inventar[2] = 3; // heal potion v invetari
                text("Pocestny: Vsichni na tebe spolehame. Uz jsme te davno potrebovali.\n");
                text("Vy: Diky moc. Zatim se to zda celkem v pohode, ale hadam, ze to se jeste zhorsi co.\n");
                text("Pocestny: A zhorsi se to uz ted. Moc se omlouvam nedokazu to ovladnout!\n");
                text("Pocestny: Carodej me asi ovladne utikej!\n");
                if (potvrzeni("Dat se na utek") == 1)
                {
                    text("Pocestny (carodej): Nikam nepujdes! Stromy uzavrit!\n");
                    printf("|Les se uzavrel dokola kolem vas\n");
                    text("Vy: Co se to prave stalo?\n");
                    text("Pocestny (carodej): To teprve uvidis!\n");
                    // ! boss fight
                }
                else
                {
                    text("Vy: Nenecham ho aby se k tobe dostal!");
                    text("Pocestny: Vybrala opravdoveho hrdinu, ale jak my chces pomoct?\n");
                    text("Vy: Zkusim carodeji zamezit vstup pomoci kouzel. Musi se to podarit.\n");
                    if (kouzlo() == 1) //TODO: sance na uspech
                    {
                        if (generaceStesti(stesti) >= 2)
                        {
                            text("Pocestny: Ty jsi to doopravdy dokazal! Ty si zablokoval carodeje!\n");
                            text("Pocestny: Vila vybrala dobre.\n");
                            text("Vy: Ja to. Ja to dokazal!\n");
                            // TODO: pocestny rekne kde je secret v hore a zkontrolovat zda se dostane na rozcesti
                        }
                        else
                        {
                            text("Pocestny (carodej): Kouzlo ti nevyslo! Jsi moc pomaly. To jsi pekne slaby.\n");
                            text("Pocestny (carodej): Ted se priprav na svuj konec!\n");
                            // ! boss fight
                        }
                    }
                    else
                    {
                        text("Pocestny (carodej): Nekdo si tady nepamatuje kouzla! Jeste ze tak. To jsi pekne slaby.\n");
                        text("Pocestny (carodej): Ted se priprav na svuj konec!\n");
                        // ! boss fight
                    }
                }
            }
            else
            {
                // pokus o vyhnuti
                text("Vy (v hlave): Tak tady se mu trochu vyhnu. Ani si me nevsimne. Tedy snad.\n");

                // sance na to ze zakopne o vetev 
                if (generaceStesti(stesti) >= 5)
                {
                    text("Vy: Tak to se podarilo. Ted se musim nejak dostat dal. No tak zatim jde vse hladce!\n");
                    // TODO: pridat menu moznosti cesty a nejak to ukoncit + upravit
                    if (generaceStesti(stesti) >= 6)
                    {
                        text("Vy: Neco se tam na zemi leskne, ale nevim jestli se mi tam chce jit.\n");
                        if (potvrzeni("Chces se jit podivat na to co se tam leskne?") == 1)
                        {
                            text("Vy: Ale podivejme se! Je to nejaky talisman pro stesti!\n");
                            // TODO: poresit invetar a detekci stesti do funkce pri kazdem loopu asi
                            stesti += 2;
                            inventar[3] = 3;
                            printf("|Talisman pro stesti pridan do inventare\n|+2 stesti\n");
                        }
                        else
                        {
                            text("Vy: To neni dulezite co tam je. Mel bych se pohnout a zbytecne se nezdrzovat. Cesta je jeste daleka.\n");
                        }
                    }
                    
                    // mozna pridat moznost nalezeni itemu
                    moznostiCesty[0] = 1;
                    moznostiCesty[1] = 2;
                    moznostiCesty[2] = 3;
                    lokace = kamDal(moznostiCesty);
                }
                else
                {
                    text("Vy: DOOoprcic!\n");
                    printf("|Zakopl si o vetev a vykrikl si\n|-1 zdravi\n");
                    zdravi--;

                    text("Pocestny: Ale, ale, nestalo se neco panackovi?\n");
                    if (potvrzeni("Chces se priznat ze ses malicko zranil?") == 1)
                    {
                        if (generaceStesti(stesti) < 3)
                        {
                            text("Pocestny: Priteli napij se z me lahvinky, to te postavi na nohy\n");
                            if (potvrzeni("Chces se napit?") == 1)
                            {
                                if (generaceStesti(stesti) == 0)
                                {
                                    text("Vy: Dekuji moc...\n");
                                    printf("|Najednou citis bolest, ktera si brzo pomine, ale ublizila ti\n|-1 zdravi\n");
                                    text("Vy: Fuj, co v tom je?\n");
                                    text("Pocestny: Copak priteli? Nechutna? Je to domaci recept. Dal jsem tam boruvky, nebo vrani oko?\n");
                                }
                                else
                                {
                                    text("Vy: Dekuji moc...\n");
                                    printf("|Najednou citis prijemny pocit v celem tele a bolest je pryc\n|+1 zdravi\n");
                                    text("Vy: Dekuji Vam moc! Hned se citim dobre! Jsem vam moc vdecny.\n");
                                }
                            }
                            else {
                                text("Vy: Ne, dekuji. Nemam zizen a ja to zvladnu.\n");
                                // TODO: Odecist jedna z reputace nebo z komunikacnich skills
                                text("Pocestny: No jak myslis... postarej se o sebe...\n");
                            }
                        }
                        else
                        {
                            text("Pocestny: Priteli to mas blbe, hned bych ti nabidl z moji lahvinky, to by te hned postavilo na nohy. Jenom ze jsem to ted dopil...\n");
                        }
                    }
                    else
                    {
                        text("Pocestny: To jsem rad ze se ti nic nestalo.\n");
                    }
                    text("Pocestny: Priteli? Jak se vlastne jmenujes a proc nas mas zachranit zrovna ty?\n");
                    text("Vy: Nevim proc zrovna ja mam vas zachranit. Ja jsem... kdo jsem? Ja zapomnel! Coze to, co se tady deje?\n");
                    text("Pocestny: Davej si pozor! To je ta magie carodeje i na tebe pusobi! Ale jinak. To je dobre. Ja uz nevim nic a carodej me muze ovladnout...\n");
                    text("Pocestny: Mel by si rychle zmizet. Carodej vi ze tu jsi priteli! Uz si me bere!\n");

                    if (potvrzeni("Vzit nohy na ramena?") == 1)
                    {
                        // boss fight
                        text("Pocestny: Pozde priteli! Uz je tad...\n");
                        text("Pocestny: ...\n");
                        printf("|Stromy se stáhli dokola a zablokovali cestu tam i zpět\n");
                        text("Vy: Co se to stalo!\n");
                        text("Pocestny (carodej): Tohle je zvlastni telo a jeste, tak daleko ode mne. Tady asi moc silu mit nebudu, ale to nevadi.\n");
                        text("Pocestny (carodej): Ale ale, takze tebe ta blba vila vybrala? Na nikoho lepsiho uz nemela silu? Tak tohle bude jeste zabava\n");
                        text("Vy: Tohle se mi nelibi.\n");
                        text("Pocestny (carodej): A to jsem ani nezacal\n");
                        // ! Start boss fight
                    }
                    else
                    {
                        // TODO: sance na boss fight jinak pomuzes zastavit carodeje
                        text("Vy: Nenecham te tady jen tak!\n");
                    }
                    

                    moznostiCesty[0] = 1;
                    moznostiCesty[1] = 2;
                    moznostiCesty[2] = 3;
                    lokace = kamDal(moznostiCesty);
                }
                
            }
            
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

int boj(char jmeno[22], int BossHp, int BossSila, int hracHp, int sila, int stesti, int utok(int sila, int stesti))
{
    char soubor[] = ("Bosss/%s/info.txt", jmeno);
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
            // hrac na tahu
            BossHp -= utok(sila, stesti);
        }
        else
        {
            // pc na tahu
            int bossVolba;
            bossVolba = rand() % 3 + 1;
            if (bossVolba == 1)
            {
                talk("Carodej: Ted te znicim!\n");
                hracHp -= rand() % BossSila + 1;
            }
            else if (bossVolba == 2)
            {
                // TODO: Hadanka
            }
            else if (bossVolba == 3)
            {
                // TODO: vytvorit piskvorky
                talk("Carodej: Tento utok nezvladnes!\n");
                printf("| kdyz porazis carodeje v piskvorkach tak ti neublizi.\n\n");
                
                printf("\t|\t \t|\t");
                printf("");
                printf("\t|\t \t|\t");
                printf("\t|");
                printf("\t|\t \t|\t");
                printf("\t");
            }
        }
    }
    
}

int utok(int sila, int stesti)
{
    int volba, utok;
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
        utok = sila * generaceStesti(stesti);
        printf("Zautocil si! Tvuj utok ma silu: %d.\n", utok);
        return utok;
    } else if (volba == 2)
    {
        // TODO: pridat konverzace pro ruzne Bosse
        printf("Pojdme si o tom promluvit!\n");
        utok = 1;
        return utok;
    } else if (volba == 3)
    {
        // TODO: pridat moznost vyuzit nejaky item
        printf("item\n");
        
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

int kouzlo()
{
    char zprava[] = "";
    printf("Prones kouzlo: ");
    gets(zprava);
    if (zprava == "sagittis")
    {
        return 1; // kouzlo na obraneni vstupu carodeje do cloveka
    }

    return 0;
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
    
    printf("\n|Moznosti presunu:\n");

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
        printf("\nVyber jednu z lokaci:\n");
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
