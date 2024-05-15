package notes.cicloV.DataStructures.week2.classExercises.Postre;

import java.util.LinkedList;

public class Postre {

    private String nombre;
    private LinkedList<String> ingredientes;
    // Método constructor
    public Postre(String nombre) {
        this.nombre = nombre;
        this.ingredientes = new LinkedList<>();
    }
    // Getter auxiliares
    public String getNombre() {
        return nombre;
    }
    public LinkedList<String> getIngredientes() {
        return ingredientes;
    }
    // Método para agregar ingrediente a la linkedlist ingredientes
    public void agregarIngrediente(String ingrediente) {
        ingredientes.add(ingrediente);
    }
    // Método para eliminar ingrediente de la linkedlist ingredientes
    public void eliminarIngrediente(String ingrediente) {
        ingredientes.remove(ingrediente);
    }
    // Método para imprimir los ingredientes del postre
    public void imprimirIngredientes(){
        for (String ingrediente : ingredientes) {
            System.out.print(ingrediente + " ");
        }
    }

}