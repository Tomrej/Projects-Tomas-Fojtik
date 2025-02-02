#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    // Autor Tomáš Fojtík
    // verze: 1.0

    /*
    License:
    */

    // uvod
    printf("Vitej v tomto uzasnem programu!\n\nAutor: Tomas Fojtik");
    sleep(2);
    system("cls");

    // vtip
    printf("Manzelka: \"Az budu jednou stara a oskliva, budes me mit stale rad?\"\n");
    sleep(2);
    printf("Manzel: \"Ja te mam rad.\"");
    sleep(2);

    // barvy
    system("color 1f");
    sleep(1);
    system("color 2e");
    sleep(1);
    system("color 3d");
    sleep(1);
    system("color 4c");
    sleep(1);
    system("color 07");
    system("cls");

    // obrazky
    system("type guitar.txt");
    system("type guitar2.txt");
    system("type drums.txt");
    system("type keyboard.txt");
    sleep(3);
    system("cls");

    // rozlouceni
    printf("Dekuji za vase strpeni a preji hezky den!\n");
    Beep(750, 800);
    Sleep(1);
    Beep(750, 800);

    return 0;
}
