package notes.cicloV.DataStructures.week1.labTime.Polynomial;

import java.util.ArrayList;

public interface iPolynomial {
    public int getDegree();
    public int getCoefficient(int n);
    public void setCoefficient(int n, int newValue);
    public double getValue(int x);
    public iPolynomial suma(iPolynomial p);

    public ArrayList<Integer> getCoefficients();
    public void print ();
}
