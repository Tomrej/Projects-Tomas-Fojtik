#include <stdio.h>
#include <stdlib.h>

#include "jedna.h"
#include "dva.h"
#include "treti.h"
#include "ctvrty.h"

void menu();
void obvod_obsah();
void nacti_cislo(int *a);

int main()
{
    int x = 0, y = 0, a = 0, b = 0, c = 0;

    printf("======================================\n");
    printf("\tKALKULACKA & PREVODNIK\n");
    printf("======================================\n\n\n");

    // hlavni menu
    int vyber = 1;
    while (vyber != 0)
    {
        menu();
        printf("\nTvuj vyber:\n");
        scanf("%d", &vyber);
        system("cls");

        if (vyber != 0 && vyber != 7)
        {
            printf("Zadej cislo:\n");
            scanf("%d", &x);
            getchar();
        }

        switch (vyber)
        {
        case 0:
            printf("Konec programu\n");
            exit(0);

        case 1:
            nacti_cislo(&y);
            printf("Soucet: %d\n", soucet(x,y));
            break;

        case 2:
            nacti_cislo(&y);
            printf("Rozdil: %d\n", odecitani(x, y));
            break;

        case 3:
            nacti_cislo(&y);
            printf("Soucin: %d\n", nasobeni(x, y));
            break;

        case 4:
            nacti_cislo(&y);
            if (y == 0)
            {
                printf("Nulou nelze delit!\n");
                exit(5);
            }
            printf("Deleni: %d\n", deleni(x, y));
            break;

        case 5:
            printf("Treti mocnina: %d\n", tretimocnina(x));
            break;

        case 6:
            nacti_cislo(&y);
            printf("Zbytek po deleni: %d\n", celociselnedeleni(x, y));
            break;

        case 7:
            obvod_obsah();
            break;

        case 8:
            printf(prvocislo(x) == 0 ? "Tvoje cislo je prvocislo\n" : "Tvoje cislo neni prvocislo\n");
            break;

        case 9:
            printf("y = ax + bx + c\n");
            printf("zadej a\n");
            nacti_cislo(&a);
            printf("\nzadej b\n");
            nacti_cislo(&b);
            printf("\nzadej c\n");
            nacti_cislo(&c);
            kvadraticka_rovnice(a, b, c, x);
            break;

        case 10:
            nacti_cislo(&y);
            printf("Nejvetsi spolecny delitel: %d\n", nejvetsi_spolecny_delitel(x, y));
            break;

        case 11:
            prevod_decimetry(x);
            break;

        case 12:
            prevod_litry(x);
            break;

        case 13:
            prevod_hodiny(x);
            break;
        
        case 14:
            printf("Zadej stranu b\n");
            nacti_cislo(&y);
            printf("Zadej stranu c\n");
            nacti_cislo(&a);
            sestrojittrojuhelnik(x, y, a);

        default:
            break;
        }
        printf("Stistkni jakoukoliv klavesu pro pokracovani\n");
        getchar();
    }
}

void menu()
{
    printf("VYBER FUNKCI:\n");
    printf("-------------\n");
    printf("(0): Konec programu\n");
    printf("(1): Scitani dvou cisel\n");
    printf("(2): Odecitani dvou cisel\n");
    printf("(3): Nasobeni dvou cisel\n");
    printf("(4): Deleni dvou cisel\n");
    printf("(5): Vypocet treti mocniny\n");
    printf("(6): Vypocet zbytku po celociselnem deleni\n");
    printf("(7): Obvod a obsah\n");
    printf("(8): Prvocislo\n");
    printf("(9): Kvadraticka rovnice\n");
    printf("(10): Nejvetsi spolecny delitel\n");
    printf("(11): Prevody z decimetru\n");
    printf("(12): Prevody z litru\n");
    printf("(13): Prevody z hodin\n");
    printf("(14): Lze trojuhelnik sestrojit\n");
}

void nacti_cislo(int *a)
{
    printf("Zadej dalsi cislo:\n");
    scanf("%d", a);
    getchar();

}

void obvod_obsah()
{
    int volba = 0;
    int x, y, z, n;
    system("cls");
    printf("Menu - obvod obsah:\n----------\n");
    printf("(1) Obvod ctverce\n");
    printf("(2) Obsah ctverce\n");
    printf("(3) Obvod obdelniku\n");
    printf("(4) Obsah obdelniku\n");
    printf("(5) Obvod trojuhelniku\n");
    printf("(6) Obsah trojuhelniku\n");
    printf("(7) Obvod kruhu\n");
    printf("(8) Obsah kruhu\n");
    printf("(9) Obvod lichobezniku\n");
    printf("(10) Obsah lichobezniku\n");

    scanf("%i", &volba);
    getchar();

    switch (volba)
    {
    case 1:
        printf("Obvod ctverce je %d\n", obvodctverec(x));
        break;
    
    case 2:
        printf("Obsah ctverce je %d\n", obsahctverec(x));
        break;
    
    case 3:
        nacti_cislo(&z);
        printf("Obvod obdelniku je %d\n", obvodobdelnik(x, y));
        break;
    
    case 4:
        nacti_cislo(&z);
        printf("Obsah obdelniku je %d\n", obsahobdelnik(x, y));
        break;
    
    case 5:
        printf("Zadej y\n");
        nacti_cislo(&z);
        printf("Zadej z\n");
        nacti_cislo(&z);
        printf("Obvod trojuhelniku je %d\n", obvodtrojuhelnik(x, y, z));
        break;
    
    case 6:
        printf("Zadej vysku\n");
        nacti_cislo(&z);
        printf("Obsah trojuhelniku je %d\n", obsahtrojuhelnik(x, y));
        break;
    
    case 7:
        printf("Obvod kruhu je %d\n", obvodkruh(x));
        break;
    
    case 8:
        printf("Obsah kruhu je %d\n", obsahkruh(x));
        break;
    
    case 9:
        printf("Zadej y\n");
        nacti_cislo(&z);
        printf("Zadej z\n");
        nacti_cislo(&z);
        printf("Zadej n\n");
        nacti_cislo(&n);
        printf("Obvod lichobezniku je %d\n", obvodlichobeznik(x, y, z, n));
        break;
    
    case 10:
        nacti_cislo(&z);
        printf("Zadej vysku\n");
        nacti_cislo(&z);
        printf("Obsah lichobezniku je %d\n", obsahlichobeznik(x, y, z));
        break;
    
    default:
        break;
    }
}