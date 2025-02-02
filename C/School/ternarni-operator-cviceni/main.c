#include <stdio.h>

int main(int argc, char const *argv[])
{
    char znak;
    int cislo1, cislo2, cislo3;

    printf("Zadej pismeno:\n");
    scanf(" %c", &znak);

    printf("Zadej tri cela cisla:\n");
    scanf("%d%d%d", &cislo1, &cislo2, &cislo3);

    /*Pomocí IF - ELSE*/
    printf("\n**Pomoci IF - Else**\n");

    // 1.)
    if(znak >= 65 && znak <= 90)
    {
        printf("Znak %c je velke pismeno\n", znak);
    } else if (znak >= 97 && znak <= 122)
    {
        printf("Znak %c je male pismeno\n", znak);
    } else
    {
        printf("Znak %c neni pismeno abecedy\n", znak);
    }

    // 2.)
    if (znak == 65 || znak == 69 || znak == 73 || znak == 79 || znak == 85 || znak == 89)
    {
        printf("Znak %c je samohlaska\n", znak);
    } else if (znak == 97 || znak == 101 || znak == 105 || znak == 111 || znak == 117 || znak == 121)
    {
        printf("Znak %c je samohlaska\n", znak);
    } else
    {
        printf("Znak %c je souhlaska\n", znak);
    }
    
    
    // 3.)
    if (cislo1 == cislo2 && cislo2 == cislo3)
    {
        printf("Cisla se rovnaji (%d)\n", cislo1);
    }
    else
    {
        if (cislo1 >= cislo2 && cislo1 >= cislo3)
        {  
            if (cislo1 == cislo2)
            {
                printf("Prvni a druhe cislo (%d) je nejvetsi\n", cislo1);
            }
            else if (cislo1 == cislo3)
            {
                printf("Prvni a treti cislo (%d) je nejvetsi\n", cislo1);
            }
            else
            {
                printf("Prvni cislo (%d) je nejvetsi\n", cislo1);
            }
        }
        else if (cislo2 >= cislo1 && cislo2 >= cislo3)
        {
            if (cislo2 == cislo3)
            {
                printf("Druhe a treti cislo (%d) je nejvetsi\n", cislo2);
            }
            else
            {
                printf("Druhe cislo (%d) je nejvetsi\n", cislo2);
            }
        }
        else if (cislo3 >= cislo1 && cislo3 >= cislo2)
        {
            printf("Treti cislo (%d) je nejvetsi\n", cislo3);
        }
    }
    
    
    /*Pomocí ternarniho operatoru*/
    printf("\n**Pomoci ternarniho operatoru**\n");

    // 1.)
    printf("Znak %c je %s\n", znak, (znak >= 65 && znak <= 90) ? "velke pismeno" : (znak >= 97 && znak <= 122) ? "male pismeno" : "jiny znak");
    // 2.)
    printf("Znak %c je %s\n", znak, (znak == 65 || znak == 69 || znak == 73 || znak == 79 || znak == 85 || znak == 89) ? "samohlaska" : (znak == 97 || znak == 101 || znak == 105 || znak == 111 || znak == 117 || znak == 121) ? "samohlaska" : "souhlaska");
    // 3.)
    printf("Nejvetsi cislo je %s\n", (cislo1 == cislo2 && cislo2 == cislo3) ? "neni, cisla se rovnaji" : (cislo1 >= cislo2 && cislo1 >= cislo3) ? "prvni cislo" : (cislo2 >= cislo1 && cislo2 >= cislo3) ? "druhe cislo" : "treti cislo");
    

    /*Pomocí konstrukce SWITCH*/
    printf("\n**Pomoci konstrukce SWITCH**\n");

    // 1.)
    switch (znak)
    {
    case 65 ... 90:
        printf("Znak %c je velke pismeno\n", znak);
        break;
    case 97 ... 122:
        printf("Znak %c je male pismeno\n", znak);
        break;
    
    default:
        printf("Jiny znak\n");
        break;
    }
    // 2.)
    switch (znak)
    {
    case 65:
        printf("Znak je samohlaska\n");
        break;
    case 69:
        printf("Znak je samohlaska\n");
        break;
    case 73:
        printf("Znak je samohlaska\n");
        break;
    case 79:
        printf("Znak je samohlaska\n");
        break;
    case 85:
        printf("Znak je samohlaska\n");
        break;
    case 89:
        printf("Znak je samohlaska\n");
        break;
    
    case 97:
        printf("Znak je samohlaska\n");
        break;
    case 101:
        printf("Znak je samohlaska\n");
        break;
    case 105:
        printf("Znak je samohlaska\n");
        break;
    case 111:
        printf("Znak je samohlaska\n");
        break;
    case 117:
        printf("Znak je samohlaska\n");
        break;
    case 121:
        printf("Znak je samohlaska\n");
        break;
    
    default:
        printf("Znak je souhlaska\n");
        break;
    }

    return 0;
}