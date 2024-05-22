package question4;

public class Main {
    public static void main(String[] args) {
        DList lista = new DList();
        // Agregamos elementos a la lista para testear
        lista.addLast(1);
        lista.addLast(3);
        lista.addLast(0);
        lista.addLast(5);
        boolean esBinaria = lista.isBinary();
        // El resultado debería ser true
        lista.printList();
        System.out.println("La lista es binaria: " + esBinaria + "\n");
    }
}
