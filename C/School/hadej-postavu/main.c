/*================================
Autor: Tomáš Fojtík, I1B
================================*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int o1, o2, o3, o4, o5;

    printf("================================\nZkusim uhadnout na jakého Marvel Cinematic Universe hrdinu prave myslis\n================================\n");
        // KLADAS
    o1 = scanBool("Byl v puvodni sestici?");
    if (o1 == 0)
    {
        // Je z puvodni sestice
        o2 = scanBool("Ma superschopnosti? (supersila, buh atd.)");
        if (o2 == 0)
        {
            o3 = scanBool("Umi letat?");
            if (o3 == 0)
            {
                printf("Tvoje postava je Thor!");
            } else
            {
                o4 = scanBool("Dokaze se zmenit kdyz je nastvany?");
                if (o4 == 0)
                {
                    printf("Tvoje postava je Bruce Banner neboli Hulk!");
                } else
                {
                    printf("Tvoje postava je Kapitán Amerika neboli Steve Rogers");
                }
                
                
            }
        } else
        {
            o3 = scanBool("Ma postava roboticke brneni/oblek?");
            if (o3 == 0)
            {
                printf("Tvoje postava je Tony Stark neboli Iron man!");
            } else
            {
                o4 = scanBool("Ma tvoje postava luk?");
                if (o4 == 0)
                {
                    printf("Tvoje postava je Hawkeye neboli Clint Barton");
                } else
                {
                    printf("Tvoje postava je Black Widow, neboli Natasha Romanoff");
                } 
            }
        } 
    } else
    {
        // Neni z puvodni sestice
        o1 = scanBool("Je z planety zeme a nepatříš ke strážcům galaxie?");
        if (o1 == 0)
        {
            o2 = scanBool("Mas superschopnosti?");
            if (o2 == 0)
            {
                o3 = scanBool("Mas schopnosti podle nejakeho zivocicha?");
                if (o3 == 0)
                {
                    o4 = scanBool("Je zvire podle ktere je tva postava savec?");
                    if (o4 == 0)
                    {
                        printf("Jsi T'Challa neboli Black Panther");
                    }
                    else
                    {
                        o5 = scanBool("Je tvoje postava teenager?");
                        if (o5 == 0)
                        {
                            printf("Jsi Spiderman");
                        }
                        else
                        {
                            printf("Jsi Ant-man");
                        }
                    }
                }
                else
                {
                    o4 = scanBool("Umis čarovat?");
                    if (o4 == 0)
                    {
                        o5 = scanBool("Byvala tvoje postava doktor?");
                        if (o5 == 0)
                        {
                            printf("Jsi Doctor Strange");
                        }
                        else
                        {
                            printf("Jsi Scarlet witch");
                        }
                        
                    }
                    else
                    {
                        printf("Jsi Captain Marvel?");
                    }
                    
                }   
            }
            else
            {
                o3 = scanBool("Ma tvoje postava brneni od Tonnyho Starka?");
                if (o3 == 0)
                {
                    printf("Jsi War Machine");
                }
                else
                {
                    o4 = scanBool("Ma tvoje postava neco spolecneho s kapitanem Amerikou?");
                    if (o4 == 0)
                    {
                        o5 = scanBool("Ma tvoje postava kridla?");
                        if (o5 == 0)
                        {
                            printf("Jsi Falcon");
                        }
                        else
                        {
                            printf("Jsi Bucky Barnes tedy Winter Soldier");
                        }
                        
                    }
                    else
                    {
                        printf("Tady mi uz dosly napady na postavy, takze tohle muzes brat jako takovy EASTER EGG :)");
                    }
                    
                }
            }
            
        } else
        {
            o2 = scanBool("Patri ke Strazcum galaxie?");
            if (o2 == 0)
            {
                o3 = scanBool("Je to zvire nebo rostlina?");
                if (o3 == 0)
                {
                    o4 = scanBool("Je tvoje postava rostlina?");
                    if (o4 == 0)
                    {
                        printf("Tvoje postava je Groot!");
                    } else
                    {
                        printf("Tvoje postava je Rocket Raccoon!");
                    }
                    
                } else
                {
                    o4 = scanBool("Jsi z planety zeme?");
                    if (o4 == 0)
                    {
                        printf("Jsi Star-lord!");
                    } else
                    {
                        o5 = scanBool("Je tvoje postava zelená?");
                        if (o5 == 0)
                        {
                            printf("Jsi Gamora!");
                        }
                        else
                        {
                            printf("Jsi Drax!");
                        }
                        
                    }
                    
                }
                
            } else
            {
                printf("Jsi Captain Marvel!");
            }    
        }
        
    }    

    return 0;
}

int scanBool(char text[])
{
    int scan;
    // mohlo by se tady pridat neco jako "catch error" pro scanf (pokud vstup je jiny nez int)
    do
    {
        printf("%s\n", text);
        printf("\t0 = ano\n\t1 = ne\n");
        scanf("%d", &scan);
    } while (scan != 0 && scan != 1);

    return scan;
}