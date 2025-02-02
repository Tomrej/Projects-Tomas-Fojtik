#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int pocetBoxu = 0;
    int nahodneCislo = 0;
    int penize = 500;

    int pocetBeznych = 0;
    int pocetVzacnych = 0;
    int pocetLegendary = 0;
    int pocetEpic = 0;

    int druhyTah = 0;
    int volba = 2;
    int animace = 1;
    int rychlostAnimace = 1;

    srand(time(NULL));

    while (penize > 0 && volba == 2)
    {    
        printf("Kolik boxu chces otevrit?\n");
        scanf("%d", &pocetBoxu);
        if (pocetBoxu * 100 > penize)
        {
            printf("Bohuzel na otevreni %d nemas dost penez.\n", pocetBoxu);
        }
        else
        {
            while (pocetBoxu > 0)
            {
                penize -= 100;
                nahodneCislo = rand() % 100;
                druhyTah = rand() % 3;


                printf("BOX SE OTEVIRA\n");
                sleep(2);
                system("cls");
                
                for (int i = 0; i < 10; i++)
                {
                    animace = rand() % 5;
                    switch (animace)
                    {
                    case 0:
                        system("cls");
                        printf("|PRAZDNY|\n");
                        sleep(rychlostAnimace);                        
                        break;

                    case 1:
                        system("cls");
                        printf("|OBYCEJNY|\n");
                        sleep(rychlostAnimace);
                        break;

                    case 2:
                        system("cls");
                        printf("|VZACNY|\n");
                        sleep(rychlostAnimace);
                        break;
                    case 3:
                        system("cls");
                        printf("|EPICKY|\n");
                        sleep(rychlostAnimace);
                        break;
                    case 4:
                        system("cls");
                        printf("|LEGENDARNI|\n");
                        sleep(rychlostAnimace);
                        break;

                    default:
                        system("cls");
                        printf("|PRAZDNY|\n");
                        sleep(rychlostAnimace);
                        break;
                    }
                }
                system("cls");


                if (nahodneCislo < 30)
                {
                    printf("|Box je prazdny!\n");
                }
                else if (nahodneCislo >= 30 && nahodneCislo < 60)
                {
                    printf("|Ziskal si Common Item.\n");
                    
                    if (druhyTah == 1)
                    {
                        printf("Ziskavas dreveny mec.\n");
                    }
                    else if (druhyTah == 2)
                    {
                        printf("Dostavas kozenou zbroj.\n");
                    }
                    else
                    {
                        printf("Ziskavas obycejny luk.\n");
                    }
                    
                    penize += 25;
                    pocetBeznych++;
                }
                else if (nahodneCislo >= 60 && nahodneCislo < 80)
                {
                    printf("|Ziskal jsi Vzacny Item.\n");

                    if (druhyTah == 1)
                    {
                        printf("Ziskavas kameny mec.\n");
                    }
                    else if (druhyTah == 2)
                    {
                        printf("Dostavas valecnou kamenou sekyru.\n");
                    }
                    else
                    {
                        printf("Ziskavas zlomenou magickou hulku.\n");
                    }
                    penize += 50;
                    pocetVzacnych++;
                }
                else if (nahodneCislo >= 80 && nahodneCislo < 90)
                {
                    printf("|Ziskal jsi Legendary Item.\n");
                    penize += 120;
                    pocetLegendary++;

                    if (druhyTah == 1)
                    {
                        printf("Ziskavas zelezny mec.\n");
                    }
                    else if (druhyTah == 2)
                    {
                        printf("Dostavas zeleznou zbroj.\n");
                    }
                    else
                    {
                        printf("Ziskavas ocarovanou kusi.\n");
                    }
                }
                else
                {
                    printf("|Ziskal jsi Epic Item.\n");
                    penize += 250;
                    pocetEpic++;

                    if (druhyTah == 1)
                    {
                        printf("Ziskavas ocarovany diamantovy mec.\n");
                    }
                    else if (druhyTah == 2)
                    {
                        printf("Dostavas diamantovou ocarovanou zbroj.\n");
                    }
                    else
                    {
                        printf("Ziskavas kouzelnou hulku s brkem fenixe.\n");
                    }
                }

                pocetBoxu--;
                sleep(3);
            }   
        }
        printf("\nPocet beznych predmetu: %d\n", pocetBeznych);
        printf("Pocet vzacnych predmetu: %d\n", pocetVzacnych);
        printf("Pocet legendarnich predmetu: %d\n", pocetLegendary);
        printf("Poccet epickych predmetu: %d\n", pocetEpic);
        printf("Pocet minci: %d.\n", penize);

        do
        {
            printf("Pokud chces skoncit, zadej 1, pokud pokracovat, zadej 2.\n");
            scanf("%d",  &volba);
            getchar();
        } while (volba < 1 || volba > 2); 
    }
    return 0;
}

