/*================================
Autor: Tomáš Fojtík, I1B
================================*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int trasa = 20;
    int pozice = 0;
    int pocetTahu = 0;
    void wait();
    int jizdaAutem();
    int pohyb(int pozice);
    int vyhra(int pozice, int pocetTahu);

    system("cls");

    printf("\t\t| VITEJ V SIMULATORU OPILCE NA CESTE DOMU |\n\n");
    printf("|Program se brzy spusti\n");
    wait();

    system("cls");

    pozice = jizdaAutem();
    vykresleniPlochy(pozice);

    while (vyhra(pozice, pocetTahu) != 1)
    {
        printf("\n\t| Pro dalsi krok stiskni enter...\n");
        getchar();
        system("cls");
        pozice += pohyb(pozice);
        vykresleniPlochy(pozice);
        pocetTahu++;
    }

    printf("\t|Trvalo to jenom %d tahu\n", pocetTahu);
    return 0;
}

void wait()
{
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
}

int pohyb(int pozice)
{
    int pravdepodobnost = 0;
    int p = 0;

    if (pozice == 0)
    {
        p = 0;
    }
    else
    {
        p = rand() % 8;
    }
    
    switch (p)
    {
    case 0 ... 3:
        printf("\n\tUdelal si krok v pred.\n");
        return 1;
    
    case 4 ... 5:
        printf("\n\tUdelal si krok zpatky.\n");
        return -1;

    case 6:
        printf("\n\tZakopl si, zustavas kde jsi.\n");
        return 0;

    case 7:
        printf("\nZastavil te kamarad, ktery jde prave do hospody. (mas 20%% ze te presvedci jit s nim a vrati te o 5 poli)");
        pravdepodobnost = rand() % 5;
        printf("\n\t| Pro pokracovani stiskni enter...\n");
        getchar();
        if (pravdepodobnost == 1)
        {
            printf("Vracis se zpet o pet poli. Tvuj kamarad te presvedcil.\n");
            if (pozice < 5)
            {
		return -pozice;
            }
            else
            {
		return -5;
            }
        }
        else
        {
            printf("Jsi tak nality, ze ani nevis co po tobe chtel a pokracujes o pole v pred.\n");
            return 1;
        }
    
    default:
        break;
    }
}

int vyhra(int pozice, int pocetTahu)
{
    if (pocetTahu == 0)
    {
        return 0;
    }
    
    if (pozice == 0)
    {
        printf("\n\n\tOpilec skoncil opet v hospode!\n");
        return 1;
    }
    else if (pozice == 20) {
        printf("\n\n\tOpilec dosel domu!\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

void vykresleniPlochy(int pozice)
{
    system("type house.txt");
    for (int i = 0; i <= 20; i++)
    {
        if (pozice == i)
        {
            printf(" [*]");
        }
        else
        {
            printf(" [ ]");
        }
        
    }
}

int jizdaAutem()
{
    int pravdepodobnost = rand() % 5;
    int pozice = 0;

    printf("\t|Kamardi jsou tady autem. Mozna ti nabidnou ze te hodi kousek bliz\n\n");

    if (pravdepodobnost == 0)
    {
        printf("Cau, ja se moc omlouvam, ale nemame v aute misto, musis jit dneska domu po svych.\n");
        return 0; 
    }
    else
    {
        printf("Cau kamo! My te kousek hodime. Jak daleko chces hodit?\n");
        
        do
        {
            printf("Napis na jake pole se chces nechat dovezt (1-10)\n");
            printf("(Zvol 0 pokud nechces s nima jet):\n");
            scanf("%d", &pozice);
            getchar();
            if (pozice > 10)
            {
                printf("To uz je moc daleko od nasi cesty, promin. Musime te vyhodit nekde driv.\n");
            }
            if (pozice == 0)
            {
                printf("Kdyz nechces, tak nevadi. Tak stastnou cestu, my jedem.\n");
            	return 0;
	    }
        } while (pozice < 0 || pozice > 10);

        printf("Jsem trochu nality, ale to zvladneme.\n");
        wait();

        pravdepodobnost = rand() % 5;

        if (pravdepodobnost == 0)
        {
            printf("Doprcic to se nemelo stat!\n");
            system("type car.txt");
            printf("\n\t| Vybourali jste a vsichni jste zemreli\n");
            exit(0);
        }
        else
        {
            printf("Cesta pro tebe dopadla uspesne!\n");
        }
        

        return pozice - 1;
    }
}
