/*=================
Tomáš Fojtík, I1B
=================*/
#include <stdio.h>
#include <time.h>

void otazka(int cislo);
int vyhodnoceni(int cislo, int odpoved);

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int odpoved;
    int moznost = 0;
    int pocetBodu = 0;
    int vyberOtazka;

    printf("\n\t||Vitejte v kvizu ohledne Tolkiena a jeho sveta!||\n\t-Otazky se mohou opakovat\n\n");

    while (moznost != 1)
    {
        vyberOtazka = rand() % 10 + 1;
        otazka(vyberOtazka);

        do
        {
            printf("\nTvoje odpoved (1-4):\n");
            scanf("%d", &odpoved);
            getchar();
        } while (odpoved > 4 || odpoved < 1);
        
        pocetBodu += vyhodnoceni(vyberOtazka, odpoved);

        printf("\n\t||Pokud chces ukoncit hru zadej 1, pokud chces pokracovat tak cokoliv jineho:\n");
        scanf("%d", &moznost);
        getchar();
    }
    
    printf("Tvuj pocet bodu je: %d\n", pocetBodu);    

    return 0;
}

void otazka(int cislo)
{
    switch (cislo)
    {
    case 1:
        printf("Tolkien obdrzel:\n");
        printf("\t1) Od Alzbety II. Rad britskeho imperia\n");
        printf("\t2) Nobelovu cenu za literaturu\n");
        printf("\t3) Americke oceneni nejlepsiho spisovatele fantasy\n");
        printf("\t4) Cenu nejlepsiho cloveka roku 1972\n");

        break;

    case 2:
        printf("Narodil se:\n");
        printf("\t1) v Prusku\n");
        printf("\t2) ve Spojenem kralovstvi\n");
        printf("\t3) v Oranzskem svobodnem statu\n");
        printf("\t4) v Americe\n");
        break;

    case 3:
        printf("Tolkien byl:\n");
        printf("\t1) krestan (katolik)\n");
        printf("\t2) muslim\n");
        printf("\t3) zid\n");
        printf("\t4) krestant (anglikan)\n");
        break;

    case 4:
        printf("Pan prstenu dostal oceneni:\n");
        printf("\t1) ze nejlepsi fantasy knihu vubec\n");
        printf("\t2) za nejvyznamnejsi kniha tisicileti\n");
        printf("\t3) nedostala oceneni\n");
        printf("\t4) za nejoblibenejsi sci-fi knihu\n");
        break;
    
    case 5:
        printf("Tolkienuv citat neni:\n");
        printf("\t1) Ne vsichni, kteri bloudi jsou ztraceni.\n");
        printf("\t2) Mnozi z tech, co ziji, by zasluhovali smrt. A mnozi z tech, co zemreli, by si zaslouzili zit.\n");
        printf("\t3) Smrt je jen dalsi cesta, kterou musime jit.\n");
        printf("\t4) Velka laska se rodi z maleho poznani.\n");
        break;
    
    case 6:
        printf("Kolik bylo barev carodeju:\n");
        printf("\t1) 3\n");
        printf("\t2) 2\n");
        printf("\t3) 4\n");
        printf("\t4) 6\n");
        break;

    case 7:
        printf("Kam odchaz elfove kdyz zemrou?\n");
        printf("\t1) Zeme neumirajicich\n");
        printf("\t2) Numenor\n");
        printf("\t3) Cuivienen\n");
        printf("\t4) Sine Mandosu\n");
        break;

    case 8:
        printf("Kolik umelych jazyku vytvoril?\n");
        printf("\t1) 8\n");
        printf("\t2) 13\n");
        printf("\t3) 15\n");
        printf("\t4) 10\n");
        break;

    case 9:
        printf("Co v elfstine znamena Arda?\n");
        printf("\t1) Matka\n");
        printf("\t2) Zeme\n");
        printf("\t3) Planeta\n");
        printf("\t4) Stred\n");
        break;
    
    case 10:
        printf("Jak se jmenovala zeme bohu:\n");
        printf("\t1) Lothlorien\n");
        printf("\t2) Valinor\n");
        printf("\t3) Arda\n");
        printf("\t4) Numenor\n");

    default:
        break;
    }
}

int vyhodnoceni(int cislo, int odpoved)
{
    switch (cislo)
    {
    case 1:
        if (odpoved == 1)
        {
            printf("Spravne!\n");
            return 1;
        }
        else
        {
            printf("Spatne! Spravne byla moznost 1\n");
        }
        
        break;

    case 2:
        if (odpoved == 3)
        {
            printf("Spravne!\n");
            return 1;
        }
        else
        {
            printf("Spatne! Spravne byla moznost 3\n");
            return 0;
        }

        break;

    case 3:
        if (odpoved == 1)
        {
            printf("Spravne!\n");
            return 1;
        }
        else
        {
            printf("Spatne! Spravne byla moznost 1\n");
            return 0;
        }

        break;

    case 4:
        if (odpoved == 2)
        {
            printf("Spravne!\n");
            return 1;
        }
        else
        {
            printf("Spatne! Spravne byla moznost 2\n");
            return 0;
        }

        break;
    
    case 5:
        if (odpoved == 4)
        {
            printf("Spravne!\n");
            return 1;
        }
        else
        {
            printf("Spatne! Spravne byla moznost 4\n");
            return 0;
        }

        break;
    
    case 6:
        if (odpoved == 3)
        {
            printf("Spravne!\n");
            return 1;
        }
        else
        {
            printf("Spatne! Spravne byla moznost 3\n");
            return 0;
        }

        break;

    case 7:
        if (odpoved == 4)
        {
            printf("Spravne!\n");
            return 1;
        }
        else
        {
            printf("Spatne! Spravne byla moznost 4\n");
            return 0;
        }

        break;

    case 8:
        if (odpoved == 3)
        {
            printf("Spravne!\n");
            return 1;
        }
        else
        {
            printf("Spatne! Spravne byla moznost 3\n");
            return 0;
        }

        break;

    case 9:
        if (odpoved == 2)
        {
            printf("Spravne!\n");
            return 1;
        }
        else
        {
            printf("Spatne! Spravne byla moznost 2\n");
            return 0;
        }

        break;
    
    case 10:
        if (odpoved == 2)
        {
            printf("Spravne!\n");
            return 1;
        }
        else
        {
            printf("Spatne! Spravne byla moznost 2\n");
            return 0;
        }
    
    default:
        break;
    }
}