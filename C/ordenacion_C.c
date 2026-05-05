#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Insertion Sort - O(n^2)
void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int *generarDatos(int n) {
    int *datos = (int *)malloc(n * sizeof(int));
    if (!datos) {
        fprintf(stderr, "Error: malloc failed\n");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        datos[i] = rand() % 10000; // valores 0-9999 para igualar Java
    }
    return datos;
}

bool estaOrdenado(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

int main(void) {
    int size = 2000000; // coincide con `ordenacion.java`

    printf("=== ORDENACIÓN N² - GASTO ELÉCTRICO ===\n");
    printf("Número de elementos: %d\n\n", size);

    srand((unsigned)time(NULL));

    int *datos = generarDatos(size);
    if (!datos) return 1;
    int *datosIS = (int *)malloc(size * sizeof(int));
    if (!datosIS) {
        free(datos);
        fprintf(stderr, "Error: malloc failed\n");
        return 1;
    }
    for (int i = 0; i < size; i++) datosIS[i] = datos[i];

    printf("INSERTION SORT:\n");
    clock_t inicio = clock();
    insertionSort(datosIS, size);
    clock_t fin = clock();
    double ms = (double)(fin - inicio) / CLOCKS_PER_SEC * 1000.0;
    printf("   Tiempo: %.0f ms\n", ms);
    printf("   Ordenado correctamente: %s\n", estaOrdenado(datosIS, size) ? "true" : "false");
    printf("   Primeros 10: ");
    for (int i = 0; i < 10 && i < size; i++) {
        if (i) printf(", ");
        printf("%d", datosIS[i]);
    }
    printf("\n\n");

    free(datos);
    free(datosIS);
    printf("=== ORDENACIÓN COMPLETADA ===\n");
    return 0;
}