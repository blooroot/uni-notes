package Pregunta1;

import java.util.*;
import java.io.*;

public class VocabularioMaps {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner console = new Scanner(System.in);
        darIntro();
        // C:\Users\Usuario\Desktop\Examen\Pregunta1\El_conejo_y_el_delfin.txt
        // C:\Users\Usuario\Desktop\Examen\Pregunta1\Sara_estaba_triste.txt
        System.out.print("[1] Archivo #1 nombre: ");
        Scanner in1 = new Scanner(new File(console.nextLine()));
        System.out.print("\n[2] Archivo #2 nombre: ");
        Scanner in2 = new Scanner(new File(console.nextLine()));
        System.out.println();
        // El cambio aquí radica en que estamos usando Map<String, Integer> para almacenar palabras y sus frecuencias en lugar de ArrayList<String>
        Map<String, Integer> mapa1 = getPalabras(in1);
        Map<String, Integer> mapa2 = getPalabras(in2);
        Map<String, Integer> comun = getCoincidencias(mapa1, mapa2);

        reportarResultados(mapa1, mapa2, comun);

        console.close();
    }

    public static Map<String, Integer> getPalabras(Scanner input) {
        // Ignoramos todos los caracteres excepto los alfabéticos y apóstrofes
        input.useDelimiter("[^a-zA-Z']+");
        Map<String, Integer> palabras = new TreeMap<>(); // Usamos TreeMap para mantener las palabras en orden alfabético automáticamente
        while (input.hasNext()) {
            String next = input.next().toLowerCase();
            palabras.put(next, palabras.getOrDefault(next, 0) + 1);
        }
        return palabras;
    }

    public static Map<String, Integer> getCoincidencias(Map<String, Integer> mapa1, Map<String, Integer> mapa2) {
        Map<String, Integer> result = new TreeMap<>(); 
        // Este método ahora retorna un mapa con cada palabra coincidente y su frecuencia
        for (String palabra : mapa1.keySet()) {
            if (mapa2.containsKey(palabra)) {
                int frecuenciaTotal = mapa1.get(palabra) + mapa2.get(palabra);
                result.put(palabra, frecuenciaTotal);
            }
        }
        return result;
    }

    public static void darIntro() {
        System.out.println("\n[PREGUNTA 1] Estudio de caso: Vocabulario (esta vez con Maps)\n");
        System.out.println("Este programa compara dos archivos de texto e informa del número de palabras en común y el porcentaje de coincidencias");
        System.out.println();
    }

    public static void reportarResultados(Map<String, Integer> mapa1, Map<String, Integer> mapa2, Map<String, Integer> comun) {
        System.out.println("------------------------------------------------------------");
        System.out.println("\n[RESULTADOS]\n");
        System.out.println("Archivo #1 palabras = " + mapa1.size());
        System.out.println("Archivo #2 palabras = " + mapa2.size());
        System.out.println("Palabras en común = " + comun.size());
        double pct1 = 100.0 * comun.size() / mapa1.size();
        double pct2 = 100.0 * comun.size() / mapa2.size();
        System.out.println("% del archivo 1 en superposición = " + pct1);
        System.out.println("% del archivo 2 en superposición = " + pct2);
        System.out.println();
    }
}
