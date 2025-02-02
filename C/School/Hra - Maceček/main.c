#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int WIDTH = 5;
const int HEIGHT = 10;

int assignCage();

void gamePreparation(int (*gameField)[WIDTH]);
void printGameField(int (*gameField)[WIDTH]);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int gameField[HEIGHT][WIDTH];
    gamePreparation(gameField);
    printGameField(gameField);

    return 0;
}

void gamePreparation(int (*gameField)[WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (i >= 2 && i <= 9 && j == 0)
            {
                gameField[i][j] = assignCage();
            }
            else if ((i == 0 || i == 1) && j == 1)
            {
                gameField[i][j] = assignCage();
            }
            else if (i >= 3 && i <= 9 && j == 2)
            {
                gameField[i][j] = assignCage();
            }
            else if ((i == 1 || i == 2) && j == 4)
            {
                gameField[i][j] = assignCage();
            }
            else
            {
                gameField[i][j] = 0;
            }            
        }        
    }
    // posledni satna
    gameField[1][4] = assignCage();

    // VCHOD
    gameField[0][5] = 52;
    // VSTUP DO ŠKOLY
    gameField[10][1] = 53;    
}

void printGameField(int (*gameField)[WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%d\t", gameField[i][j]);
        }
        printf("\n");
    }
    
}

int assignCage()
{
    static int cage[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int cageNum;

    while (1)
    {
        cageNum = rand() % 20 + 1;
        for (int i = 0; i < 20; i++)
        {
            if (cage[i] == cageNum)
            {
                cage[i] = 0;
                return cageNum;
            }        
        }
    }
    return 255;   
}