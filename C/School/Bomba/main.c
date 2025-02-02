#include <stdio.h>
#include <stdlib.h>

// deklarace
void odpocetDoVybuchu(int sec);

int main(int argc, char const *argv[])
{
    int pocetVterin = 20;
    //odpocetDoVybuchu(pocetVterin);

    while (!kbhit())
    {
        if (pocetVterin > 0)
        {
            sleep(1);
            printf("Zbyva %d vterin do vybuchu!\n", pocetVterin);
            printf("Pro deaktivaci stistkni libovolnou klavesu\n");
            pocetVterin--;
        }
        else
        {
            printf("BUM");
            return 0;

        }
        
    }
    printf("Gratuluji, podarilo se ti deaktivovat bombu %d vterin pred vybucem!\n", pocetVterin);

    return 0;
}

// definice
void odpocetDoVybuchu(int sec)
{
    if (sec > 0) 
    {
        sleep(1);
        printf("Do vybuchu zbyva %d vterin.\n", sec);
        odpocetDoVybuchu(sec-1);
    }
    else
    {
        for (int i = 0; i < 40; i++)
        {
            system("color 60");
            system("color 40");
        }
        
        printf("Bum!");
        //system("shutdown /r");
    }
    
}