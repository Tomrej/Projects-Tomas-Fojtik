#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char znak;

    printf("|Desifrovani zpravy|\nDesifrovana zprava je bez mezer a specialni znaky nebyli sifrovane!\nZadej sifru: ");

    while (1)
    {
        scanf(" %c", &znak);

        switch (znak)
        {
            case 'n':
                printf("a");
                break;

            case 'm':
                printf("b");
                break;
            
            case 'h':
                printf("c");
                break;
            
            case 'e':
                printf("d");
                break;

            case 't':
                printf("e");
                break;
            
            case 'u':
                printf("f");
                break;
            
            case 'b':
                printf("g");
                break;

            case 'k':
                printf("h");
                break;
            
            case 'o':
                printf("i");
                break;

            case 'y':
                printf("j");
                break;

            case 'i':
                printf("k");
                break;
            
            case 'j':
                printf("l");
                break;

            case 'g':
                printf("m");
                break;

            case 's':
                printf("n");
                break;
            
            case 'c':
                printf("o");
                break;

            case 'x':
                printf("p");
                break;

            case 'a':
                printf("q");
                break;
            
            case 'q':
                printf("r");
                break;

            case 'r':
                printf("s");
                break;

            case 'w':
                printf("t");
                break;
            
            case 'z':
                printf("u");
                break;

            case 'p':
                printf("v");
                break;

            case 'v':
                printf("w");
                break;

            case 'l':
                printf("x");
                break;
            
            case 'f':
                printf("y");
                break;

            case 'd':
                printf("z");
                break;
            
            default:
                printf("%c", znak);
                break;
            }
    }
    
    return 0;
}
