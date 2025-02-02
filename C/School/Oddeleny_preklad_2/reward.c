#include "common.h"

void reward()
{
    srand(time(NULL));
    switch (rand() % 10)
    {
    case 0:
        printf("Vsichni mi rikaji, ze jmeno kocoura se jako heslo pro roota nehodi. Ale kdyz ja jsem si uz na svyho qzb!7kw_2et tak zvykl!\n");
        break;

    case 1:
        printf("Co to je, kdyz pracovnika prejede parni valec? Totalni zobrazeni z 3D do 2D.\n");
        break;
    
    case 2:
        printf("Mam kvantove auto. Jakmile se podivam na tachometr, tak se ztratim.\n");
        break;
    
    case 3:
        printf("Nekdy si pripadam jako multicastovy paket. Zeptam se deseti lidi na cestu a dostanu deset ruznych odpovedi.\n");
        break;
    
    case 4:
        printf("Programator: Doktor mi rikal, ze mam po ty dlouhy zime oslabenej organismus. Tak jsem se ptal v lekarne a nabidli mi beta karoten. Na to jim kaslu. Pockam, az bude plna verze.\n");
        break;
    
    case 5:
        printf("Lide se deli do 10 skupin. Jedni dvojkovou soustavu znaji a druzi ne.\n");
        break;
    
    case 6:
        printf("Programovani je jako sex - jedna chyba a musis to podporovat do konce zivota.\n");
        break;
    
    case 7:
        printf("Na UDP vtipech je nejlepsi, ze se nestarate, jestli lidem dosly nebo ne.\n");
        break;
    
    case 8:
        printf("Programator pracujici v patem patre jezdi vytahem zasadne do ctvrteho.\n");
        break;
    
    case 9:
        printf("Tady mam pro tebe vtipne video: https://social.mtdv.me/blog/posts/funny-images\n");
        break;
    
    default:
        break;
    }
}