package notes.cicloV.DataStructures.week1.labTime.Matrix;

public class MainMatrix {
    
    public static void main(String[] args) {
        // Test del constructor de la matriz con ceros y la mostramos
        Matrix matrix1 = new Matrix(3, 3);
        System.out.println("\n[1] Matriz inicializada con ceros:\n");
        matrix1.show(); // Test del método show
        // Test del método random (matriz inicializada con valores random de 0 a 10)
        matrix1.random();
        System.out.println("\n[2] Matriz 1:\n");
        matrix1.show();
        // Test del método transpose
        System.out.println("\n[3] Matriz transpuesta:\n");
        int[][] transposeMatrix = matrix1.transpose();
        printMatrix(transposeMatrix);
        // Creamos la otra matriz
        Matrix matrix2 = new Matrix(3, 3);
        matrix2.random();
        System.out.println("\n[4] Matrix 2:\n");
        matrix2.show();
        // Test del método plus
        System.out.println("\n[5] Suma de Matrix 1 y Matrix 2:\n");
        int[][] sumMatrix = matrix1.plus(matrix2.getMatrix());
        printMatrix(sumMatrix);
        // Test del método minus
        System.out.println("\n[5] Diferencia de Matrix 1 y Matrix 2:\n");
        int[][] diffMatrix = matrix1.minus(matrix2.getMatrix());
        printMatrix(diffMatrix);
        // Test del método isEqual 
        System.out.print("\n[6] ¿Matrix 1 y Matrix 2 son iguales?: " + matrix1.isEqual(matrix2.getMatrix()) + "\n");
        // Test del método identity
        Matrix identityMatrix = Matrix.identity(matrix1);
        System.out.println("\n[7] Matrix identidad:\n");
        printMatrix(identityMatrix.getMatrix());

        System.out.println();
    }

    public static void printMatrix(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                System.out.print(matrix[i][j] + "\t");
            }
            System.out.println();
        }
    }

}
