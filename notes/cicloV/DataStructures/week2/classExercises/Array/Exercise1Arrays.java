package notes.cicloV.DataStructures.week2.classExercises.Array;

import java.util.Arrays;
import javax.swing.JOptionPane;

public class Exercise1Arrays {
    
    public static void main(String[] args) {
        // Declaramos nuestros arreglos
        int[] numeros = new int[5];
        String[] palabras = new String[5];
        int[] aleatorio = new int[numeros.length];
        // Rellenado por input del arreglo numeros
        for (int i = 0; i < 5; i++) {
            numeros[i] = Integer.parseInt(JOptionPane.showInputDialog("\nIngrese el elemento del índice " + i));
        }
        // Impresión del arreglo números
        System.out.println("\n[1] Los datos sin ordenar:");
        System.out.print("[ ");
        for (int i = 0; i < 5; i++) {
            System.out.print(numeros[i] + ", ");
        }
        System.out.print("]");
        // Los datos ordenados son:
        System.out.println("\n\n[2] Los datos ordenados son:");
        Arrays.sort(numeros); // Método sort
        System.out.print("[ ");
        for (int i = 0; i < 5; i++) {
            System.out.print(numeros[i] + ", ");
        }
        System.out.print("]");
        // Rellenando el arreglo palabras
        Arrays.fill(palabras, "Bienvenido a la clase"); // Método fill
        System.out.println("\n\n[3] Elementos del arreglo de palabras");
        for (int i = 0; i < palabras.length; i++) {
            System.out.println(palabras[i]);
        }
        // Copiando los elementos del arreglo número a aleatorio
        System.out.println("\n[4] Copia del arreglo numeros en arreglo aleatorio");        
        aleatorio = Arrays.copyOf(numeros, 5); // Método copyOf
        System.out.print("[ ");
        for (int i = 0; i < 5; i++) {
            System.out.print(aleatorio[i] + ", ");
        }
        System.out.println("]\n");
    }

}
