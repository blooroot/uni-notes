package notes.cicloV.DataStructures.week2.classExercises.LinkedList;

import java.util.LinkedList;

public class Exercise4LinkedList {
    
    public static void main(String[] args) {
        // Creación de la LinkedList lista        
        LinkedList<Integer> lista = new LinkedList<>();
        lista.add(10);
        lista.add(20);
        lista.add(-34);
        lista.add(1);
        lista.add(16);
        printLista(lista, "\n[1] Lista original: ");
        lista.remove(2); // Método remove (elimina elemento de indice 2)
        lista.add(3, 100); // Método add con index y elemento
        printLista(lista, "\n[2] Lista modificada");
        lista.sort(null);
        printLista(lista, "\n[3] Lista ordenada: ");
    }

    public static void printLista(LinkedList<Integer> lista, String header) {
        System.out.println(header);
        for (int i = 0; i < lista.size(); i++) {
            System.out.print(lista.get(i) + " ");
        }
        System.out.println();
    }

}
