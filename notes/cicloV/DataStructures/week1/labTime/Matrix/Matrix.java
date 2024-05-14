package notes.cicloV.DataStructures.week1.labTime.Matrix;

import java.util.Random;

public class Matrix implements iMatrix {

    private int rows;
    private int columns;
    private int[][] matrix;

    // Método constructor para crear matriz de ceros
    public Matrix(int rows, int columns){
        this.rows = rows;
        this.columns = columns;
        this.matrix = new int[rows][columns];
    }

    // Getter auxiliar
    public int[][] getMatrix() {
        return this.matrix;
    }

    // Método para inicializar los valores de una matriz con valores aleatorios entre 0 y 10
    @Override
    public void random() {
        Random rand = new Random();
        for ( int i = 0; i < this.rows; i++) {
            for ( int j = 0; j < this.columns; j++ ) {
                this.matrix[i][j] = rand.nextInt(11);
            } 
        }
    }

    // Método no estático para mostrar los valores de la matriz
    @Override
    public void show() {
        for ( int i = 0; i < this.rows; i++) {
            for ( int j = 0; j < this.columns; j++ ) {
                System.out.print(this.matrix[i][j] + "\t");
            }
            System.out.println();
        }
    }

    // Método no estático para crear y devolver la transpuesta de la matriz
    @Override
    public int[][] transpose() {
        int[][] result = new int[this.columns][this.rows];
        for ( int i = 0; i < this.rows; i++ ) {
            for ( int j = 0; j < this.columns; j++ ) {
                result[i][j] = this.matrix[j][i];
            }
        }
        return result;
    }

    // Método no estático para sumar la matriz invocada con otra pasada como parámetro
    @Override
    public int[][] plus(int[][] otherMatrix) {
        if (otherMatrix.length != this.rows || otherMatrix[0].length != this.columns) {
            System.out.println("Error: Las matrices no tienen las mismas dimensiones.");
            return null;
        } else {
            int[][] result = new int[this.rows][this.columns];
            for (int i = 0; i < this.rows; i++) {
                for (int j = 0; j < this.columns; j++) {
                    result[i][j] = this.matrix[i][j] + otherMatrix[i][j];
                }
            }
            return result;
        }
    }

    // Método no estático para restar la matriz invocada con otra pasada como parámetro
    @Override
    public int[][] minus(int[][] otherMatrix) {
        if (otherMatrix.length != this.rows || otherMatrix[0].length != this.columns) {
            System.out.println("Error: Las matrices no tienen las mismas dimensiones.");
            return null;
        } else {
            int[][] result = new int[this.rows][this.columns];
            for (int i = 0; i < this.rows; i++) {
                for (int j = 0; j < this.columns; j++) {
                    result[i][j] = this.matrix[i][j] - otherMatrix[i][j];
                }
            }
            return result;
        }
    }

    // Método no estático para verificar si la matriz invocada y la matriz parámetro son iguales
    @Override
    public boolean isEqual(int[][] otherMatrix) {
        if ( otherMatrix.length != this.rows || otherMatrix[0].length != this.columns ) {
            return false;
        }
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.columns; j++) {
                if ( this.matrix[i][j] != otherMatrix[i][j] ) {
                    return false;
                }
            }
        }
        return true;
    }

    // Método estático para devolver la matriz identidad 
    public static Matrix identity(Matrix matrix) {
        if (matrix.rows != matrix.columns) {
            System.out.println("Error: La matriz no es cuadrada, no se puede calcular la matriz identidad.");
            return null;
        }
        Matrix identityMatrix = new Matrix(matrix.rows, matrix.columns);
        for (int i = 0; i < matrix.rows; i++) {
            identityMatrix.matrix[i][i] = 1;
        }
        return identityMatrix;
    }
}