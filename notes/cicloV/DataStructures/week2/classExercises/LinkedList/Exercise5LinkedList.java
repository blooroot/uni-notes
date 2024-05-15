package notes.cicloV.DataStructures.week2.classExercises.LinkedList;

import java.util.LinkedList;

public class Exercise5LinkedList {
    
    public static void main(String[] args) {
        LinkedList<String> personas = new LinkedList<>();
        personas.add("Pepe");
        personas.add("Sandra");
        personas.add("Ana");
        personas.add("Laura");
        System.out.println("\n[1] Tamaño de la lista: " + personas.size() + "\n");
        System.out.println("\n[2] Lista personas: ");
        for (int i = 0; i < personas.size(); i++) {
            System.out.print(personas.get(i) + " ");
        }
        System.out.println("\n");
    }

}
