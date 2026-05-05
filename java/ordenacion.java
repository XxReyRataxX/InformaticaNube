import java.util.Arrays;
import java.util.Random;

public class ordenacion {
    
    // Insertion Sort - O(n²)
    public static void insertionSort(int[] arr) {
        int n = arr.length;
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
    
    // Generar array de datos aleatorios (simula medidor de consumo eléctrico)
    public static int[] generarDatos(int n) {
        int[] datos = new int[n];
        Random random = new Random();
        for (int i = 0; i < n; i++) {
            datos[i] = random.nextInt(10000); // Valores de consumo entre 0-10000 W
        }
        return datos;
    }
    
    // Verificar si el array está ordenado
    public static boolean estaOrdenado(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
    
    public static void main(String[] args) {
        int n = 100000; // 100k elementos
        
        System.out.println("=== ORDENACIÓN N² - GASTO ELÉCTRICO ===");
        System.out.println("Número de elementos: " + n);
        System.out.println();
        
        // Generar datos de consumo eléctrico
        int[] datos = generarDatos(n);
        int[] datosIS = datos.clone();
        
        // INSERTION SORT
        System.out.println("INSERTION SORT:");
        long inicio = System.currentTimeMillis();
        insertionSort(datosIS);
        long fin = System.currentTimeMillis();
        System.out.println("   Tiempo: " + (fin - inicio) + " ms");
        System.out.println("   Ordenado correctamente: " + estaOrdenado(datosIS));
        System.out.println("   Primeros 10: " + Arrays.toString(Arrays.copyOf(datosIS, 10)));
        System.out.println();
        
        System.out.println("=== ORDENACIÓN COMPLETADA ===");
    }
}
