#include <stdio.h>
#include <math.h>

int den_narozeni(int den_v_mesici, int mesic, int stoleti, int rok);

int main(int argc, char const *argv[])
{
    int a = 10, b = 20, c = 30;
    
    // 2) soucet vsech
    int soucet = a + b + c;
    printf("2) soucet: %d\n", soucet);

    // 3) soucet a+b*c*5
    printf("3) soucet a + b * 5 * c: %d\n", ((a+b)*5*c));

    // 4)
    printf("4) diskriminant: %d\n", b * b - 4 * a * c);

    // 5)
    float prumer = (a + b + c) / (float) 3;
    printf("5)prumer: %f\n", prumer);

    // 6)
    a = b = c = 10;

    // 7)
    // postfixove
    b++;
    c--;
    printf("7) (postfixove) A=%d , B=%d , C=%d\n", a, b, c);
    // prefixove
    printf("(prefixove) A=%d , B=%d , C=%d\n", a, ++b, --c);

    // 8)
    a = a * 73;
    printf("8) a%%c: %d\n", a % c);

    // 9)
    printf("9) a pred odcitani: %d, ", a);
    a -= 12;
    printf("a po odecteni: %d\n", a);    

    // 10)
    printf("10) b pred nasobenim: %d, ", b);
    b *= -3;
    printf("b po nasobeni: %d\n", b); 

    // 11)
    int ROK = 2007;
    printf("11) treti cifra roku narozeni: %d\n", ROK/10%10);

    // 12)
    int konec_hodiny = 12 * 60 + 20;
    int zbytek_dne = 24*60 - konec_hodiny;
    printf("12) Po hodine nam bude zbyvat %d minut\n", zbytek_dne);

    // 13)
    printf("13) V hodinach to znamena: %d hodin a %d minut\n", zbytek_dne / 60, zbytek_dne % 60);

    // 14)
    int muj_den_narozeni = den_narozeni(14, 7, 21, 7);
    printf("14) Vypocet vzorce dne meho narozeni: %d\n", muj_den_narozeni);

    // 15) POZOR NEFUNGUJE
    int den_narozeni_herce = den_narozeni(4, 4, 20, 65);
    printf("15) Robert Downey Jr. se narodil %d. den v tydnu\n", den_narozeni_herce);

    // 16)
    float hmotnost = 67;
    float vyska = 1.83;
    printf("16) BMI: %f\n", hmotnost / (vyska * vyska));

    // 17)
    // podle zadani
    char T = 'T', O = 'O', M = 'M', A = 'A', S = 'S';
    printf("17) %c%c%c%c%c\n", T, O, M, A, S);

    /*
    elegantnejsi reseni (nemuselo by to byt vubec vypano pomoci [], stacilo by printf("%s", jmeno);)

    char jmeno[] = "TOMAS";
    printf("%c%c%c%c%c\n", jmeno[0], jmeno[1], jmeno[2], jmeno[3], jmeno[4]);
    */
    
    // 18)
    printf("18) %d %d %d %d %d\n", T, O, M, A, S);

    // 19)
    printf("19) %c%c%c%c%c\n", T + 32, O + 32, M + 32, A + 32, S + 32);

    // 20)
    float znamky[] = {1, 3, 2};
    float prumerZnamek;
    int pocetZnamek = sizeof(znamky) / sizeof(znamky[0]);

    for (int i = 0; i < pocetZnamek; i++)
    {
        prumerZnamek += znamky[i];
    }

    prumerZnamek /= pocetZnamek;
    printf("20) Prumer znamek: %f\n", prumerZnamek);
    printf("Prumer znamek (zaokrouhleno): %f\n", round(prumerZnamek));
    printf("Prumer znamek (zaokrouhleno nahoru): %f\n", ceil(prumerZnamek));
    printf("Prumer znamek (zaokrouhleno dolu): %f\n", floor(prumerZnamek));

    return 0;
}

int den_narozeni(int den_v_mesici, int mesic, int stoleti, int rok)
{
    return (den_v_mesici + (13 * (mesic + 1)) / 5 + rok + rok / 4 + stoleti / 4 - 2 * stoleti) % 7 + 1;
}