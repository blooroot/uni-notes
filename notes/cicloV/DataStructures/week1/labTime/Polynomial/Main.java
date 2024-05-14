package notes.cicloV.DataStructures.week1.labTime.Polynomial;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> pol = new ArrayList<Integer>();
        pol.add(1);
        pol.add(3);
        pol.add(4);

        ArrayList<Integer> pol2 = new ArrayList<Integer>();
        pol2.add(-6);
        pol2.add(7);
        pol2.add(8);
        pol2.add(10);

        Polynomial polinomio1 = new Polynomial(pol);
        Polynomial polinomio2 = new Polynomial(pol2);
        polinomio1.print();
        polinomio2.print();

        System.out.println(polinomio1.getDegree());
        System.out.println(polinomio1.getCoefficient(2));
        System.out.println(polinomio1.getValue(3));

        Polynomial result = (Polynomial) polinomio1.suma(polinomio2);
        result.print();
    }
}
