package Pregunta1;

import java.util.*;
import java.io.*;

public class VocabularioArrayLists {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner console = new Scanner(System.in);
        darIntro();

        System.out.print("Archivo #1 nombre? ");
        Scanner in1 = new Scanner(new File(console.nextLine()));
        System.out.print("Archivo #2 nombre? ");
        Scanner in2 = new Scanner(new File(console.nextLine()));
        System.out.println();

        ArrayList<String> lista1 = getPalabras(in1);
        ArrayList<String> lista2 = getPalabras(in2);
        ArrayList<String> comun = getCoincidencias(lista1, lista2);

        reportarResultados(lista1, lista2, comun);

        console.close();
    }
        
        public static ArrayList<String> getPalabras(Scanner input) {
            // ignora todos los caracteres excepto los alfabéticos y apóstrofes
            input.useDelimiter("[^a-zA-Z']+");
            // lee todas las palabras y los ordena
            ArrayList<String> palabras = new ArrayList<String>();
            while (input.hasNext()) {
                String next = input.next().toLowerCase();
                palabras.add(next);
            }
            Collections.sort(palabras);
            // agregue palabras únicas a la nueva lista y la devuelve
            ArrayList<String> result = new ArrayList<String>();
            if (palabras.size() > 0) {
                result.add(palabras.get(0));
                for (int i = 1; i < palabras.size(); i++) {
                    if (!palabras.get(i).equals(palabras.get(i - 1))) {
                    result.add(palabras.get(i));
                    }
                }
            }
        return result;
        }
        
        public static ArrayList<String> getCoincidencias(ArrayList<String> lista1, ArrayList<String> lista2) {
            ArrayList<String> result = new ArrayList<String>();
            int i1 = 0;
            int i2 = 0;

            while (i1 < lista1.size() && i2 < lista2.size()) {
                int num = lista1.get(i1).compareTo(lista2.get(i2));
                if (num == 0) {
                    result.add(lista1.get(i1));
                    i1++;
                    i2++;
                } else if (num < 0) {
                    i1++;
                } else {    // num > 0
                    i2++;
                }
            }
            return result;
        }
        
        public static void darIntro() {
            System.out.println("Este programa compara dos archivos de texto");
            System.out.println("e informa el número de palabras en");
            System.out.println("común y el porcentaje de coincidencias");
            System.out.println();
        }
        
        public static void reportarResultados(ArrayList<String> lista1, ArrayList<String> lista2, ArrayList<String> comun) {
            System.out.println("Archivo #1 palabras = " + lista1.size());
            System.out.println("Archivo #2 palabras = " + lista2.size());
            System.out.println("Palabras en común = " + comun.size());
            double pct1 = 100.0 * (comun.size() / lista1.size());
            double pct2 = 100.0 * comun.size() / lista2.size();
            System.out.println("% del archivo 1 en superposición = " + pct1);
            System.out.println("% del archivo 2 en superposición = " + pct2);
        }
}
