package notes.cicloV.DataStructures.week2.classExercises.Postre;

import java.util.Scanner;

public class MainPostres {

    public static void main(String[] args) {
        Postres postres = new Postres();

        Postre postre1 = new Postre("Tarta de Manzana");
        postre1.agregarIngrediente("Manzanas");
        postre1.agregarIngrediente("Harina");
        postre1.agregarIngrediente("Azúcar");
        postre1.agregarIngrediente("Canela");

        Postre postre2 = new Postre("Brownie");
        postre2.agregarIngrediente("Chocolate");
        postre2.agregarIngrediente("Harina");
        postre2.agregarIngrediente("Azúcar");
        postre2.agregarIngrediente("Mantequilla");

        Postre postre3 = new Postre("Cheesecake");
        postre3.agregarIngrediente("Queso Crema");
        postre3.agregarIngrediente("Galletas");
        postre3.agregarIngrediente("Azúcar");
        postre3.agregarIngrediente("Mantequilla");

        postres.agregarPostre(postre1);
        postres.agregarPostre(postre2);
        postres.agregarPostre(postre3);

        Scanner scanner = new Scanner(System.in);
        int opcion;

        do {
            System.out.println("\nMenu:");
            System.out.println("1. Imprimir ingredientes de un postre");
            System.out.println("2. Insertar nuevos ingredientes en un postre");
            System.out.println("3. Eliminar un ingrediente de un postre");
            System.out.println("4. Eliminar un postre");
            System.out.println("5. Salir");
            System.out.print("Seleccione una opción: ");
            opcion = scanner.nextInt();
            scanner.nextLine();  // Consumir la nueva línea

            switch (opcion) {
                case 1:
                    System.out.print("\nIngrese el nombre del postre: ");
                    String nombrePostreImprimir = scanner.nextLine();
                    postres.imprimirIngredientesPostre(nombrePostreImprimir);
                    System.out.println();
                    break;
                case 2:
                    System.out.print("\nIngrese el nombre del postre: ");
                    String nombrePostreAgregar = scanner.nextLine();
                    Postre postreEncontrado = postres.buscarPostre(nombrePostreAgregar);
                    if (postreEncontrado != null) {
                        System.out.print("Ingrese el nuevo ingrediente: ");
                        postreEncontrado.agregarIngrediente(scanner.nextLine());
                    } else {
                        System.out.println("El postre " + nombrePostreAgregar + " no se encuentra en la lista");
                    }
                    break;
                case 3:
                    System.out.print("\nIngrese el nombre del postre: ");
                    String nombrePostreEliminarIngrediente = scanner.nextLine();
                    System.out.print("Ingrese el nombre del ingrediente a eliminar: ");
                    String ingredienteEliminar = scanner.nextLine();
                    postres.eliminarIngrediente(nombrePostreEliminarIngrediente, ingredienteEliminar);
                    break;
                case 4:
                    System.out.print("\nIngrese el nombre del postre a eliminar: ");
                    String nombrePostreEliminar = scanner.nextLine();
                    postres.eliminarPostre(nombrePostreEliminar);
                    break;
                case 5:
                    System.out.println("Saliendo del programa...");
                    break;
                default:
                    System.out.println("Opción no válida, intente de nuevo.");
            }
        } while (opcion != 5);

        scanner.close();
    }
}

