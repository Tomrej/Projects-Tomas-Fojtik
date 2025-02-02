#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test.c"

void pokracovat();
int vyber();
void menu();

void uvod();
int kouzelna_brana();
int les_rozcestniku();

void ozivit_zvire();

int main(void)
{
    srand(time(NULL));
    uvod();
    return 0;
}

void pokracovat()
{
    printf("\n\nStistkni jakoukoliv klavesu pro pokracovani...\n\n");
    getch();
}

int vyber(int rozsah)
{
    int volba = 0;
    do
    {
        scanf("%i", &volba);
    } while (volba < 1 || volba > rozsah);
    return volba;
}

void menu()
{
    printf("JAKY UKOL CHCES SPLINT?\n");
    printf("1) Kouzelna brana\n");
    printf("2) Les rozcestniku\n");
    printf("3) Jeskyne nekonecna\n");
    printf("4) Hluboky les\n");
    printf("5) Strazce dveri\n");
    printf("6) Magicke kruhy\n");
    printf("7) Duch starovekeho kodera\n");
    printf("8) Labyrint rekursivni magie\n");
    printf("9) |Konec hry|\n");

    printf("Tvuj vyber:\n");

    int volba = vyber(9);

    switch (volba)
    {
    case 1:
        printf("%d\n", kouzelna_brana());
        break;

    case 2:
        printf("%d\n", les_rozcestniku());

        break;
    
    case 3:
        printf("%d\n", jeskyne_nekonecna());

        break;

    case 4:
        break;
    
    case 5:
        hluboky_les();
        break;

    case 6:
        magicke_kruhy();
        break;
    
    case 7:
        duch_starovekeho_kodera();
        break;

    case 8:
        /* code */
        break;

    case 9:
        exit(0);
        break;
    
    default:
        break;
    }
}

void uvod()
{
    system("cls");
    printf("\n\t\t\tZAHADY STAROVEKEHO KODEXU\n");
    pokracovat();
    printf("Pribeh hry:\n");
    //printf("Hraci jsou cleny skupiny mladych magu na akademii car a kouzel, ktera se specializuje na starodavne magicke technologie. Objevi se tejemny kodex plny zahadnych algoritmickych kouzel, ktery pochazi z doby starovekych programatoru (stale uci na Prestizi xd). Aby se mohli stat mistri kodovani, musi hraci rozlustit a aplikovat magicke algoritmy z tohoto kodexu.\n");
    pokracovat();
    system("cls");
    menu();
}

int kouzelna_brana()
{
    int pocasi = rand() % 2;
    system("cls");

    printf("pocasi: %d", pocasi);

    printf("Pred branou stoji straze, ktery te necha projit pouze pokud se dostatecne rychle rozhodnes. Pokud je slunecno, pouzij na strazce vodu, kdyz prsi ohen.\n");
    printf("\n\t| Aktualne %s\n", pocasi == 0 ? "prsi" : "je slunecno");
    printf("Pro ohen napis 1, Pro vodu 2:\n");
    int volba = vyber(2);
    printf("%s\n", volba == (pocasi + 1) ? "Spravna volba! pokracujes dal." : "Spatne! Muzes to zkusit znovu.");
    return volba == (pocasi + 1) ? 0 : 1;
}

int les_rozcestniku()
{
    printf("V lese se nachazi rozcestnik s mnoha cestami. Musis najit cestu dal.");
}

int jeskyne_nekonecna()
{
    printf("V jeskyni plne pokladu musis najit vychod ven.\n");
    int spravny_vychod = rand() % 10 + 1;
    int volba;
    do
    {
        printf("Vychod si zatim nenasel. Jake vychod si vyberes (1-10):\n");
        volba = vyber(10);
    } while (spravny_vychod != volba);
    
    printf("Konecne ses dostal ven! Gratluju!");
    return 0;
}

int strazce_dveri()
{
    printf("Zepta se te na par otazek.\nPokud odpovis na vse spravne dostanes se dal.\n");

    printf("Kolik je 2 + 2?\n1) 2\n2) 3\n3) 4\n 4) 1");
    if (vyber(4) == 3)
    {
        printf("To neni spravne, 2 + 2 se nerovna 3 :(\nZkus to znovu priste");
        return 1;
    }
    else
    {
        printf("Tak si to dokazal.\n");
        return 0;
    }

}

int hluboky_les()
{
    printf("Budes muset odhadnout kolik kroku potrebujes aby ses dostal ke studance.\nKolik kroku chces provest? (1-10)\n");
    int kroky = vyber(20);
    for (int i = 0; i < kroky; i++)
    {
        printf("*");
    }
    if (kroky == 11)
    {
        printf("STUDANKA MLADI\n");
        printf("Dokazal si to! Pokracujes dal!\n");
        return 0;
    }
    else
    {
        printf("MIMO STUDANKU\n");
        printf("Nedal si to! Muzes to zkusit potom znovu\n");
        return 1;
    }
}

int magicke_kruhy()
{
    
    printf("Pozor tady by si mel preletet pres nebezpeci! Pokud jsem spravne caroval, tak se vsemu nebezpecnemu vyhnes!");

    int i = 0;
    while (1)
    {
        sleep(2);
        i++;
        printf("%d\n", i);

        if (i == 2)
        {
            continue;
            printf("Nebezepcne monstrum te dostalo!\n");
            break;
        }

        if (i == 3)
        {
            printf("Zatim je vse dobre!\n");
        }

        if (i == 2)
        {
            continue;
            printf("Nebezepcne monstrum te dostalo!\n");
            break;
        }

        if (i == 2)
        {
            continue;
            printf("Nebezepcny upir te dostal!\n");
            break;
        }

        if (i = 10)
        {
            printf("Zvladli jsme to!\n");
            return 0;
        }
        
        
    }
    printf("Nepodarilo se to! Jsi mrtvy!\n");
    return 1;
}

int duch_starovekeho_kodera()
{
    printf("Setkavas se s duchem starovekeho kodera. Ten chce at ozivis jeho zvire.\n");
    printf("Chces pouzit kouzlo na oziveni?\n");
    if (vyber(2) == 1)
    {
        printf("Super!");
        ozivit_zvire();
        printf("Duch ti podekoval a muzes jit dal.\n");
        return 0;
    }
    else
    {
        printf("Tak to si pokazil! Odchazis s neuspechem! Muzes to pak zkusit znovu.\n");
        return 1;
    }
    
}

void ozivit_zvire()
{
    printf("zvire_mrtve = true;\n");
    printf("Provedu svoji magii\n");
    printf("zvire_mrtve = false\n");
    printf("Nemusis dekovat\n");
}

int labyrint_rekursivni_magie()
{

}