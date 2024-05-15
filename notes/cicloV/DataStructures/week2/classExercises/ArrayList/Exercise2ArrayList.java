package notes.cicloV.DataStructures.week2.classExercises.ArrayList;

import java.util.ArrayList;
import javax.swing.JOptionPane;

public class Exercise2ArrayList {
    
    public static void main(String[] args) {
        
        ArrayList<String> cadenas = new ArrayList<>();
        String frase, respuesta;
        // Rellenando el ArrayList cadenas
        do {
            frase = JOptionPane.showInputDialog("Ingresa la frase");
            cadenas.add(frase); // Método add
            respuesta = JOptionPane.showInputDialog("¿Deseas ingresar otra frase? (SI/NO)");
        } while ( !respuesta.equalsIgnoreCase("NO") || !respuesta.equalsIgnoreCase("no"));
        // Mostrando el ArrayList cadenas
        System.out.println("\n[1] Cadena con frases originales:");
        for (int i = 0; i < cadenas.size(); i++) {
            System.out.println(cadenas.get(i));
        }
        // Modificando una frase
        cadenas.set(1, "Se modificó"); // Método set
        System.out.println("\n[2] Cadena con frase modificada");
        for (int i = 0; i < cadenas.size(); i++) {
            System.out.println(cadenas.get(i));
        }
        // Removiendo una frase
        cadenas.remove(0);
        System.out.println("\n[3] Cadena con frase removida");
        for (int i = 0; i < cadenas.size(); i++) {
            System.out.println(cadenas.get(i));
        }
        System.out.println();
    }

}
