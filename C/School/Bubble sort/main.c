/*
Tomáš Fojtík I2B,
Datum poslední změny: 19.1.2025

Poznámky: Chtělo by to ještě přidat časovač, který by měřil za jakou dobu algoritmus seřadí pole
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VELIKOST 12

void printArray(int pole[], int length);
void copyArray(int original[], int new[], int length);
// bubble sort a bogo sort jsem delal kompletne z hlavy, takze moje implementace nemusi byt nejlepsi
void bubbleSort(int pole[], int length);
void bogoSort(int pole[], int length);
// merge sort jsem nakonec nedodelal sam a vyuzil jsem verzi z internetu
void merge(int arr[], int l, int m, int r, int* counter);
void mergeSort(int arr[], int l, int r, int* counter);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int pole[VELIKOST];
    for (int i = 0; i < VELIKOST; i++)
    {
        pole[i] = rand() % 12;
    }
    
    int kopiePole[VELIKOST];
    int length = sizeof(pole) / sizeof(pole[0]);

    // bubble sort
    printf("Bubble sort:\n============\n");
    copyArray(pole, kopiePole, length);
    printArray(kopiePole, length);
    bubbleSort(kopiePole, length);
    printArray(kopiePole, length);

    // merge sort
    printf("\nMerge sort:\n===========\n");
    copyArray(pole, kopiePole, length);
    printArray(kopiePole, length);
    int mergeCounter = 0;
    mergeSort(kopiePole, 0, length - 1, &mergeCounter);
    printArray(kopiePole, length);
    printf("Pocet opakovani: %d\n", mergeCounter);

    // bogo sort
    printf("\nBogo sort:\n==========\n");
    copyArray(pole, kopiePole, length);
    printArray(kopiePole, length);
    bogoSort(kopiePole, length);
    printArray(kopiePole, length);

    return 0;
}

void printArray(int pole[], int length)
{
    printf("Pole: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d", pole[i]);
        if (i != length - 1)
        {
            printf(", ");
        }        
    }
    printf("\n");
}

void copyArray(int original[], int new[], int length)
{
    for (int i = 0; i < length; i++)
    {
        new[i] = original[i];
    }
}

void bubbleSort(int pole[], int length)
{
    int sorted = 1; // 0 => sorted
    int pocetOpakovani = 0;
    int cache = 0;

    while (sorted != 0)
    {
        pocetOpakovani++;
        sorted = 0;
        for (int i = 0; i < length - 1; i++)
        {
            if (pole[i] > pole[i + 1])
            {
                sorted = 1;

                cache = pole[i];
                pole[i] = pole[i + 1];
                pole[i + 1] = cache;
            }
        }
    }

    printf("Pocet opakovani: %d\n", pocetOpakovani);
}

void merge(int arr[], int l, int m, int r, int* counter)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    (*counter)++;
}

// l is for left index and r is right index of the sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r, int* counter)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m, counter);
        mergeSort(arr, m + 1, r, counter);

        merge(arr, l, m, r, counter);
    }
}

void bogoSort(int pole[], int length)
{
    int pocetOpakovani = 0;
    int sorted = 1; // 0 => sorted
    int cache = 0;
    int randomIndex = 0;

    while (sorted != 0)
    {
        sorted = 0;
        pocetOpakovani++;

        // check if sorted
        for (int i = 0; i < length - 1; i++)
        {
            if (pole[i] > pole[i + 1])
            {
                sorted = 1;
            }
        }
        
        // shuffle
        if (sorted != 0)
        {
            for (int i = 0; i < length; i++)
            {
                randomIndex = rand() % length;
                cache = pole[i];
                pole[i] = pole[randomIndex];
                pole[randomIndex] = cache;
            }
        }
    }
    printf("Pocet opakovani: %d\n", pocetOpakovani);
}
