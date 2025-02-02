#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char znak;

    printf("|Sifrovani zpravy|\nSifrovana zprava je bez mezer a specialni znaky se nesifruji!\nZadej svoji vetu: ");

    while (1)
    {
        scanf(" %c", &znak);
        if (znak >= 65 && znak <= 90)
        {
            znak += 32;
        }
        

        switch (znak)
        {
            case 'a':
                printf("n");
                break;

            case 'b':
                printf("m");
                break;
            
            case 'c':
                printf("h");
                break;
            
            case 'd':
                printf("e");
                break;

            case 'e':
                printf("t");
                break;
            
            case 'f':
                printf("u");
                break;
            
            case 'g':
                printf("b");
                break;

            case 'h':
                printf("k");
                break;
            
            case 'i':
                printf("o");
                break;

            case 'j':
                printf("y");
                break;

            case 'k':
                printf("i");
                break;
            
            case 'l':
                printf("j");
                break;

            case 'm':
                printf("g");
                break;

            case 'n':
                printf("s");
                break;
            
            case 'o':
                printf("c");
                break;

            case 'p':
                printf("x");
                break;

            case 'q':
                printf("a");
                break;
            
            case 'r':
                printf("q");
                break;

            case 's':
                printf("r");
                break;

            case 't':
                printf("w");
                break;
            
            case 'u':
                printf("z");
                break;

            case 'v':
                printf("p");
                break;

            case 'w':
                printf("v");
                break;

            case 'x':
                printf("l");
                break;
            
            case 'y':
                printf("f");
                break;

            case 'z':
                printf("d");
                break;
            
            default:
                printf("%c", znak);
                break;
            }
    }
    
    return 0;
}
