#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int CountFrequency(int arr[], int size);

int main(void) {
    int size;
    srand(time(0));
    scanf("%d", &size);
    int array1[size];
    for (int i = 0; i < size; i++) {
        array1[i] = rand() % 11;
    }
    CountFrequency(array1, size);
    return 0;
}

int CountFrequency(int arr[], int size) {
    int count[11] = {0}; 
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    for (int i = 0; i <= 10; i++) {
        if (count[i] > 0)
            printf("%d occurs %d times\n", i, count[i]);
    }
    return 0;
}








