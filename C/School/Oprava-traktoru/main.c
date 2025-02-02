/*=================
Tomáš Fojtík, I1B
=================*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu();
int opravitTraktor(int rok);
void kricetTraktor(int nadavky, float db);
void kricetNaManzelku();
int kricetPes();
int reklamovatTraktor(int rokVyroby, int rokAktualni);

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int body = 0;
    int pocetPokusu = 0;
    int volba;

    printf("Baca dostal k Vanocum novy cerveny trakturek. Cerveny trakturek se diky kvalitni praci pri jeho vyrobe do dvou mesicu rozbil.\n");

    while (body >= 0 && body <= 10 && pocetPokusu < 5)
    {
        int rok_vyroby;
        int pocetNadavek;
        float decibel;
        int rok_aktualni;
        
        menu();
        do
        {
            scanf("%d", &volba);
        } while (volba < 1 || volba > 5);

        printf("Stav bodu je: %d\n", body);
        printf("Zbyva ti jeste: %d pokusu\n", 5 - pocetPokusu);

        switch (volba)
        {
        case 1:
            printf("Zadej rok vyroby:\n");
            scanf("%d", &rok_vyroby);

            body += opravitTraktor(rok_vyroby);
            break;

        case 2:
            printf("Zadej pocet nadavek, ktere chces zakricet na traktor:\n");
            scanf("%d", &pocetNadavek);
            getchar();
            
            printf("Zadej kolik decibelu tvuj krik presahl.\n");
            scanf("%f", &decibel);
            getchar();

            kricetTraktor(pocetNadavek, decibel);
            break;

        case 3:
            kricetManzelka();
            break;
        
        case 4:
            body += kricetPes();
            break;

        case 5:
            printf("Zadej rok vyroby:\n");
            scanf("%d", &rok_vyroby);
            getchar();

            printf("Zadej aktualni rok:\n");
            scanf("%d", &rok_aktualni);
            getchar();

            body += reklamovatTraktor(rok_vyroby, rok_aktualni);
            break;

        default:
            break;
        }
        pocetPokusu++;
    }

    if (body > 10)
    {
        printf("======================\nVYHRAL SI\n======================\n");
    }
    else
    {
        printf("======================\n\tPROHRAL SI\n======================\n");
    }
    

    return 0;
}

void menu()
{
    printf("======================\n\tMENU:\n======================\nZadej:\n");

    printf("\t\t1) Pro opravit traktor\n");
    printf("\t\t2) Pro kricet na traktor\n");
    printf("\t\t3) Pro kricet na manzelku\n");
    printf("\t\t4) Pro kricet na nemeckeho ovcaka\n");
    printf("\t\t5) Pro reklamovat traktor\n");
}

int opravitTraktor(int rok)
{
    int nahodnaMoznost = rand() % 100;

    if (rok < 1914)
    {
        printf("Tak tohle je pekne stare! No tak to nemas sanci opravit.\n[dostavas -69 bodu]\n");
        return -69;
    }
    else if (rok >= 1914 && rok <= 1918)
    {
        printf("No tak tohle je pekne stare.\n");
        if (nahodnaMoznost == 0 || nahodnaMoznost == 1)
        {
            printf("Tak tomu se snad neda verit. Ty si doopravdy dobry v teto praci.\n[dostavas 10 bodu]\n");
            return 10;
        }
        else
        {
            printf("Jak jinak. Tohle se nepodarilo.\n[dostavas 0 bodu]\n");
            return 0;
        }
    }
    else
    {
        printf("Jeste ze je tak novy.\n[dostavas 1 bod]\n");
        return 1;
    }
    
}

void kricetTraktor(int nadavky, float db)
{
    if (nadavky <= 0)
    {
        printf("Haha, to si delas srandu?\n[dostavas 0 bodu]\n");
    }
    else if (db < 100)
    {
        printf("Wow, tak to jsem překvapen. Tady jsem čekal, že dostaneš bod.\n[dostavas bodu]\n");
    }
    else
    {
        printf("Ted se mi to realne nelibi to co delas! Mam strach!\n[dostavas 0 bodu]\n");
    }
}

void kricetManzelka()
{
    printf("Tohle byla velka chyba. Na manzelku se nekrici! Ted neni rozbity jen traktor, ale i baca. Manzelka ho zbila.\n[Prohral si]\n");
    exit(0);
}

int kricetPes()
{
    int nahodnaMoznost = rand() % 4;

    switch (nahodnaMoznost)
    {
    case 0:
        printf("Pes pomohl traktor opravit.\n[dostavas 3 body]\n");
        return 3;

    case 1:
        printf("Pes ukousnul traktoru pneumatiku.\n[dostavas -1 bod]\n");
        return -1;

    case 2:
        printf("Pes snědl bačovi všechy ovce.\n[dostavas 0 bodu]\n");
        return 0;
    
    case 3:
        printf("Bača snědl psa. Mnam.\n[dostavas 1 bod]\n");
        return 1;
    
    default:
        break;
    }
}

int reklamovatTraktor(int rokVyroby, int rokAktualni)
{
    if (rokAktualni - rokVyroby <= 2)
    {
        printf("Reklamace proběhla úspěšně.\n");
        return 3;
    }
    else if (rokAktualni - rokVyroby > 2)
    {
        printf("Reklamace se nepodařila, traktor již není v záruce.\n");
        return -3;
    }
}