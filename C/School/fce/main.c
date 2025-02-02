#include <stdio.h>
#include <time.h>

int nahodnyVyber();
void podstatnaJmena(int vyber);
void pridavnaJmena(int vyber);
void slovesa(int vyber);
void prislovce(int vyber);

void veta(int pocetVet);

int main(void)
{
    srand(time(NULL));

    int pocetVet;
    printf("================================\nVitej v programu na skladani vet\n================================\n");

    printf("Zadej kolik chces pseudo versu:\n");
    scanf("%d", &pocetVet);
    getchar();

    veta(pocetVet);

    return 0;
}

int nahodnyVyber()
{
    return rand() % 12;
}

void veta(int pocetVet)
{
    int typVety;
    for (int i = 0; i < pocetVet; i++)
    {
        printf("MOZNOSTI SKLADANI VETY\n-----------------\n");
        printf("1) pridavne jmeno + podstatne jmeno + sloveso + podstatne jmeno\n");
        printf("2) DOES + podstatne jmeno + sloveso + Pridavne jmeno\n");
        printf("3) podstatne jmeno + IS + sloveso + pridavne jmeno + podstatne jmeno\n\n");
    
        printf("Zadej, ktery typ vety chces:\n");
        do
        {
            scanf("%d", &typVety);
            getchar();
        } while (typVety < 1 || typVety > 3);        

        if (typVety == 1)
        {
            printf("|");
            pridavnaJmena(nahodnyVyber());
            podstatnaJmena(nahodnyVyber());
            slovesa(nahodnyVyber());
            podstatnaJmena(nahodnyVyber());
            printf(".\n\n");
        }
        else if (typVety == 2)
        {
            printf("| Does");
            pridavnaJmena(nahodnyVyber());
            podstatnaJmena(nahodnyVyber());
            slovesa(nahodnyVyber());
            podstatnaJmena(nahodnyVyber());
            printf("?\n\n");
        }
        else
        {
            printf("|");
            podstatnaJmena(nahodnyVyber());
            printf(" is");
            slovesa(nahodnyVyber());
            printf("ing");
            pridavnaJmena(nahodnyVyber());
            podstatnaJmena(nahodnyVyber());
            printf(".\n\n");
        }
        
    }
    
}

void podstatnaJmena(int vyber)
{
    switch (vyber)
    {
    case 0:
        printf(" physics");
        break;
    
    case 1:
        printf(" resource");
        break;
    
    case 2:
        printf(" comparison");
        break;
    
    case 3:
        printf(" awareness");
        break;
    
    case 4:
        printf(" possession");
        break;
    
    case 5:
        printf(" foundation");
        break;
    
    case 6:
        printf(" sister");
        break;
    
    case 7:
        printf(" history");
        break;

    case 8:
        printf(" dinner");
        break;

    case 9:
        printf(" error");
        break;

    case 10:
        printf(" death");
        break;

    case 11:
        printf(" revolution");
        break;

    default:
        break;
    }
}

void pridavnaJmena(int vyber)
{
    switch (vyber)
    {
    case 0:
        printf(" steady");
        break;
    
    case 1:
        printf(" groovy");
        break;
    
    case 2:
        printf(" wistful");
        break;
    
    case 3:
        printf(" mental");
        break;
    
    case 4:
        printf(" stupendous");
        break;
    
    case 5:
        printf(" blue-eyed");
        break;
    
    case 6:
        printf(" dashing");
        break;
    
    case 7:
        printf(" tightfisted");
        break;

    case 8:
        printf(" tidy");
        break;

    case 9:
        printf(" known");
        break;

    case 10:
        printf(" subsequent");
        break;

    case 11:
        printf(" polite");
        break;

    default:
        break;
    }
}

void slovesa(int vyber)
{
    if (0)
    {
        printf(" connect");
    }
    else if (1)
    {
        printf(" gain");
    }
    else if (2)
    {
        printf(" point");
    }
    else if (3)
    {
        printf(" centre");
    }
    else if (4)
    {
        printf(" beg");
    }
    else if (5)
    {
        printf(" copy");
    }
    else if (6)
    {
        printf(" penetrate");
    }
    else if (7)
    {
        printf(" express");
    }
    else if (8)
    {
        printf(" seal");
    }
    else if (9)
    {
        printf(" cancel");
    }
    else if (10)
    {
        printf(" widen");
    }
    else
    {
        printf(" relieve");
    }
    
}

void prislovce(int vyber)
{
    if (0)
    {
        printf(" frantically");
    }
    else if (1)
    {
        printf(" nearly");
    }
    else if (2)
    {
        printf(" perfectly");
    }
    else if (3)
    {
        printf(" lively");
    }
    else if (4)
    {
        printf(" gladly");
    }
    else if (5)
    {
        printf(" heavily");
    }
    else if (6)
    {
        printf(" sadly");
    }
    else if (7)
    {
        printf(" truthfully");
    }
    else if (8)
    {
        printf(" frankly");
    }
    else if (9)
    {
        printf(" speedily");
    }
    else if (10)
    {
        printf(" seemingly");
    }
    else
    {
        printf(" coyly");
    }
}