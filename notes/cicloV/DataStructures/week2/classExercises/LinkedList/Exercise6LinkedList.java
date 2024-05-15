package notes.cicloV.DataStructures.week2.classExercises.LinkedList;

import java.util.LinkedList;

public class Exercise6LinkedList {
    
    public static void main(String[] args) {
        
        LinkedList<String> lista = new LinkedList<>();
        lista.add("Palabra1");
        lista.add("Palabra2");
        lista.add("Palabra3");
        lista.add("Palabra4");
        lista.removeLast();
        System.out.println("\n[1] El tamaño de la lista es: " + lista.size());
        System.out.println("\n[2] Lista:");
        for (int i = 0; i < lista.size(); i++) {
            System.out.print(lista.get(i) + " ");
        }
        System.out.println("\n");
    }

}
