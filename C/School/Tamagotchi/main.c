#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void pokracovat();
void uvod();
void stav(int hodnota);
void konec();

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int hlad = 20, hygiena = 20, nuda = 20, zdravi = 20;
    int nahoda;
    int spanek;
    char znak;

    uvod();

    while (hlad > 0 && hygiena > 0 && nuda > 0 && zdravi > 0)
    {
        if (hlad > 20)
        {
            hlad = 20;
        }
        if (hygiena > 20)
        {
            hygiena = 20;
        }
        if (nuda > 20)
        {
            nuda = 20;
        }
        if (zdravi > 20)
        {
            zdravi = 20;
        }
        
        system("cls");
        system("type dog.txt");

        nahoda = rand() % 7;

        switch (nahoda)
        {
        case 1:
            hlad--;
            break;
        
        case 2:
            hygiena--;
            break;
        
        case 3:
            nuda--;
            break;

        case 4:
            zdravi--;
            break;

        case 5:
            spanek = rand() % 6 + 3;
            if (spanek == 5)
            {
                break;
            }
            system("cls");
            system("type dog_sleeping.txt");
            printf("\t\t\tTvuj pes usnul na %d vterin.\n", spanek);
            sleep(spanek);
        
        default:
            break;
        }

        printf("Jidlo: \t\t");
        stav(hlad);
        printf("Hygiena: \t");
        stav(hygiena);
        printf("Zabava: \t");
        stav(nuda);
        printf("Zdravi: \t");
        stav(zdravi);

        
        if (kbhit())
        {
            znak = getch();
            if (znak == 'q')
            {
                printf("Konec\n");
                exit(0);
            }
            else if (znak == '1')
            {
                printf("Probiha krmeni\n");
                hlad++;
            }
            else if (znak == '2')
            {
                printf("Probiha cisteni\n");
                hygiena++;
            }
            else if (znak == '3')
            {
                printf("Hrajes si s mazlickem\n");
                nuda++;
            }
            else if (znak == '4')
            {
                printf("Probiha leceni\n");
                zdravi++;
            }
        }
        sleep(1);
    }

    konec();
    
    return 0;
}

void pokracovat()
{
    printf("\t\t\tStistkni jakoukoliv klavesu pro pokracovani...\n");
    getch();
}

void uvod()
{
    system("cls");
    printf("\t\t\tDosel ti tvuj mazlicek!\n");
    system("type box.txt");
    pokracovat();
    system("cls");
    printf("\n\t\t\tJe to pes!\n");
    system("type dog.txt");
    pokracovat();
    system("cls");
    printf("\t\t\tOvladani:\n\tStiskni 1) Pro krmeni\n\tStiskni 2) Pro cisteni\n\tStiskni 3) Pro zabaveni mazlicka\n\tStiskni 4) Pro leceni\n");
    pokracovat();
}

void stav(int hodnota)
{
    for (int i = 0; i < hodnota; i++)
    {
        printf(" []");
    }
    printf("\n");
}

void konec()
{
    system("cls");
    printf("\n\t\t\tTvuj mazlicek zemrel\n");
    system("type rip.txt");
    pokracovat();
}
