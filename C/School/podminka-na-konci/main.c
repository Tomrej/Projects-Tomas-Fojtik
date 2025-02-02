/*================================
Autor: Tomáš Fojtík, I1B
================================*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 1, y = 1;
    int pokracovat = 1;

    while (pokracovat == 1)
    {
        printf("Zadej delenec (cele cislo):\n");
        scanf("%d", &x);
        getchar();

        do
        {
            printf("Zadejte delitel (nesmi se rovnat nule):\n");
            scanf("%d", &y);
            getchar();
        } while (y == 0);

        printf("Vysledek: %f\n", x/(float)y);

        do
        {
            printf("Zadej 1, pokud chces delit dalsi cislo. Pro ukonceni zadej 0:\n");
            scanf("%d", &pokracovat);
            getchar();
        } while (pokracovat < 0 || pokracovat > 1);
    }
    
    return 0;
}
