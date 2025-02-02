#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // autorem programu je Tomáš Fojtík

    /*
    Tohle je vice radkovy komentar, muzu tady treba hodit nejaky pracovni kod
    */

    char name[] = "";
    printf("Tvoje jmeno: ");

    scanf("%10s", name);

    printf("vyckej prosim pet vterin\n");
    // tady si chvíli počkáme. Počet vteřin v programu
    sleep(5);

    printf("Ahoj osobo s jmenem %s\n===============================\n", name);

    // barvy pozadí terminálu
    system("cls");
    system("color 0a");
    sleep(1);
    system("color 2c");
    sleep(1);
    system("color 1d");
    sleep(1);
    system("color 3b");

    // mel by se nacist obrazek ze souboru
    system("type guitar");

    // poskytnuti navratove hodnoty, 0=uspesny preklad
    return 0;
}
