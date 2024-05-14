package notes.cicloV.DataStructures.week1.labTime.Polynomial;

import java.util.ArrayList;

public class Polynomial implements iPolynomial{

    ArrayList<Integer> coefficients;
    // el orden en el polinomio es inverso al del array, por ejemplo:
    // orden en el polinomio: polinomio = (2x^4 + 0x^4 - 3x^2 + 0x^1 + 5)
    // orden en el arraylist: coefficients = {5, 0, -3, 0. 2}

    // Método constructor
    public Polynomial(ArrayList<Integer> coefficients) {
        this.coefficients = coefficients;
    }
    // Método que devuelve el grado del polinomio (exponente mayor)
    @Override
    public int getDegree() {
        int degree = 0; // Asumiendo que el polinomio esta ordenado...
        for (int i = coefficients.size() - 1; i >= 0; i--) { // Recorre del ultimo al primer elemento del polinomio (el primer al ultimo el arraylist)
            if (coefficients.get(i) != 0) { // Si el coeficiente no es cero, toma el exponente de ese elemento como el grado
                degree = i;
                break;
            }
        }
        return degree;
    }
    // Método que devuelve el término de exponente n
    @Override
    public int getCoefficient(int n) {
        return this.coefficients.get(n);
    }
    // Getter auxiliar que devuelve el ArrayList coefficients
    public ArrayList<Integer> getCoefficients() {
        return this.coefficients;
    }
    // Método que setea el un nuevo coeficiene al término de exponente x 
    @Override
    public void setCoefficient(int n, int newValue) {
        coefficients.set(n, newValue);
    }
    // Método que calcula y devuelve el valor del polinomio 
    @Override
    public double getValue(int x) {
        double result = 0;
        for (int i = 0; i < coefficients.size(); i++) {
            result += coefficients.get(i) * Math.pow(x, i);
        }
        return result;
    }
    // Método que suma dos polinomios
    @Override
    public iPolynomial suma(iPolynomial p) {
        ArrayList<Integer> biggerArray = p.getCoefficients();
        ArrayList<Integer> smallerArray = this.coefficients;
        // En un inicio se asume que p es mas grande que coefficients, pero si no se swapean
        if (this.getDegree() > p.getDegree()){
            biggerArray = this.coefficients;
            smallerArray = p.getCoefficients();
        }
        // Va recorriendo y guardando en el biggerArray la suma de los coeficientes 
        // (si sobra un termino sin sumar en el biggerArray, se queda como esta, 
        // porque solo esta recorriendo hasta el tamaño del smallerArray)
        for (int i = 0; i < smallerArray.size(); i++) {
            biggerArray.set(i, biggerArray.get(i) + smallerArray.get(i));
        }
        // Devolvemos la suma como un objeto de tipo Polynomial (que implementa la interface iPolynomial) con parametro del arraysumado
        return new Polynomial(biggerArray);
    }
    // Imprime 
    @Override
    public void print() {
        for (int i = 0; i < this.coefficients.size(); i++) {
            if (this.coefficients.get(i) >= 0) {
                if (i != 0) {
                    System.out.print("+ ");
                }
            } else {
                System.out.print("-");
            }

            System.out.print(Math.abs(this.coefficients.get(i)));
            System.out.print("x^"+i+" ");
        }
        System.out.println();
    }
}
