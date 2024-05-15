package notes.cicloV.DataStructures.week2.classExercises.ArrayList;

import java.util.ArrayList;

public class Exercise3ArrayList {

    public static void main(String[] args) {
        // Crea un objeto ArrayList de objetos String con una capacidad inicial de 10
        ArrayList<String> items = new ArrayList<>(10);
        items.add("red"); // Método add
        items.add(0, "yellow"); // Método add
        // Muestra los colores de la lista con for y contador
        System.out.println("\n[1] Muestra contenido de la lista con ciclo for y contador: ");
        for (int i = 0; i < items.size(); i++) {
            System.out.print(items.get(i) + " ");
        }
        System.out.println();
        // Muestra los colores con el metodo display
        display(items, "\n[2] Muestra contenido de la lista con for mejorado: ");
        items.add("green");
        items.add("yellow");
        display(items, "\n[3] Lista con dos nuevos elementos: ");
        items.remove("yellow"); // Método remove (elimina el primer yellow en la lista)
        display(items, "\n[4] Eliminar primera instancia de yellow: ");
        items.remove(1); // Método remove (elimine elemento de indice 1)
        display(items, "\n[5] Eliminar segundo elemento de la lista (green): ");
        System.out.printf("\n[6] ¿'red' está en la lista? %s", items.contains("red") ? "sí" : "no");
        System.out.println("\n\n[7] Número de elementos en la lista: " + items.size() + "\n");
    }

    public static void display(ArrayList<String> items, String header) {
        System.out.println(header);
        for (int i = 0; i < items.size(); i++) {
            System.out.print(items.get(i) + " ");
        }
        System.out.println();
    }

}
