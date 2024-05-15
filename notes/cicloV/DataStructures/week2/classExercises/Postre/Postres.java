package notes.cicloV.DataStructures.week2.classExercises.Postre;

import java.util.ArrayList;

public class Postres {
    
    private ArrayList<Postre> postres;

    // Método constructor
    public Postres(){
        this.postres = new ArrayList<>();
    }
    // Método para agregar un nuevo postre y su lista de ingredientes
    public void agregarPostre(Postre nuevoPostre) {
        postres.add(nuevoPostre);
        postres.sort((p1, p2) -> p1.getNombre().compareTo(p2.getNombre()));
    }
    // Método para eliminar un postre y su lista de ingredientes
    public void eliminarPostre(String nombrePostre) {
        postres.removeIf((postre) -> postre.getNombre().equals(nombrePostre));
    }
    // Método para buscar un postre por nombre
    public Postre buscarPostre(String nombrePostre) {
        for (Postre postre : postres) {
            if (postre.getNombre().equals(nombrePostre)) {
                return postre;
            }
        }
        return null;
    }
    // Método para buscar un postre y eliminar uno de sus ingredientes
    public void eliminarIngrediente(String postreNombre, String ingrediente) {
        Postre postreEncontrado = buscarPostre(postreNombre);
        if ( postreEncontrado != null ) {
            postreEncontrado.eliminarIngrediente(ingrediente);
        } else {
            System.out.println("El postre " + postreNombre + " no se encuentra en la lista");
        }
    }
    // Método para buscar un postre e imprimir su lista de ingredientes
    public void imprimirIngredientesPostre(String postreNombre) {
        Postre postreEncontrado = buscarPostre(postreNombre);
        if ( postreEncontrado != null ) {
            System.out.print("Ingredientes de " + postreNombre + ": ");
            postreEncontrado.imprimirIngredientes();
        } else {
            System.out.println("El postre " + postreNombre + " no se encuentra en la lista");
        }
    }

}
