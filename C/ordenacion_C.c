#include <stdio.h>
void ordenar(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}
int main() {
    int size=1000; 
    int *array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand();
    }
    ordenar(array, size);
    free(array);
    return 0;
}