package notes.cicloV.DataStructures.week1.labTime;

public interface iMatrix {
    // Método para inicializar los valores de una matriz con valores aleatorios entre 0 y 10
    public void random();

    // Método para mostrar los valores de la matriz
    public void show();

    // Método no estático para crear y devolver la transpuesta de la matriz invocada
    public int[][] transpose();

    // Método no estático para sumar la matriz invocada con una matriz pasada como parámetro
    public int[][] plus(int[][] matrix);

    // Método no estático para restar la matriz invocada con una matriz pasada como parámetro
    public int[][] minus(int[][] matrix);

    // Método no estático para verificar si la matriz invocada es igual a una matriz pasada como parámetro
    public boolean isEqual(int[][] matrix);
}
