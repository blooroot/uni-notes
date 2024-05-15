package Pregunta3;

import java.util.PriorityQueue;

public class HeapSort {
    
    public static void heapSort(int[] array) {
        // Creamos la cola prioritaria heap para almacenar los elementos del array
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        // Agregamos todos los elementos del array al heap
        for (int num : array) {
            heap.add(num);
        }
        // Extraemos los elementos del heap y los colocamos de nuevo en el array usando .poll()
        for (int i = 0; i < array.length; i++) {
            array[i] = heap.poll();
        }
    }

    public static void main(String[] args) {
        int[] array = {12, 9, -2, 5, 6, 7};
        System.out.println("\n[PREGUNTA 3] : HeapSort con colas prioritarias");
        System.out.print("\n[1] Array original:");
        imprimirArray(array);
        heapSort(array);
        System.out.print("[2] Array ordenado:");
        imprimirArray(array);
        System.out.println("\n");
    }

    // Método auxiliar para imprimir un array
    public static void imprimirArray(int[] array) {
        for (int num : array) {
            System.out.print(" " + num + " ");
        }
        System.out.println();
    }
}

