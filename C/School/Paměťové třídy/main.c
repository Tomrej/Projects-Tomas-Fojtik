#include <stdio.h>
#include "second.h"

extern int cislo = 1;
static int dalsiCislo = 3;

int main(int argc, char const *argv[])
{
    // vypis();
    printf("Vypis static promene v prvnim zdrojaku: %d\n", dalsiCislo);
    
    for (auto int i = 0; i < 10000; i++)
    {
        
    }
    
    
    /*for (register int i = 0; i < 10000; i++)
    {
        
    }*/

    for (int i = 0; i < 20; i++)
    {
        funkce();
    }
    

    return 0;
}
