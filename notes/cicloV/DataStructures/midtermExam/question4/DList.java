package question4;

public class DList {
    DNode header;
    DNode trailer;
    int size = 0;
    // Constructor
    public DList() {
        header = new DNode(null);
        trailer = new DNode(null);
        header.next = trailer;
        trailer.prev = header;
    }
    // Método para comprobar si la lista es binaria
    public boolean isBinary() {
        boolean esBin = true;
        for (DNode nodeIt = header.next; nodeIt != trailer && esBin == true; nodeIt = nodeIt.next) {
            if (!nodeIt.elem.equals(0) && !nodeIt.elem.equals(1)) {
                esBin = false;
            }
        }
        return esBin;
    }
    // Método auxiliar para imprmir la lista :)
    public void printList() {
        DNode current = header.next;
        System.out.print("\nLista: ");
        while (current != trailer) {
            System.out.print(current.elem + " ");
            current = current.next;
        }
        System.out.println();
    }
    // Método auxiliar para añadir un nuevo elemento a la lista
    public void addLast(Integer elem) {
        DNode newNode = new DNode(elem);
        newNode.prev = trailer.prev;
        newNode.next = trailer;
        trailer.prev.next = newNode;
        trailer.prev = newNode;
        size++;
    }
}
