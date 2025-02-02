#include <stdio.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    printf("Rekni svoji otazku a ja ti opdovim\n");

    printf(".");
    sleep(2);
    printf(".");
    sleep(2);
    printf(".\n");
    sleep(4);

    printf("Moje odpoved je: ");

    int nahodneCislo = rand() % 20 + 1;
    switch (nahodneCislo)
    {
        // Kladne
    case 1:
        printf("Rozhodne\n");
        break;
    case 2:
        printf("Nepochybne\n");
        break;
    case 3:
        printf("Ano, urcite\n");
        break;
    case 4:
        printf("Muzes se na to spolehnout\n");
        break;
    case 5:
        printf("Vidim to jako ano\n");
        break;
    case 6:
        printf("S nejvetsi pravdepodobnosti\n");
        break;
    case 7:
        printf("Výhled je dobrý\n");
        break;
    case 8:
        printf("Ano\n");
        break;
    case 9:
        printf("Znameni smeruji k ano\n");
        break;
    case 10:
        printf("Je to jiste\n");
        break;
        // Neutralni
    case 11:
        printf("Zeptej se znovu\n");
        break;
    case 12:
        printf("Radsi ti to ted nereknu\n");
        break;
    case 13:
        printf("Nyni nemuzu predpovedet\n");
        break;
    case 14:
        printf("Soustred se a zeptej se znovu\n");
        break;
    case 15:
        printf("Odpoved je mlhava, zeptej se znovu\n");
        break;
    case 16:
        printf("Nepocitej s tim\n");
        break;
    case 17:
        printf("Moje odpoved je ne\n");
        break;
    case 18:
        printf("Moje zdroje rikaji ne\n");
        break;
    case 19:
        printf("Vyhled neni moc dobry\n");
        break;
    case 20:
        printf("Velice pochybuji\n");
        break;

    default:
        break;
    }

    return 0;
}
